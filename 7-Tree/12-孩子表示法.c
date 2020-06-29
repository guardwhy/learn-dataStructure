/**
 * 孩子表示法
 */
#include <stdio.h>
#include <stdlib.h>
// 宏定义表示最大值
#define MAX_SIZE 100
#define TElemType char

/**
 * 孩子结点
 * @return
 */
typedef struct CTNode{
    int child;
    // 数据在数组中存储的位置下标
    struct CTNode* next;
}ChildPtr;

/**
 * 表头结构
 * @return
 */
typedef struct {
    // 结点的数据类型
    TElemType data;
    // 孩子链表的头指针
    ChildPtr* firstChild;
}CTBox;

/**
 * 树结构
 * @return
 */
typedef struct {
    // 结点数组
    CTBox nodes[MAX_SIZE];
    // 根的位置和结点数
    int n, r;
}CTree;

/**
 * 初始化普通树
 * @return
 */
 CTree initTree(CTree tree){
     printf("请输入节点数量: \n");
     scanf("%d", &(tree.n));
     for(int i=0; i < tree.n; i++){
         printf("请输入第%d个节点的值: \n", i + 1);
         getchar();
         // 输入数据
         scanf("%c", &(tree.nodes[i].data));
         // 动态分配内存
         tree.nodes[i].firstChild = (ChildPtr*)malloc(sizeof(ChildPtr));
         tree.nodes[i].firstChild->next = NULL;

         printf("输入节点%c的孩子节点数量: \n", tree.nodes[i].data);
         // 定义变量
         int num, j;
         scanf("%d", &num);
         // 判断
         if(num != 0){
             // 定义临时指针变量
             ChildPtr* temp = tree.nodes[i].firstChild;
             for(int j=0; j<num; j++){
                 // 动态生成新的元素
                 ChildPtr* newElem = (ChildPtr*)malloc(sizeof(ChildPtr));
                 newElem->next = NULL;

                 printf("输入第%d个孩子节点在表中的位置", j+1);
                 scanf("%d", &(newElem->child));
                 temp->next = newElem;
                 temp = temp->next;
             }
         }
     }

    return tree;
 }

 /**
  * 寻找方法
  * @return
  */
 void findChild(CTree tree, char a){
     // 定义变量
     int hasChild = 0;
     for(int i=0; i < tree.n; i++){
         // 条件判断
         if(tree.nodes[i].data == a){
             // 定义临时指针变量
             ChildPtr *temp = tree.nodes[i].firstChild->next;
             while(temp){
                 hasChild = 1;
                 printf("%c ", tree.nodes[temp->child].data);
                 temp = temp->next;
             }
             break;
         }
     }

     if(hasChild == 0){
         printf("此节点为叶子节点..");
     }
 }
int main() {
    // 结构体变量
    CTree tree;
    for(int i=0; i < MAX_SIZE; i++){
        tree.nodes[i].firstChild = NULL;
    }
    // 调用函数
    tree = initTree(tree);
    // 默认数根节点位于数组nodes[0]处
    tree.r = 0;
    printf("找出节点F的所有孩子的节点: ");
    // 调用函数
    findChild(tree, 'F');
    return 0;
}