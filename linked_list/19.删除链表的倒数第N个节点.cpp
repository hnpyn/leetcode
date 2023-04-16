/*
题意：给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

进阶：你能尝试使用一趟扫描实现吗？
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 经典快慢双指针法
        ListNode* dummyHead = new ListNode(0, head);  // 虚拟头节点，方便删除操作
        ListNode* fast = dummyHead;
        ListNode* slow = dummyHead;
        // fast指针先走n步
        while(n-- && fast != nullptr) {
            fast = fast->next;
        }
        // 控制slow指针走到要删除的节点的上一个节点
        // 此时fast指针指向尾节点
        while(fast->next != nullptr) {  
            fast = fast->next;
            slow = slow->next;
        }
        // 删除节点，释放内存
        ListNode* tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;

        return dummyHead->next;
    }
};