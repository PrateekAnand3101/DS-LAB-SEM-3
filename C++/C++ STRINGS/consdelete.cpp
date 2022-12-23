#include <iostream>
using namespace std;

int main(){
    char s[100],s1[100];
    int i;
    cout<<"Enter string:\n";
    cin.getline(s,100);
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
        {
            s1[i]=s[i];
        }
    }
    s1[i]='\0';
    cout<<s1;
    return 0;
}