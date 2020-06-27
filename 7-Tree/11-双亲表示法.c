/**
 * 双亲表示法
 */
#include <stdio.h>
#include <stdlib.h>

// 定义一个最大值
#define MAX_SIZE 100
// 树结构的数据类型
typedef char TElemType;
/**
 * 结点结构
 * @return
 */
typedef struct PTNode{
    // 结点数据
    TElemType data;
    // 双亲位置
    int parent;
}PTNode;

/**
 * 树结构
 * @return
 */
typedef struct PTree{
    // 结点数组
    PTNode nodes[MAX_SIZE];
    // 结点个数
    int n;
}PTree;

// 初始化结点
PTree InitPTNode(PTree tree){
    // 定义变量
    int i, j;
    char ch;
    printf("请输入节点个数:\n");
    scanf("%d", &(tree.n));

    printf("请输入结点的值其双亲位于数组中的位置下标:\n");
    for(int i=0; i<tree.n; i++){
        getchar();
        scanf("%c %d", &ch, &j);
        tree.nodes[i].data = ch;
        tree.nodes[i].parent = j;
    }

    return tree;
}

/**
 * 查找父节点
 * @return
 */
void FindParent(PTree tree){
    // 定义字符串变量
    char a;
    int boolFind = 0;
    printf("请输入要查询的结点值:\n");
    getchar();
    scanf("%c", &a);
    for(int i=0; i<tree.n; i++){
        // 条件判断
        if(tree.nodes[i].data == a){
            boolFind = 1;
            int add = tree.nodes[i].parent;
            printf("%c的父节点为%c,存储位置下标为%d", a, tree.nodes[add].data, add);
            break;
        }
    }
    if(boolFind == 0){
        printf("树中无此节点");
    }
}
int main() {
    // 结构体变量
    PTree tree;
    // 遍历操作
    for(int i=0; i<MAX_SIZE; i++){
        tree.nodes[i].data = " ";
        tree.nodes[i].parent = 0;
    }
    // 调用函数
    tree = InitPTNode(tree);
    FindParent(tree);
    return 0;
}