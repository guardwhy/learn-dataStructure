/**
 * kruskal算法
 * @return
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * 宏定义
 * @return
 */
#define MAXNUM 20 // 顶点数最大个数
#define INFINITY 65535
#define MAX_EDGE 20
typedef int Status;

/**
 * 图的结构类型
 * @return
*/
typedef struct MGraph{

    // 二维数组,记录顶点之间的关系
    int arcs[MAXNUM][MAXNUM];
    // 图的顶点数和边数
    int vexnum, arcnum;
}MGraph;

/**
 * 对边集数组Edge结构的定义
 * @return
*/
typedef struct Edge{
    int begin; // 开始
    int end; // 结束
    int weight; // 权值
}Edge;

/**
 * 构建图
 * @return
 */
void CreateMGraph(MGraph* G){
    // 定义变量
    int i, j;
    // 输入图的顶点数和边数
    G->vexnum = 15;
    G->arcnum = 9;

    // 初始化顶点数
    for(i=0; i<G->vexnum; i++){
        for(j=0; j<G->vexnum; j++){
            // 条件判断
            if(i == j){
                G->arcs[i][j] = 0;
            } else{
                G->arcs[i][j] = G->arcs[j][i] = INFINITY;
            }
        }
    }

    // 给予顶点赋予权值操作
    G->arcs[0][1]=10;
    G->arcs[0][5]=11;
    G->arcs[1][2]=18;
    G->arcs[1][8]=12;
    G->arcs[1][6]=16;
    G->arcs[2][8]=8;
    G->arcs[2][3]=22;
    G->arcs[3][8]=21;
    G->arcs[3][6]=24;
    G->arcs[3][7]=16;
    G->arcs[3][4]=20;
    G->arcs[4][7]=7;
    G->arcs[4][5]=26;
    G->arcs[5][6]=17;
    G->arcs[6][7]=19;

    for(i=0; i<G->vexnum; i++){
        for(j=i; j<G->vexnum; j++){
            G->arcs[j][i] = G->arcs[i][j];
        }
    }
}

/**
 * 交换权值
 * @return
 */
void Swap(Edge* edges, int i, int j){
    // 定义临时变量
    int temp;
    // 顶点头开始交换
    temp = edges[i].begin;
    edges[i].begin = edges[j].begin;
    edges[j].begin = temp;

    // 顶点尾交换
    temp = edges[i].end;
    edges[i].end = edges[j].end;
    edges[j].end = temp;

    // 权值
    temp = edges[i].weight;
    edges[i].weight = edges[j].weight;
    edges[j].weight = temp;
}

/**
 * 查找连线顶点尾部下标
 * @return
 */
int Find(int* parent, int t){
    while (parent[t] < 0){
        t = parent[t];
    }

    return t;
}

/**
 * 对权值进行排序
 * @return
*/
void sort(MGraph* G, Edge edges[]){
    for(int i=0; i < G->vexnum; i++){
        for(int j = i+1; j<G->vexnum; j++){
            if(edges[i].weight > edges[j].weight){
                // 调用函数
                Swap(edges, i, j);
            }
        }
    }
    printf("权排序之后的为: \n");
    for(int i=0; i < G->vexnum; i++){
        // 输出权值
        printf("(%d, %d) %d\n", edges[i].begin, edges[i].end, edges[i].weight);
    }
}

/**
 * Kruskal算法
 * @return
 */
void MiniSpanTree_Kruskal(MGraph G){
    // 定义变量
    int i, j, n, m;
    int k = 0;

    // 定义数组判断是否形成环路
    int parent[MAXNUM];

    // 定义边集数组
    Edge edges[MAX_EDGE];
    // 遍历数组,并且排序
    for(i=0; i < G.vexnum-1; i++){
        for(j=i+1; j<G.vexnum; j++){
            if(G.arcs[i][j] < INFINITY){
                edges[k].begin = i;
                edges[k].end = j;
                edges[k].weight = G.arcs[i][j];
                k++;
            }
        }
    }

    // 调用函数
    sort(&G, &edges);

    // 初始化数组值
    for(i=0; i < G.vexnum; i++)
        parent[i] = 0;
    printf("最小生成树:\n");

    /**
     * 循环边
     */
     for(i=0; i<G.arcnum; i++){

         int n = Find(parent,edges[i].begin);
         int m = Find(parent,edges[i].end);

         // 条件判断,说明此边没有与现有的生成树形成环路
         if (n != m)
         {
             // 将此边的结尾顶点放入下标为起点的parent中。
             parent[n] = m;
             printf("(%d, %d) %d\n", edges[i].begin, edges[i].end, edges[i].weight);
         }
     }
}
int main()
{
    // 定义结构体变量
    MGraph G;
    // 调用函数
    CreateMGraph(&G);
    MiniSpanTree_Kruskal(G);
    return 0;
}