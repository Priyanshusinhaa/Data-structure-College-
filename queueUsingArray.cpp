#include <iostream>
#define N 5000

int arr[N];
int front = -1;
int rear = -1;
int temp = 0;
int choose, val;
int choice = 1;

bool isEmpty(){
    if(front > rear){
        return true;
    }
    else{
        return false;
    }
}

bool isFull(){
    if(front == 0 and rear == N-1){
        return true;
    }
    else{
        return false;
    }
}

void peek(){
    std::cout << arr[rear] << " is Peek element." << std::endl;
}

void enqueuee(int data){
    if (isFull())
    {
        std::cout << "Queue Overflow." << std::endl;
    }
    else{
        if (front == -1 and rear == -1){
            front = 0;
            }
        arr[++rear] = data;
        std::cout << arr[rear] << " inserted." << std::endl;}
}

void dequeuee(){
    if (isEmpty()){
        std::cout << "Queue Underflow." << std::endl;
    }
    else{
        temp = arr[front];
        ++front;
        std::cout << temp << " is removed." << std::endl;
    }
}

void display(){
    if (isEmpty()){
        std::cout << "Queue Underflow." << std::endl;
    }
    else{
        for (int i = front; i <= rear; ++i){
        std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
}

void logic(){

    std::cout << "Queue operations:-" << std::endl;
    std::cout << "1. Enqueue" << std::endl;
    std::cout << "2. Dequeue" << std::endl;
    std::cout << "3. Peek" << std::endl;
    std::cout << "4. Display" << std::endl;
    std::cout << "5. To End program" << std::endl;
    std::cout << "Enter operation number: " ;
    std::cin >> choose;
    if (choose == 1){
        system("cls");
        std::cout << "Enqueue: Enter value: " ;
        std::cin >> val;
        enqueuee(val);
        std::cout << std::endl;
    }
    else if (choose == 2){
        system("cls");
        dequeuee();
        std::cout << std::endl;
    }
    else if (choose == 3){
        system("cls");
        peek();
        std::cout << std::endl;
    }
    else if (choose == 4){
        system("cls");
        display();
        std::cout << std::endl;
    }
    else if (choose == 5){
        choice = 0;
        std::cout << "Exited! " << std::endl;
    }
    else{
        std::cout << "Press Number between 1 to 5 do wishful operation" << std::endl;
    }
}


int main(){
    while(choice){
        display();
        logic();
    }
    return 0;
}
