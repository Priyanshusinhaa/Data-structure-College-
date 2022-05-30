#include<iostream>

class Node {
  public:
    int key;
  int data;
  Node * next;
  Node * previous;
  Node() {
    key = 0;
    data = 0;
    next = NULL;
    previous = NULL;
  }
  Node(int k, int d) {
    key = k;
    data = d;
  }
};

class DoublyLinkedList {
  public:
    Node * head;
  DoublyLinkedList() {
    head = NULL;
  }
  DoublyLinkedList(Node * n) {
    head = n;
  }

  Node * nodeExists(int k) {
    Node * temp = NULL;
    Node * ptr = head;
    while (ptr != NULL) {
      if (ptr -> key == k) {
        temp = ptr;
      }
      ptr = ptr -> next;
    }
    return temp;
  }

  void appendNode(Node * n) {
    if (nodeExists(n -> key) != NULL) {
      std::cout << "Node Already exists with key value : " << n -> key << ". Append another node with different Key value" << std::endl;
    } else {
      if (head == NULL) {
        head = n;
        std::cout << "Node Appended as Head Node" << std::endl;
      } else {
        Node * ptr = head;
        while (ptr -> next != NULL) {
          ptr = ptr -> next;
        }
        ptr -> next = n;
        n -> previous = ptr;
        std::cout << "Node Appended" << std::endl;
      }}}
  void prependNode(Node * n) {
    if (nodeExists(n -> key) != NULL) {
      std::cout << "Node Already exists with key value : " << n -> key << ". Append another node with different Key value" << std::endl;
    } else {
      if (head == NULL) {
        head = n;
        std::cout << "Node Prepended as Head Node" << std::endl;
      } else {
        head -> previous = n;
        n -> next = head;
        head = n;
        std::cout << "Node Prepended" << std::endl;
      }}}
  void insertNodeAfter(int k, Node * n) {
    Node * ptr = nodeExists(k);
    if (ptr == NULL) {
      std::cout << "No node exists with key value: " << k << std::endl;
    } else {
      if (nodeExists(n -> key) != NULL) {
        std::cout << "Node Already exists with key value : " << n -> key << ". Append another node with different Key value" << std::endl;
      } else {
        Node * nextNode = ptr -> next;
        if (nextNode == NULL) {
          ptr -> next = n;
          n -> previous = ptr;
          std::cout << "Node Inserted at the END" << std::endl;
        }
        else {
          n -> next = nextNode;
          nextNode -> previous = n;
          n -> previous = ptr;
          ptr -> next = n;

          std::cout << "Node Inserted in Between" << std::endl;

        }

      }
    }
  }

  void deleteNodeByKey(int k) {
    Node * ptr = nodeExists(k);
    if (ptr == NULL) {
      std::cout << "No node exists with key value: " << k << std::endl;
    } else {

      if (head -> key == k) {
        head = head -> next;
        std::cout << "Node UNLINKED with keys value : " << k << std::endl;
      } else {
        Node * nextNode = ptr -> next;
        Node * prevNode = ptr -> previous;
        // deleting at the end
        if (nextNode == NULL) {

          prevNode -> next = NULL;
          std::cout << "Node Deleted at the END" << std::endl;
        }

        //deleting in between
        else {
          prevNode -> next = nextNode;
          nextNode -> previous = prevNode;
          std::cout << "Node Deleted in Between" << std::endl;

        }
      }
    }
  }

  // 6th update node
  void updateNodeByKey(int k, int d) {

    Node * ptr = nodeExists(k);
    if (ptr != NULL) {
      ptr -> data = d;
      std::cout << "Node Data Updated Successfully" << std::endl;
    } else {
      std::cout << "Node Doesn't exist with key value : " << k << std::endl;
    }}


  void printList() {
    if (head == NULL) {
      std::cout << "No Nodes in Doubly Linked List";
    } else {
      std::cout << std::endl << "Doubly Linked List Values : ";
      Node * temp = head;

      while (temp != NULL) {
        std::cout << "(" << temp -> key << "," << temp -> data << ") <--> ";
        temp = temp -> next;
      }}
    }};

int main() {

  DoublyLinkedList obj;
  int option;
  int key1, k1, data1;
  do {
    std::cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << std::endl;
    std::cout << "1. appendNode()" << std::endl;
    std::cout << "2. prependNode()" << std::endl;
    std::cout << "3. insertNodeAfter()" << std::endl;
    std::cout << "4. deleteNodeByKey()" << std::endl;
    std::cout << "5. updateNodeByKey()" << std::endl;
    std::cout << "6. print()" << std::endl;
    std::cout << "7. Clear Screen" << std::endl << std::endl;

    std::cout << "Enter option: ";
    std::cin >> option;
    Node * n1 = new Node();
    // Node n1;

    switch (option) {
    case 0:
      break;
    case 1:
      std::cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << std::endl;
      std::cin >> key1;
      std::cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      obj.appendNode(n1);
      std::cout<<n1 -> key<<" = "<<n1 ->data <<std::endl;
      break;

    case 2:
      std::cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << std::endl;
      std::cin >> key1;
      std::cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      obj.prependNode(n1);
      break;

    case 3:
      std::cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << std::endl;
      std::cin >> k1;
      std::cout << "Enter key & data of the New Node first: " << std::endl;
      std::cin >> key1;
      std::cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;

      obj.insertNodeAfter(k1, n1);
      break;

    case 4:

      std::cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << std::endl;
      std::cin >> k1;
      obj.deleteNodeByKey(k1);

      break;
    case 5:
      std::cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << std::endl;
      std::cin >> key1;
      std::cin >> data1;
      obj.updateNodeByKey(key1, data1);

      break;
    case 6:
      obj.printList();

      break;
    case 7:
      system("cls");
      break;
    default:
      std::cout << "Enter Proper Option number " << std::endl;
    }

  } while (option != 0);

  return 0;
}