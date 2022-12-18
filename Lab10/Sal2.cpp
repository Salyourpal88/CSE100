#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node{
  char node;
  int frequency;
  Node* left;
  Node* right;
public:
	Node(){
    node = ' ';
    frequency = 0;
	}
    Node(char name, int frequency) {
      this->node = name;
      this->frequency = frequency;
    }
};

struct compare{
    bool operator()(Node* left, Node* right) {
      return (left->frequency > right->frequency);
    }
};

void print(Node* temp, string s, char chars[], int size, string binary[]){
	if(temp->node == '\n'){
      print(temp->left, s + "0", chars, size, binary);
      print(temp->right, s + "1", chars, size, binary);
    }
    else{
		for(int i = 0; i < size; i++){
      if (temp->node == chars[i]) {
        binary[i] = s;
        }
      }
    }
}

void Huffman(int arr[], char chars[], int size, string binary[]) {
  Node* z = new Node();
  Node* x = new Node();
  Node* y = new Node();

  priority_queue <Node*, vector <Node*>, compare> queue;
    
	for(int i = 0; i < size; i++){
      Node* temp = new Node(chars[i], arr[i]);
      queue.push(temp);
    }

    for(int i = 1; i <= size - 1; i++){
      x = queue.top();
      queue.pop();
      y = queue.top();
      queue.pop();
      z = new Node('\n', x->frequency + y->frequency);
      z->left = x;
      z->right = y;
      queue.push(z);
    }
    string s;
    print(queue.top(), s, chars, size, binary);
}

int main(){
  int arr[5];
  string binary[6];
  char chars[6];
  int ascii = 65;
	
	for(int i = 0; i < 6; i++){
    cin >> arr[i];
    chars[i] = (char) ascii;
    ascii++;
    }
    
    Huffman(arr, chars, 6, binary);

    for(int i = 0; i < 6; i++){
      cout << chars[i] << ":" << binary[i] << endl;
    }
    return 0;
}