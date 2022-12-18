#include <iostream>
#define MAX_INT 2147483647

using namespace std;  
int Partition(int* Array, int beg, int end){ 
	int x = Array[end]; 
	int i = beg - 1;
	for(int l = beg; l <= end-1; l++){ 
		if(Array[l] <= x){ 
			i = i + 1; 
			swap(Array[i], Array[l]); 
		} 
	} 
	swap(Array[i+1], Array[end]); 
	return i + 1; 
}

int Random_Partition(int* Array, int beg, int end){ 
	int i = rand()%(end-beg) + beg; 
	swap(Array[end], Array[i]); 
	return Partition(Array, beg, end);
}

void Random_Qsort(int* Array, int beg, int end){ 
	if(beg<end){ 
		int mid = Random_Partition(Array, beg, end); 
		Random_Qsort(Array, beg, mid-1);
		Random_Qsort(Array, mid + 1, end); 
	}
}
int main(int argc,char **argv) { 
	int* Array;
	int beg = 0; 
	int end; 
	cin >> end; 
	Array = new int[end];  
	for(int n=0; n < end; n++){
		cin >> Array[n]; 
		}
	Random_Qsort(Array, beg, end-1); 
	for(int i = 0; i < end; i++){ 
		cout << Array[i] << ";"; 
	}
	delete[] Array;
}
