package main

import (
	"fmt"
)

type Node struct {
	value int
	next  *Node
}

type Stack struct {
	top *Node
}

func (s *Stack) Push(value int) {
	node := &Node{value: value}
	node.next = s.top
	s.top = node
}

func (s *Stack) Pop() {

}

func (s *Stack) Peek() {
	fmt.Printf("Stack")
}

func (s *Stack) IsEmpty() bool {
	return s.top == nil
}

func (s *Stack) Size() int {

	count := 0
	current := s.top

	for current != nil {
		count++
		current = current.next
	}

	return count
}

func (s *Stack) PrintStack() {
	current := s.top
	for current != nil {
		fmt.Printf("Stack value: %d\n", current.value)
		current = current.next
	}
}

func main() {

	stack := &Stack{}

	stack.Push(1)
	stack.Push(2)
	stack.Push(3)
	stack.Push(4)

	stack.PrintStack()
}
