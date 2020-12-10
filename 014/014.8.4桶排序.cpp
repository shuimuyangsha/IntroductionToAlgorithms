#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <math.h>
void PrintArr(int *pnArr, int nLen)
{
    for (int i = 0; i < nLen; i++)
    {
        printf("%d ", pnArr[i]);
    }
    printf("\n");
}

void BucketSort(int *pnArr, int nLen)
{
    int **pnArrTmp;
    int i, j, k;

    //动态创建二维数组
    pnArrTmp = (int **)malloc(sizeof(int *) * 10);
    for (i = 0; i < 10; i++)
    {
        pnArrTmp[i] = (int*)malloc(sizeof(int) * nLen);
    }

    //初始化二维数组
    for (i= 0; i < 10; i++)
    {
        for (j = 0; j < nLen; j++)
        {
            pnArrTmp[i][j] = -1;
        }
    }

    //分配
    int nTmpNum = (int)pow(10, nLoop - 1);
}
int main()
{
    int nArr[11] = {0,2,1,3,2,6,9,7,4,8,6}; 
    int nArrR[11]; //存放排序后的结果
    PrintArr(nArr, 11);
    CountSort(nArr, nArrR, 11, 10);

    PrintArr(nArrR, 11);
    system("pause");
    return 0;
}