#include <iostream>

class BST
{
public:
    int value;
    BST* left;
    BST* right;
    BST(int val)
    {
        value = val;
        left = NULL;
        right = NULL;
    }

    BST& insert(int val)
    {
        BST* currentNode = this;
        while(true)
        {
            if(val < currentNode-> value)
            {
              //If value is less than current value, exploring left sub-tree 
                if(currentNode->left == NULL)
                {
                   // If left node of current node is end of the BST, iserting the value there
                    BST* newNode = new BST(val);
                    currentNode->left = newNode;
                    break;
                }else{
                  //initializing current node to the left node
                    currentNode = currentNode->left;
                }
            }else{
               //If value is greater than current value, explore right sub-tree 
                if(currentNode->right == NULL){
                  // If right node of current node is end of the BST, iserting the value there
                    BST* newNode = new BST(val);
                    currentNode->right = newNode;
                    break;
                }else{
                  //initializing current node to the right node
                    currentNode = currentNode->right;
                }
            }
        }
        return *this;
    }
    bool search(int val){
        BST* currentNode = this;
        while(currentNode != NULL){
            if(val < currentNode ->value){
              //if value is less than the current nodes value exploring left sub-tree
                currentNode = currentNode->left;
            }else if(val > currentNode->value){\
            //if value is greater than the current nodes value exploring right sub-tree
                currentNode = currentNode->right;
            }else{
              //value is found
                return true;
            }
        }
        return false;
    }

    int getMinValue(){
        BST* currentNode = this;
        while(currentNode->left != NULL){
            currentNode = currentNode->left;
        }
        return currentNode->value;

    }
};

int main(){
    BST b;
    b.insert(93);
    b.search(38);
    
    return 0;
}