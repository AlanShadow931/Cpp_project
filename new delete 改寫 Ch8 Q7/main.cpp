#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
    int* A=0; // 指向陣列A的指標
    int* B=0; // 指向陣列B的指標
    int* C=0; // 指向陣列C的指標
    int i, m;
    printf("請輸入陣列大小:"); // 提示使用者輸入陣列大小
    scanf("%d",&m); // 讀取陣列大小
    A=new int[m]; // 配置A陣列記憶體
    B=new int[m]; // 配置B陣列記憶體
    C=new int[m]; // 配置C陣列記憶體
    srand((unsigned) time(NULL)); // 設定亂數種子
    for(i=0;i<m;i++){
        *(A+i)=rand(); // A陣列每個元素給予亂數值
        *(B+i)=rand(); // B陣列每個元素給予亂數值
    }
    for(i=0;i<m;i++){
        *(C+i)=*(A+i)+*(B+i); // C陣列每個元素為A與B對應元素相加
    }
    printf("\n");
    for(i=0;i<m;i++){
        printf("C[%d]=%d\n",i,*(C+i)); // 輸出C陣列每個元素
    }
    delete [] A; // 釋放A陣列記憶體
    delete [] B; // 釋放B陣列記憶體
    delete [] C; // 釋放C陣列記憶體
    return 0;
}