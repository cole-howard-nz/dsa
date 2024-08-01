#include <iostream>
#include "queue.h"


int main()
{
    queue* new_queue = new queue();
    new_queue->enqueue(1);
    new_queue->enqueue(5);
    new_queue->enqueue(10);
    new_queue->print();
    new_queue->dequeue();
    new_queue->print();
    return 0;
}