/**
 *归并排序
 * @return
*/
#include <stdio.h>

/**
 * 宏定义
*/
#define MAX 14

/**
 * 归并排序中的合并算法
 * @return
*/
void Merge(int arr[], int left, int m, int right){
    //临时数组
    int temp[MAX] = {0};
    // 第一个数组索引
    int i;
    // 第二个数组索引
    int j;
    // 临时数组索引
    int k;

    // 分别将 i, j, k 指向各自数组的首部。
    for(i=left, j=m+1, k=0; k <= right-left; k++){
        // i到达第一个数组的尾部,将第二个数组余下元素复制到临时数组中
        if(i == m+1){
            temp[k] = arr[j++];
            continue;
        }
        //若j到达第二个数组的尾部,将第一个数组余下元素复制到临时数组中
        if(j == right+1){
            temp[k] = arr[i++];
            continue;
        }
        //如果第一个数组的当前元素比第二个数组的当前元素小,将第一个数组的当前元素复制到临时数组中
        if(arr[i] < arr[j]){
            temp[k] = arr[i++];
        } else{
            //如果第二个数组的当前元素比第一个数组的当前元素小,将第二个数组的当前元素复制到临时数组中
            temp[k] = arr[j++];
        }
    }

    //将有序的临时数组元素复制到被排序的数组arr中
    for(i=left, j=0; i<= right; i++,j++){
        arr[i] = temp[j];
    }
}

/**
 * 插入排序函数
 * @return
*/
void MergeSort(int arr[], int start, int end){
    // 条件判断
    if(start < end){
        // 定义变量
        int i;
        i = (end + start) / 2;
        // 对数组前半部分进行排序
        MergeSort(arr, start, i);
        // 对数组后半部分进行排序
        MergeSort(arr, i+1, end);
        // 合并前后部分
        Merge(arr, start, i, end);
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
    printf("归并排序比较: \n");
    // 定义数组
    int arr[MAX] = {22,34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
    // 数组长度
    int len = (int)sizeof(arr) / sizeof(*arr);
    // 定义变量
    int result1, result2;

    printf("排序前: ", result1);
    // 调用打印函数
    result1 = printArray(arr, len);

    printf("排序后: ", result2);
    // 调用排序函数
    MergeSort(arr, 0, MAX-1);
    result2 = printArray(arr, len);

    return 0;
}
