#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

#define NLEN 10

typedef struct Node
{
    int nValue;
    int *pnValue;
}Node;

void PrintArr(int *pnArr, int nLen)
{
    for (int i = 0; i < nLen; i++)
    {
        printf("%d ", pnArr[i]);
    }
    printf("\n");
}

void InsertSort(Node *pnodeArr, int nLen)
{
	int i;
    for (i = 0; i < nLen; i++)
    {
        Node tmp = pnodeArr[i];
		int j;
        for (j = i; j > 0 && tmp.nValue < pnodeArr[j-1].nValue; j--)
        {
            pnodeArr[j] = pnodeArr[j - 1];
        }
        pnodeArr[j] = tmp;
    }
}

void RandomArr(int *pnArr, int nLen)
{
	int i;
    Node *pnodeArr = (Node *)malloc(sizeof(Node) * nLen);
    int *pnArrTmp = (int *)malloc(sizeof(int) * nLen);
    
    srand(time(NULL));
    for (i = 0; i < nLen; i++)
    {
        pnArrTmp[i] = pnArr[i];
        pnodeArr[i].nValue = rand() % 1000;
        pnodeArr[i].pnValue = &pnArrTmp[i];
    }
    
    InsertSort(pnodeArr,nLen);
    for (i = 0; i < nLen; i++)
    {
        pnArr[i] = *(pnodeArr[i].pnValue);
    }
}

int main()
{
	int nArr[NLEN];
    srand(time(NULL));
	for (int i = 0; i < NLEN; i++)
    {
        nArr[i] = rand()%100;
    }

	PrintArr(nArr, NLEN);

	RandomArr(nArr, NLEN);
    
	PrintArr(nArr, NLEN);
	system("pause");
    return 0;
}

