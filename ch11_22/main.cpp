#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
class student {
    private:
    string stu_id;
    int scoreComputer;
    int scoreMath;
    int scoreEng;
    float scoreAvg;
	public:
	float avg(int a,int b,int c);
};
float student::avg(int a, int b, int c) {
    return float(a+b+c)/3;
}
int main() {
    ofstream output;
    srand(time(NULL));
    student IM[10];
    int i,id;
    cout << "請輸入起始學號(數字部分):";
    cin >> id;
    for(i=0;i<10;i++) {
        IM[i].stu_id = "S" + to_string(id+i);
        IM[i].scoreComputer = rand()%41+50;
        IM[i].scoreMath = rand()%41+50;
        IM[i].scoreEng = rand()%41+50;
        IM[i].scoreAvg = IM[i].avg(IM[i].scoreComputer,IM[i].scoreMath,IM[i].scoreEng);
    }
    output.open("student");
    if (output.fail()) {
        cout << "檔案發生錯誤" << endl;
        exit(1);
    }
    output.write((char*)&IM[i],sizeof(IM[i])*10);
    cout << "二進位檔寫入完成" << endl;
    output.close();
    return 0;
}