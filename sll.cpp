#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

int main(){
    int choice = 1;
    static node *head = 0;

    while (choice)
    {
    node *temp, *nextnode = new node;
    cout << "Enter an integer data: ";
    cin >> nextnode -> data;
    nextnode ->next = nullptr;
    if (head == 0)
    {
        head = temp = nextnode;
    }
    else{
        temp ->next = nextnode;
        temp = nextnode;
    }
    cout << "Do you wanna continue (0/1)?";
    cin >> choice;
    }

    // node *store = head;
    // while (store != 0)
    // {
    //     cout << store ->data << " ";
    //     store = store ->next;
    // }
    // inserting at any location in linked list
    int position;
    cout << "Enter where you wanna insert: ";
    cin >> position;
    node *enrol = head;
    for (int i = 0; i < position; i++)
    {
        cout << enrol ->data << " ";
        enrol = enrol ->next;
    };
    
    
    return 0;
}



