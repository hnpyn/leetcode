/*
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

示例 1： 输入：s = "We are happy."
输出："We%20are%20happy."
*/

#include <string>

using namespace std;

class Solution {
public:
  // 方法一，占用额外的空间
  // string replaceSpace(string s) {
  //     string newS;
  //     for (char ch: s) {
  //         if (ch == ' ') {
  //             newS.push_back('%');
  //             newS.push_back('2');
  //             newS.push_back('0');
  //         } else {
  //             newS.push_back(ch);
  //         }
  //     }
  //     return newS;
  // }
  // 方法二，原数组上直接操作
  string replaceSpace(string s) {
    int n = s.size();
    if (n == 0)
      return s;
    int count = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == ' ') {
        ++count;
      }
    }
    s.resize(n + count * 2);
    for (int i = n - 1, j = s.size() - 1; i < j; --i) {
      if (s[i] == ' ') {
        s[j--] = '0';
        s[j--] = '2';
        s[j--] = '%';
      } else {
        s[j--] = s[i];
      }
    }
    return s;
  }
};
