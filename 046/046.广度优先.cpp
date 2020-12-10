// 图的邻接表表示.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <stack>
#include <queue>
#include <array>
using namespace std;

template<class T>
class EdgeNode
{
public:
	T adjvex;
	EdgeNode *pnext;
};

template<class T>
class Graph
{
public:
	Graph();
	~Graph();
	void CreatALGraph();
	void BFSTraverse();
private:
	EdgeNode<T> *adjlist[100];   //数组
	int n;  //顶点数
	int e;   //边数
};

template<class T>
Graph<T>::Graph()
{
	//adjlist = new EdgeNode<T>;
}

template<class T>
Graph<T>::~Graph()
{

}
template<class T>
void Graph<T>::BFSTraverse()
{
	queue<EdgeNode<T>> q;
	int a[100]= {0};
	q.push(*adjlist[0]);
	//q.push(adjlist[0]);
	//q.push(adjlist[0]);
	int i=1;
	int flag=0;
	while(!q.empty()&&flag==0)   //该点出队，它的下一层，即邻接结点入队（未遍历过的邻接结点），直到所有点都被遍历到
	{

		EdgeNode<T> *node ;
			node = &q.front();    //为啥是&
		cout<<"->"<<node->adjvex;
		
		node = node->pnext;
		while(node!=NULL)
		{

		    int flag = 0;
			for (int i=0;i<n;i++)
			{
                 if (adjlist[i]->adjvex==node->adjvex&&a[i]==0)
				 {
					 //cout<<" "<<adjlist[i]->adjvex;
                      q.push(*adjlist[i]);
					  a[i]=1;
				 }
			}
			node=node->pnext;
		}
		if (!q.empty())
		{
			q.pop();
		}
		
		
		//for ()
		//{
		//}
		///./q.push(adjlist[i]);
	}
	flag=1;
	for (int i=0;i<n;i++)
	{
		if (a[i]==0)
		{
			flag=0;
		}
	}
	
	




}
template<class T>
void Graph<T>::CreatALGraph()
{
	//EdgeNode<T> *adjlist2 = adjlist;
	int i;
	int j;
	cout<<"输入顶点数";
	cin>>i;
	cout<<endl;
	n=i;
	for (i = 0;i<n;i++)
	{
		T data;
		cout<<"输入顶点值";
		cin>>data;
		adjlist[i] = new EdgeNode<T>;
		adjlist[i]->adjvex = data;
		adjlist[i]->pnext = NULL;

		cout<<adjlist[i]->adjvex<<endl;
		//adjlist++;


	}

	cout<<"输入边数";
	cin>>e;
	for (int i=0;i<e;i++)
	{
		int from;
		int to;
		cout<<endl<<"输入起点（节点序号）";
		cin>>from;
		cout<<endl<<"输入终点（节点序号）";
		cin>>to;
		EdgeNode<T> *node = new EdgeNode<T>;
		EdgeNode<T> *temp =  adjlist[from];
		while(temp->pnext!=NULL)
			temp = temp->pnext;
		node->adjvex = adjlist[to]->adjvex;
		node->pnext = NULL;
		temp->pnext = node;
		
		//adjlist[from] = node;
	}



}


int main(int argc, char* argv[])
{
	Graph<int> g;
	g.CreatALGraph();
	g.BFSTraverse();
	system("pause");
	return 0;
}

