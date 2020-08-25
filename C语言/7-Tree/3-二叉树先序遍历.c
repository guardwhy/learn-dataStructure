/**
 * 先序遍历,非递归实现
 */
#include <stdio.h>
#include <stdlib.h>
// 树结点的数据类型,目前暂定为整型
typedef int TElemType;
// 定义变量表示栈顶元素位置
int top = -1;
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
 *进栈函数
 */
void push(PtNode** a,PtNode* elem){
    a[++top] = elem;
}
/**
 * 弹栈函数
 */
 void pop(){
     if(top==-1){
         return;
     }
     top--;
 }

/**
 * 打印结点
 */
void showElem(PtNode* elem){
    // 输出元素
    printf("%d ", elem->data);
}

// 拿到栈顶元素
PtNode* getTop(PtNode** a){
    return a[top];
}

/**
 * 先序遍历
 * @return
 */
void PreOrderTraverse(PtTree Tree){
   // 定义一个顺序栈
   PtNode* a[30];
   // 定义临时指针
   PtNode* temp;
   // 根节点进栈
   push(a,Tree);
   // 条件判断
   while (top!=-1){
       // 取栈顶元素
       temp = getTop(a);
       // 弹栈
       pop();
       // 条件遍历
       while (temp){
           // 调用显示函数
           showElem(temp);
           // 条件判断该节点有右孩子,右孩子进栈
           if(temp->rchild){
               push(a,temp->rchild);
           }
           // 指向根节点最后一个左孩子
           temp = temp->lchild;
       }
   }
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