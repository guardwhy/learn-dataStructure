/**
 * 行逻辑顺序表
 * @return
 */
#include <stdio.h>
#define MAXSIZE 100
#define MAXRC 100
#define ElemType int
/**
 * 结构体类型
 */
typedef struct {
    // 行标i 列表j
    int i, j;
    // 元素值
    ElemType e;
}Triple;

/**
 * 矩阵结构表示
 * @return
 */
typedef struct {
    // 存储矩阵中所有非0元素的三元组
    Triple data[MAXSIZE+1];
    // 行数,列数,元素个数
    int mu, nu, tu;
    //每行第一个非零元素在data数组中的位置
    int rpos[MAXRC+1];
}RLSMatrix;

// 矩阵输出函数
void showRLSMatrix(RLSMatrix M){
    for(int i=1;i<=M.mu;i++){
        for(int j=1;j<=M.nu;j++){
            // 设置value值
            int value=0;
            if(i+1 <=M.mu){
                for(int k=M.rpos[i];k<M.rpos[i+1];k++){
                    if(i == M.data[k].i && j == M.data[k].j){
                        printf("%d ",M.data[k].e);
                        value=1;
                        break;
                    }
                }
                if(value==0){
                    printf("0 ");
                }
            }else{
                for(int k=M.rpos[i];k<=M.tu;k++){
                    if(i == M.data[k].i && j == M.data[k].j){
                        printf("%d ",M.data[k].e);
                        value=1;
                        break;
                    }
                }
                if(value==0){
                    printf("0 ");
                }
            }
        }
        printf("\n");
    }
}
int main() {
   // 结构体变量
   RLSMatrix M;

    M.tu = 4;
    M.mu = 3;
    M.nu = 4;
    M.rpos[1] = 1;
    M.rpos[2] = 3;
    M.rpos[3] = 4;
    M.data[1].e = 3;
    M.data[1].i = 1;
    M.data[1].j = 2;
    M.data[2].e = 5;
    M.data[2].i = 1;
    M.data[2].j = 4;
    M.data[3].e = 1;
    M.data[3].i = 2;
    M.data[3].j = 3;
    M.data[4].e = 2;
    M.data[4].i = 3;
    M.data[4].j = 1;
    // 调用函数,输出矩阵
    showRLSMatrix(M);
    return 0;
}