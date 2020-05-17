#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minNode(vector<int>& weights,vector<bool>& visited){
    int inf=INT_MAX;
    int d=-1;
    for(int i=1;i<weights.size();++i){
        if(weights[i]<inf && !visited[i]){
            inf=weights[i];
            d=i;
        }
    }
    return d;
}

int time(vector<vector<int> >& times, int edge, int k){
    int delay = 0;
    vector<bool> visited(edge+1,false); 
    visited[0]=true;
    vector<vector<int> > graph(edge+1, vector<int>(edge+1, -1));
    for(vector<int>& v : times){
        graph[v[0]][v[1]] = v[2];   
    }
    vector<int> weights(edge+1,INT_MAX);
    weights[k]=0;
    for (int i=0; i<edge; ++i){
        int u=minNode(weights, visited);
        if (u== -1) return -1;
        visited[u] = true; 
        vector<int> child= graph[u];
        for (int v = 1; v < child.size(); ++v){
            if (child[v] == -1) continue;    
            weights[v]=min(weights[v], weights[u] + child[v]);
            }
        }
    for(int i=1; i<weights.size(); ++i){
        if (weights[i]==INT_MAX) cout<< -1;
        delay = max(delay,weights[i]);
    }
    cout<<delay;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int edge,k;
        cout<<"Enter edge: ";
        cin>>edge;
        cout<<"Enter source k: ";
        cin>>k;
 	vector<int> a(3);
        vector<vector<int> > times(edge+1,a);
        for(int i=0;i<edge-1;i++){
            int u,v,w;
            cin>>u>>v>>w;
            times[i][0]=u;
            times[i][1]=v;
            times[i][2]=w;
        }
        time(times,edge,k);  
    }
}