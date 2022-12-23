#include <iostream>
using namespace std;
const int MAX=25;

int insertheap(int item, int a[], int n)
{
    int c,p;
    if(n==MAX)
    {
        cout<<"Heap is full\n";
        return n;
    }
    c=n+1;
    p=c/2;
    while(c!=1 && item>a[p])
    {
        a[c]=a[p];
        c=p;
        p=c/2;
    }
    a[c]=item;
    return n+1;
}

// void heapify(int a[], int n, int i)
// {
//     int largest = i; // Initialize largest as root
//     int l = 2 * i + 1; // left = 2*i + 1
//     int r = 2 * i + 2; // right = 2*i + 2
 
//     // If left child is larger than root
//     if (l < n && a[l] > a[largest])
//         largest = l;
 
//     // If right child is larger than largest so far
//     if (r < n && a[r] > a[largest])
//         largest = r;
 
//     // If largest is not root
//     if (largest != i) {
//         swap(a[i], a[largest]);
 
//         // Recursively heapify the affected sub-tree
//         heapify(a, n, largest);
//     }
// }
int delHeap(int a[], int n)
{
    int c,p,temp;
    if(n==0)
    {
        cout<<" Heap is empty\n";
        return 0;
    }
    cout<<"Item deleted is: "<<a[1]<<"\n";
    temp=a[n--];
    p=1;
    c=2*p;
    while(c<=n)
    {
        if(a[c]<a[c+1])
        {
            c++;
        }
        if(temp>=a[c])
            break;
        a[p]=a[c];
        p=c;
        c=2*p;
    }
    a[p]=temp;
    // heapify(a,n,0);
    return n;
}

void adjust(int a[], int p, int n)
{
    int c,temp;
    temp=a[p];
    c=2*p;
    while(c<=n)
    {
        if(c<n && a[c+1]>a[c])
        {
            c++;
        }
        if(temp>a[c])
            break;
        else
        {
            a[c/2]=a[c];
            c=2*c;
        }
    }
    a[c/2]=temp;
    return;
}
void sort1(int a[], int n)
{
    int i,j,temp;
    for(i=n-1;i>0;i--)
    {
        temp=a[1];
        a[1]=a[i+1];
        a[i+1]=temp;
        adjust(a,1,i);
    }
}
void print(int a[], int n)
{
    for (int i = 1; i <= n; ++i)
        cout << a[i] << " ";
    cout << "\n";
}
int main(){
    int a[]={10,5,3,2,4};
    int i;
    
    int n=sizeof(a)/sizeof(a[0]);
    
    delHeap(a,n);
     print(a,n);
    sort1(a,n);
    
     print(a,n);
    return 0;
}