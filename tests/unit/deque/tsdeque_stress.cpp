// ** params -wa = amount of elements to write per thread
// **        -ra = amount of elements to read per thread
// **        -wt = amount of writers thread
// **        -rt = amount of readers thread
// **        -out = output file, no output if not specified
// **        Output format:
// **          1 test execution per string, string content:
// **               executionTime,operationWithEmpty,writesAmountPerThread,readsAmountPerThread,writers,readers,emptyOperations,failedOperations,freedNodes

#include <iostream>
#include <gtest/gtest.h>
#include <cds/init.h>
#include <cds/gc/hp.h>
#include <cds/container/timestamped_deque.h>
#include <boost/timer/timer.hpp>
#include <fstream>

using boost::timer::cpu_timer;

int readAm = 10000, writeAm = 1000, readThreads=3, writeThreads=1;
char* outFile;
bool outEnabled = false;


struct traits_TSDeque_ic : public cds::container::timestamped_deque::traits
{
    typedef cds::atomicity::item_counter item_counter;
};

struct TestStruct {
    TestStruct():data(0) {

    }
    TestStruct(int data):data(data) {

    }
    int data;

};


boost::barrier *startBarrier;
cds::container::Timestamped_deque<TestStruct, traits_TSDeque_ic >* deque;
class DequeTest_stress : public ::testing::Test
{
    protected:
        void SetUp()
        {
            deque = new cds::container::Timestamped_deque<TestStruct, traits_TSDeque_ic>();

        }
        void TearDown()
        {

        }

};


void separate(int full, int parts, int &partSize, int &tail) {
    partSize = full/parts;
    tail = full % parts;
}


void tester(int ti) {
    std::cout << ti << std::endl;
}

void backReader(int size, int t) {
    startBarrier->wait();
    cds::threading::Manager::attachThread();
    for(int i = 0; i < size; i++) {
        TestStruct t;
        try {
            deque->pop_back(t);
        } catch (cds::container::Timestamped_deque<TestStruct, traits_TSDeque_ic >::EndlessLoopException& e) {
            std::cout << "Endless:" << e.getMapSize() << std::endl;
            deque -> printStats();
            ADD_FAILURE();
            break;
        }
    }
    std::cout << "backReaderEnd" << std::endl;
    cds::threading::Manager::detachThread();
}

void backWriter(int size, int t) {
    startBarrier->wait();
    cds::threading::Manager::attachThread();
    for(int i=0; i < size; i++) {
        TestStruct test(i);
        deque->push_back(test);
    }
    std::cout << "backWriterEnd" << std::endl;
    cds::threading::Manager::detachThread();
}

void frontReader(int size, int t) {
    startBarrier->wait();
    cds::threading::Manager::attachThread();
    for(int i = 0; i < size; i++) {
        TestStruct t;
        try {
            deque->pop_front(t);
        } catch (cds::container::Timestamped_deque<TestStruct, traits_TSDeque_ic >::EndlessLoopException& e) {
            std::cout << "Endless:" << e.getMapSize() << std::endl;
            deque -> printStats();
            ADD_FAILURE();
            break;
        }
    }
    std::cout << "frontReaderEnd" << std::endl;
    cds::threading::Manager::detachThread();
}

void frontWriter(int size, int t) {
    startBarrier->wait();
    cds::threading::Manager::attachThread();
    for(int i=0; i < size; i++) {
        TestStruct test(i);
        deque->push_front(test);
    }
    std::cout << "backWriterEnd" << std::endl;
    cds::threading::Manager::detachThread();
}

void printResult(boost::timer::cpu_timer &timer) {
    if(outEnabled) {
        cds::container::Timestamped_deque<TestStruct, traits_TSDeque_ic >::Statistic *stats = deque->getStats();
        std::ofstream outfile;
        outfile.open(outFile, std::ios_base::app);
        outfile << timer.format(3, "%w") << "," << writeAm*writeThreads + readAm*readThreads << "," << writeAm << "," << readAm << "," <<
        writeThreads << "," << readThreads << "," <<stats->emptyPopLeft.load() + stats->emptyPopRight.load() << "," << stats->failedPopLeft.load() + stats->failedPopRight.load() <<
        "," << stats->freedAmount.load() << "\n";
        std::cout << "TIME!!!!!:" << timer.format() << std::endl;
        deque->printStats();
    }
}

TEST_F(DequeTest_stress, As_a_stack) {
    int writePart = writeAm, writeTail = 0;
    int readPart = readAm, readTail = 0;
    int sumThread = readThreads + writeThreads;
//    separate(readAm, readThreads, readPart, readTail);
//    separate(writeAm, writeThreads, writePart, writeTail);



    startBarrier = new boost::barrier(sumThread+1);
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
    boost::timer::cpu_timer timer;
    startBarrier->wait();
//Waiting to end
    for(int i = 0; i < sumThread; i++)
        threads[i]->join();
    timer.stop();
    printResult(timer);

}

TEST_F(DequeTest_stress, As_a_queue) {
    int writePart = writeAm, writeTail = 0;
    int readPart = readAm, readTail = 0;
    int sumThread = readThreads + writeThreads;
//    separate(readAm, readThreads, readPart, readTail);
//    separate(writeAm, writeThreads, writePart, writeTail);


    startBarrier = new boost::barrier(sumThread+1);
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
    boost::timer::cpu_timer timer;
    startBarrier->wait();
    //Waiting to end
    for(int i = 0; i < sumThread; i++)
    threads[i]->join();
    timer.stop();
    printResult(timer);
}

TEST_F(DequeTest_stress, As_a_deque) {
    int writePart = writeAm, writeTail = 0;
    int readPart = readAm, readTail = 0;
    int sumThread = readThreads + writeThreads;
//    separate(readAm, readThreads, readPart, readTail);
//    separate(writeAm, writeThreads, writePart, writeTail);


    startBarrier = new boost::barrier(sumThread+1);
    boost::thread **threads = new boost::thread*[sumThread];

    //Read
    for(int i = 0; i < readThreads; i++) {
        int curPart = (i+1 != readThreads ? readPart : (readPart + readTail));
        if(i % 2 == 0)
            threads[i] = new boost::thread(frontReader, curPart, i);
        else
            threads[i] = new boost::thread(backReader, curPart, i);
    }
    //Write
    for(int i = 0; i < writeThreads; i++) {
        int curPart = (i+1 != writeThreads ? writePart : (writePart + writeTail));
        if(i % 2 == 0)
            threads[i+readThreads] = new boost::thread(backWriter, curPart, i+readThreads);
        else
            threads[i+readThreads] = new boost::thread(frontWriter, curPart, i+readThreads);
    }
    boost::timer::cpu_timer timer;
    startBarrier->wait();
    //Waiting to end
    for(int i = 0; i < sumThread; i++)
        threads[i]->join();
    timer.stop();
    printResult(timer);
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
        else if(strcmp(argv[i], "-out") == 0 && argc > i+1) {
            outEnabled = true;
            outFile = argv[i+1];
        }
    }
    std::cout << "Amount of writes:" << writeAm << std::endl;
    std::cout << "Amount of reads:" << readAm << std::endl;
    std::cout << "Amount of write threads:" << writeThreads << std::endl;
    std::cout << "Amount of read threads:" << readThreads << std::endl;
    cds::gc::HP hpGC(4, readThreads + writeThreads + 1);
    cds::Initialize();
    cds::threading::Manager::attachThread();


    return   RUN_ALL_TESTS();

}
