/**
 * 迪杰斯特拉算法
 */
#include <stdio.h>
#define MAX_NUM 20 // 顶点的最大个数
#define VRType int  // 边的权值类型
#define VertexType int // 顶点数据类型
#define INFINITY 65535 // 路径权值为极大值

/**
 * 图结构
 * @return
*/
typedef struct {
    VertexType vexs[MAX_NUM]; // 存储顶点数据
    VertexType arcs[MAX_NUM][MAX_NUM]; // 二维数组,记录顶点之间的关系
    int vexnum, arcnum; // 记录图的顶点数和弧边数
}MGraph;

/**
 * 存储最短路径经过的顶点下标
 * @return
*/
typedef int PathMatrix[MAX_NUM];

/**
 * 存储最短路径的权值和
 * @return
*/
typedef int ShortPathTable[MAX_NUM] ;

/**
 * 存储顶点二维数组的位置
 * @return
*/
int locationVex(MGraph* G, VertexType v){
    // 定义变量
    int i=0;
    // 遍历一维数组,找到变量
    for(; i < G->vexnum; i++){
        if(G->vexs[i] == v){
            break;
        }
    }
    // 寻找失败
    if(i > G->vexnum){
        printf("寻找失败...\n");
        return -1;
    }

    return i;
}

/**
 * 构造无向图
 * @param G
 */
void CreateUDG(MGraph *G) {
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
            G->arcs[i][j] = INFINITY;
        }
    }
    // 读入arcNum条边,建立邻接矩阵
    for(int i=0; i < G->arcnum; i++){
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
        G->arcs[n][m] = w;
    }
}

/**
 *Dijkstra算法,s表示图中起始点所在数组中的下标
 * @return
*/
void ShortestPath_Dijkstra(MGraph G, int s, PathMatrix *p, ShortPathTable *temp){
    // 存储已经确定的最短路径
    int end[MAX_NUM];
    int k = 0;

    // 数组初始化
    for(int v=0; v<G.vexnum; v++){
        end[v] = 0;
        (*temp)[v] = G.arcs[s][v];
        (*p)[v] = 0;
    }
    // 以v0为下标的顶点为起始点
    (*temp)[s] = 0;
    end[s] = 1;
    for(int i=0; i < G.vexnum; i++){
        int min = INFINITY;
        //选择到各顶点权值最小的顶点
        for(int w=0; w<G.vexnum; w++){
            if(!end[w]){
                if((*temp)[w] < min){
                    k = w;
                    min = (*temp)[w];
                }
            }
        }
        //设置该顶点的标志位为1
        end[k] = 1;
        //对s到各顶点的权值进行更新
        for(int w=0; w < G.vexnum; w++){
            // 条件判断
            if(!end[w] && (min+G.arcs[k][w] < (*temp)[w])){
                // 记录各个最短路径上存在的顶点
                (*temp)[w] = min + G.arcs[k][w];
                (*p)[w] = k;
            }
        }
    }
}
int main()
{
    // 结构体变量
    MGraph G;
    // 构造无向图
    CreateUDG(&G);
    // 定义变量
    PathMatrix p;
    ShortPathTable temp;
    // 调用最短路径算法
    ShortestPath_Dijkstra(G, 0, &p, &temp);

    // 输出顶点
    for(int i=1; i<G.vexnum; i++){
        // 定义变量
        int j = i;
        printf("V%d-V%d的最短路径中的顶点: ", 0, i);
        printf("V%d ", i);

        // 得到各个最短路径上的所有顶点
        while(p[j]!=0){
            printf("v%d", p[j]);
            j = p[j];
        }
        printf("V0\n");
    }
    printf("源点到各顶点的最短路径长度为:\n");
    for (int i=1; i<G.vexnum; i++) {
        printf("V%d - V%d : %d \n",G.vexs[0],G.vexs[i],temp[i]);
    }
    return 0;
}