#include <iostream>
#include "linked_list.h"


node::node(int value) : data(value), next(nullptr) {}

linked_list::linked_list() : head(nullptr) {}

linked_list::~linked_list()
{
    // if there is a head
    while (head)
    {
        // create temp variable
        node* temp = head;
        // get next in line for next iteration
        head = head->next;
        // delete current head
        delete temp;
    }
}

void linked_list::insert_beginning(int value)
{
    node* new_node = new node(value);
    new_node->next = head;
    linked_list::head = new_node;
}

void linked_list::insert_end(int value)
{
    node* current = head;
    while (current->next)
    {
        current = current->next;
    }
    node* new_node = new node(value);
    current->next = new_node;
}

void linked_list::insert_at(int index, int value)
{
    node* new_node = new node(value);
    if (index == 0)
    {
        node* temp = head;
        head = new_node;
        new_node->next = temp;
    } 
    else
    {
        node* temp = head;
        for (unsigned int i = 0; temp != nullptr && i < index-1; i++)
        {
            temp = temp->next;
        }

        if (temp != nullptr)
        {
            // flip node at index with new node
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }
}

void linked_list::print(linked_list& list)
{
    node* current = list.head;
    while (current)
    {
        int value = current->data;
        std::cout << value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}





int main()
{
    linked_list list = linked_list();
    list.insert_beginning(50);
    list.insert_beginning(60);
    list.insert_end(100);
    list.insert_at(3, 15);
    list.print(list);
}