// �������.cpp : �������̨Ӧ�ó������ڵ㡣
//
// ͼ���ڽӱ��ʾ.cpp : �������̨Ӧ�ó������ڵ㡣
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
	void DFSTraverse();
private:
	EdgeNode<T> *adjlist[100];   //����
	int n;  //������
	int e;   //����
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
void Graph<T>::DFSTraverse()
{
	stack <EdgeNode<T>> s;
	int a[100]= {0};
	s.push(*adjlist[0]);
	int i=1;
	int flag=0;
	while(!s.empty()&&flag==0)   //
	{
		EdgeNode<T> *node ;
		node = &s.top();
		cout<<"->"<<node->adjvex;

		if (!s.empty())
		{
			s.pop();
		}

		while(node!=NULL)
		{

			int flag = 0;
			for (int i=0;i<n;i++)
			{
				if (adjlist[i]->adjvex==node->adjvex&&a[i]==0)
				{
					//cout<<" "<<adjlist[i]->adjvex;
					s.push(*adjlist[i]);
					a[i]=1;
				}
			}
			node=node->pnext;
		}

		
	}

}

template<class T>
void Graph<T>::BFSTraverse()
{
	queue<EdgeNode<T>> q;
	int a[100]= {0};
	q.push(*adjlist[0]);
	int i=1;
	int flag=0;
	while(!q.empty()&&flag==0)   //�õ���ӣ�������һ�㣬���ڽӽ����ӣ�δ���������ڽӽ�㣩��ֱ�����е㶼��������
	{

		EdgeNode<T> *node ;
		node = &q.front();    //Ϊɶ��&
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
	cout<<"���붥����";
	cin>>i;
	cout<<endl;
	n=i;
	for (i = 0;i<n;i++)
	{
		T data;
		cout<<"���붥��ֵ";
		cin>>data;
		adjlist[i] = new EdgeNode<T>;
		adjlist[i]->adjvex = data;
		adjlist[i]->pnext = NULL;

		cout<<adjlist[i]->adjvex<<endl;
		//adjlist++;


	}

	cout<<"�������";
	cin>>e;
	for (int i=0;i<e;i++)
	{
		int from;
		int to;
		cout<<endl<<"������㣨�ڵ���ţ�";
		cin>>from;
		cout<<endl<<"�����յ㣨�ڵ���ţ�";
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
	//g.BFSTraverse();
	g.DFSTraverse();
	system("pause");
	return 0;
}


