/**
 * 折半插入排序算法
 * @return
*/
#include <stdio.h>

/**
 * 折半插入排序算法
 * @return
*/
void BInsertSort(int arr[], int len){
    // 定义变量
    int i, j, mid;
    // 定义最低下标为记录首位
    int low = 0;
    // 定义最高下标为记录末位
    int high = 0;
    // 定义临时变量
    int temp = 0;
    // 遍历操作
    for(i=1; i<len; i++){
        low = 0;
        high = i -1;
        temp = arr[i];
    //使用折半查找法判断插入位置,最终变量low表示插入位置
        while (low <= high){
            // 折半操作
            mid = (low + high) / 2;
            if(arr[mid] > temp){
                high = mid - 1;
            } else{
                low = mid + 1;
            }
        }
        //有序表中插入位置后的元素统一后移
        for(j=i; j>low; j--){
            arr[j] = arr[j-1];
        }
        // 插入元素
        arr[low] = temp;
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
    printf("折半插入排序: \n");
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
    BInsertSort(arr, len);
    result2 = printArray(arr, len);

    return 0;
}
