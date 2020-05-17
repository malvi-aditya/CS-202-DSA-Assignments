#include <iostream>
#include "seqLinearList.hpp"
int k,m=0;
template<class Item>
int opn1(LinearList<Item> &A,LinearList<Item> &B,int h, int n);
template<class Item>
int opn2(LinearList<Item> &A,LinearList<Item> &B,int h, int n);
template<class Item>
int opn3(LinearList<Item> &A,LinearList<Item> &B,int h, int n);
template<class Item>
int opn1(LinearList<Item> &A,LinearList<Item> &B,int h, int n){int p=0;
	for(int i=0;i<h;i++)
		if(A[i]<A[h] && A[i+1]>A[h]){p=i;
			break;
			}
	if(p==0){int p1=0;
		for(int i=0;i<h;i++)
		if(A[i]<A[h]){p1=i;
			break;
			}
		int p2=0;
		for(int i=-1;i<h;i++)
		if(A[i+1]>A[h]){p2=i;
				break;
			}	
		if(p1<p2){p=p1;
        }
		else{p=p2;	
        } 
	}
	Item x=A[h];
	for(int i=h-1;i>p;i--)
			A[i+1]=A[i];
	A[p+1]=x;
	if(n==k){int m1=1;
		for(int i=0;i<A.maxSize();i++)
			if(A[i]!=B[i]){m1=0;
				break;
			}
		if(m1==1)
		m=1;	
	}
	else{
    opn1<Item>(A,B,h+1,n+1);
	opn2<Item>(A,B,h+1,n+1);
	opn3<Item>(A,B,h+1,n+1);
	}
	x=A[p+1];
	for(int i=p+1;i<h;i++)
			A[i]=A[i+1];
			A[h]=x;
		return 0;		
}
template<class Item>
int opn2(LinearList<Item> &A,LinearList<Item> &B,int h, int n){int min=h;
	for(int i=h;i<A.maxSize();i++){
		if(A[i]<A[min])
			min=i;
    }
	Item x=A[h];
	A[h]=A[min];
	A[min]=x;
	if(n==k){int m1=1;
		for(int i=0;i<A.maxSize();i++)
			if(A[i]!=B[i]){
				m1=0;
				break;
			}	
		if(m1==1)
		m=1;	
	}
	else{
	opn1<Item>(A,B,h+1,n+1);
	opn2<Item>(A,B,h+1,n+1);
	opn3<Item>(A,B,h+1,n+1);
	}
	x=A[h];
	A[h]=A[min];
	A[min]=x;
    return 0;
}
template<class Item>
int opn3(LinearList<Item> &A,LinearList<Item> &B,int h, int n){
	LinearList<Item> C(A.maxSize());
	for(int i=0;i<A.maxSize();i++)
		C[i]=A[i];
	for(int i=h;i<A.maxSize()-1;i++){
		if(A[i]>A[i+1]){
		Item x=A[i];
		A[i]=A[i+1];
		A[i+1]=x;
		}
	}
	if(n==k){int m1=1;
		for(int i=0;i<A.maxSize();i++)
			if(A[i]!=B[i]){
				m1=0;
				break;
			}
		if(m1==1)
		m=1;
	}
    else{
	opn1<Item>(A,B,h,n+1);
	opn2<Item>(A,B,h,n+1);
	opn3<Item>(A,B,h,n+1);
	}
    for(int i=0;i<A.maxSize();i++)
		A[i]=C[i];
    return 0;
}
int main(){	
    int h,n;
	cin>>n;
	LinearList<int> a(n);
	LinearList<int> b(n);
    for(int i=0;i<n;i++)
	cin>>a[i];
	cin>>h;
	cin>>k;
    for(int i=0;i<n;i++)
		cin>>b[i];
	opn1<int>(a,b,h+1,1);
	opn2<int>(a,b,h+1,1);
	opn3<int>(a,b,h+1,1);
	if(m==1)
		cout<<"Yes";
	else 
		cout<<"No";
return 0;
}