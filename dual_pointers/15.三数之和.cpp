/*
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a
+ b + c = 0 ？ 请你找出所有满足条件且不重复的三元组。

注意： 答案中不可以包含重复的三元组。

示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为： [[-1, 0, 1], [-1, -1, 2]]
*/

#include <unordered_set>
#include <vector>

using namespace std;

// 双指针
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > 0) {
        return res;
      }
      // 第一个数去重
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      int left = i + 1;
      int right = nums.size() - 1;
      while (right > left) {
        if ((nums[i] + nums[left] + nums[right]) < 0) {
          ++left;
        } else if ((nums[i] + nums[left] + nums[right]) > 0) {
          --right;
        } else {
          res.push_back({nums[i], nums[left], nums[right]});
          // 后两个数的去重应该放在找到第一个三元组之后
          while (right > left && nums[right] == nums[right - 1]) {
            --right;
          }
          while (right > left && nums[left] == nums[left + 1]) {
            ++left;
          }
          // 找到答案后，双指针同时收缩
          --right;
          ++left;
        }
      }
    }
    return res;
  }
};
