/*
给定一个字符串 s 和一个整数 k，从字符串开头算起, 每计数至 2k 个字符，就反转这 2k 个字符中的前 k 个字符。
如果剩余字符少于 k 个，则将剩余字符全部反转。
如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。

示例:

输入: s = "abcdefg", k = 2
输出: "bacdfeg"
*/

#include <string>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        // 不要写太多逻辑判断和计数，从for循环表达式上下手
        for (int i = 0; i < s.size(); i += (2 * k)) {
            // 每隔2k个字符，前k个反转
            // 剩余字符小于2k但大于等于k时，前k个反转
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k);
            } else {
                // 剩余字符少于k个，剩余全部反转
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};