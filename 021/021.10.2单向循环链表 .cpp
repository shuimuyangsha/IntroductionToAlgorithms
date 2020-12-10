#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include<assert.h>

typedef struct LoopLink
{
    int nValue;
    struct LoopLink *pNext;
}LoopLink, *PLoopLink;

PLoopLink Create()
{
    PLoopLink pHead = (PLoopLink)malloc(sizeof(LoopLink));
    if (NULL == pHead)
    {
        printf("�����ڴ�ʧ��!\n");

    }
    pHead->nValue = -9999;
    pHead->pNext = pHead;

    return pHead;
}

void Insert(PLoopLink pHead, int nValue)
{
    if (NULL == pHead)
    {
        printf("����δ�����ɹ�!\n");
        return ;
    }
    PLoopLink pCur = pHead;
    PLoopLink pTmp = (PLoopLink)malloc(sizeof(LoopLink));
    pTmp->nValue = nValue;
    pTmp->pNext = NULL;

    while (pCur->pNext != pHead)
    {
        if (pCur->pNext->nValue > nValue)
        {
            break;
        }
        pCur = pCur->pNext;
    }

    pTmp->pNext = pCur->pNext;
    pCur->pNext = pTmp;
}

void Delete(PLoopLink pHead, int nValue)
{
    if (pHead == NULL)
    {
        printf("����δ�����ɹ�!\n");
        return;
    }
    PLoopLink pCur = pHead;
    while (pCur->pNext!= pHead)
    {
        if (pCur->pNext->nValue == nValue)
        {
            PLoopLink pTmp = pCur->pNext;
            pCur->pNext = pTmp->pNext;

            free(pTmp);
            pTmp = NULL;
        }
        else
        {
            pCur = pCur->pNext;
        }
    }
}

PLoopLink Find(PLoopLink pHead, int nValue)
{
    if (pHead == NULL)
    {
        printf("����δ�����ɹ�!\n");
        return NULL;
    }
    PLoopLink pCur = pHead;
    while (pCur->pNext!= pHead)
    {
        if (pCur->pNext->nValue == nValue)
        {
            return pCur->pNext;
        }
        else
        {
            pCur = pCur->pNext;
        }
    }
    return NULL;
}
bool IsEmpty(PLoopLink pHead)
{
    if (NULL == pHead)
    {
        printf("����δ�����ɹ�!\n");
    }
    return pHead->pNext == pHead;

}

void Print(PLoopLink pHead)
{
    if (pHead == NULL)
    {
        printf("����δ�����ɹ�!\n");
        return;
    }
    if (pHead->pNext == pHead)
    {
        printf("����Ϊ��!\n");
        return;
    }
    PLoopLink pCur = pHead->pNext;
    while (pCur != pHead)
    {
        printf("%d ", pCur->nValue);
        pCur = pCur->pNext;
    }

    printf("\n");
}
int main()
{
    PLoopLink pHead = Create();
   // printf("%d\n", IsEmpty(pHead));
    Insert(pHead, 1);
    Insert(pHead, 5); 
    Insert(pHead, 8);
    Insert(pHead, 4);
    Insert(pHead, 0);

    if (NULL != Find(pHead, 2))
    {
        printf("�������и�����!\n");
    }
    else
    {
         printf("������û�и�����!\n");
    }
    
    Delete(pHead, 8);
    Print(pHead);
    system("pause");

    return 0;
}