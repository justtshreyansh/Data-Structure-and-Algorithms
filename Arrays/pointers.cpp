#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[100];
    int size;
    cout<<"Enter the size of the array:";
    cin>>size;
    cout<<"Enter the elements of the array:";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int *p;
    p = arr; //since the name of the array always points to the base address
    cout<<"Printing the elements by both pointers and general method:"<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" "<<*(p+i)<<endl;
    }

    return 0;
}