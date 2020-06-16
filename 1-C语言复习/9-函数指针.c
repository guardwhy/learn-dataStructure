#include <stdio.h>
/**
 * 函数指针
 * @return
 */
 // 函数类型:void print(int*arr, const int n)
 // 函数指针类型: void(*)(int *arr, const int n)

 // 声明函数
 void print(int *arr, const int n){
     for(int i=0; i < n; i++){
         printf("%d\n", arr[i]);
     }

     printf("-----------\n");
 }

 void square(int *arr, const int n){
     for(int i=0; i < n; i++){
         arr[i] *= arr[i];
     }
 }

 int sum(int *arr, const int n){
     int s = 0;
     for(int i=0; i < n; i++){
         s += arr[i];
         return s;
     }
 }
 void test_function_pointer(){
     // 定义数组
     int a[] = {1,23,4,8,9,6};
     print(a, 6);
     printf("%d\n", sum(a,6));

     void(*fp)(int *arr, const int n) = 0;
     fp = square;
     fp (a, 6);
     fp = print;
     fp(a, 6);
 }
int main() {
    // 调用函数
    test_function_pointer();
    return 0;
}