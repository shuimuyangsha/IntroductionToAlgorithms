// ͼ���ڽӱ��ʾ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <iostream>
#include <stack>
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
		node->adjvex = adjlist[to]->adjvex;
		node->pnext = adjlist[from];
		adjlist[from] = node;
	}


	
}


int main(int argc, char* argv[])
{
	Graph<int> g;
	g.CreatALGraph();
	
	system("pause");
	return 0;
}

