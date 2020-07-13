/**
 * 平衡二叉树
 * @return
*/
#include <stdio.h>
#include <stdlib.h>

/**
 * 宏定义
 * @return
*/
typedef int ElemType ; // 元素类型
typedef enum{false, true} bool;

//定义平衡因子数
#define LH +1  // 左高
#define EH 0  // 等高
#define RH -1 // 右高

/**
 * 二叉树的二叉链表结点结构定义
 * @return
*/
typedef struct BSTNode{
    ElemType data; // 结点数据
    int bf; // 结点的平衡因子
    struct BSTNode *rchild,*lchild; // 左右孩子指针
}BSTNode,*BSTree;

/**
 * 对以p为根的二叉排序树作右旋处理.
 * 处理之后p指向新的树根结点，即旋转处理之前的左子树的根结点
 * @return
*/
void R_Rotate(BSTree* p){
    BSTree lc;
    // lc指向P的左子树根结点
    lc=(*p)->lchild;
    // lc的右子树挂接为p的左子树
    (*p)->lchild = lc->rchild;
    // p指向新的根节点
    lc->rchild = (*p);
    *p = lc;
}

/**
 * 对以P为根的二叉排序树作左旋处理.
 * 处理之后P指向新的树根结点，即旋转处理之前的右子树的根结点0
 * @return
*/
void L_Rotate(BSTree* p){
    BSTree rc;
    // rc指向p的右子树根结点
    rc = (*p)->rchild;
    // rc的左子树挂接为p的右子树
    (*p)->rchild = rc->lchild;
    // p指向新的根结点
    rc->lchild = *p;
    *p = rc;
}

/**
 * 对以指针T所指结点为根的二叉树作左平衡旋转处理
 * 本算法结束时，指针T指向新的根结点
 * @return
*/
void LeftBalance(BSTree* T){
    BSTree lc, rd;
    // L指向T的左子树根结点
    lc = (*T)->lchild;
    // 检查T的左子树的平衡度，并作相应平衡处理
    switch(lc->bf){
        // 新结点插入在T的左孩子的左子树上,要作单右旋处理
        case LH:
            (*T)->bf = lc->bf = EH;
            R_Rotate(T);
            break;
        // 新结点插入在T的左孩子的右子树上,要作双旋处理.
        case RH:
            // ld指向T的左孩子的右子树根
            rd = lc->rchild;
            // 修改T及其左孩子的平衡因子
            switch (rd->bf) {
                case LH:
                    (*T)->bf = RH;
                    lc->bf = EH;
                    break;
                case EH:
                    (*T)->bf = lc->bf = EH;
                    break;
                case RH:
                    (*T)->bf = EH;
                    lc->bf = LH;
                    break;
            }
            rd->bf = EH;
            // 对T的左子树作左旋平衡处理
            L_Rotate(&(*T)->lchild);
            // 对T作右旋平衡处理
            R_Rotate(T);
            break;
    }
}

/*
 * 对以指针T所指结点为根的二叉树作右平衡旋转处理，
 * 本算法结束时，指针T指向新的根结点
 * @return
*/
void RightBalance(BSTree* T){
    BSTree lc, rd;
    // rc指向T的右子树根结点
    lc = (*T)->rchild;
    // 检查T的右子树的平衡度，并作相应平衡处理
    switch(lc->bf){
        // 新结点插入在T的右孩子的右子树上,要作单左旋处理
        case RH:
            (*T)->bf = lc->bf = EH;
            L_Rotate(T);
            break;
            // 新结点插入在T的左孩子的左子树上,要作双旋处理.
        case LH:
            // rd指向T的右孩子的左子树根
            rd = lc->lchild;
            // 修改T及其左孩子的平衡因子
            switch(rd->bf)
            {
                case LH:
                    (*T)->bf = EH;
                    lc->bf = RH;
                    break;
                case EH:
                    (*T)->bf = lc->bf = EH;
                    break;
                case RH:
                    (*T)->bf = EH;
                    lc->bf = LH;
                    break;
            }
            rd->bf = EH;
            // 对T的左子树作左旋平衡处理
            R_Rotate(&(*T)->rchild);
            // 对T作右旋平衡处理
            L_Rotate(T);
            break;
    }
}

/**
 *若在平衡的二叉排序树T中不存在和e有相同关键字的结点，则插入一个
 *数据元素为e的新结点，并返回1，否则返回0。若因插入而使二叉排序树
 *失去平衡，则作平衡旋转处理，布尔变量taller反映T长高与否。
 * @return
*/
int InsertAVL(BSTree* T,ElemType e,bool* taller){
    //如果本身为空树，则直接添加e为根结点
    if((*T) == NULL){
        // 插入新结点，树“长高”，置taller为TRUE
        (*T) = (BSTree)malloc(sizeof(BSTNode));
        (*T)->bf = EH;
        (*T)->data = e;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
        *taller = true;
    } else if(e == (*T)->data){
        // 树中已存在和e有相同关键字的结点则不再插入
        *taller = false;
        return 0;
        // 如果e小于结点T的数据域,则插入到T的左子树中
    } else if(e < (*T)->data){
        // 应继续在T的左子树中进行搜索
        if(!InsertAVL(&(*T)->lchild, e, taller))
            return 0; // 未插入

        // 已插入到T的左子树中且左子树“长高”
        if(*taller){
            // 检查T的平衡度
            switch ((*T)->bf) {
                // 原本左子树比右子树高，需要作左平衡处理
                case LH:
                    LeftBalance(T);
                    *taller = false;
                    break;
                    // 原本左、右子树等高，现因左子树增高而使树增高
                case EH:
                    (*T)->bf = LH;
                    *taller = true;
                    break;
                    // 原本右子树比左子树高，现左、右子树等高
                case RH:
                    (*T)->bf = EH;
                    *taller = false;
                    break;
            }
        }
        // 应继续在T的右子树中进行搜索
    } else{
        // 未插入
        if(!InsertAVL(&(*T)->rchild, e, taller))
            return 0;

        // 已插入到T的右子树且右子树“长高”
        if(*taller){
            // 检查T的平衡度
            switch((*T)->bf)
            {
                // 原本左子树比右子树高，现左、右子树等高
                case LH:
                    (*T)->bf = EH;
                    *taller = false;
                    break;
                // 原本左、右子树等高，现因右子树增高而使树增高
                case EH:
                    (*T)->bf = RH;
                    *taller = true;
                    break;
                // 原本右子树比左子树高，需要作右平衡处理
                case RH:
                    RightBalance(T);
                    *taller = false;
                    break;
            }
        }
    }
    return 1;
}


/**
 * 判断现有平衡二叉树中是否已经具有数据域为e的结点
 * @return
*/
bool FindNode(BSTree root, ElemType e, BSTree* pos){
    BSTree pt = root;
    (*pos) = NULL;
    // 判断条件
    while (pt){
        if(pt->data == e){
            (*pos) = pt;
            return true;
        } else if(pt->data > e){
            pt = pt->lchild;
        } else{
            pt = pt->rchild;
        }
    }
    return false;
}

/**
 * 中序遍历平衡二叉树
 * @return
*/
void PreOrderTraverse(BSTree root){
    if(root->lchild)
        PreOrderTraverse(root->lchild);

    printf("%d ",root->data);

    if(root->rchild)
        PreOrderTraverse(root->rchild);
}

int main()
{
    // 定义变量
    int i;
    // 定义数组
    int arr[]={3,2,1,4,5,6,7,10,9,8};
    BSTree root = NULL, pos;
    bool taller;
    // 遍历数组,查找表构建平衡二叉树
    for(i=0; i<10; i++){
        InsertAVL(&root, arr[i], &taller);
    }
    // 中序遍历输出
    PreOrderTraverse(root);

    // 判断平衡二叉树是否含有数据域为89的数据
    if(FindNode(root, 9, &pos)){
        printf("\n%d\n", pos->data);
    } else{
        printf("\n查找失败\n");
    }
    return 0;
}