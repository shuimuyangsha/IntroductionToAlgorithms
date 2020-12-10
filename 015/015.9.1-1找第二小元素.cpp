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

void MaxMin(int *pnArr, int nLen, int *pnMin1, int *pnMin2)
{
    if (nLen % 2 == 0)
    {
        if (pnArr[0] > pnArr[1])
        {
            *pnMin2 = pnArr[0];
            *pnMin1 = pnArr[1];
        }
        else
        {
            *pnMin2 = pnArr[1];
            *pnMin1 = pnArr[0];
        }
        for (int i = 3; i < nLen; i += 2)
        {
            if (pnArr[i] > pnArr[i - 1])
            {
                if (pnArr[i - 1] < *pnMin1)
                {
                    *pnMin2 = *pnMin1;
                    *pnMin1 = pnArr[i - 1];
                }
                else if(pnArr[i - 1] < *pnMin2)
                {
                    *pnMin2 = pnArr[i - 1];
                }
            }
            else
            {
                if (pnArr[i] < *pnMin1)
                {
                    *pnMin2 = *pnMin1;
                    *pnMin1 = pnArr[i];
                }
                else if (pnArr[i] < *pnMin2)
                {
                    *pnMin2 = pnArr[i];
                }    
            }
        }
    }
    else
    {
         *pnMin1 = pnArr[0];
         *pnMin2 = pnArr[0];
         for (int i = 2; i < nLen; i += 2)
        {
            if (pnArr[i] > pnArr[i - 1])
            {
                if (pnArr[i - 1] < *pnMin1)
                {
                    
                    *pnMin2 = *pnMin1;
                    *pnMin1 = pnArr[i - 1];
                }else if (pnArr[i - 1] < *pnMin2)
                {
                    *pnMin2 = pnArr[i - 1];
                }    
            }
            else
            {
                if (pnArr[i] < *pnMin1)
                {
                    *pnMin2 = *pnMin1;
                    *pnMin1 = pnArr[i - 1];
                }
                if (pnArr[i] < *pnMin2)
                {
                    *pnMin2 = pnArr[i];
                }    
            }
        }
    }
    
   
}
int main()
{
    int nArr[10] = {0,22,1,3,2,6,9,7,4,12}; 

    PrintArr(nArr, 10);
    int nMin1, nMin2;
    MaxMin(nArr, 10, &nMin1, &nMin2);

    printf("最小值为%d  次小值为%d\n", nMin1, nMin2);
    system("pause");
    return 0;
}