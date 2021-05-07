#include <iostream>
#include <fstream>
using namespace std;

class Node{
    public:

    long int Key;
    Node* Left = nullptr;
    Node* Right = nullptr;

    static void DestroyNode(Node* node) {
        if(node) { 
            DestroyNode(node->Left);
            DestroyNode(node->Right);
            delete node;
        }
    }


    Node * addNode(int key, Node* node) {
        if(node == nullptr) {
            node = new Node; 
            node->Key = key;
            node->Left = nullptr;
            node->Right = nullptr;
        } else if (key < node->Key)
            node->Left = addNode(key, node->Left);
        else if(key > node->Key)
            node->Right = addNode(key, node->Right);
        return node;
    }


    friend ostream& operator << (ostream& os, Node* node)	// method of insert, operator overload >> like friendly functions	
    {
        if(node != nullptr) {
            os << node->Key << '\n';
            os << node->Left;
            os << node->Right;
        }
        return os;
    }
};



int main() {

    Node* root = nullptr;
    long int n = 0;
    ifstream fin;
    fin.open("C:\\Users\\programming\\cpp-examples\\fpmi-algos\\0.1\\input.txt");
    while (fin >> n) {
        root = root->addNode(n, root);
        }


    ofstream fout;
    fout.open("C:\\Users\\programming\\cpp-examples\\fpmi-algos\\0.1\\output.txt");
    fout << root;        
    return 0;

}