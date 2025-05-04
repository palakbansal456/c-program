#include<iostream>
using namespace std;
int main(){
    int arr[5]={4,5,6,7,8};
    int max=arr[0];
    for(int i=1;i<5;i++){
        if(arr[i]>max)
        max=arr[i];
    }
    cout<<"The largest number of an array is: "<<max<<endl;
    return 0;
}
