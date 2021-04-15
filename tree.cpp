#include<iostream>
#include<vector>


using std::vector;
using std::cout;
using std::cin;


struct Tree {
    int value;
    Tree* left;
    Tree* right;
    Tree* parent;

    void insert(Tree* node, int value) {

        if (value <= node->value) {
            if (node->left != nullptr) {
                insert(node->left, value);
            }
            else {
                Tree* next = new Tree;
                next->value = value;
                node->left = next;
            }
        }
    
        if (value > node->value) {
            if (node->right != nullptr) {
                insert(node->right, value);
            }
            else {
                Tree* next = new Tree;
                next->value = value;
                node->right = next;
            
            }
        }
    }

    void get_tree(Tree* node) {
        if (node->left != nullptr) {
            get_tree(node->left);
        }
        cout << node->value;
        if (node->right != nullptr) {
            get_tree(node->right);
        }
    }


};


   

int main() {
    Tree tr1;
    vector<int> arr = { 6, 3, 12, 4, 1, 10, 8, 9, 2 };
    Tree* node = new Tree;
    node->value = arr[0];
    node->left = nullptr;
    node->right = nullptr;
    for (int i = 1; i < arr.size(); ++i) {
        tr1.insert(node, arr[i]);
    
    }

    tr1.get_tree(node);
}
