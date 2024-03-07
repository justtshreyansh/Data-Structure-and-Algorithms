#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    unordered_map<int,list<int>> adj;
    //adjacency list implementation
    void addEdges(int u,int v,bool direction){
        adj[u].push_back(v);
        if(direction==0) adj[v].push_back(u);


    }

    void printAdj(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }

};
int main(){
    Graph g;
    int nodes;
    cout<<"Enter the number of nodes:"<<endl;
    cin>>nodes;

    int edges;
    cout<<"Enter the number of edges:"<<endl;
    cin>>edges;

    for(int i=0;i<edges;i++){
        int u, v;
        cin>>u>>v;
        g.addEdges(u,v,0);

    }
    g.printAdj();
    return 0;
}