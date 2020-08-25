#include <stdio.h>
#include <string.h>

// struct定义结构类型，即将多个相关变量组合在一起，表示某个概念
typedef struct
{
    // 姓名
    char name[10];
    // 年龄
    int age;
}Student;

int main()
{
    // 创建stu类型
    Student stu;
    // 添加属性
    strcpy(stu.name, "curry");
    stu.age = 21;
    printf("%s %d\n", stu.name, stu.age);

    Student *p = &stu;
    printf("%s %d\n", p->name, p->age);
    // 拷贝复制
    strcpy(p->name, "kobe");
    p->age = 38;
    // 输出结果
    printf("%s %d\n", p->name, p->age);
    return 0;
}
