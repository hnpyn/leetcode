/*
题意：给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d，
使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例： 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。 
满足要求的四元组集合为： [[-1, 0, 0, 1], [-2, -1, 1, 2], [-2, 0, 0, 2]]
*/

#include <vector>
#include <unordered_set>

using namespace std;

// 该题同三数之和，增加一个循环即可，但是同样不适合哈希法，仅供了解
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        // 先排序是核心
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > target && nums[i] >= 0) {  // 剪枝，需注意nums[i] >= 0
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {  // 第一个数去重
                continue;
            }
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0) {  // 剪枝
                    break;
                }
                if (j > i + 1 && nums[j] == nums[j - 1]) {  // 第二个数去重
                    continue;
                }
                // 使用哈希表寻找满足题意的数，同两数之和，注意去重操作
                unordered_set<long> set;  // 使用long，不然溢出会导致结果出错
                for (int k = j + 1; k < nums.size(); ++k) {
                    // 第三个数去重
                    if (k > j + 2 && nums[k] == nums[k - 1] && nums[k - 1] == nums[k - 2]) {
                        continue;
                    }
                    // 注意使用long，避免溢出
                    long sum = (long) nums[i] + nums[j] + nums[k];
                    long d = (long) target - sum;
                    if (set.find(d) != set.end()) {
                        res.push_back({nums[i], nums[j], nums[k], (int) d});
                        set.erase(d);  // 第四个数去重
                    } else {
                        set.insert(nums[k]);
                    }
                }
            }
        }
        return res;
    }
};