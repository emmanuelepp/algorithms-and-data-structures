#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;

bool push ( Node** top, int value)
{
    Node* newNode = malloc(sizeof *newNode);
    if (!newNode) return false;

    newNode->data = value;
    newNode->next = *top;
    *top = newNode;

    return true;
}

bool pop (Node** top, int* value)
{
    if (!top || !*top) return false;

    Node* temp = *top;
    if (value) *value = temp->data;
    *top = (*top)->next;
    free(temp);

    return true;
}

int peek(Node* top)  
{
    if(!top) return -1; 
    
    return top->data;
}

int size(Node* top)
{
    int count = 0;
    for(Node* cur = top; cur; cur = cur->next) count++;

    return count;
}

bool isEmpty( Node* top ) {
    return top == NULL;
}

void clearMemory(Node** top) {
    while (*top) {
        Node* next = (*top)->next;
        free(*top);
        *top = next;
    }
}

void printStack(void)
{
    const Node* current = top;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main()
{
    push(&top, 0);
    push(&top, 2);
    push(&top, 4);
    printStack();

    clearMemory(&top);

    return 0;
}

