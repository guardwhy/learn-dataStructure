/**
 * 散列表
 * @return
*/
#include <stdio.h>
#include <stdlib.h>

/**
 * 宏定义
 * @return
*/
typedef int Status;	// Status是函数的类型。
#define MAXSIZE 100 // 存储空间初始分配量
#define HASHSIZE 12 // 定义散列表长为数组的长度
#define NULLKEY -32768

typedef enum{false, true} bool;

// 散列表表长
int length = 0;

/**
 * 哈希表结构
 * @return
*/
typedef struct {
    int *elem; // 数据元素存储基址,动态分配数组
    int count; // 当前数据元素个数
}HashTable;

/**
 * 初始化散列表
 * @return
*/
Status InitHashTable(HashTable* H){
    // 定义变量
    int i;
    length = HASHSIZE;
    H->count = length;
    // 内存分配
    H->elem = (int *)malloc(length* sizeof(int));
    // 遍历操作
    for(i=0; i<length; i++)
        H->elem[i] = NULLKEY;
    return true;
}

/**
 * 散列函数
 * @return
*/
int Hash(int key){
    // 除留余数法
    return key % length;
}

/**
 * 插入关键字进散列表
 * @return
*/
void InsertHash(HashTable *H, int key){
    // 散列地址
    int addr = Hash(key);
    // 如果不为空,则发生冲突
    while (H->elem[addr] != NULLKEY){
        // 开放定址法的线性探测
        addr = (addr+1) % length;
    }
    // 直到有空位插入关键字
    H->elem[addr] = key;
}

/**
 * 散列表查找关键字
 * @return
*/
Status SearchHash(HashTable H, int key, int *addr){
    // 求散列地址
    *addr = Hash(key);
    // 如果不为空,则冲突
    while (H.elem[*addr] != key){
        // 开放定址法的线性探测
        *addr = (*addr+1) % length;
        // 如果循环回到原点
        if(H.elem[*addr] == NULLKEY || *addr == Hash(key))
            // 则说明关键字不存在
            return false;
    }
    return true;
}

int main()
{
    // 定义数组
    int arr[HASHSIZE] = {12,67,56,16,25,37,22,29,15,47,48,34};
    // 定义变量
    int i, p;
    // 结构体变量
    HashTable H;

    int key = 39;
    // 初始化函数
    InitHashTable(&H);
    // 遍历操作
    for(i=0; i<length; i++){
        // 插入元素
        InsertHash(&H, arr[i]);
    }

    // 查找值
    int result = SearchHash(H, key, &p);
    if(result){
        printf("查找 %d 的地址为：%d \n",key,p);
    } else{
        printf("查找 %d 失败....\n",key);
    }

    for(i=0; i<length; i++){
        key = arr[i];
        // 调用函数
        SearchHash(H, key, &p);
        printf("查找 %d 的地址为：%d \n",key,p);
    }
    return 0;
}