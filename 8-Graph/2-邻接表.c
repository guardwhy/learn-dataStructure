#include <stdio.h>

/**
 * 宏定义
 */
#define MAXVEX 20 // 最大顶点数
#define  VertexType int//顶点数据的类型

/**
 * 边表结点
 * @return
 */
typedef struct ArcNode{
    int adjvex; // 存储该顶点对应的下标
    struct ArcNode* next; // 指向下一个邻接点
}ArcNode;

/**
 * 顶点表结点
 * @return
 */
typedef struct VertexNode{
    VertexType data; // 顶点域,存储顶点的信息
    ArcNode* firstarc; // 指向下一条边的指针
}VertexNode, AdjList[MAXVEX]; // 存储各链表头结点的数组

/**
 * 图的结构
 * @return
 */
typedef struct{
    AdjList vertices; // 图中顶点的数组
    int vexNum, arcNum; // 当前顶点数和边数
    int kind; // 当前图的种类
}ALGraph;
int main() {
    printf("hello world!!!");
    return 0;
}