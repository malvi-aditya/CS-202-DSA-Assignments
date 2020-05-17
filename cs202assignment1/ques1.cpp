#include<iostream>
#include "seqLinearList.hpp"
#include "sorting.hpp" 
using namespace std;
int main(){
    int n,t;
    cout<<"Enter the length of array: ";
    cin>>n;
    cout<<"Enter array: ";
    LinearList<int> A(n);
    for(int i=0; i<n; i++){
        cin>>t;
        A.insert(i,t);
    }
    cout<<"The entered LinearList is: ";
   for(int i=0; i<n; i++){
       cout<<A[i]<<" ";
   }
    cout<<"\n";
    Sort<int> sort;
    // sort.insertionSort(A,0,n-1);
    cout<<"The sorted List is: \n";
    cout<<"insertion sort\n";
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    sort.mergeSort(A,0,n-1);
    cout<<"Merge sort\n";
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
    sort.heapSort(A,0,n-1);
    cout<<"Heap sort\n";
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
    sort.quickSort(A,0,n-1);
    cout<<"Quick sort\n";
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
    return 0;
}