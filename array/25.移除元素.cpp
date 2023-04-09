#include<vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    // 快指针来获取新数组中的元素，慢指针来获取新数组中需要更新的位置
        int slow = 0;
        for (int fast = 0; fast < nums.size(); ++fast) {
            if (nums[fast] != val) {
                nums[slow] = nums[fast];  // 直接覆盖
                ++slow;
            }
        }
        return slow;
    }
};