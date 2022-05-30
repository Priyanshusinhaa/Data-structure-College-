#include <iostream>

int arr[11] = {122,43,12,54,32,76,47,21,86,14,33};

int lsearch(int arr[], int n, int x)
{
	int i;
	for (i = 0; i < n; i++)
		if (arr[i] == x)
			return i;
	return -1;
}

int main(void)
{
	int n = sizeof(arr) / sizeof(arr[0]);
	int val;
	std::cout << "Enter value to check : ";
	std::cin >> val;
	int result = lsearch(arr, n, val);
	(result == -1)? std::cout << "Element is not present in array": std::cout << "Element is present at index " << result;
	return 0;
}