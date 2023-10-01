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
        Sort(std::vector<T>& vec) : m_vec(vec), m_size(vec.size()) {}

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

        void insertion_sort()
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
