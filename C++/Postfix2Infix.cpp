// #include <iostream>
// using namespace std;
// class stk
// {
//     int top;
//     char s[100];
//     public:
//     stk()
//     {
//         top=-1;
//     }
//     void push(char a)
//     {
//         if(top==99)
//         {
//             cout<<"Stack Overflow";
//             return;
//         }
//         s[++top]=a;
//     }
//     char pop()
//     {
//         if(top==-1)
//         {
//             return '\0';
//         }
//         return s[top--];
//     }
//     bool isempty()
//     {
//         if(top==-1)
//             return true;
//         else
//             return false;
//     }
//     void contopfix(char infix[])
//     {
//         char pfix[50];
//         int l,precedence,p;
//         char e1,e2;
//         p=0;
//         for(int i=0;infix[i]!='\0';i++)
//         {
//             e1=infix[i];
//             switch(e1)
//             {
//                 case '(':
//                        push(e1);
//                        break;
//                 case ')':
//                     while((e2=pop())!='(')
//                             pfix[p++]=e2;
//                     break;
//                 case '+':
//                 case '-':
//                 case '*':
//                 case '/':
//                     if(!isempty())
//                     {
//                         precedence=prec(e1);
//                         e2=pop();
//                         while(precedence<=prec(e2))
//                         {
//                             pfix[p++]=e2;
//                             if(!isempty())
//                                 e2=pop();
//                             else
//                                 //push(e1);
//                                 break;
//                         }
//                         //push(e1);
//                         if(precedence>prec(e2))
//                         {
//                             push(e2);
//                             //push(e1);
//                         }
//                     }
//                     push(e1);
//                     break;
//                 default:
//                     pfix[p++]=e1;
//                     break;
//             }
//         }
//         while(!isempty())
//             pfix[p++]=pop();
//         pfix[p]='\0';
//         cout<<"The postfix expression is: "<<pfix<<endl;

//     }
//     int prec(char symbol)
//     {
//         switch(symbol)
//         {
//         case '/':
//         case '*':return 3;
//         case '+':
//         case '-':return 2;
//         case '(':return 0;
//         default:return -1;
//         }
//     }
//     void rev()
//     {

//     }
// };
// bool isOperand(char x) {
//     return (x >= 'a' && x <= 'z') ||
//            (x >= 'A' && x <= 'Z');
// }
// char postfix2infix(char exp[]) {
//     stk s;

//     for (int i = 0; exp[i] != '\0'; i++) {
//         if (isOperand(exp[i])) {
//             char op(1, exp[i]);
//             s.push(op);
//         }

//         else {
//             char op1 = s.pop();
//             char op2 = s.pop();
//             s.push("(", op2 ,exp[i] ,
//                    op1 , ")");
//         }
//     }
//     return s.pop();
// }


// int main() {
//     stk s;
//     char postfix[200];
//     cout << "Enter the postfix expression: ";
//     cin.getline(postfix,200);
//     cout << postfix2infix(postfix);

//     return 0;
// }

#include <string.h>

#include <iostream>
#define maxsize 100

using namespace std;

bool isOperand(char x) {
    return (x >= 'a' && x <= 'z') ||
           (x >= 'A' && x <= 'Z');
}

class stack {
    public:
    int top;
    char a[maxsize];

    stack() { top = -1; }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == maxsize - 1; }

    void push(char ele) {
        if (isFull()) cout << "Stack-Overflow" << endl;
        else a[++top] = ele;
    }
    char pop() {
        if (isEmpty()) {
            cout << "Stack-Underflow" << endl;
            
        } else {
            return a[top--];
        }
    }
    void display(){
        if (isEmpty()) cout << "Empty-Stack" << endl;
        else{
            for (int i = 0; i <= top; i++){
                cout << a[i] << " ";
            }
        }
        cout << endl;
    }
};


char postfix2infix(char exp) {
    stack s;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (isOperand(exp[i])) {
            char op(1, exp[i]);
            s.push(op);
        }

        else {
            char op1 = s.pop();
            char op2 = s.pop();
            s.push('(' + op2 + exp[i] +
                   op1 + ')');
        }
    }
    return s.pop();
}


int main() {
    stack s;
    char postfix[100];
    cout << "Enter the postfix expression: ";
    cin >> postfix;
    cout << postfix2infix(postfix);

    return 0;
}

//Program to convert a Postfix expression to an Infix expression
// #include <iostream>
// #include <string.h>
// using namespace std;
// const int STACK_SIZE=100;

// class Stack{
//     int top;
//     char arr[100];
//     public:
//     Stack(){
//         top=-1;
//     }
//     void push(char elem){
//         if(top<STACK_SIZE){
//             arr[++top]=elem;
//         }
//         else
//             cout<<"Stack Overflow!";
//     }
//     char pop(){
//         if(top>=0)
//             return arr[top--];
//         cout<<"Underflow!"<<endl;
//     }
//     char peek(){
//         if(top>=0)
//             return arr[top];
//         cout<<"Underflow!"<<endl;
//     }
// };

// char postToInfix(char pre[]){
//     Stack s;
//     char output, final;
//     int l=strlen(pre);
//     for(int i=0;i<l;i++){
//         if(isdigit(pre[i])||isalpha(pre[i])){
//             s.push(1,pre[i]);
//         }
//         else{
//             char a=s.pop();
//             char b=s.pop();
//             char exp='('+b+pre[i]+a+')';
//             s.push(exp);
//         }
//     }
//     output=s.peek();
//     return output;
// }

// int main(){
//     char inp[100];
//     cout<<"Enter the expression:";
//     cin>>inp;
//     cout<<postToInfix(inp);
// }