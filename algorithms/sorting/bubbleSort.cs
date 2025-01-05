using System;

public static void BubbleSort(int[] nums)
{
    for (int i = 0; i < nums.Length; i++)
    {
        for (int j = 0; j < nums.Length - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}

public static void Main()
{
    int[] numbers = { 42, 7, 19, 88, 4, 73, 25, 11, 39, 2 };

    // Unordered Array
    Console.WriteLine("Arreglo desordenado:");
    foreach (int number in numbers)
    {
        Console.Write(number + " ");
    }
    Console.WriteLine();

    BubbleSort(numbers);

    // Ordered Array
    Console.WriteLine("Arreglo ordenado:");
    foreach (int number in numbers)
    {
        Console.Write(number + " ");
    }
    Console.WriteLine();
}

