#include <iostream>
#include <list>
#include <stack>

using namespace std;

class SCC{
    int End;
    list<int> *adj;

    void DepthFirstSearch(int index, bool* Truth, int index2, int* array);
    void Convert(int index, bool* Truth, stack<int> &Heap);

    public:
        void SCC_Output(int Point, int* array);
        SCC(int End);
        void Combine(int val1, int val2);
    SCC Exchange();
};

SCC::SCC(int End){
    this -> End = End;
    adj = new list<int>[End];
}

void SCC::DepthFirstSearch(int index, bool* Truth, int index2, int* array){
    Truth[index] = 1;
    array[index] = index2;
    list<int>::iterator i;

    for (i = adj[index].begin(); i != adj[index].end(); ++i){
        if (!Truth[*i]){
            DepthFirstSearch(*i, Truth, index2, array);
        }
    }
}

SCC SCC::Exchange(){

    SCC Graph(End);

    for (int beg = 0; beg < End; beg++){
        list<int>::iterator i;
        for(i = adj[beg].begin(); i != adj[beg].end(); i++){
            Graph.adj[*i].push_back(beg);
        }
    }
    return Graph;
}

void SCC::Convert(int index, bool* Truth, stack<int> &Heap){
    Truth[index] = 1;
    list<int>::iterator i;

    for(i = adj[index].begin(); i != adj[index].end(); i++){
        if(!Truth[*i]){
            Convert(*i, Truth, Heap);
        }
    }
    Heap.push(index);
}

void SCC::SCC_Output(int Point, int* array){
    stack<int> Heap;
    bool Truth[End];
    
    //We create an Boolean array, where we convert false values
    for(int i = 0; i < End; i++){
        if(Truth[i] != 1){
            Convert(i, Truth, Heap);
        }
    }

    SCC gather = Exchange();

    //We make values False
    for(int i = 0; i < End; i++){
        Truth[i] = 0;
    }

    while (Heap.empty() == 0){
        int index = Heap.top();
        Heap.pop();
        int low = index;

        if (Truth[index] != 1){
            gather.DepthFirstSearch(index, Truth, index, array);
            for(int i = 0; i < Point; i++){
                if(array[i] == index){
                    if(i < low){
                    low = i;
                    }
                }
            }
            for(int i = 0; i < Point; i++){
                if(array[i] == index){
                    array[i] = low;
                }
            }
        }
    }
}

void SCC::Combine(int val1, int val2){  //Values 1 and 2
    adj[val1].push_back(val2);  //Add Val2 to the array connected with val 1
}

int main(){
    int Point, Rows;
    int val1, val2;
    cin >> Point >> Rows;
    int* array = new int[Point];

    SCC Graph(Point);
    
    //We combine the values to an array
    for(int i = 0; i < Rows; i++){
        cin >> val1 >> val2;
        Graph.Combine(val1, val2);
    }
    
    //Create an array with the value of Point gathered from the user
    for(int i = 0; i < Point; i++){
        array[i] = Point;
    }

    Graph.SCC_Output(Point, array);

    //Print the newly constructed array
    for(int i = 0; i < Point; i++){
        cout << array[i] << "\n";
    }
}