// 26���·��dijstra.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <iostream>
using namespace std;
const int N=1000;
/*
��Դ���·��:Dijkstra�㷨
�㷨˼��:
��Դ�㿪ʼ,ÿ�κϲ�����Դ�����ڼ�������ĵ㵽Դ�㼯��,������dis[]��¼,
�ϲ�֮��Ӧ���ɳ�ԭ�����dis[]��ֵ.ֱ�����еĵ����Դ�㼯��,���߷�����ͼ����ͨ.
Ӧ�÷�Χ:
����ͼ,�ߵ�Ȩֵ�Ǹ�.
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
n:ͼ�н�����
link:ͼ���ڽӱ��ʾ
dis:��ž��������
pre:��Ž��ǰ��������
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