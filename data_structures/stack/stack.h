#pragma once
#include <unordered_map>

class stack
{
private:
    int* array;
    unsigned int capacity;
    unsigned int top_index;
    
    void resize_stack(unsigned int capacity);

public:
    stack(unsigned int capacity);
    ~stack();

    void push(int value);
    int pop();
    int peek();
    int is_empty();
    unsigned int get_size();
    void clear();
    int find(int value);
    int value_at(int index);

    void print();
};
