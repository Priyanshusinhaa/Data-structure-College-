#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++){
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key){
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void printArray(int arr[], int n){
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr[] = { 152, 121, 113, 56, 64 };
	int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Unsorted Elements: ";
    printArray(arr, n);
	insertionSort(arr, n);
    cout << "sorted Elements: ";
	printArray(arr, n);

	return 0;
}

