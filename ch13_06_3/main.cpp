#include <iostream>
#include <string>
using namespace std;

// 車輛類別
class car {
public:
    int wheel;              // 輪子數量
    int person;             // 可載人數
    int fuel_capacity;      // 油箱容量
    string name;            // 車名

    // 建構子，帶有預設參數
    car(string, int, int, string, int);
    ~car();                 // 解構子

    void SetEngine(string SetEngine); // 設定引擎型號
    void CheckEngine();               // 顯示引擎型號
    void refill(int fuel);            // 補充燃油
    void run(int distance);           // 行駛指定距離

private:
    string engine;          // 引擎型號
    int remaining_fuel;     // 剩餘油量
    int max_mileage;        // 可行駛最大里程
    int total_mileage;      // 累積行駛里程
};

// 卡車類別，繼承自car
class truck: public car {
public:
    int length;             // 卡車長度

    // 建構函式
    truck(string, int, int, int, string);
    ~truck();               // 解構函式
};

// car類別建構函式，初始化成員
car::car(string carname="自小客",int carwheel=4,int carperson=5,string carengine="MT500-LR",int capacity=50) {
    cout << "car建構函式執行中..." << endl << "---------------------------" << endl;
    name = carname;
    wheel = carwheel;
    person = carperson;
    engine = carengine;
    fuel_capacity = capacity;
    remaining_fuel = fuel_capacity;
    max_mileage = fuel_capacity * 10;
    total_mileage = 0;
}

// truck類別建構函式，呼叫car建構函式並初始化length
truck::truck(string truckname, int truckwheel, int truckperson, int trucklength, string truckengine)
    : car(truckname, truckwheel, truckperson, truckengine), length(trucklength) {
    cout << "truck建構函式執行中..." << endl;
}

// car類別解構函式
car::~car() {
    cout << "car解構函式執行中..." << endl;
}

// truck類別解構函式
truck::~truck() {
    cout << "truck解構函式執行中..." << endl;
}

// 設定引擎型號
void car::SetEngine(string SetEngine) {
    engine = SetEngine;
}

// 顯示引擎型號
void car::CheckEngine() {
    cout << engine;
}

// 行駛指定距離，並更新油量與里程
void car::run(int distance) {
    if (distance <= max_mileage) {
        total_mileage += distance;
        max_mileage -= distance;
        remaining_fuel -= distance / 10;
        cout << "\n行駛 " << distance << " 公里，剩餘油量: " << remaining_fuel << " 公升，可行里程數: " << max_mileage << " 公里，總里程數: " << total_mileage << " 公里";
    }
    else
        cout << "\n油量不足，無法行駛 " << distance << " 公里";
}

// 補充燃油，並更新可行駛里程
void car::refill(int fuel) {
    if (fuel + remaining_fuel > fuel_capacity) {
        remaining_fuel = fuel_capacity;
    }
    else
        remaining_fuel += fuel;
    max_mileage = remaining_fuel * 10;
    cout << "\n補充燃油 " << fuel << " 公升，剩餘油量: " << remaining_fuel << " 公升，可行里程數: " << max_mileage << " 公里";
}

int main() {
    car* mycar = new car(); // 建立car物件
    cout << mycar->name << " 有 " << mycar->wheel << " 個輪子，可載 " << mycar->person << " 個人，引擎型號是 ";
    mycar->CheckEngine();
    cout << "，油箱容量為 " << mycar->fuel_capacity << " 公升";
    mycar->run(50);         // 行駛50公里
    mycar->refill(100);     // 補充100公升燃油
    mycar->run(200);        // 行駛200公里
    cout << "\n---------------------------" << endl;
    delete mycar;           // 釋放物件
    return 0;
}