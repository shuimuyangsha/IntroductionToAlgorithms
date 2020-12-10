// 12二叉查找树.cpp : 定义控制台应用程序的入口点。
//

// 3 - 10二叉搜索树查找.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
using namespace std;

typedef struct BSTree
{
	int nValue;
	struct BSTree *pLChild;
	struct BSTree *pRChild;
}BSTree, *PBSTree;

PBSTree  CreatTree(PBSTree root,int a)
{

	if (root==NULL)
	{
		root = (PBSTree)malloc(sizeof(BSTree));

		root->nValue=a;
		root->pLChild=NULL;
		root->pRChild=NULL;

	}
	else if (a<=root->nValue)
	{
		root->pLChild = CreatTree(root->pLChild,a);
	}
	else if (a>root->nValue)
	{
		root->pRChild = CreatTree(root->pRChild,a);
	}
	return root;
}

PBSTree InsertBSTree(PBSTree pRoot, int nValue)
{
	if (pRoot == NULL)
	{
		pRoot = (PBSTree)malloc(sizeof(BSTree));

		pRoot->nValue = nValue;
		pRoot->pLChild = NULL;
		pRoot->pRChild = NULL;
	}
	else
	{
		if (pRoot->nValue > nValue)
		{
			pRoot->pLChild = InsertBSTree(pRoot->pLChild, nValue);
		}
		else if (pRoot->nValue < nValue)
		{
			pRoot->pRChild = InsertBSTree(pRoot->pRChild, nValue);
		}
	}

	return pRoot;
}

void InOrder(PBSTree pRoot)
{
	if (!pRoot)
	{
		return;
	}
	InOrder(pRoot->pLChild);
	printf("%d ", pRoot->nValue);
	InOrder(pRoot->pRChild);
}
int FindMin(PBSTree root)
{
	while(root->pLChild!=NULL)
		root=root->pLChild;
	return root->nValue;
}
int FindMax(PBSTree root)
{
	while(root->pRChild!=NULL)
		root=root->pRChild;
	return root->nValue;
}
PBSTree FindLoc(PBSTree root,int mid)//大于节点去右边找，小于去左边找
{

	if (mid>=root->nValue)
	{
		if (root->pRChild==NULL)
		{
			return root;
		}
		return FindLoc(root->pRChild,mid);
	}
	else
	{
		if (root->pLChild==NULL)
		{
			return root;
		}
		return FindLoc(root->pLChild,mid);
	}
}


PBSTree search(PBSTree root,int value)//大于节点去右边找，小于去左边找
{

	if (value==root->nValue)
	{
		return root;
	} 
	else if (value>root->nValue)
	{
		if (root->pRChild==NULL)
		{
			return NULL;
		}
		return FindLoc(root->pRChild,value);
	}
	else
	{
		if (root->pLChild==NULL)
		{
			return NULL;
		}
		return FindLoc(root->pLChild,value);
	}
}



int main(int argc, char* argv[])
{
	PBSTree root = NULL;
	int a=1;



	while (a!=0)
	{
		cout<<"输入插入的数字(0停止插入)：";
		cin>>a;
		cout<<endl;
		root=CreatTree(root,a);
	}


	InOrder(root);
	//cout<<endl<<FindMin(root);
	//cout<<endl<<FindMax(root);
	//int mid = (FindMin(root)+FindMax(root))/2;
	//cout<<endl<<"最近节点"<<FindLoc(root,mid)->nValue;
	int n=9;
	PBSTree p = search(root,n);
	if (p==NULL)
	{
		cout<<"没找到";
	}
	else
	{
		cout<<endl<<"找到"<<p->nValue;
	}
	system("pause");
	return 0;
}

