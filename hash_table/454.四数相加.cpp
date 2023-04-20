/*
给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。

为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -2^28 到 2^28 - 1 之间，
最终结果不会超过 2^31 - 1 。

例如:

输入:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

输出: 2

解释:
两个元组如下:
(0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
(1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
*/

#include <vector>
#include <unordered_map>

using namespace std;

// 哈希表经典题目
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // key: nums1 + nums2; value: nums1 + nums2出现的次数
        unordered_map<int, int> res;
        for (auto a: nums1) {
            for (auto b: nums2) {
                ++res[a + b];
            } 
        }
        int count = 0;  // nums1 + nums2 + nums3 + nums4 出现的次数
        // 后面的过程类似于两数之和了，统计出现的次数即可
        for (auto c: nums3) {
            for (auto d: nums4) {;
                if (res.find(-c - d) != res.end()) {  // 0 - (c + d) = -c - d
                    count += res[-c - d];
                }
            }
        }
        return count;
    }
};