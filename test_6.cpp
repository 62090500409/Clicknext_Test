#include<iostream>
#include "utilized.cpp"
using namespace std;

#define SIZE 10

int main(){
    int *array = new int[SIZE];
    int i;
    cout << "enter to 10 members of array\n";
    for(i = 0; i < SIZE; i++){
        cout << "[" << i << "] : ";
        cin >> array[i];
    }
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    PRINT_INT_ARRAY(array, SIZE);
    quick_sort(&array[0], &array[SIZE - 1], false);
    cout << "after sorted" << endl;
    PRINT_INT_ARRAY(array, SIZE);
    delete [] array;
    return 0;
}