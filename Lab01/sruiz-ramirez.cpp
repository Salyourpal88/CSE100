#include <iostream>
#define MAX_INT 2147483647

using namespace std;
  

int main(int argc,char **argv) {
	int ListSize = 0;
	int* Array;
	int saver = 0;
	int k = 0;
	
	cin >> ListSize; 
	Array = new int[ListSize];
	for(int l=0; l<ListSize; l++){
		cin >> Array[l]; 
	}
	for(int i=1; i<ListSize; i++){ 
		saver = Array[i];
		k = i - 1; 
		while(k >= 0 && Array[k] > saver){ 
			Array[k + 1] = Array[k]; 
			k = k - 1; 
		}
		Array[k+1] = saver;
		for(int m=0; m<=i; m++){ 
			cout << Array[m] << ";" ;
		}
		cout << "\n";
	
	}
	delete[] Array;
}
