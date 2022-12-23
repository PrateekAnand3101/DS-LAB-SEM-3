// program to swap two numbers
// #include<iostream>
// using namespace std;

// int main()
// {
//     int num1,num2,temp;
//     cout<<"please enter the 1st number:- "<<endl;
//     cin>>num1;
//     cout<<"please enter the 2nd number:- "<<endl;
//     cin>>num2;
    
//     temp=num2;
//     num2=num1;
//     num1=temp;
//     cout<<"after swapping, the first number is:- "<<num1<<endl;
//     cout<<"after swapping, the second number is:- "<<num2<<endl;

//     return 0;
// }


// #include<iostream>
// using namespace std;

// int main()
// {
//     int a[200],n,i;
//     cout<<"Enter the number of elements:\n";
//     cin>>n;
//     cout<<"Enter the elements:\n";
//     for(i=0;i<n;i++)
//     {
//         cin>>a[i];
//     }
//     for(i=0;i<n;i++)
//     {
//         for(int j=0;j<n-i-1;j++)
//         {
//             if(a[j]>a[j+1])
//             {
//                 int temp=a[j];
//                 a[j]=a[j+1];
//                 a[j+1]=temp;
//             }
//         }   
            
            
//     }
    
//     cout<<"The second largest element is:\n"<<a[n-2]<<endl;
//     return 0;
// }

#include <iostream>
#include <string.h>
using namespace std;
class task
{
    public:
    char username[50];
    int tsize, t, taskname;
    void getData()
    {
        cin>>username>>taskname>>tsize>>t;
    }
};
class queue
{
    int c;
    task a[5];
    public:
    queue()
    {
        c=-1;
    }
    void enqueue(int tn, int p)
    {
        c++;
        a[c].taskname=tn;
        a[c].tsize=p;
    }
    int deq()
    {
        int k=0, n;
        int l, i;
        l=a[0].tsize;
        for(i=1; i<c; i++)
        {
            if(a[i].tsize>l)
            {
                l=a[i].tsize;
                k=i;
                n=a[i].taskname;
            }
        }
        for(i=k; i<c; i++)
        {
            a[k]=a[k+1];
        }
        c--;
        return n;
    }
};
int main()
{
    queue q;
    q.enqueue(10, 1);
    q.enqueue(14, 5);
    q.enqueue(16, 4);
    q.enqueue(77, 3);
    q.enqueue(7, 2);
    int a=q.deq();
    int b=q.deq();
    int c=q.deq();
    int d=q.deq();
    cout<<a<<"\n"<<b<<"\n"<<c<<"\n"<<d;
}