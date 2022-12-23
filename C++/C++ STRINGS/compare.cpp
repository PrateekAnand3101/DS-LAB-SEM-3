#include <iostream>
using namespace std;

int main(){
    char s1[100],s2[100];
    cout<<"Enter the strings:\n";
    cout<<"s1: ";
    cin>>s1;
    cout<<"s2: ";
    cin>>s2;
    for(int i=0;s1[i]!='\0';i++)
    {
        if(s2[i]==s1[i])
        {
            continue;
        }
        else
        {
            cout<<"Strings are not equal";
            return 0;
        }
    }
    cout<<"strings are equal";
    return 0;
}