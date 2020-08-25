#include <stdio.h>
#include <stdlib.h>

// 定义Size最大值,顺序表最大申请空间的大小
#define Capacity 5

// 定义结构体Table
typedef struct SqList{
    // 声明一个动态数组
    int * array;
    // 声明变量记录数组长度
    int length;
    // 声明变量分配存储容量
    int capacity;
}sqlist;

// 初始化操作
sqlist initSqList(){
    // 声明变量
    sqlist s;
    // 创建一个顺序表，动态的申请内存空间
    s.array = (int*)malloc(Capacity* sizeof(int));
    // 申请失败，退出程序
    if(!s.array){
        printf("申请失败");
        exit(0);
    }

    // 空表的长度为0
    s.length = 0;
    // 空表的容量为Capacity
    s.capacity = Capacity;
    return s;
}

// 插入元素,val为插入的元素,add为插入元素的位置
sqlist insert(sqlist s, int val, int add){
    // 1.插入元素位置比顺序表长度+1还大，或者插入位置本身不存在,则退出程序
    if(add > s.length+1 || add < 1){
        printf("插入位置有问题...");
        exit(0);
    }
    // 判断是否有多余的空间,如果没有则需要申请空间
    if(s.length >= s.capacity){
        // 再分配空间
        s.array = (int*)realloc(s.array, (s.capacity + 1) *sizeof(int));
        if(!s.array){
            printf("分配失败..");
            return s;
        }
        // 分配成功
        s.capacity += 1;
    }
    // 插入操作,直接将从插入位置开始的后续元素,逐个后移
    for(int i=s.length-1; i>=add-1; i--){
        s.array[i+1] = s.array[i];
    }
    // 后移完成以后直接插入元素,添加到相应的顺序表中
    s.array[add-1] = val;
    // 线性表长度
    s.length ++;
    return s;
}

// 删除元素
sqlist delSqList(sqlist s, int add){
    // 条件判断
    if(add>s.length || add<1){
        printf("被删除的元素位置有误");
        exit(0);
    }
    // 删除操作
    for(int i=add; i<s.length; i++){
        s.array[i-1] = s.array[i];
    }
    s.length--;
    return s;
}

// 查找元素,val表示要查找的元素
int selectSqList(sqlist s, int val){
    for(int i=0; i<s.length; i++){
        // 条件判断
        if(s.array[i]==val){
            return i + 1;
        }
    }

    return 0;
}

// 修改顺序表中的元素,val为要修改的
sqlist setSqList(sqlist s, int val, int newVal){
    // 选择目标元素
    int value = selectSqList(s, val);
    // 由于返回元素在顺序表的位置,所以-1就是该元素在数组的下标
    s.array[value -1] = newVal;
    return s;
}
// 声明函数
void showSqList(sqlist s){
    for(int i=0; i<s.length; i++){
        printf("%d ", s.array[i]);
    }

    printf("\n");
}

int main()
{
    // 初始化
    sqlist s1 = initSqList();
    // 向顺序表中添加元素
    for(int i=1; i<=Capacity; i++){
        s1.array[i-1] = i;
        s1.length++;
    }
    printf("顺序表中的元素:\n");
    // 调用函数
    showSqList(s1);

    printf("在下标为3的位置插入元素21:\n");
    s1 = insert(s1, 21, 4);
    // 调用函数
    showSqList(s1);

    printf("删除元素2\n");
    s1 = delSqList(s1, 2);
    showSqList(s1);

    printf("查找元素33的位置:\n");
    int add = selectSqList(s1, 33);
    printf("%d\n", add);

    printf("将元素5改为24:\n");
    s1 = setSqList(s1, 5, 24);
    showSqList(s1);
    return 0;
}
