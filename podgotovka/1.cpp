#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include <algorithm>

using std::vector;
using std::cout;
using std::cin;
using std::string;



/*
Дан массив чисел, в котором есть хотя бы два элемента. 
Найти пару элементов этого массива, произведение которых максимально. 
Ограничение по времени O(N). ("задача поиска")
*/





int main() {
	vector<int>arr;
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		arr.push_back(a);
	}

	int max1;
	max1 = arr[0];

	for (int i = 1; i < N; i++) {
		if (arr[i] > max1) {
			max1 = arr[i];
		}

	}

	int max2;
	max2 = arr[0];

	for (int i = 1; i < N; i++) {
		if ((arr[i] > max2) and (arr[i] < max1)) {
			max2 = arr[i];
		}
	}

	 
	cout << max1 * max2;


}
