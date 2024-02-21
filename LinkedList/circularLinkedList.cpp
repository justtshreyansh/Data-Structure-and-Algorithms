#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node * next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertNode(Node *&tail,int element,int data){
    //if the linked list is empty
    if(tail==NULL){
        Node * newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else{
        //if linked list is not empty
        Node * curr =tail;

        while(curr->data!=element){
            curr = curr->next;
        }

        Node * newNode = new Node(data);
        newNode->next = curr->next;
        curr->next = newNode;

    }
}
void print(Node *tail){
    Node * temp = tail;
   do{
        cout<<tail->data<<" ";
        tail = tail->next;
   }
   while(tail!=temp);
        
   
   cout<<endl;
    
}
int main(){
    Node * tail = NULL;
    insertNode(tail,1,1);
    insertNode(tail,1,4);
    insertNode(tail,4,7);
    
    insertNode(tail,7,9);
    insertNode(tail,4,6);
    print(tail);

    return 0;
}