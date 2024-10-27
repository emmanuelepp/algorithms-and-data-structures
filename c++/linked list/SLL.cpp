#include <iostream>

class Node
{
public:
    int value;
    Node *next;
    Node(int value) : value(value), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;
    Node *tail;
    int length;

public:
    LinkedList(int value) : head(new Node(value)), tail(head), length(1) {}

    void printList() const
    {
        Node *current = head;

        while (current != nullptr)
        {
            std::cout << current->value << std::endl;
            current = current->next;
        }
    }

    bool isEmpty() const
    {
        return length == 0;
    }

    void append(int value)
    {
        Node *newNode = new Node(value);
        if (isEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void prepend(int value)
    {
        Node *newNode = new Node(value);
        if (length == 0)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    void deleteLast()
    {
        if (length == 0)
            return;

        Node *current = head;
        if (length == 1)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            while (current->next != tail)
            {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
        }

        length--;
    }

    void deleteFirts()
    {
        if (length == 0)
            return;

        Node *current = head;
        if (length == 1)
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
        }

        delete current;
        length--;
    }

    Node *get(int index)
    {
        if (index < 0 || index >= length)
            return nullptr;

        Node *current = head;

        for (int i = 0; i < index; ++i)
        {
            current = current->next;
        }
        return current;
    }

    bool set(int index, int value)
    {
        if (index < 0 || index >= length)
            return false;

        Node *current = get(index);
        if (current)
        {
            current->value = value;
            return true;
        }
        return false;
    }

    bool insert(int index, int value)
    {
        if (index < 0 || index > length)
            return false;
        if (index == 0)
        {
            prepend(value);
            return true;
        }

        if (index == length)
        {
            append(value);
            return true;
        }

        Node *newNode = new Node(value);
        Node *current = get(index - 1);
        newNode->next = current->next;
        current->next = newNode;
        length++;
        return true;
    }

    void deleteNode(int index)
    {
        if (index < 0 || index > length)
            return;
        if (index == 0)
            return deleteFirts();
        if (index == length - 1)
            return deleteLast();

        Node *prev = get(index - 1);
        Node *current = prev->next;

        prev->next = current->next;
        delete current;
        length--;
    }

    void reverse()
    {
        if (head == nullptr || head == tail)
        {
            return;
        }

        Node *current = head;
        Node *previous = nullptr;
        Node *next = nullptr;

        tail = head;

        while (current != nullptr)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }

        head = previous;
    };

    int main()
    {
        LinkedList *SLL = new LinkedList(5);
        SLL->printList();
        SLL->append(11);
        SLL->printList();
    }
};
