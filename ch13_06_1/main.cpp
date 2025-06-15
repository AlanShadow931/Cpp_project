#include <stdio.h>
#include <string.h>

// 定義車輛類別 car
class car {
public:
    int wheel;           // 輪子數量
    int person;          // 可載人數
    char name[20];       // 車名
    car(char*,int,int,char*); // 建構函式
    ~car();                   // 解構函式
    void SetEngine(char* SetEngine); // 設定引擎型號
    void CheckEngine();             // 顯示引擎型號
private:
    char engine[20];     // 引擎型號
};

// 定義卡車類別 truck，繼承自 car
class truck: public car{
public:
    int length;          // 貨卡長度
    truck(char*,int,int,int,char*); // 建構函式
    ~truck();                          // 解構函式
};

// car 類別的建構函式，帶有預設參數
car::car(char* carname="自小客",int carwheel=4,int carperson=5,char* carengine="MT500-LR") {
    printf("car建構函式執行中...\n");
    strcpy(name,carname);
    wheel=carwheel;
    person=carperson;
    strcpy(engine,carengine);
}

// truck 類別的建構函式，初始化 car 並設定 length
truck::truck(char* truckname="卡車",int truckwheel=6,int truckperson=3,int trucklength=10,char* truckengine="MAX1000-ER")
: car(truckname,truckwheel,truckperson,truckengine),length(trucklength){
    printf("truck建構函式執行中...\n");
};

// car 類別的解構函式
car::~car() {
    printf("\ncar解構函式執行中...");
}

// truck 類別的解構函式
truck::~truck() {
    printf("\ntruck解構函式執行中...");
}

// 設定引擎型號
void car::SetEngine(char* SetEngine) {
    strcpy(engine,SetEngine);
}

// 顯示引擎型號
void car::CheckEngine(){
    printf("%s",engine);
}

int main()
{
    // 建立 car 物件
    car mycar;
    printf("%s有%d個輪子，可載%d個人，引擎型號是",mycar.name,mycar.wheel,mycar.person);
    mycar.CheckEngine();
    printf("\n---------------------------\n");

    // 建立 truck 物件
    truck mytruck;
    printf("%s有%d個輪子，可載%d個人，貨卡長度是%d公尺，引擎型號是",mytruck.name,mytruck.wheel,mytruck.person,mytruck.length);
    mytruck.CheckEngine();
    printf("\n---------------------------");
    return 0;
}