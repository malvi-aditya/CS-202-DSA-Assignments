#include<iostream>
#include<algorithm>
using namespace std;

template <class Key, class Value>
class Binarynode{
public:
	Key key;
	Value val;		
	int height;			
	int size;
	Binarynode<Key,Value> *left, *right, *parent;
	Binarynode();
	Binarynode(Key key, Value value);
};

//#**********************************************#/
template <class Key, class Value>
Binarynode<Key,Value>::Binarynode(Key key, Value value){
	this->key=key;
	this->val=value;
	this->left=NULL;
	this->right=NULL;
	this->parent=NULL;
}

//#**********************************************#/
template <class Key, class Value>
Binarynode<Key,Value>::Binarynode(){
	this->key= Key();
	this->val= Value();
	this->left=NULL;
	this->right=NULL;
	this->parent=NULL;
}

//#**********************************************#/
template <class Key, class Value>
class AVL{
protected:
	Binarynode<Key,Value> *root;
public:
	AVL(){this->root=NULL;} 
	int balance(Binarynode<Key,Value>* p);
	Binarynode<Key,Value>* leftRotate(Binarynode<Key,Value>* p);
	Binarynode<Key,Value>* rightRotate(Binarynode<Key,Value>* p);
	Binarynode<Key,Value>* Delete_value(Binarynode<Key,Value>* p, const Key& key);
	Binarynode<Key,Value>* Insert_value(Binarynode<Key,Value>* root, const Key& key, const Value& value);
	virtual Key get_minimum();
	virtual Key get_maximum();
	virtual void preorder();
	virtual void inorder();
	virtual void postorder();
  	virtual int getHeight();
	bool key_search(const Key&key);
	void put(const Key& key, const Value& value);
	void remove(const Key& key);
	virtual Value get(const Key &key);
	virtual Key predecessoroftree(const Key& key);
	virtual Key successoroftree(const Key& key);
};

//#**********************************************#/

template <class Key, class Value>
int heightoftree(Binarynode<Key,Value> *node){
	if (node==NULL) return 0;
	int rightside=heightoftree(node->right);
	int leftside=heightoftree(node->left);
	if (leftside>rightside) return leftside+1;
	else return rightside+1;
}

template <class Key, class Value>
int AVL<Key,Value>::getHeight(){
	return heightoftree(this->root);
}
//#**********************************************#/

template <class Key, class Value>
int AVL<Key, Value>::balance(Binarynode<Key,Value> *p){
	int leftside,rightside;
	if (p==NULL)
		return 0;
	if (p->left==NULL)
		leftside=0;
	else
		leftside=p->left->height;
	if (p->right==NULL)
		rightside=0;
	else
		rightside=p->right->height;
	return leftside-rightside;
}

//#**********************************************#/

template <class Key, class Value>
Binarynode<Key,Value>* AVL<Key,Value>::leftRotate(Binarynode<Key,Value>* node){
	Binarynode<Key,Value> *x=node->right;
	x->parent=node->parent;
	if (node->parent==NULL) 
		this->root=x;
	else if (node->parent->left==node) 
		node->parent->left=x;
	else if (node->parent->right==node) 
		node->parent->right=x;
	Binarynode<Key,Value> *y=x->left;
	if (y)
		y->parent=node;
	node->parent=x;
	node->right=y;
	x->left=node;
	node->height=max(height(node->left),height(node->right));
	x->height=max(height(x->left),height(x->right));
	return x;
}

template <class Key, class Value>
Binarynode<Key,Value>* AVL<Key,Value>::rightRotate(Binarynode<Key,Value>* node){
	Binarynode<Key,Value> *x=node->left;
	x->parent=node->parent;
	if (node->parent==NULL) 
		this->root=x;
	else if (node->parent->left==node) 
		node->parent->left=x;
	else if (node->parent->right==node) 
		node->parent->right=x;
	Binarynode<Key,Value> *y=x->right;
	if (y)
		y->parent=node;
	node->parent=x;
	node->left=y;
	x->right=node;
	node->height=max(height(node->left),height(node->right));
	x->height=max(height(x->left),height(x->right));
	return x;
}

//#**********************************************#/
template <class Key, class Value>
int height(Binarynode<Key,Value>* p){
	if (p==NULL)
		return 0;
	return p->height;
}

//#**********************************************#/
template <class Key, class Value>
Binarynode <Key,Value>* AVL<Key,Value>::Insert_value(Binarynode <Key,Value> * root ,const Key& key,const Value& value){
	Binarynode <Key,Value> *ptr;
	if(root==NULL){
		ptr=new Binarynode <Key,Value>(key,value);
		ptr->height=1;
		return ptr;
	}
	if(root->key>=key){
		ptr=Insert_value(root->left,key,value);
		ptr->parent=root;
		root->left=ptr;
	}
	else if(root->key<key){
		ptr=Insert_value(root->right,key,value);
		ptr->parent=root;
		root->right=ptr;
	}
	root->height=1+max(height(root->left),height(root->right));
	int bal=balance(root);
	if (bal>1 &&key<root->left->key){
		return rightRotate(root);
	}
	if (bal < -1 && key > root->right->key){
		return leftRotate(root);
	}
	if (bal>1 && key>root->left->key){
		root->left=leftRotate(root->left);
		return rightRotate(root);
	}
	if (bal<-1&&key<root->right->key){
		root->right=rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}

template <class Key, class Value>
void AVL<Key,Value>::put(const Key& key, const Value& value){
	this->root =Insert_value(this->root,key,value);
}

//#**********************************************#/
template <class Key, class Value>
Binarynode<Key,Value>* AVL<Key,Value>::Delete_value(Binarynode<Key,Value>*p, const Key& key){
	if (p==NULL)
		return p;
	if (key<p->key)
		p->left=Delete_value(p->left,key);
	else if (key>p->key)
		p->right=Delete_value(p->right,key);
	else{
		if (p->left==NULL || p->right==NULL) // 1 child or no child
		{
			Binarynode<Key,Value>*tmp=(p->left==NULL)?p->right:p->left;
			if (p!=this->root){
				if (p->parent->left==p) 
					p->parent->left=tmp;
				else if (p->parent->right==p) 
					p->parent->right=tmp;
				if (tmp)
					tmp->parent=p->parent;
			}
			delete p;
			return tmp;
		}
		else  // 2 childs
		{
			Binarynode<Key,Value>*tmp=p->right;
			while (tmp->left!=NULL)
				tmp=tmp->left;
			p->key=tmp->key;
			p->val=tmp->val;
			p->right=Delete_value(p->right,tmp->key);
		}
	}
	int bal=balance(p);
	if (bal>1) //L
	{
		if (balance(p->left)>=0) //LL
			return rightRotate(p);
		else if (balance(p->left)<0) //LR
		{
			p->left=leftRotate(p->left);
			return rightRotate(p);
		}
	}
	else if (bal<-1) //R
	{
		if (balance(p->right)<=0) //RR
			return leftRotate(p);
		else if (balance(p->right)>0)//RL
		{
			p->right=rightRotate(p->right);
			return leftRotate(p);
		}
	}
	return p;
}

//#**********************************************#/
template <class Key, class Value>
void AVL<Key,Value>::remove(const Key& key){
	this->root=Delete_value(this->root,key);
}

//#**********************************************#/
template <class Key, class Value>
void inOrderFunc(Binarynode<Key,Value> *root){
	if(root==NULL)
		return;
	inOrderFunc(root->left);
	cout<<(root->key)<<" "<<(root->val)<<"\n";
	inOrderFunc(root->right);
}
template <class Key, class Value>
void AVL<Key,Value>:: inorder(){
	inOrderFunc(this->root);
}
//#**********************************************#/

template <class Key, class Value>
void preorderfunc(Binarynode<Key,Value> *root){
	if(root==NULL)
		return;
	cout<<(root->key)<<" "<<(root->val)<<"\n";
	preorderfunc(root->left);

	preorderfunc(root->right);
}
template <class Key, class Value>
void AVL<Key,Value>:: preorder(){
	preorderfunc(this->root);
}

//#**********************************************#/
template <class Key, class Value>
void postorderfunc(Binarynode<Key,Value> *root){
	if(root==NULL)
		return;
	cout<<(root->key)<<" "<<(root->val)<<"\n";
	postorderfunc(root->right);
	postorderfunc(root->left);
}
template <class Key, class Value>
void AVL<Key,Value>:: postorder(){
	postorderfunc(this->root);
}

//#**********************************************#/
template <class Key, class Value>
Key minimum_value(Binarynode<Key, Value>* node){
	if (node==NULL)
		return Key();
	if (node->left==NULL)
		return node->key;
	else
		return minimum_value(node->left);
}

template <class Key, class Value>
Key maximum_value(Binarynode<Key, Value>* node){
	if (node==NULL)
		return Key();
	if (node->right==NULL)
		return node->key;
	else
		return maximum_value(node->right);
}

template <class Key, class Value>
Key AVL<Key,Value>::get_minimum(){
	return minimum_value(this->root);
}

template <class Key, class Value>
Key AVL<Key,Value>::get_maximum(){
	return maximum_value(this->root);
}

//#**********************************************#/
template <class Key, class Value>
Value get_value(Binarynode<Key,Value>* p, const Key& key){
	if (p==NULL)
		return Value();
	if (p->key==key)
		return p->val;
	else if (p->key<key)
		return get_value(p->right,key);
	else if (p->key>key)
		return get_value(p->left,key);
    return 0;
}

template <class Key, class Value>
Value AVL<Key,Value>::get(const Key& key){
	return get_value(this->root, key);
}
//#**********************************************#/

template<class Key,class Value>
bool AVL<Key,Value>::key_search(const Key& key){
	Value temp1=-11111;
	temp1 = get(key);
	if(temp1!=-11111) return true;
	return false;
}

//#**********************************************#/
template <class Key, class Value>
Key AVL<Key,Value>::successoroftree(const Key& key){
	Binarynode<Key, Value> *node = this->root;
	while (node){
		if (node->key == key) break;
		if (node->key > key) node = node->left;
		else node = node->right;
	}
	if (!node) return key;
	if (node->right){	
		node = node->right;
		while (node){
			if (!node->left) break;
			node = node->left;
		}
		if (!node) return key;
		return node->key;
	}
	else{	
		while (node){
			if (node->key > key) return node->key;
			node= node->parent;
		}
		if (!node) return key;
	}
    return 0;
}

//#**********************************************#/

template <class Key, class Value>
Key AVL<Key,Value>::predecessoroftree(const Key& key){ 
	Binarynode<Key, Value> *node = this->root;
	while (node){
		if (node->key == key) break;
		if (node->key > key) node = node->left;
		else node = node->right;
	}
	if (!node) return key;
	if (node->left)
	{
		node = node->left;
		while(node)
		{ if (!node->right) break;
		  node = node->right;
		}
		if (!node) return key;
		return node->key;
	}
	else
	{ while (node)
		{
			if (node->key < key)
				return node->key;
			node = node->parent;
		}
		if (!node)
			return key;
			}
    return 0;
	}

//#**********************************************#/