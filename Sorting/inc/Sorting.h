#pragma once
#include<vector>
#include<iostream>

namespace ch
{
    template<typename T>
    class Sort
    {
    private:
        std::vector<T>& m_vec{nullptr};
        int m_size{0};

    public:
        Sort(std::vector<T>& vec) : m_vec(vec), m_size(vec.size())
        {
            if (m_vec.empty())
                throw std::out_of_range("Empty container!");
        }

        void comb_sort()
        {
            int dist = m_size;
            const double factor = 1.247;
            bool swapped = true;

            while (dist > 1 || swapped)
            {
                dist = dist / factor;
                if (dist < 1)
                    dist = 1;

                swapped = false;

                for (int i = 0; i < m_size - dist; ++i)
                {
                    if (m_vec[i] > m_vec[i + dist])
                    {
                        std::swap(m_vec[i], m_vec[i + dist]);
                        swapped = true;
                    }
                }
            }
        }

        void insertion_sort() //O(n^2) наихудший случай, когда элементы расположены по убыванию
        {
            int j = 0;
            for (int i = 1; i < m_size; ++i)
            {
                j = i - 1;
                while (j >= 0 && m_vec[j] >= m_vec[j + 1])
                {
                    std::swap(m_vec[j], m_vec[j + 1]);
                    --j;
                }
            }
        }

        void selection_sort() //O(n^2)
        {
            int min_index;
            for (int i = 0; i < m_size - 1; ++i)
            {
                min_index = i;
                for (int j = i + 1; j < m_size; ++j)
                {
                    if (m_vec[j] < m_vec[min_index])
                        min_index = j;
                }
                std::swap(m_vec[i], m_vec[min_index]);
            }
        }

        void shell_sort()
        {
            
        }

        void print_vec()
        {
            for (int i = 0; i < m_vec.size(); ++i)
                std::cout << m_vec[i] << " ";
            std::cout << "\n";
        }
    };
}
