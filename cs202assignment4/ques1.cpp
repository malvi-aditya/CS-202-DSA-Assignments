#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int a[] = {0, 0, 1, 1, 1, -1, -1, -1};
int b[] = {1, -1, 0, 1, -1, 0, 1, -1};

int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cout<<"Enter x and y: ";
        cin>>x>>y;
        cout<<"Enter no. of circles K: ";
        int k;  
        cin>>k;
        cout<<"Enter radius of circles: ";
        int r;
        cin>>r;
        vector<int> X;
        vector<int> Y;
        cout<<"Enter x coordinates of each: ";
        for(int i=0;i<k;i++){
            int z;
            cin>>z;
            X.push_back(z);
        }
        cout<<endl;
        cout<<"Enter y coordinates of each: ";
        for(int i=0;i<k;i++){
            int z;
            cin>>z;
            Y.push_back(z);
        }
        int mat[x+1][y+1];
        for(int i=0; i<x+1;i++){
            for(int j=0; j<y+1; j++) mat[i][j]=0;
        }      

        for(int i=0;i<=x;i++){
          for(int j=0;j<=y;j++){
              for(int k=0;k<r;k++){
                  if(sqrt(pow(X[k]-i, 2) + pow(Y[k]-j, 2)) <= r){
                      mat[i][j]=-1;
                    }
                }
            }
        }
    for(int i=0; i<x+1;i++){
        for(int j=0; j<y+1; j++){
            cout<<mat[i][j];
        }   
        cout<<endl;
    }    
    int flag=1;
    if(mat[0][0]==-1 or mat[x][y]==-1){
        cout<<"NO";
        break;
    }
    queue<pair<int,int> > que;
    que.push(make_pair(0,0));
    mat[0][0]=1;
    while(!que.empty()){
        int p = que.front().first;
        int q = que.front().second;
        que.pop();
        if(p==x && q==y){
            flag=0;
            break;
        }
        for(int i=0;i<8;i++){
            int nx=p+a[i];
            int ny=q+b[i];
            if(nx>=0 && nx<=x && ny>=0 && ny<=y && mat[nx][ny]==0){
                mat[nx][ny] = 1;
                que.push(make_pair(nx,ny));
            }
        }
    }
    if(flag) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    }
    return 0;
}