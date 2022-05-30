#include<iostream>
#include<cmath>
#include<stack>

float scanNum(char ch){
   int value;
   value = ch;
   return float(value-'0');
}

int isOperator(char ch){
   if(ch == '+'|| ch == '-'|| ch == '*'|| ch == '/' || ch == '^')
      return 1;
   return -1;
}

int isOperand(char ch){
   if(ch >= '0' && ch <= '9')
      return 1;
   return -1;
}

float operation(int a, int b, char op){
   if(op == '+')
      return b+a;
   else if(op == '-')
      return b-a;
   else if(op == '*')
      return b*a;
   else if(op == '/')
      return b/a;
   else if(op == '^')
      return pow(b,a);
   else
      return INT_MIN;
}

float postfixEval(std::string postfix){
   int a, b;
   std::stack<float> stk;
   std::string::iterator it;

   for(it=postfix.begin(); it!=postfix.end(); it++) {
      if(isOperator(*it) != -1) {
         a = stk.top();
         stk.pop();
         b = stk.top();
         stk.pop();
         stk.push(operation(a, b, *it));}

      else if(isOperand(*it) > 0){
         stk.push(scanNum(*it));
      }
   }
   return stk.top();
}

int main() {
   int choice = 1;
   std::string postfix_expression;
   while(choice){
        std::cout << std::endl;
        std::cout << " Enter Postfix expression: ";
        std::cin >> postfix_expression;
        system("cls");
        std::cout << std::endl;
        std::cout << " Your Postfix expression: " << postfix_expression << std::endl;
        std::cout << std::endl;
        std::cout << " Evaluation of Postfix is: "<<postfixEval(postfix_expression) << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << " Do you wanna continue(0/1)? " ;
        std::cin >> choice;
   }
   return 0;
}
