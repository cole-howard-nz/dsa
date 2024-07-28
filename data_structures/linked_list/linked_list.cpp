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

void linked_list::insert_at(unsigned int index, int value)
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

void linked_list::delete_beginning()
{
    node* temp = head;
    head = head->next;
    delete temp;
}

void linked_list::delete_end()
{
    if (!head->next)
    {
        head = nullptr;
        return;
    }

    node* current = head;
    // run until we have second-to-last index
    while (current->next && current->next->next)
    {
        current = current->next;
    }
    // set second-to-last's next pointer to null
    // a.k.a second-to-last is now last
    current->next = nullptr;
}

void linked_list::delete_at(unsigned int index)
{
    if (index == 0)
    {
        delete_beginning();
        return;
    }

    node* current = head;
    for (unsigned int i = 0; current != nullptr && i < index-1; i++)
    {
        current = current->next;
    }

    if (current != nullptr && current->next != nullptr)
    {
        node* node_to_delete = current->next;
        current->next = current->next->next;
        delete node_to_delete;
    }
}

void linked_list::delete_value(int value)
{
    if (head->data == value)
    {
        delete_beginning();
        return;
    }

    node* current = head;
    while (current->next != nullptr && current->next->data != value)
    {
        current = current->next;
    }

    //std::cout << "debug: " << current->data << " " << current->next << std::endl;

    if (current->next != nullptr)
    {
        node* node_to_delete = current->next;
        current->next = current->next->next;
        delete node_to_delete;
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