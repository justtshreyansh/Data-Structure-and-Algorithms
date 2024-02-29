#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node * left;
    Node *right;

    Node(int data){
        this->data  = data;
        this->left = NULL;
        this->right = NULL;
    }

};
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
Node * insertIntoBST(Node * root,int data){
    if(root==NULL){
        root = new Node(data);
        return root;
    }
    if(root->data>data){
        root->left = insertIntoBST(root->left,data);
    }
    else{
        root->right = insertIntoBST(root->right,data);
    }

    return root;
}
Node *searchInBST(Node * root,int target){
    while(root!=NULL){
        if(root->data==target){
            return root;
        }
        else if(root->data<target){
            root = root->right;
        }
        else{
            root = root->left;
        }

    }
    return nullptr;
}

Node *minValue(Node * root){
    
    while(root->left!=NULL){
        root = root->left;
    }
    return root;
}

Node *maxValue(Node * root){
    
    while(root->right!=NULL){
        root = root->right;
    }
    return root;
}
Node *deleteFromBST(Node *root,int val){
    if(root==NULL){
        return root;
    }
    if(root->data==val){
        //0  child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //1 child - right
        if(root->left==NULL && root->right!=NULL){
            Node * temp = root->right;
            delete root;
            return temp;
        }
        //1 child left
        if(root->right==NULL && root->left!=NULL){
            Node * temp = root->left;
            delete root;
            return temp;
        }
        //2 child 
        if(root->left!=NULL && root->right!=NULL){
            int mini = minValue(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right,mini);
            return root;

        }
    }
    else if(root->data>val){
        root->left = deleteFromBST(root->left,val);
    }
    else{
        root->right = deleteFromBST(root->right,val);
    }
}
void takeInput(Node *&root){
    int data;
    cin>>data;
    while(data!=-1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}
int main(){
    Node *root = NULL;
    takeInput(root);
    levelOrderTraversal(root);
    cout<<"Min value is:"<<minValue(root)->data<<endl;
    cout<<"Max value is:"<<maxValue(root)->data<<endl;
    root = deleteFromBST(root,50);

    levelOrderTraversal(root);
    cout<<"Min value is:"<<minValue(root)->data<<endl;
    
    return 0;
}
//50 20 70 10 30 90 110 -1