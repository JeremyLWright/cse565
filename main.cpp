#include "sort.hpp"
#include <vector>
#include <random>
#include <limits>
#include <cassert>
int main(int argc, const char *argv[])
{
    std::numeric_limits<int> limits;

    std::mt19937 engine(time(0)); // Fixed seed of 0
    std::uniform_int_distribution<int> range_dist(0,150);
    std::uniform_int_distribution<int> element_dist(0, limits.max());
   
    size_t n = 100000000;
    auto f = [&](){return element_dist(engine);};
    for(size_t i = 0; i < n; ++i)
    {
        std::vector<int> vs;
        std::generate_n(std::back_inserter(vs), range_dist(engine), f);
        selection_sort(std::begin(vs), std::end(vs));
        assert(std::is_sorted(std::begin(vs), std::end(vs)));
        if(i %100000 == 0)
            std::cout << static_cast<double>(i)/n*100 << "%% complete\n";
    }
    return 0;
}
