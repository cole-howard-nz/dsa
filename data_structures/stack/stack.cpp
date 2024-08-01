#include "stack.h"
#include <iostream>
#include <unordered_map>

void stack::resize_stack(unsigned int capacity)
{
    int* new_array = new int[capacity]; 
    for (unsigned int i = 0; i < top_index; i++)
    {
        new_array[i] = array[i];
    }
    delete[] array;
    array = new_array;
    stack::capacity = capacity;
}

stack::stack(unsigned int capacity)
{
    stack::capacity = capacity;
    top_index = 0;
    array = new int[capacity];
}

stack::~stack()
{
    delete[] array;
}

void stack::push(int value)
{
    if (top_index == capacity)
    {
        resize_stack(capacity * 2);
    }

    array[top_index] = value;
    top_index++;
}

int stack::pop()
{
    if (is_empty())
    {
        std::cout << "Stack is empty, nothing to pop." << std::endl;
        return -1;
    }
    int value = array[top_index];
    top_index--;

    // Resizing logic if full of empties.
    if (top_index > 0 && top_index == capacity / 4)
    {
        resize_stack(capacity / 2);
    }

    return value;
}

int stack::peek()
{
    return array[top_index-1];
}

int stack::is_empty()
{
    std::cout << "Stack is " << (top_index==0 ? "empty." : "not empty.") << std::endl;
    return top_index == 0;
}

unsigned int stack::get_size()
{
    return top_index;
}

void stack::clear()
{
    top_index = 0;
    resize_stack(2);
}

int stack::find(int value)
{
    for (unsigned int i = 0; i < capacity; i++)
    {
        if (array[i] == value)
            return i;
    }
    return -1;
}

int stack::value_at(int index)
{
    // scuffed as, i tried to free the memory but had issues.
    // if a stack is large and then is "cleared" the values
    // higher in the stack (which are now 'removed') still
    // exist in memory.

    // this check just stops us from accessing it lol
    if (array[index] && index <= top_index - 1)
        return array[index];
    return -1;
}

void stack::print()
{
    for (unsigned int i = 0; i < top_index; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}