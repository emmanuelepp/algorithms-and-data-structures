#include <vector>
#include <iostream>
// Time: O(N^2)
// Space: O(1)
class BubbleSort
{
public:
    std::vector<int> sort(std::vector<int> nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size() - 1; j++)
            {
                if (nums[j] > nums[j + 1])
                {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }

        return nums;
    }
};

int main()
{
    std::vector<int> list = {5, 4, 7, 9, 3, 8, 1, 0, 2};

    BubbleSort s;

    std::vector<int> sortedList = s.sort(list);

    for (int num : sortedList)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}