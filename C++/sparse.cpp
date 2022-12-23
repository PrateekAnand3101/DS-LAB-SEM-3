// #include <iostream>
// using namespace std;
// const int MAX=100;

// class sparse
// {
//     int r,c,v,k,a[MAX];
//     public:
//     void read(sparse a[])
//     {
//         int m,n,ele;
//         cout<<"Enter the order:\n";
//         cin>>m>>n;
//         int k=1;
//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 cin>>ele;
//                 if(ele==0)
//                     continue;
//                 else
//                     a[k].r=i;
//                     a[k].c=j;
//                     a[k].v=ele;
//                     k++;
//             }
//         }
//         a[0].r=m;
//         a[0].c=n;
//         a[0].v= k-1;
//     }

//     void display(sparse a[])
//     {
//         int k=1;
//         for(int i=0;i<a[0].r;i++)
//         {
//             for(int j=0;j<a[0].c;j++)
//             {
//                 if(i==a[k].r && j==a[k].c)
//                 {
//                     cout<<a[k].v;
//                     k++;
//                 }
//                 else
//                     cout<<"0";
//             }
//             cout<<"\n";
//         }
//         for(int i=0;i<=a[0].v;i++)
//         {
//             cout<<a[i].r<<" "<<a[i].c<<" "<<a[i].v<<endl;
//         }
        
//     }

//     void ftranspose(sparse a[], sparse b[])
//     {
//         int rT[MAX],sp[MAX],i;
//         for(int i=0;i<a[0].c;i++)
//         {
//             rT[i]=0;
//         }
//         for(int i=0;i<=a[0].v;i++)
//         {
//             rT[a[i].c]++;
//         }
//         sp[0]=1;
//         for(int i=1;i<=a[0].c;i++)
//         {
//             sp[i]=sp[i-1]+rT[i-1];
//         }
//         for(int i=1;i<=a[0].v;i++)
//         {
//             k=sp[a[i].c]++;
//             b[k].r=a[i].c;
//             b[k].c=a[i].r;
//             b[k].v=a[i].v;
//         }
//         display(b);
        
//     }
// };
// int main(){
//     sparse s,a[MAX],b[MAX];
//     s.read(a);
//     s.ftranspose(a,b);
//     s.display(a);
//     return 0;
// }

//fast transpose
#include <iostream>
using namespace std;
const int MAX=100;
class sparse
{
int r,c,v,k,a[MAX];
    public:
    void read(sparse a[])
    {
        int m;
        int n;
        cout<<"Enter the order :\n";
        cin>>m>>n;
        k=1;
        int ele;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>ele;
                if(ele==0)
                {
                    continue;
                }
                a[k].r=i;
                a[k].c=j;
                a[k].v=ele;
                k++;            
            }
        }
        a[0].r=m;
        a[0].c=n;
        a[0].v=k-1;
    }

    void display(sparse a[])
    {      int k=1;
        for(int i=0;i<a[0].r;i++)
        {
            for(int j=0;j<a[0].c;j++)
            {
                if(i==a[k].r && j==a[k].c)
                {
                    cout<<a[k].v;
                    k++;
                }
                
                else
                cout<<"0";
            }
            cout<<endl;
        }
        
        for(int i=0;i<=a[0].v;i++)
        {   
            
            cout<<a[i].r<<" "<<a[i].c<<" "<<a[i].v<<"\n";
        }
    }
    
    void ftranspose(sparse a[], sparse b[])
    {
        int rt[MAX],sp[MAX],i;
        b[0].r=a[0].c;
        b[0].c=a[0].r;
        b[0].v=a[0].v;
        for(int i=0;i<a[0].c;i++)
        {
            rt[i]=0;
        }
        for(int i=1;i<=a[0].v;i++)
        {
            rt[a[i].c]++;
        }
        sp[0]=1;
        for(int i=1;i<=a[0].c;i++)
        {
            sp[i]=sp[i-1]+rt[i-1];
        }
        for(int i=1;i<=a[0].v;i++)
        {
            k=sp[a[i].c]++;
            b[k].r=a[i].c;
            b[k].c=a[i].r;
            b[k].v=a[i].v;
        }
        display(b);
        
    }
};

int main(){

    sparse s,a[MAX],b[MAX];
    s.read(a);
    s.ftranspose(a,b);
    s.display(a);
    return 0;
}