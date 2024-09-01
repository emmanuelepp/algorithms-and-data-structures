/*
A queue is a linear data structure that operates on the principle of FIFO (First In, First Out).
This means that the first element added to the queue is the first one to be removed. You can visualize
a queue like a line of people waiting for a service: the first person in line is the first one to be served,
and new people join the end of the line.

The fundamental operations of a queue include:

Enqueue: Add an element to the end of the queue.
Dequeue: Remove the element from the front of the queue.
Front (or Peek): Retrieve the front element without removing it.
IsEmpty: Check whether the queue is empty.
*/

/*
Queue (FIFO - First In, First Out)

Front -> |  1  |  3  |  5  | <- Rear

    Enqueue(7)
Front -> |  1  |  3  |  5  |  7  | <- Rear

    Dequeue() -> 1
Front -> |  3  |  5  |  7  | <- Rear
*/

package main

import (
	"fmt"
)

// node represents an element in the queue.
type node struct {
	value int   // Stored value
	next  *node // Pointer to the next node
}

// Queue represents a FIFO queue with a head and tail pointer.
type Queue struct {
	head *node // Front of the queue (where elements are dequeued)
	tail *node // End of the queue  (where elements are enqueued)
}

// Enqueue adds a new element to the end of the queue.
func (q *Queue) Enqueue(value int) {
	newNode := &node{value: value} // Create a new node with the given value

	if q.head == nil {
		q.head = newNode
		q.tail = newNode
	} else {
		q.tail.next = newNode // Link the new node at the end of the queue
		q.tail = newNode      // Update the tail to the new node
	}
}

// Dequeue removes and returns the front element of the queue.
func (q *Queue) Dequeue() int {
	if q.head == nil {
		return -1
	}

	value := q.head.value // Store the value of the front node
	q.head = q.head.next  // Move the head to the next node

	if q.head == nil {
		q.tail = nil
	}

	return value
}

// Peek returns the value of the front element without removing it.
func (q *Queue) Peek() int {

	if q.head == nil {
		return -1
	}
	return q.head.value
}

// IsEmpty checks if the queue is empty.
func (q *Queue) IsEmpty() bool {
	return q.head == nil
}

func (q *Queue) PrintQueue() {
	current := q.head
	for current != nil {
		fmt.Println(current.value)
		current = current.next
	}
}

func main() {

	queue := &Queue{}

	fmt.Println(queue.IsEmpty())

	queue.Enqueue(10)
	queue.Enqueue(8)
	queue.Enqueue(9)

	fmt.Println(queue.IsEmpty())

	queue.PrintQueue()

}
