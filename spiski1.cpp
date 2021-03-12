#include <iostream>
using std::cin;
using std::cout;
using std::endl;

typedef struct Node {
	int value;
	struct Node* next;
};

void push_left(Node** head, int value) {
	if (*head == NULL) {
		*head = (Node*)malloc(sizeof(Node));
		(**head).value = value;
		(*head)->next = NULL;
	}
	else {
		Node* a = (Node*)malloc(sizeof(Node));
		a->value = value;
		a->next = *head;
		*head = a;
	}
}
int main() {
	
	Node* head;
	head = NULL;
	for (int i = 0; i < 6; ++i) {
		push_left(&head, 2);
		cout << (*head).value;
	}
    return 0;
}
