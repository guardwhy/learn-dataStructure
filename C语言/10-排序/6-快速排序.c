/**
 * 快速排序
 * @return
*/
#include <stdio.h>

/**
 * 快速排序函数1
 * @return
*/
void Quick_Sort1(int *arr, int low, int high){
    // 定义变量
    int i = low;
    int j = high;
    // 定义Key值
    int key = arr[low];
    // 如果low >= high则说明排序结束了
    if(low >= high){
        return;
    }

    // 当while循环结束一次表示比较了一轮
    while (low < high){
        while (low < high && key <= arr[high]){
            --high ; // 向前寻找
        }
        if(key > arr[high]){
            // 不用交换,直接赋值
            arr[low] = arr[high];
            ++low;
        }

        // 向后寻找
        while (low < high && key >= arr[low]){
            ++low;
        }

        // 直接赋值,不用交换
        if(key < arr[low]){
            arr[high] = arr[low];
            --high;
        }
    }

    //查找完一轮后key值归位,不用比较一次就互换一次。此时key值将序列分成左右两部分.
    arr[low] = key;
    // 调用函数
    Quick_Sort1(arr, i, low-1);
    Quick_Sort1(arr, low+1, j);
}

/**
 * 交换函数
 * @param p
 * @param q
 */
void Swap(int *p, int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
    return;
}

/**
 * 快速排序函数2
 * @return
*/
void QuickSort2(int *a, int low, int high)
{
    int i = low;
    int j = high;
    int key = a[low];
    if (low >= high)  //如果low >= high说明排序结束了
    {
        return ;
    }
    while (low < high)  //该while循环结束一次表示比较了一轮
    {
        while (low < high && key <= a[high])
        {
            --high;  //向前寻找
        }
        if (key > a[high])
        {
            Swap(&a[low], &a[high]);
            ++low;
        }
        while (low < high && key >= a[low])
        {
            ++low;  //向后寻找
        }
        if (key < a[low])
        {
            Swap(&a[low], &a[high]);
            --high;
        }
    }
    QuickSort2(a, i, low-1);  //用同样的方式对分出来的左边的部分进行同上的做法
    QuickSort2(a, low+1, j);  //用同样的方式对分出来的右边的部分进行同上的做法
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
    printf("快速排序比较: \n");
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
    // Quick_Sort1(arr, 0, len-1);
    QuickSort2(arr, 0, len-1);
    result2 = printArray(arr, len);

    return 0;
}
