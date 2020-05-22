#include<iostream>
#include<algorithm>
using namespace std;

enum Colour { RED, BLACK };

template <class Key, class Dataue>
class BinaryNode
{
public:
	Key key;
	Dataue data;
	Colour colour;		
	int height;		
	int size;		
	BinaryNode<Key,Dataue> *left, *right, *parent;
	BinaryNode();
	BinaryNode(Key key, Dataue dataue);
};

template <class Key, class Dataue>
BinaryNode<Key,Dataue>::BinaryNode()
{
	this->key= Key();
	this->data= Dataue();
	this->left=NULL;
	this->right=NULL;
	this->parent=NULL;
}

template <class Key, class Dataue>
BinaryNode<Key,Dataue>::BinaryNode(Key key, Dataue dataue)
{
	this->key=key;
	this->data=dataue;
	this->left=NULL;
	this->right=NULL;
	this->parent=NULL;
}

template <class Key, class Dataue>
class RBTree{
protected:
	BinaryNode<Key,Dataue> *root;
	void putRBFixup(BinaryNode<Key,Dataue>* p);
	void deleteRBFixup(BinaryNode<Key,Dataue>* x, BinaryNode<Key,Dataue>* xparent, bool xIsLeft);
public:
	RBTree(){
		this->root=NULL;
	}
	bool has(const Key&key);
	virtual Dataue key_search(const Key &key);
	void put(const Key& key, const Dataue& dataue);
	void remove(const Key& key);
	void printrbtree();
	BinaryNode<Key,Dataue>* rightRotate(BinaryNode<Key,Dataue> *g);
	BinaryNode<Key,Dataue>* leftRotate(BinaryNode<Key,Dataue> *g);
	virtual Key get_minimum();
	virtual Key get_maximum();
	virtual Key predecessoroftree(const Key& key);
	virtual Key  successoroftree(const Key& key);
	virtual void preorder();
	virtual void inorder();
	virtual void postorder();
	virtual int getHeight();
	int blackHeight(BinaryNode<Key,Dataue>* p);
	BinaryNode<Key,Dataue>* getRoot();
};

template<class Key, class Dataue>
BinaryNode<Key,Dataue>* RBTree<Key,Dataue>::getRoot()
{
	return (this->root);
}

template<class Key,class Dataue>
int size(BinaryNode<Key,Dataue>* p)
{
	int pl,pr;
	if (p==NULL)
		return 0;
	if (p->left==NULL)
		pl=0;
	else
		pl=p->left->size;
	if (p->right==NULL)
		pr=0;
	else
		pr=p->right->size;
	return 1+pl+pr;
}

template<class Key,class Dataue>
void sizeUpdate(BinaryNode<Key,Dataue>* p)
{
	while (p!=NULL)
	{
		p->size=1+size(p->left)+size(p->right);
		p=p->parent;
	}
}

template <class Key, class Dataue>
BinaryNode<Key,Dataue>* RBTree<Key,Dataue>::rightRotate(BinaryNode<Key,Dataue>* g)
{
	BinaryNode<Key,Dataue> *p=g->left;
	p->parent=g->parent;
	if (g->parent==NULL) 
		this->root=p;
	else if (g->parent->left==g) 
		g->parent->left=p;
	else if (g->parent->right==g) 
		g->parent->right=p;
	BinaryNode<Key,Dataue> *rchild=p->right;
	if (rchild)
		rchild->parent=g;
	g->parent=p;
	g->left=rchild;
	p->right=g;
	p->size=g->size;
	g->size=1+size(g->left)+size(g->right);
	return p;
}

template <class Key, class Dataue>
BinaryNode<Key,Dataue>* RBTree<Key,Dataue>::leftRotate(BinaryNode<Key,Dataue>* g)
{
	BinaryNode<Key,Dataue> *p=g->right;
	p->parent=g->parent;
	if (g->parent==NULL) // g root
		this->root=p;
	else if (g->parent->left==g) //g left child
		g->parent->left=p;
	else if (g->parent->right==g) //g right child
		g->parent->right=p;
	BinaryNode<Key,Dataue> *lchild=p->left;
	if (lchild)
		lchild->parent=g;
	g->parent=p;
	g->right=lchild;
	p->left=g;
	p->size=g->size;
	g->size=1+size(g->left)+size(g->right);
	return p;
}

template <class Key, class Dataue>
void RBTree<Key,Dataue>::putRBFixup(BinaryNode<Key,Dataue>* p)
{
	if (p==this->root)
		p->colour=BLACK;
	else if (p->parent->colour!=BLACK)  // problem only when parent is red of red
	{
		//Find parent's sibling (uncle)
		BinaryNode<Key,Dataue> *unc;
		if (p->parent->parent==NULL)
			unc=NULL;
		else
		{
			if (p->parent->parent->right==p->parent)
				unc=p->parent->parent->left;
			else
				unc=p->parent->parent->right;
		}

		if (unc && unc->colour==RED) // uncle present with colour red
		{
			unc->colour=BLACK;
			p->parent->colour=BLACK;
			p->parent->parent->colour=RED;
			putRBFixup(p->parent->parent);
		}
		else // uncle present with colour black or no uncle present
		{
			BinaryNode<Key,Dataue> *pa=p->parent;
			BinaryNode<Key,Dataue> *gpa=p->parent->parent;
			if (p==pa->left && pa==gpa->left) //LL
			{
				rightRotate(gpa);
				swap(pa->colour, gpa->colour);
			}
			else if (p==pa->right && pa==gpa->right) //RR
			{
				leftRotate(gpa);
				swap(pa->colour, gpa->colour);
			}
			else if (p==pa->right && pa==gpa->left) //LR
			{
				leftRotate(pa);
				rightRotate(gpa);
				swap(p->colour, gpa->colour);
			}
			else if (p==pa->left && pa==gpa->right) //RL
			{
				rightRotate(pa);
				leftRotate(gpa);
				swap(p->colour, gpa->colour);
			}
		}
	}
	this->root->colour=BLACK;
}
template <class Key, class Dataue>
BinaryNode<Key,Dataue>* putUtil(BinaryNode<Key,Dataue>* p, const Key& key, const Dataue& dataue)
{
	if (p==NULL)
		p = new BinaryNode<Key, Dataue>(key,dataue);
	else if (key<p->key)
	{
		p->left=putUtil(p->left,key,dataue);
		p->left->parent=p;
	}
	else if (key>=p->key)
	{
		p->right=putUtil(p->right,key,dataue);
		p->right->parent=p;
	}
	return p;
}
template <class Key, class Dataue>
BinaryNode<Key,Dataue>* findUtil(BinaryNode<Key,Dataue> *p, const Key &key)
{
	if (p==NULL)
		return NULL;
	else if (key<p->key)
		return findUtil(p->left,key);
	else if (key>p->key)
		return findUtil(p->right,key);
	else
		return p;
}

template <class Key, class Dataue>
void RBTree<Key,Dataue>::put(const Key& key, const Dataue& dataue)
{
	this->root = putUtil(this->root,key,dataue); 	// BST put
	BinaryNode<Key,Dataue> *p = findUtil(this->root, key);
	p->colour=RED; 		// set colour of puted node to RED
	sizeUpdate(p);
	putRBFixup(p); 	// recolour or rotate
}

template <class Key, class Dataue>
int RBTree<Key,Dataue>::blackHeight(BinaryNode<Key,Dataue>* p)
{
	if (p==NULL)
		return 0;
	if (p->colour==BLACK)
		return 1+blackHeight(p->left);
	else
		return blackHeight(p->left);
}

template <class Key, class Dataue>
bool isRed(BinaryNode<Key,Dataue> *p)
{
	if (p==NULL)
		return false;
	return (p->colour==RED);
}

template <class Key, class Dataue>
bool isBlack(BinaryNode<Key,Dataue> *p)
{
	if (p==NULL)
		return true;
	return (p->colour==BLACK);
}

template <class Key, class Dataue>
void RBTree<Key,Dataue> :: deleteRBFixup(BinaryNode<Key,Dataue>* x, BinaryNode<Key,Dataue>* xparent, bool xIsLeft)
{
	BinaryNode<Key,Dataue> *w;
	while (x!=this->root && isBlack(x))
	{
		if (xIsLeft)
		{
			w=xparent->right;	// w is sibling
			if (isRed(w))
			{
				w->colour=BLACK;
				xparent->colour=RED;
				leftRotate(xparent);
				w=xparent->right;
			}
			if (isBlack(w->left) && isBlack(w->right))
			{
				w->colour=RED;
				x=xparent;
				xparent=x->parent;
				xIsLeft=(xparent!=NULL && x==xparent->left);
			}
			else
			{
				if (isBlack(w->right))
				{
					w->left->colour=BLACK;
					w->colour=RED;
					rightRotate(w);
					w=xparent->right;
				}
				w->colour=xparent->colour;
				xparent->colour=BLACK;
				if (w->right!=NULL)
					w->right->colour=BLACK;
				leftRotate(xparent);
				x=this->root;
				xparent=NULL;
			}
		}
		else
		{
			w=xparent->left;	// w is sibling
			if (isRed(w))
			{
				w->colour=BLACK;
				xparent->colour=RED;
				rightRotate(xparent);
				w=xparent->left;
			}
			if (isBlack(w->right) && isBlack(w->left))
			{
				w->colour=RED;
				x=xparent;
				xparent=x->parent;
				xIsLeft=(xparent!=NULL && x==x->parent->left);
			}
			else
			{
				if (isBlack(w->left))
				{
					w->right->colour=BLACK;
					w->colour=RED;
					leftRotate(w);
					w=xparent->left;
				}
				w->colour=xparent->colour;
				xparent->colour=BLACK;
				if (w->left!=NULL)
					w->left->colour=BLACK;
				rightRotate(xparent);
				x=this->root;
				xparent=NULL;
			}
		}
	}
	if (x!=NULL)
		x->colour=BLACK;
}

template<class Key, class Dataue>
void RBTree<Key, Dataue>::remove(const Key& key)
{
	BinaryNode<Key,Dataue> *xparent, *x, *y, *p = findUtil(this->root, key);
	if (p->left==NULL || p->right==NULL)  // always delete single child or no child node y
		y=p;
	else
		y=findUtil(this->root,succUtil(this->root,p));
	if (y->left)	// x is child of y that replaces y
		x=y->left;
	else
		x=y->right;
	if (x!=NULL)
		x->parent=y->parent;
	xparent=y->parent;   // used to pass parent to fixup when x is null
	bool yIsLeft=false;
	if (y->parent==NULL)
		this->root=x;
	else if (y->parent->left==y)
	{
		y->parent->left=x;
		yIsLeft=true;
	}
	else
	{
		y->parent->right=x;
		yIsLeft=false;
	}
	if (y!=p)				//replace contents of succ y to p and then delete y
	{
		p->key=y->key;
		p->data=y->data;
	}
	if (y->colour==BLACK)   // fixup needed only when node deleted was black
		deleteRBFixup(x,xparent,yIsLeft);  //xparent,yIsLeft is passed for cases where x is NIL node as this code does not use NIL node implementation
}

template <class Key, class Dataue>
void printrb(BinaryNode<Key,Dataue> *root)
{
	if(root==NULL)
		return;
	cout<<(root->key)<<" "<<(root->data)<<" "<<(root->colour)<<"\n";
	printrb(root->left);
	printrb(root->right);
}

template <class Key, class Dataue>
void RBTree<Key,Dataue> :: printrbtree()
{
	std::cout<<this->root->colour<<"\n";
	printrb(this->root);
}

template <class Key, class Dataue>
int ghUtil(BinaryNode<Key,Dataue> *p)
{
	if (p==NULL)
		return 0;
	int lh=ghUtil(p->left);
	int rh=ghUtil(p->right);
	if (lh>rh)
		return lh+1;
	else
		return rh+1;
}

template <class Key, class Dataue>
int RBTree<Key,Dataue>::getHeight()
{
	return ghUtil(this->root);
}
template <class Key, class Dataue>
void inorderUtil(BinaryNode<Key,Dataue> *root)
{
	if(root==NULL)
		return;
	inorderUtil(root->left);
	cout<<(root->key)<<" "<<(root->data)<<"\n";
	inorderUtil(root->right);
}
template <class Key, class Dataue>
void RBTree<Key,Dataue>:: inorder()
{
	inorderUtil(this->root);
}

template <class Key, class Dataue>
void preorderUtil(BinaryNode<Key,Dataue> *root)
{
	if(root==NULL)
		return;
	cout<<(root->key)<<" "<<(root->data)<<"\n";
	preorderUtil(root->left);

	preorderUtil(root->right);
}
template <class Key, class Dataue>
void RBTree<Key,Dataue>:: preorder()
{
	preorderUtil(this->root);
}
template <class Key, class Dataue>
void postorderUtil(BinaryNode<Key,Dataue> *root)
{
	if(root==NULL)
		return;
	cout<<(root->key)<<" "<<(root->data)<<"\n";
	postorderUtil(root->right);
	postorderUtil(root->left);


}
template <class Key, class Dataue>
void RBTree<Key,Dataue>:: postorder()
{
	postorderUtil(this->root);
}

template <class Key, class Dataue>
Key RBTree<Key,Dataue>::predecessoroftree(const Key& key)
{
	BinaryNode<Key, Dataue> *p = this->root;
	while (p)
	{
		if (p->key == key)
			break;
		if (p->key > key)
			p = p->left;
		else
			p = p->right;
	}
	if (!p)
		return key;
	if (p->left)
	{
		p = p->left;
		while(p)
		{
			if (!p->right)
				break;
			p = p->right;
		}
		if (!p)
			return key;
		return p->key;
	}
	else
	{
		while (p)
		{
			if (p->key < key)
				return p->key;
			p = p->parent;
		}
		if (!p)
			return key;
	}
    return 0;
}

template <class Key, class Dataue>
Key RBTree<Key,Dataue>:: successoroftree(const Key& key)
{
	BinaryNode<Key, Dataue> *p = this->root;
	while (p)
	{
		if (p->key == key)
			break;
		if (p->key > key)
			p = p->left;
		else
			p = p->right;
	}
	if (!p)
		return key;
	if (p->right)
	{
		p = p->right;
		while (p)
		{
			if (!p->left)
				break;
			p = p->left;
		}
		if (!p)
			return key;
		return p->key;
	}
	else
	{
		while (p)
		{
			if (p->key > key)
				return p->key;
			p = p->parent;
		}
		if (!p)
			return key;
	}
    return 0;
}

template <class Key, class Dataue>
Key minUtil(BinaryNode<Key, Dataue>* p)
{
	if (p==NULL)
		return Key();
	if (p->left==NULL)
		return p->key;
	else
		return minUtil(p->left);
}

template <class Key, class Dataue>
Key RBTree<Key,Dataue>::get_minimum()
{
	return minUtil(this->root);
}

template <class Key, class Dataue>
Key maxUtil(BinaryNode<Key, Dataue>* p)
{
	if (p==NULL)
		return Key();
	if (p->right==NULL)
		return p->key;
	else
		return maxUtil(p->right);
}

template <class Key, class Dataue>
Key RBTree<Key,Dataue>::get_maximum()
{
	return maxUtil(this->root);
}
template <class Key, class Dataue>
Dataue getUtil(BinaryNode<Key,Dataue>* p, const Key& key)
{
	if (p==NULL)
		return Dataue();
	if (p->key==key)
		return p->data;
	else if (p->key<key)
		return getUtil(p->right,key);
	else if (p->key>key)
		return getUtil(p->left,key);
    return 0;
}


template <class Key, class Dataue>
Dataue RBTree<Key,Dataue>::key_search(const Key& key)
{
	return getUtil(this->root, key);
}

template<class Key,class Dataue>
bool RBTree<Key,Dataue>::has(const Key& key){
	Dataue temp1=-101010;
	temp1 = key_search(key);
	if(temp1!=-101010)
 	 	return true;
	else
  		return false;
}

template <class Key, class Dataue>
Key succUtil(BinaryNode<Key,Dataue>* root, BinaryNode<Key,Dataue>* p){
	if (p->right!=NULL)
		return minUtil(p->right);
	if (p->parent==NULL)
	 	return p->key;
	BinaryNode<Key,Dataue>* x=p->parent;
	while (x!=NULL  && p==x->right)
	{
		p=x;
		x=x->parent;
	}
	if (x==NULL)
		return p->key;
	return x->key;
}
