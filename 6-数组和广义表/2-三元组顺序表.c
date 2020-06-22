#include <stdio.h>
/**
 * 三元组顺序存储
 * @return
 */

// 存储结构定义
#define MAXSIZE 200
typedef int ElemType;

//三元组结构体
typedef struct {
    // 行标i 列表j
    int i, j;
    // 元素值
    ElemType e;
}Triple;
// 矩阵结构表示
typedef struct{
    // 存储矩阵中所有非0元素的三元组'
    Triple data[MAXSIZE + 1];
    //mu和nu分别记录矩阵的行数和列数,tu记录矩阵中所有的非0元素的个数.
    int mu, nu, tu;
}TSmatrix;

// 初始化稀疏矩阵
void InitTSmatrix(TSmatrix *M){
    // 定义变量
    int a,b, c, x, y, z;
    printf("请输入行数,列数和非零源的个数: \n");
    scanf("%d%d%d", &a, &b, &c);
    M->mu = a;
    M->nu = b;
    M->tu = c;

    printf("请输入非零元所对应的三元组(i,j,e) :\n");
    for(int k=1; k <=M->tu; k++){
        printf("请输入第%d个非零元素: ", k);
        scanf("%d%d%d", &x, &y, &z);
        M->data[k].i = x;
        M->data[k].j = y;
        M->data[k].e = z;
    }
}

// 输出存储的稀疏矩阵
void show(TSmatrix M){
    printf("当前的稀疏矩阵的非零元依次是:\n");
    for(int k=1; k<=M.tu; k++){
        printf("%d %d %d\n", M.data[k].i, M.data[k].j,M.data[k].e);
    }
}
int main() {
    // 结构体变量
    TSmatrix s;
    InitTSmatrix(&s);
    show(s);
    return 0;
}