#include<bits/stdc++.h>
using namespace std;
class Heap{
    public:
    int *arr;
    int size;

    Heap(){
        arr = new int[100000];
        size =0;
    }
    void insertInHeap(int value){
        size++;
        arr[size] = value;
        int i = size;
        //In insertion first we insert at the last position and then we check for its parent if parent is smaller then we swap and check for parent's parent
        while(i>1){
            int parent = i/2;
            if(arr[parent]<arr[i]){
                swap(arr[parent],arr[i]);
                i = parent;
            }
            else{
                return ;
            }
        }
    }
    void deleteInHeap(){
        if(size==0){
            cout<<"Nothing to delete"<<endl;
            return ;
        }
        arr[1] = arr[size];
        size--;
        int i =1;
        //we remove the last element and place it in root element

        while(i<=size){
            int left = 2*i;
            int right = 2*i+1;
            if(arr[left]>=arr[right] && arr[left]>=arr[i] && left<=size){
                swap(arr[i],arr[left]);
                i = left;
            }
            else if(arr[left]<arr[right] && arr[right]>arr[i] && right<=size){
                swap(arr[right],arr[i]);
                i = right;
            }
            else{
                return ;
            }
        }

    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
    }

};
int main(){
    Heap h1;
    h1.insertInHeap(10);
    h1.insertInHeap(20);
    h1.insertInHeap(30);
    h1.insertInHeap(40);
    h1.insertInHeap(50);
    h1.insertInHeap(60);
    h1.insertInHeap(70);
    h1.insertInHeap(80);
    h1.insertInHeap(90);
    h1.deleteInHeap();
    h1.deleteInHeap();
    h1.deleteInHeap();
    h1.deleteInHeap();
    h1.deleteInHeap();
    h1.deleteInHeap();
    h1.deleteInHeap();
    h1.deleteInHeap();
    h1.deleteInHeap();
    h1.deleteInHeap();


     
     
    
    h1.print();
    return 0;
}