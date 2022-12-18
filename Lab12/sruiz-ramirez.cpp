#include <iostream>
#include <vector>
#include <queue>
#define MAX_INT 2147483647

using namespace std;

typedef pair<int, int> Integer;
vector<Integer> adj[2000]; //adj dynamic array
int key[2000]; //key for the function
int pi[2000]; //Numerical intake of the array
bool Located[2000]; //Used to reference if it is found

void MST_Prim(int v){
	priority_queue<Integer, vector<Integer>, greater<Integer>> vertice; //Order the queue
	vertice.push(pair<int, int>(0,0)); //Push in the values

	for(int i = 0; i < v; i++){  //for each u Є G.V
		key[i] = MAX_INT; //u.key = ∞
		pi[i] = 0;  //u.π = NIL
	}

	while(!vertice.empty()){   //while Q != 0 (While the queue isn't empty)
		int u = vertice.top().second; //u = Extract_Min(Q)
		vertice.pop(); //Pop so we don't reuse
		Located[u] = true; 

        for(int i = 0; i < adj[u].size(); i++){ //for each v Є G.adj[u]  
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            
            if(!Located[v] && w < key[v]){ //if v Є Q & w(u, v) < v.key
				pi[v] = u;   //v.π = u
                key[v] = adj[u][i].second;  //v.key = w(u, v)
                vertice.push(pair<int,int>(w,v)); //Insert
            }
        }
	}
	for(int i = 1; i < v; i++){
    	cout << pi[i] << "\n";
	} //output
}

int main(){
	int v, e;
	int one, two, three;
	cin >> v >> e;  //vertice and edges

	for(int i = 0; i < e; i++){
		cin >> one >> two >> three; //obtain v, e, w
		adj[one].push_back(make_pair(two, three));
		adj[two].push_back(make_pair(one, three));
	}
	MST_Prim(v);
}