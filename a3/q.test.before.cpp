/*******************************************************************************
 * FILENAME:    q.test.cpp
 * DESCRIPTION: unit tests for user-space threads and queue
 * AUTHOR:      Jeremy Wright, Matt Welch
 * SCHOOL:      Arizona State University
 * CLASS:       CSE531: Dstributed and Multiprocessor Operating Systems
 * INSTRUCTOR:  Dr. Partha Dasgupta
 * TERM:        Fall 2014
 *******************************************************************************/
extern "C" {
#include "threads/q.h"
}


#include <gtest/gtest.h>
#include <deque>
#include <functional>
#include <algorithm>
#include <random>
#include <chrono>
#include <limits>
#include <iterator>
class Directed : public ::testing::Test 
{
    protected:
        virtual void SetUp()
        {
            InitQ(&q);
        }

        virtual void TearDown()
        {
            //FreeQ(&q);
        }

        Q q;
};


TEST_F(Directed, Add)
{
    for(int i = 1; i < 100; ++i)
    {
        test_item_t t;
        t.data = i;
        AddQ(&q, &t);
        ASSERT_EQ(i, size_(&q));
    }
    ASSERT_EQ(99, size_(&q));
    for(int i = 1; i < 100; ++i)
    {
        DelQ(&q);
    }
    ASSERT_EQ(0, size_(&q));
}

TEST_F(Directed, PutGet)
{
    int i = 8;
    test_item_t t;
    t.data = i;
    AddQ(&q, &t);
    ASSERT_EQ(8, DelQ(&q)->data);
    ASSERT_EQ(0, size_(&q));
}

TEST_F(Directed, DeleteEmpty)
{
    InitQ(&q);
    DelQ(&q);
}
TEST_F(Directed, RotateEmpty)
{
    InitQ(&q);
    RotateQ(&q);
}
TEST_F(Directed, RotateOne)
{
    test_item_t t;
    t.data = 9;

    AddQ(&q, &t);
    for(int i = 0; i < 100; ++i)
        ASSERT_EQ(9, RotateQ(&q)->data);
}
TEST_F(Directed, RotateTwo)
{
    InitQ(&q);

    test_item_t t1;
    t1.data = 0;
    AddQ(&q, &t1);

    test_item_t t2;
    t2.data = 1;
    AddQ(&q, &t2);

    for(int i = 0; i < 100000; ++i)
        ASSERT_EQ(i%2, RotateQ(&q)->data);
}

TEST_F(Directed, Rotate)
{
    size_t const test_size = 4;
    test_item_t data[test_size];

    for(int i = 0; i < (int)test_size; ++i)
    {
        data[i].data = i;
        AddQ(&q, &data[i]);
    }

    for(int i = 0; i < 1000; ++i)
    {
        ASSERT_EQ(3, PeekQ(&q)->data);
        ASSERT_EQ(0, RotateQ(&q)->data);
        ASSERT_EQ(0, PeekQ(&q)->data);
        ASSERT_EQ(1, RotateQ(&q)->data);
        ASSERT_EQ(1, PeekQ(&q)->data);
        ASSERT_EQ(2, RotateQ(&q)->data);
        ASSERT_EQ(2, PeekQ(&q)->data);
        ASSERT_EQ(3, RotateQ(&q)->data);
        ASSERT_EQ(3, PeekQ(&q)->data);
    }
}
TEST_F(Directed, AddDel)
{
    size_t const test_size = 4;
    test_item_t data[test_size];

    for(int i = 0; i < (int)test_size; ++i)
    {
        data[i].data = i;
        AddQ(&q, &data[i]);
    }

    for(int i = 0; i < 1000; ++i)
    {
        ASSERT_EQ(3, PeekQ(&q)->data);
        ASSERT_EQ(0, RotateQ(&q)->data);
        ASSERT_EQ(0, PeekQ(&q)->data);
        ASSERT_EQ(1, RotateQ(&q)->data);
        ASSERT_EQ(1, PeekQ(&q)->data);
        ASSERT_EQ(2, RotateQ(&q)->data);
        ASSERT_EQ(2, PeekQ(&q)->data);
        ASSERT_EQ(3, RotateQ(&q)->data);
        ASSERT_EQ(3, PeekQ(&q)->data);
    }
}


