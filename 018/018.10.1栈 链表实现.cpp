#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include<assert.h>

typedef struct Stack
{
    int nValue;
    struct Stack *pNext;
    
}Stack, *PStack;

PStack CreateStack()
{
    PStack pStack = (PStack)malloc(sizeof(Stack));
    pStack->nValue = 0;
    pStack->pNext = NULL;
    
    return pStack;
}

bool IsEmpty(PStack pStack)
{
	if(NULL == pStack)
	{
		printf("ջδ�����ɹ�!\n");
	}
    return pStack->pNext == NULL;
}
PStack PushStack(PStack pStack, int nValue)
{
	if(NULL == pStack)
	{
		printf("ջδ�����ɹ�!\n");
		return NULL;
	}
    PStack pTmp = (PStack)malloc(sizeof(Stack));
    pTmp->nValue = nValue;
    pTmp->pNext = pStack->pNext;
    pStack->pNext = pTmp;

    return pStack;
}

//����ÿ�ζ���ɾ�������е�һ����� ���Բ��ô���PStack *pStack��
int PopStack(PStack pStack)
{
	if(NULL == pStack)
	{
		printf("ջδ�����ɹ�!\n");
	}
    PStack pTmp = pStack->pNext;
    pStack->pNext = pTmp->pNext;
    
    int nValue = pTmp->nValue;
    free(pTmp);

    return nValue;
}

void Destroy(PStack pStack)
{
    while (!IsEmpty(pStack))
    {
        PopStack(pStack);
    }
    free(pStack);
    pStack = NULL;
}
int main()
{
    PStack pStack = CreateStack();
    
    for (int i = 0; i < 10; i++)
    {
        pStack = PushStack(pStack, i);
    }

    while (!IsEmpty(pStack))
    {
        printf("%d ", PopStack(pStack));
    }
    
    Destroy(pStack);
	system("pause");
    return 0;
}