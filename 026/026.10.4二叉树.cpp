#include<stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct BiTNode
{
    int nValue;
    struct BiTNode *pLChild;
    struct BiTNode *pRChild;
}BiTNode, *PBiTree;

//����Ϊ0��ʾ���Ϊ��
PBiTree Create()
{
    int nValue;
    PBiTree pRoot;
    scanf("%d", &nValue);
    if (nValue == 0)
    {
        pRoot = NULL;
    }
    else
    {
        pRoot = (PBiTree)malloc(sizeof(BiTNode));
        if (NULL == pRoot)
        {
            printf("�����ڴ�ʧ��!\n");
        }
        else
        {
            pRoot->nValue = nValue;
            printf("������%d�������ӽ��:", pRoot->nValue);
            pRoot->pLChild = Create();

            printf("������%d�������ӽ��:", pRoot->nValue);
            pRoot->pRChild = Create();
        }
    }
    return pRoot;
}

PBiTree Init()
{
    int nValue;
    PBiTree pRoot;
    scanf("%d", &nValue);
    //����0��ʾ�ս��
    if (nValue == 0)
    {
        pRoot = NULL;
        return pRoot;
    }
    else
    {
        pRoot = (PBiTree)malloc(sizeof(BiTNode));
        printf("������%d��������:");
        pRoot->pLChild = Init();

        printf("������%d�����Һ���:");
        pRoot->pRChild = Init();
        
        return pRoot;
    }
}
void Visit(PBiTree p)
{
    printf("%d ", p->nValue);
}

void PreOrder(PBiTree pRoot)
{
    if (NULL == pRoot)
    {
        return;
    }
    Visit(pRoot);
    PreOrder(pRoot->pLChild);
    PreOrder(pRoot->pRChild);
}

void PreOrder1(PBiTree pRoot)
{
    PBiTree pStack[100];
    int nTop = 0;
    PBiTree pCur = pRoot;

    while (nTop > 0 || pCur != NULL)
    {
        while (pCur != NULL)
        {//���ʽ��pCur���е����� 
            Visit(pCur);
            pStack[nTop++] = pCur;
            pCur = pCur->pLChild;
        }

        if (nTop > 0)
        {//��ջ �����Һ���
            nTop--;
            pCur = pStack[nTop];
            pCur = pCur->pRChild;
        }
    }
}

void InOrder(PBiTree pRoot)
{
    if (NULL == pRoot)
    {
        return;
    }
    InOrder(pRoot->pLChild);
    Visit(pRoot);
    InOrder(pRoot->pRChild);
}

void InOrder1(PBiTree pRoot)
{
    PBiTree pStack[100];
    int nTop = 0;
    PBiTree pCur = pRoot;

    while (nTop > 0 || pCur != NULL)
    {
        while (pCur != NULL)
        {
            pStack[nTop++] = pCur;
            pCur = pCur->pLChild;
        }

        if (nTop > 0)
        {
            nTop--;
            pCur = pStack[nTop];
            Visit(pCur);
            pCur = pCur->pRChild;
        }
    }
}

void PostOrder(PBiTree pRoot)
{
    if (NULL == pRoot)
    {
        return;
    }
    PostOrder(pRoot->pLChild);
    PostOrder(pRoot->pRChild);
    Visit(pRoot);
}

void PostOrder1(PBiTree pRoot)
{
    PBiTree pStack[100];
    int nTop = 0;
    PBiTree pCur = pRoot;
    PBiTree IsVisited = NULL;
    while (nTop > 0 || pCur != NULL)
    {
        while (pCur != NULL)
        {
            pStack[nTop++] = pCur;
            pCur = pCur->pLChild;
        }
        pCur = pStack[nTop - 1];
        if (pCur->pRChild == NULL && IsVisited == pCur->pRChild)
        {
            Visit(pCur);
            nTop--;
            IsVisited = pCur;
            pCur = NULL;
        }
        else
        {
            pCur = pCur->pRChild;
        }
        
    }
}

//������������
void LevelOrder(PBiTree pRoot)
{
    if (NULL == pRoot)
    {
        return;
    }
    PBiTree Queue[100];
    int nHead = 0;
    int nTail = 0;
    PBiTree pCur;
    
    Queue[nTail++] = pRoot;
    while (nHead != nTail)
    {
        pCur = Queue[nHead++];
        Visit(pCur);
        if (pCur->pLChild)
        {
            Queue[nTail++] = pCur->pLChild;
        }
        if (pCur->pRChild)
        {
            Queue[nTail++] = pCur->pRChild;
        }
    }
}

//ֻ�и����ʱ �߶�Ϊ1 ���Ϊ0
int TreeHight(PBiTree pRoot)
{
    int nCount;
    int nLChild, nRChild;
    if (NULL == pRoot)
    {
        return 0;
    }
    nLChild = TreeHight(pRoot->pLChild);
    nRChild = TreeHight(pRoot->pRChild);
    nCount = nLChild > nRChild ? nLChild : nRChild;

    return nCount + 1;
}

//Ҷ�ӽ�����
int TreeLeaf(PBiTree pRoot)
{
    int nLChild, nRChild;
    if (pRoot == NULL)
    {
        return 0;
    }
    if (pRoot->pLChild == NULL && pRoot->pRChild == NULL)
    {
        return 1;
    }
    nLChild = TreeLeaf(pRoot->pLChild);
    nRChild = TreeLeaf(pRoot->pRChild);
    return nLChild + nRChild; 
}

int FindParent(PBiTree pRoot, int nValue)
{
    if (pRoot == NULL)
    {
        return 0;
    }
    if (pRoot->pLChild && pRoot->pLChild->nValue == nValue)
    {
        return pRoot->nValue;
    }
    if (pRoot->pRChild && pRoot->pRChild->nValue == nValue)
    {
        return pRoot->nValue;
    }
    FindParent(pRoot->pLChild, nValue);
    FindParent(pRoot->pRChild, nValue);
}

int LeftSibling(PBiTree pRoot, int nValue)
{
    if (pRoot == NULL)
    {
        return 0;
    }

    if (pRoot->pRChild && pRoot->pRChild->nValue == nValue)
    {
        if (pRoot->pLChild)
        {
            return pRoot->pLChild->nValue;
        }
    }
    FindParent(pRoot->pLChild, nValue);
    FindParent(pRoot->pRChild, nValue);
}

int RightSibling(PBiTree pRoot, int nValue)
{
    if (pRoot == NULL)
    {
        return 0;
    }

    if (pRoot->pLChild && pRoot->pLChild->nValue == nValue)
    {
        if (pRoot->pRChild)
        {
            return pRoot->pRChild->nValue;
        }
    }
    FindParent(pRoot->pLChild, nValue);
    FindParent(pRoot->pRChild, nValue);
}

int main()
{
    printf("�����������ֵ:");
    PBiTree pRoot = Create();

    printf("ǰ�����:");
    PreOrder1(pRoot);
    
    printf("�������:");
    InOrder1(pRoot);

    printf("�������:");
    PostOrder(pRoot);
    
    printf("������:");
    LevelOrder(pRoot);

    printf("�������ĸ߶�Ϊ:%d\n", TreeHight(pRoot));
    printf("��������Ҷ�Ӹ���Ϊ:%d\n", TreeLeaf(pRoot));
    
    int rv = FindParent(pRoot, 4);
    if (rv != 0)
    {
        printf("������ֵΪ:%d\n", rv);
    }
    else
    {
        printf("�ý���޸����!\n", rv);
    }

    rv = LeftSibling(pRoot, 4);
    if (rv != 0)
    {
        printf("���ֵܽ���ֵΪ:%d\n", rv);
    }
    else
    {
        printf("�ý�������ֵܽ��!\n", rv);
    }

	system("pause");
    return 0;
}