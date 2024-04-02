#include<bits/stdc++.h>
using namespace std;
int binarySearch(int arr[],int n,int target){
    int low =0;
    int high = n-1;
   
    while(low<high){
       int mid = (low+high)/2;
       //if element is present at the mid index
       if(arr[mid]==target){
        return mid;
       }
       //if mid element is greater than the target element
       else if(arr[mid]>target){
        high = mid-1;
       }
       //if the mid element in less than the target element
       else low = mid+1;
    }
    return -1;
}
int firstOccurence(int arr[],int n,int target){
        int low = 0;
        int high = n-1;
        int first =-1;
        while(low<=high){
            int mid = (low+high)/2;
            //agar target ke barabar hoga toh first occurence ke liye left side me jayenge
            if(arr[mid]>=target){
                first = mid;
                high = mid-1;
            }
            //agar target se chota ho gaya toh right side me dekhenege
            else if(arr[mid]<target){
                low = mid+1;
            }
            //aur agar target se bada ho gaya toh left side me jayenge
           else high = mid-1;
        }
        return first;
}
int lastOccurence(int arr[],int n,int target){
    int low = 0;
    int high = n-1;
    int last = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==target){
            last = mid;
            low = mid+1;
            
        }
        else if(arr[mid]>target){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return last;
}
int numberOfOccurence(int arr[],int n,int target){
    return lastOccurence(arr,n,target) - firstOccurence(arr,n,target)+1;
}
pair<int,int> firstAndLastOccurence(int arr[],int n,int target){
    return {firstOccurence(arr,n,target),lastOccurence(arr,n,target)};
}
int peakIndexInMountainArray(int arr[],int n){
    int low =0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
            return mid;
        }
        else if(arr[mid]>arr[mid-1]){
            low = mid;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
}


int main(){
    
    return 0;
}