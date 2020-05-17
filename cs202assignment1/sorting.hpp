#ifndef SORTING_HPP
#define SORTING_HPP
#include <iostream>
#include "seqLinearList.hpp"

template<class Item>
class Sort{
	private:
		
	public:
		void insertionSort(LinearList<Item>& A, int low, int high);
		void mergeSort(LinearList<Item>& A, int low, int high);
	 	void quickSort(LinearList<Item>& A, int low, int high);
		int  Partition(LinearList<Item>& A,int low,int high);
        void heapSort(LinearList<Item>& A, int low, int n);
		void merge(LinearList<Item>&A,int low, int mid ,int high);
//		void mergeSort(LinearList<Item>& A, int low, int high);
//            	void quickSort(LinearList<Item>& A, int low, int high);
};
template<class Item>
void Sort<Item>::insertionSort(LinearList<Item>& A, int low, int high){
	for(int j=low+1;j<=high;j++){
		Item key=A[j];
		int i=j-1;
		while(i>=low && A[i]>key){
			A[i+1]=A[i];
			i=i-1;

		}
	A[i+1]=key;
	}
}
template<class Item>
void Sort<Item>::mergeSort(LinearList<Item>& A, int low, int high){
	if(low<high){
		int mid=(low+high)/2;
		mergeSort(A,low,mid);
		mergeSort(A,mid+1,high);
		merge(A,low,mid,high);
	}
}
template<class Item>
void Sort<Item>::merge(LinearList<Item>&A,int low, int mid ,int high){
	int i=low;
	int j=mid+1;
	int k=0;
	int tem[high -mid +1];
	while (i<=mid && j<=high){
		if(A[i]<A[j]){
			tem[k]=A[i];
			k++;
			i++;
		}
		else{
			tem[k]=A[j];
			k++;
			j++;
		}
	}
	while(i<=mid){
		tem[k]=A[i];
		k++;
		i++;
	}
	while(j<=high){
		tem[k]=A[j];
		k++;
		j++;
	}
	for(int t=low;t<=high;t++){
		A[t]=tem[t-low];

	}
}
template<class Item>
int Sort<Item>::Partition(LinearList<Item>& A,int low,int high){
	Item pivot=A[high];
    int i=(low-1);
    for (int j=low; j<=high-1; j++){
        if (A[j] <= pivot){
            i=i+1;
			Item temp=A[i];
			A[i]=A[j];
			A[j]=temp;
        }
    }
		Item temp=A[i+1];
		A[i+1]=A[high];
		A[high]=temp;
    return (i + 1);
}
template<class Item>
void Sort<Item>::quickSort(LinearList<Item>& A, int low, int high){
	if(low<high){
		int mid;
		mid=Partition(A,low,high);
		quickSort(A,low,mid-1);
		quickSort(A,mid+1,high);
	}
}
template<class Item>
void swap(Item* a, Item* b)
{
    Item temp=*a;
    *a=*b;
    *b=temp;
}

template <class Item>
void maxHeapify(LinearList<Item> &A, int i, int n)
{
	int left=2*i+1;
	int right=2*i+2;
	int parent=i;
	if (left<n && A[left]>A[parent]){
		parent=left;
	}
	if (right<n && A[right]>A[parent]){
		parent=right;
	}
	if (parent!=i){
		swap(A[i],A[parent]);
		maxHeapify(A,parent,n);
	}
}
template <class Item>
void Sort <Item>:: heapSort(LinearList<Item>& A, int low, int high){
	int i;
	for (i=((high+1)/2)-1;i>=low;i--){
		maxHeapify(A,i,high+1);
	}
		
	while (high>=low){
		swap(&A[low],&A[high]);
		maxHeapify(A,low,high);
		high--;
	}
}
#endif