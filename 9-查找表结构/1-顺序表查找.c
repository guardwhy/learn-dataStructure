/**
 * 顺序查找的实现
 * @return
*/
#include <stdio.h>
#include <stdlib.h>

/**
 *宏定义
 */
#define keyType int

/**
 * 数据元素值
*/
typedef struct {
    keyType key; //查找表中每个数据元素的值
}ElemType;

/**
 * 表结构类型
 * @return
*/
typedef struct {
    ElemType* elem; // 表中的数据元素的数组
    int length; // 表中的数据的总数量
}SSTable;

/**
 * 创建查找表
 * @return
*/
void Create_list(SSTable** st, int length){
    // 内存分配
    (*st) = (SSTable*)malloc(sizeof(SSTable));
    // 表的长度
    (*st)->length = length;
    (*st)->elem = (ElemType*)malloc((length+1)* sizeof(ElemType));
    printf("输入数据表中的元素: \n");
    // 数组下标为1的空间开始存储数据
    for(int i=1; i<=length; i++){
        // 输入元素
        scanf("%d", &((*st)->elem[i].key));
    }
}

/**
 * 有哨兵顺序查找
 * @return
*/
int Sequential_Search(SSTable *st, keyType key){
    //将一个数据元素存放到查找表的第一个位置，起监视哨的作用
    st->elem[0].key = key;
    int i = st->length;
    // 遍历数据元素,遍历数组下标为0
    while (st->elem[i].key != key){
        i--;
    }
    // 当i=0时,查找失败.反之返回含有关键字key的数据元素在数据表中的位置
    return i;
}

int main()
{
    // 定义结构体变量
    SSTable *st;
    // 创建函数
    Create_list(&st, 5);
    getchar();
    printf("请输入查找数据的关键字: \n");
    // 定义变量
    int key;
    scanf("%d", &key);

    //调用查找函数
    int location = Sequential_Search(st, key);
    // 条件判断
    if(location == 0){
        printf("元素不存在....");
    }else{
        printf("元素在数据表中的位置是: %d", location);
    }
    return 0;
}