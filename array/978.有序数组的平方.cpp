/*
给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方
组成的新数组，要求也按 非递减顺序 排序。

示例 1： 输入：nums = [-4,-1,0,3,10] 输出：[0,1,9,16,100] 解释：平方后，数组变为
[16,1,0,9,100]， 排序后，数组变为 [0,1,9,16,100]

示例 2： 输入：nums = [-7,-3,2,3,11] 输出：[4,9,9,49,121]
*/

#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size() - 1;
    vector<int> res(nums.size());  // 新数组从后往前储存结果
    for (int left = 0, right = nums.size() - 1; left <= right;) {
      // 数组有序，平方最大的一定在两端，比较两端值，将平方加入新数组即可
      if (-nums[left] > nums[right]) {
        res[n] = nums[left] * nums[left];
        ++left;
      } else {
        res[n] = nums[right] * nums[right];
        --right;
      }
      --n;
    }
    return res;
  }
};
