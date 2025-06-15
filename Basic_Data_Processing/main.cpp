#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string fileName, input, line;
    ifstream readfile; // 用於讀取檔案
    ofstream output;   // 用於寫入檔案

    cout << "請輸入檔名:";
    cin >> fileName; // 取得使用者輸入的檔名

    // 以附加模式開啟檔案，若檔案不存在則建立新檔
    output.open(fileName.c_str(), ios::app);
    if (output.fail()) { // 檢查檔案是否成功開啟
        cout << "檔案發生錯誤" << endl;
        exit(1);
    }

    cout << "請輸入內容(欲退出程序請輸入exit):" << endl;
    // 持續讀取使用者輸入，直到輸入"exit"為止
    while (1) {
        cin >> input;
        if (input == "exit")
            break; // 若輸入exit則跳出迴圈
        output << input << endl; // 將輸入內容寫入檔案
    }
    output.close(); // 關閉寫入檔案

    // 以讀取模式開啟檔案
    readfile.open(fileName.c_str(), ios::in);
    if (readfile.fail()) { // 檢查檔案是否成功開啟
        cout << "檔案發生錯誤" << endl;
        exit(1);
    }

    cout << "寫入完成，檔案" << fileName << "的內容如下:" << endl;
    // 逐行讀取檔案內容並輸出到螢幕
    while (getline(readfile, line))
        cout << line << endl;
    readfile.close(); // 關閉讀取檔案

    return 0;
}