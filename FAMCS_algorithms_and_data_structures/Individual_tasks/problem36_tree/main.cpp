#include <vector>
#include <fstream>
#pragma comment(linker, "/STACK:16777216")

using namespace std;

int number_of_roots = 0;

class Node{
public:
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}

    Node* helper(const vector<int>& preorder, int& id, int limit) {
        if (id == (int) preorder.size() || preorder[id] >= limit)
            return NULL;
        int root_val = preorder[id];
        Node* root = new Node(root_val);
        id++;
        root->left = helper(preorder, id, root_val);
        root->right = helper(preorder, id, limit);
        return root;
    }

    Node* bstFromPreorder(vector<int>& preorder) {
        int id = 0;
        return helper(preorder, id, INT_MAX);
    }

    void postOrder(Node* node, FILE* fout)  
    {  
        if (node == NULL)  
            return;  
        postOrder(node->left, fout);  
        postOrder(node->right, fout);  
        if (number_of_roots-- == 1)
            fprintf(fout, "%d", node->val);
        else
            fprintf(fout, "%d ", node->val);
    }  

    void inOrder(Node* node, FILE* fout)  
    {  
        if (node == NULL)  
            return;  
        inOrder(node->left, fout);  
        if (number_of_roots-- == 1)
            fprintf(fout, "%d", node->val);
        else
            fprintf(fout, "%d ", node->val);
        inOrder(node->right, fout);  
    }  

};

int main() {
    FILE *fin;
    fin = fopen("C:\\Users\\programming\\FAMCS_algorithms_and_data_structures\\problem36\\input.txt", "r");
    FILE *fout;
    fout = fopen("C:\\Users\\programming\\FAMCS_algorithms_and_data_structures\\problem36\\output.txt", "w");

    int n = 0; // number of elem
    fscanf(fin, "%d", &n);
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        fscanf(fin, "%d", &arr[i]);
    }
    
    Node* root = nullptr;
    root = root->bstFromPreorder(arr);

    number_of_roots = n;
    root->postOrder(root, fout);
    number_of_roots = n;
    fprintf(fout, "\n");
    root->inOrder(root, fout);
    
    fclose(fin);
    fclose(fout);
    return 0;

}