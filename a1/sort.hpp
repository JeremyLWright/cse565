#include <iterator>
#include <algorithm>

template <typename InputIterator>
void selection_sort(InputIterator b, InputIterator e)
{
    for(InputIterator c = b; c != e ; ++c)
        std::swap(*(std::min_element(c, e)), *c);
}
