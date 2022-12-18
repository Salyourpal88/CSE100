#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

typedef pair<int, int> IP;//integer pair
vector<IP> adj[1000];//adjacents
bool VISITED[1000]; //considers what has been visited in MST
int key[1000];//define key considered first in pairing
int parent[1000];//define parent array

//PRIMS(based on pseudocode)

void prims(int n)
{
    priority_queue<IP, vector<IP>, greater<IP> >Q;
    //first, create a priority queue that holds the respective vertices in place
    Q.push(pair<int,int>(0,0));
    
    
    for(int i=0; i<n; i++)
    {
        key[i]=999999999; //after inserting the source as 0 utilizing Q, initialize all keys to infinity (large number)
        parent[i] = 0;
        
    }
    
    do{
        int u = Q.top().second;  //MIN KEY VERTEX. u = min() by KEY VALUE
        Q.pop();
        VISITED[u]=true;
        //  VISITED
        for(int i=0; i < adj[u].size(); i++)
        {
            //A= A u (U,PARENT(u));
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            
            //vertex, weight, and adjacents
            if(!VISITED[v] && key[v]>w) //condition for considering smaller weight wrt vertex
            {
                key[v]=adj[u][i].second;
                Q.push(pair<int,int>(w,v));
                parent[v]=u;
            }
        }//count++;
        
    }while(!Q.empty());
  // while(count < n && count > 0);
    
    //PRINT LOOP WRT parent
    for(int i=1; i<n; i++)
    cout<<parent[i]<<endl;
    
    
}

int main(){
    int n, m, u, v, w;
    cin >> n;
    cin >> m;
    
    //create graph
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    
    prims(n);
    
    return 0;
}