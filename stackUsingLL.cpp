#include <iostream>

int choice = -1;
int choose;
int val;

struct Node{
    int data;
    struct Node* link;};
Node* top;

void push(int data){
    struct Node* temp;
    temp = new Node();
    if (!temp){
        std::cout << "\nHeap Overflow";
        exit(1);}
    temp->data = data;
    temp->link = top;
    top = temp;}
 
int isEmpty(){return top == 0;}
 
int peek(){
    if (!isEmpty()){std::cout << top ->data << std::endl;}
    else{exit(1);}
}

void pop(){
    struct Node* temp;
    if (top == NULL){
        std::cout << "\nStack Underflow" << std::endl;
        exit(1);}
    else{
        temp = top;
        top = top->link;
        temp->link = NULL;
        free(temp);}
}

void display(){
    struct Node* temp;
    if (top == NULL){
        std::cout << "\nStack Underflow" << std::endl;}
    else{
        temp = top;
        std::cout << "Elements in stack are: ";
        while (temp != NULL){
            std::cout << temp->data << " ";
            temp = temp->link;}
        std::cout << std::endl;}
}

int main(){   
    while (choice){
        std::cout << "Operation in stack are:-" << std::endl;
        std::cout << "1. Push" << std::endl;
        std::cout << "2. Pop" << std::endl;
        std::cout << "3. Peek" << std::endl;
        std::cout << "4. Display" << std::endl;
        std::cout << "5. Program End" << std::endl;
        std::cout << "Enter operation :" ;
        std::cin >> choose;
        switch (choose){
        case 1:
            system("cls");
            std::cout << "Enter value: ";
            std::cin >> val;
            push(val);
            std::cout << val << " inserted." << std::endl;
            break;
        case 2:
            system("cls");
            pop();
            std::cout << "One element poped." << std::endl;
            break;
        case 3:
            system("cls");
            peek();
            break;
        case 4:
            system("cls");
            display();
            break;
        case 5:
            choice = 0;
            std::cout << "Program Ended.";
            break;
        
        default:
            break;}}       
    return 0;
}
 