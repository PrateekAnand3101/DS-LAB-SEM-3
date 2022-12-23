// program to find the upper and lower limits 
// of fundamental data types

// #include <iostream>
// #include<climits>
// #include<cfloat>

// using namespace std;

// int main(){
//     int a;
//    cout<<"the upper limit of int is:- "<<INT_MAX<<endl;
//    cout<<"the lower limit of int is:- "<<INT_MIN<<endl;
//    char b;
//    cout<<"the upper limit of char is:- "<<SCHAR_MAX<<endl;
//    cout<<"the lower limit of char is:- "<<SCHAR_MIN<<endl;
   
   
   
   
   
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main(){
//     char s1[100],s2[100];
//     int i;
//     cout<<"Enter string s1:\n";
//     cin>>s1;
//     for(int i=0;s1[i]!='\0';i++)
//     {
//         s2[i]=s1[i];
        
//     }
//     s2[i]='\0';
//     cout<<"The copied string is:\n"<<s2;
    
//     return 0;
// }


#include <iostream>
using namespace std;
class matrix
{
    int r, c, v;
    public:
    void getData(int row, int col, int val)
    {
        r=row;
        c=col;
        v=val;
    }
    int getByRow(matrix m[], int n, int row, int col)
    {
        for(int i=0; i<n; i++)
        {
            if(m[i].r==row && m[i].c==col)
                return m[i].v;
        }
        return -1;
    }
   
};
int main()
{
    int n, i, r, c, v, val=-1;
    cout<<"Enter number of non-zero elements\n";
    cin>>n;
    matrix m[n];
    cout<<"Enter no. of non-zero values, no. of rows and no. of columns\n";
    cin>>v>>r>>c;
    m[0].getData(r, c, v);
    for(i=1; i<n; i++)
    {
        cout<<"Enter value, row and column for object number "<<i<<"\n";
        cin>>v>>r>>c;
        m[i].getData(r, c, v);
    }
    cout<<"Enter row and column to check\n";
    cin>>r>>c;
    cout<<"Value= "<<m[0].getByRow(m,n,r,c);
}