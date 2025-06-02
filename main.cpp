#include <iostream>
#include <string>
using namespace std;
class car {
public:
    int wheel;
    int person;
    int fuel_capacity;
    string name;
    car(string,int,int,string,int);
    ~car();
    void SetEngine(string SetEngine);
    void CheckEngine();
    void refill(int fuel);
    void run(int distance);
private:
    string engine;
    int remaining_fuel;
    int max_mileage;
    int total_mileage;
};
class truck: public car{
    public:
    int length;
    truck(string,int,int,int,string);
    ~truck();
};
car::car(string carname="自小客",int carwheel=4,int carperson=5,string carengine="MT500-LR",int capacity=50) {
    cout<<"car建構函式執行中..."<<endl<<"---------------------------"<<endl;
    name=carname;
    wheel=carwheel;
    person=carperson;
    engine=carengine;
    fuel_capacity=capacity;
    remaining_fuel=fuel_capacity;
    max_mileage=fuel_capacity*10;
    total_mileage=0;
}
truck::truck(string truckname="卡車",int truckwheel=6,int truckperson=3,int trucklength=10,string truckengine="MAX1000-ER")
: car(truckname,truckwheel,truckperson,truckengine),length(trucklength){
    cout<<"truck建構函式執行中..."<<endl;
};
car::~car() {
    cout<<"car解構函式執行中..."<<endl;
}
truck::~truck() {
    cout<<"truck解構函式執行中..."<<endl;
}
void car::SetEngine(string SetEngine) {
    engine=SetEngine;
}
void car::CheckEngine(){
    cout<<engine;
}
void car::run(int distance) {
    if (distance<=max_mileage) {
        total_mileage+=distance;
        max_mileage-=distance;
        remaining_fuel-=distance/10;
        cout<<"\n行駛 "<<distance<<" 公里，剩餘油量: "<<remaining_fuel<<" 公升，可行里程數: "<<max_mileage<<" 公里，總里程數: "<<total_mileage<<" 公里";
    }
    else
        cout<<"\n油量不足，無法行駛 "<<distance<<" 公里";
}
void car::refill(int fuel) {
    if (fuel+remaining_fuel>fuel_capacity) {
        remaining_fuel=fuel_capacity;
    }
    else
        remaining_fuel+=fuel;
    max_mileage=remaining_fuel*10;
    cout<<"\n補充燃油 "<<fuel<<" 公升，剩餘油量: "<<remaining_fuel<<" 公升，可行里程數: "<<max_mileage<<" 公里";
}
int main(){
    car* mycar = new car();
    cout<<mycar->name<<" 有 "<<mycar->wheel<<" 個輪子，可載 "<<mycar->person<<" 個人，引擎型號是 ";
    mycar->CheckEngine();
    cout<<"，油箱容量為 "<<mycar->fuel_capacity<<" 公升";
    mycar->run(50);
    mycar->refill(100);
    mycar->run(200);
    cout<<"\n---------------------------"<<endl;
    delete mycar;
    return 0;
}

