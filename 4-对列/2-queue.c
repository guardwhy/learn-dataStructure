#include <stdio.h>
#define max 5 // 表示顺序表申请的空间大小

// 入队列操作
int enQueue(int* a, int front, int rear, int data){
    //当rear超过max,则直接将从a[0]重新开始存储,如果rear+1和front重合,表示数组已满。
    if((rear+1)%max == front){
        printf("队列空间已经满了");
        return rear;
    }
    a[rear%max] = data;
    rear++;
    return rear;
}
// 出队列操作
int deQueue(int* a, int front, int rear){
    // 如果front==rear,表示队列为空.
    if(front==rear%max){
        printf("队列为空..");
        return front;
    }
    printf("%d ", a[front]);
    // front+1同max进行比较,如果等于max,直接跳转到a[0]
    front = (front+1)%max;
    return front;
}
int main() {
    // 定义数组
    int a[max];
    // 对头指针
    int front;
    // 队尾指针
    int rear;
    // 当队列中没有元素的时候,对头和队尾都指向同一块地址
    front = rear = 0;
    // 入队列操作
    rear = enQueue(a, front,rear,1);
    rear = enQueue(a, front,rear,2);
    rear = enQueue(a, front,rear,3);
    rear = enQueue(a, front,rear,4);
    // 出队列操作
    front = deQueue(a, front, rear);
    // 再次入队列
    rear = enQueue(a,front, rear, 5);
    // 再次出队列
    front = deQueue(a, front, rear);
    // 再次入队列
    rear = enQueue(a, front, rear, 6);

    // 再次出队列
    front = deQueue(a, front, rear);
    front = deQueue(a, front, rear);
    front = deQueue(a, front, rear);
    front = deQueue(a, front, rear);
    return 0;
}