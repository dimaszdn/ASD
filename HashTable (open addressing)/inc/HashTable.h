#pragma once
#include<string>
#include<fstream>

struct Node
{
    char m_sym;
    int m_key;

    Node(char sym, int key) : m_sym{sym}, m_key{key}
    {}
};

class HashTable
{
private:
    std::ofstream fout;
    const int m_cap = 120;
    int m_size = 0;
    Node** table;

public:
    HashTable()
    {
        table = new Node*[m_cap];
        for (int i = 0; i < m_cap; ++i)
            table[i] = nullptr;
    }

    ~HashTable()
    {
        for (int i = 0; i < m_size; ++i)
        {
            if (table[i] != nullptr)
                delete table[i];
        }


        fout.close();
    }

    [[nodiscard]] bool isEmpty() const
    {
        if (m_size > 0)
            return true;
        return false;
    }

    int hashFunc()
    {

    }

    void insert(int key, const char sym)
    {
        Node* tmpNode = new Node(sym, key);

    }

    void readFile()
    {

    }

    void outputFile()
    {
        fout.open("files/Hash Table.txt");

    }
};