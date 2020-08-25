/**
 * 广度优先搜索
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

//定义bool型常量
typedef enum{
    false,true}bool;
/**
 *访问标志的数组
 * @return
 */
bool visited[MAXNUM];

/**
 *循环队列的顺序存储结构
 * @return
 */
typedef struct Queue{
    // 数据域
    VertexType data;
    // 指针域
    struct Queue* next;
}Queue;

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
/**
 * 输出顶点函数
 * @param G
 * @param v
 */
void visitVex(MGraph G, int v){
    printf("%d ", G.vexs[v]);
}

/**
 * 判断队列是否为空
 * @param Q
 * @return
 */
bool QueueEmpty(Queue *Q){
    // 条件判断
    if(Q->next == NULL){
        return true;
    }

    return false;
}

/**
 * 初始化队列
 * @param Q
 */
void InitQueue(Queue** Q){
    // 分配内存
    (*Q) = (Queue*)malloc(sizeof(Queue));
    (*Q)->next = NULL;
}

/**
 * 顶点元素入队列
 * @param Q
 * @param v
 */
void EnQueue(Queue** Q, VertexType v){
    // 动态内存分配
    Queue* elem = (Queue*)malloc(sizeof(Queue));
    // 指向顶点
    elem->data = v;
    elem->next = NULL;
    // 定义临时指针
    Queue* temp = (*Q);
    // 条件判断
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = elem;
}

/**
 * 对头元素出队列
 * @param Q
 * @param s
 */
void DeQueue(Queue** Q, int* s){
    (*s) = (*Q)->next->data;
    (*Q)->next = (*Q)->next->next;
}

/**
 * 深度优先搜索
 * @return
 */
void  BFSTraverse(MGraph G){
    // 定义变量
    int i, j;
    // 数组初始化
    for(i=0; i<G.vexNum; ++i){
        visited[i] = false;
    }
    // 定义一个队列
    Queue* Q;
    // 初始化队列
    InitQueue(&Q);

    // 对每个顶点做循环
    for(i=0; i<G.vexNum; i++){
        // 判断是否访问
        if(!visited[i]){
            visited[i] = true;
            // 调用函数
            visitVex(G, i);
            // 将此顶点入队列
            EnQueue(&Q, G.vexs[i]);
            // 判断当前队列不为空
            while (!QueueEmpty(Q)){
                // 将队中元素出队列,赋值给j
                DeQueue(&Q, &j);
                j = locationVex(&G, j);
                for(int w=FirstAdjVex(G, j); w>=0; w=NextAdjVex(G, j, w)){
                    if(!visited[w]){
                        // 将找到此顶点标记以访问
                        visited[w] = true;
                        visitVex(G, w);
                        // 将找到的此顶点入队列
                        EnQueue(&Q, G.vexs[w]);
                    }
                }
            }
        }
    }
}

int main() {
    // 结构体变量
    MGraph G;
    // 初始化图
    CreateUDG(&G);
    // 深度优先搜索
    BFSTraverse(G);
    return 0;
}