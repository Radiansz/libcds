#include <iostream>
#include <gtest/gtest.h>
#include <cds/init.h>
#include <cds/gc/hp.h>
#include <cds/container/timestamped_deque.h>
#define DATA_SIZE 1000000
#define THREADS_AMOUNT 8

int readAm = 10000, writeAm = 10000, readThreads=4, writeThreads=4;



struct traits_TSDeque_ic : public cds::container::timestamped_deque::traits
{
    typedef cds::atomicity::item_counter item_counter;
};

void separate(int full, int parts, int &partSize, int &tail) {
    partSize = full/parts;
    tail = full % parts;
}


struct TestStruct {
    TestStruct():data(0) {

    }
    TestStruct(int data):data(data) {

    }
    int data;

};

cds::container::Timestamped_deque<TestStruct, traits_TSDeque_ic >* deque;
boost::barrier *startBarrier;

void tester(int ti) {
    std::cout << ti << std::endl;
}

void backReader(int size, int t) {
    std::cout << "Thread:" << t << std::endl;
    startBarrier->wait();
    cds::threading::Manager::attachThread();
    for(int i = 0; i < size; i++) {
        TestStruct t;
        try {
            deque->pop_back(t);
        } catch (cds::container::Timestamped_deque<TestStruct, traits_TSDeque_ic >::EndlessLoopException& e) {
            break;
        }
    }
    cds::threading::Manager::detachThread();
}

void backWriter(int size, int t) {
    std::cout << "Thread:" << t << std::endl;
    startBarrier->wait();
    cds::threading::Manager::attachThread();
    for(int i=0; i < size; i++) {
        TestStruct test(i);
        deque->push_back(test);
    }
    cds::threading::Manager::detachThread();
}

void frontReader(int size, int t) {
    std::cout << "Thread:" << t << std::endl;
    startBarrier->wait();
    cds::threading::Manager::attachThread();
    for(int i = 0; i < size; i++) {
        TestStruct t;
        try {
            deque->pop_front(t);
        } catch (cds::container::Timestamped_deque<TestStruct, traits_TSDeque_ic >::EndlessLoopException& e) {
            break;
        }
    }
    cds::threading::Manager::detachThread();
}

void frontWriter(int size, int t) {
    std::cout << "Thread:" << t << std::endl;
    startBarrier->wait();
    cds::threading::Manager::attachThread();
    for(int i=0; i < size; i++) {
        TestStruct test(i);
        deque->push_front(test);
    }
    cds::threading::Manager::detachThread();
}




TEST(TSDeque_stress, As_a_stack) {
    int writePart, writeTail;
    int readPart, readTail;
    int sumThread = readThreads + writeThreads;
    separate(readAm, readThreads, readPart, readTail);
    separate(writeAm, writeThreads, writePart, writeTail);

    deque = new cds::container::Timestamped_deque<TestStruct, traits_TSDeque_ic>();
    int amount = THREADS_AMOUNT/2;
    startBarrier = new boost::barrier(sumThread);
    boost::thread **threads = new boost::thread*[sumThread];

//Read
    for(int i = 0; i < readThreads; i++) {
        int curPart = (i+1 != readThreads ? readPart : (readPart + readTail));
        threads[i] = new boost::thread(backReader, curPart, i);
    }
//Write
    for(int i = 0; i < writeThreads; i++) {
        int curPart = (i+1 != writeThreads ? writePart : (writePart + writeTail));
        threads[i+readThreads] = new boost::thread(backWriter, curPart, i+readThreads);
    }
//Waiting to end
    for(int i = 0; i < sumThread; i++)
        threads[i]->join();
    deque->printStats();
}

TEST(TSDeque_stress, As_a_queue) {
    int writePart, writeTail;
    int readPart, readTail;
    int sumThread = readThreads + writeThreads;
    separate(readAm, readThreads, readPart, readTail);
    separate(writeAm, writeThreads, writePart, writeTail);

    deque = new cds::container::Timestamped_deque<TestStruct, traits_TSDeque_ic>();
    int amount = THREADS_AMOUNT/2;
    startBarrier = new boost::barrier(sumThread);
    boost::thread **threads = new boost::thread*[sumThread];

    //Read
    for(int i = 0; i < readThreads; i++) {
        int curPart = (i+1 != readThreads ? readPart : (readPart + readTail));
        threads[i] = new boost::thread(frontReader, curPart, i);
    }
    //Write
    for(int i = 0; i < writeThreads; i++) {
        int curPart = (i+1 != writeThreads ? writePart : (writePart + writeTail));
        threads[i+readThreads] = new boost::thread(backWriter, curPart, i+readThreads);
    }
    //Waiting to end
    for(int i = 0; i < sumThread; i++)
    threads[i]->join();
    deque->printStats();
}




int main(int argc, char *argv[]) {


    ::testing::InitGoogleTest(&argc, argv);

    for(int i=0; i<argc; i++) {
        std::cout << "param:" << argv[i] << std::endl;
        if(strcmp(argv[i], "-ra") == 0 && argc > i+1 && atoi(argv[i+1]) != 0)
            readAm = atoi(argv[i+1]);
        else if(strcmp(argv[i], "-wa") == 0 && argc > i+1 && atoi(argv[i+1]) != 0)
            writeAm = atoi(argv[i+1]);
        else if(strcmp(argv[i], "-rt") == 0 && argc > i+1 && atoi(argv[i+1]) != 0)
            readThreads = atoi(argv[i+1]);
        else if(strcmp(argv[i], "-wt") == 0 && argc > i+1 && atoi(argv[i+1]) != 0)
            writeThreads = atoi(argv[i+1]);
    }
    std::cout << "Amount of writes:" << writeAm << std::endl;
    std::cout << "Amount of reads:" << readAm << std::endl;
    std::cout << "Amount of write threads:" << writeThreads << std::endl;
    std::cout << "Amount of read threads:" << readThreads << std::endl;
    cds::gc::HP hpGC(4, readThreads + writeThreads + 1);
    cds::Initialize();
    cds::threading::Manager::attachThread();

    return RUN_ALL_TESTS();

}
