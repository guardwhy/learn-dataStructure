/**
 * Prim算法
 * @return
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * 宏定义
 * @return
 */
#define MAXNUM 20 // 顶点数最大个数
#define VRType int // 顶点变量类型
#define InfoType char // 存储边指针变量类型
#define VertexType int // 顶点数据类型
#define INFINITY 65535 // 最大值

/**
 * 顶点数据类型
 * @return
*/
typedef struct ArcCell{
    // 对于无权图,用1或0表示是否相邻.对于带权图,直接为权值。
    VRType adj;
    // 该弧相关信息的指针
    InfoType* info;
}AreCell,AdjMatri[MAXNUM][MAXNUM];

/**
 * 图的结构类型
 * @return
 */
typedef struct MGraph{
    // 图顶点的数据
    VertexType vexs[MAXNUM];
    // 二维数组,记录顶点之间的关系
    AdjMatri arcs;
    // 图的顶点数和边数
    int vexnum, arcnum;
}MGraph;

/**
 * 判断出顶点在二维数组中的位置
 * @return
 */
int locationVex(MGraph G, VertexType v){
    // 定义变量
    int i;
    // 遍历数组,寻找变量
    for(i = 0; i<G.vexnum; i++){
        if(G.vexs[i] == v)
            return i;
    }
    return -1;
}

/**
 * 构建无向网
 * @return
 */
void CreateUDN(MGraph *G) {
    printf("请输入顶点个数和边的个数: \n");
    //输入顶点数和边数
    scanf("%d, %d", &(G->vexnum),&(G->arcnum));

    // 读入顶点信息,建立顶点表
    for(int i=0; i <G->vexnum; i++){
        printf("请输入顶点:\n");
        scanf("%d", &(G->vexs[i]));
    }
    /**
     * 邻接矩阵初始化
     * @param G
     */
    for(int i=0; i < G->vexnum; i++){
        for(int j =0; j<G->vexnum; j++){
            G->arcs[i][j].adj = INFINITY;
            G->arcs[i][j].info = NULL;
        }
    }
    // 读入arcNum条边,建立邻接矩阵
    for(int i=0; i < G->arcnum; i++){
        // 定义变量
        int v1, v2, w;
        printf("输入边(vi,vj)上的下标i，下标j和权值w:\n");
        scanf("%d,%d,%d", &v1, &v2, &w);

        int a = locationVex(*G, v1);
        int b = locationVex(*G, v2);

        //无向图的二阶矩阵沿主对角线对称
        G->arcs[a][b].adj = w;
        G->arcs[b][a].adj = w;

    }
}

/**
 * 记录从顶点集U到V-U的代价最小的边的辅助数组定义
 * @return
 */
typedef struct {
    VertexType adjvex; // 顶点集U中到该点为最小权值的那个顶点的序号
    VRType lowcost; // 那个顶点到该点的权值
}minside[MAXNUM];

// 定义一个全局数组
minside array;

// 在辅助数组中找出权值最小的数组下标,可以找到此边的终点顶点
int minimun(MGraph G, minside SZ){
    // 定义变量
    int temp = INFINITY;
    int min = -1;
    // 顶点已经进入最小生成树,让该顶点每次和temp变量进行比较,然后找出最小值
    for(int i=0; i<G.vexnum; i++){
        if(SZ[i].lowcost > 0 && SZ[i].lowcost < temp){
            temp=SZ[i].lowcost;
            min = i;
        }
    }
    // 返回最小权值的下标
    return min;
}

/**
 * Prim实现,G为无向网,u在网中选择任意顶点做起始点
 * @return
 */
void  MiniSpanTree_PRIM(MGraph G, VertexType u){
    // 起始点在顶点数组中的位置下标
    int k = locationVex(G, u);
    // 存入辅助数组中的相应位置
    for(int i=0; i<G.vexnum; i++){
        if(i != k){
            array[i].adjvex = k;
            array[i].lowcost = G.arcs[k][i].adj;
        }
    }

    // 定义辅助数组对应位置的权值
    array[k].lowcost = 0;
    printf("输出路径:\n");
    // 更新辅助数组中的信息
    for(int i=1; i < G.vexnum; i++){
        // 找出权值最小的边所在的数组下标
        k = minimun(G, array);
        printf("v%d v%d \n", G.vexs[array[k].adjvex], G.vexs[k]);
        //归入最小生成树的顶点的辅助数组中的权值设为0
        array[k].lowcost = 0;

        // 遍历,更新结点
        for(int j=0; j<G.vexnum; j++){
            if(G.arcs[k][j].adj < array[j].lowcost){
                array[j].adjvex = k;
                array[j].lowcost = G.arcs[k][j].adj;
            }
        }
    }

    printf("\n");
}
int main()
{
    // 结构体变量
    MGraph G;
    // 调用函数
    CreateUDN(&G);
    // prim算法
    MiniSpanTree_PRIM(G, 1);
    return 0;
}
