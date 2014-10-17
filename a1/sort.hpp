#include <iterator>
#include <algorithm>

template <typename InputIterator>
void selection_sort(InputIterator b, InputIterator e)
{
    //Selection sort performs the following steps:
    //1) From the current iterator, find the smallest value
    //2) Swap the smallest value with the current iterator
    //3) Continue until end of range

    for(InputIterator c = b; c != e ; ++c)
    {
        std::swap(*(std::min_element(c, e)), *c);
    }

}
