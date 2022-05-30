#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <vector>

std::vector<int> arr;
char ch;
char insSwitch,remSwitch;
int choice = 1;
int val, pos;
int choose;

void insert();
void insertAtMid();
void insertAtBegining();
void clearArray();
void remove();
void display();
void logic();
void removeSwitch();
void insertSwitch();

// Main function

int main(){
    while (choice)
    { 
        logic();
    }
    return 0;
}

void insert(int val){
    arr.insert(arr.end(),val);
}

void insertAtBegin(int val){
    arr.insert(arr.begin(), val);
}

void insertAtMid(int pos, int val){

    arr.insert(arr.begin() + pos, val);
}

void remove(int pos){
    arr.erase(arr.begin()+pos);
}

void clearArray(){
    arr.clear();
}

void removeSwitch(){
    std::cout << "1. Remove Element from specified position. " << std::endl;
    std::cout << "2. Delete Array. " << std::endl;
    std::cout << "3. End program "<< std::endl;
    std::cout << "Enter operation: " ;
    std::cin >> remSwitch;
    switch (remSwitch)
    {
    case '1':
        std::cout << "Enter position/Index: ";
        std::cin >> pos;
        remove(pos);
        break;
    case '2':
        clearArray();
        std::cout << "Array clear successfully :)" << std::endl;
        break;

    case '3':
        std::cout << "Exited!" << std::endl;
        choice = 0;
        break;
    
    default:
        break;
    }
}

void logic(){
    std::cout << std::endl;
    std::cout << "Operation in Array:" << std::endl;
    std::cout << "1. Insert " << std::endl;
    std::cout << "2. Display " << std::endl;
    std::cout << "3. Remove" << std::endl;
    std::cout << "4. End program "<< std::endl;
    std::cout << "Enter operation: ";
    std::cin >> ch;

    switch (ch)
    {
    case '1':
        insertSwitch();
        break;
    case '2':
        display();
        break;
    case '3':
        removeSwitch();
        break;
    case '4':
        choice = 0;
        std::cout << "Exited!" << std::endl;
        break;
    default:
        break;
    }
}

void display(){
    system("cls");
    std::cout << std::endl;
    if (arr.empty()){
        std::cout << "Insert a Element first. Array is Empty!" << std::endl;
    }
    else{ }
    for (auto i = 0; i < arr.size(); ++i){
        std::cout << arr[i] << " ";
    }
}

void insertSwitch(){
    system("cls");
    std::cout << std::endl;
    std::cout << "1. Insert at End" << std::endl;
    std::cout << "2. Insert at middle" << std::endl;
    std::cout << "3. Insert at Begining" << std::endl;
    std::cout << "4. End program(press x) "<< std::endl;
    std::cout << "Enter operation: " ;
    std::cin >> insSwitch;
    if (insSwitch == '3'){
        std::cout << "Enter value: ";
        std::cin >> val;
        insertAtBegin(val);
    }
    else if (insSwitch == '2'){
        std::cout << "Enter value: ";
        std::cin >> val;
        std::cout << std::endl;
        std::cout << "Enter Index/Position: ";
        std::cin >> pos;
        insertAtMid(pos,val);
    }
    else if (insSwitch == '1'){
        std::cout << "Enter value: ";
        std::cin >> val;
        insert(val);
    }
    else if (insSwitch == '4'){
        std::cout << "Exited!" << std::endl;
        choice = 0;
    }
    else{
        choice = 0;
    }
}
