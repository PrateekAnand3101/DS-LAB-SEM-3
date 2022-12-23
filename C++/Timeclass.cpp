// #include <iostream>
// #include <iomanip>
// using namespace std;
// class timer{
//     private:
//     int hour;
//     int min;
//     int sec;
//     public:

//     void read(){
//         char ch=':';
//         cout<<"Enter the time in the format HH:MM:SS"<<endl;
//         cin>>hour>>ch>>min>>ch>>sec;
//     }

//     void display(){
//         cout<<hour<<':'<<min<<':'<<sec<<endl;
//     }

//     void add(timer t1, timer t2) {
//         int s=t1.sec+t2.sec;
//         int m=t1.min+t2.min;
//         int h=t1.hour+t2.hour;
//         sec=s%60;
//         min=(m+s/60)%60;
//         hour=(h+m/60)%24;
//     }

//     void difference(timer t1, timer t2){
//         sec=t1.sec-t2.sec;
//         min=t1.min-t2.min;
//         hour=t1.hour-t2.hour;
//         if (sec<0){
//             min-=1;
//             sec+=60;
//         }
//         if(min<0){
//             hour-=1;
//             min+=60;
//         }
//         if(hour<0){
//             hour+=24;
//         }
//     }
// };

// int main(){
//     timer t1,t2;
//     t1.read();
//     t2.read();
//     timer t3, t4;
//     t3.add(t1,t2);
//     t4.difference(t1,t2);
//     cout<<setw(12)<<"ADD  ";
//     t3.display();
//     cout<<"DIFFERENCE  ";
//     t4.display();
// }

// #include <iostream>
// #include <string.h>
// using namespace std;
// int main(){
//     char a[50], b[50];
//     cout<<"Enter the main string:"<<endl;
//     gets(a);
//     cout<<"Enter the sub string:"<<endl;
//     gets(b);
//     int n, al, bl;
//     cout<<"Enter the location to enter the sub string:";
//     cin>>n;
//     al=strlen(a);
//     bl=strlen(b);
//     //SHIFTING ELEMENTS N PLACES TO THE RIGHT BY STEP 'LENGTH(B)'
//     for(int i=1;i<=(al-n);i++){
//         a[al+bl-i]=a[al-i];
//     }
//     a[al+bl]='\0';
//     //SUBSTITUTING SUBSTRING IN VACATED SPACE
//     for(int j=0;j<bl;j++){
//         a[n+j]=b[j];
//     }
//     cout<<a;
//     return 0;
// }

// #include <iostream>
// #include <string.h>
// using namespace std;
// int main(){
    // char a[50], b[50];
    // cout<<"Enter the main string:"<<endl;
    // gets(a);
    // cout<<"Enter the sub string:"<<endl;
    // gets(b);
    // int al=strlen(a),bl=strlen(b);
    // bool flag=false;
    // int loc=-1;
// 
// 
    // SEARCHING FOR THE SUBSTRING IN THE MAIN STRING
    // for (int i=0; i<=al-bl;i++){
        // for (int j=i;j<i+bl;j++){
            // flag=true;
            // if(a[j]!=b[j-i]){
                // flag=false;
                // break;
            // }
        // }
        // if(flag==true){
            // loc=i;
            // break;
        // }
    // }
    // IF FOUND, DELETING THE SUBSTRING FROM THE MAIN STRING
    // if (loc==-1){
        // cout<<"Substring not found in string";
        // return 0;
    // }
    // for(int i=0;i<al-loc;i++){
        // a[loc+i]=a[loc+bl+i];
    // }
    // cout<<a;
// 
// 
// }

// #include<iostream>
// using namespace std;
// class student{
//     private:
//     int rn;
//     char name[50];
//     char Grade;
//     public:
//     void read()
//     {
//         cout<<"Enter the roll number of student:";
//         cin>>rn;
//         cout<<"Enter the name of the student:";
//         cin>>name;
//         cout<<"Enter the grade received by the student:";
//         cin>>Grade;
//     }
//     void Display()
//     {
//         cout<<"Roll number:"<<rn<<"\tName:"<<name<<"\tGrade:"<<Grade;
//     }
//     void test(student s1[], int n)
//     {
//         for(int i=0; i<n; i++)
//         {
//             for(int j=0; j<n-i-1; j++)
//             {
//                 if((s1[j].rn)>(s1[j+1].rn))
//                 {
//                     student temp;
//                     temp=s1[j];
//                     s1[j]=s1[j+1];
//                     s1[j+1]=temp;
//                 }
//             }
//         }
//     }
// };
// int main()
// {
//     int n;
//     cout<<"Enter the number of students:";
//     cin>>n;
//     student s[n];
//     for(int i=0; i<n; i++)
//     {
//         cout<<"Student "<<i+1<<":"<<endl;
//         s[i].read();
//         cout<<endl<<endl;
//     }
//     cout<<"The data of students has been fed"<<endl<<endl;
//     s[0].test(s,n);
//     cout<<"Displaying the stored data:"<<endl;
//     for(int i=0; i<n; i++)
//     {
//         s[i].Display();
//         cout<<endl;
//     }
// }

#include <iostream>

using namespace std;
class time{
    private:
    int hour;
    int min;
    int sec;
    public:

    void read(){
        char ch=':';
        cout<<"Enter the time:\n"<<endl;
        cin>>hour>>ch>>min>>ch>>sec;
    }

    void display(){
        cout<<hour<<':'<<min<<':'<<sec<<endl;
    }

    void add(time t1, time t2) {
        int s=t1.sec+t2.sec;
        int m=t1.min+t2.min;
        int h=t1.hour+t2.hour;
        sec=s%60;
        min=(m+s/60)%60;
        hour=(h+m/60)%24;
    }

    void difference(time t1, time t2){
        sec=t1.sec-t2.sec;
        min=t1.min-t2.min;
        hour=t1.hour-t2.hour;
        if (sec<0){
            min-=1;
            sec+=60;
        }
        if(min<0){
            hour-=1;
            min+=60;
        }
        if(hour<0){
            hour+=24;
        }
    }
};

int main()
{
    time t1,t2;
    t1.read();
    t2.read();
    time t3, t4;
    t3.add(t1,t2);
    t4.difference(t1,t2);
    cout<<"ADD  ";
    t3.display();
    cout<<"DIFFERENCE  ";
    t4.display();
}