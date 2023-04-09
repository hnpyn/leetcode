#include<vector>

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