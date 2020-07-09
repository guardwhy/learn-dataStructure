/**
 * 弗洛伊德算法
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
typedef int PathMatrix[MAX_NUM][MAX_NUM];

/**
 * 存储最短路径的权值和
 * @return
*/
typedef int ShortPathTable[MAX_NUM][MAX_NUM] ;

/**
 * 存储顶点二维数组的位置
 * @return
*/
int locationVex(MGraph* G, VertexType v){
    // 定义变量
    int i;
    // 遍历一维数组,找到变量
    for(i=0; i < G->vexnum; i++){
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
void ShortestPath_Floyed(MGraph G, PathMatrix *p, ShortPathTable *temp){
    int v, w, k;
    // 数组初始化
    for( v=0; v<G.vexnum; v++){
        for(w=0; w<G.vexnum; w++){
            (*temp)[v][w] = G.arcs[v][w];
            (*p)[v][w] = -1;
        }
    }
    // 顶点遍历
    for(k=0; k<G.vexnum; k++){
        // 遍历网中任意两个顶点，判断间接的距离是否更短。
        for(v=0; v<G.vexnum; v++){
            for(w=0; w<G.vexnum; w++){
                // 存储距离更短的路径
                if((*temp)[v][w] > (*temp)[v][k] + (*temp)[k][w]){
                    (*temp)[v][w] = (*temp)[v][k] + (*temp)[k][w];
                    (*p)[v][w] = k;
                }
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
    ShortestPath_Floyed(G, &p, &temp);
    // 遍历操作
    for(int i=0; i<G.vexnum; i++){
        for(int j=0; j<G.vexnum; j++){
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
    for(int i=0; i<G.vexnum; i++) {
        for (int j = 0; j < G.vexnum; j++) {
            printf("%d ", temp[i][j]);
        }
        printf("\n");
    }
    return 0;
}