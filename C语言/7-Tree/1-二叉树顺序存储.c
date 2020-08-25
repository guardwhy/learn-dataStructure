/**
 * 二叉树顺序存储
 */
#include <stdio.h>
#include <stdlib.h>

// 树结点的数据类型,目前暂定为整型
typedef int TElemType;
/**
 * 结点结构
 * @return
 */
typedef struct PTNode{
    // 结点数据
    TElemType data;
    // 左右孩子指针
    struct PTNode *lchild, *rchild;
}PTNode, *Tree;

// 创建函数
void CreateTree(Tree *T){
    *T = (PTNode*)malloc(sizeof(PTNode));
    (*T)->data = 1;
    // 左子树
    (*T)->lchild = (PTNode*)malloc(sizeof(PTNode));
    (*T)->lchild->data = 2;
    // 右子树
    (*T)->rchild = (PTNode*)malloc(sizeof(PTNode));
    (*T)->rchild->data = 3;
    // 右子树
    (*T)->rchild->lchild = NULL;
    (*T)->rchild->rchild = NULL;
    // 左子树
    (*T)->lchild->lchild = (PTNode*)malloc(sizeof(PTNode));
    (*T)->lchild->lchild->data = 4;

    (*T)->lchild->rchild=NULL;
    (*T)->lchild->lchild->lchild = NULL;
    (*T)->lchild->lchild->rchild = NULL;
}
int main() {
    // 结构体变量
    Tree p;
    // 调用函数
    CreateTree(&p);
    // 输出结果
    printf("%d", p->lchild->lchild->data);
    return 0;
}