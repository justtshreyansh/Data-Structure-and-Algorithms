#include<bits/stdc++.h>
using namespace std;
//Function for checking precedence
int precedence(char ch){
    if(ch=='^'){
        return 3;
    }
    if(ch=='*' || ch=='/') return 2;
    if(ch=='+' || ch=='-'){
        return 1;
    }
    else return -1;
}
//Function for checking associativity
bool associativity(char ch){
    if(ch=='^') return false;
    return true;
}

string infixToPostfix(string str){
    
    stack<int> st;
    string ans;
    for(int i=0;i<str.size();i++){
        char ch = str[i];
        //if the character is operand push into the stack
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
            ans+=ch;
        }
        //if the character is '(' then push into the stack
        else if(ch=='('){
            st.push(ch);
        }
        //if the character is ')' then pop all the operator until the '(' is found
        else if(ch==')'){
            while(st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop(); //removing the opening braces
        }
        //if the stack in not empty and precedence of incoming is less or equal to the top of stack then pop untill the top of the stack has less precendce
        else{
            while((!st.empty() && precedence(str[i])<precedence(st.top())) || (!st.empty() && precedence(str[i])==precedence(st.top()) && associativity(str[i])==true )  ){
                ans+=st.top();
                st.pop();
            }
            st.push(ch);
        }
        
        
       

   
    }
    //pop all elements of the stack
    while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
    return ans;
}
int main(){
    string ans = "a+b*(c^d-e)^(f+g*h)-i";
    string result = infixToPostfix(ans);
    cout<<result<<endl;
    return 0;
}