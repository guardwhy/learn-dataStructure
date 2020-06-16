#include <stdio.h>
#include <stdlib.h>

// 链表中的节点结构
typedef struct listStack{
    // 数据域
    int data;
    // 指针域
    struct liststack* next;
}listStack;

// stack为当前的链栈,a表示入栈元素
listStack* push(listStack* stack, int a){
    // 创建存储元素新节点
    listStack* node = (listStack*)malloc(sizeof(listStack));
    node->data = a;
    // 新节点和头节点建立联系
    node->next = stack;
    // 更改头指针的指向
    stack = node;
    return stack;
}

// 栈顶元素出栈
listStack* pop(listStack* stack){
    // 条件判断
    if(stack){
        // 声明一个新指针指向栈顶节点
        listStack* temp = stack;
        // 更新头指针
        stack = stack->next;
        printf("弹栈元素:%d ", temp->data);
        // 条件判断
        if(stack){
            printf("栈顶元素:%d\n", stack->data);
        } else{
            printf("该栈已经是空的..\n");
        }
        // 释放内存
        free(temp);
    } else{
        printf("该栈没有任何元素..");
        return stack;
    }
    return stack;
}

int main() {
    // 定义指针
    listStack* stack = NULL;
    // 入栈操作
    stack = push(stack,1);
    stack = push(stack,22);
    stack = push(stack,3);
    stack = push(stack,56);
    // 出栈操作
    stack = pop(stack);
    stack = pop(stack);
    stack = pop(stack);
    stack = pop(stack);
    stack = pop(stack);
    return 0;
}