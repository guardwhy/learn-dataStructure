#include <iostream>
/**
 * c++中定义struct结构类型时候，使用时不在需要struct关键字
 */
using namespace std;

struct LNode{
    // 数据域
    char data;
    // 指针域
    LNode *next;
};

int main()
{
    // 创建node类型,堆栈区
    LNode node;
    node.data = 'X';
    // 堆存储区
    LNode *p = new LNode;
    // 属性
    p->data = 'A';
    p->next = 0;
    // 输出结果
    
    printf("%c %c\n", p->data, node.data);
    return 0;
}