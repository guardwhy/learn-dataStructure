/*
   二叉树层次遍历
*/
#include <stdio.h>
#include <stdlib.h>

// 初始化对头和队尾指针
int front = 0;
int rear = 0;

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

// 入队函数
void EnQueue(PtTree* a, PtTree node) {
   a[rear++] = node;
}

// 出队函数
PtNode* DeQueue(PtNode** a) {
   return a[front++];
}

// 输出函数
void showElem(PtTree node) {
   // printf("二叉树层次遍历：");
   printf("%d ", node->data);
}

int main() {
   // 结构体变量
   PtTree Tree;
   // 初始化二叉树
   CratePtTree(&Tree);
   // 定义临时指针变量
   PtNode* temp;

   // 创建队列数组
   PtTree a[10];
   // 调用函数
   EnQueue(a, Tree);
   /*
       当对头队尾相等时,表示队列为空
   */
   while (front < rear) {
       // 对头结点出列
       temp = DeQueue(a);
       // 调用函数
       showElem(temp);
       // 将对头结点的左右子树依次入队
       if (temp->lchild != NULL) {
           EnQueue(a, temp->lchild);
       }
       if (temp->rchild != NULL) {
           EnQueue(a, temp->rchild);
       }
   }
   return 0;
}
