#include <iostream>
/*
    指针数组
*/
using namespace std;

// 声明函数
void test_pointer_array(){
    printf("test_pointer_array:\n");
    // 定义数组
    int a[] = {1,2,3,5,7,0};
    // 遍历循环
    for(int i=0; i<6; i++){
        printf("%d", a[i]);
        printf("\n");
    }
    printf("--------\n");

    // 定义指针变量
    int *p = a; // int *p = &(a[i]);
    // 遍历
    for(int i=0; i<6; i++){
        printf("%d", a[i]);
        printf("\n");
    }
    printf("--------\n");

    for(int i=0; i<6; i++){
        printf("%d", *(p+i));
        printf("\n");
    }
    printf("--------\n");

    int *q = a+6;
    for(; p < q; p++){
        printf("%d", *p);
        printf("\n");
    }

    
}

int main()
{
    // 调用函数
    test_pointer_array();
   
   return 0;
}
