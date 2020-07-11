/**
 * 斐波那契查找
 */
#include <stdio.h>

/**
 * 宏定义
*/
#define MAXSIZE 100 // 存储空间初始分配量
typedef int Status; // 函数类型
int Fib[100]; // 斐波那契数列

/**
 * 斐波那契查找
 * @return
*/
int Fibonacci_Search(int* a, int n, int key){
    // 定义变量
    int low, high, mid, i, k=0;
    // 定义最低下标为记录首位
    low = 1;
    // 定义最高下标为记录末位
    high = n;

    // 条件判断
    while (n > Fib[k]-1){
       k++;
    }
    for(i=n; i < Fib[k]-1; i++){
        a[i] = a[n];
    }

    // 条件判断
    while (low<=high){
        // 插值操作
        mid = low + Fib[k-1]-1;
        if(key < a[mid]){
            high = mid - 1;
            k = k - 1;
        }else if(key > a[mid]){
            low = mid + 1;
            k = k - 2;
        }else{
            // 假如相等则说明mid即为查找到的位置
            if(mid <= n){
                return mid;
            } else{
                return n;
            }
        }
    }

    return 0;
}

int main() {
    // 定义变量
    int a[MAXSIZE+1], i;
    // 创建数组
    int arr[MAXSIZE]={0,1,16,24,35,47,59,62,73,88,99};

    // 数组赋值
    Fib[0] = 0;
    Fib[1] = 1;

    for(i=2; i < 100; i++){
        Fib[i] = Fib[i-1] + Fib[i-2];
    }

    // 调用函数
    int result = Fibonacci_Search(arr, 10, 62);
    // 输出寻找结果
    printf("斐波那契查找:%d \n", result);
    return 0;
}