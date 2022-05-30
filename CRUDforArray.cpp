#include <iostream>
#include <vector>
#define Q 100

int array[] = {1,3,7,5,6,77,84,2,5,3};
int size_of_array = sizeof(array)/sizeof(array[0]);

void swap(int &i, int &j){
    int z;
    z = i; i = j; j = z;
}

void insert(int data, int position){
    for ( int i = position; i <= size_of_array + 1; ++i)
    {
        swap(array[position], array[i+1]);
    }
    array[position] = data;
}

void remove(int position){
    int size_of_arr = sizeof(array)/sizeof(*array);
    for (int i = position; i <= size_of_arr + 1; ++i)
    {
        swap(array[i],array[i+1]);
    }
};

void display(){
    int size_of_arr = sizeof(array)/sizeof(*array);
    for (int i = 0; i <= size_of_arr; ++i)
    {
        std::cout << array[i] << " " ;
    }
    std::cout << std::endl;
}

int main(){
    insert(45,0);
    insert(46,1);
    insert(47,2);
    insert(48,3);
    display();
    return 0;
}