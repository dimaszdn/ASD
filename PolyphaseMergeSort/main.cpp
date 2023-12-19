#include <iostream>
#include<vector>
#include<filesystem>
#include<PolyphaseMergeSort.h>

void random_fill(std::fstream& file, const std::string& path, int countEl, int begin, int end)
{
    file.open(path, std::ios::out);
    srand(time(0));
    int value;
    for (int i = 0; i < countEl; ++i)
    {
        value = begin + rand() % (end - begin + 1);
        file << value;
        file << "\n";
    }
    file.close();
}

int main()
{
    std::fstream input;
    random_fill(input, "files/input.txt", 101, -1000, 1000);

    PolyphaseMergeSort polyphaseMergeSort("files/input.txt");
    polyphaseMergeSort.sort();
    std::cout << polyphaseMergeSort.getOutputFlag();
    return 0;
}