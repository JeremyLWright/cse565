
#include "sort.hpp"
#include "gtest/gtest.h"
#include <vector>
#include <random>
#include <limits>
#include <cassert>
#include <iostream>

using TestInput = std::vector<int>;

class RandomizedTest : public testing::TestWithParam<TestInput> {};
TEST_P(RandomizedTest, Sorting)
{
    auto vs = GetParam();
    selection_sort(std::begin(vs), std::end(vs));
    ASSERT_TRUE(std::is_sorted(std::begin(vs), std::end(vs)));
}

std::vector<std::vector<int>> GenerateTestCases()
{
    std::vector<TestInput> test_cases;
    std::numeric_limits<int> limits;

    std::mt19937 engine(time(0));
    std::uniform_int_distribution<int> range_dist(0,1500);
    std::uniform_int_distribution<int> element_dist(
            limits.min(), 
            limits.max());

    size_t n = 1;// 10000;
    auto f = [&](){return element_dist(engine);};
    std::generate_n(std::back_inserter(test_cases), n, 
            [&](){ 
            TestInput vs;
            std::generate_n(std::back_inserter(vs), 
                range_dist(engine), 
                f);
            return vs;
            });
    return test_cases;
}

INSTANTIATE_TEST_CASE_P(
    hw1,
    RandomizedTest,
    testing::ValuesIn(GenerateTestCases())
);

TEST(Regression, Sort)
{
    std::uniform_int_distribution<int> element_dist(std::numeric_limits<int>::min(),
            std::numeric_limits<int>::max());
    std::mt19937 engine(time(0));

    std::vector<int> vs(100000);
    auto f = [&](){return element_dist(engine);};
    std::generate(std::begin(vs), std::end(vs), f);
    selection_sort(std::begin(vs), std::end(vs));
    ASSERT_TRUE(std::is_sorted(std::begin(vs), std::end(vs)));


}
