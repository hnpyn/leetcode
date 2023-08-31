/*
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s
的长度最小的 连续 子数组， 并返回其长度。如果不存在符合条件的子数组，返回 0。

示例：
输入：s = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。

提示：
1 <= target <= 10^9
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^5
*/

#include <vector>

using namespace std;

class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    // 滑动窗口法
    int res = INT32_MAX;                     // 用于判断是否有子数组
    int sum = 0;                             // 子数组和
    int i = 0;                               // 窗口起始位置
    int subLength = 0;                       // 窗口长度
    for (int j = 0; j < nums.size(); ++j) {  // j为窗口结束位置
      sum += nums[j];
      // 注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
      while (sum >= target) {
        subLength = j - i + 1;  // 计算窗口长度
        res = res > subLength ? subLength : res;
        sum -= nums[i++];  // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
      }
    }
    // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
    return res == INT32_MAX ? 0 : res;
  }
};
