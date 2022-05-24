// 1. 模拟法：记录当前天数，当前日工资，涨薪倒计时
// 在纯编辑器（仅自动换行，括号）的情况下水土不服，写出了无数bug
#include <iostream>

using std::cin;
using std::cout;

int main()
{
    int totalDays = 0;
    cin >> totalDays;

    int totalSalary = 0;
    int salary = 1;
    int dayToRaise = 1;
    int date = 1;

    while (date <= totalDays)
    {
        if (dayToRaise)
        {
            --dayToRaise;
            totalSalary += salary;
            ++date;
        }
        else
        {
            ++salary;
            dayToRaise = salary;
        }
    }

    cout << totalSalary;

    return 0;
}