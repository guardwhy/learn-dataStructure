#include <stdio.h>
#include <malloc.h>
/**
 * C语言通过p= malloc(n);
 * p= realloc（oldp,n);分配内存，迪过 free（p）释放内存.
 * @return
 */
// 声明函数
void test_malloc(){
    // 定义变量
    int a = 3;
    int *p = &a; // p存储a的地址,即p指向a
    *p = 4;

    // 动态内存分配,分配1个int
    p=(int *)malloc(sizeof(int)); // p存储动态内存块的地址,p指向这个int的内存。
    *p = 5; // void*
    // 释放内存
    free(p);

    p = (int*)malloc(3*sizeof(int)); // p指向可以存放3个int的内存的第一个int的地址
    *p = 6;
    // 输出结果
    printf("%d\n", p[0]);   // p[0]就是*(p+0) 即*p

    *(p+1) = 7;
    *(p+2) = 8;
    // 遍历
    for(int i=0; i<3; i++){
        printf("%d", p[i]); // *(p+i)
    }
    printf("\n");

    int *p0 = p;
    int *q = p + 3;
    // 条件判断
    while (p < q){
        printf("%d", *p);
        p++;
    }
    printf("\n");
    // free(p0);

    //重新动态分配内存
    q = (int*)realloc(p0, 5*sizeof(int));
    p = q;

    *(p + 3) = 9;
    *(p + 4) = 10;

    p0 = p;
    q = p + 5;
    while (p < q){
        printf("%d", *p);
        p++;
    }
    printf("\n");
    free(p0);
}

int main() {
    // 调用函数
    test_malloc();
    return 0;
}