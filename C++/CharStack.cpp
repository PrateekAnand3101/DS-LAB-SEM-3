// #include <iostream>
// #include<string>
// using namespace std;
// enum Boolean{FALSE, TRUE};
// class stk
// {
//     int top;
//     int a[200];
//     int maxsize;
//     public:
//     stk(){ }
//     stk(int size)
//     {
//         maxsize=size;
//         top=-1;
//     }

//     Boolean Isfull()
//     {
//         if(top==maxsize-1)
//         {
//             return true;
//         }
//         else
//              return false;
//     }

//     Boolean Isempty()
//     {
//         if(top==-1)
//         {
//             return true;
//         }
//         else
//             return false;
//     }

//     void push(char x);
//     char pop();
//     void display();

// };

// void stk::push(char x)
// {
//     if(Isfull())
//     {
//         cout<<"Stack is full\n";
//     }
//     else
//     {
//         a[++top]=x;
//     }
// }

// char stk::pop()
// {
//     if(Isempty())
//     {
//         cout<<"Stack is empty\n";
//         return -1;
//     }
//     else
//     {
//         return a[top--];
//     }
// }

// void reverse(char s[])
// {
//     int i=0,n;
//     while(s[j]!='\0')
//     {
//         i++;
//         n=i;
//     }
//     stk s(10);
//     for(int i=0;i<n;i++)
//     {
//         s.push(s[i]);
//     }
//     for(int i=0;i<n;i++)
//     {
//         s[i]=s.pop();
        
//     }
//     cout<<"Reversed string: "<<s;

// }
// int main(){
//     char s[50];
//     int a;
//     cout<<"Enter a string";
//     cin>>s;
//     reverse(s);
//     return 1;
    
//     return 0;
// }

// #include <iostream>
// using namespace std;
// #define STACK_SIZE 22
// class Stack {
//     private:
//     int top;
//     char arr[STACK_SIZE];
//     public:
//     Stack(){
//         top=-1;
//     }
//     void push(int elem){
//         if(top!=STACK_SIZE-1){
//             arr[++top]=elem;
//         }
//         else{
//             cout<<"Overflow"<<endl;
//         }
//     }

//     int pop(){
//         if(top!=-1)
//             return arr[top--];
//         cout<<"Stack Underflow!"<<endl;
//         return -1;
//     }

//     int peek(){
//         if(top!=-1)
//             return arr[top];
//         else{
//             cout<<"Underflow"<<endl;
//             return -1;
//         }
//     }

//     void display(){
//         for(int i=top;i>=0;i--){
//             cout<<arr[i]<<endl;
//         }
//     }
// };

// int main(){
//     Stack stk1;
//     string a;
//     cout<<"Enter String:";
//     getline(cin, a);
//     for(int i=0;i<a.length();i++)
//         stk1.push(a[i]);

//     int i;
//     for( i=0 ; (i<a.length())&&(stk1.pop()==a[i]) ;++i);

//     if(i == a.length())
//         cout<<"String is a palindrome.";
//     else
//         cout<<"String is not a palindrome.";
//         return 0;
// }

// #include <iostream>
// #include <string.h>
// #include <stdio.h>
// #define STACK_SIZE 100
// using namespace std;
// class Stack {
//     private:
//     int top;
//     int arr[STACK_SIZE];
//     public:
//     Stack(){
//         top=-1;
//     }
//     void push(int elem){
//         if(top!=STACK_SIZE-1){
//             arr[++top]=elem;
//         }
//         else{
//             cout<<"Overflow"<<endl;
//         }
//     }

//     int pop(){
//         if(top>=0)
//             return arr[top--];
//         cout<<"Underflow"<<endl;
//         return -1;
//     }



//     void display(){
//         for(int i=top;i>=0;i--){
//             if(arr[i]<=10)
//                 cout<<arr[i];
//             else
//             {
//                 char c=arr[i]+55;
//                 cout<<c;
//             }

//         }
//     }
// };

// int main(){
//     Stack New;
//     cout<<"Enter number:";
//     int numb;
//     cin>>numb;
//     int base,div;
//     cout<<"Enter the base:";
//     cin>>base;
//     do{
//         div=numb%base;
//         numb=numb/base;
//         New.push(div);
//     }   while(numb>=base);
//     New.push(numb);
//     New.display();
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main(){
//     int fval=5,sval=15;
//     int *p1,*p2;
//     p1=&fval;
//     p2=&sval;
//     *p1=10;
//     *p2=*p1;
//     p1=p2;
//     *p1=20;
//     cout<<fval<<endl;
//     cout<<sval;
//     return 0;
// }
// #include<iostream>
// using namespace std;
// int main()
// {
// int i, j, (*p)[2], a[][2]={{12, 22},{33, 44} };
// p=a;
// for(i=0;i<2;i++)
// {
//     for(j=0;j<2;j++)
//     {
//         cout<<*(*(p+i)+j)<<"\t";
        
//     }
//     cout<<"\n";
        
// }
// }
#include <iostream>
using namespace std;
int *larger (int*, int*);
int main()
{
int a=10, b=20, *p;  p=larger (&a, &b);  
cout<<*p;
}
int *larger (int *x, int *y)
{
if (*x > *y)
    return(x);  
else
    return(y);
}
