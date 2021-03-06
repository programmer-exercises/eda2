#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "vector_preconfig.h"

using namespace std;
 
int get_max(int array[], int size){
    int max = array[0];
    for (int i = 1; i < size; i++){
        if (array[i] > max){
            max = array[i];
        }
    }
    return max;
}
 
void count_sort(int array[], int size, int exp){
    int output[size];
    int i, count[10] = {0};
 
    // Store count of occurrences in count[]
    for (i = 0; i < size; i++){
        int position = (array[i]/exp)%10;
        count[position]++;
    }
 
    for (i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }
 
    // Build the output array
    for (i = size - 1; i >= 0; i--){
        int position = count[(array[i]/exp)%10];
        output[position-1] = array[i];
        count[(array[i]/exp)%10]--;
    }
 
    for (i = 0; i < size; i++){
        array[i] = output[i];
    }
}
 
void radix_sort(int array[], int size){
    int max = get_max(array, size);
 
    // exp =  1, 10, 100 ...
    for (int exp = 1; max/exp > 0; exp *= 10){
        count_sort(array, size, exp);
    }
}
 
void print(int array[], int size){
    for (int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
}
 
int main(){
    
    int array[100];
    preconfig(array,100);
    int size = sizeof(array)/sizeof(array[0]);

    clock_t start, end;
    start = clock();
    cout << endl;
    radix_sort(array, size);
    cout << endl;
    end = clock();
    
    long double tmili = (end - start)/(double)(CLOCKS_PER_SEC/1000);
    cout << "Time: " << tmili << " ms" << endl;

    return 0;
}
