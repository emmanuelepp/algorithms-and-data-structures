class Node
{
public:
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

    void enqueue(int value)
    {
        Node *newNode = new Node(value);
        if (tail == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        height++;
    }

    void dequeue()
    {
        if (head == nullptr)
        {
            return;
        }

        Node *current = head;
        head = head->next;
        delete current;
        height--;

        if (head == nullptr)
        {
            tail = nullptr;
        }
    }

    int getFront()
    {
        if (height == 0)
            return -1;
        return head->value;
    }

    int getBack()
    {
        if (tail == nullptr)
            return -1;
        return tail->value;
    }

    bool isEmpty()
    {
        return height == 0;
    }
};