// Online C++ compiler to run C++ program online
#include <iostream>
#include<string.h>
using namespace std;
const int MAX=100;
class stk
{
    int top;
    char a[100];
    public:
    stk()
    {
        top=-1;

    }
    bool isEmpty()
    {
        return top==-1;
    }
    bool isFull()
    {
        if(top==-1)
            return true;
        return false;
    }
    // int Top()
    // {
    //     if(top==-1)
    //     {
    //         cout<<"No element in stack\n";
            
    //     }
    //     return a[top];
            
    // }
    void push(char x)
    {
        if(isFull())
        {
            cout<<"Stack overflow\n";
        }
        else
            a[++top]=x;
    }
    int pop()
    {
        if(isEmpty())
        {
            cout<<"Stack underflow\n";
        }
        else
            return a[top--];
    }
    


};
int prec(char sym)
    {
        switch(sym)
        {
            case '/':
            case '*':
            return 3;
            case '+':
            case '-':
            return 2;
            case '(':
            return 0;
            default:
            return -1;
        }
    }
void conToPfix()
    {
        int i,prec,p;
        stk s;
        char e1,e2;
        char pfix[MAX];
        p=0;
        for(i=0;infix[i]!='\0';i++)
        {
            e1=infix[i];
            switch(e1)
            {
                case '(':
                s.push(e1);
                break;
                case ')':
                while((e2=s.pop())!='(')
                {
                    pfix[p++]=e2;

                }
                break;
                case '+':
                case '-':
                case '*':
                case '/':
                if(!s.isEmpty())     
                {
                    int precedence=prec(e1);
                    e2=s.pop();
                    while(precedence<=prec(e2))
                    {
                        pfix[p++]=e2;
                        if(!s.isEmpty())
                            e2=s.pop();
                        else
                            break;

                    }
                    if(precedence>prec(e2))
                    {
                        push(e2);
                    }

                }
                push(e1);
                break;

                default:
                pfix[p++]=e1;
                break;   
            }
        }
        while(!s.isEmpty())
        {
            pfix[p++]=s.pop();
        }
        pfix[p]='\0';
        cout<<"The postfix expression is:\n"<<pfix<<endl;
    }
    


    int main()
    {
    stk s;
    char str[MAX];
    cout<<"Enter the expression:\n";
    for(int i=0;str[i]!='\0';i++)
    {
        cin>>str[i];
        s.push(str[i]);
        s.conToPfix();
    }
    cout<<s.conToPfix();
    return 0;
    
}