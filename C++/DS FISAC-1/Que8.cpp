#include<iostream>
#include<string.h>
#define N 100
char arr[100];
char atb[100];
using namespace std;
class stak
{int top;
char *arr;
public:
stak(){
arr=new char[N];
top=-1;


}

void push(char x)
{
    arr[++top]=x;

}
void peek()
{
cout<<arr[top];

}
char  pop()
{

char x=arr[top--];

     return x;
}
bool isempty(){
if(top==-1)
{return true;
}
else{
    return false;
}
}
bool isfull()
{

if(top>=N-1)
{
    return 1;
}
else
{
    return 0;
}
}
void display(){cout<<"The stack is"<<endl;
for(int i=top;i>=0;i--)
{
    cout<<arr[i]<<endl;
}
}
char topp()
{
    return arr[top];
}


};

int prec(char c)
{

    if(c=='^')
    {
        return 3;
    }

else if(c=='/'||c=='*')
    {
        return 2;
    }


else if(c=='+'||c=='-')
    {
        return 1;
    }

else {return -1;}




}

void inftopos(char a[])
{
stak w;
int j=0;
char output[100];
for(int i=0;i<strlen(a);i++)

{
char c=a[i];
if(isdigit(c))
{
   output[j++]=c;
}







else if(c=='(')
{
    w.push(a[i]);
}

else if(c==')')
{
while(w.topp()!='(')
{char x=w.pop();
  output[j++]=x;
}
w.pop();


}
else {
    while( prec(c)<=prec(w.topp())&&w.topp()!='(')
{
output[j++]=w.pop();


}
w.push(c);

}

}
while(!w.isempty())
{
output[j++]=w.pop();

}
strcpy(atb,output);

}

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
void pretoinf(char str[])
{


char op1[10],op2[10],sym[10];
    stk s;

    int i;
    char res[10];
    int n=strlen(str);

    for(i=n;i>=0;i--)
    {
        sym[0]=str[i];
        sym[1]='\0';

        if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
        {
            strcpy(op2,s.pop());
            strcpy(op1,s.pop());
            strcpy(res,"(");
            strcat(res,op2);
            strcat(res,sym);
            strcat(res,op1);
            strcat(res,")");
            s.push(res);

        }
        else {
            s.push(sym);
        }
    }

 strcpy(arr,s.pop());

}


void pretopost(char abc[])
{

pretoinf(abc);

inftopos(arr);

puts(atb);
}



int main()
{

char str[100];
cout<< "Enter the  prefix exp"<<endl;
    gets(str);





pretopost(str);






}
