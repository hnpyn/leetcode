/*
题意：给定一个链表，返回链表开始入环的第一个节点。如果链表无环，则返回 null。

为了表示给定链表中的环，使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

说明：不允许修改给定的链表。
*/

#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // // 解法一，hash表
        // unordered_set<ListNode*> hashTable;
        // // 遍历链表，记录每个节点
        // while (head != nullptr) {
        //     //如果重复出现，则链表存在环，且为该重复节点
        //     if (hashTable.count(head)) {
        //         return head;
        //     }
        //     hashTable.insert(head);
        //     head = head->next;
        // }
        // return nullptr;

        // 解法二，快慢指针
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr) {
            if (fast->next == nullptr) {
                return nullptr;
            }
            slow = slow->next;
            fast = fast->next->next;
            // 快慢指针必定在慢指针进环的第一圈内相遇
            if (slow == fast) {
                // 快慢指针相遇时，一个新指针从头节点出发
                ListNode* newPtr = head;
                while (true) {
                    // 新指针和慢指针一定相遇在入口处
                    if (slow == newPtr) {
                        return newPtr;
                    }
                    slow = slow->next;
                    newPtr = newPtr->next;
                }
            }
        }
        return nullptr;
    }
};