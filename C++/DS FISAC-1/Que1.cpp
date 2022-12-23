//Sort an array using pointer
#include <iostream>
using namespace std;
int main() 
{
    int n, i, temp, j;
    cout<<"Enter number of elements\n";
    cin>>n;
    int a[n];
    cout<<"Enter elements\n";
    int *p=a;
    for(i=0; i<n; i++)
        cin>>*(p+i);
    for(i=1; i<=n-1; i++)
    {
        for(j=0; j< n-i; j++)
        {
            if(*(p+j)>*(p+j+1))
            {
                temp= *(p+j);
                *(p+j)= *(p+j+1);
                *(p+j+1)= temp;
            }
        }
    }
    cout<<"Sorted array is:";
    for(i=0; i<n; i++)
        cout<<"\n"<<*(p+i);
return 0;
}