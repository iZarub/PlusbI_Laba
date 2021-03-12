#include <iostream>
using std::cin;
using std::cout;
using std::endl;



typedef struct Node {
	int value;
	struct Node* next;
};



int pop(Node** head, int index) {

	Node* curr = *head;
	Node* temp = curr;

	
	if (index == 1) {
		int s = curr->value;
		*head = curr->next;
		free(curr);
		return s;
	}
	else {
		for (int i = 1; i < index; i++) {
			temp = curr;
			curr = curr->next;
		}
		temp->next = curr->next;
		int s = curr->value;
		free(curr);
		return s;
	}
	
}
