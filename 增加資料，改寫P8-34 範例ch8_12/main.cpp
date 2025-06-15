#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int main(){
    int i;
    // 定義一週七天的名稱
    string str1[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    // 定義七種顏色
    string str2[7] = {"White", "Red", "Green", "Yellow", "Pink", "Purple", "Orange"};
    // 用於存放顏色+星期的組合
    string str3[7] = {};

    // 迴圈遍歷每一天
    for(i = 0; i < 7; i++) {
        // 將顏色和星期組合起來，存入str3
        str3[i] = str2[i] + " " + str1[i];
        // 輸出組合結果
        cout << str3[i] << endl;
    }

    return 0;
}