#ifndef UNDIRECTED_GRAPH
#define UNDIRECTED_GRAPH 1

#include <bits/stdc++.h>
#include <stack>
#include "AbstractGraph.hpp"
#include "AdjacencyList.hpp"
#include "AdjacencyMatrix.hpp"

class UndirectedGraph : public AbstractGraph {
	private:
		GraphAdjacencyBase *base;
		char repre;
		AdjacencyList *list;
		AdjacencyMatrix *matrix;
 	public:
  		UndirectedGraph(int vertices, char mode);
  		~UndirectedGraph(); 
		bool edgeExists(int i, int j) ;
		int edges() ;
		int vertices() ;
		void add(int i, int j);
		void remove(int i, int j) ;
		void dfs(int i) ;
		void bfs(int i) ;	
};
UndirectedGraph :: UndirectedGraph(int vertices,char mode){
	repre=mode;
	if(repre=='l'){
		list=new AdjacencyList(vertices);
	}
	else if(repre=='m'){
		matrix=new AdjacencyMatrix(vertices);
	}
	else cout<<"Enter from l or m"<<endl;
}
UndirectedGraph:: ~UndirectedGraph(){
	if(repre=='l') delete list;
	else delete matrix;
}
bool UndirectedGraph:: edgeExists(int i,int j){
	if(repre=='l'){
		return list->edgeExists(i,j);
	}
	else return matrix->edgeExists(i,j);
}
int UndirectedGraph::edges(){
	if (repre=='l') return (list->edges())/2;
	else return (matrix->edges())/2;
}
int UndirectedGraph:: vertices(){
	if(repre=='l') return list->vertices();
	else return matrix->vertices();
}
void UndirectedGraph:: add(int i,int j){
	if(repre=='l'){
		list->add(i,j);
		list->add(j,i);
	}
	else{
		matrix->add(i,j);
		matrix->add(j,i);
	}
}
void UndirectedGraph:: remove(int i,int j){
	if(repre=='l'){
		list->remove(i,j);
		list->remove(j,i);	
	}
	else{
		matrix->remove(i,j);
		matrix->remove(j,i);
	}
}

void UndirectedGraph:: dfs(int i){
	int size =this-> vertices();
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

void UndirectedGraph:: bfs(int i){
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

	
#endif /* ifndef UNDIRECTED_GRAPH */
