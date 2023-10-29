#include <Sorting.h>
#include <iostream>
#include <vector>

using namespace ch;

int main()
{
    std::vector<int> v1 = { 10, -5, 16, 3, 0, 3, -100, 500, 0, -3, -1000};
    std::vector<int> v2 = {-50, 20, 100, 3, 4, 300, 6, 43, 21, 56}; //-50 3 4 6 20 21 43 56 100 300
    std::vector<int> v3 = {-50, 20, 100, 3};
    std::vector<int> v0 = {9, 8, 5, 7, 5, 6, 5, 1};
    std::vector<int> v4 = {32, 95, 90, 82, 24, 66, 35, 90, 75, 54, 40, 43, 90, 68};
    std::vector<int> v5 = {654, 304, 100, 21, 5, 0};

    auto S = new Sort<int>(v5);

//    int a = -512;
//    std::cout << (a / 100) % 10;

    try
    {
//        S->print_vec();
        S->radix_sort();
//        S->print_vec();
    }
    catch (std::out_of_range& ex)
    {
        std::cout << ex.what() << "\n";
    }

    delete S;

    return 0;
}
