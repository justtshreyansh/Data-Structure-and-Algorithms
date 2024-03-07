#include<bits/stdc++.h>
using namespace std;
//Traditional recursion method
int fib(int n){
    if(n==1 || n==0){
        return n;
    }
    return fib(n-1) + fib(n-2);
}
//top down dp
int fib1(int n,vector<int> &dp){
    if(n<=1) return n;

    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n] = fib1(n-1,dp)+fib1(n-2,dp);
    return dp[n];

}
//bottom up dp
int fib2(int n){
   vector<int> dp(n+1);
   dp[0] = 0;
   dp[1] =1;
   for(int i=2;i<=n;i++){
    dp[i] = dp[i-1] + dp[i-2];

   }
   return dp[n];
}
//space optimisation
int fib3(int n ){
    int first =0;
    int second =1;
    for(int i=2;i<=n;i++){
        int next = first+second;
        first = second;
        second = next;
    }
    return second;
}
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<fib3(n)<<endl;
    return 0;
}