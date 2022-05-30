#include <iostream>

struct node{int data; node *link;};
int choose;
int choice = 1;
int val;
node *front = 0;
node *rear = 0;

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
        std::cout << "\nQueue Underflow." << std::endl; }
    else{
        temp = front;
        store = front ->data;
        front = front ->link;
        delete(temp);}}

void display(){
    node *temp = front;
    std::cout << "Elements in queue are: ";
    while (temp != 0){   
        std::cout << temp ->data << " ";
        temp = temp -> link;}
    std::cout <<"\n"<<std::endl;}

void choiceSwitch(){
    std::cout << "Operation on Queue: " << std::endl;
    std::cout << "1) Enqueue" << std::endl;
    std::cout << "2) Dequeue" << std::endl;
    std::cout << "3) Display" << std::endl;
    std::cout << "4) End Program." << std::endl;
    std::cout << "Enter choice: ";
    std::cin >> choose;
    switch (choose){
    case 1:
        std::cout << "Enter value: ";
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
        display();
        break;
    case 4:
        choice = 0;
        std::cout << "\nProgram Ended.";
        break;
    default:
        break;}}

int main(){
    while (choice){
        display();
        choiceSwitch();}
    return 0;}
