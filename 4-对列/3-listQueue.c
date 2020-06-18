#include <stdio.h>
#include <stdlib.h>
/**
 * 链式队列实现
 * @return
 */
 // 链表中的节点结构
typedef struct ListQueue{
    // 数据域
    int data;
    // 指针域
    struct list* next;
}list;

// 初始化链式队列函数
list* initQueue(){
    // 创建一个头节点
    list* queue = (list*)malloc(sizeof(list));
    // 对头节点进行初始化
    queue->next = NULL;
    // 返回头节点
    return queue;
}
// 链式队列数据入队
list* enQueue(list* rear, int data){
    // 1.用节点包裹入队元素
    list* enNode = (list*)malloc(sizeof(list));
    enNode->data = data;
    enNode->next = NULL;
    // 2.新节点和队尾节点建立逻辑关系
    rear->next = enNode;
    // 3.队尾节点指向新节点
    rear = enNode;
    // 返回新的队尾节点,为新的元素入队做准备
    return rear;
}

list* DeQueue(list* top, list* rear){
    // 条件判断
    if(top->next == NULL){
        printf("\n队列为空...");
        return rear;
    }
    // 定义一个新指针指向即将出队的节点
    list* p = top->next;
    printf("%d", p->data);
    // 建立联系
    top->next = p->next;
    // 条件判断
    if(rear == p){
        rear = top;
    }
    // 释放节点
    free(p);
}

int main() {
    // 创建队尾指针和对头指针
    list* queue, *top, *rear;
    // 创建头节点
    queue = top = rear = initQueue();
    // 添加节点
    rear = enQueue(rear,1);
    rear = enQueue(rear,2);
    rear = enQueue(rear,3);
    rear = enQueue(rear,4);

    // 入队完成,所有的数据元素开始出队列
    rear= DeQueue(top, rear);
    rear = DeQueue(top, rear);
    rear = DeQueue(top, rear);
    rear = DeQueue(top, rear);
    rear = DeQueue(top, rear);
    return 0;
}