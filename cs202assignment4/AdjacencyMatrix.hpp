#ifndef ADJACENCY_MATRIX
#define ADJACENCY_MATRIX 1
#include "GraphAdjacencyBase.hpp"
#include <vector>
using namespace std;

class AdjacencyMatrix : public GraphAdjacencyBase{
	private:
		int size;
		int **AdjMat;
	public:
		AdjacencyMatrix(int vertices);
		bool edgeExists(int i, int j) ;
		int edges() ;
		int vertices() ;
		void add(int i, int j);
		void remove(int i, int j) ;
		int degree(int i);  
};
AdjacencyMatrix:: AdjacencyMatrix(int vertices){
	size = vertices;
	AdjMat =new int*[size];
}
bool AdjacencyMatrix:: edgeExists(int i,int j){
	return (AdjMat[i][j]==1);
}
int AdjacencyMatrix:: vertices(){
	return size;
}
int AdjacencyMatrix:: edges(){
	int count=0;
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(AdjMat[i][j]==1) count+=1; 
		}
	}
	return count;
}
void AdjacencyMatrix:: add(int i,int j){
	AdjMat[i][j]=1;
}
void AdjacencyMatrix:: remove(int i,int j){
	AdjMat[i][j]=0;
}
int AdjacencyMatrix:: degree(int i){
	int count=0;
	for(int j=0;j<size;j++){
		if(AdjMat[i][j]==1) count+=1;
		if(AdjMat[j][i]==1) count==1;
	}
	return count;
}
#endif /* ifndef ADJACENCY_MATRIX */
