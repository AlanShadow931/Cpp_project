#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    string fileName,input,line;
    ifstream readfile;
    ofstream output;
    cout << "請輸入檔名:";
    cin >> fileName;
    output.open(fileName.c_str(),ios::app);
    if (output.fail()) {
        cout << "檔案發生錯誤" << endl;
        exit(1);
    }
    cout << "請輸入內容(欲退出程序請輸入exit):" << endl;
    while(1) {
        cin >> input;
        if(input == "exit")
            break;
        output << input << endl;
    }
    output.close();
    readfile.open(fileName.c_str(),ios::in);
    if (output.fail()) {
        cout << "檔案發生錯誤" << endl;
        exit(1);
    }
    cout << "寫入完成，檔案" << fileName << "的內容如下:" << endl;
    while (getline(readfile,line))
        cout << line << endl;
    readfile.close();
    return 0;
}
