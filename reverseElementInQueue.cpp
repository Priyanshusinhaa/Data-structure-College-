#include <iostream>
#include <stack>

struct node{int data; node *link;};
int choose;
int choice = 1;
int val;
node *front = 0;
node *rear = 0;

void choiceSwitch();

void enqueue(int val){
    node *newnode = new node;
    newnode ->data = val;
    newnode ->link = 0;
    if (front == 0 and rear == 0){
        rear = front = newnode;}
    else{
        rear ->link = newnode;
        rear = newnode;}}

void dequeue(){
    int store;
    node *temp;
    if (rear == 0){
        std::cout << "\n Queue Underflow." << std::endl; }
    else{
        temp = front;
        store = front ->data;
        front = front ->link;
        delete(temp);}}

void display(){
    node *temp = front;
    std::cout << "\n Elements in queue are: ";
    while (temp != 0){   
        std::cout << temp ->data << " ";
        temp = temp -> link;}
    std::cout <<std::endl;}

int reverse(){
    node *temp = front;
    std::stack <int> stack;
    std::cout << " Reverse Elements are :";
    while (temp != 0){
        stack.push(temp ->data);
        temp = temp ->link;}
    while (!stack.empty()){
        std::cout << " " << stack.top();
        stack.pop();}
    return 1;
}

void choiceSwitch(){
    std::cout << std::endl;
    std::cout << "\n Operation on Queue: " << std::endl;
    std::cout << " 1) Enqueue" << std::endl;
    std::cout << " 2) Dequeue" << std::endl;
    std::cout << " 3) Reverse" << std::endl;
    std::cout << " 5) End Program." << std::endl;
    std::cout << " Enter choice: ";
    std::cin >> choose;
    switch (choose){
    case 1:
        std::cout << " Enter value: ";
        std::cin >> val;
        enqueue(val);
        system("cls");
        break;
    case 2:
        system("cls");
        dequeue();
        break;
    case 3:
        system("cls");
        reverse();
        break;
    case 5:
        choice = 0;
        std::cout << "\n Program Ended.";
        break;
    default:
        break;}}

int main(){
    while (choice){
        display();
        reverse();
        choiceSwitch();}
    return 0;}