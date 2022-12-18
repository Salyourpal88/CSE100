#include <iostream>
#define MAX_INT 2147483647
using namespace std;
int r[3500][3500];

void Print_Optimal_Parens(int i, int j){
    if(i == j){
        cout << "A" << i - 1;
    }
    else{
        cout << "(";
        Print_Optimal_Parens(i, r[i][j]);
        Print_Optimal_Parens(r[i][j] + 1, j);
        cout << ")";
    }
}



int Matrix_Chain_Order(int* p, int num){
    int n = num;
    int m[n][n];
    int s[n][n];
    for(int i = 1; i <= n; i++){
        m[i][i] = 0;
    }
    for(int l = 2; l <= n; l++){
        for(int i = 1; i <= n - l + 1; i++){
            int j = i + l - 1;
            m[i][j] = 2147483647;
            for(int k = i; k <= j - 1; k++){
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if(q < m[i][j]){
                    m[i][j] = q;
                    r[i][j] = k;
                }
            }
        }
    }
    return m[1][num];
}


int main(){
    int num; 
    cin >> num; 
    int* p = new int[num + 1];
    for(int i = 0; i <= num; i++){
        cin >> p[i];
    }
    cout << Matrix_Chain_Order(p, num) << "\n";
    Print_Optimal_Parens(1, num);
    cout << "\n";  
}