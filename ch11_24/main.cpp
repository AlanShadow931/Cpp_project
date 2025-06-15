#include <iostream>
#include <fstream>
using namespace std;

// 定義學生類別
class student {
public:
    char stu_id[12];         // 學號
    int scoreComputer;       // 計算機概論成績
    int scoreMath;           // 數學成績
    int scoreEng;            // 英文成績
    float scoreAvg;          // 平均分數

    // 顯示學生資料
    void display() {
        cout << stu_id << "\t" << scoreComputer << "\t" << scoreMath << "\t" << scoreEng << "\t" << scoreAvg << endl;
    }
};

int main() {
    // 以二進位方式開啟檔案 student
    ifstream read("student", ios::binary);

    // 移到檔案結尾，取得檔案大小
    read.seekg(0, ios::end);
    long filesize = read.tellg();

    // 回到檔案開頭
    read.seekg(0, ios::beg);

    // 計算學生資料筆數
    int n = filesize / sizeof(student);

    // 檢查檔案是否為空或格式錯誤
    if (n == 0) {
        cerr << "檔案為空或格式錯誤" << endl;
        return 1;
    }

    // 配置記憶體以儲存所有學生資料
    student* IM = new student[n];

    // 讀取所有學生資料到記憶體
    read.read((char*)IM, sizeof(student) * n);

    // 檢查讀取是否成功
    if (!read) {
        cerr << "讀取資料失敗" << endl;
        delete[] IM;
        return 1;
    }

    // 輸出標題
    cout << "\n學號\t\t計概\t數學\t英文\t平均分數\n";

    // 顯示每位學生的資料
    for (int i = 0; i < n; i++) {
        IM[i].display();
    }

    // 釋放記憶體
    delete[] IM;

    // 關閉檔案
    read.close();

    return 0;
}