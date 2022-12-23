#include<iostream>
#include<string.h>
using namespace std;
class stk
{
    char s[100][100];
    int top;
public:
    stk()
    {
        top=-1;

    }

    void push(char a[])
    {
        strcpy(s[++top],a);
      
    }
    char *pop()
    {
        return s[top--];
    }
    void display()
    {
        int i;
        for(i=0;i<=top;i++)
            cout<<s[i]<< "\t";

    }
};

int main()
{
    char str[100],op1[10],op2[10],sym[10];
    stk s;
    cout<< "Enter the postfix exp"<<endl;
    gets(str);
    int i;
    char res[10];
    int n=strlen(str);
    /*char a[]="(";
    char b[]=")";*/
    for(i=0;i<n;i++)
    {
        sym[0]=str[i];
        sym[1]='\0';
                   
        if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
        {
            strcpy(op2,s.pop());
            strcpy(op1,s.pop());
            strcpy(res,"(");
            strcat(res,op1);
            strcat(res,sym);
            strcat(res,op2);
            strcat(res,")");
            s.push(res);

        }
        else {
            s.push(sym);
        }
    }


cout<<s.pop();
return 0;
}
