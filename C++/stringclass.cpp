// #include <iostream>
// #include <string.h>
// #include <stdio.h>
// using namespace std;

// class Student{
//     private:
//         char name[50];
//         char grade;
//         int roll;
//     public:
//         void reader(Student s[], int n){
//             for(int i=0;i<n;i++){
//                 cout<<"Enter the roll no:";
//                 cin>>(s[i].roll);
//                 fflush(stdin);
//                 cout<<"Enter the name:";
//                 gets(s[i].name);
//                 cout<<"Enter the grade:";
//                 cin>>(s[i].grade);
//             }
//         }
//         void printer(Student s[], int n){
//             for(int i=0;i<n;i++){
//                 cout<<endl<<"Student "<<i+1<<endl;
//                 cout<<"Roll No.: "<<s[i].roll<<endl;
//                 cout<<"Name: "<<s[i].name<<endl;
//                 cout<<"Grade: "<<s[i].grade<<endl;
//             }
//         }
//         void sort(Student s[],int n){
//             Student temp;
//             int min;
//             for(int i=0;i<n;i++){
//                 min=i;
//                 for(int j=i+1;j<n;j++){
//                     if(s[j].roll<s[min].roll){
//                         min=j;
//                     }
//                 }
//                 temp=s[i];
//                 s[i]=s[min];
//                 s[min]=temp;
//                 }
//         }
// };


// int main(){
//     int n;
//     cout<<"Enter the number of students:";
//     cin>>n;
//     fflush(stdin);
//     Student s[n], a;
//     a.reader(s,n);
//     a.sort(s,n);
//     a.printer(s,n);
//     return 0;
// }  

// #include<iostream>
// using namespace std;
// int main()
// {
//     char s1[100];
//     int i,l=0;
//     cout<<"Enter the string s1:\n";
//     cin>>s1;
//     for(i=0;s1[i]!='\0';i++)
//     {
//         l++;
//     }
//     cout<<"The length of the string is:\n"<<l;

//     return 0;
// }

// #include<iostream>
// using namespace std;
// int main()
// {
//     char s[100],s1[100];
//     int i;
//     cout<<"Enter string s:\n";
//     cin>>s;
//     cout<<"Enter string s1:\n";
//     cin>>s1;
//     int l=0;
//     while(s[l]!='\0')
//     {
//         l++;
//     }
//     for(i=0;s1[i]!='\0';i++,l++)
//     {
//         s[l]=s1[i];
//     }
//     s[l]='\0';

//     cout<<"s is:"<<s;
//     return 0;
// }
#include<iostream>
using namespace std;

int main()
{
    char s1[20],s2[20];
    int i=0,chk=0;
    cout<<"enter first string: ";
    cin.getline(s1,20);
    cout<<"enter second string: ";
    cin.getline(s2,20);

    while(s1[i]!='\0'|| s2[i]!='\0')
    {
        if(s1[i]!=s2[i])
        {
            chk++;
        }
        i++;
    }
    if(chk==0)
        cout<<"\nString are Equal";
    else
        cout<<"\nStrings are not Equal";
    return 0;
}

