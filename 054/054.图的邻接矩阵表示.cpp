// 图的邻接矩阵表示.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>  
#include <list>  
using namespace std; 
#define MAXVEX 10  
#define INFINITY 65535  
typedef struct 
{ 
	char vexs[MAXVEX]; 
	int arc[MAXVEX][MAXVEX]; 
	int numVertexes; 
	int numEdges; 
}MGraph;//图的数据结构，邻接矩阵  
void CreateMGraph(MGraph *pGraph,int &numVexs,int &numEdges) 
{ 
	pGraph->numEdges=numEdges; 
	pGraph->numVertexes=numVexs; 
	for(int i=0;i<numVexs;i++) 
	{ 
		cout<<"输入第"<<i+1<<"个顶点:"; 
		cin>>pGraph->vexs[i]; 
	} 
	for(int i=0;i<numVexs;i++) 
	{ 
		for(int j=0;j<numVexs;j++) 
			pGraph->arc[i][j]=INFINITY; 
	} 
	for(int i=0;i<numEdges;i++) 
	{ 
		int j,k; 
		cout<<"请输入第"<<i+1<<"条边的下标:"; 
		cin>>j>>k; 
		pGraph->arc[j][k]=1; 
		pGraph->arc[k][j]=1; 
	} 
} 
void BFSTravers(MGraph &pGraph) 
{ 
	int num=pGraph.numVertexes; 
	list<int> queue; 
	bool *visited=new bool[num]; 
	for(int i=0;i<num;i++) 
		visited[i]=false; 
	for(int i=0;i<pGraph.numVertexes;i++) 
	{ 
		if(!visited[i]) 
		{ 
			cout<<"访问顶点"<<pGraph.vexs[i]<<endl; 
			visited[i]=true; 
			queue.push_back(i); 
			while(!queue.empty()) 
			{ 
				i=queue.front(); 
				queue.pop_front(); 
				for(int j=0;j<pGraph.numVertexes;j++) 
				{ 
					if(pGraph.arc[i][j]==1&&!visited[j]) 
					{ 
						cout<<"访问顶点"<<pGraph.vexs[j]<<endl; 
						visited[j]=true; 
						queue.push_back(j); 
					} 
				} 
			} 
		} 
	} 
	delete []visited; 
} 
int main(int argc, char* argv[]) 
{ 
	MGraph graph; 
	int numVex; 
	int numEdge; 
	cout<<"输入图的顶点数："; 
	cin>>numVex; 
	cout<<"输入图的边数："; 
	cin>>numEdge; 
	CreateMGraph(&graph,numVex,numEdge); 
	BFSTravers(graph); 
	system("pause"); 
	return 0; 
} 

