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