/*
题意：给你两个单链表的头节点 headA 和 headB，请你找出并返回两个单链表相交的起始节点。
如果两个链表没有交点，返回 null。

题目数据保证整个链式结构中不存在环。
注意，函数返回结果后，链表必须保持其原始结构。
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 注意是指针相等，不是数值相等
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 0, lenB = 0;
        // 求A的长度
        while (curA != nullptr) {
            curA = curA->next;
            ++lenA;
        }
        // 求B的长度
        while (curB != nullptr) {
            curB = curB->next;
            ++lenB;
        }
        // 求长度差，并将curA和curB放置在同一起点
        int diff = 0;
        curA = headA;
        curB = headB;
        if (lenA > lenB) {
            diff = lenA - lenB;
            while (diff--) {
                curA = curA->next;
            }
        } else {
            diff = lenB - lenA;
            while (diff--) {
                curB = curB->next;
            }
        }
        // 遍历A，B，遇到相同的直接返回
        while (curA != nullptr) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }

        return nullptr;
    }
};