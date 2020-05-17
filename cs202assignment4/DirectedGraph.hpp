#ifndef DIRECTED_GRAPH
#define DIRECTED_GRAPH 1
#include <bits/stdc++.h>
#include <stack>
#include <queue>
#include "AbstractGraph.hpp"
#include "AdjacencyList.hpp"
#include "AdjacencyMatrix.hpp"

class DirectedGraph :public AbstractGraph {
	private:
		char repre;
		AdjacencyMatrix *matrix;
		AdjacencyList *list;
	public:
		DirectedGraph(int numVertices, char repre);
		bool edgeExists(int i, int j) ;
		int edges() ;
		int vertices();
		void add(int i, int j);
		void remove(int i, int j) ;
		void dfs(int i) ;
		void bfs(int i) ;	
};
DirectedGraph:: DirectedGraph(int numVertices, char repre){
	if(repre=='l'){
		list=new AdjacencyList(numVertices);
	}
	else if(repre=='m'){
		matrix= new AdjacencyMatrix(numVertices);
	}
	else cout<<"Please enter either l or m"<<endl;
}
bool DirectedGraph:: edgeExists(int i,int j){
	if(repre=='l'){
		return list->edgeExists(i,j);
	}
	else return matrix->edgeExists(i,j);
}
int DirectedGraph:: edges(){
	if(repre=='l'){
		return list->edges();
	}
	else return matrix->edges();
}
int DirectedGraph:: vertices(){
	if(repre=='l'){
		return list->vertices();
	}
	else return matrix->vertices();
}
void DirectedGraph:: add(int i,int j){
	if(repre=='l'){
		list->add(i,j);
	}
	else matrix->add(i,j);
}
void DirectedGraph:: remove(int i,int j){
	if(repre=='l'){
		list->remove(i,j);
	}
	else matrix->remove(i,j);
}

void DirectedGraph:: dfs(int i){
	int size = this->vertices();
	vector<bool> visit(size,false);//initially vertices not visited
	stack<int> stk;// stack initialized
	stk.push(i);// root pushed
	while(!stk.empty()){
		i = stk.top();
		cout<<i;
		stk.pop();
		if(!visit[i]){
			for(int j=0;j<size;j++){
				if(edgeExists(i,j)&& visit[j]==false){
					stk.push(j);
				}
			}
			
		}
		visit[i]=true;
	}
}


void DirectedGraph:: bfs(int i){
	int size=this->vertices();
	queue<int> que;
	vector<bool> visit(size,false);
	que.push(i);
	while(!que.empty()){
		int front= que.front();
		que.pop();
		cout<<front<<endl;
		if(!visit[i]){
			for(auto j=0;j<size;j++){
				if(edgeExists(i,j)&& visit[j]==false){
					que.push(j);
					visit[j]=true;
				}
			}
		}
		visit[i]=true;
	}
}

#endif /* ifndef DIRECTED_GRAPH */
