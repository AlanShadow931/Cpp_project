#include <iostream>
#include <stdlib.h>
#include <time.h>

int main() {
    // 宣告三個指標用於動態分配陣列
    int* A=0;
    int* B=0;
    int* C=0;
    int i, j, m, n;

    // 輸入陣列的列數與行數
    printf("請輸入陣列大小\n");
    printf("請輸入列數:");
    scanf("%d", &m);
    printf("請輸入行數:");
    scanf("%d", &n);

    // 動態分配三個 m*n 大小的陣列
    A = new int[m * n];
    B = new int[m * n];
    C = new int[m * n];

    // 初始化亂數種子
    srand((unsigned)time(NULL));

    // 隨機產生 A、B 兩個陣列的元素（1~49）
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            A[i * n + j] = rand() % 49 + 1;
            B[i * n + j] = rand() % 49 + 1;
        }
    }

    // 輸出 A 陣列
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("A[%d,%d]=%d\t", i + 1, j + 1, A[i * n + j]);
        }
        printf("\n");
    }
    printf("\n");

    // 輸出 B 陣列
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("B[%d,%d]=%d\t", i + 1, j + 1, B[i * n + j]);
        }
        printf("\n");
    }
    printf("\n");

    // 計算 C 陣列（A+B）
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            C[i * n + j] = A[i * n + j] + B[i * n + j];
        }
    }

    // 輸出 C 陣列
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("C[%d,%d]=%2d\t", i + 1, j + 1, C[i * n + j]);
        }
        printf("\n");
    }

    // 釋放動態分配的記憶體
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}