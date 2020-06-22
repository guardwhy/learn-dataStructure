/**
 * 广义表的长度
 */
#include <stdio.h>
#include <stdlib.h>

// 结构体类型
typedef struct GLNode{
    // 标志域
    int tag;
    union {
        // 原子结点的值域
        char atom;
        struct {
            // 子表结点的指针域,hp指向表头,tp指向表尾
            struct GLNode* hp, *tp;
        }ptr;
    };
}*Glist;

/**
 * 创建广义表
 * @return
 */
Glist createGlist(Glist A){
    // 创建广义表,动态分配内存
    A = (Glist)malloc(sizeof(Glist));
    // 标记位
    A->tag = 1;
    // 表头原子
    A->ptr.hp = (Glist)malloc(sizeof(Glist));
    A->ptr.hp->tag = 0;
    A->ptr.hp->atom = 'a';

    // 表尾子表(b,c,d)
    A->ptr.tp = (Glist)malloc(sizeof(Glist));
    A->ptr.tp->tag = 1;
    A->ptr.tp->ptr.hp = (Glist)malloc(sizeof(Glist));
    A->ptr.tp->ptr.tp = NULL;

    // 存放下一个数据元素(b,c,d),表头为b,表尾是(c,d)
    A->ptr.tp->ptr.hp->tag = 1;
    A->ptr.tp->ptr.hp->ptr.hp = (Glist)malloc(sizeof(Glist));
    A->ptr.tp->ptr.hp->ptr.hp->tag = 0;
    A->ptr.tp->ptr.hp->ptr.hp->atom = 'b';
    A->ptr.tp->ptr.hp->ptr.tp = (Glist)malloc(sizeof(Glist));

    // 存放下一个数据元素(c,d),表头为c,表尾为d
    A->ptr.tp->ptr.hp->ptr.tp->tag = 1;
    A->ptr.tp->ptr.hp->ptr.tp->ptr.hp = (Glist)malloc(sizeof(Glist));
    A->ptr.tp->ptr.hp->ptr.tp->ptr.hp->tag = 0;
    A->ptr.tp->ptr.hp->ptr.tp->ptr.hp->atom = 'c';
    A->ptr.tp->ptr.hp->ptr.tp->ptr.tp = (Glist)malloc(sizeof(Glist));
    //存放表尾d
    A->ptr.tp->ptr.hp->ptr.tp->ptr.tp->tag = 1;
    A->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.hp = (Glist)malloc(sizeof(Glist));
    A->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.hp->tag = 0;
    A->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.hp->atom = 'd';
    A->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.tp = NULL;
    return A;
}

/**
 * 广义表长度
 * @return
 */
 int GlistLength(Glist A){
     // 定义变量
     int num = 0;
     Glist temp = A;
     // 条件判断
     while (temp){
         num++;
         temp = temp->ptr.tp;
     }

    return num;
 }
int main() {
    // 创建结构体变量
    Glist A = NULL;
    A = createGlist(A);
    // 输出结果
    printf("广义表的长度为: %d", GlistLength(A));
    return 0;
}