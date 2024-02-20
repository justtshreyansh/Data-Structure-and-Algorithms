#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node * prev;
    Node * next;

    Node(int data){
        this->data =  data;
        this->next =  NULL;
        this->prev = NULL;

    }
};
int getLength(Node *&head){
    Node * temp = head;
    int count =0;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
void insertAtHead(Node *&head,int data){
    Node * temp = new Node(data);//create a new node
    temp->next = head;//new node next will be head 
    head->prev = temp;//head prev will be temp
    head = temp;//shifting head to the new node
}
void insertAtTail(Node *&tail,int data){
        Node *temp = new Node(data);//create a new node
       
        tail->next = temp;
        temp->prev = tail;
        tail = temp;

}
void insertAtPosition(Node *&head,Node *&tail,int position,int data){
    int length = getLength(head);
    if(position==1) {
        insertAtHead(head,data);
        return ;
    }
    if(position==length+1){
        insertAtTail(tail,data);
        return ;
    }
    Node * malik = head;
    int cnt =1;
    while(cnt<position-1){
        cnt++;
        malik = malik->next;
    }

    Node * temp = new Node(data);
    temp->next = malik->next;
    malik->next->prev = temp;
    malik->next = temp;
    temp->prev= malik;


    
    
}

void deleteNode(Node *&head,int position){
   
    if(position==1) {
        Node *temp = head;
        temp->next->prev=  NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        Node * curr = head;
        Node *prev = NULL;

        int cnt =1;
        while(cnt<position){
           prev = curr;
           curr = curr->next;
            cnt++;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
        
    }
}
void print(Node *&head){
    Node * temp = head;
   
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    Node * head = new Node(50);
    Node * tail = head;
    print(head);
    cout<<"Length:";
    cout<<getLength(head)<<endl;
    insertAtHead(head,40);
    insertAtHead(head,30);
    insertAtHead(head,20);
    insertAtHead(head,10);
    print(head);
    insertAtTail(tail,60);
    insertAtTail(tail,70);
    insertAtTail(tail,80);
    insertAtTail(tail,90);
    print(head);
    insertAtPosition(head,tail,5,41);
    print(head);
    insertAtPosition(head,tail,1,1);
    print(head);
    insertAtPosition(head,tail,12,100);
    print(head);
    deleteNode(head,1);
    print(head);
    deleteNode(head,11);
    print(head);
    deleteNode(head,5);
    print(head);
    return 0;
}