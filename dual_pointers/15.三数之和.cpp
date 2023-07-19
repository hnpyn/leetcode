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
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      unordered_set<int> set;
      for (int j = i + 1; j < nums.size(); ++j) {
        if (j > i + 2 && nums[j] == nums[j - 1] && nums[j - 1] == nums[j - 2]) {
          continue;
        }
        int c = 0 - (nums[i] + nums[j]);
        if (set.find(c) != set.end()) {
          res.push_back({nums[i], nums[j], c});
          set.erase(c);
        } else {
          set.insert(nums[j]);
        }
      }
    }
    return res;
  }
};
