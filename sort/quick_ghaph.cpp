#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<fstream>
#include<string>
#include<sstream>
#include<chrono>
#include <cstdlib>

using namespace std::chrono;
using std::cout;
using std::cin;
using std::string;

int* sort(int* arr, int start, int stop) {
	int i = start;
	int j = stop;
	int num = arr[(i + j) / 2];
	int baza;


	while (i <= j) {
		while (arr[i] < num) {
			i++;
		}

		while (arr[j] > num) {
			j--;
		}

		if (i <= j) {

			baza = arr[i];
			arr[i] = arr[j];
			arr[j] = baza;
			i++;
			j--;
		}
	}

	if (j >= start) {
		sort(arr, start, j);
	}

	if (i <= stop) {
		sort(arr, i, stop);
	}

	return arr;
}



void output(string name, string file) {
	std::ofstream resout(file, std::ios::app);
	if (resout.is_open()) {
		resout << name << std::endl;
	}
	resout.close();
}



int main() {
	int N;

	for (int N = 0; N <= 1000; N++) {
		
		int* arr;
		arr = new int[N];

		for (int i = 0; i < N; i++) { 
			int a;
			a = rand();
			arr[i] = a;
		}



		auto start = std::chrono::high_resolution_clock::now();


		sort(arr, 0, N - 1);


		auto end = std::chrono::high_resolution_clock::now();
		nanoseconds fs = duration_cast<nanoseconds > (end - start);
		output(std::to_string(fs.count()), "quick.txt");


		delete[] arr;

	}

}
