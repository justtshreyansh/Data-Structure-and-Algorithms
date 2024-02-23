#include<bits/stdc++.h>
using namespace std;
class Stack{
    //data members
    public:
    int *arr;
    int size;
    int top;
    //Constructor
    Stack(int size){
        this->size = size;
        arr = new int[size];
        top =-1;
    }

    //push operation
    void push(int x){
        if(isFull()){
            cout<<"Stack overflow"<<endl;
        }
        else{
            top++;
            arr[top] = x;
        }
    }
    //pop operation
    void pop(){
        if(top==-1){
            cout<<"Stack underflow"<<endl;
        }
        else{
            top--;
        }
    }
    int peek(){
        if(top==-1){
            return -1;
        }
        else{
            return arr[top];
        }
    }
    // int top(){
    //     if(top==-1){
    //         return -1;
    //     }
    //     else{
    //         int x = arr[top];
    //         top--;
    //         return x;
    //     }
    // }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        return false;
    }
    bool isFull(){
        if(top==size-1){
            return true;
        }
        else return false;
    }


};
void print(Stack &s){
    cout<<s.top<<endl;
    s.pop();

}
int main(){
    Stack st(5);
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    st.pop();
    st.push(2);
    st.push(4);
    
   

    return 0;
}