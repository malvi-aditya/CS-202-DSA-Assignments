#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
    int gap;
    int mis;
    if(argv[1][0]== '1'){// 1 or 2 passed in command line
        gap=6;// gap penalty
        mis=4;// mismatch penalty
    }
    else{
        gap=4;
        mis=6;
    }
    string x="_";
    string y="_";
    cout<<"Input first string:  ";
    cin>>x;// string x input
    cout<<"Input second string: ";
    cin>>y;// string y input
    int m=x.size(),n=y.size();
    int mat[m+1][2];
    for(int i=0;i<m+1;i++){
        for(int j=0;j<=1;j++)
        {
            if(i==0|| j==0){
                mat[i][j]=(i+j)*gap;
            }
        }
    }
    for(int j=1;j<n+1;j++){
        mat[0][1]=j*gap;
        for(int i=1;i<m+1;i++){
              if(x[i-1]==y[j-1]){// when two character match,previous diagonal value
                mat[i][1]=mat[i-1][0];
            }
            else{
                mat[i][1]=(min(min(mat[i][0]+gap,mat[i-1][1] + gap),mat[i-1][0]+mis));
                // min cost of the three path approaches possible
            }
        }
        for(int i=0;i<m+1;i++){
            mat[i][0]=mat[i][1];
        }
        
    }
    cout<<endl;
    cout<<"Minimized Cost: "<<mat[m][1];
    return 0;
}
    