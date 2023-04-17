/*
给定两个字符串 s 和 t，编写一个函数来判断 t 是否是 s 的字母异位词。

注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。

示例 1: 输入: s = "anagram", t = "nagaram" 输出: true

示例 2: 输入: s = "rat", t = "car" 输出: false

说明: 你可以假设字符串只包含小写字母。
*/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // 方法一，先排序，然后直接比较，省略
        // 方法二，哈希表
        if (s.length()!= t.length()) {
            return false;
        }
        // 数组作为一个简单的哈希表，下标即为key
        vector<int> record(26, 0);
        for (auto ch: s) {
            // 减去'a'，将ASCII码映射到 0-25，对应数组下标
            record[ch - 'a']++;
        }
        for (auto ch: t) {
            record[ch - 'a']--;
            // 不是字母异位词，必然会出现小于0的情况
            if (record[ch - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};