#include<iostream>
using namespace std;

int main() {
    int input, i, j;
    int n = 1;
    cout << "input integer which in [1-4] : ";
    cin >> input;
    while(input < 1 || input > 4){
        cout << "(invalid input) please input in [1-4] : ";
        cin >> input;
    }
    for(i = 1; i <= input; i++ ){
        for(j = 0; j < (input - i); j++) cout << ' ';
        for(j = 0; j < i; j++){
            cout << n % 10 << ' ';
            n++;
        }
        cout << endl;
    }
    return 0;
}