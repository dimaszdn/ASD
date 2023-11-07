#pragma once
#include<vector>
#include<iostream>

namespace ch
{
    std::vector<int> random_fill(int countEl, int begin, int end)
    {
        srand(time(0));
        std::vector<int> random;
        for (int i = 0; i < countEl; ++i)
            random.push_back(begin + rand() % (end - begin + 1));
        return random;
    }

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

        void insertion_sort()
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

        void selection_sort()
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
                        m_vec[j + dist] = m_vec[j];
                        m_vec[j] = tmp;
                    }
                }
            }
        }

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

        void merge_sort(int begin, int end)
        {
            if (end - begin < 2) //если один элемент
                return;

            if (end - begin == 2) //если пара
            {
                if (m_vec[begin] > m_vec[begin + 1])
                    std::swap(m_vec[begin], m_vec[begin + 1]);
                return;
            }

            int mid = (begin + end) / 2; //делим пополам
            merge_sort(begin, mid);
            merge_sort(mid, end);

            //сливаем половины нужным образом
            std::vector<int> output;
            int b_part1 = begin;
            int e_part1 = (begin + end) / 2;
            int b_part2 = e_part1;
            while (output.size() < end - begin)
            {
                if (b_part1 >= e_part1 || (b_part2 < end && m_vec[b_part1] > m_vec[b_part2]))
                {
                    output.push_back(m_vec[b_part2]);
                    ++b_part2;
                }
                else
                {
                    output.push_back(m_vec[b_part1]);
                    ++b_part1;
                }
            }

            //перезаписываем
            for (int i = begin; i < end; ++i)
                m_vec[i] = output[i - begin];
        }

        void quick_sort(int begin, int end)
        {
            if (begin > end)
                return;

            int left = begin;
            int right = end;
            auto middle = m_vec[(begin + end) / 2];

            while (left <= right)
            {
                while (m_vec[left] < middle)
                    ++left;
                while (m_vec[right] > middle)
                    --right;
                if (left <= right)
                {
                    std::swap(m_vec[left], m_vec[right]);
                    ++left;
                    --right;
                }
            }

            quick_sort(begin, right);
            quick_sort(left, end);
        }

        void heapify(int root, int size)
        {
            int max = root;
            int lChild = 2 * root + 1;
            int rChild = 2 * root + 2;

            if (lChild < size && m_vec[lChild] >= m_vec[max])
                max = lChild;

            if (rChild < size && m_vec[rChild] >= m_vec[max])
                max = rChild;

            if (max != root)
            {
                std::swap(m_vec[root], m_vec[max]);
                heapify(max, size); //рекурсивно вызываемся для поддерева
            }
        }

        void heap_sort()
        {
            for (int i = (m_size / 2) - 1; i >= 0; --i)
                heapify(i, m_size);

            for (int i = m_size - 1; i >= 0; --i)
            {
                std::swap(m_vec[0], m_vec[i]);
                heapify(0, i);
            }
        }

        void print_vec()
        {
            for (int i = 0; i < m_vec.size(); ++i)
            {
                std::cout << m_vec[i] << " ";
            }
            std::cout << "\n";
        }

        int getSize()
        {
            return m_size;
        }

    private:
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