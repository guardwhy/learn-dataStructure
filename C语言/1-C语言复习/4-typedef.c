#include <stdio.h>

/*
    typedef是关键字,用于给一个数据类型起一个别名
*/
void typedef_test(){
    printf("typedef_test:\n");
    typedef char CHAR;
    // 定义变量
    CHAR ch = 'a';
    // 输出结果
    printf("%c %d\n", ch, ch);  // typedef_test:

}

int main()
{
    // 调用函数
    typedef_test();
    return 0;
}
