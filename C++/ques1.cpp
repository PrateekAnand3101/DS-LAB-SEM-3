// program to find the size of fundamental data type in C++
// #include<iostream>
// using namespace std;

// int main()
// {
//     int a;
//     cout<<"size of int is:- "<<sizeof(a)<<endl;
//     char b;
//     cout<<"size of char is:- "<<sizeof(b)<<endl;
//     short c;
//     cout<<"size of short is:- "<<sizeof(c)<<endl;
//     long d;
//     cout<<"size of long is:- "<<sizeof(d)<<endl;
//     long long e;
//     cout<<"size of long long is:- "<<sizeof(e)<<endl;
//     float f;
//     cout<<"size of float is:- "<<sizeof(f)<<endl;
//     double g;
//     cout<<"size of double is:- "<<sizeof(g)<<endl;
//     long double h;
//     cout<<"size of long double is:- "<<sizeof(h)<<endl;
//     bool i;
//     cout<<"the size of bool is:- "<<sizeof(i)<<endl;
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
        for(int i=1; i<=n; i++)
        {
            if(m[i].r==row && m[i].c==col)
                return m[i].v;
        }
        return -1;
    }
    int getNumElementsInColumn(matrix m[], int n, int col)
    {
        int j=0;
        for(int i=1; i<=n; i++)
        {
            if(m[i].c==col)
                j++;
        }
        return j;
    }
};
int main()
{
    int n, i, j, r, c, k=0;
    cout<<"Enter number of rows, columns and non-zero elements\n";
    cin>>r>>c>>n;
    int a[r][c];
    matrix m[n];
    m[0].getData(r, c, n);
    cout<<"Enter elements\n";
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            cin>>a[i][j];
            if(a[i][j]>0)
            {
                k++;
                m[k].getData(i, j, a[i][j]);
            }
        }
    }
    cout<<"Enter row and column to check\n";
    cin>>r>>c;
    cout<<"Value= "<<m[1].getByRow(m, k, r, c);
    cout<<"\nEnter column to check\n";
    cin>>c;
    cout<<"Number of elements are= "<<m[1].getNumElementsInColumn(m,k,c);
}
