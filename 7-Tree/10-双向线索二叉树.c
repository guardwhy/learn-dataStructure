/**
 * 双向线索二叉树
 */
#include <stdio.h>
#include <stdlib.h>

// 树结点的数据类型,目前暂定为字符型
typedef char TElemType;
/**
 * 枚举，Link为0，Thread为1
 * @return
 */
typedef enum PointerTag{
    Link,
    Tag
}PointerTag;

/**
 * 结点结构
 * @return
 */
typedef struct BiThrNode{
    // 数据域
    TElemType data;
    // 指针域
    struct BiThrNode* lchild, *rchild;
    // 标志域,枚举类型
    PointerTag Ltag, Rtag;
}BiThrNode, *BiThrTree;

// 初始化
BiThrTree pre = NULL;

/**
 * 先序遍历初始化二叉树
 * @return
 */
void CreateTree(BiThrTree* tree){
    // 定义变量
    char data;
    // printf("请输入元素: \n");
    // 输入元素
    scanf("%c", &data);
    // 条件判断
    if(data != 's'){
        if(!((*tree)=(BiThrNode*)malloc(sizeof(BiThrNode)))){
            printf("申请结点空间失败--");
            return;
        } else{
            // 先序遍历初始化
            (*tree)->data = data;
            // 标志位指向
            (*tree)->Ltag = Link;
            (*tree)->Rtag = Link;
            // 初始化左右子树
            CreateTree(&((*tree)->lchild));
            CreateTree(&((*tree)->rchild));
        }
    } else{
        // 申请失败
        *tree = NULL;
    }
}

/**
 * 中序线索化
 * @return
 */
void InThreading(BiThrTree temp){
    // 判断条件
    if(temp){
        // 递归当前左子树,进行线索化
        InThreading(temp->lchild);
        // 如果当前结点没有左子树,左标志位设为1,左指针指向上一个结点
        if(!temp->lchild){
            temp->Ltag = Tag;
            temp->lchild = pre;
        }

        // 如果pre结点没有右子树,右标志位设为1,右指针域指向当前结点
        if(pre && !pre->rchild){
            pre->Rtag = Tag;
            pre->rchild = temp;
        }
        // 指向当前结点
        pre = temp;
        // 调用函数
        InThreading(temp->rchild);
    }
}

/**
 * 双向线索链表
 * @return
 */
void InOrderThread(BiThrTree* head, BiThrTree s){
    // 初始化头节点
    (*head) = (BiThrTree)malloc(sizeof(BiThrNode));
    // 条件判断
    if((*head) == NULL){
        printf("申请内存失败...");
        return;
    }
    (*head)->rchild = *head;
    (*head)->Rtag = Link;
    // 条件判断该树是否是空树
    if(!s){
        (*head)->lchild = *head;
        (*head)->Ltag = Link;
    } else{
        // pre指向头节点
        pre = *head;
        // 头节点左子树设为根节点
        (*head)->lchild = s;
        (*head)->Ltag = Link;
        // 线索化二叉树
        InThreading(s);
        // pre节点指向中序序列中的最后一个节点
        pre->rchild = *head;
        pre->Rtag = Tag;
        (*head)->rchild = pre;
    }
}
/**
 * 中序遍历双向线索二叉树
 * @return
 */
void InOrderThraverse(BiThrTree head){
    BiThrTree temp;
    // temp指向根节点
    temp = head->lchild;
    // 条件判断
    while (temp != head){
        // 当ltag=0时候,循环到中序序列的第一个节点
        while (temp->Ltag == Link){
            temp = temp->lchild;
        }
        // 操作结点数据
        printf("%c ", temp->data);

        // 当节点右标志位1时候,直接找到其后继结点
        while (temp->Rtag == Tag && temp->rchild != head){
            temp = temp->rchild;
            printf("%c ", temp->data);
        }
        // 寻找右子树最左下的结点
        temp = temp->rchild;
    }
}
int main() {
    // 结构体变量
    BiThrTree s;
    BiThrTree head;
    printf("输入先序二叉数:\n");
    // 调用函数
    CreateTree(&s);
    InOrderThread(&head, s);
    printf("输出中序遍历: \n");
    // 调用函数
    InOrderThraverse(head);
    return 0;
}