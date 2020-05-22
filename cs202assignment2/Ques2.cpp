#include<iostream>
#include<algorithm>
#include"AVL.hpp"
#include"RBTree.hpp"
using namespace std;

int main(){
    int tu;
    cout<<"Which Tree you want to use:\n";
    cout<<"1. RB Tree\n";
    cout<<"2. AVL Tree\n";
    cin>>tu;
    if(tu==2){
        char c;
        AVL<int,int> a;
        int flag=1;
        while(flag){
            cout<<"(a) Insert a key \n(b) Search for a key \n(c) Delete a key \n(d) Display all the keys as observed in inorder traversal \n
            (e) Display all the keys as observed in preorder traversal \n(f) Display all the keys as observed in postorder traversal \n
            (g) Display all the keys as observed in levelorder traversal \n(h) Display the minimum key in a tree \n(i) Display the maximum key in a tree \n
            (j) Display the succesor of a key \n(k) Display the predecessor of a key \n(l) Display the height of a tree \n(m) Exit\n";
	        cin>>c;
            if(c=='a'){
                int v,k;
                cout<<"Enter the key: ";
                cin>>k;
                cout<<"Enter the value: ";
                cin>>v;
                a.put(k,v);    
            }
            if(c=='b'){
                int k;
                cout<<"Enter the key: ";
                cin>>k;
                cout<<a.key_search(k)<<"\n";
            }
            if(c=='c'){
                int k;
                cout<<"Enter the key: ";
                cin>>k;
                a.remove(k);
            }
            if(c=='d'){
                a.inorder();   
            }
            if(c=='e'){
                a.preorder();
            }
            if(c=='f'){
                a.postorder();
            }
            if(c=='g'){
                a.inorder();
            }
            if(c=='h'){
                cout<<a.get_minimum()<<"\n";
            }
            if(c=='i'){
                cout<<a.get_maximum()<<"\n";
            }
            if(c=='j'){
                int k;
                cout<<"Enter the key: ";
                cin>>k;
                cout<<a.predecessoroftree(k)<<"\n";
            }
            if(c=='k'){
                int k;
                cout<<"Enter the key: ";
                cin>>k;
                cout<<a.successoroftree(k)<<"\n";
            }
            if(c=='l'){
                cout<<a.getHeight()<<"\n";
            }
            if(c=='m'){
                flag=0;
            }
        }
    }
    else{
        RBTree<int,int> a;
        char c;
        int flag=1;
        while(flag){
            cout<<"(a) Insert a key \n(b) Search for a key \n(c) Delete a key \n(d) Display all the keys as observed in inorder traversal \n
            (e) Display all the keys as observed in preorder traversal \n(f) Display all the keys as observed in postorder traversal \n
            (g) Display all the keys as observed in levelorder traversal \n(h) Display the minimum key in a tree \n(i) Display the maximum key in a tree \n
            (j) Display the succesor of a key \n(k) Display the predecessor of a key \n(l) Display the height of a tree \n(m) Exit\n";
	        cin>>c;
            if(c=='a'){
                int v,k;
                cout<<"Enter the key: ";
                cin>>k;
                cout<<"Enter the value: ";
                cin>>v;
                a.put(k,v);
            }
            if(c=='b'){
                int k;
                cout<<"Enter the key: ";
                cin>>k;
                cout<<a.key_search(k)<<"\n";
            }
            if(c=='c'){
                int k;
                cout<<"Enter the key: ";
                cin>>k;
                a.remove(k);
            }
            if(c=='d'){
                a.inorder();
            }
            if(c=='e'){
                a.preorder();
            }
            if(c=='f'){
                a.postorder();
            }
            if(c=='g'){
                a.inorder();
            }
            if(c=='h'){
                cout<<a.get_minimum()<<"\n";
            }
            if(c=='i'){
                cout<<a.get_maximum()<<"\n";
            }
            if(c=='j'){
                int k;
                cout<<"Enter the key: ";
                cin>>k;
                cout<<a.predecessoroftree(k)<<"\n";
            }
            if(c=='k'){
                int k;
                cout<<"Enter the key: ";
                cin>>k;
                cout<<a.successoroftree(k)<<"\n";
            }
            if(c=='l'){
                cout<<a.getHeight()<<"\n";
            }
            if(c=='m'){
                flag=0;
            }
        } 
    }
	return 0;
}
