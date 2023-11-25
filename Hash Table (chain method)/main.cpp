#include<HashTable.h>

#include <iostream>
#include<vector>

int main()
{
    try
    {
        std::ifstream fin;
        std::vector<std::string> text = readFile(fin);
        size_t cap = std::stoi(text[0]);
        HashTable hashTable(cap);

        for (int i = 1; i < text.size(); ++i)
            hashTable.insert(text[i]);

        hashTable.outputFile();
    }
    catch (const std::out_of_range& ex)
    {
        std::cout << ex.what() << "\n";
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << "\n";
    }
    return 0;
}
