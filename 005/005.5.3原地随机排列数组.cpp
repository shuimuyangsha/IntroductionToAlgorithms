#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

void PrintArr(int *pnArr, int nLen)
{
    for (int i = 0; i < nLen; i++)
    {
        printf("%d ", pnArr[i]);
    }
    printf("\n");
}

void Swap(int *p, int *q)
{
    int nTmp = *p;
    *p = *q;
    *q = nTmp;
}

void RandomSort(int *pnArr, int nLen)
{
    srand(time(NULL));
    for (int i = 0; i < nLen; i++)
    {
        int nIndex = rand()%nLen;
        Swap(&pnArr[i], &pnArr[nIndex]);
    }
}

int main()
{
    int nArr[10] = {1,2,3,4,5,6,7,8,9,10};
    
    PrintArr(nArr, 10);
    RandomSort(nArr, 10);
    PrintArr(nArr, 10);
	system("pause");
    return 0;
}