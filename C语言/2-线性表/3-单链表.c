#include <stdio.h>
#include <stdlib.h>

// 创建结构体LinkList
typedef struct LinkList{
    // 数据域
    char data;
    // 指针域
    struct LinkList* next;
}link;

// 链表初始化
link* initLink(){
    // 创建首节点
    link* head = (link*)malloc(sizeof(link));
    //声明一个指针指向头结点，用于遍历链表
    link * temp = head;
    // 从第二个节点开始创建
    for(int i=1; i<8; i++){
        //创建一个新节点并且开始初始化
        link* node = (link*)malloc(sizeof(link));
        node->data = i;
        node->next = NULL;
        // 将首节点和新建立的node节点建立关系
        temp->next = node;
        // 指针head每次都指向新链表的最后一个节点也就是node节点.
        temp = temp->next;
    }
    // 通过返回头指针可以找到整个链表
    return head;
}

// 链表插入元素,val表示新元素，site表示要插入链表的位置
link* insertLink(link* p, int data, int site){
    // 定义临时结点
    link* temp = p;
    // 首先找到要插入位置的上一个节点
    for(int i=1; i<site; i++){
        temp = temp->next;
        // 如果该节点为空
        if(temp == NULL){
            printf("插入位置无效\n");
            return p;
        }
    }
    // 创建插入新节点
    link* node = (link*)malloc(sizeof(link));
    node->data = data;
    // 向链表中插入节点
    node->next = temp->next;
    temp->next = node;

    // 返回临时节点
    return p;
}

// 删除链表元素,site表示要插入链表的位置
link* removeLink(link* p, int site){
    // 定义临时节点
    link* temp = p;
    // 遍历到删除节点的上一个节点
    for(int i=1; i<site; i++){
        temp = temp->next;
        // 判断是否存在该节点
        if(temp->next == NULL){
            printf("链表中没有该节点");
            return p;
        }
    }
    // 定义一个指针指向被删除的结点
    link* removeNode = temp->next;
    // 将结点从链表中摘下来,更改前一个结点的指针域
    temp->next = temp->next->next;
    // 手动释放该结点
    free(removeNode);
    return p;
}

// 查找链表元素
int findLink(link* p, int data){
    // 定义临时指针
    link* temp = p;
    // 定义变量
    int i = 1;
    // 条件判断
    while (temp->next){
        temp = temp->next;
        if(temp->data == data){
            return i;
        }
        i++;
    }
    // 查询失败
    return 0;
}

// 修改链表元素
link * updateLink(link* p, int site, int newData){
    // 定义指针变量
    link * temp = p;
    temp = temp->next;
    // 遍历
    for(int i=1; i<site; i++){
        temp = temp->next;
    }
    temp->data = newData;
    return p;
}
// 输出链表
void showLinkList(link* p){
    // 将首节点指针重新指向头节点
    link* temp = p;
    // 链表遍历
    while (temp->next){
        temp = temp->next;
        printf("%d ", temp->data);
    }
    printf("\n");
}

int main() {
    /**
     * 初始化链表
     */
    printf("初始化链表: \n");
    link* p = initLink();
    showLinkList(p);

    /**
     * 插入元素
     */
    printf("链表在4的位置插入元素33: \n");
    p = insertLink(p, 33, 4);
    showLinkList(p);

    /**
     * 删除元素
     */
    printf("删除链表中3: \n");
    p = removeLink(p, 3);
    showLinkList(p);

    /**
     * 查询元素
     */
    int site = findLink(p,2);
    printf("元素2的位置是:%d\n", site);
    showLinkList(p);

    /**
     * 修改元素
     */
    printf("修改5位置上的元素: \n");
    p = updateLink(p, 5, 66);
    showLinkList(p);
    return 0;
}