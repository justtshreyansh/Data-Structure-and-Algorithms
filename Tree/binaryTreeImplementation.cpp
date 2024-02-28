#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node * left;
    Node * right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

};
Node * buildTree(Node * root){
    cout<<"Enter the element:";
    int data;
    cin>>data;
    root = new Node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter the element for the left of: "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the element for the right of:"<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}


void levelOrderTraversal(Node * root){
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node *temp = q.front();
       
        q.pop();

        if(temp==NULL){
            cout<<endl; // level completed
            if(!q.empty()){ //if queue contains element
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }

       
    }
   
}
// NLR Node left right
void preOrderTraversal(Node * root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    
    preOrderTraversal(root->right);
   
}
// LNR left node right
void inOrderTraversal(Node * root){
    if(root==NULL){
        return ;
    }
   
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
   
}
// LRN left right node
void postOrderTraversal(Node * root){
    if(root==NULL){
        return ;
    }
    
    postOrderTraversal(root->left);
    
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
   
}
int main(){
    Node * root = NULL;

    root = buildTree(root);

    // levelOrderTraversal(root);

    cout<<"Preorder traversal:";
    preOrderTraversal(root);
    cout<<endl;

    cout<<"Inorder Traversal:";
    inOrderTraversal(root);
    cout<<endl;

    cout<<"Postorder traversal:";
    postOrderTraversal(root);
    cout<<endl;
    
    return 0;
}
//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1