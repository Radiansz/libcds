#include <iostream>
#include <gtest/gtest.h>
#include <cds/init.h>
#include <cds/gc/hp.h>
#include <cds/container/timestamped_deque.h>
#define DATA_SIZE 10

cds::gc::HP hpGC(4, 8);

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




TEST(TSDeque_unit, Creation) {
    cds::container::Timestamped_deque<TestStruct, traits_TSDeque_ic >* deque = new cds::container::Timestamped_deque<TestStruct, traits_TSDeque_ic>();

}

TEST(TSDeque_unit, Empty) {
    cds::container::Timestamped_deque<TestStruct, traits_TSDeque_ic >* deque = new cds::container::Timestamped_deque<TestStruct, traits_TSDeque_ic>();
    EXPECT_TRUE(deque->empty());
}

TEST(TSDeque_unit, Push_front) {
    cds::container::Timestamped_deque<TestStruct, traits_TSDeque_ic >* deque = new cds::container::Timestamped_deque<TestStruct, traits_TSDeque_ic>();
    for(int i=0; i < DATA_SIZE; i++) {
        TestStruct test(i);
        deque->push_front(test);
    }
    EXPECT_EQ(DATA_SIZE, deque->size());
}

TEST(TSDeque_unit, Push_back) {
    cds::container::Timestamped_deque<TestStruct, traits_TSDeque_ic >* deque = new cds::container::Timestamped_deque<TestStruct, traits_TSDeque_ic>();
    for(int i=0; i < DATA_SIZE; i++) {
        TestStruct test(i);
        deque->push_back(test);
    }
    EXPECT_EQ(DATA_SIZE, deque->size());
}

TEST(TSDeque_unit, Pop_back_with_Push_front) {
    cds::container::Timestamped_deque<TestStruct, traits_TSDeque_ic >* deque = new cds::container::Timestamped_deque<TestStruct, traits_TSDeque_ic>();
    for(int i=0; i < DATA_SIZE; i++) {
        TestStruct test(i);
        deque->push_front(test);
    }

    for(int i=0; i < DATA_SIZE; i++) {
        TestStruct test;
        deque->pop_back(test);
        EXPECT_EQ(i, test.data);
    }
    EXPECT_EQ(0, deque->size());
}

TEST(TSDeque_unit, Pop_back_with_Push_back) {
    cds::container::Timestamped_deque<TestStruct, traits_TSDeque_ic >* deque = new cds::container::Timestamped_deque<TestStruct, traits_TSDeque_ic>();
    for(int i=0; i < DATA_SIZE; i++) {
        TestStruct test(i);
        deque->push_back(test);
    }

    for(int i=0; i < DATA_SIZE; i++) {
        TestStruct test;
        deque->pop_back(test);
        EXPECT_EQ((DATA_SIZE - i - 1), test.data);
    }
    EXPECT_EQ(0, deque->size());
}

TEST(TSDeque_unit, Pop_front_with_Push_front) {
    cds::container::Timestamped_deque<TestStruct, traits_TSDeque_ic >* deque = new cds::container::Timestamped_deque<TestStruct, traits_TSDeque_ic>();
    for(int i=0; i < DATA_SIZE; i++) {
        TestStruct test(i);
        deque->push_front(test);
    }

    for(int i=0; i < DATA_SIZE; i++) {
        TestStruct test;
        deque->pop_front(test);
        EXPECT_EQ((DATA_SIZE - i - 1), test.data);
    }
    EXPECT_EQ(0, deque->size());
}

TEST(TSDeque_unit, Pop_front_with_Push_back) {
    cds::container::Timestamped_deque<TestStruct, traits_TSDeque_ic >* deque = new cds::container::Timestamped_deque<TestStruct, traits_TSDeque_ic>();
    for(int i=0; i < DATA_SIZE; i++) {
        TestStruct test(i);
        deque->push_back(test);
    }

    for(int i=0; i < DATA_SIZE; i++) {
        TestStruct test;
        deque->pop_front(test);
        EXPECT_EQ(i, test.data);
    }
    EXPECT_EQ(0, deque->size());
}

TEST(TSDeque_unit, Pop_front_from_empty) {
    cds::container::Timestamped_deque<TestStruct, traits_TSDeque_ic >* deque = new cds::container::Timestamped_deque<TestStruct, traits_TSDeque_ic>();
    TestStruct test;
    EXPECT_FALSE(deque->pop_front(test));
}

TEST(TSDeque_unit, Pop_back_from_empty) {
    cds::container::Timestamped_deque<TestStruct, traits_TSDeque_ic >* deque = new cds::container::Timestamped_deque<TestStruct, traits_TSDeque_ic>();
    TestStruct test;
    EXPECT_FALSE(deque->pop_back(test));
}


int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    cds::Initialize();
    cds::threading::Manager::attachThread();
    std::cout << "Hello tests" << std::endl;
    return RUN_ALL_TESTS();;
}
