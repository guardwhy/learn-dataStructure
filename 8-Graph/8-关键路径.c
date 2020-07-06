/**
 *关键路径算法实现
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * 宏定义
 * @return
 */
#define MAXNUM 20 // 顶点数最大个数
#define VertexType int // 顶点数据类型

// 保存弧的最早开始时间
VertexType Ve[MAXNUM];
// 保存弧的最晚开始时间
VertexType Vl[MAXNUM];

/**
 * 边表结点
 * @return
 */
typedef struct ArcNode{
    int adjvex; // 存储该顶点对应的下标
    struct ArcNode* nextarc; // 指向下一个邻接点
    VertexType weight; // 权值
}ArcNode;

/**
 * 顶点表结点
 * @return
 */
typedef struct VertexNode{
    VertexType data; // 顶点域,存储顶点的信息
    ArcNode* firstArc; // 指向下一条边的指针
}VertexNode, AdjList[MAXNUM]; // 存储各链表头结点的数组

/**
 * 图的结构
 * @return
 */
typedef struct{
    AdjList vertices; // 图中顶点的数组
    int vexNum, arcNum; // 当前顶点数和边数
}ALGraph;

/**
 * 邻接表数组下标
 * @return
*/
VertexType locationVex(ALGraph G, VertexType v){
    // 条件遍历
    for(int i=0; i< G.vexNum; i++){
        if(G.vertices[i].data == v){
            return i;
        }
    }

    // 寻找失败
    return -1;
}

/**
 * 创建邻接表
 * @return
*/
void CreateAOE(ALGraph** G){
    // 定义变量
    int i;
    int begin, end, weight;

    // 分配内存
    *G = (ALGraph*)malloc(sizeof(ALGraph));
    printf("请输入顶点数和弧的边数: \n");
    scanf("%d,%d",&((*G)->vexNum),&((*G)->arcNum));

    /**
     * 读入顶点信息,建立顶点表
     */
    printf("建立顶点表: \n");
    for(i=0; i < (*G)->vexNum; i++){
        printf("请输入%d个顶点:\n", i);
        //刷新缓冲区
        fflush(stdin);
        scanf("%d", &((*G))->vertices[i].data);
        // 将边表置为空表
        (*G)->vertices[i].firstArc = NULL;
    }

    /**
    * 建立边表
    */
    printf("建立边表:\n");
    printf("请输入边(vi,vj)上的下标i，下标j和权w:\n");
    for(i=0; i<(*G)->arcNum; i++){
        scanf("%d,%d,%d", &begin, &end, &weight);

        // 创建临时指针
        ArcNode *p = (ArcNode*)malloc(sizeof(ArcNode));
        // 指向下标位置
        p->adjvex = locationVex(*(*G), end);
        p->nextarc = NULL;
        p->weight = weight;

        int locate = locationVex(*(*G), begin);
        p->nextarc = (*G)->vertices[locate].firstArc;
        (*G)->vertices[locate].firstArc = p;
    }
}

/**
 * 栈结构
 * @return
*/
typedef struct stack{
    // 数据域
    VertexType data;
    // 指针域
    struct stack* next;
}stack;

// 定义栈指针变量
stack* T;

/**
 * 初始化栈结构
 * @return
*/
void initStack(stack* *S){
    (*S) = (stack*)malloc(sizeof(stack));
    (*S)->next = NULL;
}

/**
 * 判断栈是否为空
 * @return
*/
bool StackEmpty(stack S){
    if(S.next == NULL){
        return true;
    }
    return false;
}

/**
 * 进栈,插入到链表中
 * @return
*/
void push(stack *S, VertexType v){
    // 定义临时指针
    stack *p = (stack*)malloc(sizeof(stack));
    // 存储信息
    p->data = v;
    p->next = NULL;
    // 向链表中插入节点
    p->next = S->next;
    S->next = p;
}

/**
 * 弹栈,删除链表首元结点,释放该空间。
 * @return
*/
void pop(stack* S, VertexType *i){
    // 将数据域通过地址传值给变量
    stack *p = S->next;
    *i = p->data;
    S->next = S->next->next;
    // 释放空间
    free(p);
}
int main(){
    ALGraph G;
    CreateAOE(&G);//创建AOE网
    return 0;
}