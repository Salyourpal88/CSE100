#include <iostream> 
using namespace std;

void Counting_Sort(int A[][10], int B[][10], int k, int l, int d){
    int C[k];
    for(int i = 0; i <= k; i++){
        C[i] = 0; 
    }
    for(int j = 0; j < d; j++){
        C[A[j][l]] = C[A[j][l]] + 1;
    }
    for(int i = 1; i <= k; i++){
        C[i] = C[i] + C[i - 1];
    }
    for(int j = d - 1; j >= 0; j--){
        int temp = C[A[j][l]];
        B[temp][l] = A[j][l];
        C[A[j][l]] = C[A[j][l]] - 1;
    }
    if(l = 9){
        for(int i = 0; i < d; i++){
            for(int j = 0; j < 10; j++){
            cout << B[i][j] << ";";
        }
        cout << "\n";
    }
    } 
    
}


void Radix_Sort(int A[][10], int d){ 
    int B[d][10];
    for(int j = 0; j < 10; j++){
        Counting_Sort(A, B, 3, j, d);
    }
}
int main(){
    int row; 
    cin >> row; 
    int Array[row][10];
    for(int i = 0; i < row; i++){
        for(int j = 0; j < 10; j++){
            cin >> Array[i][j];
        }
    }
    Radix_Sort(Array, row);
}