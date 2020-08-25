#include <stdio.h>
/**
 * 顺序栈代码实现
 * @param a
 * @param top
 * @param ele
 * @return
 */

// 元素ele进入栈
int push(int* a, int top, int ele){
    //等价于先执行 ++top，再执行 a[top]=ele
    a[++top] = ele;
    return top;
}

// 数据元素出栈
int pop(int* a, int top){
    // 条件判断
    if(top==-1){
        printf("该栈为空栈...");
        return -1;
    }
    printf("弹栈元素: %d\n", a[top]);
    top--;
    return top;
}

int main() {
    // 定义数组
    int a[20];
    // 定义top值
    int top = -1;
    // 入栈操作
    top = push(a, top, 2);
    top = push(a, top, 3);
    top = push(a, top, 4);
    top = push(a, top, 5);
    // 弹栈操作
    top = pop(a, top);
    top = pop(a, top);
    top = pop(a, top);
    top = pop(a, top);

    return 0;
}