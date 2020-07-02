#include <stdio.h>
#include <stdbool.h>
/**
 * 宏定义
 * @return
 */
#define INFINITY INT_MAX // 最大值
#define MAXNUM 20 // 顶点数最大个数
#define VRType int // 顶点变量类型
#define InfoType char // 存储边指针变量类型
#define VertexType char // 顶点数据类型

/**
  * 图的种类
  * @return
 */
typedef enum{
    DG, //有向图
    DN, //有向网
    UDG,//无向图
    UDN // 无向网
}GraphKind;
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
    // 顶点表
    VertexType vexs[MAXNUM];
    // 二维数组,记录顶点之间的关系
    AdjMatri arcs;
    // 图的顶点数和边数
    int vexNum, arcNum;
    // 图的种类标志
    GraphKind kind;
}MGraph;

/**
 * 判断出顶点在二维数组中的位置
 * @return
 */
int locationVex(MGraph G, VertexType v){
    // 定义变量
    int i;
    // 遍历数组,寻找变量
    for(i = 0; i<G.vexNum; i++){
        if(G.vexs[i] == v)
            return i;
    }
    // 寻找失败
    return -1;
}

/**
 * 构建无向图
 * @return
 */
bool CreateUDG(MGraph *G) {
    // 定义变量
    int i, j, k, IncInfo;
    // 定义变量
    VertexType v1, v2;

    printf("请输入无向图顶点个数和边的个数和边的其他信息(若为0,则表示不含其他): \n");
    //输入顶点数和边数
    scanf("%d %d %d", &(G->vexNum),&(G->arcNum), &IncInfo);

    // 读入顶点信息,建立顶点表
    for(i=0; i <G->vexNum; i++){
        // 清空缓存
        fflush(stdin);
        printf("请输入顶点:\n");
        scanf("%c", &(G->vexs[i]));
    }
    /**
     * 邻接矩阵初始化
     * @param G
     */
    for(i=0; i < G->vexNum; i++){
        for(j =0; j<G->vexNum; j++){
            // 赋值操作
            G->arcs[i][j].adj = 0;
            G->arcs[i][j].info = NULL;
        }
    }
    // 读入arcNum条边,建立邻接矩阵
    for(k=0; k < G->arcNum; k++){
        fflush(stdin);

        printf("请输入边所依附的两个顶点: \n");
        scanf("%c,%c", &v1, &v2);

        i = locationVex(*G, v1);
        j = locationVex(*G, v2);
        //无向图的二阶矩阵沿主对角线对称
        G->arcs[i][j].adj = 1;

        if(IncInfo){
            printf("请输入边的其他信息: \n");
            scanf("%c", &G->arcs[i][j].info);
        }
        G->arcs[j][i] = G->arcs[i][j];
    }
    G->kind = UDG;
    return true;
}

/**
 *访问标志的数组
 * @return
 */
bool visited[MAXNUM];

/**
 * 邻接矩阵深度优先递归算法
 * @return
 */
void DFS(MGraph G, int v){
    // 定义变量
    int w;
    visited[v] = true;
    for(w=0; w < G.vexNum; w++){
        // 对访问邻接点递归调用
        if(G.arcs[v][w].adj == 1 && !visited[w]){
            DFS(G, w);
        }
    }
}

/**
 * 遍历操作
 * @return
 */
void DFSTraverse(MGraph G){
    // 定义变量
    int v, k, count = 0;
    for(v=0; v < G.vexNum; v++)
        visited[v] = false;
    for(k=0; k<G.vexNum; k++){
        // 判断条件
        if(!visited[k]){
            DFS(G, k);
            count++;
        }
    }
    if(count == 1)
        printf("该图为连通图!!!\n");
     else
        printf("该图为非连通图!!!\n");

}
int main() {
    // 结构体变量
    MGraph G;
    // 调用函数
    CreateUDG(&G);
    DFSTraverse(G);
    return 0;
}