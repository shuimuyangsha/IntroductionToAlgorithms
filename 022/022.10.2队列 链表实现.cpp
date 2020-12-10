#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include<assert.h>

typedef struct QNode
{
    int nValue;
    struct QNode *pNext;
    
}QNode, *PQNode;

typedef struct 
{
    PQNode pHead;
    PQNode pTail;
}LinkQueue;

void Create(LinkQueue *pLink)
{
    PQNode pTmp = (PQNode)malloc(sizeof(QNode));
    pLink->pHead = pLink->pTail = pTmp;
    if (pLink == NULL)
    {
        exit(0);
    }
    pLink->pHead->pNext = NULL;
    pLink->pHead->nValue = 0;
}

void EnQueue(LinkQueue *pLink, int nValue)
{
    PQNode pTmp = (PQNode)malloc(sizeof(QNode));
    pTmp->nValue = nValue;
    pTmp->pNext = NULL;

    pLink->pTail->pNext = pTmp;
    pLink->pTail = pTmp;
}

int DeQueue(LinkQueue *pLink)
{
    if (pLink->pHead == pLink->pTail)
    {//����Ϊ��
        printf("����Ϊ�գ��޷����ӣ�\n");
    }
    PQNode pTmp = pLink->pHead->pNext;
    pLink->pHead->pNext = pTmp->pNext;
    
    if (pLink->pTail == pTmp)
    {//��������ֻ��һ��Ԫ�أ�����Ӻ�Ҫ�޸Ķ�βָ��
        pLink->pTail = pLink->pHead;
    }
    int nValue = pTmp->nValue;
    free(pTmp);
    pTmp = NULL;

    return nValue;
}

bool IsEmpty(LinkQueue *pLink)
{
    return pLink->pHead == pLink->pTail;
}

void DestroyQueue(LinkQueue *pLink)
{
    while (pLink->pHead != NULL)
    {
        pLink->pTail = pLink->pHead->pNext;
        free(pLink->pHead);
        pLink->pHead = pLink->pTail;
    }
}
int main()
{
    LinkQueue *pLink = (LinkQueue *)malloc(sizeof(LinkQueue));
    Create(pLink);
	int i;
    for (i = 0; i < 10; i++)
    {
        EnQueue(pLink, i);
    }
    
    for (i = 0; i < 10; i++)
    {
        printf("%d ", DeQueue(pLink));
    }

    DestroyQueue(pLink);
	system("pause");
    return 0;
}