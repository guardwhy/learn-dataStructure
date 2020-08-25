#include <stdio.h>
/**
 * 宏定义
 * @return
 */
#define MAXNUM 20 // 顶点数最大个数
#define VRType int // 顶点变量类型
#define InfoType char // 存储边指针变量类型
#define VertexType int // 顶点数据类型

typedef enum{false,true}bool; //定义bool型常量
/**
 *访问标志的数组
 * @return
 */
bool visited[MAXNUM];

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
}MGraph;

/**
 * 判断出顶点在二维数组中的位置
 * @return
 */
int locationVex(MGraph* G, VertexType v){
    // 定义变量
    int i;
    // 遍历数组,寻找变量
    for(i = 0; i<G->vexNum; i++){
        if(G->vexs[i] == v)
            break;
    }
    // 寻找失败
    if(i>G->vexNum){
        printf("顶点不存在...");
        return -1;
    }
    return i;
}

/**
 * 构建无向图
 * @return
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
 * 查找第一个邻接顶点序号
 * @return
 */
int FirstAdjVex(MGraph G, int v){
    /**
     * 初始条件:图G存在,v是G中的某个顶点
     * 操作条件: 返回v的第一个邻接顶点的序号,若顶点在G中没有邻接顶点,则返回-1
     */
     for(int i=0; i<G.vexNum; i++){
         if(G.arcs[v][i].adj){
             return i;
         }
     }
    // 寻找失败
    return -1;
}

/**
 * 寻找顶点的下一个顶点
 * @return
 */
int NextAdjVex(MGraph G, int v, int w){
    /**
    * 初始条件:图G存在,v是G中的某个顶点,w是v的邻接点.
    * 操作条件: 返回v的下一个邻接顶点的序号,若w是v的最后一个邻接顶点,则返回-1
    */
    for(int i=w+1; i<G.vexNum; i++){
        if(G.arcs[v][i].adj){
            return i;
        }
    }
    // 寻找失败
    return -1;
}

void visitVex(MGraph G, int v){
    printf("%d ", G.vexs[v]);
}

/**
 * 邻接矩阵深度优先递归算法
 * @return
 */
void DFS(MGraph G, int v){
    // 定义变量
    int w;
    visited[v] = true;
    // 访问第v个顶点
    visitVex(G, v);
    // 遍历
    for(w=FirstAdjVex(G, v); w>=0; w=NextAdjVex(G, v, w)){
        // 判断是否被访问
        if(!visited[w])
            DFS(G,w);
    }
}

/**
 * 深度优先搜索
 * @return
 */
void DFSTraverse(MGraph G){
    //将用做标记的visit数组初始化为false
    for(int v=0; v<G.vexNum; ++v){
        visited[v] = false;
    }
    //对于每个标记为false的顶点调用深度优先搜索函数
    for(int v=0; v<G.vexNum; v++){
        if(!visited[v]){
            DFS(G, v);
        }
    }
}
int main() {
    // 结构体变量
    MGraph G;
    // 初始化图
    CreateUDG(&G);
    // 深度优先搜索
    DFSTraverse(G);
    return 0;
}