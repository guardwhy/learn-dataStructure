/**
 * 选择排序
 * @return
*/
#include <stdio.h>

/**
 * 选择排序函数
 * @return
*/
void insertion_sort(int arr[], int len){
    // 定义i,j,temp变量
    int i, j, temp;
    // 遍历操作
    for(i=0; i<len; i++){
       // 内层循环找出最小值,然后进行交换
       for(int j=i; j<len; j++){
           if(arr[j] < arr[i]){
               // 交换变量
               temp = arr[j];
               arr[j] = arr[i];
               arr[i] = temp;
           }
       }
    }
}

/**
 * 打印函数
 * @return
*/
int printArray(int arr[], int len){
    int i;
    for(i=0; i<len; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main()
{
    printf("选择排序比较: \n");
    // 定义数组
    int arr[] = {22,34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
    // 数组长度
    int len = (int)sizeof(arr) / sizeof(*arr);
    // 定义变量
    int result1, result2;

    printf("排序前: ", result1);
    // 调用打印函数
    result1 = printArray(arr, len);

    printf("排序后: ", result2);
    // 调用排序函数
    insertion_sort(arr, len);
    result2 = printArray(arr, len);

    return 0;
}
