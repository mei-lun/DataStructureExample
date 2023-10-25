#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode {
    int val;            //节点数据
    struct ListNode *next;    //指向下一个节点的指针
}ListNode;
/*//////////////////////////////////
             链队
//////////////////////////////////*/
/* 基于链表实现的队列 */
typedef struct {
    ListNode *front, *rear;
    int queSize;
} LinkedListQueue;

/* 构造函数 */
LinkedListQueue *newLinkedListQueue() {
    LinkedListQueue *queue = (LinkedListQueue *)malloc(sizeof(LinkedListQueue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->queSize = 0;
    return queue;
}

/* 析构函数 */
void delLinkedListQueue(LinkedListQueue *queue) {
    // 释放所有节点
    for (int i = 0; i < queue->queSize && queue->front != NULL; i++) {
        ListNode *tmp = queue->front;
        queue->front = queue->front->next;
        free(tmp);
    }
    // 释放 queue 结构体
    free(queue);
}

/* 获取队列的长度 */
int size(LinkedListQueue *queue) {
    return queue->queSize;
}

/* 判断队列是否为空 */
bool empty(LinkedListQueue *queue) {
    return (size(queue) == 0);
}

/* 入队 */
void push(LinkedListQueue *queue, int num) {
    // 尾节点处添加 node
    ListNode *node = newListNode(num);
    // 如果队列为空，则令头、尾节点都指向该节点
    if (queue->front == NULL) {
        queue->front = node;
        queue->rear = node;
    }
    // 如果队列不为空，则将该节点添加到尾节点后
    else {
        queue->rear->next = node;
        queue->rear = node;
    }
    queue->queSize++;
}

/* 访问队首元素 */
int peek(LinkedListQueue *queue) {
    assert(size(queue) && queue->front);
    return queue->front->val;
}

/* 出队 */
void pop(LinkedListQueue *queue) {
    int num = peek(queue);
    ListNode *tmp = queue->front;
    queue->front = queue->front->next;
    free(tmp);
    queue->queSize--;
}

/* 打印队列 */
void printLinkedListQueue(LinkedListQueue *queue) {
    int arr[] = malloc(size(queue->queSize));
    // 拷贝链表中的数据到数组
    int i;
    ListNode *node;
    for (i = 0, node = queue->front; i < queue->queSize; i++) {
        arr[i] = node->val;
        node = node->next;
    }
    printArray(arr, queue->queSize);
}
