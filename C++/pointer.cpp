#include <iostream>
using namespace std;

int main(){
    int a=10;
    int *p;
    p=&a;
    cout<<"address of p is:-"<<p<<endl;
    cout<<"size of int is:-"<<sizeof(int)<<endl;
    cout<<"address of p-1 is:-"<<p-1<<endl;
    return 0;
}