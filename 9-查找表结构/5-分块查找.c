/**
 * 分块查找
 * @return
*/
#include <stdio.h>
#include <stdlib.h>
/**
 * 定义块状结构
 * @return
*/
struct index{
    int key;
    int start;
}newIndex[3];

/**
 * 分块查找
 * @return
*/
int Block_search(int key, int a[]){
    // 定义变量
    int i=0;
    // 起始值
    int startValue;
    // 判断在那段块中
    while (i < 3 && key > newIndex[i].key){
        i++;
    }
    // 当大于数组时,返回失败
    if(i >= 3){
        return -1;
    }

    // 块范围的起始值
    startValue = newIndex[i].start;
    // 条件判断
    while (startValue <= startValue + 5 && a[startValue] != key){
        startValue++;
    }
    //如果大于块范围的结束值,则寻找失败
    if(startValue > startValue + 5){
        return -1;
    }
    return startValue;
}

/**
 * 比较
 * @return
*/
int CompareTo(const void* a, const void* b){
    // 三目运算比较
    return (*(struct index*)a).key > (*(struct index*)b).key ? 1:-1;
}

int main() {
    // 定义变量
    int i, result, key;
    int j = -1;
    // 定义数组
    int a[] = {36,42,44,39,24,48, 22,12,13,8,10,20,  60,58,74,49,86,56};
    // 判断起始值和最大值
    for(i=0; i<3; i++){
        // 每个块范围的起始值
        newIndex[i].start = j+1;
        j += 6;
        for(int result =newIndex[i].start; result<=j; result++){
            if(newIndex[i].key < a[result]){
                newIndex[i].key = a[result];
            }
        }
    }
    // 按照key值进行排序
    qsort(newIndex, 3, sizeof(newIndex[0]), CompareTo);
    // 调用函数
    printf("请输入要查找的元素:\n");
    scanf("%d", &key);
    result = Block_search(key, a);
    // 输出查找的结果
    if(result > 0){
        printf("查找成功,元素在数组中的位置: %d\n", result+1);
    } else{
        printf("查找失败....\n");
    }
    return 0;
}