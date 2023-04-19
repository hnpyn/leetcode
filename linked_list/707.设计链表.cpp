/*
题意：

在链表类中实现这些功能：

get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。

addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。

addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。

addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，
则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。

deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点.
*/

class MyLinkedList{
public:

    // 定义链表结构体
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    // 初始化链表
    MyLinkedList() {
        _size = 0;
        _dummyHead = new ListNode(0);  // 虚拟头节点
    }
    
    int get(int index) {
        // 注意index是从0开始的，0节点是头节点
        if (index > _size - 1) {
            return -1;
        }
        ListNode* cur = _dummyHead->next;
        while (index--) {  // 注意不能--index
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = _dummyHead->next;  // 继承虚拟头节点的next
        _dummyHead->next = newNode;
        _size += 1;
    }
    
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        ListNode* cur = _dummyHead;  // 如果此时没有真正的头节点，那么尾节点也是头节点
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = newNode;
        _size += 1;
    }
    
    void addAtIndex(int index, int val) {
        if (index > _size) {
            return;
        }
        ListNode* newNode = new ListNode(val);
        ListNode* cur = _dummyHead;  // 获取index节点的前一个节点
        while (index--) {
            cur = cur->next;
        }
        newNode->next = cur->next;  // 继承前一个节点的next
        cur->next = newNode;
        _size += 1;
    }
    
    void deleteAtIndex(int index) {
        if (index > _size - 1) {
            return;
        }
        ListNode* cur = _dummyHead;  // 获取index节点的前一个节点
        while (index--) {
            cur = cur->next;
        }
        ListNode* tmp = cur->next;  // 拿到要删除的节点
        cur->next = cur->next->next;  // 跳过index节点
        delete tmp;
        _size -= 1;
    }

private:
    int _size;
    ListNode* _dummyHead;
};