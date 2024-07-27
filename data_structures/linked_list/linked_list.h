#pragma once


struct node
{
    int data;
    node* next;

    node(int value);
};

class linked_list
{
private:
    node* head;
public:
    linked_list();
    ~linked_list();

    void insert_beginning(int value);
    void insert_end(int value);
    void insert_at(int value, int index);
    
    void print(linked_list& list);
};