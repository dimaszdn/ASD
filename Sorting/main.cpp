#include <Sorting.h>
#include <iostream>
#include <vector>

using namespace ch;

int main()
{
    std::vector<int> v1 = { 10, -5, 16, 3, 0, 3, -100, 500};
    std::vector<int> v2 = {-50, 20, 100, 3, 4, 300, 6, 43, 21, 56};
    auto S = new Sort<int>(v2);
    S->comb_sort();
    S->print_vec();

    return 0;
}
