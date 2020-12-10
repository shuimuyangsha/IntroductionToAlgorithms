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

int Min(int *pnArr, int nLen)
{
    int nMin = pnArr[0];
    for (int i = 1; i < nLen; i++)
    {
        if (nMin > pnArr[i])
        {
            nMin = pnArr[i];
        }
    }

    return nMin;
}

int Max(int *pnArr, int nLen)
{
    int nMax = pnArr[0];
    for (int i = 1; i < nLen; i++)
    {
        if (nMax < pnArr[i])
        {
            nMax = pnArr[i];
        }
    }

    return nMax;
}

void MaxMin(int *pnArr, int nLen, int *pnMax, int *pnMin)
{
    if (nLen % 2 == 0)
    {
        if (pnArr[0] > pnArr[1])
        {
            *pnMax = pnArr[0];
            *pnMin = pnArr[1];
        }
        else
        {
            *pnMax = pnArr[1];
            *pnMin = pnArr[0];
        }
        for (int i = 3; i < nLen; i += 2)
        {
            if (pnArr[i] > pnArr[i - 1])
            {
                if (pnArr[i] > *pnMax)
                {
                    *pnMax = pnArr[i];
                }
                if (pnArr[i - 1] < *pnMin)
                {
                    *pnMin = pnArr[i - 1];
                }    
            }
            else
            {
                if (pnArr[i - 1] > *pnMax)
                {
                    *pnMax = pnArr[i - 1];
                }
                if (pnArr[i] < *pnMin)
                {
                    *pnMin = pnArr[i];
                }    
            }
        }
    }
    else
    {
         *pnMax = pnArr[0];
         *pnMin = pnArr[0];
         for (int i = 2; i < nLen; i += 2)
        {
            if (pnArr[i] > pnArr[i - 1])
            {
                if (pnArr[i] > *pnMax)
                {
                    *pnMax = pnArr[i];
                }
                if (pnArr[i - 1] < *pnMin)
                {
                    *pnMin = pnArr[i - 1];
                }    
            }
            else
            {
                if (pnArr[i - 1] > *pnMax)
                {
                    *pnMax = pnArr[i - 1];
                }
                if (pnArr[i] < *pnMin)
                {
                    *pnMin = pnArr[i];
                }    
            }
        }
    }
    
   
}
int main()
{
    int nArr[10] = {0,2,1,3,2,6,9,7,4,12}; 

    PrintArr(nArr, 10);
    int nMax, nMin;
    MaxMin(nArr, 10, &nMax, &nMin);

    printf("最大值为%d  最小值为%d\n", nMax, nMin);
    system("pause");
    return 0;
}