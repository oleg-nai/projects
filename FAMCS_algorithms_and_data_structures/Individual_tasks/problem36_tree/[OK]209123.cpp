#include <fstream>
#include <stack>

struct tree {
    tree *left = nullptr,
            *right = nullptr;
    int data;
    bool left_visited;
    bool right_visited;

    explicit tree(int value): data(value){
        left_visited = false;
        right_visited = false;
    }
};

tree *root = nullptr;
tree *up_to_date = nullptr;
tree *head_maxNode = nullptr;


void myPush(int value, std::stack<tree*> &nodesWithoutRight) {
    if (root == nullptr) {
        root = new tree(value);
        up_to_date = root;
    } else {
        if (value < up_to_date->data) {
            up_to_date->left = new tree(value);
            nodesWithoutRight.push(up_to_date);
            up_to_date = up_to_date->left;
        } else {
            while (!nodesWithoutRight.empty() && nodesWithoutRight.top()->data <= value) {
                up_to_date = nodesWithoutRight.top();
                nodesWithoutRight.pop();
            }
            up_to_date->right = new tree(value);
            up_to_date = up_to_date->right;
        }
    }
}

void inOrder(std::ofstream& out) noexcept {
    std::stack<tree*> stack;
    stack.push(root);
    while (!stack.empty()) {
        tree* up_to_date = stack.top();
        if (up_to_date != nullptr) {
            if (up_to_date->left_visited) {
                up_to_date->left_visited = false;
                stack.push(up_to_date->left);
            } else if (up_to_date->right_visited) {
                out << up_to_date->data;
                if (up_to_date != head_maxNode) {
                    out << " ";
                }
                up_to_date->right_visited = false;
                stack.push(up_to_date->right);
            } else {
                stack.pop();
            }
        } else {
            stack.pop();
        }
    }
}

void postOrder(std::ofstream& out) noexcept {
    std::stack<tree*> stack;
    stack.push(root);
    while (!stack.empty()) {
        tree* currentNode = stack.top();
        if (currentNode != nullptr) {
            if (!currentNode->left_visited) {
                currentNode->left_visited = true;
                stack.push(currentNode->left);
            } else if (!currentNode->right_visited) {
                currentNode->right_visited = true;
                stack.push(currentNode->right);
            } else {
                out << currentNode->data;
                if (currentNode != root) {
                    out << " ";
                }
                stack.pop();
            }
        } else {
            stack.pop();
        }
    }
}

int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");
    size_t size;
    in >> size;
    std::stack<tree*> nodesWithoutRight;
    for (size_t i = 0; i < size; ++i) {
        int element;
        in >> element;
       myPush(element, nodesWithoutRight);
    }
    head_maxNode = root;
    while (head_maxNode->right != nullptr) {
        head_maxNode = head_maxNode->right;
    }
    postOrder(out);
    out << "\n";
    inOrder(out);
    in.close();
    out.close();
}