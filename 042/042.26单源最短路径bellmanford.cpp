// 26��Դ���·��bellmanford.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

#define MAX_VERTEX_NUM    20
#define INFINITY    2147483647 
struct adjVertexNode 
{
	int adjVertexPosition;
	int weight;
	adjVertexNode* next; 
};
struct VertexNode
{
	char data[2];
	int distance;
	VertexNode* path;
	adjVertexNode* list;
}; 
struct Graph
{
	VertexNode VertexNode[MAX_VERTEX_NUM];
	int vertexNum;
	int edgeNum;
};

void CreateGraph (Graph& g)
{
	int i, j, edgeStart, edgeEnd, edgeWeight;
	adjVertexNode* adjNode;
	
	g.vertexNum=7;
	g.edgeNum=14;

	for (i=0;i<g.vertexNum;i++) 
	{
		cout<<"������";
		cin >> g.VertexNode[i].data; // vertex data info.
		cout<<endl;
		g.VertexNode[i].list=NULL; 
	}

	for (j=0; j<g.edgeNum; j++) 
	{ 
		cout<<endl<<"������㣨�ڵ���ţ�";
		cin >>edgeStart ;
		cout<<endl<<"�����յ㣨�ڵ���ţ�";
			cin>>edgeEnd;
			cout<<endl<<"����Ȩֵ";
				cin>> edgeWeight; 
		adjNode = new adjVertexNode; 
		adjNode->weight = edgeWeight;
		adjNode->adjVertexPosition = edgeEnd-1; 
		// ���ڽӵ���Ϣ���뵽����Vi�ı߱�ͷ��,ע����ͷ������������β����
		adjNode->next=g.VertexNode[edgeStart-1].list; 
		g.VertexNode[edgeStart-1].list=adjNode; 
	}
}

void PrintAdjList(const Graph& g)
{
	for (int i=0; i < g.vertexNum; i++)
	{
		cout<< g.VertexNode[i].data << "->";
		adjVertexNode* head = g.VertexNode[i].list;
		if (head == NULL)
			cout << "NULL";
		while (head != NULL)
		{
			cout << head->adjVertexPosition + 1 <<" ";
			head = head->next;
		}
		cout << endl;
	}
}
void DeleteGraph(Graph &g)
{
	for (int i=0; i<g.vertexNum; i++)
	{
		adjVertexNode* tmp=NULL;
		while(g.VertexNode[i].list!=NULL)
		{
			tmp = g.VertexNode[i].list;
			g.VertexNode[i].list = g.VertexNode[i].list->next;
			delete tmp;
			tmp = NULL;
		}
	}
}
void BellmanFord(Graph& g, VertexNode& s)
{
	deque<VertexNode*> q;
	for (int i=0; i<g.vertexNum; i++)
	{
		g.VertexNode[i].distance = INFINITY;
		g.VertexNode[i].path = NULL;
	}
	s.distance = 0;
	q.push_back(&s);

	int counter = 0;
	while(!q.empty())
	{
		VertexNode* v = q.front();
		q.pop_front();
		if(v==NULL)
			break;

		adjVertexNode* head = v->list;
		while (head != NULL)
		{
			VertexNode* w = &g.VertexNode[head->adjVertexPosition];
			if(v->distance + head->weight < w->distance)
			{
				w->distance = v->distance + head->weight;
				w->path = v;
				if (find(q.begin(), q.end(), w)==q.end())
				{
					q.push_back(w);
				}
			}
			head = head->next;
		}
		counter++;
		if (counter>g.vertexNum * g.edgeNum)
		{
			cout<<"ֵΪ��"<<endl;
			exit(1);
		}
	}
}
void PrintPath(Graph& g, VertexNode* source, VertexNode* target)
{
	if (source!=target && target->path==NULL)
	{
		cout << "��·�� " << endl;
	}
	else
	{
		if (target->path!=NULL)
		{
			PrintPath(g, source, target->path);
			cout << " ";
		}
		cout << target->data ;
	}
}

int main(int argc, const char ** argv)
{
	Graph g;
	CreateGraph(g);
	PrintAdjList(g);
	VertexNode& start = g.VertexNode[0];
	VertexNode& end = g.VertexNode[6];
	BellmanFord(g, start);

	PrintPath(g, &start, &end);
	cout << endl;
	DeleteGraph(g);
	system("pause");
	return 0;
}



