

#include <iostream>
#include <string.h>
using namespace std;
const int MAX=100;

int prec(char c) {
    if(c == '^')
        return 3;
    else if(c == '/' || c=='*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

class stack {
    public:
    int top;
    int a[MAX];

    stack() { top = -1; }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }

    void push(int ele) {
        if (isFull()) cout << "Stack-Overflow" << endl;
        else a[++top] = ele;
    }
    int pop() {
        if (isEmpty()) {
            cout << "Stack-Underflow" << endl;
            return -999999;
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

int evalpostfix(char str[]){
    stack s1;
    for(int i = 0 ; str[i] != '\0'; i++){
        if(str[i] >= '0' && str[i] <= '9'){
            s1.push(str[i] - '0');
        }else{
            int op1 = s1.pop();
            int op2 = s1.pop();
            switch(str[i]){
                case '+': s1.push(op2 + op1); break;
                case '-': s1.push(op2 - op1); break;
                case '*': s1.push(op2 * op1); break;
                case '/': s1.push(op2 / op1); break;
                case '%': s1.push(op2 % op1) ; break;
            }
        }
    }
    return s1.pop();
}

// int evaluatePrefix(char str[]){
//     stack st;
//     int i = 0;
//     while(str[i] != '\0'){
//         i++;
//     }
//     i--;
//     while(i > -1){
//         if(str[i] >= '0' && str[i] <= '9'){
//             st.push(str[i] - '0');
//         }else{
//             int val1 = st.pop();
//             int val2 = st.pop();
//             switch(str[i]){
//                 case '+': st.push(val2 + val1); break;
//                 case '-': st.push(val2 - val1); break;
//                 case '*': st.push(val2 * val1); break;
//                 case '/': st.push(val2 / val1); break;
//                 case '%': st.push(val2 % val1) ; break;
//             }
//         }
//         i--;
//     }
//     return st.pop();
// }

int main(){
    char postfix[100];
    // cout << "Enter Prefix Expession";
    // cin >> prefix;
    // cout << evaluatePrefix(prefix) << endl;
    cout << "Enter postfix Expession";
    cin >> postfix;
    cout << evalpostfix(postfix) <<endl;
}
          