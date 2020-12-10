#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct BSTree
{
    int nValue;
    struct BSTree *pLChild;
    struct BSTree *pRChild;
}BSTree, *PBSTree;

PBSTree InsertBSTree(PBSTree pRoot, int nValue)
{
    if (pRoot == NULL)
    {
        pRoot = (PBSTree)malloc(sizeof(BSTree));
        if (!pRoot)
        {
            printf("�����ڴ�ʧ��!\n");
            return NULL;
        }
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

PBSTree SearchBSTree(PBSTree pRoot, int nValue)
{
    if (pRoot == NULL)
    {
        return NULL;
    }
    if (pRoot->nValue == nValue)
    {
        return pRoot;
    }
    else if (pRoot->nValue > nValue)
    {
        return SearchBSTree(pRoot->pLChild, nValue);
    }
    else
    {
        return SearchBSTree(pRoot->pRChild, nValue);
    }
}

//ɾ��BST��һ�����
void DeleteNode(PBSTree *pDel)
{
    PBSTree pTmp,pLChildMax;
    if ((*pDel)->pLChild && (*pDel)->pRChild)
    {//������������Ϊ�� �������������ֵ����ָ��ָ��Ҫɾ������������
     //Ȼ��Ҫɾ�����������������ŵ�Ҫɾ������λ��
        pTmp = pLChildMax = (*pDel)->pLChild;
        while (pLChildMax->pRChild)
        {
            pLChildMax = pLChildMax->pRChild;
        }
        pLChildMax->pRChild = (*pDel)->pRChild;
        free((*pDel));
        (*pDel) = pTmp;
    }
    else if (!(*pDel)->pLChild)
    {//������Ϊ��
        pTmp = *pDel;
        (*pDel) = (*pDel)->pRChild;
        free(pTmp);
    }
    else if (!(*pDel)->pRChild)
    {//������Ϊ��
        pTmp = *pDel;
        (*pDel) = (*pDel)->pLChild;
        free(pTmp);
    }
    
}

//ɾ������
//��p��p1��r��ָ�������p����ʾsҪɾ���Ľ�㣬
//p1����ʾp���ĸ�ĸ��㣬��ɾ�����԰����¹涨���У�

//1 �����p��û���������������������ĸ����汻ɾ���Ľ��p��

//2 �����p�������������������������Ұ��������ε����
//һ�����r������r������ָ���ó�ָ��p�����������ĸ���
//Ȼ���ý��p�����������ĸ�ȥ���汻ɾ���Ľ��p��

void DeleteBSTree(PBSTree *pRoot, int nValue)
{
    if (!SearchBSTree((*pRoot), nValue))
    {
        printf("û�и�Ԫ�أ��޷�ɾ��!\n");
        return;
    };
    if (nValue == (*pRoot)->nValue)
    {
        DeleteNode(pRoot);
    }
    else if ((*pRoot)->nValue > nValue)
    {
        DeleteBSTree(&(*pRoot)->pLChild, nValue);
    }
    else
    {
        DeleteBSTree(&(*pRoot)->pRChild, nValue);
    }
}

PBSTree DeleteBSTree1(PBSTree pRoot, int nValue)
{
    if (pRoot == NULL)
    {
        printf("��Ϊ��!\n");
        return NULL;
    }
    
    if (pRoot->nValue > nValue)
    {
        pRoot->pLChild = DeleteBSTree1(pRoot->pLChild, nValue);
    }
    else if (pRoot->nValue < nValue)
    {
        pRoot->pRChild = DeleteBSTree1(pRoot->pRChild, nValue);
    }
    else
    {//pRoot��ΪҪɾ���Ľ��
        if(pRoot->pLChild && pRoot->pRChild)
        {//������������Ϊ��
         //�������������ֵ��ֵ��Ҫɾ���Ľ�㣬��ɾ�������������ֵ���(Ҷ�ӽ��)    
            PBSTree pLChildMax = pRoot->pLChild;
            while (pLChildMax->pRChild)
            {
                pLChildMax = pLChildMax->pRChild;
            }
            pRoot->nValue = pLChildMax->nValue;
            
            pRoot->pLChild = DeleteBSTree1(pRoot->pLChild, pRoot->nValue);
        }
        else
        {
            PBSTree pTmp = pRoot;
            if (pRoot->pLChild == NULL)
            {//������Ϊ��
                pRoot = pRoot->pLChild;
            }
            else if (pRoot->pRChild == NULL)
            {//������Ϊ��
                pRoot = pRoot->pLChild;
            }

            delete pTmp;
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

PBSTree GetParent(PBSTree pRoot, int nValue)
{
    if (pRoot == NULL)
    {//BST��Ϊ��
        return NULL;
    }

    if (pRoot->pLChild && pRoot->pLChild->nValue == nValue)
    {
        return pRoot;
    }
    if (pRoot->pRChild && pRoot->pRChild->nValue == nValue)
    {
        return pRoot;
    }
    
    PBSTree ptemp = NULL;
    ptemp = GetParent(pRoot->pLChild, nValue);
    if(ptemp != NULL)
        return ptemp;

    ptemp = GetParent(pRoot->pRChild, nValue);
    if(ptemp != NULL)
    return ptemp;
}
int main()
{
    PBSTree pRoot = NULL;
    int data[] = {12,3,2,34,1,23,44,667,23,3};
    for (int i = 0; i < sizeof(data) / sizeof(int); i++)
    {
        pRoot = InsertBSTree(pRoot, data[i]);
    }
    
    InOrder(pRoot);
    PBSTree p = SearchBSTree(pRoot, 311);
    if (p)
    {
        printf("�и�Ԫ��%d\n", p->nValue);
    }
    else
    {
        printf("û�и�Ԫ��!\n");
    }
    
    //DeleteBSTree1(pRoot, 12);
    printf("\n");
    InOrder(pRoot);

    p = GetParent(pRoot, 23);
    if (p)
    {
        printf("�����Ϊ%d\n", p->nValue);
    }
    else
    {
        printf("�޸����!\n");
    }

	system("pause");

    return 0;
}