#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
    int i;
    // 定義一個長度為7的字元指標陣列，分別指向每週的英文名稱
    char* Week[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    // 迴圈輸出每一天的名稱
    for(i = 0; i < 7; i++)
        cout << "Week[" << i << "]=" << Week[i] << endl;
    return 0;
}