/*
编写一个算法来判断一个数 n 是不是快乐数。

快乐数定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。如果 可以变为  1，那么这个数就是快乐数。

如果 n 是快乐数就返回 True ；不是，则返回 False 。

示例：

输入：19
输出：true
解释：
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
*/

#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> res;
        while (true) {
            if (n == 1) {
                return true;
            }
            
            n = getSum(n);

            // 如果sum重复出现，说明进入循环，不会是快乐数了
            // 这其实是进入了一个环形链表，可以推算一下
            if (res.find(n) != res.end()) {
                return false;
            } else {
                res.insert(n);
            }
        }
    }

    // 计算各个位数平方和
    int getSum(int n) {
        int sum = 0;
        while (n > 0) {
            int r = n % 10;
            sum += r * r;
            n /= 10;
        }
        return sum;
    }
};