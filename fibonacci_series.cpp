#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    int a=0, b=1, c;
    cout<<"Fibonacci Series: ";
    for(int i = 1; i <= n; i++){
        cout<<a<<" ";
        c = a + b;
        a = b;
        b = c;
    } 
    return 0;
}