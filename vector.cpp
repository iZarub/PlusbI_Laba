#include<iostream>
#include<string>
#include<fstream>
#include<string>
#include<sstream>
using std::cout;
using std::cin;
using std::string;


struct vector {
	int* mas;
	unsigned int size;
	unsigned int capacity;

public:

	vector() {

		capacity = 1;
		size = 0;
		mas = (int*)malloc(capacity * sizeof(int));

	}


	~vector() {
		capacity = 0;
		size = 0;
		free(mas);
		mas = (int*)malloc(sizeof(int*));
	}



	void push_back(int d) {

		if (size == capacity) {
			capacity = 2 * capacity;
			mas = (int*)realloc(mas, capacity* sizeof(int));
			mas[size] = d;
			size = size + 1;
		}

		else {
			mas[size] = d;
			size = size + 1;
		}
	}



	void pop_back() {
		size = size - 1;
	}


	
	void realize(int new_capacity) {
		int a = log2(new_capacity) + 1;
		a = pow(2,a);
		capacity = a;
		cout << capacity;
		mas = (int*)realloc(mas, capacity * sizeof(int));
	}


	void shrink_to_fit() {
		int a = log2(size) + 1;
		a = pow(2, a);
		capacity = a;
		cout << capacity;
		mas = (int*)realloc(mas, capacity * sizeof(int));
	
	
	
	}

	void clear() {
		size = 0;
		
	}


	void input_from_file(string URL)
		{
			std::ifstream file(URL);
			string line{};
			string number{};
			while (getline(file, line))
			{
				std::stringstream strStream(line);
				while (getline(strStream, number, ','))
				{
					if (size == capacity)
					{
						mas = (int*)realloc(mas, 2 * capacity * sizeof(int));
						capacity *= 2;
						mas[size] = atoi(number.c_str());
						size += 1;
					}
					else
					{
						mas[size] = atoi(number.c_str());
						size += 1;
					}
				}
			}
		}	
	


	void GetVector(){
		for (int i = 0; i < size; i++) {
			cout << mas[i] << " ";
		}

	
	}




};


int main() {
	vector v1;
	v1.input_from_file("dano.txt");




	v1.GetVector();
	
}
