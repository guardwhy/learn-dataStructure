#include <iostream>
/**
 动态内存分配
对于类型T,可以用newT分配一块T类型值大小的内存块，也可以用newT[n]分配可存放n个T类型的内存块，也称为动态数组。
对于p=newT，必须用 delete p释放这块动态内存块,对于p= new T[n]，必须用 delete[]p释放这块动态内存块。
 */
using namespace std;

// 声明函数
void test_malloc(){
    // 定义变量
    int a = 3;
    int *p = &a; // p存储a的地址,即p指向a
    *p = 4;

    p = new int; // p存储动态内存块的地址,p指向这个int大小的内存块。
    *p = 5; // *p就是这个动态内存，将其中值设置为5
    // 释放内存
    delete p;

    p = new int[3]; // p指向可以存放3个int的内存块的第一个int块的地址
    *p = 6;
    // 输出,p[0]就是*(p+0) 就是*p
    cout << p[0] << endl; // 6

    *(p+1) = 7;
    *(p+2) = 8;
    // 遍历
    for(int i=0; i<3; i++){
        printf("%d", p[i]); // 6,7,8
    }
    printf("\n");

    // 定义指针变量
    int *p1 = p;
    int *q = p + 3;
    while(p < q){
        printf("%d", *p); // 6,7,8
        p++;
    }
    printf("\n");
    delete [] p1;

}
int main()
{
    // 调用函数
    test_malloc();
    return 0;
}
