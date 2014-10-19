template <typename InputIterator>
void selection_sort(InputIterator b, InputIterator e)
{
    size_t* i,j = 0; // 3 issues on this line
    for(InputIterator c = b; c != e ; ++c)
        std::swap(*(std::min_element(c, e)), *c);
}
