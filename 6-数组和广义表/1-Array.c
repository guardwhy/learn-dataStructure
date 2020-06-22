#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <malloc.h>
#include <math.h>

// 宏定义
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW 3
#define UNDERFLOW 4
#define MAX_ARRAY_DIM 8 // 设置数组维数的最大值为8

// 函数类型
typedef int Status ;
// 布尔类型
typedef int Boolean;
// 类型
typedef int ElemType;
typedef struct {
    ElemType *base; // 存放元素的基址
    int dim; // 数组维数
    int* bounds; // 等价整形数组,存各维长度
    int* constants; // 每变化一维的跨度
}Array;

// 数组初始化
Status InitArray(Array* A, int dim,...){
    //elemtotal元素总值
    int elemtotal = 1, i;
    // 定义指向参数的指针ap
    va_list ap;
    // 条件判断
    if(dim<1 || dim>MAX_ARRAY_DIM)
        return ERROR;
    // 数组维度
    (*A).dim = dim;
    // 数组维界基址
    (*A).bounds = (int*)malloc(dim* sizeof(int));
    if(!(*A).bounds)
        exit(OVERFLOW);
    va_start(ap,dim);
    for(i=0; i<dim; ++i){
        (*A).bounds[i] = va_arg(ap, int);
        if((*A).bounds[i] < 0)
            return UNDERFLOW;
        elemtotal*=(*A).bounds[i];
    }
    va_end(ap);
    (*A).base = (ElemType *)malloc(elemtotal* sizeof(ElemType));
    if(!(*A).base)
        exit(OVERFLOW);
    (*A).constants=(int *)malloc(dim*sizeof(int));
    if(!(*A).constants)
        exit(OVERFLOW);
    (*A).constants[dim-1]=1;
    for(i=dim-2; i>=0; --i)
        (*A).constants[i]=(*A).bounds[i+1]*(*A).constants[i+1];
    return OK;
}

/**
 * 销毁操作
 * @param A
 * @return
 */
Status DestroyArray(Array* A){
    // 销毁数组A
    if((*A).base){
        // 释放内存
        free((*A).base);
        (*A).base = NULL;
    } else{
        return ERROR;
    }

    if((*A).bounds){
        free((*A).bounds);
        (*A).bounds = NULL;
    } else{
        return ERROR;
    }

    if((*A).constants){
        free((*A).constants);
        (*A).constants = NULL;
    } else
        return ERROR;
    return OK;
}

/**
 * 存储地址
 * @param A
 * @param ap
 * @param off
 * @return
 */
Status Locate(Array A, va_list ap, int *off){
    // ap指示的各下标值合法，则求出该元素在A中的相对地址off
    int i, ind;
    *off = 0;
    // 遍历
    for(i=0; i<A.dim; i++){
        ind = va_arg(ap, int);
        // 条件判断
        if(ind<0 || ind>=A.bounds[i])
            return OVERFLOW;
        *off += A.constants[i]*ind;
    }
    return OK;
}

Status Value(ElemType *e, Array A,...){
    // 定义指向参数的指针ap
    va_list ap;
    Status result;
    int off;
    va_start(ap, A);
    // 调用locate
    if((result=Locate(A,ap,&off)) == OVERFLOW)
        return result;
    *e = *(A.base+off);
    return OK;
}

Status Assign(Array* A, ElemType e, ...){
    va_list ap;
    Status result;
    int off;
    va_start(ap, e);
    if((result=Locate(*A, ap, &off)) == OVERFLOW)
        return result;
    *((*A).base+off) = e;
    return OK;
}
int main() {
    // 结构体变量
    Array A;
    // 数组a[3][4][2]
    int i, j, k, *p;
    int dim = 3;
    int bound1=3, bound2=4,bound3=2;
    ElemType e, *p1;
    // 调用函数
    InitArray(&A, dim, bound1,bound2,bound3);
    p = A.bounds;
    printf("A.bounds=");

    // 顺序输出A.bounds
    for(i=0; i<dim; i++)
        printf("%d", *(p+i));
    p = A.constants;
    printf("\nA.constants=");

    // 顺序输出A.constants
    for(i=0; i<dim; i++)
        printf("%d", *(p+i));
    printf("\n%d页%d行%d列矩阵元素如下:\n", bound1, bound2, bound3);
    for(i=0; i<bound1; i++){
        for(j=0; j<bound2; j++){
            for(k=0; k<bound3; k++){
                // 赋值给A[i][j][k]
                Assign(&A, i*100+j*10+k, i, j, k);
                // 输出A[i][j]
                printf("A[%d][%d][%d]=%2d ", i, j, k, e);
            }
            printf("\n");
        }
        printf("\n");
    }
    p1 = A.base;
    printf("A.base=\n");
    // 遍历条件,顺序输出A.base
    for(i=0; i<bound1*bound2*bound3; i++){
        printf("%4d", *(p1 + i));
        if(i%(bound2*bound3)==bound2*bound3-1)
            printf("\n");
    }
    DestroyArray(&A);
    return 0;
}