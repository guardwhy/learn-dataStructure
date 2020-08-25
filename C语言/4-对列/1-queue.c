#include <stdio.h>
/**
 * 顺序队列
 * @return
 */
 // 入队列操作
 int enQueue(int* a, int rear, int data){
     a[rear] = data;
     rear++;
     return rear;
 }

 // 出队列操作
 void deQueue(int* a, int front, int rear){
     // 如果front == rear,表示队列为空
     while (front!=rear){
         printf("出队列的元素: %d\n", a[front]);
         front++;
     }
 }
int main() {
    // 定义数组
    int a[10];
    // 设置对头指针
    int front;
    // 设置队尾指针
    int rear;
    // 当队列中没有元素,对头和队尾指向同一块地址
    front = rear = 0;
    // 入队操作
    rear = enQueue(a,rear,1);
    rear = enQueue(a,rear,2);
    rear = enQueue(a,rear,3);
    rear = enQueue(a,rear,4);
    rear = enQueue(a,rear,5);

    // 出列
    deQueue(a,front,rear);
    return 0;
}