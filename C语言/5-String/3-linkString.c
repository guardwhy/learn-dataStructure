#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 设置全局链表中存储数据的个数
#define linkNum 3

// 设置结构体类型link
typedef struct Link{
    // 数据域
    char a[linkNum];
    // 指针域
    struct Link* next;
}link;

// 初始化链表,head为头指针,str为存储字符串
link* initLink(link* head, char* str){
    // 字符串长度
    int length = strlen(str);
    // 字符串的个数
    int num = length/linkNum;
    // 条件判断
    if(length%linkNum){
        num++;
    }
    // 创建并初始化首节点
    head = (link*)malloc(sizeof(link));
    head->next = NULL;
    // 定义指针变量
    link* temp = head;
    // 初始化链表
    for(int i=0; i<num; i++){
        int j=0;
        for(; j<linkNum; j++){
            // 条件判断
            if(i*linkNum + j < length){
                temp->a[j] = str[i*linkNum + j];
            }else{
                temp->a[j] ='#';
            }
        }
        // 条件判断
        if(i*linkNum + j < length){
            // 创建新的节点
            link* newlink = (link*)malloc(sizeof(link));
            // 建立关联
            newlink->next = NULL;
            temp->next = newlink;
            temp = newlink;
        }
    }

    // 返回节点
    return head;
}

// 输出链表
void showList(link* head){
    link* temp = head;
    while (temp){
        for(int i=0; i < linkNum; i++){
            printf("%c", temp->a[i]);
        }
        temp = temp->next;
    }
}

int main() {
    // 定义头指针
    link* head = NULL;
    // 初始化函数
    head = initLink(head, "wwqe.guardwhy is mvp.com");
    showList(head);
    return 0;
}