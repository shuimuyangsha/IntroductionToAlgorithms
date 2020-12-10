// ǿ��ͨ��֧.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include<iostream>
#define MAX 100
using namespace std;

//����������ʽڵ��α�־ö�ٱ���
enum Color{white,gray,black};

//�߶˵�ṹ��
struct edgeNode
{
	int no; //��β�˵����
	char info; //�߶˵�����
	struct edgeNode * next; //��һ��
};

//�ڵ�ṹ��
struct vexNode
{
	char info; //�ڵ�����
	struct edgeNode *link; //��֮�����Ķ˵�
};

//ǿ��ͨ��ͼ������ͷ�ṹ��
struct StronConHead
{
	int num; // ǿ��ͨ��ͼ���
	struct StronConNode *link; //��ǿ��ͨ��ͼ�ĵ�һ���ڵ�
};

//
struct StronConNode
{
	int num; //һ��ǿ��ͨ��ͼ�ڵ�����
	char info; //һ��ǿ��ͨ��ͼ�ڵ������
	struct StronConNode *next; //��һ��
};

//����������ʽڵ�Ŀ�ʼ/���ʱ��ṹ��
struct Time
{
	int num; //�ڵ����
	int time; //ʱ��
};

//�洢�ڵ���Ϣ,adjlist1�洢ͼ��adjlist2�洢ͼ��ת��
vexNode adjlist1[MAX],adjlist2[MAX];
//���ʲ��
//��û����Ϊwhite�������˵��ǻ�û����������к��������Ϊgray
//����������к��������Ϊblack
Color color[MAX];
//���ʵĿ�ʼʱ��
Time d[MAX];
//���ʵ����ʱ��
Time f[MAX];
//�������ʱ�����ʹ��Ľڵ��־
bool visited[MAX];
//con[j]�����Ϊj��ǿ��ͨ��ͼ������ͷ���飬
StronConHead con[MAX];


//�����ڽӱ�洢����ת��
//adjlist1Ϊ�ڵ㼯��adjlist2Ϊͼת�ýڵ㼯��nΪ�ڵ������eΪ����Ŀ
void createGraph(vexNode *adjlist1,vexNode *adjlist2,int n,int e)
{
	int i;
	for(i=1;i<=n;i++)
	{
		cout<<"���붥��ֵ";
		cin>>adjlist1[i].info;
		adjlist2[i].info = adjlist1[i].info;
		adjlist1[i].link = NULL;
		adjlist2[i].link = NULL;
	}
	edgeNode *p1,*p2;
	int v1,v2;
	for(i=1;i<=e;i++)
	{
		cout<<"������㣨�ڵ���ţ�";
		cin>>v1;
		cout<<"�����յ㣨�ڵ���ţ�";
		cin>>v2;
		//����ԭͼ�ڽӱ�
		p1 = (edgeNode*)malloc(sizeof(edgeNode));
		p1->no = v2;
		p1->info = adjlist1[v2].info;
		p1->next = adjlist1[v1].link;
		adjlist1[v1].link = p1;
		//����ת��ͼ�ڽӱ�
		p2 = (edgeNode*)malloc(sizeof(edgeNode));
		p2->no = v1;
		p2->info = adjlist2[v1].info;
		p2->next = adjlist2[v2].link;
		adjlist2[v2].link = p2;
	}
}

//�����������������Ȩͼ
//adjlist1Ϊԭͼ���ڽӱ�洢��timeΪһ��ȫ��ʱ�����v�ǵڼ����ڵ�
void DFS1(vexNode *adjlist1,int &time,int v)
{
	color[v] = gray;
	time += 1;
	d[v].num = v;
	d[v].time = time;
	edgeNode *p;
	p = adjlist1[v].link;
	while(p != NULL)
	{
		if(color[p->no]==white)
		{
			DFS1(adjlist1,time,p->no);
		}
		p = p->next;
	}
	color[v] = black;
	time += 1;
	f[v].num = v;
	f[v].time = time;
}

////�������е�һ������������ڵ�����ʱ��
void fast_sort_f(Time *f,int begin,int end)
{
	if(begin<end)
	{
		int i = begin-1, j = begin;
		f[0] = f[end];
		while(j<end)
		{
			if(f[j].time>f[0].time)
			{
				i++;
				Time temp = f[i];
				f[i] = f[j];
				f[j] = temp;
			}
			j++;
		}
		Time temp1 = f[end];
		f[end] = f[i+1];
		f[i+1] = temp1;
		fast_sort_f(f,begin,i);
		fast_sort_f(f,i+2,end);
	}
}
//�����������������Ȩͼ��ת��ͼ
//adjlist2Ϊת��ͼ���ڽӱ�洢��con�����Ϊno��ǿ��ͨ��ͼ������ͷ���飬
//timeΪһ��ȫ��ʱ�����v�ǵڼ����ڵ�
void DFS2(vexNode *adjlist2,StronConHead *con,int &no,int v)
{
	visited[v] = true;
	StronConNode *p1 = (StronConNode*)malloc(sizeof(StronConHead));
	p1->info = adjlist2[v].info;
	p1->num = v;
	p1->next = con[no].link;
	con[no].link = p1;
	edgeNode *q1;
	q1 = adjlist2[v].link;
	while(q1 != NULL)
	{
		if(!visited[q1->no])
		{
			DFS2(adjlist2,con,no,q1->no);
		}
		q1 = q1->next;
	}
}

////��ӡ����ǿ��ͨ��֧�ڵ�
//con�����Ϊno��ǿ��ͨ��ͼ������ͷ���飬no��ǿ��ͨȫ�ַ�֧���
void print_StronConCom(StronConHead *con,int &no)
{
	int i;
	StronConNode * p;
	for(i=1;i<no;i++)
	{
		cout<<"ǿ��ͨ��֧"<<i<<"��";
		p = con[i].link;
		while(p !=NULL)
		{
			cout<<"("<<p->num<<":"<<p->info<<") ";
			p = p->next;
		}
		cout<<endl;
	}
}
int main(int argc, char* argv[])
{
	int cases;
	cout<<"����������";
	cin>>cases;
	while(cases--)
	{
		int n,e;
		cout<<"�ڵ�����";
		cin>>n;
		cout<<"������";
		cin>>e;
		//���ʽڵ��ʱ�����ȫ�ֱ���
		int time = 0;
		//no��ǿ��ͨȫ�ַ�֧��ţ�ȫ�ֱ���
		int no = 1;
		//���ʱ�־�����ǰ���ڵ㶼��ʼ��Ϊ0
		int i;
		for(i=1;i<=n;i++) 
		{
			color[i] = white;
			visited[i] = false;
			con[i].link = NULL;
		}
		//�����ڽӱ�
		createGraph(adjlist1,adjlist2,n,e);
		//��һ���������������ԭͼ
		for(i=1;i<=n;i++)
		{
			if(color[i]==white)
				DFS1(adjlist1,time,i);
		}
		//�������е�һ������������ڵ�����ʱ��
		fast_sort_f(f,1,n);
		//�ڶ����������������ԭͼ��ת��ͼ
		for(i=1;i<=n;i++)
		{
			if(!visited[i])
			{
				DFS2(adjlist2,con,no,f[i].num);
				no += 1;
			}
		}
		//��ӡ����ǿ��ͨ��֧�ڵ�
		print_StronConCom(con,no);
	}
	system("pause");
	return 0;
}
