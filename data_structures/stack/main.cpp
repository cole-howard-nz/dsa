#include "stack.h"
#include <iostream>

int main()
{
    stack* s = new stack(2);

    s->push(50);
    s->push(69);
    s->print();
    s->pop();
    s->print();
    s->is_empty();
    std::cout << s->peek() << std::endl;
    s->push(69);
    s->push(69);
    s->push(69);
    s->push(69);
    s->push(69);
    s->push(69);
    s->push(69);
    std::cout << s->peek() << std::endl;
    s->print();
    std::cout << s->get_size() << std::endl;
    s->clear();
    s->print();
    s->push(50);
    s->print();
    return 0;
}