/*
给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。

示例 1:
输入: "abab"
输出: True
解释: 可由子字符串 "ab" 重复两次构成。

示例 2:
输入: "aba"
输出: False

示例 3:
输入: "abcabcabcabc"
输出: True
解释: 可由子字符串 "abc" 重复四次构成。 (或者子字符串 "abcabc" 重复两次构成。)
*/

#include <string>

using namespace std;

// KMP 算法
class Solution {
public:
    void getNext(int* next, const string& s) {
        int j = 0;
        next[0] = j;
        for (int i = 1; i < s.size(); ++i) {
            while(j > 0 && s[j] != s[i]) {
                j = next[j - 1];
            }
            if (s[j] == s[i]) {
                ++j;
            }
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern(string s) {
        if (s.size() == 1) {
            return false;
        }
        int next[s.size()];
        getNext(next, s);
        int len = s.size();
        /* 
        字符串长度减去最长相同前后缀的长度（当字符串是由重复子串构成的时候，
        next数组的最后一位必然是最长相同前后缀长度）相当于是一个周期的长度，
        如果这个周期可以被整除，就说明整个字符串就是这个周期的循环。
        */
        if (next[len - 1] > 0 && len % (len - next[len - 1]) == 0) {
            return true;
        }
        return false;
    }
};
