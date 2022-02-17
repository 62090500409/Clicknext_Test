#include<iostream>
using namespace std;

#define MAX 1000

int main(){
    unsigned int price, five_hund, one_hund, fifty, twenty, ten, five;
    cout << "customer pay " << MAX << " thb\n";
    cout << "enter price of product (must less than " << MAX << ") : ";
    cin >> price;
    while(price >= MAX){
        cout << "(invalid input) please enter not over 999 : ";
        cin >> price;
    }
    cout << "return :\n";
    five_hund = price/500;
    price = price % 500;
    if(five_hund > 0) cout << "500 - " << five_hund << endl;
    one_hund = price/100;
    price = price % 100;
    if(one_hund > 0) cout << "100 - " << one_hund << endl;
    fifty = price/50;
    price = price % 50;
    if(fifty > 0) cout << "50  - " << fifty << endl;
    twenty = price/20;
    price = price % 20;
    if(twenty > 0) cout << "20  - " << twenty << endl;
    ten = price/10;
    price = price % 10;
    if(ten > 0) cout << "10  - " << ten << endl;
    five = price/5;
    price = price % 5;
    if(five > 0) cout << "5   - " << five << endl;
    if(price > 0) cout << "1   - " << price << endl;
    return 0;
}