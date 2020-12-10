// �ѡ������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include<iostream>
#define N 100
using namespace std;
struct Activity
{
	int number; //����
	int begin; //���ʼʱ��
	int end; //�����ʱ��
	bool flag; //�˻�Ƿ�ѡ��
};
//���ڻ�������ս���ʱ���������,ʹ�ÿ�������
void fast_sort(Activity *act,int f,int t)
{
	if(f<t)
	{
		int i = f-1,j = f;
		Activity a = act[t];
		while(j<t)
		{
			if(act[j].end<=a.end)
			{
				i++;
				Activity temp1 = act[i];
				act[i] = act[j];
				act[j] = temp1;
			}
			j++;
		}
		Activity temp2 = act[t];
		act[t] = act[i+1];
		act[i+1] = temp2;
		fast_sort(act,f,i);
		fast_sort(act,i+2,t);
	}
}
//ѡ�������Ŀ
void select_activity(Activity *act,int n)
{
	int i = 0;
	act[0].flag = true;
	Activity a = act[0];
	for(i=1;i<n;i++)
	{
		if(act[i].begin>=a.end)
		{
			act[i].flag = true;
			a = act[i];
		}
	}
}
int main(int argc, char* argv[])
{
	int cases;
	Activity act[N];
	cout<<"�����밸���ĸ�����"<<endl;
	cin>>cases;
	while(cases--)
	{
		int n;
		cout<<"����������Ŀ��"<<endl;
		cin>>n;
		int i;
		for(i=0;i<n;i++)
		{
			act[i].number = i+1;
			act[i].flag = false;
			cout<<"�"<<i+1<<"��ʼʱ�䣺";
			cin>>act[i].begin;
			cout<<"�"<<i+1<<"����ʱ�䣺";
			cin>>act[i].end;
		}
		//��������
		fast_sort(act,0,n-1);
		//ѡ�������Ŀ���
		select_activity(act,n);
		int sum = 0;
		cout<<"����ѡ��Ļ����Ϊ��"<<endl;
		cout<<"< ";
		for(i=0;i<n;i++)
			if(act[i].flag)
			{
				cout<<act[i].number<<" ";
				sum ++;
			}
			cout<<">"<<endl;
			cout<<"������ϵ���ĿΪ��"<<sum<<endl;
	}
	system("pause");
	return 0;
}
