// 活动选择问题.cpp : 定义控制台应用程序的入口点。
//

#include<iostream>
#define N 100
using namespace std;
struct Activity
{
	int number; //活动编号
	int begin; //活动开始时间
	int end; //活动结束时间
	bool flag; //此活动是否被选择
};
//对于活动集，按照结束时间递增排序,使用快速排序
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
//选择最大活动数目
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
	cout<<"请输入案例的个数："<<endl;
	cin>>cases;
	while(cases--)
	{
		int n;
		cout<<"请输入活动的数目："<<endl;
		cin>>n;
		int i;
		for(i=0;i<n;i++)
		{
			act[i].number = i+1;
			act[i].flag = false;
			cout<<"活动"<<i+1<<"开始时间：";
			cin>>act[i].begin;
			cout<<"活动"<<i+1<<"结束时间：";
			cin>>act[i].end;
		}
		//快速排序
		fast_sort(act,0,n-1);
		//选择最大数目活动集
		select_activity(act,n);
		int sum = 0;
		cout<<"最终选择的活动集合为："<<endl;
		cout<<"< ";
		for(i=0;i<n;i++)
			if(act[i].flag)
			{
				cout<<act[i].number<<" ";
				sum ++;
			}
			cout<<">"<<endl;
			cout<<"最大活动集合的数目为："<<sum<<endl;
	}
	system("pause");
	return 0;
}
