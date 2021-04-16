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
                balance_tree(node);
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
                balance_tree(node);
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


    int get_height(Tree* node) {        //Depth of subtree
        if (node == nullptr) {
            return 0;
        }
        return std::max(get_height(node->left), get_height(node->right)) + 1;
    }

    


    void left_small_rot(Tree* node) {
        Tree* b = node->right;
        node->right = b->left;
        if (b->left != nullptr) {
            b->left->parent = node;
        }
        b->left = node;
        node->parent = b;
    }

    void right_small_rot(Tree* node) {
        Tree* b = node->left;
        node->left = b->right;
        if (b->right != nullptr) {
             b->right->parent = node;
        }
        b->right = node;
        node->parent = b;
    }


    void balance(Tree* node) { 
        cout << "Flag";
        if ((node->left) != nullptr and (node->right) != nullptr) {
            //cout << "Flag";
            if ((get_height(node->right->left) <= get_height(node->right->right)) and (get_height(node->right->right) == get_height(node->left) + 2)) {  //Left small rotation
                left_small_rot(node);
            }
            else if ((get_height(node->left->right) <= get_height(node->left->left)) and (get_height(node->left->left) == get_height(node->right) + 2)) {  //Right small rottation
                right_small_rot(node);
            }
            else if ((get_height(node->right->right) == get_height(node->left) + 1) and (get_height(node->right->left) == get_height(node->left) + 2)) { //Left big rotation
                right_small_rot(node->right);
                left_small_rot(node);
            }
            else if ((get_height(node->left->left) == get_height(node->right) + 1) and (get_height(node->left->right) == get_height(node->right + 2))) { //Right big rotation
                left_small_rot(node->left);
                right_small_rot(node);
            }
        }
        else if ((node->right == nullptr) and (node->left != nullptr)) {
            //cout << "Flag";
            if ((get_height(node->left->right) <= get_height(node->left->left)) and (get_height(node->left->left) == get_height(node->right) + 2)) {  //Right small rottation
                right_small_rot(node);
            }
            else if ((get_height(node->left->left) == get_height(node->right) + 1) and (get_height(node->left->right) == get_height(node->right + 2))) { //Right big rotation
                right_small_rot(node);
            }
        }
        else if ((node->left == nullptr) and (node->right != nullptr)) { //работаем тут
            //if ((get_height(node->right->left) <= get_height(node->right->right)) and (get_height(node->right->right) == get_height(node->left) + 2)) {  //Left small rotation
                //left_small_rot(node);
            //}
            if (((get_height(node->left) - get_height(node->right) == -2) and (get_height(node->right->left) - get_height(node->right->right) == -1)) or 
                ((get_height(node->left) - get_height(node->right) == -2) and (get_height(node->right->left) - get_height(node->right->right) == 0))) {
                left_small_rot(node);
                cout << "Flag";
            }
            else if ((get_height(node->right->right) == get_height(node->left) + 1) and (get_height(node->right->left) == get_height(node->left) + 2)) { //Left big rotation
                left_small_rot(node);
            }
        }
        else {} 
    
    }


    void balance_tree(Tree* node) { // Balance from bottom to top
        while (node->parent != nullptr){
            if (abs(get_height(node->left) - get_height(node->right)) >= 2) {
                balance(node);
            }
            node = node->parent;
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
    //vector<int>arr = {6, 12, 14};
    //vector<int>arr = { 20, 8, 7, 6, 15, 17, 11, 13, 12, 9, 10 };
    vector<int>arr = { 1, 2, 3, 4, 5, 6 ,7 ,8  , 9 };
    //vector<int>arr = { 8, 10, 9, 13, 12, 14 };
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
    //cout << (tr1.find_value(node, 12)->left->value);


    tr1.get_tree(node);
}
