using System;
class Node
{
    public int Value;
    public Node Next;

    public Node(int value)
    {
        Value = value;
        Next = null;
    }
}


class LinkedList
{
    private Node Head;
    private Node Tail;
    private int Length;

    public LinkedList()
    {
        Head = null;
        Tail = null;
        Length = 0;
    }

    public void PrintValues()
    {
        Node current = Head;

        while (current != null)
        {
            Console.WriteLine(current.Value);
            current = current.Next;
        }
    }

    public bool IsEmpty()
    {
        return Length == 0;
    }

    //The Append method adds a new node to the end of the list, updating Tail and the list's length.
    public void Append(int value)
    {
        Node newNode = new Node(value);

        if (Head == null)
        {
            Head = newNode;
            Tail = newNode;
        }
        else
        {
            Tail.Next = newNode;
            Tail = newNode;
        }

        Length++;
    }
}


class Program
{
    public static void Main()
    {
        LinkedList list = new LinkedList();

        list.Append(10);
        list.Append(20);
        list.Append(30);

        list.PrintValues();

    }

}