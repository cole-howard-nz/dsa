#include "queue.h"
#include <iostream>


node::node(int value)
{
    data = value;
    next_node = nullptr;
}

queue::queue()
{
    front_node = nullptr;
    rear_node = nullptr;
}

queue::~queue()
{
    while (!is_empty())
    {
        dequeue();
    }   
}

void queue::enqueue(int value)
{
    node* new_node = new node(value);
    if (rear_node)
    {
        rear_node->next_node = new_node;
    }
    rear_node = new_node;
    if (!front_node)
    {
        front_node = new_node;
    }
}

int queue::dequeue()
{
    if (is_empty())
        return -1;

    node* temp_node = front_node;
    int value = temp_node->data;
    front_node = front_node->next_node;

    if (!front_node)
        rear_node = nullptr;
    delete temp_node;
    return value;
}

int queue::peek_front()
{
    return front_node->data;
}

int queue::peek_rear()
{
    return rear_node->data;
}

bool queue::is_empty()
{
    if (front_node == nullptr)
        std::cout << "Queue is empty." << std::endl;
    return (front_node == nullptr);
}

unsigned int queue::get_size()
{
    unsigned int counter = 0;
    node* temp_node = front_node;
    while (temp_node != nullptr)
    {
        temp_node = temp_node->next_node;
        counter++;
    }
    return counter;
}

void queue::print()
{
    if (is_empty())
        return;

    node* current_node = front_node;
    while (current_node != nullptr)
    {
        std::cout << current_node->data << " ";
        current_node = current_node->next_node;
    }
    std::cout << std::endl;

}