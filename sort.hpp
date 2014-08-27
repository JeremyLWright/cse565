#include <iterator>
#include <iostream>
#include <algorithm>

template <typename InputIterator>
void selection_sort(InputIterator b, InputIterator e)
{

    //Selection sort performs the following steps:
    //1) Starting at index 0, search the entire array to find the
    //smallest value
    //2) Swap the smallest value found with the value at index 0
    //3) Repeat steps 1 & 2 starting from the next index

    for(InputIterator c = b; c != e ; ++c)
    {
        auto m = std::min_element(c, e);
        std::swap(*m, *c);
    }

}
