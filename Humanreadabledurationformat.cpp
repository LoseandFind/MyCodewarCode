#include <string>
#include<vector>
#include<iostream>
const static int year = 60 * 60 * 24 * 365;
const static int day = 60 * 60 * 24;
const static int hour = 60 * 60;
const static int minute = 60;
void ChangeTime(std::vector<std::string>& Time, int& flag, const int time, int& seconds, const std::string& when)
{
    std::string Times;
    int times = seconds / time;
    seconds = seconds % time;
    if (times > 0)
    {
        flag++;
        if (times > 1) Times = std::to_string(times) + " " + when + "s";
        else Times = std::to_string(times) + " " + when;
        Time.emplace_back(Times);
    }
}
std::string format_duration(int seconds) {
    // your code here
    int flag = 0;
    std::string result;
    std::vector<std::string> Time;
    ChangeTime(Time, flag, year, seconds, "year");
    ChangeTime(Time, flag, day, seconds, "day");
    ChangeTime(Time, flag, hour, seconds, "hour");
    ChangeTime(Time, flag, minute, seconds, "minute");
    ChangeTime(Time, flag, 1, seconds, "second");
    if (flag == 1) { result = Time[0]; return result; }
    else if (flag == 2) { result = Time[0] + " and " + Time[1]; return result; }
    int start =0;
    while (flag>2)
    {
        result += Time[start] + ", ";
        flag--;
        start++;
    }
    result += Time[Time.size()-2] + " and " + Time[Time.size()-1];
    return result;
}
int main()
{
    int seconds = 62;
    std::cout<<format_duration(seconds);
}