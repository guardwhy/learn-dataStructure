/**
 * 哈夫曼树编码实现
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INFINITY INT_MAX
#define MAXLEN 20

/**
 * 哈夫曼树结点结构
 * @return
 */
typedef struct {
    // 结点权重
    unsigned int weight;
    // 父结点,左孩子,右孩子在数组中的位置下标
    unsigned int parent, lchild, rchild;
}HTNode, *HuffmanTree;

/**
 * 动态二维数组
 * @return
 */
typedef char** HuffmanCode;

/**
* SELECT函数
* @return
*/
void Select(HuffmanTree* HT, int x, int* s1, int* s2){
    // 定义变量
    int i=1, min1 = INFINITY, min2 = INFINITY;
    // 遍历循环
    for(; i<=x; i++)
        if((*HT)[i].weight < min1 && (*HT)[i].parent == 0){
            min1 = (*HT)[i].weight;
            *s1 = i;
        }
    for(i=1; i<=x;i++){
        if((*HT)[i].weight < min2 && (*HT)[i].parent == 0 && i != *s1){
            min2 = (*HT)[i].weight;
            *s2 = i;
        }
    }
}
/**
 * 创建HT函数
 * @return
 */
//HT为哈夫曼树，HC为存储结点哈夫曼编码的二维动态数组，n为结点的个数, w为数组
 void HuffmanCoding(HuffmanTree* HT, HuffmanCode* HC, int* w, int n){
    // 定义变量
    int m, i;
    HuffmanTree p;
    //存放结点哈夫曼编码的数组
    char* cd;
    // 条件判断
    if(n <= 1)
        return;
    m = 2 * n - 1;
    // 动态内存分配,静态链表初始化
    *HT = (HuffmanTree)malloc((m+1)*sizeof(HTNode));
    // 赋值操作
    for(p=*HT + 1, i=1; i<=n; ++i,++p, ++w){
        p->weight = *w;
        p->parent = 0;
        p->lchild = 0;
        p->rchild = 0;
    }

    for(; i<=m; ++i, ++p){
        p->weight = 0;
        p->parent = 0;
        p->lchild = 0;
        p->rchild = 0;
    }

    // 创建哈夫曼树
    for (int i = n+1; i <=m; ++i) {
        // 定义两个变量
        int s1, s2;
        // 调用函数
        Select(HT, i-1, &s1, &s2);
        (*HT)[s1].parent = i;
        (*HT)[s2].parent = i;
        (*HT)[i].lchild = s1;
        (*HT)[i].rchild = s2;
        (*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
    }

    /**
     * 逆向哈夫曼编码
     */
    (*HC) = (HuffmanCode)malloc((n+1)*sizeof(char*));
    // 创建数组
    cd = (char*)malloc(n * sizeof(char));
    // 逆序
    cd[n -1] = '\0';
    for(i=1; i<=n; ++i){
        // 定义初始变量
        int start = n - 1;
        // 当前结点
        int c;
        // 双亲
        int f;
        for(c=i, f=(*HT)[i].parent; f != 0; c = f, f=(*HT)[f].parent)
            if((*HT)[f].lchild == c)
                cd[--start] = '0';
            else
                cd[--start] = '1';
        (*HC)[i] = (char*)malloc((n-start) * sizeof(char));
        // 复制
        strcpy((*HC)[i], &cd[start]);
        printf("%s\n", (*HC)[i]);
    }

    // 释放空间
    free(cd);
 }

int main() {
    // 结构体变量
    HuffmanTree ht;
    HuffmanCode hc;
    // 定义变量和数组
    int n, i, w[MAXLEN];
    char ch[MAXLEN];
    printf("请输入要编码的字符个数: \n");
    scanf("%d", &n);

    for(i=0; i < n; i++){
        printf("输入字符和相应的权值: \n");
        fflush(stdin);
        scanf("%c %d", &ch[i], &w[i]);
    }

    printf("字符");
    for(i=0; i< n; i++)
        printf("%c", ch[i]);
        printf("对应的哈夫曼编码分别是: \n");
        HuffmanCoding(&ht, &hc, w, n);
    
    return 0;
}