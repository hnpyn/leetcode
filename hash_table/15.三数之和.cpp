/*
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？
请你找出所有满足条件且不重复的三元组。

注意： 答案中不可以包含重复的三元组。

示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为： [[-1, 0, 1], [-1, -1, 2]]
*/

#include <vector>
#include <unordered_set>

using namespace std;

// 哈希法不太合适，去重过程不好处理，容易出错，也没什么优势，仅供了解
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        // 先排序，便于处理
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            // 排序后第一个数大于0，无法凑成三元组
            if (nums[i] > 0) {
                return res;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {  // 第一个数去重
                continue;
            }
            unordered_set<int> set;
            for (int j = i + 1; j < nums.size(); ++j) {
                if (j > i + 2 && nums[j] == nums[j - 1] && nums[j - 1] == nums[j - 2]) {
                    // 第二个数去重
                    continue;
                }
                // 用哈希表寻找最后一个数
                int c = 0 - (nums[i] + nums[j]);
                if (set.find(c) != set.end()) {
                    res.push_back({nums[i], nums[j], c});
                    set.erase(c);  // 第三个数去重
                } else {
                    set.insert(nums[j]);
                }
            }
        }    
        return res;
    }
};