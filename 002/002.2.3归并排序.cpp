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

//�ϲ���������
void Merge(int data[], int nLpos, int nRpos, int nRightEnd)
{
    int i;
    int k = nLpos;
    int nLeftEnd = nRpos;
    int nTmpPos = 0;
    int nLen = nRightEnd - nLpos + 1;
    int *pnArr = (int *)malloc(sizeof(int) * nLen);
    ++nRpos;
    while (nLpos <= nLeftEnd && nRpos <= nRightEnd)
    {
        if (data[nLpos] <= data[nRpos])
        {
            pnArr[nTmpPos++] = data[nLpos++];
        }
        else
        {
            pnArr[nTmpPos++] = data[nRpos++];
        }
    }
    while (nLpos <= nLeftEnd)
    {
        pnArr[nTmpPos++] = data[nLpos++];
    }
    while (nRpos <= nRightEnd)
    {
        pnArr[nTmpPos++] = data[nRpos++];
    }
    
    nTmpPos = 0;
    for (i = k; i <= nRightEnd; i++)
    {
        data[i] = pnArr[nTmpPos++];
    }

    free(pnArr);
}

void MergeSort(int *pnArr, int nLeft, int nRight)
{
    if (nLeft > nRight)
    {
        return;
    }
    if (nRight > nLeft)
    {
        //1�ֽ�
        int nMid = (nLeft + nRight) / 2;
        
        //2���
        MergeSort(pnArr, nLeft, nMid);
        MergeSort(pnArr, nMid + 1, nRight);

        //3�ϲ�
        Merge(pnArr, nLeft, nMid, nRight);
    }
}
int main()
{
    srand(time(NULL));
    int nArr[10];
    for (int i = 0; i < 10; i++)
    {
        nArr[i] = rand()%100;
    }
    
    printf("����ǰ:");
    PrintArr(nArr, 10);
    
    MergeSort(nArr, 0, 9);
    printf("�����:");
    PrintArr(nArr, 10);

	system("pause");
    return 0;
}