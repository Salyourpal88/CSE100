#include <iostream>
#define MAX_INT 2147483647

using namespace std; 
void Max_Heapify(int* Array, int k, int i){  
	//Gets the left and right value
	int l = 2 * i + 1; 
	int r = 2 * i + 2; 
	int exchange = 0;
	int largest; 
	//Looks at comparisons for the values 
	if(l < k && Array[l] > Array[i]){ 
		largest = l;
	} 
	else{
		largest = i; 
	}
	if(r < k && Array[r] > Array[largest]){ 
		largest = r;
	} 
	if(largest != i){  
		// another swaping of values
		exchange = Array[largest]; 
		Array[largest] = Array[i]; 
		Array[i] = exchange;  
		//recursive
		Max_Heapify(Array, k, largest);	 
	} 
}
void Build_Max_Heap(int* Array, int Size){  
	for(int i = Size / 2 - 1; i >= 0; i--){ 
		Max_Heapify(Array, Size, i);  
	}
}

void Heap_sort(int* Array, int Size){ 
	Build_Max_Heap(Array, Size);
	int exchange = 0;
	for(int i = Size - 1; i > 0; i--){  
		// lines swap the values
		exchange = Array[0]; 
		Array[0] = Array[i]; 
		Array[i] = exchange; 
		Max_Heapify(Array, i, 0);
	}

}

int main(int argc,char **argv) {
	int* Array; 
	int Size; 
	// collects values and array values for each
	cin >> Size; 
	Array = new int[Size];  
	for(int n=0; n < Size; n++){
		cin >> Array[n]; 
		}
	Heap_sort(Array, Size);  
	// prints the array
	for(int k = 0; k < Size; k++){ 
		cout << Array[k] << ";"; 
	}
	delete[] Array;

}