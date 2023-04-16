/*
题意：
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0, head);  // 虚拟头节点方便操作
        ListNode* cur = dummyHead;  // 当前节点
        while (cur->next != nullptr && cur->next->next != nullptr) {  // 要交换的两个节点不能为null
            ListNode* tmp1 = cur->next;  // 记录第一个临时节点
            ListNode* tmp2 = cur->next->next->next;  // 记录第二个临时节点

            cur->next = cur->next->next;  // 步骤一
            cur->next->next = tmp1;  // 步骤二，连个节点交换
            cur->next->next->next = tmp2;  // 步骤三

            cur = cur->next->next;  // cur移动两位，准备下一轮交换
        }
        return dummyHead->next;
    }
};