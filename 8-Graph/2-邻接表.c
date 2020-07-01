/**
 * 邻接表实现
 */
#include <stdio.h>
#include <stdlib.h>
/**
 * 宏定义
 */
#define MAXVEX 20 // 最大顶点数
#define  VertexType int//顶点数据的类型
#define  InfoType int//图中弧或者边包含的信息的类型

/**
 * 边表结点
 * @return
 */
typedef struct ArcNode{
    int adjvex; // 存储该顶点对应的下标
    struct ArcNode* nextarc; // 指向下一个邻接点
    InfoType info; // 和边相关的信息
}ArcNode;

/**
 * 顶点表结点
 * @return
 */
typedef struct VertexNode{
    VertexType data; // 顶点域,存储顶点的信息
    ArcNode* firstArc; // 指向下一条边的指针
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

/**
 * 建立图的邻接表结构
 * @return
 */
void CreateGraph(ALGraph* G){
    // 定义变量
    int i, j, k;
    // 定义临时指针
    ArcNode* arcNode;

    printf("请输入顶点数和边数:\n");
    scanf("%d,%d", &G->vexNum, &G->arcNum); // 输入顶点数和边数

    /**
     * 读入顶点信息,建立顶点表
     */
    printf("建立顶点表: \n");
    for(i=0; i < G->vexNum; i++){
        printf("请输入%d个顶点:\n", i);
        //刷新缓冲区
        fflush(stdin);
        G->vertices[i].data = getchar();
        // 将边表置为空表
        G->vertices[i].firstArc = NULL;
    }

    /**
     * 建立边表
     */
     printf("建立边表:\n");
     for(k=0; k<G->arcNum; k++){
         printf("请输入边(vi,vj)上的顶点序号:\n");
         // 输入边(vi,vj)上的顶点序号
         scanf("%d,%d", &i, &j);
         // 向内存申请空间,生成边表结点
         arcNode = (ArcNode*)malloc(sizeof(ArcNode));
         // 邻接序号为j
         arcNode->adjvex = j;
         // 将arcNode的指针指向当前顶点上指向的结点
         arcNode->nextarc = G->vertices[i].firstArc;
         // 将当前顶点的指针指向arcNode
         G->vertices[i].firstArc = arcNode;

         // 向内存申请空间,生成边表结点
         arcNode = (ArcNode*)malloc(sizeof(ArcNode));
         // 邻接序号为i
         arcNode->adjvex = i;
         // 将arcNode的指针指向当前顶点上指向的结点
         arcNode->nextarc = G->vertices[j].firstArc;
         // 将当前顶点的指针指向arcNode
         G->vertices[j].firstArc = arcNode;
     }
}

/**
 * 输出邻接表
 * @return
 */
void showGraph(ALGraph *G)
{
    int i;
    for (i = 0; i < G->vexNum; i++)
    {
        printf("%d->", i);
        while (G->vertices[i].firstArc != NULL)
        {
            printf("%d->", G->vertices[i].firstArc->adjvex);
            G->vertices[i].firstArc = G->vertices[i].firstArc->nextarc;
        }
        printf("\n");
    }
}
int main() {
    // 结构体变量
    ALGraph G;
    // 调用函数
    CreateGraph(&G);
    showGraph(&G);
    return 0;
}