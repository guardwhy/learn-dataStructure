#include <stdio.h>
#include <string.h>

/**
 * BF算法实现
 * @return
 */

// 串普通模式匹配算法的实现函数,A是伪主串,B是伪子串
int index(char* A, char* B){
    // 定义变量
    int i=0, j=0;
    // 条件遍历
    while (i<strlen(A) && j<strlen(B)){
        // 判断条件
        if(A[i] == B[j]){
            i++;
            j++;
        } else{
            i = i-j+1;
            j=0;
        }
    }
    // 跳出循环:遍历完主串,匹配失败,j=strlen(B),说明字串遍历完成,在主串中匹配成功。
    if(j == strlen(B)){
        return i-strlen(B) + 1;
    }
    // 当i等于strlen(A)
    return 0;
}
int main() {
    // 定义字符串,调用函数
    int number = index("ababcabcacbab", "abcac");
    printf("%d", number);
    return 0;
}