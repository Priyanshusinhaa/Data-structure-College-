#include <iostream>

int arr[] = {1,2,3,5,66,78,3,23};
int numOfElements = sizeof(arr)/sizeof(arr[0]);

int main(){
    std::cout << " Number of elements in Array: " << numOfElements;
    return 0;
}