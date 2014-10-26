
#include "sort.hpp"
#include "gtest/gtest.h"
#include <vector>
#include <random>
#include <limits>
#include <cassert>
#include <iostream>


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
