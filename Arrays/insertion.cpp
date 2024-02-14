#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[100];
    cout<<"Enter the size of the array:";
    int size;
    cin>>size;
    cout<<"Enter the elements of the array:";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"Enter the position at which you want to insert:";
    int position;
    cin>>position;
    cout<<"Enter the elements you want to insert:";
    int insert;
    cin>>insert;
    if(position<0 || position>=size+1){
        cout<<"We cannot insert at invalid positions";
    }
    else{
        for(int i=size-1;i>=position;i--){
            arr[i+1] = arr[i];
        }
        arr[position] =  insert;
        size++;
    }
    cout<<"Printing the array:";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
   

    return 0;
}