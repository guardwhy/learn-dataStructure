#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * 堆分配存储
 * @return
 */
int main() {
    // 定义两个指针变量
    char* p = NULL;
    char* q = NULL;
    // 动态分配内存空间
    p = (char*)malloc(10 * sizeof(char));
    strcpy(p, "guardwhy");
    q = (char*)malloc(10 *sizeof(char));
    strcpy(q,"hello.world");

    // 字符串p的长度
    int length1 = strlen(p);
    // 字符串q的长度
    int length2 = strlen(q);
    // 将合并的字符串存储在p中,如果p的长度不够,可以使用realloc动态申请内存
    if(length1 < length1 + length2){
        p = (char*)realloc(p, (length1 + length2+1) * sizeof(char));
    }
    // 条件遍历
    for(int i=length1; i<length1+length2; i++){
        p[i] = q[i-length1];
    }
    p[length1+length2] = '\0';
    // 输出操作
    printf("%s", p);
    // 用完动态数组要立即释放
    free(p);
    free(q);
    return 0;
}