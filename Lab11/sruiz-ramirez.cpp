#include<bits/stdc++.h>
#define ll  long long int

using namespace std;

int main(){    
    //What are the amount of points?
    int length;
    cin >> length;
    int limit = INT_MIN;
    int j, k;

    //Dynamic double array
    vector <vector<int>> spot(length, vector<int>(2,0));
    
    for(int i = 0; i < length; i++){
        cin >> spot[i][0]; 
        cin >> spot[i][1];
    }
    /* Test 1
    9
    spot[0][0] = 6 spot[0][1] = 6
    spot[1][0] = 5 spot[1][1] = 7
    spot[2][0] = 7 spot[2][1] = 4
    spot[3][0] = 1 spot[3][1] = 10
    spot[4][0] = 5 spot[4][1] = 8
    spot[5][0] = 4 spot[5][1] = 2
    spot[6][0] = 6 spot[6][1] = 2
    spot[7][0] = 5 spot[7][1] = 6
    spot[8][0] = 4 spot[8][1] = 1
    */
    
    //map of 2 int and boolean operation
    map <pair<int,int>,bool> Hash_Graph;
    
    for(int i = 0; i < length; i++){
        Hash_Graph[{spot[i][0], spot[i][1]}] = true;
    }

    /* Test 1
    bollean of these spots:
    spot[0][0] | true spot[0][1] | true
    spot[1][0] | true spot[1][1] | true
    spot[2][0] | true spot[2][1] | true
    spot[3][0] | true spot[3][1] | true 
    spot[4][0] | true spot[4][1] | true
    spot[5][0] | true spot[5][1] | true
    spot[6][0] | true spot[6][1] | true
    spot[7][0] | true spot[7][1] | true
    spot[8][0] | true spot[8][1] | true
    */

    //We loop through the graph
    for(auto val = Hash_Graph.begin(); val != Hash_Graph.end(); val++){
        j = val -> first.first; //Gets double array value from Hash_Graph 
        k = val -> first.second; //Gets double array value from Hash_Graph
        if(Hash_Graph[{j - 1, k - 1}]){
            limit = max(limit, j + k);   //Find max
        }
    }

    //If limit matches the INT_MIN, we return -1
    if(limit == INT_MIN){
        limit = -1;
    }
    cout << limit;
}