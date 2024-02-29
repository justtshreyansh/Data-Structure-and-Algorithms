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
void reverseLevelOrderTraversal2(Node * root){
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        if(temp==NULL){
            ans.push_back(0);
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            ans.push_back(temp->data);
            if(temp->right){
                q.push(temp->right);
            }
            if(temp->left){
                q.push(temp->left);
            }
        }



        
    }
    reverse(ans.begin(),ans.end());

    for(int i=0;i<ans.size();i++){
        if(ans[i]==0){
            cout<<endl;
            continue;
        }
        cout<<ans[i]<<" ";
    }
}
void leftTree(Node *root,vector<int> &ans){
    if(!root) return ;
    if(root->left){
        ans.push_back(root->data);
        leftTree(root->left,ans);
    }
    else if(root->right){
        ans.push_back(root->data);
        leftTree(root->right,ans);
    }
}
void leaf(Node * root,vector<int> &ans){
    if(!root) return ;
    leaf(root->left,ans);
    if(!root->left && !root->right) ans.push_back(root->data);
    leaft(root->right,ans);
}

void rightTree(Node* root,vector<int> &ans){
    if(!root) return;
    if(root->right){
        rightTree(root->right,ans);
        ans.push_back(root->data);
    }
    else if(root->left){
        rightTree(root->left,ans);
        ans.push_back(root->data);
    }

}
vector<int> boundaryTraversal(Node * root){
    vector<int> ans;
    ans.push_back(root->data);
    leftTree(root->left,ans);
    leaf(root,ans);
    rightTree(root->right,ans);
    return ans;
    
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

    cout<<"Reverse order traversal:";
    reverseLevelOrderTraversal2(root);
    
    return 0;
}
//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1