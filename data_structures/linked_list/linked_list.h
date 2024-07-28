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
    void insert_at(int value, unsigned int index);

    void delete_beginning();
    void delete_end();
    void delete_at(unsigned int index);
    void delete_value(int value);

    void update_beginning(int value);
    void update_end(int value);
    void update_at(unsigned int index, int value);
    void update_value(int value, int new_value);
    
    unsigned int get_size();
    void print();
};