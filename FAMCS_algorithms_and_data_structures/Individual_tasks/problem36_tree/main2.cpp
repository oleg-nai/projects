#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#pragma comment(linker, "/STACK:16777216")

using namespace std;

struct tree {
    int data;
    bool left_visited;
    bool right_visited;

    tree *left = nullptr;
    tree *right = nullptr;

    tree(int val){
        data = val;
        left_visited = false;
        right_visited = false;
    }
};


tree *up_to_date = nullptr;
tree *head_maxNode = nullptr;
tree *root = nullptr;

void myPush(int val, stack<tree*> &tree_without_r) {
    if (root == nullptr) {
        root = new tree(val);
        up_to_date = root;
    } 
    else {
        if (val < up_to_date->data) {
            up_to_date->left = new tree(val);
            tree_without_r.push(up_to_date);
            up_to_date = up_to_date->left;
        } 
        else {
            while (!tree_without_r.empty() && tree_without_r.top()->data <= val) {
                up_to_date = tree_without_r.top();
                tree_without_r.pop();
            }
            up_to_date->right = new tree(val);
            up_to_date = up_to_date->right;
        }
    }
}

// обход дерева
void inOrderOutput(ofstream& fout){
    stack<tree*> myStack;
    myStack.push(root);
    while (!myStack.empty()) {
        tree* up_to_date = myStack.top();

        if (up_to_date != nullptr)
            if (up_to_date->left_visited) {
                up_to_date->left_visited = false;
                myStack.push(up_to_date->left);
            } 
            else if (up_to_date->right_visited) {
                fout << up_to_date->data;
                if (up_to_date != head_maxNode) {
                    fout << " ";
                }
                up_to_date->right_visited = false;
                myStack.push(up_to_date->right);
            } 
            else {
                myStack.pop();
            } 
        else
            myStack.pop();
    }
}

// обход дерева 
void postOrderOutput(ofstream& fout){
    stack<tree*> myStack;
    
    myStack.push(root);

    while (!myStack.empty()) {
        
        tree* temp = myStack.top();
        if (temp != nullptr) {
            if (!temp->left_visited) {
                temp->left_visited = true;
                myStack.push(temp->left);
            } 
            else if (!temp->right_visited) {
                temp->right_visited = true;
                myStack.push(temp->right);
            } 
            else {
                fout << temp->data;
                if (temp != root) 
                    fout << " ";
                myStack.pop();
            }
        } 
        else 
            myStack.pop();
    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    size_t n; // число вернин
    fin >> n;

    stack<tree*> tree_without_r;
    for (size_t i = 0; i < n; ++i) {
        int element;
        fin >> element;
        myPush(element, tree_without_r);
    }

    head_maxNode = root;
    while (head_maxNode->right != nullptr) {
        head_maxNode = head_maxNode->right;
    }

    // output info
    postOrderOutput(fout);
    fout << endl;
    inOrderOutput(fout);
}