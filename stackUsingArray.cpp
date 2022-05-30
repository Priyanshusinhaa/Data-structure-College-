#include <iostream>
#define N 100

// variable initialization or declaration
int arr[N];
int top = -1;
int data, temp;
char choose;
int choice = 1;

// function declaration
void push();
void pop();
void peak();
void display();
void logic();

// Main funcition

int main(){
    while (choice)
    {  
        logic();
    }
    return 0;
}

// function defination

void push(int data){
    if (top == N -1){
        std::cout << "Stack Overflow." << std::endl;
    }
    else{
        system("cls");
        arr[++top] = data;
        std::cout << arr[top] <<" Inserted!" << std::endl;
    }
}

void pop(){
    if (top == -1){
        std::cout << "Stack Underflow." << std::endl;
    }
    else{
        system("cls");
        temp = arr[top];
        arr[--top];
        std::cout << temp << " Poped." << std::endl;
    }
}

void peak(){
    if (top == -1){
        std::cout << "Stack Underflow." << std::endl;
    }
    else{
        system("cls");
        std::cout << "Peak Element: " << arr[top] << std::endl;
    }
}

void display(){
    if (top == -1)
    {
        std::cout << "Stack Underflow: " << std::endl;
    }
    else{
        system("cls");
        std::cout << "Stored elements in array are: " ;
        for (int i = 0; i <= top; ++i){
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
    
}

void logic(){
    std::cout << "Operations on Stack :-" << std::endl;
    std::cout << "1. Push" << std::endl;
    std::cout << "2. Pop" << std::endl;
    std::cout << "3. Peak " << std::endl;
    std::cout << "4. Display" << std::endl;
    std::cout << "x. For Ending Program: " << std::endl;
    std::cout << "Enter Operation: ";
    std::cin >> choose;
    switch (choose)
    {
    case '1':
        std::cout << "Enter Data: ";
        std::cin>> data;
        push(data);
        break;
    case '2':
        pop();
        break;
    case '3':
        peak();
        break;
    case '4':
        display();
        break;
    case 'x':
        choice = 0;
        std::cout << "Program Ended... " << std::endl;
    default:
        break;
    }
}

