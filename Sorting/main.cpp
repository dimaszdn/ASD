#include <Sorting.h>
#include <iostream>
#include <vector>

using namespace ch;

int main()
{
    std::vector<int> v1 = { 10, -5, 16, 3, 0, 3, -100, 500, 0, -3, -1000};
    std::vector<int> v2 = {-50, 20, 100, 3, 4, 300, 6, 43, 21, 56}; //-50 3 4 6 20 21 43 56 100 300
    std::vector<int> v3 = {-50, 20, 100, 3};
    std::vector<int> v0 = {};
    auto S = new Sort<int>(v3);
    try
    {
        S->insertion_sort();
        S->print_vec();
    }
    catch (std::out_of_range& ex)
    {
        std::cout << ex.what() << "\n";
    }


    return 0;
}
