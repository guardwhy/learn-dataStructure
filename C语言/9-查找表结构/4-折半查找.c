/**
 * 折半查找
 */
#include <stdio.h>

/**
 * 宏定义
*/
#define MAXSIZE 100 // 存储空间初始分配量
typedef int Status; // 函数类型

/**
 * 折半查找
 * @return
*/
int Binary_Search(int* a, int n, int key){
    // 定义变量
    int low, high, mid;
    // 定义最低下标为记录首位
    low = 1;
    // 定义最高下标为记录末位
    high = n;

    // 条件判断
    while (low <= high){
        // 折半操作
        mid = (low + high)/2;
        // 查找值比插值小
        if(key < a[mid])
            // 最高下标调整到插值下标小一位
            high = mid -1;
            // 查找值比插值大
        else if( key > a[mid])
            // 最小下标调整到插值下标大一位
            low = mid + 1;
        else
            // 相等则说明mid即为查找的位置
            return mid;
    }

    return 0;
}

int main() {
    // 定义变量
    int a[MAXSIZE+1], i;
    // 创建数组
    int arr[MAXSIZE]={0,1,16,24,35,47,59,62,73,88,99};

    for(i=0;i<=MAXSIZE;i++)
    {
        a[i]=i;
    }

    // 调用函数
    int result = Binary_Search(arr, 10, 16);
    // 输出寻找结果
    printf("折半查找:%d \n", result);
    return 0;
}