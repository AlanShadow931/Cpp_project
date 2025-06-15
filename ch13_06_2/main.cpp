#include <stdio.h>
#include <string.h>

// 車輛類別
class car {
public:
    int wheel;              // 輪子數
    int person;             // 可載人數
    int fuel_capacity;      // 油箱容量
    char name[20];          // 車名

    // 建構函式，初始化車輛屬性
    car(char*,int,int,char*,int);
    // 解構子
    ~car();

    // 設定引擎型號
    void SetEngine(char* SetEngine);
    // 檢查引擎型號
    void CheckEngine();
    // 補充燃油
    void refill(int fuel);
    // 行駛指定距離
    void run(int distance);

private:
    char engine[20];        // 引擎型號
    int remaining_fuel;     // 剩餘油量
    int max_mileage;        // 最大可行駛里程
    int total_mileage;      // 累積行駛里程
};

// 卡車類別，繼承自car
class truck: public car{
public:
    int length;             // 卡車長度

    // 建構函式，初始化卡車屬性
    truck(char*,int,int,int,char*);
    // 解構函式
    ~truck();
};

// car類別建構子，帶預設參數
car::car(char* carname="自小客",int carwheel=4,int carperson=5,char* carengine="MT500-LR",int capacity=50) {
    printf("car建構函式執行中...\n");
    strcpy(name, carname);          // 設定車名
    wheel = carwheel;               // 設定輪子數
    person = carperson;             // 設定可載人數
    strcpy(engine, carengine);      // 設定引擎型號
    fuel_capacity = capacity;       // 設定油箱容量
    remaining_fuel = fuel_capacity; // 初始剩餘油量等於油箱容量
    max_mileage = fuel_capacity * 10; // 最大可行駛里程
    total_mileage = 0;              // 初始總里程為0
}

// truck類別建構函式，呼叫car建構子初始化基底屬性
truck::truck(char* truckname, int truckwheel, int truckperson, int trucklength, char* truckengine)
: car(truckname, truckwheel, truckperson, truckengine), length(trucklength) {
    printf("truck建構函式執行中...\n");
}

// car類別解構函式
car::~car() {
    printf("\ncar解構函式執行中...");
}

// truck類別解構函式
truck::~truck() {
    printf("\ntruck解構函式執行中...");
}

// 設定引擎型號
void car::SetEngine(char* SetEngine) {
    strcpy(engine, SetEngine);
}

// 輸出引擎型號
void car::CheckEngine() {
    printf("%s", engine);
}

// 行駛指定距離
void car::run(int distance) {
    if (distance <= max_mileage) {
        total_mileage += distance;           // 累加總里程
        max_mileage -= distance;             // 減少可行駛里程
        remaining_fuel -= distance / 10;     // 計算剩餘油量
        printf("\n行駛 %d 公里，剩餘油量: %d 公升，可行里程數: %d 公里，總里程數: %d 公里",
               distance, remaining_fuel, max_mileage, total_mileage);
    } else {
        printf("\n油量不足，無法行駛 %d 公里", distance);
    }
}

// 補充燃油
void car::refill(int fuel) {
    if (fuel + remaining_fuel > fuel_capacity) {
        remaining_fuel = fuel_capacity;      // 超過油箱容量則設為最大
    } else {
        remaining_fuel += fuel;              // 增加油量
    }
    max_mileage = remaining_fuel * 10;       // 更新可行駛里程
    printf("\n補充燃油 %d 公升，剩餘油量: %d 公升，可行里程數: %d 公里",
           fuel, remaining_fuel, max_mileage);
}

int main() {
    car mycar;   // 建立car物件
    printf("%s 有 %d 個輪子，可載 %d 個人，引擎型號是", mycar.name, mycar.wheel, mycar.person);
    mycar.CheckEngine();
    printf("，油箱容量為 %d 公升", mycar.fuel_capacity);
    mycar.run(50);      // 行駛50公里
    mycar.refill(100);  // 補充100公升燃油
    mycar.run(200);     // 行駛200公里
    printf("\n---------------------------");
    return 0;
}