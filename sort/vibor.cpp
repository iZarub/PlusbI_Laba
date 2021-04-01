#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using std::vector;
using std::cout;
using std::cin;


int main() {
	int N;
	cin >> N;
	int* arr;
	arr = new int[N];

	
	for (int i = 0; i < N; i++) { // Ввод
		int a;
		cin >> a;
		arr[i] = a;
	}

	
	for (int i = 0; i < N; i++) { 
		cout << arr[i] << " ";
	
	}

	cout << std::endl;


	for (int i = 0; i < N-1; i++) {
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


	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";

	}

	delete[] arr;


}
