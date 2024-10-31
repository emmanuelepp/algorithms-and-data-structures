#include <iostream>
class Node
{
public:
    int value;
    Node *next;
    Node(int value) : value(value), next(nullptr) {}
};

class Stack
{
private:
    Node *top;
    int height;

public:
    Stack() : top(nullptr), height(0) {}

    void printStack()
    {
        Node *current = top;
        while (current)
        {
            std::cout << current->value << std::endl;
            current = current->next;
        }
    }

    void push(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        height++;
    }

    void pop()
    {
        if (top == nullptr)
            return;
        Node *newNode = top;
        top = top->next;
        delete newNode;
        height--;
    }

    bool isEmpty()
    {
        return height == 0;
    }
    int getTop()
    {
        if (top == nullptr)
            return -1;
        return top->value;
    }

    int getSize()
    {
        return height;
    }
};