#include<iostream>
using namespace std;

string revert_word(string str){
    int i, j, s;
    string revert_str = "";
    s = 0;
    for(i = 0; i <= str.length(); i++){
        if(str[i] == ' ' || str[i] == '.' || str[i] == '\0'){
            for(j = i - 1; j >= s; j--){
                revert_str += str[j];
            }
            revert_str += str[i];
            s = i + 1;
        }
    }
    return revert_str;
}

int main(){
    string input;
    cout << "enter some sentense or phrase : ";
    getline(cin, input);
    cout << "revert : " << revert_word(input) << endl;
    return 0;
}