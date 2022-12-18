#include<iostream>
#include<string>
#include<sstream>
using namespace std;

struct Node {
  int key;   // Value of the node
  Node *left;   // Pointer to the left node
  Node *right;  // Pointer to the right node
  Node *p; // Pointer to the parent node
};

void oin(Node* &x){
  if(x != NULL){
    oin(x -> left);
    cout << x -> key << "\n";
    oin(x -> right);
  }
}

void opre(Node* &x){
  if(x != NULL){
    cout << x -> key << "\n";
    opre(x -> left);
    opre(x -> right);
  }
}

void opost(Node* &x){
  if(x != NULL){
    opost(x -> left);
    opost(x -> right);
    cout << x -> key << "\n";
  }
}

Node* Minimum(Node* &x){
   while(x -> left != NULL){
     x = x -> left;
   }
   return x;
}

void Transplant(Node* &T, Node* &u, Node* &v){
  if(u -> p == NULL){
    T = v; 
  }
  else if(u == u -> p -> left){
     u -> p -> left = v;
  }
  else{
    u -> p -> right = v;
  }
  if(v != NULL){
     v -> p = u -> p;
  }
}

Node* Search(Node* &x, int k){
   if(x == NULL || k == x->key){
		return x;
	}
	if(k < x -> key){
		return Search(x -> left, k);
	}
	else return Search(x -> right, k);
}

void Delete(Node* &T, int z){
  Node* za = Search(T, z);
  if(za -> left == NULL){
     Transplant(T, za, za -> right);
  }
  else if(za -> right == NULL){
     Transplant(T, za, za -> left);
  }
  else{ 
    Node* y = Minimum(za -> right);
    if(y -> p != za){
       Transplant(T, y, y -> right);
       y -> right = za -> right; 
       y -> right -> p = y;
    }
    Transplant(T, za, y);
    y -> left = za -> left;
    y -> left -> p = y;
  }
}

Node* Insert(Node* &T, int z){
  Node* y = NULL;
  Node* x = T;
  Node* za = new Node();
  za -> key = z;
  
  while(x != NULL){
    y = x; 
    if(za -> key < x -> key){
      x = x -> left;
    }
    else{
      x = x -> right;
    }
  }
  za -> p = y; 
  if(y == NULL){
    T = za;
  }
  else if(za -> key < y -> key){
    y -> left = za;
  }
  else{
    y -> right = za;
  }
}

int main(int argc,char **argv) {
  Node *root = NULL;
  // Using a fixed size buffer for reading content is not always safe, 
  // but ok here because we know how our input has to be:
  char line[100];

  // Main loop
  while ( std::cin.getline(line,100) ){
    string str(line);
    if ( str.size()==0 ) continue; 
    if ( str[0]=='e' ) return 1;

    // Use cerr if you want to always print to the console, because cout
    // will be redirected to the output file when calling the Grade script:
    // cerr<<line<<endl;

    if ( str[0]=='o' ){
      if ( str.substr(0,3)=="oin" ){ 
        // Todo: in-order-traversal  
        oin(root);
      }
      else if ( str.substr(0,4)=="opre" ){
        // Todo: pre-order-traversal
        opre(root);
      }
      else if (str.substr(0,5) == "opost"){
        // Todo: post-order-traversal
        opost(root);
      }
     }
     else
     { int key;
       stringstream convert_stm(str.substr(1,str.size()-1));
       if ( !(convert_stm>>key) ) key = -1; // invalid

       if (str.substr(0,1) == "i") Insert(root, key); // Todo: insert key
       else
       if (str.substr(0,1) == "d") Delete(root, key); // Todo: delete key
     }
  }
    
  return 1;
}