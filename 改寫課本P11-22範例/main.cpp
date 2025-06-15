#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;

// 定義學生類別
class student {
public:
    char stu_id[12];         // 學號
    int scoreComputer;       // 電腦成績
    int scoreMath;           // 數學成績
    int scoreEng;            // 英文成績
    float scoreAvg;          // 平均成績

    // 計算三科平均分數
    float avg(int a, int b, int c) {
        return float(a+b+c)/3;
    }
};

int main() {
    // 以二進位方式開啟檔案
    ofstream output("student", ios::binary);
    if (output.fail()) {
        cerr << "檔案發生錯誤" << endl;
        return 1;
    }

    srand(time(NULL)); // 設定亂數種子

    student IM[10];    // 宣告10位學生的陣列
    int id;
    cout << "請輸入起始學號（數字部分）: ";
    cin >> id;

    // 產生10位學生資料
    for (int i = 0; i < 10; i++) {
        // 產生學號，格式為 S+7位數字
        snprintf(IM[i].stu_id, sizeof(IM[i].stu_id), "S%07d", id+i);
        // 隨機產生三科成績（50~90分）
        IM[i].scoreComputer = rand() % 41 + 50;
        IM[i].scoreMath = rand() % 41 + 50;
        IM[i].scoreEng = rand() % 41 + 50;
        // 計算平均分數
        IM[i].scoreAvg = IM[i].avg(IM[i].scoreComputer, IM[i].scoreMath, IM[i].scoreEng);
    }

    // 將學生資料寫入二進位檔案
    output.write((char*)IM, sizeof(IM));
    if (!output) {
        cerr << "寫入資料時發生錯誤" << endl; // cerr為標準錯誤輸出
        return 1;
    }
    output.close();

    cout << "二進位檔寫入完成" << endl;
    return 0;
}