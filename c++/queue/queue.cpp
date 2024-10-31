class Node
{
private:
    int value;
    Node *next;

    Node(int value) : value(value), next(nullptr) {}
};

class Queue
{
private:
    Node *head;
    Node *tail;
    int height;

public:
    Queue() : head(nullptr), tail(nullptr), height(0) {}

    // TODO: functions.
};