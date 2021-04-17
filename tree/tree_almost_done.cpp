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
    int right_balance;
    int left_balance;
    int node_balance;



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
                insert_balance(node);
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
                insert_balance(node);
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
                insert_balance(parent);
            }else{
                parent->right = nullptr;
                delete elem;
                insert_balance(parent);
            }  
        }else if (elem->right == nullptr) {   
            if (elem->value > parent->value) {
                parent->right = elem->left;
                elem->left->parent = elem->parent;
                elem = nullptr;
                delete elem;
                insert_balance(parent);
            }else {
                parent->left = elem->left;
                elem->left->parent = elem->parent;
                elem = nullptr;
                delete elem;
                insert_balance(parent);
            }
        }else if (elem->left == nullptr) {  
            if (elem->value <= parent->value) {
                parent->left = elem->right;
                elem->right->parent = elem->parent;
                elem = nullptr;
                delete elem;
                insert_balance(parent);
            }else {
                parent->right = elem->right;
                elem->right->parent = elem->parent;
                elem = nullptr;
                delete elem;
                insert_balance(parent);
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
                insert_balance(parent);
            }else {                          
                elem->value = min->value;
                min->parent->right = min->right;
                if (min->right != nullptr) {
                    min->right->parent = elem;
                }else {
                    min->parent = elem;
                }
                delete min;
                insert_balance(parent);
            }
        }
    }


    int get_height(Tree* node) {        //Depth of subtree
        if (node == nullptr) {
            return 0;
        }
        return std::max(get_height(node->left), get_height(node->right)) + 1;
    }


    void balance(Tree* node){
        node->node_balance = get_height(node->left) - get_height(node->right);

        if (node->right == nullptr) {
            node->right_balance = 0;
        }else {
            node->right_balance = get_height(node->right->left) - get_height(node->right->right);
        }

        if (node->left == nullptr) {
            node->left_balance = 0;
        }else {
            node->left_balance = get_height(node->left->left) - get_height(node->left->right);
        }


        if (node->node_balance == -2) {
            if ((node->right_balance == -1) or (node->right_balance == 0))  {
                left_small_rot(node);
            }
            else {
                big_left_rot(node);

            }
        }
        else if (node->node_balance == 2) {
            if ((node->left_balance == 1) /*or (node->left_balance == 0)*/) { //Возможно убрать ноль!
                right_small_rot(node);
            }   
            else {
                big_right_rot(node);
            }
        }

        else {}
    }
    

    void insert_balance(Tree* node) {
        do {
            balance(node);
            
            node = node->parent;
        } while (node != nullptr);
    }
    
    

    void big_left_rot(Tree* node) {
        Tree* q = node->right->left->left;
        Tree* c = node->right->left;
        Tree* b = node->right;
        Tree* parent = node->parent;
        b->left = c->right;
        if (c->right != nullptr) {
            c->right->parent = b;
        }
        c->right = b;
        b->parent = c;
        if (node->parent != nullptr) {
            if (node->parent->left == node) {
                node->parent->left = c;
            }
            else {
                node->parent->right = c;
            }
        }
        c->left = node;
        node->parent = c;
        node->right = q;
        if (q != nullptr) {
            q->parent = node;
        }
        c->parent = parent;    
    }


    void big_right_rot(Tree* node) {
        Tree* q = node->left->right->right;
        Tree* c = node->left->right;
        Tree* b = node->left;
        Tree* parent = node->parent;
        b->right = c->left;
        if (c->left != nullptr) {
            c->left->parent = b;
        }
        c->left = b;
        b->parent = c;
        if (node->parent != nullptr) {
            if (node->parent->left == node) {
                node->parent->left = c;
            }
            else {
                node->parent->right = c;
            }
        }
        c->right = node;
        node->parent = c;
        node->left = q;
        if (q != nullptr) {
            q->parent = node;
        }
        c->parent = parent;
    
    }


    void left_small_rot(Tree* node) {
        Tree* b = node->right;
        node->right = b->left;
        if (b->left != nullptr) {
            b->left->parent = node;
        }
        if (node->parent != nullptr) {
            if (node->parent->left == node) {
                node->parent->left = b;
            }
            else {
                node->parent->right = b;
            }
            
        }
        
        b->parent = node->parent;
        
        b->left = node;
        node->parent = b;
        
    }


    void right_small_rot(Tree* node) {
        Tree* b = node->left;
        node->left = b->right;

        if (b->right != nullptr) {
             b->right->parent = node;
        }
        if (node->parent != nullptr) {
            if (node->parent->left == node) {
                node->parent->left = b;
            }
            else {
                node->parent->right = b;
            }
        }
        b->parent = node->parent;

        b->right = node;
        node->parent = b;
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
    //vector<int>arr = {4, 6, 5, 8, 7, 9};
    //vector<int> arr = { 6, 3, 12, 4, 1, 10, 8, 9, 2, 5, 7 };
    //vector<int>arr = {6, 7, 8, 9};
    //vector<int>arr = { 20, 8, 7, 6, 15, 17, 11, 13, 12, 9, 10 };
    //vector<int>arr = {1, 2, 3, 4, 5, 6 ,7 ,8, 9, 10, 11, 12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49};
    //vector<int>arr = { 8, 10, 9, 13, 12, 14 };
    //vector<int>arr = { 17, 66, 85, 34, 58, 70, 54, 19, 15, 1 };
    vector<int>arr = { 10, 6, 4, 8, 9};
    Tree* node = new Tree;
    node->value = arr[0];
    node->left = nullptr;
    node->right = nullptr;
    node->parent = nullptr;
    for (int i = 1; i < arr.size(); ++i) {
        tr1.insert(node, arr[i]);
        while (node->parent != nullptr) {
            node = node->parent;
        }
        tr1.get_tree(node);
        cout << std::endl;
        cout << node->value << std::endl;
    }
    
    /*
    tr1.delete_node(node, 19);
    tr1.delete_node(node, 17);
    tr1.delete_node(node, 1);
    while (node->parent != nullptr) {
        node = node->parent;
    }

    tr1.delete_node(node, 34);
    cout << node->left->value << std::endl;
    

    cout << node->value;
    */
    //tr1.get_tree(node);
    cout << std::endl;
    cout << node->right->value;
  
}
