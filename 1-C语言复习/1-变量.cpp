#include <iostream>

using namespace std;

// c++变量即用即定义，C语言必须在函数开头声明
void test_var_def(){
    // 定义变量
    int a = 2, s;
    s = 6;
    int c = 2;
    cout << "a的值:" << a << endl << "s的值:"<< s << endl<< "c的值:"<< c << endl;

    // printf("%d %d\n", a, c);
}

// 引用变量。引用其他变量的变量,引用形参本身不具备独立的内存
void test_var_ref(){
    printf("kobe是超级英雄\n");
    // 定义变量
    int a = 3;
    int& b = a;

    cout << "a的值:" << a << endl;
    cout << "b的值:" << b << endl;

    // 定义b的值
    b = 5;
    cout << "a的值:" << a << endl;
    cout << "b的值:" << b << endl;
}

// 引用变量主要用于函数的形参，即引用引用形参引用的是实际参数
void ref_value(int &ref, int value){
    ref += 3;
    value += 2;
}

void test_ref_value(){
    // 输出语句
    printf("test_var_vaule:\n");
    // 定义变量
    int x = 3;
    int y = 5;
    // 调用函数
    ref_value(x, y);
    // 输出结果
    printf("%d %d\n", x, y);
}

int main()
{
    // 调用函数
    test_var_def();
    
    test_var_ref();
    test_ref_value();
    return 0;
}
