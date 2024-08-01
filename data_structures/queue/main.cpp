#include <iostream>
#include "queue.h"


int main()
{
    queue* new_queue = new queue();
    new_queue->enqueue(5);
    new_queue->enqueue(6);
    new_queue->enqueue(7);
    new_queue->enqueue(8);
    new_queue->print();
    new_queue->dequeue();
    new_queue->print();
    std::cout << "Size of queue is: " << new_queue->get_size() << std::endl;
    std::cout << "Front of queue: " << new_queue->peek_front() << std::endl;
    std::cout << "Rear of queue: " << new_queue->peek_rear() << std::endl;
    new_queue->print();
    return 0;
}