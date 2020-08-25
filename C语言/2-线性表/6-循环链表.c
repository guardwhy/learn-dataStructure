#include <stdio.h>
#include <stdlib.h>
/**
 * 循环链表实现
 * @return
 */
typedef struct node{
    // 属性
    int number;
    struct node* next;
}person;

// 初始化链表
person* initLink(int n){
    // 首结点
    person* head = (person*)malloc(sizeof(person));
    head->number = 1;
    head->next = NULL;
    person* cyclic = head;
    // 遍历循环
    for(int i=2; i<=n; i++){
        person* temp = (person*)malloc(sizeof(person));
        temp->number = i;
        temp->next = NULL;
        cyclic->next = temp;
        cyclic = cyclic->next;
    }
    // 首尾相连
    cyclic->next = head;
    return head;
}

// 查找
void findList(person* head, int k, int j){
    person* tail = head;
    // 找到链表第一个结点的上一个结点.
    while (tail->next != head){
        tail = tail->next;
    }
    person* p = head;
    // 找到编号为k的人
    while (p->number!=k){
        tail = p;
        p = p->next;
    }
    //从编号为k的人开始，只有符合p->next==p时，说明链表中除了p结点，所有编号都出列.
    while (p->next!=p){
        // 找到从p报数1开始，报m的人，并且还要知道数j-1人的位置tail.
        for(int i=1; i<j; i++){
            tail = p;
            p = p->next;
        }
        // 从链表上将p拿下来
        tail->next = p->next;
        printf("出列人的编号为:%d\n", p->number);
        free(p);
        // 使用指针指向下一个编号
        p = tail->next;
    }
    printf("出列人的编号为:%d\n",p->number);
    free(p);
}

int main() {
    printf("请输入教室的人数:");
    // 定义变量
    int n;
    scanf("%d", &n);
    person* head = initLink(n);

    printf("从第k人开始报数(k>1且k<%d):",n);
    int k;
    scanf("%d", &k);

    printf("数到j的人出列:");
    int j;
    scanf("%d", &j);
    findList(head, k, j);
    return 0;
}