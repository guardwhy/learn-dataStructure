/**
 * 拓扑排序算法
 * @return
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * 宏定义
 * @return
 */
#define MAXNUM 14 // 顶点的最大个数
#define MAXEDGE 13 // 边的数量
#define INFINITY 65535
typedef int Status;
/*#define OK 1
#define ERROR 0*/
typedef enum{false,true}bool; //定义bool型常量

/**
 * 边表结点
 * @return
*/
typedef struct EdgeNode{
    int adjvex; // 邻接点域,存储该顶点对应的下标
    struct EdgeNode* next; // 链域,指向下一个邻接点的指针
    int weight; // 用于存储权值
}EdgeNode;

/**
 * 顶点表结点
 * @return
*/
typedef struct VertexNode{
    // 顶点的数据域
    int data;
    // 指向邻接点的指针
    EdgeNode* firstEdge;
    // 顶点入度
    int indegree;
}VertexNode, AdjList[MAXNUM];

/**
 * 图的结构体类型(邻接矩阵)
 * @return
*/
typedef struct {
    int vexs[MAXNUM]; // 顶点表
    int arc[MAXNUM][MAXNUM]; // 邻接矩阵,可看作边表
    int numVertexes, numEdges; // 当前的顶点数和边数
}MGraph;

/**
 * 图的结构体类型(邻接表)
 * @return
*/
typedef struct graphAdjList{
    AdjList adjList; // 图中顶点及其各邻接点数组
    int numVertexes, numEdges; // 记录顶点数和边
}graphAdjList,*GraphAdjList;

/**
 * 构建图
 * @return
 */
void CreateMGraph(MGraph *G){
    // 定义变量
    int i, j;
    // 给顶点和边赋值
    G->numVertexes = MAXNUM;
    G->numEdges = MAXEDGE;

    /**
     * 初始化图
    */
    for(i=0; i<G->numVertexes; i++){
        G->vexs[i] = i;
    }
    for(i=0; i<G->numVertexes; i++){
        for(j=0; j<G->numVertexes; j++){
            G->arc[i][j] = 0;
        }
    }

    G->arc[0][4]=1;
    G->arc[0][5]=1;
    G->arc[0][11]=1;
    G->arc[1][2]=1;
    G->arc[1][4]=1;
    G->arc[1][8]=1;
    G->arc[2][5]=1;
    G->arc[2][6]=1;
    G->arc[2][9]=1;
    G->arc[3][2]=1;
    G->arc[3][13]=1;
    G->arc[4][7]=1;
    G->arc[5][8]=1;
    G->arc[5][12]=1;
    G->arc[6][5]=1;
    G->arc[8][7]=1;
    G->arc[9][10]=1;
    G->arc[9][11]=1;
    G->arc[10][13]=1;
    G->arc[12][9]=1;
}

/**
 * 创建邻接表
 * @return
*/
void CreateALGraph(MGraph G, GraphAdjList *GL){
    // 定义变量
    int i, j;
    EdgeNode* p;
    // 向内存申请空间,生成存储数组
    *GL = (GraphAdjList)malloc(sizeof(graphAdjList));
    (*GL)->numVertexes = G.numVertexes;
    (*GL)->numEdges = G.numEdges;

    /**
     * 读入顶点信息,建立顶点表
     */
    for(i=0; i < G.numVertexes; i++){
        (*GL)->adjList[i].indegree = 0;
        (*GL)->adjList[i].data = G.vexs[i];
        // 将边表设置为空表
        (*GL)->adjList[i].firstEdge = NULL;
    }

    /**
     * 建立边表
     */
     for(i=0; i < G.numVertexes; i++){
         for(j=0; j<G.numVertexes; j++){
             // 条件判断
             if(G.arc[i][j] == 1){
                 // 分配内存
                 p = (EdgeNode*)malloc(sizeof(EdgeNode));
                 // 邻接序号
                 p->adjvex = j;
                 // 将当前顶点上的指向的结点指针赋值给p
                 p->next = (*GL)->adjList[i].firstEdge;
                 // 将当前顶点的指针指向p
                 (*GL)->adjList[i].firstEdge = p;
                 (*GL)->adjList[j].indegree++;
             }
         }
     }
}

/**
 * 拓扑排序
 * @return
*/
Status TopologicalSort(GraphAdjList GL){
    // 定义指针变量
    EdgeNode *p;
    int i,k,gettop;
    // 栈指针下标
    int top = 0;
    // 定义计数器,输出顶点的个数
    int count = 0;

    // 将入度为0的顶点入栈
    int* stack;
    stack = (int *)malloc(GL->numVertexes * sizeof(int));
    for(i=0; i<GL->numVertexes; i++)
        // 将入度为0的顶点入栈
        if(0 == GL->adjList[i].indegree)
            stack[++top] = i;
    while (top!=0){
        // 出栈操作
        gettop = stack[top--];
        // 输出顶点
        printf("%d ->", GL->adjList[gettop].data);
        // 统计输出顶点数
        count++;

        // 对顶点弧表遍历
        for(p = GL->adjList[gettop].firstEdge; p; p=p->next){
            k = p->adjvex;
            // 将k号顶点的邻接点的入度减1，如果减1后为0，则入栈
            if(!(--GL->adjList[k].indegree))
                stack[++top] = k;
        }
    }
    printf("\n");
    if(count < GL->numVertexes){
        return false;
    }else{
        return true;
    }
}
int main() {
    // 结构体变量
    MGraph G;
    GraphAdjList GL;

    int result;
    // 调用函数
    CreateMGraph(&G);
    CreateALGraph(G, &GL);
    result=TopologicalSort(GL);
    printf("result:%d",result);
    return 0;
}