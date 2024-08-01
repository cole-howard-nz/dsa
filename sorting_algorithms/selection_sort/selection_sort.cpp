#include <iostream>
#include <vector>


void selection_sort(std::vector<int>& list)
{
    unsigned int length = list.size();
    for (unsigned int i = 0; i < length; i++)
    {
        unsigned int minimum_index = i;
        for (unsigned int j = i+1;  j < length; j++)
        {
            if (list[j] < list[minimum_index])
            {
                minimum_index = j;
            }
        }
        unsigned int temp = list[minimum_index];
        list[minimum_index] = list[i];
        list[i] = temp;       
    }
}

int main()
{
    std::vector<int> list = {9, 5, 2, 4, 7, 6, 8, 10, 5, 3, 1};
    selection_sort(list);
    for (int value : list)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    return 0;
}