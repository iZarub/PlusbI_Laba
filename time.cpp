#include<iostream>
#include<string>
#include<fstream>
#include<string>
#include<sstream>
#include<chrono>
#include<list>

using std::cout;
using std::cin;
using std::string;
using namespace std::chrono;


void output(string name, string file) {
	std::ofstream resout(file, std::ios::app);
		if (resout.is_open()) {
			resout << name << std::endl;
		}
	resout.close();
}



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


	void push_front(int d) {
		if (size == capacity) {
			size = size + 1;
			capacity = 2 * capacity;
			mas = (int*)realloc(mas, capacity * sizeof(int));
			int* temp = (int*)malloc(capacity * sizeof(int));
			for (int i = 0; i < size - 1; i++) {
				temp[i + 1] = mas[i];


			}
			temp[0] = d;

			for (int i = 0; i < size; i++) {
				mas[i] = temp[i];
			}


		}

		else {
			int* temp = (int*)malloc(capacity * sizeof(int));
			size = size + 1;
			for (int i = 0; i < size - 1; i++) {
				temp[i + 1] = mas[i];


			}
			temp[0] = d;

			for (int i = 0; i < size; i++) {
				mas[i] = temp[i];
			}

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
	vector v2;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N + 1; i++) {
		auto start = std::chrono::high_resolution_clock::now();
		v1.push_back(1);
		auto end = std::chrono::high_resolution_clock::now();
		nanoseconds fs = duration_cast<nanoseconds>(end - start);

		output(std::to_string(fs.count()), "push_back_vec.txt");
	}





	for (int i = 0; i < M + 1; i++) {
		auto start = std::chrono::high_resolution_clock::now();
		v2.push_front(1);
		auto end = std::chrono::high_resolution_clock::now();
		nanoseconds fs = duration_cast<nanoseconds>(end - start);

		output(std::to_string(fs.count()), "push_front_vec.txt");

	}



	for (int i = 0; i < N + 1; i++) {
		auto start = std::chrono::high_resolution_clock::now();
		v1.pop_back();
		auto end = std::chrono::high_resolution_clock::now();
		nanoseconds fs = duration_cast<nanoseconds>(end - start);

		output(std::to_string(fs.count()), "pop_back_vec.txt");

	}

	std::list<int> list1;
	for (int i = 0; i < N + 1; i++) {
		auto start = std::chrono::high_resolution_clock::now();
		list1.push_back(1);
		auto end = std::chrono::high_resolution_clock::now();
		nanoseconds fs = duration_cast<nanoseconds>(end - start);

		output(std::to_string(fs.count()), "push_back_list.txt");

	}

	std::list<int> list2;
	for (int i = 0; i < M + 1; i++) {
		auto start = std::chrono::high_resolution_clock::now();
		list2.push_front(1);
		auto end = std::chrono::high_resolution_clock::now();
		nanoseconds fs = duration_cast<nanoseconds>(end - start);
		output(std::to_string(fs.count()), "push_front_list.txt");

	}
	
	
}
