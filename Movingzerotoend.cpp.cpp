#include <vector>
#include<algorithm>
std::vector<int> move_zeroes(const std::vector<int>& input) {
    // your code here
    std::vector<int> nums;
    nums.assign(input.begin(), input.end());
    int left = -1;
    unsigned int second = 0;
    for (second = 0; second < nums.size(); second++)
    {
        if (nums[second] != 0)
        {
            left++;
            std::swap(nums[left], nums[second]);
        }
    }
    return nums;
}