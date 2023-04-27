/*
给定一个字符串，逐个翻转字符串中的每个单词。

示例 1：
输入: "the sky is blue"
输出: "blue is sky the"

示例 2：
输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。

示例 3：
输入: "a good   example"
输出: "example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
*/

#include <string>

using namespace std;

// 提升难度，不用API，O(1)空间复杂度
class Solution {
public:
    string reverseWords(string s) {
        // 先移除多余空格
        removeWhiteSpace(s);
        // 再对字符串整体反转
        reverse(s, 0, s.size() - 1);
        // 最后逐个单词反转
        int i = 0;
        for (int j = 0; j <= s.size(); ++j) {
            // 遇到空格或者到达字符串尾时反转
            if (s[j] == ' ' || j == s.size()) {
                reverse(s, i, j - 1);  // 反转是左闭右闭的
                i = j + 1;  // 移动到下一个单词开头位置
            }
        }
        return s;
    }
    
    void reverse(string& s, int start, int end) {
        // 按照索引反转字符串
        while (start < end) {
            swap(s[start++], s[end--]);
        }
    }

    void removeWhiteSpace(string& s) {
        // 删除多余空格，参照25.移除元素实现
        int slow = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {  // 遇到非空格时开始处理
                if (slow > 0) {  // slow > 0，说明不是第一个单词
                    s[slow++] = ' ';  // 在单词前添加空格
                }
                // 完成单词的移动，遇到空格说明单词结束
                while (i < s.size() && s[i] != ' ') {
                    s[slow++] = s[i++];
                }
            }
        }
        // slow所在的位置，就是字符串移除多余空格后的大小
        s.resize(slow);
    }
};