#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

int Parent(int i)
{
    return (i-1)/2;
}
int LeftChild(int i)
{
    return 2*i + 1;
}
int RightChild(int i)
{
    return 2*i + 2;
}

int Maximum(int *pnArr, int nLen)
{
    if (NULL == pnArr || nLen == 0)
    {
        printf("╤сапн╙©у!\n");
        return -1;
    }

    return pnArr[0];
}

void Swap(int *a, int *b)
{
    int nTmp = *a;
    *a = *b;
    *b = nTmp;
}

void MaxHeapify(int *pnArr, int nLen, int i)
{
    int LChild = LeftChild(i);
    int RChild = RightChild(i);
    int nMaxPos;
    if (LChild < nLen && pnArr[LChild] > pnArr[i])
    {
        nMaxPos = LChild;
    }
    else
    {
        nMaxPos = i;
    }
    if (RChild < nLen && pnArr[RChild] > pnArr[nMaxPos])
    {
        nMaxPos = RChild;
    }
    
    if (nMaxPos != i)
    {
        Swap(&pnArr[nMaxPos], &pnArr[i]);
        MaxHeapify(pnArr, nLen,nMaxPos);
    }
    
}

void BuildMaxHeap(int *pnArr, int nLen)
{
    for (int i = Parent(nLen -1); i >= 0; i--)
    {
        MaxHeapify(pnArr, nLen, i);
    }
}


void HeapSort(int *pnArr, int nLen)
{
    BuildMaxHeap(pnArr, nLen);
    for (int i = nLen - 1; i > 0; i--)
    {
        Swap(&pnArr[i], &pnArr[0]);
        nLen--;
        MaxHeapify(pnArr, nLen, 0);
    }
}

void PrintArr(int *pnArr, int nLen)
{
    for (int i = 0; i < nLen; i++)
    {
        printf("%d ", pnArr[i]);
    }
    printf("\n");
}

int main()
{
    int nArr[10] = {4,1,3,2,16,9,10,14,8,7};
    
    PrintArr(nArr, 10);
    HeapSort(nArr, 10);

    PrintArr(nArr, 10);
	system("pause");
    return 0;
}