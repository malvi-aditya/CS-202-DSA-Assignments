#include <iostream>
using namespace std;
int isMax(int A[],int n)
{// find the max 
    int x=A[0],y=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]>x)
        {
            x=A[i];
            y=i;
        }
    }
    return y;
}
int isMin(int A[],int n)
{// find the min
    int x=A[0],y=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]<x)
        {
            x=A[i];
            y=i;
        }
    }
    return y;
}
int Sum(int A[],int n)
{ // function for calculating sum
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=A[i];
    }
    return sum;
}
int Operation(int A[],int n,int c)
{ // main function for the operation 
int B[n/2],x,r,i=0,k=n-(n/2),C[k];
cout<<"The subarrays are : "<<endl;
for(i ;i<(n/2); i++)
{
    B[i]=A[i];
    cout<<B[i]<<" ";
}
cout<<endl;
for(int j=i;j<n;j++)
{
    C[j-i]=A[j];
    cout<<C[j-i]<<" ";
}
cout<<endl;
int g=Sum(B,n/2),h=Sum(C,k);
if(g>h)
{
    x=(n/2);
} 
else
{
    x=k;
}
cout<<endl;
int D[x];
if(g>h)
{
    for(int j=0;j<(n/2);j++){
        D[j]=B[j];
    }
}
else
{
    for(int j=0;j<k;j++){
        D[j]=C[j];
    }
}
cout<<endl;
for(int j=0;j<x;j++)
{
    cout<<D[j]<<" ";
}
cout<<endl;
if(g>h)
{
    while(c>0)
    {
        int min=isMin(D,x),max=isMax(C,k);
        if(D[min]<C[max])
        {
        int tmp=D[min];
            D[min]=C[max];    
            C[max]=tmp;
        }
    c-=1;
    }
    r=Sum(C,k);
}
else
{
    while(c>0)
    {
    int min=isMin(D,x),max=isMax(B,n/2);
    if(D[min]<B[max])
    {
        int temp=D[min];
            D[min]=B[max];
            B[max]=temp;
    }
    c-=1;
    }
    r=Sum(B,n/2);
}
cout<<endl;
for(int j=0;j<x;j++)
{
    cout<<D[j]<<" ";
}
int sumMax=Sum(D,x);
    cout<<endl;
    cout<<"Sum of unhealthy population "<<r<<endl;// min array
    cout<<"Sum of healthy populaton  "<<sumMax<<endl;// max aaray
    cout<<endl;
    return (sumMax-r);
}
int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<endl;
    int A[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter elements: ";
        cin>>A[i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    int j;
    cout<<"Enter swap number: ";
    cin>>j;
    cout<<endl;
    int t=Operation(A,n,j);
    cout<<"The difference between arrays is "<<t<<endl;
    return 0;
}