#include <stdio.h>
#include <stdlib.h>

// 链表最大数值
#define maxSize 6

// 创建结构体
typedef struct{
    // 数据域
    int data;
    // 游标域
    int cur;
}component;

// 创建备用链表
void reserveArray(component *array){
    // 遍历
    for(int i=0; i<maxSize; i++){
        // 将每个数组分量链接到一起
        array[i].cur = i+1;
        array[i].data = -1;
    }
    // 最后一个结点的游标为0
    array[maxSize-1].cur = 0;
}

// 分配空间
int mallocArray(component* array){
    //若备用链表非空，则返回分配的结点下标，否则返回0
    int i = array[0].cur;
    if(array[0].cur){
        array[0].cur = array[i].cur;
    }
    return i;
}

// 初始化静态链表
int initArray(component* array){
    // 调用函数
    reserveArray(array);
    int p = mallocArray(array);
    // 定义一个变量,将他当作指针使用，指向链表的最后一个结点。
    int temp = p;
    for(int i=1; i<4; i++){
        // 从备用链表中拿出空闲的容量
        int a = mallocArray(array);
        //将申请的空闲分量链接在链表的最后一个结点后面
        array[temp].cur = a;
        // 给新申请的分量的数据域初始化
        array[a].data = i;
        // 指向链表的最后一个结点的指针后移'
        temp = a;
    }
    // 新链表最后一个结点指针设置为0
    array[temp].cur = 0;
    return p;
}

// 遍历
void showArray(component* array, int p){
    int temp = p;
    // 遍历
    while(array[temp].cur){
        printf("%d,%d", array[temp].data, array[temp].cur);
        temp = array[temp].cur;
    }
    printf("%d,%d", array[temp].data, array[temp].cur);
}
int main() {
    // 声明变量
    component array[maxSize];
    int p = initArray(array);
    printf("静态链表为:\n");
    // 调用函数
    showArray(array, p);
    return 0;
}