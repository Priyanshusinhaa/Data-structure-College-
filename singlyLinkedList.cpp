#include <iostream>

struct node{
    int data;
    node *ptr;
};

int choose;
int choice = 1;

node *temp ,*head = 0;

void add(int data){
    node *newnode = new node;
    newnode ->data = data;
    newnode ->ptr = nullptr;
    if(head == 0){
        head = temp = newnode;
    }
    else{
        temp ->ptr = newnode;
        temp = newnode;
    }
}

void addAtBegining(int data){
    node *store_adr;
    node *newnode = new node;
    newnode ->data = data;
    store_adr = head;
    newnode -> ptr = store_adr;
    head = newnode;
}

void remove(){
    int iter;
    int i = 1;
    int data;
    node *store = head;
    node *store1 = head;
    while (store != 0){
        store = store ->ptr;
        ++iter;
    }
    while (i != iter -1){
        store1 = store1 ->ptr;
        ++i;
    }
    store1 ->ptr = nullptr;
    delete(store);
}

void removeAtBegining(){
    node *store;
    store = head;
    head = head ->ptr;
    delete(store);
}

void display(){
    node *store = head;
    std::cout << " \nData is singly Linked list: ";
    while (store != 0){
        std::cout << store ->data << " ";
        store = store ->ptr;}
    std::cout << std::endl;
}

void switchForSll(){

    int val;
    std::cout << " \nOperations can be performed on Singly Linked List :- "<< std::endl;
    std::cout << " 1. Add at begining" << std::endl;
    std::cout << " 2. Add at End" << std::endl;
    std::cout << " 3. Remove at Begining" << std::endl;
    std::cout << " 4. Remove at End" << std::endl;
    std::cout << " 5. Display" << std::endl;
    std::cout << " 6. End Program" << std::endl;
    std::cout << " Enter choice: ";
    std::cin >> choose;

    switch (choose)
    {
    case 1:
        std::cout << " Enter value: ";
        std::cin >> val;
        addAtBegining(val);
        break;
    case 2:
        std::cout << " Enter value: ";
        std::cin >> val;
        add(val);
        break;
    case 3:
        removeAtBegining();
        break;
    case 4:
        remove();
        break;
    case 5:
        display();
        break;
    case 6:
        choice = 0;
        std::cout << "Program ended." << std::endl;
    default:
        break;
    }
}

int main(){
    while (choice)
    {   
        system("cls");
        display();
        switchForSll();
    }
    
    return 0;
}