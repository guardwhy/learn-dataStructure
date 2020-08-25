/**
 * 堆排序
 * @return
*/
#include <stdio.h>

/**
 * 交换函数
 * @return
*/
void swap(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

/**
 * 调整使其满足堆的性质
 * @return
*/
void heapify(int arr[], int start, int end){
    // 建立父节点指标
    int dad = start;
    // 建立子节点指标
    int son = dad * 2 + 1;
    // 子节点指标在范围内才比较
    while (son <= end){
        // 比较两个子节点的大小,选择最大的
        if(son + 1 <= end && arr[son] < arr[son + 1])
            son++;
        // 如果父节点大于子节点代表调整完毕,直接跳出函数
        if(arr[dad] > arr[son])
            return;
        else{
            // 否则交换父子内容再继续子节点和孙结点比较
            swap(&arr[dad], &arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

/**
 * 堆排序函数
 * @return
*/
void heap_sort(int arr[], int len){
    // 定义i变量
    int i;
    // 初始化,i从最后一个父节点开始调整
    for(i=len/2-1; i>=0; i--){
        // 调用函数
        heapify(arr, i, len-1);
    }
    // 先将第一个元素和已经排好的元素前一位做交换,再重新调整,直到排序完毕
    for(i = len -1; i > 0; i--){
        swap(&arr[0], &arr[i]);
        heapify(arr, 0, i-1);
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
    printf("堆排序比较: \n");
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
    heap_sort(arr, len);
    result2 = printArray(arr, len);

    return 0;
}
