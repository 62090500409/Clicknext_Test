#include<iostream>
using namespace std;

int main(){
    unsigned int input, i, j;
    cout << "enter high of pyramid : ";
    cin >> input;
    for(i = 0; i < input; i++){
        for(j = input - 1; j > i; j--) cout << ' ';
        for(j = 2*i + 1; j > 0; j--) cout << '*';
        cout << '\n';
    }
    return 0;
}