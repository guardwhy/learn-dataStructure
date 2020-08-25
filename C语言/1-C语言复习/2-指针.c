#include <stdio.h>
/*
指针和指针变量
指针：变量的地址，可以用运算符&获得一个变量的地址。&a:就获得变量a的地址（指针）
指针变量：存储指针的变量，即变量里存储的是某种类型的指针（地址）
如type是一个数据类型，则type*也是一个数据类型，称为type指针类型。
type* 类型的变量只能存储type类型变量的地址
*/

// 声明函数
void test_pointer(){
    printf("test_pointer:\n");
    // 定义变量
    int a = 3;
    // 得到变量a的地址
    printf("%p\n", &a); // 0x7ffe5b247a3c

    // p是int*类型,可以存储一个int类型变量的地址
    int* p = &a;
    // p里面的内容是a的地址
    printf("%p\n", p); // 0x7ffe5b247a3c

}

int main()
{
    // 调用函数
    test_pointer();
    return 0;
}
