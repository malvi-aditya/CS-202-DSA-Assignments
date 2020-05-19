#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
    int gap;
    int mis;
    if(argv[1][0]== '1'){// 1 or 2 passed in command line
        gap=1;// gap penalty
        mis=1000;// mismatch penalty
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
    int m=x.size(),n=y.size();// two variables each of size corresponding to string declared
    int mat[m+1][n+1];// matrix of size (m+1)*(n+1) declared
    mat[0][0]=0;   
    for(int i=1;i<m+1;i++){
        mat[i][0]=i*gap; //vertical string null,horizontal penalty
    }
    for(int i=1;i<n+1;i++){
        mat[0][i]=i*gap;// horizontal string null, vertical penalty
    }
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(x[i-1]==y[j-1]){// when two character match,previous diagonal value
                mat[i][j]=mat[i-1][j-1];
            }
            else{
                mat[i][j]=(min(min(mat[i][j-1]+gap,mat[i-1][j] + gap),mat[i-1][j-1]+mis));
                // min cost of the three path approaches possible
            }
        }
    }
    cout<<endl;
    cout<<"Minimized cost: "<< mat[m][n]<<endl;
    int mm=m,nn=n;
    string z="_";
    while(!(mm==0 || nn==0)){
        if(x[mm-1]==y[nn-1]){
            mm--;
            nn--;// when elements match
        }
        else if(mat[mm-1][nn-1] + mis == mat[mm][mm]){
            mm--;// mismatch along diagonal
            nn--;
        }
        else if(mat[mm-1][nn] + gap== mat[mm][nn]){
            mm--;// gap  in vertical string
            y.insert(nn,z);
        }
        else if(mat[mm][nn-1] + gap==mat[mm][nn]){
            nn--;// gap in horizontal string
            x.insert(mm,z);
        }
    }
    if(mm!=0){
        for(int i=0; i<mm;i++){
            y.insert(0,z);
        }
    }
    else{
        for(int i=0;i<nn;i++){
            x.insert(0,z);
        }
    }
    // output best alignments of strings
    cout<<"Optimal alignment of strings: "<<endl;
    cout<< "First string:  "<<x<<endl;
    cout<< "Second string: "<<y<<endl;
    return 0;
}
