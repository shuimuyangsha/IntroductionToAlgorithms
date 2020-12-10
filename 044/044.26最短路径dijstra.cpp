// 26最短路径dijstra.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
using namespace std;
const int N=1000;
/*
单源最短路径:Dijkstra算法
算法思想:
从源点开始,每次合并距离源点所在集合最近的点到源点集合,距离用dis[]记录,
合并之后应用松弛原理更新dis[]的值.直到所有的点均在源点集合,或者发现了图不连通.
应用范围:
有向图,边的权值非负.
*/
template <class T>
struct Node
{
	Node(int t=0,T c=0,Node * n=NULL):to(t),cost(c),next(n){}
	int to;
	T cost;
	Node * next;
};
/*
n:图中结点个数
link:图的邻接表表示
dis:存放距离的数组
pre:存放结点前驱的数组
*/
template <class T>
bool Dijkstra(const int & n,Node<T> * link[N],T * dis,int * pre=NULL)
{
	memset(dis,0x3f,sizeof(T)*n);
	if(pre)
		memset(pre,-1,sizeof(int)*n);
	bool vst[N]={false};
	dis[0]=0;
	int i,j;
	for(i=0;i<n;i++)
	{
		T Max=0x3f3f3f3f;
		int idx=-1;
		for(j=0;j<n;j++)
		{
			if(! vst[j] && dis[j]<Max)
			{
				Max=dis[j];
				idx=j;
			}
		}
		if(idx==-1)
			return false;
		vst[idx]=true;
		Node<T> * p=link[idx];
		while(p)
		{
			if(p->cost+dis[idx]<dis[p->to])
			{
				dis[p->to]=p->cost+dis[idx];
				if(pre)
					pre[p->to]=idx;
			}
			p=p->next;
		}
	}
	return true;
}
template <class T>
void AddNode(Node<T> * * arr,int a,int b,T c)
{
	arr[a]=new Node<T>(b,c,arr[a]);
}
int main()
{
	int n;
	int a,b,c;
	Node<int> * link[N];
	memset(link,0,sizeof(link));
	//scanf("%d",&n);
	n=6;
	//while(scanf("%d%d%d",&a,&b,&c)!=EOF)
		AddNode(link,0,1,5);
		//AddNode(link,0,1,4);
		AddNode(link,1,3,1);
		AddNode(link,1,2,6);
		AddNode(link,1,4,16);
		AddNode(link,3,4,1);
		AddNode(link,3,5,9);
		AddNode(link,4,5,1);
	int dis[N],pre[N];
	Dijkstra(n,link,dis,pre);
	for(int i=0;i<n;i++)
		printf("%d %d\n",dis[i],pre[i]);
	system("pause");
	return 0;
}