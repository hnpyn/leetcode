/*
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

示例 1： 输入：s = "We are happy."
输出："We%20are%20happy."
*/

#include <string>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        // 该方法可以优化空间复杂度
        int count = 0;
        int sOldSize = s.size();
        // 统计空格数
        for (auto ch: s) {
            if (ch == ' ') {
                ++count;
            }
        }
        // 将字符串延长到替换后的长度
        s.resize(s.size() + count * 2);
        int sNewSize = s.size();
        // 双指针从后往前替换空格
        for (int i = sNewSize - 1, j = sOldSize - 1; j < i; --i, --j) {
            if (s[j] != ' ') {
                s[i] = s[j];
            } else {
                s[i] = '0';
                s[i - 1] = '2';
                s[i - 2] = '%';
                i -= 2;  // 前移多填充的字符个数
            }
        }
        return s;
    }
};