#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void InsertSort(int *pnArr, int nLen)
{
    if (pnArr == NULL || nLen == 0)
    {
        return;
    }

    for (int i = 1; i < nLen; i++)
    {
        int nTmp = pnArr[i];
		int j;
        for (j = i; j > 0 && nTmp < pnArr[j - 1]; j--)
        {
            pnArr[j] = pnArr[j-1];
        }
        pnArr[j] = nTmp;
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
    srand(time(NULL));
    int nArr[10];
    for (int i = 0; i < 10; i++)
    {
        nArr[i] = rand()%100;
    }
    
    printf("ÅÅÐòÇ°:");
    PrintArr(nArr, 10);
    
    InsertSort(nArr, 10);
    printf("ÅÅÐòºó:");
    PrintArr(nArr, 10);

	system("pause");
    return 0;
}