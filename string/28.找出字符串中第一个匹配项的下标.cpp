/*
给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle
字符串出现的第一个位置 (从0开始)。 如果不存在，则返回  -1。

示例 1: 输入: haystack = "hello", needle = "ll" 输出: 2

示例 2: 输入: haystack = "aaaaa", needle = "bba" 输出: -1

说明: 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
对于本题而言，当 needle 是空字符串时 我们应当返回 0 。这与C语言的 strstr() 以及
Java的 indexOf() 定义相符。
*/

#include <string>

using namespace std;

class Solution {
public:
  void getNext(int *next, const string &s) {
    int j = 0;                           // 前缀末尾
    next[0] = 0;                         // 前缀表
    for (int i = 1; i < s.size(); ++i) { // i 从i开始，i为后缀末尾
      // 前后缀不匹配时
      while (j > 0 && s[i] != s[j]) {
        j = next[j - 1];
      }
      // 前后缀匹配时，j+1，i+1（在for 循环中完成）
      if (s[i] == s[j]) {
        ++j;
      }
      // 更新前缀表
      next[i] = j;
    }
  }

  int strStr(string haystack, string needle) {
    int next[needle.size()];
    getNext(next, needle);
    int j = 0;
    for (int i = 0; i < haystack.size(); ++i) {
      // 字符串不匹配时，查询前一位的前缀表，对模式串进行回退，
      while (j > 0 && haystack[i] != needle[j]) {
        j = next[j - 1];
      }
      if (haystack[i] == needle[j]) {
        ++j;
      }
      // 模式串完全匹配时，j与模式串size相等（因为上一个if会对j加一）
      if (j == needle.size()) {
        // 此时i减去j再加上上一个if中对j多加的一个1，即为第一匹配项的下标
        return (i - needle.size() + 1);
      }
    }
    return -1;
  }
};
