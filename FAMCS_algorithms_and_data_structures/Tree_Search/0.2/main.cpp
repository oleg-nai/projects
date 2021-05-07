#include <iostream>
#include <fstream>
using namespace std;

class Node{
    public:

    long long int Key;
    Node* Left = nullptr;
    Node* Right = nullptr;

    Node * addNode(long long int key, Node* node) {
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

    Node * findMinKey(Node * node){
        if (node->Left != nullptr)
            return findMinKey(node->Left);
        else
            return node;
    }
    
    Node * delete_elem(long long int key, Node* node) {
        if(node == nullptr)
            return node;
        if (key < node->Key) {
            node->Left = delete_elem(key, node->Left);
            return node;
        }
        else if (key > node->Key){
            node->Right = delete_elem(key, node->Right);
            return node;
        }

        // node.Key == key
        if(node->Left == nullptr){
            return node->Right;
        }
        else if (node->Right == nullptr) {
            return node->Left;
        }
        else { // both subtrees exists
            long long int minKey = findMinKey(node->Right)->Key;
            node->Key = minKey;
            node->Right = delete_elem(minKey, node->Right);
            return node;
        }
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
    long long int n = 0;
    long long int toDelete = 0;

    ifstream fin;
    fin.open("C:\\Users\\programming\\fpmi-algos\\0.2\\input.txt");
    fin >> toDelete;
    while (fin >> n) {
        root = root->addNode(n, root);
    }
    fin.close();

    root = root->delete_elem(toDelete, root);

    ofstream fout;
    fout.open("C:\\Users\\programming\\fpmi-algos\\0.2\\output.txt");
    fout << root; 
    fout.close();

    return 0;
}