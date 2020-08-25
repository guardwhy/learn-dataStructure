#include <stdio.h>
#include <stdlib.h>
/**
 * 双向链表
 * @return
 */
typedef struct dbList{
    // 指向前驱指针域
    struct dbList* prior;
    // 数据域
    int data;
    // 指向后继指针域
    struct dbList* next;
}dbList;

// 链表初始化声明
dbList* initList(dbList* head);
// 显示链表
void showList(dbList* head);
// 链表添加元素
dbList* insertList(dbList* head, int data, int site);
// 删除结点
dbList* removeList(dbList* head, int data);

// 查找节点
int findList(dbList* head, int ele);
// 更新结点
dbList* updateList(dbList* head, int site, int newEle);

int main() {
    // 创建头指针
    dbList* head = NULL;
    // 双向链表初始化
    head = initList(head);
    // 显示链表
    showList(head);
    // 在表中第2的位置插入元素88
    head = insertList(head, 88, 2);
    showList(head);

    // 删除元素4
    head = removeList(head, 4);
    showList(head);

    // 查找元素
    printf("元素88的位置是: %d\n", findList(head, 88));

    // 修改元素
    head = updateList(head, 4,9);
    showList(head);
    return 0;
}

// 链表初始化调用
dbList* initList(dbList* head){
    // 创建首节点,双向链表的头指针是head
    head = (dbList*)malloc(sizeof(dbList));
    // 初始化节点
    head->prior = NULL;
    head->next = NULL;
    head->data = 1;
    // 声明一个指向首节点的指针,方便后期向链表中添加新创的节点
    dbList * list = head;
    for(int i=2; i<6; i++){
        // 创建新的节点并且初始化
        dbList* node = (dbList*)malloc(sizeof(dbList));
        node->prior = NULL;
        node->next = NULL;
        node->data = i;

        // 新节点和末节点建立关系
        list->next=node;
        node->prior=list;
        // 指针永远指向链表最后一个节点
        list = list->next;
    }
    // 返回创建的新链表
    return head;
}
// 调用链表
void showList(dbList* head){
    // 定义临时节点
    dbList* temp = head;
    // 判断条件
    while (temp){
        // 如果该节点下一个节点是NULL,则表明是最后一个节点
        if(temp->next == NULL){
            printf("%d\n", temp->data);
        }else{
            printf("%d <->", temp->data);
        }
        temp=temp->next;
    }
}
// 链表添加节点
dbList* insertList(dbList* head, int data, int site){
    // 新建数据域data节点
    dbList* temp = (dbList*)malloc(sizeof(dbList));
    temp->next = NULL;
    temp->prior = NULL;
    temp->data = data;
    // 插入到链表的头部
    if(site==1){
        temp->next = head;
        head->prior = temp;
        head = temp;
    } else{
        // 声明节点
        dbList* node = head;
        // 找到要插入位置的前一个结点
        for(int i=1; i<site-1; i++){
            node = node->next;
        }
        // 条件判断
        if(node->next == NULL){
            node->next = temp;
            temp->prior = node;
        } else{
            node->next->prior = temp;
            temp->next = node->next;
            node->next = temp;
            temp->prior = node;
        }
    }

    return head;
}
// 链表删除结点
dbList* removeList(dbList* head, int data){
    dbList* temp = head;
    // 条件判断
    while (temp){
        // 判断该结点中的数据域和data是否相等,如果相等,摘除该结点
        if(temp->data==data){
            temp->prior->next = temp->next;
            temp->next->prior = temp->prior;
            // 释放空间
            free(temp);
            return head;
        }
        temp = temp->next;
    }
    printf("链表中没有该数据元素...");
    return head;
}
// 查找链表中的结点
int findList(dbList* head, int ele){
    // 定义一个指针p,初始化头指针head
    dbList* p = head;
    // 定义变量结点
    int i = 1;
    while(p){
        if(p->data == ele){
            return i;
        }
        i++;
        p = p->next;
    }
    // 查找失败
    return -1;
}
// 更新结点
dbList* updateList(dbList* head, int site, int newEle){
    // 定义指针变量
    dbList* temp = head;
    // 遍历到删除的结点
    for(int i=1; i<site; i++){
        temp = temp->next;
    }
    temp->data = newEle;
    return head;
}