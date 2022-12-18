#include <iostream>
#define MAX_INT 2147483647

using namespace std;

int max(int q, int p){
if(q > p){
    return q;
}
else{
    return p;
}
}

int* Extended_Bottom_Up_Cut_Rod(int*p, int n){
    int* r = new int[n + 1];
    int* s = new int[n + 1];
    int q;
    r[0] = 0; 
    for(int j = 1; j <= n; j++){
        q = -2147483647;
        for(int i = 1; i <= j; i++){
            if(q < p[i] + r[j - i]){
                q = p[i] + r[j - i];
                s[j] = i;
            }
        }
        r[j] = q;
    }
    return r, s;
}

void Print_Cut_Rod_Solution(int* p, int n){
    int* r;
    int* s;
    (r, s) = Extended_Bottom_Up_Cut_Rod(p, n);
    while(n > 0){
        cout << s[n] << " ";
        n = n - s[n];
    }
    cout << "-1" << "\n";
}

int Bottom_Up_Cut_Rod(int* p, int n){
    int q;
    int* r = new int[n + 1]; 
    r[0] = 0;
    for(int j = 1; j <= n; j++){
        q = -2147483647;
        for(int i = 1; i <= j; i++){
            q = max(q, p[i] + r[j - i]);
        }
        r[j] = q;
    }
    return r[n];
}

int main(int argc,char **argv){
int n;
cin >> n;
int* p = new int[n + 1];
for(int i = 1; i <= n; i++){
    cin >> p[i];
}
cout << Bottom_Up_Cut_Rod(p,n) << "\n";
Print_Cut_Rod_Solution(p,n);
}