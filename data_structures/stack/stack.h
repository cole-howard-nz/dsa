#pragma once
#include <unordered_map>

class stack
{
private:
    int* array;
    unsigned int capacity;
    unsigned int top_index;
    std::unordered_map<int, unsigned int> stack_map;
    
    void resize_stack(unsigned int capacity);

public:
    stack(unsigned int capacity);
    ~stack();

    const std::unordered_map<int, unsigned int> get_map();

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
