/*
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target，
写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

示例 1:
输入: nums = [-1,0,3,5,9,12], target = 9     
输出: 4       
解释: 9 出现在 nums 中并且下标为 4     

示例 2:
输入: nums = [-1,0,3,5,9,12], target = 2     
输出: -1        
解释: 2 不存在 nums 中因此返回 -1        

提示：
你可以假设 nums 中的所有元素是不重复的。
n 将在 [1, 10000]之间。
nums 的每个元素都将在 [-9999, 9999]之间。
*/

#include<vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;  // 左闭
        int right = nums.size() - 1;  // 右闭
        while (left <= right) {  // 左闭右闭区间包含左右相等的情况
            int mid = left + (right - left) / 2;  // 避免溢出
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                left = mid + 1;  // mid已做过判断，不应在包含在区间内，所以+1
            } else {
                right = mid - 1;  //同上
            }
        }
        return -1;
    }
};