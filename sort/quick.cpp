#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using std::vector;
using std::cout;
using std::cin;



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

	sort(arr, 0, N-1);

	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";

	}

}
