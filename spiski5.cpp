#include <iostream>
using std::cin;
using std::cout;
using std::endl;

struct Node{
    int value;
    struct Node* next;


};


void remove_all(Node** head, int value){
    Node* curr = *head;
    Node* index = *head;

    if (curr -> value  == value){
        *head = curr->next;
        free(curr);
    }


    while (index->next != NULL){

        if ((index->next)->value == value){
            Node* temp = index->next;
            index->next = index->next->next;
            free(temp);
        }

        else {
        index = index->next;
        };
    }
}
