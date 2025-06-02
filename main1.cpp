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
car::car(char* carname="�ۤp��",int carwheel=4,int carperson=5,char* carengine="MT500-LR",int capacity=50) {
    printf("car�غc�禡���椤...\n");
    strcpy(name,carname);
    wheel=carwheel;
    person=carperson;
    strcpy(engine,carengine);
    fuel_capacity=capacity;
    remaining_fuel=fuel_capacity;
    max_mileage=fuel_capacity*10;
    total_mileage=0;
}
truck::truck(char* truckname="�d��",int truckwheel=6,int truckperson=3,int trucklength=10,char* truckengine="MAX1000-ER")
: car(truckname,truckwheel,truckperson,truckengine),length(trucklength){
    printf("truck�غc�禡���椤...\n");
};
car::~car() {
    printf("\ncar�Ѻc�禡���椤...");
}
truck::~truck() {
    printf("\ntruck�Ѻc�禡���椤...");
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
        printf("\n��p %d �����A�Ѿl�o�q: %d ���ɡA�i�樽�{��: %d �����A�`���{��: %d ����",distance,remaining_fuel,max_mileage,total_mileage);
    }
    else
        printf("\n�o�q�����A�L�k��p %d ����", distance);
}
void car::refill(int fuel) {
    if (fuel+remaining_fuel>fuel_capacity) {
        remaining_fuel=fuel_capacity;
    }
    else
        remaining_fuel+=fuel;
    max_mileage=remaining_fuel*10;
    printf("\n�ɥR�U�o %d ���ɡA�Ѿl�o�q: %d ���ɡA�i�樽�{��: %d ����",fuel,remaining_fuel,max_mileage);

}
int main(){
    car mycar;
    printf("%s �� %d �ӽ��l�A�i�� %d �ӤH�A���������O",mycar.name,mycar.wheel,mycar.person);
    mycar.CheckEngine();
    printf("�A�o�c�e�q�� %d ����",mycar.fuel_capacity);
    mycar.run(50);
    mycar.refill(100);
    mycar.run(200);
    printf("\n---------------------------");
    return 0;
}

