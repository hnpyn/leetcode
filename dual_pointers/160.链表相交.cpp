/*
题意：给你两个单链表的头节点 headA 和
headB，请你找出并返回两个单链表相交的起始节点。 如果两个链表没有交点，返回
null。

题目数据保证整个链式结构中不存在环。
注意，函数返回结果后，链表必须保持其原始结构。
*/

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
