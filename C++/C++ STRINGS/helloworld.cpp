#include <iostream>
using namespace std;

int main(){
    char s[100];
    cout<<"Enter a string\n";
    cin.getline(s,100);
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='o')
        {
            cout<<i<<" ";
        }
    }
    return 0;
}