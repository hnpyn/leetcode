/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9

所以返回 [0, 1]
*/

#include <vector>
#include <unordered_map>

using namespace std;

// 梦开始的地方
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 经典哈希表题目
        unordered_map<int, int> nums_table;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums_table.find(target - nums[i]) != nums_table.end()) {
                return {nums_table[target - nums[i]], i};
            }
            nums_table[nums[i]] = i;
        }
        return {};
    }
};
