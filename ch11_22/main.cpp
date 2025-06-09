#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;
class student {
public:
    char stu_id[12];
    int scoreComputer;
    int scoreMath;
    int scoreEng;
    float scoreAvg;
    float avg(int a, int b, int c) {
        return float(a+b+c)/3;
    }
};
int main() {
    ofstream output("student",ios::binary);
    if (output.fail()) {
        cerr << "檔案發生錯誤" << endl;
        return 1;
    }
    srand(time(NULL));
    student IM[10];
    int id;
    cout << "請輸入起始學號（數字部分）: ";
    cin >> id;
    for (int i = 0; i < 10; i++) {
        snprintf(IM[i].stu_id,sizeof(IM[i].stu_id),"S%07d",id+i);
        IM[i].scoreComputer=rand()%41+50;
        IM[i].scoreMath=rand()%41+50;
        IM[i].scoreEng=rand()%41+50;
        IM[i].scoreAvg=IM[i].avg(IM[i].scoreComputer,IM[i].scoreMath,IM[i].scoreEng);
    }
    output.write((char*)IM,sizeof(IM));
    if (!output) {
        cerr << "寫入資料時發生錯誤" << endl;
        return 1;
    }
    output.close();
    cout << "二進位檔寫入完成" << endl;
    return 0;
}