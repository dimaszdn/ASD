#pragma once
#include<vector>

void quick_sort(int mas[], int begin, int end)
{
    if (begin > end)
        return;

    int left = begin;
    int right = end;
    auto middle = mas[(begin + end) / 2];

    while (left <= right)
    {
        while (mas[left] < middle)
            ++left;
        while (mas[right] > middle)
            --right;
        if (left <= right)
        {
            std::swap(mas[left], mas[right]);
            ++left;
            --right;
        }
    }

    quick_sort(mas, begin, right);
    quick_sort(mas, left, end);
}