#include <vector>
#include <iostream>


void insertion_sort(std::vector<int>& list)
{
    unsigned int size = list.size();
    for (unsigned int i = 1; i < size; i++)
    {
        int current = list[i];
        int sorted = i-1;
        while (sorted >= 0 && list[sorted] > current)
        {
            list[sorted + 1] = list[sorted]; 
            sorted--;
        }
        list[sorted + 1] = current;
    }
}

int main()
{
    std::vector<int> list = {9, 5, 2, 4, 7, 6, 8, 10, 5, 3, 1};
    insertion_sort(list);
    for (int value : list)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    return 0;
}