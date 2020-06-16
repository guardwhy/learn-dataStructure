#include <stdio.h>
#include <stdlib.h>

// 创建list结构体类型
typedef struct list{
    // 指向前驱指针域
    struct list* prior;
    // 数据域
    int data;
    // 指向后继的指针域
    struct list* next;
}list;

// 初始化双向链表
list* initList(list* head){
    // 创建头节点
    head = (list*)malloc(sizeof(list));
    // 前驱指针
    head->prior = NULL;
    head->next = NULL;
    head->data = 1;

    //声明一个指针指向头结点，用于遍历链表
    list* temp = head;
    for(int i=2; i<=7; i++){
        // 动态创建结点
        list* node = (list*)malloc(sizeof(list));
        // 前驱指针
        node->prior = NULL;
        // 后继指针
        node->next = NULL;
        // 数据域
        node->data = i;

        temp->next = node;
        node->prior = temp;
        temp = temp->next;
    }
    // 将链表的首尾结点进行双向连接
    temp->next = head;
    head->prior = temp;
    return head;
}

// 显示链表
void showList(list* head){
    // 定义指针变量,指向头节点
    list* p = head;
    // 条件判断,当遍历指针下一个结点是head时候,证明此时已经循环至链表的最后一个结点'
    while (p->next != head){
        if(p->next == NULL){
            printf("%d\n", p->data);
        }else{
            printf("%d->", p->data);
        }
        p = p->next;
    }
    // 输出循环链表的最后一个结点
    printf("%d", p->data);
}

int main() {
    // 定义指针
    list* head = NULL;
    head = initList(head);
    // 调用函数
    showList(head);
    return 0;
}