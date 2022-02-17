#include<iostream>
#include "utilized.cpp"
using namespace std;

#define MAX 100

bool pair_sum(int* array, unsigned int size, int sum){
    int* sorted = insertion_sort(array, size);
    int* head = sorted;
    int* tail = sorted + (size - 1);
    int npair = 0;
    while(head < tail){
        if(*head + *tail < sum) head++;
        else if(*head + *tail > sum) tail--;
        else {
            cout << *head << ',' << *tail << endl;
            head++;
            tail--;
            npair++;
        }
    }
    delete [] sorted;
    return npair != 0;
}

int main(){
    int *array = new int[MAX];
    int size;
    int sum;
    cout << "enter up to " << MAX << " members of array (enter not integer to stop)\n";
    size = INT_ARRAY_INPUT(&array, MAX, 'a');
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    PRINT_INT_ARRAY(array, size);
    cout << "enter sum of integer for pairing : ";
    cin >> sum;
    cout << "pairing result\n";
    if(!pair_sum(array, size, sum)) 
        cout << "there's any pair of integers which has sum = " << sum << endl;
    delete [] array;
    return 0;
}