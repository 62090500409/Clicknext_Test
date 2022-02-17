#include<iostream>
#include "utilized.cpp"
using namespace std;

#define MAX 100

int main(){
    int* array = new int[MAX];
    uint i,size;
    cout << "enter boardcast day\n";
    cout << "*enter up to " << MAX << " members of array (enter zero or negative or non-integer to stop)\n";
    size = INT_ARRAY_INPUT(&array, MAX, '-');
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    int *sorted;
    size = unique_array(&sorted, array, size);
    int *lower, *upper;
    PRINT_INT_ARRAY(sorted, size);
    lower = &sorted[0];
    upper = lower;
    while(upper < sorted + size - 1){
        while(*upper + 1 == *(upper + 1) || *upper == *(upper + 1)){
            upper++;
            if(upper >= sorted + size - 1) break;
        }
        cout << *lower;
        if(lower == upper) {
            cout << ", ";
            upper++;
        }
        else cout << "-";
        lower = upper;
    }
    cout << *lower << endl;
    delete [] sorted;
    delete [] array;
    return 0;
}