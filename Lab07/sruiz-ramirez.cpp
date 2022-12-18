#include <iostream>
#include <list>
using namespace std;

class Table{
    private:
    list<int> *HashChain;
    public:
    Table(){
        HashChain = NULL;
    };

  ~Table(){
        if(HashChain != NULL){
            delete [] HashChain;
        }
    }

    void FormTable(int hashSize){
        HashChain = new list<int>[hashSize];   
    }

    void InsertChain(int num, int hashSize){
        HashChain[num % hashSize].push_front(num);
    }
  
    bool DeleteNum(int num, int hashSize){
        list<int> l = HashChain[num % hashSize];
        list<int>::iterator the;
        if(l.empty()){
            return false;
        }
        else{    
            for (the = l.begin(); the != l.end(); ++the){
                if(*the == num){
                    l.erase(the);
                    HashChain[num % hashSize] = l;
                    return true;
                }
            }
        return false;
        }
    }

    void SearchHash(int key, int hashSize){
        list<int> l = HashChain[key % hashSize];
        list<int>::iterator twice;
        int index = 0;
        if(l.empty()){
            cout << key << ":NOT_FOUND;" << "\n";
        } 
        else {
            for (twice = l.begin(); twice != l.end(); ++twice){
                if(*twice == key){
                    cout<< key << ":FOUND_AT" << (key % hashSize) << "," << index << ";" << "\n";
                    return;
                }
                index++;
            }
            cout << key << ":NOT_FOUND;" << endl;   
        }
    }

    void OutputHash(int hashSize){
        list<int> seviper;
        list<int>::iterator lion;
        for(int i = 0; i < hashSize; i++){
            seviper = HashChain[i];
            if(seviper.empty()){
            cout << i << ":;" << endl;
            }
            else {
                cout << i << ":";
                for (lion = seviper.begin(); lion != seviper.end(); ++lion){
                    cout << *lion << "->";
                }
                cout << ";" << endl;   
            }   
        }
    }
};

int main(){
    int hashSize;
    int num;
    cin >> hashSize;
    char rule;

    Table table;
    table.FormTable(hashSize);
    cin >> rule;
    
    while(rule != 'e'){
        if(rule == 'i'){
            cin >> num;
            table.InsertChain(num, hashSize);
        } 

        else if(rule == 'd'){
            cin >> num;
            if(table.DeleteNum(num, hashSize)){
                cout << num << ":DELETED;" << endl;
            } 
            else {
                cout << num << ":DELETE_FAILED;" << endl;
            }
        } 

        else if(rule == 's'){
            cin >> num;
            table.SearchHash(num, hashSize);
        } 

        else if(rule == 'o'){
            table.OutputHash(hashSize);
        }
        cin >> rule;
    }
    return 0;
}