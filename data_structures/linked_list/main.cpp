#include <iostream>
#include "linked_list.h"

int main()
{
    linked_list list = linked_list();
    linked_list list2 = linked_list();

    list.insert_beginning(50);
    list.insert_beginning(40);
    list.insert_beginning(30);
    list.insert_beginning(20);
    list.insert_beginning(10);
    list.delete_beginning();
    list.insert_beginning(69);
    list.delete_value(50);
    list.update_beginning(420);
    list.update_end(1337);
    list.update_at(2, 500);
    list.update_value(20, 666);
    list.insert_end(50);
    list.insert_end(50);
    list.insert_end(50);
    list.insert_end(50);
    list.insert_at(5, 100);
    list.update_beginning(99999); 
    list.print(list);

    std::cout << "The size of the linked list: " << list.get_size() << " elements." << std::endl;
    std::cout << "The size of the linked list: " << list2.get_size() << " elements." << std::endl;
}