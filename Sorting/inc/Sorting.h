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
            T tmp;
            const int N = 5;
            int i, j, dist;
            int a[N];
            a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;
            for (int k = 0; k < N; ++k)
            {
                dist = a[k];
                for (i = dist; i < m_size; ++i)
                {
                    tmp = m_vec[i];
                    for (j = i - dist; (j >= 0) && (m_vec[j] >= tmp); j = j - dist)
                    {
//                        std::cout << "[" << dist << "]" << " ";
//                        this->print_vec1(j + dist, j);
                        m_vec[j + dist] = m_vec[j];
                        m_vec[j] = tmp;
//                        std::cout <<"After: ";
//                        this->print_vec1(j + dist, j);
//                        std::cout << "\n";
                    }
                }
            }
        }

        //**********************************
        void counting_sort(int exp)
        {
            const int maxDigit = 10;
            std::vector<int> count(maxDigit, 0);
            std::vector<T> output(m_vec.capacity());

            for (int i = 0; i < m_size; ++i)
                count[(m_vec[i] / exp) % 10]++; //(512 / 100) % 10, exp = 100 in this instance

            for (int i = 1; i < maxDigit; ++i)
                count[i] += count[i - 1];

            for (int i = m_size - 1; i >= 0; --i)
            {
                output[count[(m_vec[i] / exp) % 10] - 1] = m_vec[i];
                count[(m_vec[i] / exp) % 10]--;
            }

            for (int i = 0; i < output.size(); ++i)
                std::cout << output[i] << " ";
            std::cout << "\n\n";

            for (int i = 0; i < m_size; ++i)
                m_vec[i] = output[i];
        }

        void radix_sort()
        {
            T max = this->getMax();
            for (int exp = 1; max / exp > 0; exp = exp * 10)
                this->counting_sort(exp);
        }
        //***********************************

        void print_vec1(int x, int y)
        {
            for (int i = 0; i < m_vec.size(); ++i)
            {
                if (i == x || i == y)
                {
                    std::cout << "|" << m_vec[i] << "|" << " ";
                }
                else
                    std::cout << m_vec[i] << " ";
            }
//            std::cout << "\n";
        }

        void print_vec()
        {
            for (int i = 0; i < m_vec.size(); ++i)
            {
                std::cout << m_vec[i] << " ";
            }
            std::cout << "\n";
        }

    private:
        T getMax()
        {
            T max = m_vec[0];
            for (int i = 1; i < m_size; ++i)
            {
                if (m_vec[i] > max)
                    max = m_vec[i];
            }
            return max;
        }
    };
}
