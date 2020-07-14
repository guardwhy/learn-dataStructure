/**
 * 2-路插入排序
 * @return
*/
#include <stdio.h>

/**
 * 2-插入排序函数
 * @return
*/
void TwoInsert_Sort(int arr[], int len, int temp[]){
    // 定义变量
    int i,  k;
    // 分别记录temp数组中最大值和最小值的位置
    int first = 0;
    int final = 0;
    temp[0] = arr[0];

    // 遍历操作
    for(i=1; i < len; i++){
        // 插入元素比最小元素小
        if(arr[i] < temp[first]){
            first = (first-1 + len) % len;
            temp[first] = arr[i];
            // 插入元素比最大元素大
        } else if(arr[i] > temp[final]){
            final = (final + 1 + len) % len;
            temp[final] = arr[i];
            // 插入元素比最小大,比最大小
        } else{
            k = (final+1 + len) % len;
            //当插入值比当前值小时,需要移动当前值的位置
            while (temp[((k-1) + len) % len] > arr[i]){
                temp[(k + len) % len] =temp[(k - 1 + len) % len];
                k = (k - 1 + len) % len;
            }
            //插入该值
            temp[(k + len) % len] = arr[i];
            //因为最大值的位置改变，所以需要实时更新final的位置
            final = (final + 1 + len) % len;
        }
    }
    // 将排序记录复制到原来的顺序表里
    for(k=0; k < len; k++){
        arr[k] = temp[(first + k) % len];
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
    printf("2-路插入排序: \n");
    // 定义数组
    int arr[] = {22,34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};

    // 数组长度
    int len = (int)sizeof(arr) / sizeof(*arr);

    // 定义数组temp
    int temp[len];

    // 定义变量
    int result1, result2;

    printf("排序前: ", result1);
    // 调用打印函数
    result1 = printArray(arr, len);

    printf("排序后: ", result2);
    // 调用排序函数
    TwoInsert_Sort(arr, len, temp);
    result2 = printArray(arr, len);

    return 0;
}
