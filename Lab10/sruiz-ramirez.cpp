#include <iostream>
#include <queue>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

//Create a Node structure for the priority_queue
struct Node{
  char node;
  int freq;
  Node* left;
  Node* right;

  //Make the Node public with node  
public:
	Node(){
    node;
    freq;
	}
  
  //Allow the Node to consist of a letter (A-F)(Freq = some const)
    Node(char letter, int freq) {
      this->node = letter;
      this->freq = freq;
    }
};

//Organizes the Node into a heap of ascending order
struct comparison{
    bool operator()(Node* left, Node* right) {
      return (left->freq > right->freq);
    }
};

//Loops through the tree in order to encode the numbers of :1's and 0's 
void Tree_Encrypt(Node* root, string num, char letters[], int n, string encrypt[]){
	if(root->node == '*'){
    Tree_Encrypt(root->left, num + "0", letters, n, encrypt);
    Tree_Encrypt(root->right, num + "1", letters, n, encrypt);
    }
    else{
		for(int i = 0; i < n; i++){
      if (root->node == letters[i]) {
        encrypt[i] = num;
        }
      }
    }
}

void Huffman(int* array, char letters[], int n, string encrypt[]) {
  //allocate a new node z,x,y
  Node* z = new Node();
  Node* x = new Node();
  Node* y = new Node();
  
  //Variable to store string of code for context of tree
  string num;

  //Value type, dynamic array, function to soert array
  priority_queue <Node*, vector <Node*>, comparison> container;

  //Creates a priority_queue with characters and values  
	for(int i = 0; i < n; i++){
      Node* temp = new Node(letters[i], array[i]);
      container.push(temp);
    }

    for(int i = 1; i <= n - 1; i++){
      //Extract-Minimum(Container), also sets x as location of node
      x = container.top();
      //Removes min in order to find the next min
      container.pop();
      //Extract-Minimum(Container), also sets y as location of node
      y = container.top();
      //Removes min for the next itteration
      container.pop();
      //Creates Parent Node with characer and value of Parent Node (z.freq = x.freq + y.freq)
      z = new Node('*', x->freq + y->freq);
      //Connects Parent node to left child Node
      z->left = x;
      //Connects Parent node to Right child Node
      z->right = y;
      //Puts z node back into Container, because it may be child of another parent Node (Insert(Q,z))
      container.push(z);
    }
    //Send to funtion to encrypt A-F 
    Tree_Encrypt(container.top(), num, letters, n, encrypt);
}

int main(){
  //Construct necessary arrays for Huffman function
  int* array = new int[5];
  char letters[6];
  int ascii = 65;
  string encrypt[6];
	
  //Gather user input and construct an array of the letter A-F
	for(int i = 0; i < 6; i++){
    cin >> array[i];
    letters[i] = (char) ascii;
    ascii++;
    }
    
    Huffman(array, letters, 6, encrypt);
    
    //Finally print the code
    for(int i = 0; i < 6; i++){
      cout << letters[i] << ":" << encrypt[i] << "\n";
    }
}