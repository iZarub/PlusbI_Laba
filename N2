#include <iostream>
using std::cin;
using std::cout;
using std::endl;


//Реализуйте функцию очистки списка.С освобождением памяти и записью NULL в указатель на первый элемент :


typedef struct Node {
	int value;
	struct Node* next;
};



void clear_list(Node** head) {
    Node* curr = *head;

    while (curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        free(temp);

    }
    *head = NULL;
}
