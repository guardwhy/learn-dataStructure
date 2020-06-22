#include <stdio.h>
#include <string.h>

/**
 * kmp算法实现
 * @return
 */
//调用了普通求next的方式,通过函数第一次运行,也可以得出它的值为1
void Next(char* T, int* next){
    // 定义变量
    next[1] = 0;
    int i = 1;
    int j = 0;
    // 条件判断
    while (i<strlen(T)){
        if(j==0||T[i-1]==T[j-1]){
            j++;
            i++;
            if(T[i-1]!=T[j-1]){
                next[i] = j;
            } else{
                next[i] = next[j];
            }
        } else{
            j = next[j];
        }
    }
}

// 声明KMP函数
int KMP(char* S, char* T){
    // 定义数组
    int next[15];
    // 初始化next数组
    Next(T, next);
    // 定义变量
    int i =1;
    int j = 1;

    // 条件判断
    while (i<= strlen(S) && j<=strlen(T)){
        /**
         j等于0:代表模式串的第一个字符就和当前测试的字符不相等。
         S[i-1]==T[j-1],如果对应位置字符相等，两种情况下,指向当前测试的两个指针下标i和j都向后移。
         */
         if(j==0 || S[i-1] == T[j-1]){
             i++;
             j++;
         }else{
             // 测试的两个字符不相等,i不动,j变为当前测试字符串的next值.
             j = next[j];
         }
    }
    if(j>strlen(T)){
        // 如果条件为true,则匹配成功.
        return i-(int)strlen(T);
    }
    return -1;
}
int main() {
    // 调用函数
    int i = KMP("ababcabcacbab","abcac");
    printf("%d", i);
    return 0;
}