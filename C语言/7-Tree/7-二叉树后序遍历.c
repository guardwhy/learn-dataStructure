/*
	二叉树后序遍历(非递归实现)
*/
#include <stdio.h>
#include <stdlib.h>

// 定义变量记录栈顶元素的位置
int top = -1;

// 树结点的数据类型,目前暂定为整型
typedef int TElemType;

/**
* 结点结构
* @return
*/
typedef struct PtNode {
   // 结点数据
   TElemType data;
   // 左右孩子指针
   struct PtNode* lchild, * rchild;
}PtNode, * PtTree;

/**
*初始化函数
* @param T
*/
void CratePtTree(PtTree* T) {
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
   (*T)->rchild->lchild->data = 6;
   // 节点6左右子树为空
   (*T)->rchild->lchild->lchild = NULL;
   (*T)->rchild->lchild->rchild = NULL;
   // 返回父节点，分配空间
   (*T)->rchild->rchild = (PtNode*)malloc(sizeof(PtNode));
   // 右节点7
   (*T)->rchild->rchild->data = 7;
   // 节点7左右子树为空
   (*T)->rchild->rchild->lchild = NULL;
   (*T)->rchild->rchild->rchild = NULL;
   // 左节点为4
   (*T)->lchild->lchild->data = 4;
   // 节点4左右子树为空
   (*T)->lchild->lchild->lchild = NULL;
   (*T)->lchild->lchild->rchild = NULL;
}

// 弹栈函数
void pop() {
   if (top == -1) {
       return;
   }
   top--;
}

// 输出结点数值
void showElem(PtNode* elem) {
   printf("%d ", elem->data);
}

/*
 后序遍历非递归算法
*/
typedef struct SNode {
   // 数据类型
   PtTree p;
   // 标记位
   int tag;
}SNode;

/*
   后续遍历使用的进栈函数
*/
void postpush(SNode* a, SNode sdata) {
   // 添加元素
   a[++top] = sdata;
}

/*
   后序遍历函数
*/

void PostOrderTraverse(PtTree Tree) {
   // 定义一个栈
   SNode a[20];
   // 定义临时指针
   PtNode* temp;
   // 定义标记元素
   int tag;
   SNode sdata;

   temp = Tree;
   // 条件遍历
   while (temp||top!= -1)
   {
       while (temp) {
           // 入栈准备
           sdata.p = temp;
           // 设置标记为0
           sdata.tag = 0;
           // 压栈操作
           postpush(a, sdata);
           // 遍历左子树
           temp = temp->lchild;
       }

       // 取得栈顶元素
       sdata = a[top];
       // 弹栈操作
       pop();
       temp = sdata.p;
       tag = sdata.tag;

       // 当tag等于0，该节点没有遍历右子树
       if (tag == 0) {
           // 更改结点的标志位,重新压栈
           sdata.p = temp;
           sdata.tag = 1;
           postpush(a, sdata);
           temp = temp->rchild;
       }
       else {
           showElem(temp);
           temp = NULL;
       }
   }
}
int main() {
   // 创建结构体变量
   PtTree Tree;
   CratePtTree(&Tree);
   printf("后序遍历(非递归实现): \n");
   PostOrderTraverse(Tree);
	return 0;
}
