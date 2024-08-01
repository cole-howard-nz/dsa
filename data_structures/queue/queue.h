struct node
{
    int data;
    node* next_node;

    node(int value);
};

class queue
{
private:
    node* front_node;
    node* rear_node;

public:
    queue();
    ~queue();

    void enqueue(int value);
    int dequeue();

    int peek_front();
    int peek_rear();
    bool is_empty();
    unsigned int get_size();

    void print();
};