#include <iostream>
#include <bits/stdc++.h>
#include "DirectedGraph.hpp"
#include "UndirectedGraph.hpp"
using namespace std;

void dfs(int i,int j,int n,int m, vector<vector<bool> > visited, vector<vector<int> > mat){
    if(i<0||j<0||i>n||j>m) return;
    if(mat[i][j]!=0) return;
    visited[i][j]=false;
    dfs(i+1,j,n,m,visited,mat);
    dfs(i,j+1,n,m,visited,mat);
    dfs(i-1,j,n,m,visited,mat);
    dfs(i,j-1,n,m,visited,mat);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cout<<"Enter n and m: ";
        cin>>n>>m;
        vector<bool> a(m,false);
        vector<vector<bool> > visited(n,a);
        vector<int> aa(m,0);
        vector<vector<int> > mat(n,aa);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int x;
                if(x!=1 || x!=0){
                    cout<< "Enter from 0 or 1 "<<endl;
                    break;
                }
                else cin>>mat[i][j];
                if(mat[i][j]==0) visited[i][j]=true;

            }
        }

        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==true){
                    dfs(i,j,n,m,visited,mat);
                    count++;
                }
            }
        }
        cout<<count<<endl;
    }
}