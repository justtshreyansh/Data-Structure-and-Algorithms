#include<bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> boards,int n,int k,int mid){
    int paintersCount =1;
    int boardsCount = 0;
    
    for(int i=0;i<n;i++){
        if(boards[i]+boardsCount<=mid){
            
            boardsCount+=boards[i];
        }
        else{
            paintersCount++;
            if(paintersCount>k || boards[i]>mid){
                return false;
            }
            boardsCount = boards[i];
            
        }
    }
    return true;
}
int paintersPartition(vector<int> boards,int k){
    int low = 0;
    int high = 0;
    int n = boards.size();
    for(int i=0;i<boards.size();i++){
        high+=boards[i];
    }
    int ans = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(isPossible(boards,n,k,mid)){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}
int main(){
    vector<int> boards = {48,90};
    int k =2;
    cout<<paintersPartition(boards,k)<<endl;
    return 0;
}