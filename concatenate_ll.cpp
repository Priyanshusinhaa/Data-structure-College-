#include <iostream>

struct node{
    int data;
    node *ptr;
};

int choice = 1;
int choose;

node *temp ,*head = 0;
node *temp2 ,*head2 = 0;

node *temp_head = head;
node *temp_head2 = head2;

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

void display(){
    node *store = head;
    std::cout << " \n Data in singly Linked list: ";
    while (store != 0){
        std::cout << store ->data << " ";
        store = store ->ptr;}
    std::cout << std::endl;
}


void add2(int data){
    node *newnode2 = new node;
    newnode2 ->data = data;
    newnode2 ->ptr = nullptr;
    if(head2 == 0){
        head2 = temp2 = newnode2;
    }
    else{
        temp2 ->ptr = newnode2;
        temp2 = newnode2;
    }
}

void display2(){
    node *store2 = head2;
    std::cout << " \n Data in singly Linked list: ";
    while (store2 != 0){
        std::cout << store2 ->data << " ";
        store2 = store2 ->ptr;}
    std::cout << std::endl;
}

void concatenate(node *a, node *b)
{
    if (a->ptr == NULL)
        a->ptr = b;
    else
        concatenate(a->ptr,b);
}

void c_and_d_21(){
    concatenate(temp_head2, temp_head);
    std::cout << " concatenated second in first ll: ";
    while(temp_head != 0){
        std::cout << temp_head ->data << " ";
        temp_head = temp_head ->ptr;
    }
}
void c_and_d_12(){
    concatenate(temp_head, temp_head2);
    std::cout << " concatenated first in second ll: ";
    while(temp_head2 != 0){
        std::cout << temp_head2 ->data << " ";
        temp_head2 = temp_head2 ->ptr;
    }
}

void switchsll(){
    int val;
    std::cout << " Operation in Two singly linked list you can perform:-" << std::endl;
    std::cout << " 1) Add in first sll" << std::endl;
    std::cout << " 2) Add in second sll" << std::endl;
    std::cout << " 3) Concatenate first sll in second one" << std::endl;
    std::cout << " 4) Concatenate second sll in first one" << std::endl;
    std::cout << " 5) End program " << std::endl;
    std::cout << " Enter choice : ";
    std::cin >> choose;
    switch (choose)
    {
    case 1:
        std::cout << " Enter value: ";
        std::cin >> val;
        add(val);
        break;
    case 2:
        std::cout << " Enter value: ";
        std::cin >> val;
        add2(val);
    case 3:
        c_and_d_12();
        break;
    case 4:
        c_and_d_21();
        break;
    case 5:
        choice = 0;
        std::cout << " Program Ended.";
    default:
        break;
    }

}

int main(){
    while(choice){
        display();
        display2();
        switchsll();
    }
    return 0;
}
