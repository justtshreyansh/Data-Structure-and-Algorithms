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

//function for finding the length of the linked list
int length(Node * head){
    int count =0;
    while(head!=NULL){
        count++;
        head = head->next;
       
    }
    return count;
}
//Function for inserting node at head
void insertAtHead(Node *&head,int data){
    Node * temp = new Node(data);
    temp->next = head; //pointing the address of new node to next node
    head = temp; // shifting the head to the newly created node


}

//Function for inserting at tail 
void insertAtTail(Node *&tail,int data){
    Node * temp = new Node(data);
    tail->next=  temp; //we are shifting the address of temp to the tail
    tail = tail->next; // we are updating the tail to the next node
}
//Function for inserting value at position
void insertAtPosition(Node * head,int position,int data){
        if(position==1){
            insertAtHead(head,data);
            return ;
        }
        int len = length(head);
        if(position==len+1){
            insertAtTail(head,data);
            return ;
        }
        int cnt =1;
        while(cnt<position-1){
            head = head->next;
            cnt++;
        }
        Node * temp = new Node(data);
        temp->next = head->next;//because the next after the new node is stored in new node
        head->next= temp;//
        
}
//Function for deleting node from any position
void deleteNode(Node *&head,int position){
    if(position==1){
        Node * temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;

    }
    else{
        Node * prev= NULL;
        Node * curr = head;
        int cnt =1;
        while(cnt<position){
            prev = curr;
            curr= curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

//Function to reverse a linked list
Node * reverseLinkedList(Node * &head){
    Node * prev = NULL;
    Node * curr = head;
    Node * forward = NULL;
    while(curr!=NULL){
        forward = curr->next;
        curr->next = prev;
        prev=  curr;
        curr = forward;
    }
    return prev;
}
bool SearchElement(Node *head,int element){
    Node * temp = head;
    while(temp!=NULL){
        if(temp->data==element){
            return true;
        }
        temp =  temp->next;
    }
    return false;
}
//Function for printing the linked list
void print(Node * head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;

    }
    cout<<endl;
}

int main(){
    Node * first = new Node(10);
    Node * second = new Node(20);
    Node * third = new Node(30);
    Node * fourth = new Node(40);
    Node * fifth = new Node(50);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;
    print(first);
    int size = length(first);
    cout<<size<<endl;

    insertAtHead(first,9);
    print(first);

    insertAtTail(fifth,51);
    print(first);

    insertAtPosition(first,3,11);
    print(first);

    deleteNode(first,4);
    print(first);
    cout<<"Printing in reverse:"<<endl;
    Node * temp = reverseLinkedList(first);
    print(temp);

    cout<<SearchElement(first,19);
    return 0;
}