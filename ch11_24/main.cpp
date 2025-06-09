#include <iostream>
#include <fstream>
using namespace std;
class student {
public:
    char stu_id[12];
    int scoreComputer;
    int scoreMath;
    int scoreEng;
    float scoreAvg;
    void display() {
        cout << stu_id << "\t" << scoreComputer << "\t" << scoreMath << "\t" << scoreEng << "\t" << scoreAvg << endl;
    }
};
int main() {
    ifstream read("student",ios::binary);
    if (!read) {
        cerr << "無法開啟檔案，請確認檔案是否存在" << endl;
        return 1;
    }
    read.seekg(0,ios::end);
    long filesize=read.tellg();
    read.seekg(0,ios::beg);
    int n = filesize / sizeof(student);
    if (n == 0) {
        cerr << "檔案為空或格式錯誤" << endl;
        return 1;
    }
    student* IM = new student[n];
    read.read((char*)IM,sizeof(student) * n);
    if (!read) {
        cerr << "讀取資料失敗" << endl;
        delete[] IM;
        return 1;
    }
    cout << "\n學號\t\t計概\t數學\t英文\t平均分數\n";
    for (int i=0;i<n;i++) {
        IM[i].display();
    }
    delete[] IM;
    read.close();
    return 0;
}
