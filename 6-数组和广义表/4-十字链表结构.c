/**
 * 十字链表结构
 */
#include <stdio.h>
#include <stdlib.h>
/**
 * 结构体类型
 * @return
 */
typedef struct OLNode{
    // 行标i 列表j
    int i, j;
    // 当前位置的数据
    int e;
    struct OLNode *right, *down; // 指针域 右指针 下指针
}OLNode, *OLink;

/**
 * 十字链表矩阵表示
 */
typedef struct {
    OLink  *rhead, *chead; // 行和列链表头指针
    int mu, nu, tu; // 矩阵的行数,列数,非零元的个数
}CrossList;

// 声明函数
CrossList CreateMatrix(CrossList M){
    // 定义变量
    int m, n, t;
    int i, j, e;
    // 声明指针
    OLNode *p, *q;

    printf("输入矩阵的行数、列数和非0元素个数: \n");
    scanf("%d%d%d", &m, &n, &t);
    M.mu = m;
    M.nu = n;
    M.tu = t;
    if (!(M.rhead = (OLink*)malloc((m + 1) * sizeof(OLink))) ||
    !(M.chead = (OLink*)malloc((n + 1) * sizeof(OLink))))
    {
        printf("初始化矩阵失败");
        exit(0);
    }
    for (i = 1; i <= m; i++)
    {
        M.rhead[i] = NULL;
    }
    for (j = 1; j <= n; j++)
    {
        M.chead[j] = NULL;
    }
    for (scanf("%d%d%d", &i, &j, &e); 0 != i; scanf("%d%d%d", &i, &j, &e)) {
        if (!(p = (OLNode*)malloc(sizeof(OLNode))))
        {
            printf("初始化三元组失败");
            exit(0);
        }
        p->i = i;
        p->j = j;
        p->e = e;
        //链接到行的指定位置
        if (NULL == M.rhead[i] || M.rhead[i]->j > j)
        {
            p->right = M.rhead[i];
            M.rhead[i] = p;
        }
        else
        {
            for (q = M.rhead[i]; (q->right) && q->right->j < j; q = q->right);
            p->right = q->right;
            q->right = p;
        }
        //链接到列的指定位置
        if (NULL == M.chead[j] || M.chead[j]->i > i)
        {
            p->down = M.chead[j];
            M.chead[j] = p;
        }
        else
        {
            for (q = M.chead[j]; (q->down) && q->down->i < i; q = q->down);
            p->down = q->down;
            q->down = p;
        }
    }
    return M;
}

// 显示矩阵
void showCrossList(CrossList M){
    for(int i=1; i <= M.nu; i++){
        // 条件判断
        if(NULL != M.chead[i]){
            OLink p = M.chead[i];
            while(NULL != p){
                printf("%d\t%d\t%d\n", p->i, p->j, p->e);
                p= p->down;
            }
        }
    }
}
int main() {
    // 定义结构体变量
    CrossList M;
    // 声明指针
    M.rhead = NULL;
    M.chead = NULL;
    // 调用函数
    M = CreateMatrix(M);
    printf("输出矩阵M:\n");
    // 调用函数
    showCrossList(M);
    return 0;
}