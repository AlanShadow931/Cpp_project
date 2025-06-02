#include <stdio.h>
#include <string.h>
class car {
public:
    int wheel;
    int person;
    int fuel_capacity;
    char name[20];
    car(char*,int,int,char*,int);
    ~car();
    void SetEngine(char* SetEngine);
    void CheckEngine();
    void refill(int fuel);
    void run(int distance);
private:
    char engine[20];
    int remaining_fuel;
    int max_mileage;
    int total_mileage;
};
class truck: public car{
    public:
    int length;
    truck(char*,int,int,int,char*);
    ~truck();
};
car::car(char* carname="自小客",int carwheel=4,int carperson=5,char* carengine="MT500-LR",int capacity=50) {
    printf("car建構函式執行中...\n");
    strcpy(name,carname);
    wheel=carwheel;
    person=carperson;
    strcpy(engine,carengine);
    fuel_capacity=capacity;
    remaining_fuel=fuel_capacity;
    max_mileage=fuel_capacity*10;
    total_mileage=0;
}
truck::truck(char* truckname="卡車",int truckwheel=6,int truckperson=3,int trucklength=10,char* truckengine="MAX1000-ER")
: car(truckname,truckwheel,truckperson,truckengine),length(trucklength){
    printf("truck建構函式執行中...\n");
};
car::~car() {
    printf("\ncar解構函式執行中...");
}
truck::~truck() {
    printf("\ntruck解構函式執行中...");
}
void car::SetEngine(char* SetEngine) {
    strcpy(engine,SetEngine);
}
void car::CheckEngine(){
    printf("%s",engine);
}
void car::run(int distance) {
    if (distance<=max_mileage) {
        total_mileage+=distance;
        max_mileage-=distance;
        remaining_fuel-=distance/10;
        printf("\n行駛 %d 公里，剩餘油量: %d 公升，可行里程數: %d 公里，總里程數: %d 公里",distance,remaining_fuel,max_mileage,total_mileage);
    }
    else
        printf("\n油量不足，無法行駛 %d 公里", distance);
}
void car::refill(int fuel) {
    if (fuel+remaining_fuel>fuel_capacity) {
        remaining_fuel=fuel_capacity;
    }
    else
        remaining_fuel+=fuel;
    max_mileage=remaining_fuel*10;
    printf("\n補充燃油 %d 公升，剩餘油量: %d 公升，可行里程數: %d 公里",fuel,remaining_fuel,max_mileage);

}
int main(){
    car mycar;
    printf("%s 有 %d 個輪子，可載 %d 個人，引擎型號是",mycar.name,mycar.wheel,mycar.person);
    mycar.CheckEngine();
    printf("，油箱容量為 %d 公升",mycar.fuel_capacity);
    mycar.run(50);
    mycar.refill(100);
    mycar.run(200);
    printf("\n---------------------------");
    return 0;
}

