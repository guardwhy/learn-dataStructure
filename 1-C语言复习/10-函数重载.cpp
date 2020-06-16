#include <iostream>

using namespace std;
/**
 * 函数重载
 * @return
 */
 void print(double *arr, const int n){
     // 遍历循环
     for(int i=0; i<n; i++){
         // 输出
         printf("%lf\n", arr[i]);
     }
 }
 // 声明函数
 void test_function_overload(){
     printf("test_function_overload:\n");
     // 定义数组
     int a[] = {1,2,3,5,7,6};
     // print(a,6);
     double b[] = {1.1,3.8,3.3,4.8,5.9};
     print(b,5);
 }

int main() {
    // 调用函数
    test_function_overload();
    return 0;
}