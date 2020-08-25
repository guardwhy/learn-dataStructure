/**
 * 邻接矩阵实现
 */
#include <stdio.h>
#include <stdlib.h>
/**
 * 宏定义
 * @return
 */
#define MAXNUM 20 // 顶点的最大个数
#define VRType int // 表示顶点之间的关系的变量类型
#define InfoType char //边额外信息的指针变量类型
#define VertexType int //顶点的数据类型
/**
 * 枚举类型
 * @return
 */
typedef enum {
    DG, // 有向图
    DN, //有向网
    UDG, // 无向图
    UDN // 无向网
}GraphKid;
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
 * 图的结构体类型
 * @return
 */
typedef struct MGraph{
    // 顶点表
    VertexType vexs[MAXNUM];
    // 邻接矩阵
    AdjMatri arcs;
    // 图的顶点数和边数
    int vexNum, arcNum;
    // 图的种类
    GraphKid kind;
}MGraph;

/**
 * 顶点在二维数组的位置
 * @return
 */
int locationVex(MGraph* G, VertexType v){
    // 定义变量
    int i=0;
    // 遍历一维数组,找到变量
    for(; i < G->vexNum; i++){
        if(G->vexs[i] == v){
            break;
        }
    }
    // 寻找失败
    if(i > G->vexNum){
        printf("寻找失败...\n");
        return -1;
    }

    return i;
}

/**
 * 构造有向网
 * @param G
 */
void CreateDN(MGraph *G) {
    printf("请输入顶点个数和边的个数: \n");
    //输入顶点数和边数
    scanf("%d, %d", &(G->vexNum),&(G->arcNum));

    // 读入顶点信息,建立顶点表
    for(int i=0; i <G->vexNum; i++){
        printf("请输入顶点:\n");
        scanf("%d", &(G->vexs[i]));
    }
    /**
     * 邻接矩阵初始化
     * @param G
     */
    for(int i=0; i < G->vexNum; i++){
        for(int j =0; j<G->vexNum; j++){
            G->arcs[i][j].adj = 0;
            G->arcs[i][j].info = NULL;
        }
    }
    // 读入arcNum条边,建立邻接矩阵
    for(int i=0; i < G->arcNum; i++){
        // 定义变量
        int v1, v2;
        printf("输入边(vi,vj)上的下标i，下标j:\n");
        scanf("%d,%d", &v1, &v2);

        int n = locationVex(G, v1);
        int m = locationVex(G, v2);
        // 条件判断
        if(m == -1 || n == -1){
            printf("寻找失败--");
            return;
        }
        //无向图的二阶矩阵沿主对角线对称
        G->arcs[n][m].adj = 1;
        G->arcs[m][n].adj = 1;
    }
}

/**
 * 构造有向图
 * @param G
 */
void CreateDG(MGraph *G) {
    printf("请输入顶点个数和边的个数: \n");
    //输入顶点数和边数
    scanf("%d, %d", &(G->vexNum),&(G->arcNum));

    // 读入顶点信息,建立顶点表
    for(int i=0; i <G->vexNum; i++){
        printf("请输入顶点:\n");
        scanf("%d", &(G->vexs[i]));
    }
    /**
     * 邻接矩阵初始化
     * @param G
     */
    for(int i=0; i < G->vexNum; i++){
        for(int j =0; j<G->vexNum; j++){
            G->arcs[i][j].adj = 0;
            G->arcs[i][j].info = NULL;
        }
    }
    // 读入arcNum条边,建立邻接矩阵
    for(int i=0; i < G->arcNum; i++){
        // 定义变量
        int v1, v2;
        printf("输入边(vi,vj)上的下标i，下标j:\n");
        scanf("%d,%d", &v1, &v2);

        int n = locationVex(G, v1);
        int m = locationVex(G, v2);
        // 条件判断
        if(m == -1 || n == -1){
            printf("寻找失败--");
            return;
        }
        // 将边的数据加入二维数组
        G->arcs[n][m].adj = 1;
    }
}

/**
 * 构造无向网
 * @param G
 */
void CreateUDN(MGraph *G) {
    printf("请输入顶点个数和边的个数: \n");
    //输入顶点数和边数
    scanf("%d, %d", &(G->vexNum),&(G->arcNum));

    // 读入顶点信息,建立顶点表
    for(int i=0; i <G->vexNum; i++){
        printf("请输入顶点:\n");
        scanf("%d", &(G->vexs[i]));
    }
    /**
     * 邻接矩阵初始化
     * @param G
     */
    for(int i=0; i < G->vexNum; i++){
        for(int j =0; j<G->vexNum; j++){
            G->arcs[i][j].adj = 0;
            G->arcs[i][j].info = NULL;
        }
    }
    // 读入arcNum条边,建立邻接矩阵
    for(int i=0; i < G->arcNum; i++){
        // 定义变量
        int v1, v2, w;
        printf("输入边(vi,vj)上的下标i，下标j和权w:\n");
        scanf("%d,%d,%d", &v1, &v2, &w);

        int m = locationVex(G, v1);
        int n = locationVex(G, v2);
        // 条件判断
        if(m == -1 || n == -1){
            printf("寻找失败--");
            return;
        }
        //无向图的二阶矩阵沿主对角线对称
        G->arcs[n][m].adj = w;
        G->arcs[w][n].adj = w;
    }
}
/**
 * 构造无向图
 * @param G
 */
void CreateUDG(MGraph *G) {
    printf("请输入顶点个数和边的个数: \n");
    //输入顶点数和边数
    scanf("%d, %d", &(G->vexNum),&(G->arcNum));

    // 读入顶点信息,建立顶点表
    for(int i=0; i <G->vexNum; i++){
        printf("请输入顶点:\n");
        scanf("%d", &(G->vexs[i]));
    }
    /**
     * 邻接矩阵初始化
     * @param G
     */
    for(int i=0; i < G->vexNum; i++){
        for(int j =0; j<G->vexNum; j++){
            G->arcs[i][j].adj = 0;
            G->arcs[i][j].info = NULL;
        }
    }
    // 读入arcNum条边,建立邻接矩阵
    for(int i=0; i < G->arcNum; i++){
        // 定义变量
        int v1, v2, w;
        printf("输入边(vi,vj)上的下标i，下标j和权w:\n");
        scanf("%d,%d,%d", &v1, &v2, &w);

        int n = locationVex(G, v1);
        int m = locationVex(G, v2);
        // 条件判断
        if(m == -1 || n == -1){
            printf("寻找失败--");
            return;
        }
        //无向图的二阶矩阵沿主对角线对称
        G->arcs[n][m].adj = w;
    }
}

/**
 * 选择图的类型
 * @return
 */
void CreateGraph(MGraph* G){
    printf("请输入选择的图类型:\n");
    scanf("%d", &(G->kind));
    //通过不同的函数实现不同的类型
    switch (G->kind) {
        case 0:
            return CreateDG(G);
            break;
        case 1:
            return CreateDN(G);
            break;
        case 2:
            return CreateUDG(G);
            break;
        case 3:
            return CreateUDN(G);
            break;
        default:
            break;
    }
}

/**
 * 打印矩阵
 * @return
 */
void showGrapth(MGraph G){
    printf("输出邻接矩阵为:\n");
    // 遍历操作
    for(int i=0; i < G.vexNum; i++){
        for(int j=0; j < G.vexNum; j++){
            printf("%d", G.arcs[i][j].adj);
        }
        printf("\n");
    }
}
int main()
{
    // 结构体变量
    MGraph G;
    // 调用函数
    CreateGraph(&G);
    // 打印矩阵
    showGrapth(G);
    return 0;
}