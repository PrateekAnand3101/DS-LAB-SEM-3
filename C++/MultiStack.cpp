// #include <iostream>
// using namespace std;

// class stk
// {
//     int item,a[100],top1,top2;
//     public:
//     stk()
//     {
//         top1=top2=-1;

//     }
//     void push1(int item)
//     {
//         if(top1==top2-1)
//         {
//             cout<<"Stack full";

//         }
//         else
//         {
//             a[++top1]=item;
//         }

//     }

//     void push2(int item)
//     {
//         if(top2==top1+1)
//         {
//             cout<<"Stack full";

//         }
//         else
//         {
//             a[top2--]=item;
//         }

//     }

//     void pop1()
//     {
//         int item;
    
//         if(top1==-1)
//         {
//             cout<<"Stack empty";

//         }
//         else
//         {
//             item= a[top1--];
//             cout<<"Deleted item from stack1 is: "<<item;

//         }
//     }
//     void pop2()
//     {
//         int item;
//         if(top2==-1)
//         {
//             cout<<"Stack empty";
//         }
//         else
//         {
//             item= a[top2++];
//             cout<<"Deleted item from stack1 is: "<<item;
//         }
//     }
//     // void display1()
//     // {
//     //     if(top1>=0)
//     //     {
//     //         cout<<"Stack elements are:";
//     //         for(int i =top1;i>=0;i--)
//     //         {
//     //             cout<<a[i]<<" ";
//     //             cout<<endl;
//     //         }
//     //     }
//     //     else
//     //     {
//     //         cout<<"Stack is empty";

//     //     }
//     // }
//     // void display2()
//     // {
//     //     if(top2>=100)
//     //     {
//     //         cout<<"Stack elements are:";
//     //         for(int i =top2;i<=100;i--)
//     //         {
//     //             cout<<a[i]<<" ";
//     //             cout<<endl;
//     //         }
//     //     }
//     //     else
//     //     {
//     //         cout<<"Stack is empty";

//     //     }
//     // }
// };

// int main(){
//     stk s1[100];
//     int item;
//     s1.push1();
//     s1.push2();
//     // s.display1();
//     // s.display2();
//     s1.pop();
//     return 0;
// }
#include<iostream>
using namespace std;
const int MAX=100;

class MStk{
private:
    int top[100], bot[100], arr[MAX], n, a;
public:
    MStk(){
        cout<<"number of stacks: ";
        cin>>n;
        cout<<"enter the size of the Multiple stack";
        top[0] = bot[0] = -1;
        for(int i=1, j=-1;i<n;i++){
            cin>>a;
            j=j+a;
            top[i]=bot[i]=j;
        }
        for(int i=0, j=-1;i<n;i++){
            cout<<top[i]<<" ";
        }
    }
    void push(int ele, int NumStk){
        if (top[NumStk]==bot[NumStk+1]){
            cout<<"Stack overflow";
            return;
        }
        else{
            arr[++top[NumStk]]=ele;
            return;
        }
    }

    int pop(int NumStk){
        if (top[NumStk]==bot[NumStk]){
            cout<<"Underflow";
        }
        else{
            return arr[top[NumStk]--];
        }
    }
    void display(){
        for (int i=0;i<n;i++){
            cout<<"Stack "<<i<<": ";
            for (int j=bot[i];j<top[i];j++){
                cout<<arr[j]<<" ";
            }
            cout<<"\n";
        }
    }
};


int main(){
    MStk s1;
    int z, ele, NumStk;
    while (z!=-1){
        cout<<"Enter action: 1 for push, 2 for pop, 3 for display, -1 for exit";
        cin>>z;
        switch (z){
        case -1:
            break;
        case 1:
            cout<<"enter element and matrix num starting from 0: ";
            cin>>ele>>NumStk;
            s1.push(ele, NumStk);
            break;

        case 2:
            cout<<"enter matrix num starting from 0: ";
            cin>>NumStk;
            ele = s1.pop(NumStk);
            cout<<ele;
            break;
        case 3:
            s1.display();
            break;
        }
    }
    return 0;
}