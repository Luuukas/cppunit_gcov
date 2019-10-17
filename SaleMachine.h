#include <string>
using namespace std;

class SaleMachine
{
public:
    SaleMachine();
    string sale(string drink, int money);
    int orangeNum, beerNum, fiveNum;

private:
    string answer[5] = {"很抱歉，没有", "请取走", "拿好5元，请取走", "没有零钱找，退您10元", "错误指令！"};
    string type[2] = {"beer", "orange"};
};