#include <iostream>
#include <vector>


unsigned int partition(std::vector<int>& list, unsigned int beginning, unsigned int end)
{
    unsigned int index = beginning;
    int pivot = list[end];
    for (unsigned int i = beginning; i < end; i++)
    {
        if (list[i] <= pivot)
        {
            int temp = list[index];
            list[index] = list[i];
            list[i] = temp;
            index++;
        }
    }
    int temp = list[index];
    list[index] = list[end];
    list[end] = temp;
    return index;
}

void quick_sort(std::vector<int>& list, unsigned int beginning, unsigned int end)
{
    if (beginning < end)
    {
        unsigned int index = partition(list, beginning, end);
        if (beginning < index)
        {
            quick_sort(list, beginning, index - 1);
        }
        if (index < end)
        {
            quick_sort(list, index + 1, end);
        }
    }
}

int main()
{
    std::vector<int> list = {9, 5, 2, 4, 7, 6, 8, 10, 5, 3, 1};
    quick_sort(list, 0, list.size() - 1);
    for (int value : list)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    return 0;
}