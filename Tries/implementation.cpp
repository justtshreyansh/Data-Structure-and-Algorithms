#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }


};

class Trie{
    public:
    TrieNode* root;

    void insertAtUtil(TrieNode* root,string str){
        if(word.length()==0){
            root->isTerminal = true;
        }

        int index = word[0]-'A';
        TrieNode * child;
        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertAtUtil(child,word.substr(1));
    }

    void insertWord(string str){
        insertAtUtil(root,str);
    }

};
int main(){
    return 0;
}