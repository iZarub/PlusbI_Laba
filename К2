#include<iostream>
#include<vector>
#include<cmath>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::getline;

struct stack {
	int value;
	stack* next;
	int s;
};

void add_top(stack** top, int value) {

	if (*top == NULL) {
		*top = (stack*)malloc(sizeof(stack));
		(*top)->value = value;
		(*top)->next = NULL;
	}
	else {
		stack* a;
		a = (stack*)malloc(sizeof(stack));
		a->value = value;
		a->next = *top;
		*top = a;

	}
}



void pop_top(stack** top) {
	stack* a = *top;
	*top = a->next;
	free(a);

}



void print(stack* top) {
	stack* a = top;

	while (a != NULL) {
		cout << a->value << " ";
		a = a->next;
	}
}

int main() {
	std::string input;


	stack* top;
	top = NULL;
	
	


	while (cin >> input) {
		if (input == "+") {
			int q = top->value;
			pop_top(&top);
			int p = top->value;
			pop_top(&top);
			add_top(&top, p + q);


		}
		else if (input == "-") {
			int q = top->value;
			pop_top(&top);
			int p = top->value;
			pop_top(&top);
			add_top(&top, p - q);


		}
		else if (input == "/") {
			int q = top->value;
			pop_top(&top);
			int p = top->value;
			pop_top(&top);
			add_top(&top, p / q);
		
		
		}


		else if (input == "*") {
			int q = top->value;
			pop_top(&top);
			int p = top->value;
			pop_top(&top);
			add_top(&top, p * q);

		}
		else {
			int a = std::stoi(input);
			add_top(&top, a);
		}

	}

	print(top);

	return 0;
}
