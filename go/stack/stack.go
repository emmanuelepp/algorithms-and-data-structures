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

type node struct {
	value int
	next  *node
}

type Stack struct {
	top *node
}

func (s *Stack) Push(value int) {
	newNode := &node{value: value}
	if s.top == nil {
		s.top = newNode
	} else {
		newNode.next = s.top
		s.top = newNode
	}
}

func (s *Stack) Pop() int {
	if s.top == nil {
		return -1
	}

	value := s.top.value

	s.top = s.top.next

	return value
}

func (s *Stack) Peek() int {
	if s.top == nil {
		return -1
	}

	return s.top.value
}

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
