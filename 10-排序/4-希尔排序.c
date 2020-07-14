/**
 * 希尔排序
 * @return
*/
#include <stdio.h>

/**
 * 希尔排序函数
 * @return
*/
void shell_sort(int arr[], int len) {
    int i, j, tmp, gap;
    // // 增量gap, 并逐步的缩小增量
    for (gap = len / 2; gap > 0; gap /= 2) {
        // 从第gap个元素，逐个对其所在的组进行直接插入排序
        for (i = gap; i < len; i++) {
            tmp = arr[i];
            for (j = i - gap; j >= 0 && tmp < arr[j]; j -= gap) {
                // 移动
                arr[j + gap] = arr[j];
            }
            //当退出while后，就给temp找到插入的位置
            arr[j + gap] = tmp;
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
    printf("希尔排序比较: \n");
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
    shell_sort(arr, len);
    result2 = printArray(arr, len);

    return 0;
}
