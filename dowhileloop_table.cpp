#include<iostream>
using namespace std;
int main(){
   int i;
   int j=1;
   cout<<"Enter the number "<<i;
   cin>>i;
   do{
    cout<<i<<"x"<<j<<"="<<i*j<<endl;
    j++;
   }while(j<=10);
}