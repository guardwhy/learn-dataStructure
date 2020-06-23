/**
 * 后序遍历,递归实现
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
    // 创建右子树5
    (*T)->lchild->lchild = (PtNode*)malloc(sizeof(PtNode));
    (*T)->lchild->rchild = (PtNode*)malloc(sizeof(PtNode));
    (*T)->lchild->rchild->data = 5;
    // 节点5左右子树为空
    (*T)->lchild->rchild->lchild = NULL;
    (*T)->lchild->rchild->rchild = NULL;

    // 右节点3
    (*T)->rchild->data = 3;
    // 左节点为6
    (*T)->rchild->lchild = (PtNode*)malloc(sizeof(PtNode));
    (*T)->rchild->lchild->data=6;
    // 节点6左右子树为空
    (*T)->rchild->lchild->lchild=NULL;
    (*T)->rchild->lchild->rchild=NULL;
    // 返回父节点，分配空间
    (*T)->rchild->rchild=(PtNode *)malloc(sizeof(PtNode));
    // 右节点7
    (*T)->rchild->rchild->data=7;
    // 节点7左右子树为空
    (*T)->rchild->rchild->lchild=NULL;
    (*T)->rchild->rchild->rchild=NULL;
    // 左节点为4
    (*T)->lchild->lchild->data=4;
    // 节点4左右子树为空
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
 * 后序遍历
 * @return
 */
void PostOrderTraverse(PtTree T){
    // 条件判断
    if(T){

        // 访问结点的左孩子
        PostOrderTraverse(T->lchild);
        // 返回结点的右孩子
        PostOrderTraverse(T->rchild);
        // 调用方法
        showElem(T);
    }
    // 结点为空,返回上一层
    return;
}
int main() {
    // 定义结构体变量
    PtTree Tree;
    // 调用函数
    CratePtTree(&Tree);
    printf("后序遍历: \n");
    PostOrderTraverse(Tree);
    return 0;
}