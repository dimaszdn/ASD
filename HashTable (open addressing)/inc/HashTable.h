#pragma once
#include<string>
#include<fstream>
#include<vector>

class HashTable
{
private:
    std::ofstream fout;
    std::vector<std::string> table;

public:
    explicit HashTable(size_t cap) : table(cap, " ")
    {

    }

    ~HashTable()
    {
        fout.close();
    }

    int hashFunc(const std::string& word)
    {
        //H(s0, s1, ..., sk) = s0 * p^size-1 + s1 * p^size-2 + ... + s_k * p^0 (s-коды букв, p-произвольная const, size - длина слова)
        auto base = 13;
        int hash = 0;
        auto mod = table.capacity();
        for (int i = 0; i < word.size(); ++i)
            hash += static_cast<int>(this->getCharCode(word[i]) * pow(base, word.size() - i - 1));
        return static_cast<int>(hash % mod);
    }

    void insert(const std::string& word)
    {
        int index = this->hashFunc(word);
        while (table[index] != " " && table[index] != word)
        {
            if (index == table.size() - 1)
                index = 0;
            ++index;
        }
        table[index] = word;
    }

    [[nodiscard]] size_t getCap() const { return table.capacity(); }

    void outputFile()
    {
        fout.open("files/Table.txt");
        std::string tmp;
        const int maxSizeWord = 15;
        const int maxCountDigit = static_cast<int>(std::to_string(this->getCap()).size());
        for (int i = 0; i < table.capacity(); ++i)
        {
            tmp = std::to_string(i);
            tmp.resize(maxCountDigit);
            fout << tmp << "|" << "\t";
            tmp = table[i];
            tmp.resize(maxSizeWord);
            fout << tmp << "\n";
        }
    }

private:
    int getCharCode(char letter)
    {
        return (std::tolower(letter) - 'a' + 1);
    }
};

std::vector<std::string> readFile(std::ifstream& fin)
{
    std::string word;
    std::vector<std::string> text;

    fin.open("files/Text.txt");
    if (!fin.is_open())
        throw std::exception("Text file not found!");
    else
    {
        while (fin >> word)
        {
            text.push_back(word);
        }
    }
    fin.close();

    return text;
}