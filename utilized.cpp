#include<iostream>
#include<cstdlib>
using namespace std;

int* ZEROARRAY(int n){
    int* arr = new int[n];
    int i;
    for(i = 0; i < n; i++){
        arr[i] = 0;
    }
    return arr;
}

int INT_ARRAY_INPUT(int* array[], uint max, char stop_condi){
    int i, j, tmp, sum;
    for(i = 0; i < max; i++){
        cout << "[" << i << "] : ";
        cin >> tmp;
        if(!cin.good()) break;
        if(stop_condi == '+'){
            if(tmp >= 0) break;
        } else if(stop_condi == '-'){
            if(tmp <= 0) break;
        } else if(stop_condi == '0'){
            if(tmp == 0) break;
        } else if(stop_condi == 'p'){
            if(tmp > 0) break;
        } else if(stop_condi == 'n'){
            if(tmp < 0) break;
        }
        (*array)[i] = tmp;
    }
    cin.clear();
    cin.ignore();
    int *buf_array = *array;
    *array = new int[i];
    for(j = 0; j < i; j++) (*array)[j] = buf_array[j];
    delete [] buf_array;
    return i;
}

void PRINT_INT_ARRAY(int* array, uint size){
    int i;
    cout << "your array : [ " << array[0];
    for(i = 1; i < size; i++){
        cout << ", " << array[i];
    }
    cout << " ] array size : " << size << endl;
}

int* insertion_sort(int* array, uint size){
    int* sort = new int[size];
    int i,j;
    for(i = 0; i < size; i++){
        for(j = i; j >= 0; j--){
            if(j == 0 || sort[j - 1] <= array[i]){
                sort[j] = array[i];
                break;
            } else {
                sort[j] = sort[j - 1];
            }
        }
    }
    return sort;
}

int unique_array(int* unique[], int* array, uint size){
    int* sorted = insertion_sort(array, size);
    int* unique_list = new int[size];
    uint i, n;
    n = 0;
    for(i = 0; i < size; i++){
        unique_list[n] = sorted[i];
        n++;
        while(sorted[i] == sorted[i+1] && i + 1 < size){
            i++;
        }
    }
    delete [] sorted;
    *unique = new int[n];
    for(i = 0; i < n; i++){
        (*unique)[i] = unique_list[i];
    }
    delete [] unique_list;
    return n;
}


void swap(int* x, int* y){
    if(x == y) return;
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int* partition(int* low, int* high, bool asc){
    int rd = rand() % (high - low + 1);
    int* rand_pivot = low + rd;
    swap(rand_pivot, high);
    int pivot = *high;
    int* parti = low - 1;
    int* indx;
    for(indx = low; indx <= high - 1; indx++){
        if(asc){
            if(*indx < pivot){
            parti++;
            swap(parti, indx);
            }
        }
        else {
            if(*indx > pivot){
            parti++;
            swap(parti, indx);
            }
        }
    }
    swap(high, parti + 1);
    return parti + 1;
}

void quick_sort(int* low, int* high, bool asc){
    int* parti;
    if(low < high){
        parti = partition(low, high, asc);

        quick_sort(low, parti - 1, asc);
        quick_sort(parti + 1, high, asc);
    }
}

void merge(int* left, int* mid, int* right, bool asc){
    int lsize = mid - left + 1;
    int rsize = right - mid;
    int* larray = new int[lsize];
    int* rarray = new int[rsize];
    int *lindx, *rindx, *mindx;
    bool sort_condi;

    for(lindx = left; lindx <= mid; lindx++){
        larray[lindx - left] = *lindx;
    }
    for(rindx = mid + 1; rindx <= right; rindx++){
        rarray[rindx - mid - 1] = *rindx;
    }

    mindx = left;
    lindx = &larray[0];
    rindx = &rarray[0];
    while(lindx < &larray[0] + lsize && rindx < &rarray[0] + rsize){
        if(asc) sort_condi = *lindx < *rindx;
        else sort_condi = *lindx > *rindx;
        if(sort_condi){
            *mindx = *lindx;
            lindx++;
        } else {
            *mindx = *rindx;
            rindx++;
        }
        mindx++;
    }

    while(lindx < &larray[0] + lsize){
        *mindx = *lindx;
        lindx++;
        mindx++;
    }
    while(rindx < &rarray[0] + rsize){
        *mindx = *rindx;
        rindx++;
        mindx++;
    }

    delete [] larray;
    delete [] rarray;
}

void merge_sort(int* left, int* right, bool asc){
    int* mid = left + (right - left)/2;
    if(left < right){
        merge_sort(left, mid, asc);
        merge_sort(mid + 1, right, asc);
        merge(left, mid, right, asc);
    }
}