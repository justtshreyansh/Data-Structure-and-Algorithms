#include<bits/stdc++.h>
using namespace std;
class Queue{
        public: //access specifiers
        //data members
        int *arr;
        int size;
        int qfront;
        int rear;
        //constructor
        Queue(int size){
            this->size = size;
            arr = new int[size];
            qfront =0;
            rear =0;
        }
        //function members
        bool isEmpty(){
            if(qfront==rear){
                return 1;
            }
            return 0;
        }

        bool isFull(){
            if(rear==size){
                return 1;
            }
            return 0;
        }

        void push(int data){
            if(rear==size){
                cout<<"Queue is already full"<<endl;
            }
            else{
                arr[rear] = data;
                rear++;
            }
        }

        void pop(){
            if(qfront==rear){
                cout<<"Queue is Empty"<<endl;
            }
            else{
                arr[qfront] = -1;
                qfront++;
                if(qfront==rear){
                    qfront =0;
                    rear = 0;
                }
            }
        }

        int front(){
            if(qfront==rear) return -1;
            return arr[qfront];
        }
};
int main(){
   int t;
   cin>>t;
   while(t--){
    int n,query;
    cin>>n>>query;
    Queue q(n);
    while(query--){
        int data;
        cin>>data;
        q.push(data);
        cout<<q.front()<<endl;
        q.pop();
    }

   }
    return 0;
}