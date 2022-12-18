#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//Pseudocode from book
//Priority queue from cppreference

struct nodes{
    char node;
    int frequency;
    nodes* left;
    nodes* right;
public:
	nodes(){
		node = ' ';
		frequency = 0;
	}
    nodes(char name, int frequency) {
        this->node = name;
		this->frequency = frequency;
    }
};

struct compare{
    bool operator()(nodes* left, nodes* right) {
        return (left->frequency > right->frequency);
    }
};

void print(nodes* temp, string s, char chars[], int size, string binary[]){
	if(temp == NULL){
		return;
	}
	else if(temp->node == '\n'){
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
    nodes* x;
    nodes* y;
    nodes* z;
    int i = 0;
    priority_queue <nodes*, vector <nodes*>, compare> queue;
    
	for(i = 0; i < size; i++){
        nodes* temp = new nodes(chars[i], arr[i]);
        queue.push(temp);
    }
    
    while(queue.size() > 1){
        x = queue.top();
        queue.pop();
        y = queue.top();
        queue.pop();
        z = new nodes('\n', x->frequency + y->frequency);
        z->left = x;
        z->right = y;
        queue.push(z);
    }
    
    string s = "";
    cout << queue.top();
    print(queue.top(), s, chars, size, binary);
    
}

int main(){
    int arr[7];
    string binary[7];
    char chars[7];
    int i = 0;
	
	for(i = 0; i < 6; i++){
        cin >> arr[i];
    }
    
    i = 0;
	//char a = 65 -> A in ascii and so on and so forth
    for(int a = 65; a < 71; a++){
        chars[i] = (char) a;
        i++;
    }
    
    Huffman(arr, chars, 6, binary);
    
    i = 0;
    for(i = 0; i < 6; i++){
        cout << chars[i] << ":" << binary[i] << endl;
    }
    return 0;
}