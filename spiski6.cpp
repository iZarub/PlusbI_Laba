#include <iostream>
using std::cin;
using std::cout;
using std::endl;

struct Node{
    int value;
    struct Node* next;


};


void replace_all(Node* head, int old_value, int new_value) {
    Node* index = head;
    while (index->next != nullptr){
        if (index -> value == old_value){
            index->value = new_value;
        }
        index = index->next;
    }
}
