/*
给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串 ransom 能不能由第二个字符串 magazines 
里面的字符构成。如果可以构成，返回 true ；否则返回 false。

(题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。杂志字符串中的每个字符只能在赎金信字
符串中使用一次。)

注意：

你可以假设两个字符串均只含有小写字母。

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // 题目给定小写字母前提条件，可用数组来代替哈希表，速度更快，更省空间
        vector<int> res(26, 0);

        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        // 记录magazine中各个字符出现的次数
        for (int i = 0; i < magazine.size(); ++i) {
            ++res[magazine[i] - 'a'];
        }
        // 遍历ransomNote，减去对应字符的个数
        for (int i = 0; i< ransomNote.size(); ++i) {
            --res[ransomNote[i] - 'a'];
            // 如果小于0，说明magazine没能覆盖ransomNote
            if (res[ransomNote[i] - 'a'] < 0) {
                return false;
            }
        }
        // 走到这里，说明符合条件
        return true;
    }
};