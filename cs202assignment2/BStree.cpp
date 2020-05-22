#include<iostream>
using namespace std;

class BST {
    struct node {
        int value;
        node* left;
        node* right;
    };
    node* root;

    /**********************************/
    int height(node * root){
        if(root==NULL)
            return 0;
        int leftheight=height(root->left);
        int rightheight=height(root->right);
        if(leftheight > rightheight)
            return(leftheight+1);
        else
            return (rightheight+1);
    }
    /**********************************/
    
    void level(node *root,int h){
        if(!root)
            return ;
        if(h==1)
            cout<<root->value<<" ";
        level(root->left,h-1);
        level(root->right,h-1);
    }
    void LevelOrder(node * root){
        int n=height(root);
        for(int i=1;i<=n;i++){
            level(root,i);  
        }
    }
    /**********************************/
    node* value_insert(int x, node* t){
        if(t == NULL){
            t = new node;
            t->value = x;
            t->left = t->right = NULL;
        }
        else if(x < t->value)
            t->left = value_insert(x, t->left);
        else if(x > t->value)
            t->right = value_insert(x, t->right);
        return t;
    }

    /**********************************/
    
    node* get_min(node* t){
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return get_min(t->left);
    }

    /**********************************/
    node* get_max(node* t) {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return get_max(t->right);
    }
    
    /**********************************/
    node* get_val(node* t,int x){
        if (t==NULL)  return NULL;
        else if(t->value<x)
            return get_val(t->right, x);
        else if (t->value<x)
            return get_val(t->left, x);
        else
            return t;
    }
    
    /**********************************/
    
    void get_sc(node* root, node*& succ, int key){
        if (root == nullptr) {
            succ = nullptr;
            return;
        }
        if (root->value == key){
            if (root->right)
                succ = get_min(root->right);
        }
        else if (key < root->value){
            succ = root;
            get_sc(root->left, succ, key);
        }
        else
            get_sc(root->right, succ, key);
    }
    
    /**********************************/
    
    void get_predecessor(node* root, node*& succ, int key){
        if (root == nullptr) {
            succ = nullptr;
            return;
        }
        if (root->value == key){
            if (root->left)
                succ = get_max(root->left);
        }
        else if (key < root->value){
            get_predecessor(root->left, succ, key);
        }
        else{
            succ = root;
            get_predecessor(root->right, succ, key);
        }
    }
    
    /**********************************/
    
    node* value_remove(int x, node* t) {
        node* temp;
        if(t == NULL)
            return NULL;
        else if(x < t->value)
            t->left = value_remove(x, t->left);
        else if(x > t->value)
            t->right = value_remove(x, t->right);
        else if(t->left && t->right){
            temp = get_min(t->right);
            t->value = temp->value;
            t->right = value_remove(t->value, t->right);
        }
        else{
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }

        return t;
    }
    
    node* deletetree(node* t) {
        if(t == NULL)
            return NULL;
        deletetree(t->left);
        deletetree(t->right);
        delete t;
        return NULL;
    }
    
    /**********************************/
    void intraversal(node* t) {
        if(t == NULL)
            return;
        intraversal(t->left);
        cout << t->value << " ";
        intraversal(t->right);
    }

    /**********************************/

    void pretraversal(node* t) {
        if(t == NULL)
            return;
        cout << t->value << " ";
        pretraversal(t->left);
        pretraversal(t->right);
    }

    /**********************************/

    void posttraversal(node* t) {
        if(t == NULL)
            return;
        posttraversal(t->left);
        posttraversal(t->right);
        cout << t->value << " ";
    }

    /**********************************/

    node* value_find(node* t, int x) {
        if(t == NULL)
            return NULL;
        else if(x < t->value)
            return value_find(t->left, x);
        else if(x > t->value)
            return value_find(t->right, x);
        else
            return t;
    }
    int sizeoftree;

public:
    BST() {
        root = NULL;
        sizeoftree=0;
    }

    ~BST() {
        root = deletetree(root);
    }

    void value_insert(int x) {
        root = value_insert(x, root);
        sizeoftree++;
    }
    

    void value_remove(int x) {
        root = value_remove(x, root);
        sizeoftree--;
    }

    void intraversal() {
        intraversal(root);
        cout << "\n";
    }
    void pretraversal() {
        pretraversal(root);
        cout << "\n";
    }
    void posttraversal() {
        posttraversal(root);
        cout << "\n";
    }
    void levelorder(){
        LevelOrder(root);
        cout << "\n";
    }
    void search(int x) {
        root = value_find(root, x);
    }
    void sc(int x){
        node* New =NULL;
        get_sc(root, New, x);
        cout<<New->value<<"\n";
    }
    void pd(int x){
        node* New =NULL;
        get_predecessor(root, New, x);
        cout<<New->value<<"\n";
    }
    int height() return height(root);
    int size() return sizeoftree;
    
};

int main() {
    BST tree;
    tree.value_insert(10);
    tree.value_insert(100);
    tree.value_insert(1);
    tree.value_insert(25);
    tree.value_insert(150);
    tree.value_insert(20);
    tree.value_insert(4);
    tree.sc(10);
    tree.pd(10);
    cout<<"Height: "<<tree.height()<<"\n";
    cout<<"Size: "<<tree.size()<<"\n";
    
    //#*********************************
    
    tree.intraversal();
    tree.pretraversal();
    tree.posttraversal();
    tree.levelorder();
    
    //#**********************************
    
    tree.value_remove(20);
    tree.value_remove(25);
    tree.intraversal();
    tree.pretraversal();
    tree.posttraversal();
    tree.levelorder();
    
    //#**********************************
    
    tree.value_remove(150);
    tree.intraversal();
    tree.pretraversal();
    tree.posttraversal();
    tree.levelorder();
    return 0;
}