#include <iostream>
#define MAX_INT 2147483647

using namespace std;  
int line(int c, int v){ 
	if(c > v){ 
		return c; 
	} 
	else{ 
		return v; 
	}
}

int FindMaxCrossingSubArray(int* Array,int low,int mid,int max){
	int LSum = -2147483647;  
	int MLeft;
	int MRight;
	int add = 0; 
	for(int i = mid; i>=low; i--){ 
		add = add + Array[i]; 
		if(add > LSum){ 
			LSum = add; 
			MLeft = i; 
		}  
	} 
	int RSum = -2147483647; 
	add = 0;
	for(int j =mid +1; j<=max; j++){ 
		add = add + Array[j]; 
		if(add > RSum){ 
			RSum = add; 
			MRight = j; 
		}
	} 
	return(MLeft, MRight, LSum + RSum);
} 
 
int FindMaxSubArray(int* Array,int low,int max){  
	 if(max == low){ 
		 return Array[low];
	 } 
	 int mid = ((low + max)/2);
	 return line(line(FindMaxSubArray(Array, low, mid),FindMaxSubArray(Array, mid + 1, max)), FindMaxCrossingSubArray(Array, low, mid, max)); 	 
}

int main(int argc,char **argv) { 
	int ListSize; 
	int* Array; 
	
	cin >> ListSize; 
	Array = new int[ListSize];
	for(int l=0; l<ListSize; l++){
		cin >> Array[l]; 
	}  		
	cout << FindMaxSubArray(Array, 0, ListSize-1); 
	delete[] Array;
}
