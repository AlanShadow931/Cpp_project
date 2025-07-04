#include <stdio.h>
#include <string.h>

// 定義車輛類別
class car
{
public:
    int wheel;                       // 輪子數量
    int person;                      // 可乘載人數
    char name[20];                   // 車輛名稱
    void SetEngine(char* SetEngine); // 設定引擎型號
    void CheckEngine();              // 輸出引擎型號
private:
    char engine[20];     // 引擎型號（私有成員）
};

// 設定引擎型號
void car::SetEngine(char* SetEngine)
{
    strcpy(engine,SetEngine);
}

// 輸出引擎型號
void car::CheckEngine()
{
    printf("引擎型號%s\n",engine);
}

int main(void)
{
    car bus,truck,taxi; // 宣告三種車輛

    // 設定公車屬性
    strcpy(bus.name,"公車");
    bus.wheel=6;
    bus.person=40;
    bus.SetEngine("M9000-24");

    // 設定卡車屬性
    strcpy(truck.name,"卡車");
    truck.wheel=8;
    truck.person=3;
    truck.SetEngine("TM9000-B6");

    // 設定計程車屬性
    strcpy(taxi.name,"計程車");
    taxi.wheel=4;
    taxi.person=5;
    taxi.SetEngine("T1600-AC");

    // 輸出各車輛資訊及引擎型號
    printf("%s有%d個輪子,可載%d人 ",bus.name,bus.wheel,bus.person);bus.CheckEngine();
    printf("%s有%d個輪子,可載%d人 ",truck.name,truck.wheel,truck.person);truck.CheckEngine();
    printf("%s有%d個輪子,可載%d人 ",taxi.name,taxi.wheel,taxi.person);taxi.CheckEngine();

    return 0;
}