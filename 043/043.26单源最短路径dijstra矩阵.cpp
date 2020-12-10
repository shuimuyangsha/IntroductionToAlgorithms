// 26单源最短路径dijstra矩阵.cpp : 定义控制台应用程序的入口点。
//
#include <iostream>
#include<stack>
#define M 100
#define N 100
using namespace std;

typedef struct node
{
	int matrix[N][M];      //邻接矩阵 
	int n;                
	int e;                 
}Graph; 

void Dijkstra(Graph g,int *dist,int *path,int v0)   //v0源顶点 
{
	int i,j,k;
	bool visited[100];
	
	for(i=0;i<g.n;i++)     //初始化 
	{
		if(g.matrix[v0][i]>0&&i!=v0)
		{
			dist[i]=g.matrix[v0][i];
			path[i]=v0;     //path记录最短路径上从v0到i的前一个顶点 
		}
		else
		{
			dist[i]=INT_MAX;    //若i不与v0直接相邻，则权值置为无穷大 
			path[i]=-1;
		}
		visited[i]=false;
		path[v0]=v0;
		dist[v0]=0;
	}
	visited[v0]=true;
	for(i=1;i<g.n;i++)     //循环扩展n-1次 
	{
		int min=INT_MAX;
		int u;
		for(j=0;j<g.n;j++)    //寻找未被扩展的权值最小的顶点 
		{
			if(visited[j]==false&&dist[j]<min)
			{
				min=dist[j];
				u=j;        
			}
		} 
		visited[u]=true;
		for(k=0;k<g.n;k++)   //更新dist数组的值和路径的值 
		{
			if(visited[k]==false&&g.matrix[u][k]>0&&min+g.matrix[u][k]<dist[k])
			{
				dist[k]=min+g.matrix[u][k];
				path[k]=u; 
			}
		}        
	}    
}

void showPath(int *path,int v,int v0)   //打印最短路径上的各个顶点 
{
	stack<int> s;
	int u=v;
	while(v!=v0)
	{
		s.push(v);
		v=path[v];
	}
	s.push(v);
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
} 

int main(int argc, char *argv[])
{
	int n,e;     //表示输入的顶点数和边数 
	cout<<"输入顶点数";
	cin>>n;
	cout<<endl<<"输入边数";
	cin>>e;
	while(e!=0)
	{
		int i,j;
		int s,t,w;      //表示存在一条边s->t,权值为w
		Graph g;
		int v0;
		int *dist=(int *)malloc(sizeof(int)*n);
		int *path=(int *)malloc(sizeof(int)*n);
		for(i=0;i<N;i++)
			for(j=0;j<M;j++)
				g.matrix[i][j]=0;
		g.n=n;
		g.e=e;
		for(i=0;i<e;i++)
		{
			cout<<endl<<"输入起点（节点序号）";
			cin>>s;
			cout<<endl<<"输入终点（节点序号）";
			cin>>t;
			cout<<endl<<"输入权值";
			cin>>w;
			g.matrix[s][t]=w;
		}
		v0 = 0;        //输入源顶点 
		Dijkstra(g,dist,path,v0);
		for(i=0;i<n;i++)
		{
			if(i!=v0)
			{
				showPath(path,i,v0);
				cout<<dist[i]<<endl;
			}
		}
	}

	system("pause");
	return 0;
}
