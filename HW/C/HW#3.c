#include <stdio.h>

int main() {
    int numRows, i, j, k;

    // 用户输入钻石的行数
    printf("请输入钻石图案的行数（奇数）：");
    scanf("%d", &numRows);

    // 打印钻石的上半部分
    for(i = 1; i <= numRows; i++) {
        // 打印空格
        for(j = numRows; j > i; j--) {
            printf(" ");
        }
        // 打印星号
        for(k = 1; k <= 2 * i - 1; k++) {
            printf("*");
        }
        printf("\n");
    }

    // 打印钻石的下半部分
    for(i = numRows - 1; i >= 1; i--) {
        // 打印空格
        for(j = numRows; j > i; j--) {
            printf(" ");
        }
        // 打印星号
        for(k = 1; k <= 2 * i - 1; k++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}