#include <iostream>
#include <gtest/gtest.h>
#include <cds/init.h>
#include <cds/gc/hp.h>
#include <cds/container/timestamped_deque.h>
#define DATA_SIZE 1000000
#define THREADS_AMOUNT 8

cds::gc::HP hpGC(4, THREADS_AMOUNT + 1);

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

cds::container::Timestamped_deque<TestStruct, traits_TSDeque_ic >* deque;
boost::barrier *startBarrier;

void backReader() {
    startBarrier->wait();
    cds::threading::Manager::attachThread();
    for(int i = 0; i < DATA_SIZE; i++) {
        TestStruct t;
        try {
            deque->pop_back(t);
        } catch (cds::container::Timestamped_deque<TestStruct, traits_TSDeque_ic >::EndlessLoopException& e) {
            break;
        }
    }
    cds::threading::Manager::detachThread();
}

void backWriter() {
    startBarrier->wait();
    cds::threading::Manager::attachThread();
    for(int i=0; i < DATA_SIZE; i++) {
        TestStruct test(i);
        deque->push_back(test);
    }
    cds::threading::Manager::detachThread();
}


TEST(TSDeque_stress, As_a_stack) {
    deque = new cds::container::Timestamped_deque<TestStruct, traits_TSDeque_ic>();
    int amount = THREADS_AMOUNT/2;
    startBarrier = new boost::barrier(amount*2+1);
    boost::thread **threads = new boost::thread*[THREADS_AMOUNT];
    for(int i = 0; i < amount; i++)
        threads[i] = new boost::thread(backReader);
    for(int i = 0; i < amount; i++)
        threads[i+amount] = new boost::thread(backWriter);
    startBarrier->wait();
    for(int i = 0; i < amount*2; i++)
        threads[i]->join();
    deque->printStats();

}


int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    cds::Initialize();
    cds::threading::Manager::attachThread();
    std::cout << "Hello tests" << std::endl;
    return RUN_ALL_TESTS();;
}
