#include<bits/stdc++.h>
using namespace std;
int main(){
   
    int arr[100];
    int size;
    cout<<"Enter the size of the array:";
    cin>>size;
    //taking input of array
    cout<<"Enter the elements of the array:";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"Enter position at which you want to delete:";
    int position;
    cin>>position;
    int deletedElement = arr[position];
    bool flag = false;
    if(position<0 || position>=size){
        cout<<"Invalid position"<<endl;
    }
    else{
        flag = true;
        for(int i=position;i<size;i++){
            arr[i] = arr[i+1];
        }
        size--;
    }
    cout<<"Printing the array:";
    for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
    }
    cout<<endl;
    if(flag){
        cout<<"Deleted Element is:"<<deletedElement<<endl;
    }
    else{
        cout<<"No element is deleted"<<endl;
    }
   
    return 0;
}