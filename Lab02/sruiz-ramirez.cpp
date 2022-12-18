#include <iostream>
#define MAX_INT 2147483647
using namespace std;

void merge(int* arr, int a, int b, int c){

    int A, B;
    int i, j, k;
    int* X;
    int* Y;

    A = b - a + 1;
    B = c - b;

    X = new int[A+1];
    Y = new int[B+1];

    for (i = 0; i < A; i++){
        X[i] = arr[a + i];
    }
    for (j = 0; j < B; j++){
        Y[j] = arr[b + j + 1];
    }
    X[A] = 2147483647;
    Y[B] = 2147483647;

    i = 0;
    j = 0;

    for (k = a; k <= c; k++){
        if (X[i] <= Y[j]){
            arr[k] = X[i];
            i++;
        } else {
            arr[k] = Y[j];
            j++;
        }
    }

}

void mergesort(int* arr, int a, int c){
    if (a < c){
        int b = (a + c)/2;
        mergesort(arr, a, b);
        mergesort(arr, b+1, c);
        merge(arr, a, b ,c);
    }
}

int main(){

    int* arr;
    int size;
    cin >> size;
    arr = new int [size];

    for (int n = 0; n < size; n++){
        cin >> arr[n];
    }

    mergesort(arr, 0, size-1);



    for (int n = 0; n < size; n++){
        cout << arr[n] << ";";
    }

    

    return 0;
}