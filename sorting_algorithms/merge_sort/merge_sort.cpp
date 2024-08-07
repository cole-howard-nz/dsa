#include <iostream>
#include <vector>

void merge(std::vector<int>& list, unsigned int left, unsigned int middle, unsigned int right)
{
    unsigned int left_size = middle - left + 1;
    unsigned int right_size = right - middle;
    std::vector<int> left_half(left_size);
    std::vector<int> right_half(right_size);

    for (unsigned int i = 0; i < left_size; i++)
    {
        left_half[i] = list[left + i];
    }
    for (unsigned int i = 0; i < right_size; i++)
    {
        right_half[i] = list[middle + 1 + i];
    }

    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int a = left;
    while (i < left_size && j < right_size)
    {
        if (left_half[i] <= right_half[j])
        {
            list[a] = left_half[i];
            i++;
        }
        else
        {
            list[a] = right_half[j];
            j++;
        }
        a++;
    }
    while (i < left_size)
    {
        list[a] = left_half[i];
        i++;
        a++;
    }
    while (j < right_size)
    {
        list[a] = right_half[j];
        j++;
        a++;
    }
}

void merge_sort(std::vector<int>& list, unsigned int left, unsigned int right)
{
    if (left < right)
    {
        unsigned int middle = left + (right - left) / 2;
        if (left < middle)
        {
            merge_sort(list, left, middle);
        }
        if (middle + 1 < right)
        {
            merge_sort(list, middle + 1, right);
        }
        merge(list, left, middle, right);
    }
}

int main()
{
    std::vector<int> list = {9, 5, 2, 4, 7, 6, 8, 10, 5, 3, 1};
    merge_sort(list, 0, list.size() - 1);
    for (int value : list)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    return 0;
}
