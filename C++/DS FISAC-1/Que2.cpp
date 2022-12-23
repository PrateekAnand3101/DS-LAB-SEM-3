//a user defined function to count the number of vowels and consonants in a string 
// using a pointer
#include <iostream>
using namespace std;
int main() 
{
    char a[50];
    int i, v=0, c=0;
    cout<<"Enter string\n";
    cin>>a;
    char *p=a;
    for(i=0; *(p+i)!='\0'; i++)
    {
        if(*(p+i)=='a' || *(p+i)=='e' || *(p+i)=='i' || *(p+i)=='o' || *(p+i)=='u')
        {
            v++;
        }
        else
        {
            c++;
        }
    }
    cout<<"Number of vowels= "<<v<<"\n";
    cout<<"Number of consonants= "<<c<<"\n";
    return 0;
}