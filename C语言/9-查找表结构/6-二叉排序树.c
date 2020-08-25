/**
 *二叉排序树
 * @return
*/
#include <stdio.h>
#include <stdlib.h>

/**
 * 宏定义
 * @return
*/
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 // 存储空间初始分配量
#define ElemType int

/**
 * 二叉排序树的节点结构定义
 * @return
*/
typedef struct BiTNode{
    // 结点数据
    int data;
    // 左右孩子指针
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

/**
 * 二叉排序树查找
 * @return
*/
int SearchBST(BiTree T, int key, BiTree f, BiTree *p){
    // 如果T指针为空，说明查找失败
    if(!T){
        *p = f;
        // 指针p指向查找路径上访问的最后一个结点并返回FALSE.
        return FALSE;
    } else if(key == T->data){
        // 如果相等,使P指针指向关键字,并且返回查找成功信息
        *p = T;
        return TRUE;
    }else if(key < T->data){
        // 在左子树中继续查找
        return SearchBST(T->lchild, key, T, p);
    } else{
        // 在右子树中继续查找
        return SearchBST(T->rchild, key, T, p);
    }
}

/**
 * 二叉排序树插入操作
 * @return
*/
int InsertBST(BiTree* T, ElemType e){
    // 当二叉排序树T中不存在关键字等于key的数据元素时， 插入key并返回TRUE，否则返回FALSE
    BiTree p = NULL;
    // 查找不成功
    if(!SearchBST((*T), e, NULL, &p)){
        // 内存分配,插入操作
        BiTree s = (BiTree)malloc(sizeof(BiTNode));
        s->data = e;
        s->lchild = s->rchild = NULL;

        // 如果p为NULL,说明该二叉排序树为空树,此时插入的结点为整棵树的根结点.
        if(!p){
            // 插入s为新的根结点
            *T = s;
            // 如果p不为NULL,则p指向的为查找失败的最后一个叶子结点。
        }else if(e < p->data){
            p->lchild = s; // 插入s为左孩子
        } else{
            p->rchild = s; // 插入s为右孩子
        }
        return TRUE;
    }
    else{
        return FALSE;  // 树中已有关键字相同的结点,不再插入
    }
}

/**
 * 二叉排序树删除操作
 * @return
*/
int Delete(BiTree *p){
    // 从二叉排序树中删除结点p，并重接它的左或右子树。
    BiTree q, s;
    // 结点p本身为叶子结点,直接删除
    if(!(*p)->lchild && !(*p)->rchild){
        *p = NULL;
    } else if(!(*p)->lchild){
        // 左子树为空,用结点p的右子树根节点代替结点p
        q = *p;
        *p = (*p)->rchild;
        // 释放内存
        free(q);
    }else if(!(*p)->rchild){
        // 右子树为空,用结点p的左子树根节点代替结点p
        q = *p;
        // 将左子树存储的结点的地址赋值给指针变量 p
        *p = (*p)->rchild;
        // 释放内存
        free(q);
    }else{
        // 左右子树都不为空
        q = *p;
        s = (*p)->lchild;
        // 找到结点p的直接前驱
        while (s->rchild){
            q = s;
            s = s ->rchild;
        }
        // 改变结点p的值
        (*p)->data = s->data;
        // 判断结点p的左子树s是否有右子树
        if(q != *p){
            // 存在右子树,在删除直接前驱结点的同时,令前驱的左孩子结点改为q指向结点的孩子结点。
            q->rchild = s->lchild;
        }else{
            // 不存在右子树,直接将左子树上移
            q->lchild = s->lchild;
        }

        // 释放内存
        free(s);
    }
    return TRUE;
}

int DeleteBST(BiTree* T, int key){
    //二叉排序树T中存在关键字等于key的数据元素时，则删除该数据元素结点
    if(!(*T)){
        //  不存在关键字等于key的数据元素
        return FALSE;
    }else{
        // 找到关键字等于key的数据元素
        if(key == (*T)->data){
            Delete(T);
            return TRUE;
        } else if(key < (*T)->data){
            // 使用递归方式
            return DeleteBST(&(*T)->lchild, key);
        } else{
            return DeleteBST(&(*T)->rchild, key);
        }
    }
}

/**
 * 中序输出
 * @return
*/
void PreOrderTraverse(BiTree t){
    // 条件判断
    if(t == NULL){
        return;
    }
    PreOrderTraverse(t->lchild);
    printf("%d ", t->data);
    PreOrderTraverse(t->rchild);
}
int main()
{
    // 定义变量
    int i;
    // 定义数组
    int a[10]={62,88,58,47,35,73,51,99,37,93};
    BiTree T=NULL;

    // 遍历操作
    for(i=0;i<10;i++)
    {
        InsertBST(&T, a[i]);
    }
    printf("中序遍历二叉树: \n");
    // 调用函数
    PreOrderTraverse(T);
    printf("\n");
    printf("删除88后,中序遍历二叉排序树: \n");
    // 调用删除函数
    DeleteBST(&T, 88);
    PreOrderTraverse(T);
    return 0;
}