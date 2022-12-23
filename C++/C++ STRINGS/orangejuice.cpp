#include <iostream>
#include<string.h>
using namespace std;

int main(){
    char s[100],s1[100];
    cout<<"enter a string:\n";
    cin.getline(s,100);
    cout<<"Enter the word to be searched:\n";
    cin>>s1;
    for(int i=0;s[i]!='\0';i++)
    {
        strcmp(s[i],s1[i]);
        if(strcmp())
        {
            continue;
            cout<<"word not found";
        }
        

    }
    cout<<"word found \n";
    return 0;
}