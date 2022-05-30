#include<iostream>  
#include<stack>

// Declarartion of function
bool IsOperator(char);  
bool IsOperand(char);  
bool checkPrecedencePriority(char, char);  
std::string convertExpression(std::string);  

// Main function
int main(){  
    std::string infix_expression, postfix_expression;  
    int ch;  
    do{  
        std::cout << " Write infix expression: ";
        std::cin >> infix_expression;  
        postfix_expression = convertExpression(infix_expression);  
        std::cout << "\n Infix expression: " << infix_expression << std::endl;  
        std::cout << "\n Postfix expression: " << postfix_expression << std::endl;  
        std::cout << "\n Do you wanna input more infix expression(0/ 1)?";  
        std::cin >> ch;
        if (ch == 1){system("cls");}
        else{std::cout << "\n\n Program Ended."; }
    }
    while(ch == 1); 
    return 0;  
}  

// Defination of function
bool IsOperator(char c){  
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' )  
        return true;     
    return false;  
}  
    
bool IsOperand(char c){  
    if( c >= 'A' && c <= 'Z'){ 
        return true;}  
    if (c >= 'a' && c <= 'z'){  
        return true;}  
    if(c >= '0' && c <= '9'){   
        return true; } 
    return false;
    } 

int precedence(char op){  
    if(op == '+' || op == '-'){ return 1; } 
    if (op == '*' || op == '/'){ return 2;}
    if(op == '^'){return 3;}      
    return 0;
    } 
 
bool checkPrecedencePriority(char op1, char op2){  
    int p1 = precedence(op1);  
    int p2 = precedence(op2);  
    if (p1 == p2){  
        if (op1 == '^' ){return false;}
        return true;}  
    return  (p1>p2 ? true : false);}  
    
std::string convertExpression(std::string infix){  
    std::stack <char> stack;  
    std::string postfix ="";    
    char ch;  
    
    stack.push( '(' );  
    infix += ')';  
    
    for(int i = 0; i< int(infix.length()); ++i){  
        ch = infix[i];
        if(ch == ' ')  
            continue;  
        else if(ch == '('){  
            stack.push(ch);}
        else if(IsOperand(ch)){  
            postfix += ch;}  
        else if(IsOperator(ch)){  
            while(!stack.empty() && checkPrecedencePriority(stack.top(), ch)){  
                postfix += stack.top();  
                stack.pop();}  
            stack.push(ch);}
        else if(ch == ')'){  
            while(!stack.empty() && stack.top() != '('){  
                postfix += stack.top();  
                stack.pop();}  
            stack.pop();}
    }  
    return postfix;  
}  