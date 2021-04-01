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


		for (int i = 0; i < N - 1; i++) {
			int min;
			int k;
			for (int j = i + 1; j < N; j++) {
				if (arr[j] < arr[i]) {
					min = arr[j];
					arr[j] = arr[i];
					arr[i] = min;

				}

			}


		}

		auto end = std::chrono::high_resolution_clock::now();
		nanoseconds fs = duration_cast<nanoseconds > (end - start);
		output(std::to_string(fs.count()), "vstavka.txt");


		delete[] arr;

	}

}
