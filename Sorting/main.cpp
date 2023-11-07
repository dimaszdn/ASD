#include <Sorting.h>
#include <iostream>
#include <vector>

using namespace ch;

void print_vec(const std::vector<int>& v)
{
    for (int i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << "\n";
}

int main()
{
    std::vector<int> v1 = {3, 6, 5, 7, 2, 1, 4, 8};
    std::vector<int> v2 = random_fill(10, 0, 1000);
    print_vec(v2);

    auto S = new Sort<int>(v2);

    try
    {
        S->heap_sort();
        S->print_vec();
    }
    catch (std::out_of_range& ex)
    {
        std::cout << ex.what() << "\n";
    }

    delete S;

    return 0;
}
