#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;
using Clock = chrono::high_resolution_clock;

void bubbleSort(vector<int> &arr) {
	int n = arr.size();
	for (int i = 0; i < n; ++i) {
		bool swapped = false;
		for (int j = 0; j + 1 < n - i; ++j) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}
		if (!swapped) break; 
	}
}

void insertionSort(vector<int> &arr) {
	int n = arr.size();
	for (int i = 1; i < n; ++i) {
		int key = arr[i];
		int j = i;
		while (j > 0 && arr[j - 1] > key) {
			arr[j] = arr[j - 1];
			--j;
		}
		arr[j] = key;
	}
}

void selectionSort(vector<int> &arr) {
	int n = arr.size();
	for (int i = 0; i < n; ++i) {
		int minIdx = i;
		for (int j = i + 1; j < n; ++j) {
			if (arr[j] < arr[minIdx]) minIdx = j;
		}
		if (minIdx != i) swap(arr[i], arr[minIdx]);
	}
}

void merge(vector<int> &arr, int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;
	vector<int> L(n1), R(n2);
	for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
	for (int j = 0; j < n2; ++j) R[j] = arr[mid + 1 + j];
	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) arr[k++] = L[i++];
		else arr[k++] = R[j++];
	}
	while (i < n1) arr[k++] = L[i++];
	while (j < n2) arr[k++] = R[j++];
}

void mergeSortRec(vector<int> &arr, int left, int right) {
	if (left >= right) return;
	int mid = left + (right - left) / 2;
	mergeSortRec(arr, left, mid);
	mergeSortRec(arr, mid + 1, right);
	merge(arr, left, mid, right);
}

void mergeSort(vector<int> &arr) {
	if (!arr.empty())
		mergeSortRec(arr, 0, arr.size() - 1);
}


vector<int> generateRandom(int n, mt19937 &rng) {
	uniform_int_distribution<int> dist(1, static_cast<int>(n));
	vector<int> v(n);
	for (int i = 0; i < n; ++i) v[i] = dist(rng);
	return v;
}

vector<int> generateIncreasing(int n) {
	vector<int> v(n);
	for (int i = 0; i < n; ++i) v[i] = static_cast<int>(i + 1);
	return v;
}

vector<int> generateDecreasing(int n) {
	vector<int> v(n);
	for (int i = 0; i < n; ++i) v[i] = static_cast<int>(n - i);
	return v;
}

vector<int> generateUniform(int n, int value = 5) {
	vector<int> v(n, value);
	return v;
}


template <typename Func>
double measureTime(Func f) {
	auto start = Clock::now();
	f();
	auto end = Clock::now();
	chrono::duration<double, milli> diff = end - start;
	return diff.count();
}


int main() {
	vector<int> sizes = {100, 1000, 10000, 100000};
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


	for (int n : sizes) {
		vector<int> baseRandom = generateRandom(n, rng);
		vector<int> baseIncreasing = generateIncreasing(n);
		vector<int> baseDecreasing = generateDecreasing(n);
		vector<int> baseUniform = generateUniform(n);

		struct Dataset {
			string name;
			vector<int> data;
		};
		
		vector<Dataset> datasets = {
			{"Random", baseRandom},
			{"Increasing", baseIncreasing},
			{"Decreasing", baseDecreasing},
			{"Uniform", baseUniform}
		};

		for (auto &ds : datasets) {
			// Test each algorithm with a copy of the data
            cout<<"Dataset Size: "<<n<<endl;
            cout<<"Type: "<<ds.name<<endl;
			vector<int> arr;
			double timeTaken;
           
			// Bubble Sort
			arr = ds.data;
			timeTaken = measureTime([&]() { bubbleSort(arr); });
			cout<<"Bubble sort time-complexity : " << timeTaken <<" Milliseconds" << endl;

			// Insertion Sort
			arr = ds.data;
			timeTaken = measureTime([&]() { insertionSort(arr); });
			cout<<"Insertion sort time-complexity : " << timeTaken <<" Milliseconds" << endl;

			// Selection Sort
			arr = ds.data;
			timeTaken = measureTime([&]() { selectionSort(arr); });
			cout<<"Selection sort time-complexity : " << timeTaken <<" Milliseconds" << endl;

			// Merge Sort
			arr = ds.data;
			timeTaken = measureTime([&]() { mergeSort(arr); });
			cout<<"Merge sort time-complexity : " << timeTaken <<" Milliseconds" << endl;
        
            cout<<endl;
        }
	}
	return 0;
}

