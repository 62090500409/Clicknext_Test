#include<iostream>
#include "utilized.cpp"
using namespace std;

string toUpper(string str){
    int i;
    string upper = "";
    for(i = 0; i < str.length(); i++){
        if(str[i] >= 97 && str[i] <= 122) upper += str[i] - 32;
        else upper += str[i];
    }
    return upper;
}

bool string_compare(string s1, string s2){
    if(s1.length() != s2.length()) return false;
    int* s1_ASCIIfreq = ZEROARRAY(69);
    int* s2_ASCIIfreq = ZEROARRAY(69);
    // (char - 32) [0-32]  : special character with ascii code since 32 to 64
    // (char - 32) [33-58] : A-Z
    // (char - 32) [59-64] : [ \ ] ^ _ `
    // (char - 58) [65-68] : { | } ~
    int i, m, ascii, indx;
    string upper_s1 = toUpper(s1);
    string upper_s2 = toUpper(s2);
    for(i = 0; i < s1.length(); i++){
        if(upper_s1[i] >= 123 && upper_s1[i] <= 126) m = 58;
        else m = 32;
        indx = upper_s1[i] - m;
        s1_ASCIIfreq[indx]++;
        
        if(upper_s2[i] >= 123 && upper_s2[i] <= 126) m = 58;
        else m = 32;
        indx = upper_s2[i] - m;
        s2_ASCIIfreq[indx]++;
    }
    for(i = 0; i < 69; i++){
        if(s1_ASCIIfreq[i] != s2_ASCIIfreq[i]) return false;
    }
    delete [] s1_ASCIIfreq;
    delete [] s2_ASCIIfreq;
    return true;
}

int main() {
    string s1;
    string s2;
    cout << "Enter 1st string : ";
    cin >> s1;
    cout << "Enter 2nd string : ";
    cin >> s2;
    if(string_compare(s1, s2)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}