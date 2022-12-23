// #include <iostream>
// #include <string.h>
// using namespace std;
// int main(){
//     char a[50], b[50];
//     cout<<"Enter the main string:"<<endl;
//     gets(a);
//     cout<<"Enter the sub string:"<<endl;
//     gets(b);
//     int al=strlen(a),bl=strlen(b);
//     bool flag=false;
//     int pos=-1;



//     for (int i=0; i<=al-bl;i++){
//         for (int j=i;j<i+bl;j++){
//             flag=true;
//             if(a[j]!=b[j-i]){
//                 flag=false;
//                 break;
//             }
//         }
//         if(flag==true){
//             pos=i;
//             break;
//         }
//     }

//     if (pos==-1){
//         cout<<"Substring not found in string";
//         return 0;
//     }
//     for(int i=0;i<al-pos;i++){
//         a[pos+i]=a[pos+bl+i];
//     }
//     cout<<a;
//     return 0;

// }

#include <iostream>
#include <string.h>
using namespace std;
int main(){
    char a[100], b[100];
    cout<<"Enter the main string:"<<endl;
    gets(a);
    cout<<"Enter the sub string:"<<endl;
    gets(b);
    int n, al, bl;
    cout<<"Enter the location to enter the sub string:";
    cin>>n;
    al=strlen(a);
    bl=strlen(b);

    for(int i=1;i<=(al-n);i++){
        a[al+bl-i]=a[al-i];
    }
    a[al+bl]='\0';

    for(int j=0;j<bl;j++){
        a[n+j]=b[j];
    }
    cout<<a;
}
