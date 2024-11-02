package main

import "fmt"

/*
A linked list is a dynamic data structure that consists of nodes linked together in a sequence. Unlike arrays, linked lists do not require memory to be contiguous, allowing for efficient insertion and deletion of nodes. This flexibility makes linked lists suitable for implementing various higher-level data structures like stacks, queues, and graphs.

Each node in a linked list contains at least two parts:

Data: The value stored in the node.
Next: A reference (or link) to the next node in the sequence.
You can visualize a linked list as a chain of nodes, where each node points to the next node in the line.

The fundamental operations of a linked list include:

Insertion: Add a node to the linked list. This can be done at the beginning, at the end, or between two nodes.
Deletion: Remove a node from the linked list. Similar to insertion, a node can be removed from any position in the list.
Traversal: Access each node of the linked list, usually starting from the first node, referred to as the head of the list, and moving through each link until the end of the list is reached (which is indicated by a null reference).
Search: Find a node in the linked list containing a given value.
*/

/*
Initial Linked List:
Head -> | 10 | -> | 20 | -> | 30 | -> | 40 | -> null

Insert(25) after 20:
Head -> | 10 | -> | 20 | -> | 25 | -> | 30 | -> | 40 | -> null

Delete(30):
Head -> | 10 | -> | 20 | -> | 25 | -> | 40 | -> null

*/

type node struct {
	value int
	next  *node
}

type LinkedList struct {
	head *node
	tail *node
}

func (ll *LinkedList) InsertElement(value int) {
	node := &node{value: value}

	if ll.head == nil {
		ll.head = node
		ll.tail = node
	} else {
		ll.tail.next = node
		ll.tail = node
	}
}

func (ll *LinkedList) DeleteElement(value int) bool {

	if ll.head == nil {
		return false
	}

	if ll.head.value == value {
		ll.head = ll.head.next
		if ll.head == nil {
			ll.tail = nil
		}

		return true
	}

	current := ll.head
	for current.next != nil {
		if current.next.value == value {
			current.next = current.next.next
			if current.next == nil {
				ll.tail = current
			}
			return true
		}

		current = current.next
	}

	return false
}

func (ll *LinkedList) PrintLinkedList() {
	current := ll.head
	for current != nil {
		fmt.Println(current.value)
		current = current.next
	}
}

func main() {

	linkedList := &LinkedList{}

	//fmt.Println(linkedList.IsEmpty())

	linkedList.InsertElement(10)
	linkedList.InsertElement(8)
	linkedList.InsertElement(9)

	linkedList.PrintLinkedList()

}
