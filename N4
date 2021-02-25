#include <iostream>
using std::cin;
using std::cout;
using std::endl;



typedef struct Node {
	int value;
	struct Node* next;
};

void remove(Node** head, int value) {
	Node* curr = *head;
	Node* temp = curr;

	if (curr->value == value) {
		*head = curr->next;
		free(curr);
	}

	else {
		while (curr->value != value) {
			temp = curr;
			curr = curr->next;

		}

		temp->next = curr->next;
		free(curr);
	
	}

}
