#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include<assert.h>

typedef struct Link
{
    int nValue;
    struct Link *pPrev;
    struct Link *pNext;
}Link, *PLink;

PLink Create( )
{
    PLink pLink = (PLink)malloc(sizeof(Link));
    pLink->nValue = 0;
    pLink->pPrev = NULL;
    pLink->pNext = NULL;

    return pLink;
}

//����С�����˳���������
PLink Insert(PLink pLink, int nValue)
{
    if (NULL == pLink)
    {
        printf("����δ�����ɹ�!\n");
        return NULL;
    }
    PLink pTmp = (PLink)malloc(sizeof(Link));
    pTmp->nValue = nValue;
    pTmp->pNext = NULL;
    pTmp->pPrev = NULL;

    PLink pCur = pLink;
    while (pCur->pNext != NULL && nValue >= pCur->pNext->nValue)
    {
        pCur = pCur->pNext;
    }

    if (pCur->pNext == NULL)
    {//���뵽���һ��������
        pTmp->pPrev = pCur;
        pCur->pNext = pTmp;
    }
    if (nValue < pCur->pNext->nValue)
    {//���뵽�м�λ��
        pTmp->pNext = pCur->pNext;
        pCur->pNext->pPrev = pTmp;
        pTmp->pPrev = pCur;
        pCur->pNext = pTmp;
    }

    return pLink;
}

void Delete(PLink pLink, int nValue)
{
    if (NULL == pLink)
    {
        printf("����δ�����ɹ�!\n");
        return;
    }
    PLink pCur = pLink;
    bool bDel = false;
    while (pCur->pNext != NULL )
    {
        //���жϷ���while������Ϊ����ɾ�����е���nValue�Ľ��
        if (pCur->pNext->nValue == nValue)
        {
            PLink pTmp = pCur->pNext;
            if (NULL == pTmp->pNext)
            {//ɾ�����һ�����
                pCur->pNext = NULL;
            }
            else
            {
                pCur->pNext = pTmp->pNext;
                pTmp->pNext->pPrev = pCur;
            }        
            bDel = true;
            free(pTmp);
        }
        else
        {
            pCur = pCur->pNext;
        }
    }
    if (!bDel)
    {
        printf("������û������ %d���޷�ɾ��!\n", nValue);
    }
}

PLink Find(PLink pLink, int nValue)
{
    PLink pCur = pLink->pNext;
    while (NULL != pCur->pNext)
    {
        if (pCur->nValue == nValue)
        {
            return pCur;
        }
        pCur = pCur->pNext;
    }
    return NULL;
}
void Print(PLink pLink)
{
    if (pLink->pNext == NULL)
    {
        printf("����Ϊ��!\n");
        return;
    }
    PLink pCur = pLink->pNext;
    while (pCur != NULL)
    {
        printf("%d ", pCur->nValue);
        pCur = pCur->pNext;
    }
}
bool IsEmpty(PLink pLink)
{
    return pLink->pNext == NULL;
}

void Destroy(PLink pLink)
{
    PLink pCur = pLink;
    PLink pDel = NULL;
    PLink pNext = NULL;

    while (pCur->pNext != NULL)
    {
        pDel = pCur->pNext;
        if (NULL == pDel->pNext)
        {//�������һ�����
            pCur->pNext = NULL;
        }
        else
        {
            pDel->pNext->pPrev = pCur;
            pCur->pNext = pDel->pNext;
        }  
        free(pDel);

        printf("\n");
        Print(pLink);

    }
    free(pLink);
}
int main()
{
    PLink pLink = Create();
    pLink = Insert(pLink, 1);
    pLink = Insert(pLink, 5);
    pLink = Insert(pLink, 8);
    pLink = Insert(pLink, 4);
    pLink = Insert(pLink, 4);

    Delete(pLink, 8);

//    if (NULL != Find(pLink, 4))
//    {
//        printf("�������и�����!\n");
//    }
//    else
//    {
//        printf("������û�и�����!\n");
//    }
    Print(pLink);
    
   // Destroy(pLink);
	system("pause");
    return 0;
}