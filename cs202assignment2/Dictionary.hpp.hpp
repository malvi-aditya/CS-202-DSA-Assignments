#include"RBTree.hpp"
template<class Key, class Value>
class Dictionary: public RBTree<int ,int>{
	RBTree<int ,int> a;
public:
	Dictionary(){
	}
	virtual ~Dictionary(){};
	virtual bool has(const Key& key){
		return a.has(key);
	}
	virtual void remove(const Key& key){
		a.remove(key);
	}
	virtual Value get(const Key& key){
		return a.get(key);
	}
    virtual void put(const Key& key, const Value& value){
		a.put(key,value);
	}
};
