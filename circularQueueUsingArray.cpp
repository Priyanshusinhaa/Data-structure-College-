#include <iostream>
#define N 100

int arr[N];
int front = -1;
int rear = -1;
int choose, val;
int choice = 1;


bool isEmpty(){
    if (front = -1 && rear == -1){return true;}
    else{return false;}
    }

bool isFull(){
    if (front = 0 && rear == N -1){return true;}
    if ((rear+1)%N ==front){ return true;}
    return false;  
}

void enQueue(int element){  
    if(front==-1 && rear==-1){  
        front=0;  
        rear=0;  
        arr[rear]=element;}  
    else if(isFull()){  
        std::cout << "Queue is full.";}  
    else{  
        rear=(rear+1)%N;         
        arr[rear]=element;}  
}  

void deQueue(){
    int val;
    if (isEmpty()) {std::cout << "Queue is Empty" << std::endl;} 
    else {
      val = arr[front];
      if (front == rear - 1){
        front = -1;
        rear = -1;}
      else{
        front = (front + 1) % N;
        std::cout << std::endl;
        std::cout << val << " is Deleted.";}}
  }

void display(){  
    int i=front;  
    if(isEmpty()){  
        std::cout << "\n Queue is Empty.." << std::endl;}  
    else{  
        std::cout << "\nElements in a Queue are :";  
        while(i<=rear){  
            std::cout << arr[i] << " ";
            i=(i+1)%N;}
        std::cout << std::endl;
    }}  

int main(){
    while (choice){   
        std::cout << "\nOperation is Circular Queue :- " << std::endl;
        std::cout << "1. Enqueue " << std::endl;
        std::cout << "2. Dequeue " << std::endl;
        std::cout << "3. Display " << std::endl;
        std::cout << "4. End program " << std::endl;
        std::cout << "Enter Operation: ";
        std::cin >> choose;
        switch (choose){
        case 1:
            system("cls");
            std::cout << "Enter value: ";
            std::cin >> val;
            enQueue(val);
            std::cout << val << " inserted." << std::endl;
            break;
        case 2:
            system("cls");
            deQueue();
            break;
        case 3:
            system("cls");
            display();
            break;
        case 4:
            choice = 0;
            std::cout << "Program Ended.";
        default:
            break;}}
    return 0;
}