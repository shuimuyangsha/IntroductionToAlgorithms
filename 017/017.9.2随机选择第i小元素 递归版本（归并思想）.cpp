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

void Swap(int *p1, int *p2)
{
    int nTmp = *p1;
    *p1 = *p2;
    *p2 = nTmp;
}

int Partition(int *pnArr, int nLeft, int nRight)
{
    int nKey = nRight;
    int i = nLeft - 1;
    for (int j = nLeft; j < nRight; j++)
    {
        if (pnArr[j] <= pnArr[nKey])
        {
            i++;
            Swap(&pnArr[i], &pnArr[j]);
        }
    }

    Swap(&pnArr[i+1], &pnArr[nKey]);
    return i+1;
}

int RandomPartiton(int *pnArr, int nLeft, int nRight)
{
    srand(time(NULL));
    int i = rand()%(nRight - nLeft + 1) + nLeft;
    Swap(&pnArr[i], &pnArr[nRight]);

    return Partition(pnArr, nLeft, nRight);
}
//i  第i小元素
int RandomSelect(int *pnArr, int nLeft, int nRight, int i)
{
    if (nLeft == nRight)
    {
        return pnArr[nLeft];
    }
    //寻找一个nTmpPos下标，nTmpPos左边的值都小于它，右边的值都大于它
    int nTmpPos = RandomPartiton(pnArr, nLeft, nRight);

    int nLCount = nTmpPos - nLeft + 1;
    if (nLCount == i)
    {
        return pnArr[nTmpPos];
    }
    else if (i  < nLCount)
    {
        return RandomSelect(pnArr, nLeft, nTmpPos - 1, i);
    }
    else
    {
        return RandomSelect(pnArr, nTmpPos + 1, nRight, i - nLCount);
    }
}

int main()
{
    int nArr[10] = {0,2,1,3,5,6,9,7,4,12}; 

    PrintArr(nArr, 10);
    printf("第5最小元素的值为%d\n", RandomSelect(nArr, 0, 9, 5));
    system("pause");
    return 0;
}