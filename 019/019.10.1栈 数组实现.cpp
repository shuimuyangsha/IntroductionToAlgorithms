#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include<assert.h>

typedef struct Stack
{
    int nTop;
    int nLen;
    int *pnArr;
}Stack, *PStack;

//��ʼ��ջ nLenΪջ�Ĵ�С
PStack Create(int nLen)
{
    if (nLen <= 0)
    {
        return NULL;
    }

    PStack pStack = (PStack)malloc(sizeof(Stack)); 
    pStack->nTop = 0;
    pStack->nLen = nLen;
    pStack->pnArr = (int *)malloc(sizeof(int) * nLen);
    
    return pStack;
}

bool IsEmpty(PStack pStack)
{
    return pStack->nTop == 0;
}

bool IsFull(PStack pStack)
{
    return pStack->nTop == pStack->nLen;
}

void Push(PStack pStack, int nValue)
{
    if (pStack->nTop == pStack->nLen)
    {
        printf("ջ����!\n");
        return;
    }
    pStack->pnArr[pStack->nTop] = nValue;
    pStack->nTop++;
}

int Pop(PStack pStack)
{
    if (pStack->nTop == 0)
    {
        printf("ջΪ��!\n");
    
    }
    else
    {
        pStack->nTop--;
        return pStack->pnArr[pStack->nTop];
    }
    
}

void Destroy(PStack pStack)
{
    free(pStack->pnArr);
    pStack->pnArr = NULL;
    free(pStack);
    pStack = NULL;
}
int main()
{
    PStack pStack = Create(10);
    int i;
    for (i = 0; i < 12; i++)
    {
        Push(pStack, i);
    }

    for (i = 0; i < 10; i++)
    {
        printf("%d ", Pop(pStack));
    }

    
    Destroy(pStack);
	system("pause");
    return 0;
}