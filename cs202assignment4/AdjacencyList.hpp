#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST 1
#include "GraphAdjacencyBase.hpp"
#include <iostream>
#include<list>
# define loop(n) for(int i=0;i<n;i++)
using namespace std;

class AdjacencyList : public GraphAdjacencyBase {
	private:
	int size;
	list<int> *AdjList;

	public:
	AdjacencyList(int vertices);
	bool edgeExists(int i, int j) ;
	int edges() ;
	int vertices();
	void add(int i, int j);
	void remove(int i, int j) ;
	int degree(int i);  	
};
AdjacencyList:: AdjacencyList(int vertices){
	size=vertices;
	AdjList=new list<int> [vertices]; 
}
void AdjacencyList :: add(int i,int j){
	AdjList[i].push_back(j);
}
void AdjacencyList :: remove(int i,int j){
	AdjList[i].remove(j);
} 
bool AdjacencyList:: edgeExists(int i,int j){
    list<int>::iterator it;
	it=find(AdjList[i].begin(),AdjList[i].end(),j);
	if(it!=AdjList[i].end()) return true;
	else return false;
}
int AdjacencyList:: vertices(){
	return size;
}
int AdjacencyList:: edges(){
	int count=0;
	int vertices= size;
	loop(vertices){
		count+=AdjList[i].size();
	}
	return count/2; 
}
int AdjacencyList:: degree(int i){
	return AdjList[i].size();
}

#endif /* ifndef ADJACENCY_LIST */
