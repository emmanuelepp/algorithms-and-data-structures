/*
A stack is a linear data structure that operates on the principle of LIFO (Last In, First Out).
This means that the last element added to the stack is the first one to be removed. You can visualize
a stack like a stack of plates: you add plates to the top, and the only plate you can remove is the one on the top.

The fundamental operations of a stack include:

Push: Add an element to the top of the stack.
Pop: Remove the element from the top of the stack.
Peek (or Top): Retrieve the top element without removing it.
IsEmpty: Check whether the stack is empty.
*/

/*
Stack (LIFO - Last In, First Out)

    |     |
    |     |
    |  5  |  <-- Top
    |  3  |
    |  1  |
    +-----+

    Push(7)
    |     |
    |  7  |  <-- Top
    |  5  |
    |  3  |
    |  1  |
    +-----+

    Pop() -> 7
    |     |
    |     |
    |  5  |  <-- Top
    |  3  |
    |  1  |
    +-----+
*/

package main

import "fmt"

// node represents an element in the stack.
type node struct {
	value int   // Stored value
	next  *node // Pointer to the next node
}

// Stack represents a LIFO (Last In, First Out) stack.
type Stack struct {
	top *node // Pointer to the top of the stack
}

// Push adds a new element to the top of the stack.
func (s *Stack) Push(value int) {
	newNode := &node{value: value}
	if s.top == nil {
		s.top = newNode
	} else {
		newNode.next = s.top // Link the new node to the current top
		s.top = newNode      // Update the top to the new node
	}
}

// Pop removes and returns the top element of the stack.
func (s *Stack) Pop() int {
	if s.top == nil {
		return -1
	}

	value := s.top.value // Store the value of the top element

	s.top = s.top.next // Move the top pointer to the next element

	return value
}

// Peek returns the first element of the stack without removing it.
func (s *Stack) Peek() int {
	if s.top == nil {
		return -1
	}

	return s.top.value
}

// IsEmpty checks if the stack is empty.
func (s *Stack) IsEmpty() bool {
	return s.top == nil
}

func (s *Stack) PrintStack() {
	current := s.top
	for current != nil {
		fmt.Println(current.value)
		current = current.next
	}
}

func main() {

	stack := &Stack{}

	stack.Push(10)
	stack.Push(8)
	stack.Push(9)

	stack.PrintStack()
}
