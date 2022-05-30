#include <iostream>
using namespace std;
struct node {
   int data;
   struct node *next;
};


node* head = NULL; 

void insert(int newdata) {
   node *newnode = new node;
   node *ptr = head;
   newnode->data = newdata;
   newnode->next = head;
   if (head!= NULL) {
      while (ptr->next != head)
      ptr = ptr->next;
      ptr->next = newnode;
   } else
   newnode->next = newnode;
   head = newnode;
}
void display() {
   node* ptr;
   ptr = head;
   do {
      std::cout<<ptr->data <<" ";
      ptr = ptr->next;
   } while(ptr != head);
}

int main() {
   insert(3);
   insert(1);
   insert(7);
   insert(2);
   insert(9);
   std::cout<<"The circular linked list is: ";
   display();
   return 0;
}