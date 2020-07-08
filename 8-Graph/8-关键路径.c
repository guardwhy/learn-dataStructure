/**
 * 关键路径
 */
#include <stdio.h>
#include <stdlib.h>
/**
 * 宏定义
 */
#define  MAX_NUM 20//最大顶点个数
#define  VertexType int//顶点数据的类型
typedef enum{false,true} bool;

//最早开始时间
VertexType ve[MAX_NUM];
//最晚开始时间
VertexType vl[MAX_NUM];

/**
 * 边表结点
 * @return
*/
typedef struct ArcNode{
    int adjvex;//邻接点域,存储该顶点对应的下标
    struct ArcNode * nextarc;//链域,指向下一个邻接点的指针
    VertexType weight; // 权值
}ArcNode;

/**
 * 顶点表结点
 * @return
*/
typedef struct VNode{
    VertexType data;//顶点的数据域
    ArcNode * firstarc;//指向邻接点的指针
}VNode,AdjList[MAX_NUM];//存储各链表头结点的数组

/**
 * 图的结构
 * @return
*/
typedef struct {
    AdjList vertices;//图中顶点及各邻接点数组
    int vexnum,arcnum;//记录图中顶点数和边或弧数
}ALGraph;

/**
 * 判断出顶点在二维数组中的位置
 * @return
 */
int LocateVex(ALGraph G,VertexType u){
    for (int i=0; i<G.vexnum; i++) {
        if (G.vertices[i].data==u) {
            return i;
        }
    }
    return -1;
}

/**
 *创建AOE网
 * @return
 */
void CreateAOE(ALGraph **G){
    // 定义变量
    VertexType begin,end,weight;
    // 动态内存分配
    *G=(ALGraph*)malloc(sizeof(ALGraph));
    //输入顶点数和边数
    scanf("%d,%d",&((*G)->vexnum),&((*G)->arcnum));

    // 读入顶点信息,建立顶点表
    for (int i=0; i<(*G)->vexnum; i++) {
        scanf("%d",&((*G)->vertices[i].data));
        (*G)->vertices[i].firstarc=NULL;
    }

    /**
     * 邻接矩阵初始化
     * @param G
     */
    for (int i=0; i<(*G)->arcnum; i++) {
        // 请输入数据
        scanf("%d,%d,%d", &begin, &end, &weight);
        ArcNode *p=(ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex=LocateVex(*(*G), end);
        p->nextarc=NULL;
        p->weight=weight;

        int locate=LocateVex(*(*G), begin);
        p->nextarc=(*G)->vertices[locate].firstarc;
        (*G)->vertices[locate].firstarc=p;
    }
}

/**
 * 结构体定义栈结构
 */
typedef struct stack{
    VertexType data;
    struct stack * next;
}stack;

/**
 * 定义栈指针
 */
stack *T;

/**
 * 初始化栈结构
 */
void initStack(stack* *S){
    (*S)=(stack*)malloc(sizeof(stack));
    (*S)->next=NULL;
}

/**
 * 判断栈是否为空
 * @param S
 * @return
 */
bool StackEmpty(stack S){
    if (S.next==NULL) {
        return true;
    }
    return false;
}

/**
 * 入栈操作
 * @param S
 * @param u
 */
void push(stack *S,VertexType u){
    stack *p=(stack*)malloc(sizeof(stack));
    p->data=u;
    p->next=NULL;
    //进栈，以头插法将新结点插入到链表中
    p->next=S->next;
    S->next=p;
}

/**
 * 弹栈操作
 * @param S
 * @param i
 */
void pop(stack *S,VertexType *i){
    // 删除链表首元结点的同时,并将该结点中的数据域通过地址传值给变量i;
    stack *p=S->next;
    *i=p->data;
    S->next=S->next->next;
    // 释放空间
    free(p);
}

/**
 * 统计入度
 * @param G
 * @param indegree
 */
void FindInDegree(ALGraph G,int indegree[]){
    //初始化数组，默认初始值全部为0
    for (int i=0; i<G.vexnum; i++) {
        indegree[i]=0;
    }
    //遍历邻接表，根据各链表中结点的数据域存储的各顶点位置下标，在indegree数组相应位置+1
    for (int i=0; i<G.vexnum; i++) {
        ArcNode *p=G.vertices[i].firstarc;
        while (p) {
            indegree[p->adjvex]++;
            p=p->nextarc;
        }
    }
}

/**
 * 拓扑排序算法
 * @param G
 * @return
 */
bool TopologicalSort(ALGraph G){
    //顶点入度的数组
    int indegree[G.vexnum];
    //统计各顶点的入度
    FindInDegree(G,indegree);

    //建立栈结构，程序中使用的是链表
    stack *S;
    //初始化栈
    initStack(&S);
    for (int i=0; i<G.vexnum; i++) {
        ve[i]=0;
    }
    //查找度为0的顶点，作为起始点
    for (int i=0; i<G.vexnum; i++) {
        if (!indegree[i]) {
            push(S, i);
        }
    }
    int count=0;
    //栈为空为结束标志
    while (!StackEmpty(*S)) {
        int index;
        //弹栈，并记录栈中保存的顶点所在邻接表数组中的位置
        pop(S,&index);
        //压栈，为求各边的最晚开始时间做准备
        push(T, index);
        ++count;
        //依次查找跟该顶点相链接的顶点，如果初始入度为1，当删除前一个顶点后，该顶点入度为0
        for (ArcNode *p=G.vertices[index].firstarc; p ; p=p->nextarc) {

            VertexType k=p->adjvex;

            if (!(--indegree[k])) {
                //入栈
                push(S, k);
            }
            //ve数组中存储的就是各顶点的最长路径长度。
            if (ve[index]+p->weight > ve[k]) {
                ve[k]=ve[index]+p->weight;
            }
        }
    }
    //如果count值小于顶点数量，表明有向图有环
    if (count<G.vexnum) {
        printf("该图有回路");
        return false;
    }
    return true;
}

/**
 * 关键路径
 */
void CriticalPath(ALGraph G){
    // 定义变量
    int j,k;
    // 条件判断
    if (!TopologicalSort(G)) {
        return ;
    }
    for (int i=0 ; i<G.vexnum ; i++) {
        vl[i]=ve[G.vexnum-1];
    }

    while (!StackEmpty(*T)) {
        pop(T, &j);
        for (ArcNode* p=G.vertices[j].firstarc ; p ; p=p->nextarc) {
            k=p->adjvex;
            //构建Vl数组，如果每个边的汇点-边的权值比源点值小，就保存更小的。
            if (vl[k]-p->weight < vl[j]) {
                vl[j] = vl[k]-p->weight;
            }
        }
    }
    for (j = 0; j < G.vexnum; j++) {
        for (ArcNode*p = G.vertices[j].firstarc; p ;p = p->nextarc) {
            k = p->adjvex;
            //求各边的最早开始时间e[i],等于ve数组中相应源点存储的值
            int a = ve[j];
            //求各边的最晚开始时间l[i]，等于汇点在vl数组中存储的值减改边的权值
            int b = vl[k] - p->weight;
            //判断e[i]和l[i]是否相等，如果相等，该边就是关键路径.用@表示
            char flag = (a == b) ? '@' : ' ';
            printf("%3d%3d%3d%3d%3d%2c\n", j, k, p->weight, a, b, flag);
        }
    }
}
int main(){
    // 结构体变量
    ALGraph *G;
    //创建AOE网
    CreateAOE(&G);
    // 初始化栈
    initStack(&T);
    // 拓扑排序
    TopologicalSort(*G);
    // 最短路径
    CriticalPath(*G);
    return  0;
}