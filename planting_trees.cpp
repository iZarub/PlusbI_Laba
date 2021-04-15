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
            }else {
                Tree* next = new Tree;
                next->value = value;
                node->left = next;
                next->left = nullptr;
                next->right = nullptr;
                next->parent = node;
            }   
        }
        if (value > node->value) {
            if (node->right != nullptr) {
                insert(node->right, value);
            }else {
                Tree* next = new Tree;
                next->value = value;
                node->right = next;
                next->left = nullptr;
                next->right = nullptr;
                next->parent = node;
            } 
        }
    }


    Tree* find_value(Tree* node, int value) {
        if (node->value > value) {
            return find_value(node->left, value);
        }
        if (node->value < value) {
            return find_value(node->right, value);
        }
        if (node->value == value) {
            return node;
        }else { return nullptr; }    
    }


    Tree* find_right_min(Tree* node) {
        Tree* min = node->right;
        while (min->left != nullptr) {
            min = min->left;
        }
        return min;
    }


    void delete_node(Tree* node, int value) {
        Tree* elem = find_value(node, value);
        Tree* parent = elem->parent;
        if ((elem->right == nullptr) and (elem->left == nullptr)) {
            if (elem->value <= parent->value) {
                parent->left = nullptr;
                delete elem;
            }else{
                parent->right = nullptr;
                delete elem;
            }  
        }else if (elem->right == nullptr) {
            if (elem->value > parent->value) {
                parent->right = elem->left;
                elem->left->parent = elem->parent;
                elem = nullptr;
                delete elem;
            }else {
                parent->left = elem->left;
                elem->left->parent = elem->parent;
                elem = nullptr;
                delete elem;
            }
        }else if (elem->left == nullptr) {
            if (elem->value <= parent->value) {
                parent->left = elem->right;
                elem->right->parent = elem->parent;
                elem = nullptr;
                delete elem;
            }else {
                parent->right = elem->right;
                elem->right->parent = elem->parent;
                elem = nullptr;
                delete elem;
            }
        }else {
            Tree* min = find_right_min(elem);
            if (elem->right != min) {
                elem->value = min->value;
                min->parent->left = min->right;
                if (min->right != nullptr) {
                    min->right->parent = min->parent;
                }else {
                    min->parent->left = nullptr;
                }
                
                delete min;
            }else {
                elem->value = min->value;
                min->parent->right = min->right;
                if (min->right != nullptr) {
                    min->right->parent = elem;
                }else {
                    min->parent = elem;
                }
                delete min;
            }
        }
    }


    void get_tree(Tree* node) {
        if (node->left != nullptr) {
            get_tree(node->left);
        }
        cout << node->value << " ";
        if (node->right != nullptr) {
            get_tree(node->right);
        }
    }
};




int main() {
    Tree tr1;
    //vector<int> arr = { 6, 3, 12, 4, 1, 10, 8, 9, 2, 5, 7 };
    //vector<int>arr = { 6, 12, 14, 13 };
    vector<int>arr = { 20, 8, 7, 6, 15, 17, 11, 13, 12, 9, 10 };
    Tree* node = new Tree;
    node->value = arr[0];
    node->left = nullptr;
    node->right = nullptr;
    node->parent = nullptr;
    for (int i = 1; i < arr.size(); ++i) {
        tr1.insert(node, arr[i]);
    }

    
    
    tr1.get_tree(node);
    cout << std::endl;

    tr1.delete_node(node, 8);
    tr1.delete_node(node, 11);
    tr1.delete_node(node, 12);
    tr1.delete_node(node, 15);
    tr1.delete_node(node, 17);
    tr1.delete_node(node, 9);
    tr1.delete_node(node, 6);
    tr1.delete_node(node, 10);


    tr1.get_tree(node);
}
