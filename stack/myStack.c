/*//////////////////////////
            栈
//////////////////////////*/
// 栈的实现分为链表和数组
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10
#define INT_MAX 100000007

typedef struct ListNode {
    int val;            //节点数据
    struct ListNode *next;    //指向下一个节点的指针
}ListNode;

/* 链栈的实现 */
/* 基于链表实现的栈 */
typedef struct {
    ListNode *top; // 将头节点作为栈顶
    int size;      // 栈的长度
} LinkedListStack;

/* 构造函数 */
LinkedListStack *newLinkedListStack() {
    LinkedListStack *s = malloc(sizeof(LinkedListStack));
    s->top = NULL;
    s->size = 0;
    return s;
}

/* 析构函数 */
void delLinkedListStack(LinkedListStack *s) {
    while (s->top) {
        ListNode *n = s->top->next;
        free(s->top);
        s->top = n;
    }
    free(s);
}

/* 获取栈的长度 */
int size(LinkedListStack *s) {
    assert(s);
    return s->size;
}

/* 判断栈是否为空 */
bool isEmpty(LinkedListStack *s) {
    assert(s);
    return size(s) == 0;
}

/* 访问栈顶元素 */
int peek(LinkedListStack *s) {
    assert(s);
    assert(size(s) != 0);
    return s->top->val;
}

/* 入栈 */
void push(LinkedListStack *s, int num) {
    assert(s);
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->next = s->top; // 更新新加节点指针域
    node->val = num;     // 更新新加节点数据域
    s->top = node;       // 更新栈顶
    s->size++;           // 更新栈大小
}

/* 出栈 */
int pop(LinkedListStack *s) {
    if (s->size == 0) {
        printf("stack is empty.\n");
        return INT_MAX;
    }
    assert(s);
    int val = peek(s);
    ListNode *tmp = s->top;
    s->top = s->top->next;
    // 释放内存
    free(tmp);
    s->size--;
    return val;
}

//////////////////////////////////////////////////////////////////////
/* 基于数组实现的栈 */
typedef struct {
    int *data;
    int size;
} ArrayStack;

/* 构造函数 */
ArrayStack *newArrayStack() {
    ArrayStack *s = malloc(sizeof(ArrayStack));
    // 初始化一个大容量，避免扩容
    s->data = malloc(sizeof(int) * MAX_SIZE);
    s->size = 0;
    return s;
}

/* 获取栈的长度 */
int size(ArrayStack *s) {
    return s->size;
}

/* 判断栈是否为空 */
bool isEmpty(ArrayStack *s) {
    return s->size == 0;
}

/* 入栈 */
void push(ArrayStack *s, int num) {
    if (s->size == MAX_SIZE) {
        printf("stack is full.\n");
        return;
    }
    s->data[s->size] = num;
    s->size++;
}

/* 访问栈顶元素 */
int peek(ArrayStack *s) {
    if (s->size == 0) {
        printf("stack is empty.\n");
        return INT_MAX;
    }
    return s->data[s->size - 1];
}

/* 出栈 */
int pop(ArrayStack *s) {
    if (s->size == 0) {
        printf("stack is empty.\n");
        return INT_MAX;
    }
    int val = peek(s);
    s->size--;
    return val;
}

int main() {
    ArrayStack *stack = newArrayStack();
    for(int i = 0; i < 10; i++){
        push(stack, i);
    }
    while(!isEmpty(stack)) {
        printf("top: %d, pop: %d\n", peek(stack), pop(stack));
    }
    return 0;
}