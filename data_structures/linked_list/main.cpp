#include <iostream>
#include "linked_list.h"

int main()
{
    linked_list list = linked_list();
    list.insert_beginning(50);
    list.insert_beginning(40);
    list.insert_beginning(30);
    list.insert_beginning(20);
    list.insert_beginning(10);
    list.delete_beginning();
    list.insert_beginning(69);
    list.delete_value(50);
    list.print(list);
}