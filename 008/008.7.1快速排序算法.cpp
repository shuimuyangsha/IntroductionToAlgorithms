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

//实现对子数组[nLeft - nRight]的原址重排，将主元素放到合适位置
//递增排序
int Patition1(int *pnArr, int nLeft, int nRight)
{
    int nKey = pnArr[nRight];
    int i = nLeft - 1;

    for (int j = nLeft; j < nRight; j++)
    {
        if (pnArr[j] <= nKey)
        {
            i++;
            Swap(&pnArr[i], &pnArr[j]);
        }
    }
    
    //将主元素插入到中间位置
    Swap(&pnArr[i+1], &pnArr[nRight]);

    return i+1;
}

//递增排序
int Patition2(int *pnArr, int nLeft, int nRight)
{
    int nKey = nRight;
    int i = nLeft - 1;
    bool bExchange = false;

    for (int j = nLeft; j < nRight; j++)
    {
        if (pnArr[j] < pnArr[nKey])
        {
            i++;
            Swap(&pnArr[i], &pnArr[j]);
            bExchange = true;
        }
    }
    Swap(&pnArr[i+1],&pnArr[nRight]);
    if (bExchange)
    {
        return i+1;
    }
    else
    {
        return (nLeft + nRight) / 2;
    }
}

//递减排序
int Patition3(int *pnArr, int nLeft, int nRight)
{
    int nKey = nRight;
    int i = nLeft - 1;
    for (int j = nLeft; j < nRight; j++)
    {
        if (pnArr[j] > pnArr[nKey])
        {
            i++;
            Swap(&pnArr[i],&pnArr[j]);
        }
    }
    Swap(&pnArr[i+1], &pnArr[nRight]);
    return i + 1;
}

//寻找一个nTmpPos下标，nTmpPos左边的值都小于它，右边的值都大于它
void QuickSort(int *pnArr, int nLeft, int nRight)
{
    if (nLeft < nRight)
    {
        //分解
        int nTmpPos = Patition3(pnArr, nLeft, nRight);

        //解决/合并
        QuickSort(pnArr, nLeft, nTmpPos - 1);
        QuickSort(pnArr, nTmpPos + 1, nRight);
    }
}

int main()
{
    int nArr[10] = {42,1,3,2,16,9,10,14,8,17}; 
    
    PrintArr(nArr, 10);
    QuickSort(nArr, 0,9);

    PrintArr(nArr, 10);
    system("pause");
    return 0;
}