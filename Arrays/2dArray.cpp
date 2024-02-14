#include<bits/stdc++.h>
using namespace std;
int main(){

    //row major order
    int arr[100][100];
    cout<<"Enter the row:";
    int row;
    cin>>row;
    cout<<"Enter the column:";
    int column;
    cin>>column;
    cout<<"Enter the elements of the matrix:";
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"Printing the elements of the matrix in row major order:"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    //column major order
    int matrix[100][100];
    cout<<"Enter the row:";
    int n;
    cin>>n;
    cout<<"Enter the column:";
    int m;
    cin>>m;
    cout<<"Enter the elements of the matrix:";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[j][i];
        }
    }
    cout<<"Printing the elements of the matrix in column major order:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}