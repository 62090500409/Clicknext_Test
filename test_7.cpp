#include<iostream>
using namespace std;

int main(){
    unsigned int sec;
    cout << "enter amount of seconds : ";
    cin >> sec;
    unsigned int min = sec/60;
    sec = sec % 60;
    unsigned int hour = min/60;
    min = min % 60;
    unsigned int day = hour/24;
    hour = hour % 24;
    cout << "result: ";
    if(hour < 10) cout << '0';
    cout << hour << ':';
    if(min < 10) cout << '0';
    cout << min << ':';
    if(sec < 10) cout << '0';
    cout << sec;
    if(day > 0) cout << " & " << day << " day";
    if(day > 1) cout << 's';
    cout << endl;
    return 0;
}