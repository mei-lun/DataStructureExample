#include <stdio.h>
#include <stdlib.h>

/*///////////////////////////////
            单向链表
/*//////////////////////////////
//数据结构
typedef struct ListNode {
    int val;            //节点数据
    struct ListNode *next;    //指向下一个节点的指针
}ListNode;
//创建链表节点的构造函数
ListNode *newListNode(int val) {
    ListNode *node, *next;
    node = (ListNode *) malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

ListNode *initLinkedList() {
    /* 初始化链表 0 -> 1 -> 2 -> 3 -> 4 */
    ListNode* n0 = newListNode(0);
    ListNode* n1 = newListNode(1);
    ListNode* n2 = newListNode(2);
    ListNode* n3 = newListNode(3);
    ListNode* n4 = newListNode(4);
    // 构建指引指向
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    return n0;
}

/* 删除链表的节点 n0 之后的首个节点 */
void removeItem(ListNode* n0) {
    if (!n0->next) return;
    // n0 -> P ->n1
    // 删除
    ListNode *P = n0->next;
    ListNode *n1 = P->next;
    n0->next = n1;
    free(P);
}

/* 访问链表节点 */
ListNode *accessNode(ListNode *head, int index) {
    while (head && head->next && index) {
        head = head->next;
        index--;
    }
    return head;
}

/* 查找节点 */
int findNode(ListNode *head, int target) {
    int index = 0;
    while(head) {
        if(head->val == target) return index;
        head = head->next;
        index++;
    }
    return -1;
}

// 遍历查看链表中的元素
void showLinkedList(ListNode* n0) {
    while (n0->next) {
      printf("%d ", n0->val);
      n0 = n0->next;  
    }
    printf("\n");
}

int main() {
    ListNode* head = initLinkedList();
    showLinkedList(head);
    removeItem(head);
    showLinkedList(head);
    ListNode *node = accessNode(head, 2);
    printf("%d", node->val);
    return 0;
}