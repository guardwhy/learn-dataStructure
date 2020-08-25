/**
 * 先序遍历,递归实现
 */
#include <stdio.h>
#include <stdlib.h>
// 树结点的数据类型,目前暂定为整型
typedef int TElemType;
/**
 * 结点结构
 * @return
 */
typedef struct PtNode{
    // 结点数据
    TElemType data;
    // 左右孩子指针
    struct PtNode *lchild, *rchild;
}PtNode, *PtTree;

/**
 *初始化函数
 * @param T
 */
void CratePtTree(PtTree *T){
    // 创建根结点
    *T = (PtNode*)malloc(sizeof(PtNode));
    (*T)->data = 1;

    // 创建左节点
    (*T)->lchild = (PtNode*)malloc(sizeof(PtNode));
    (*T)->rchild = (PtNode*)malloc(sizeof(PtNode));
    (*T)->lchild->data = 2;
    // 创建右子树
    (*T)->lchild->lchild = (PtNode*)malloc(sizeof(PtNode));
    (*T)->lchild->rchild = (PtNode*)malloc(sizeof(PtNode));
    (*T)->lchild->rchild->data = 5;
    (*T)->lchild->rchild->lchild = NULL;
    (*T)->lchild->rchild->rchild = NULL;

    (*T)->rchild->data = 3;
    (*T)->rchild->lchild = (PtNode*)malloc(sizeof(PtNode));
    (*T)->rchild->lchild->data=6;
    (*T)->rchild->lchild->lchild=NULL;
    (*T)->rchild->lchild->rchild=NULL;
    (*T)->rchild->rchild=(PtNode *)malloc(sizeof(PtNode));
    (*T)->rchild->rchild->data=7;
    (*T)->rchild->rchild->lchild=NULL;
    (*T)->rchild->rchild->rchild=NULL;
    (*T)->lchild->lchild->data=4;
    (*T)->lchild->lchild->lchild=NULL;
    (*T)->lchild->lchild->rchild=NULL;
}

/**
 * 打印结点
 */
 void showElem(PtNode* elem){
     // 输出元素
     printf("%d ", elem->data);
 }

/**
 * 先序遍历
 * @return
 */
 void PreOrderTraverse(PtTree T){
     // 条件判断
     if(T){
         // 调用方法
         showElem(T);
         // 访问结点的左孩子
         PreOrderTraverse(T->lchild);
         // 返回结点的右孩子
         PreOrderTraverse(T->rchild);
     }
     // 结点为空,返回上一层
    return;
 }
int main() {
    // 定义结构体变量
    PtTree Tree;
    // 调用函数
    CratePtTree(&Tree);
    printf("先序遍历: \n");
    PreOrderTraverse(Tree);
    return 0;
}