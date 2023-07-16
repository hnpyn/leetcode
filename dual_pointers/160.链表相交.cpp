/*
题意：给你两个单链表的头节点 headA 和
headB，请你找出并返回两个单链表相交的起始节点。 如果两个链表没有交点，返回
null。

题目数据保证整个链式结构中不存在环。
注意，函数返回结果后，链表必须保持其原始结构。
*/

#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == nullptr || headA == nullptr) {
      return NULL;
    }

    ListNode *curA = headA;
    int headALen = 0;
    while (curA != nullptr) {
      ++headALen;
      curA = curA->next;
    }

    ListNode *curB = headB;
    int headBLen = 0;
    while (curB != nullptr) {
      ++headBLen;
      curB = curB->next;
    }

    curA = headA;
    curB = headB;
    if (headALen < headBLen) {
      swap(headA, headB);
      swap(curA, curB);
    }
    int diff = abs(headALen - headBLen);
    for (int i = 0; i < diff; ++i) {
      curA = curA->next;
    }

    while (curA != nullptr) {
      if (curA == curB) {
        return curA;
      }
      curA = curA->next;
      curB = curB->next;
    }

    return NULL;
  }
};
