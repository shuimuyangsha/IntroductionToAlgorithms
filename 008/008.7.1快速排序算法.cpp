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

//ʵ�ֶ�������[nLeft - nRight]��ԭַ���ţ�����Ԫ�طŵ�����λ��
//��������
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
    
    //����Ԫ�ز��뵽�м�λ��
    Swap(&pnArr[i+1], &pnArr[nRight]);

    return i+1;
}

//��������
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

//�ݼ�����
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

//Ѱ��һ��nTmpPos�±꣬nTmpPos��ߵ�ֵ��С�������ұߵ�ֵ��������
void QuickSort(int *pnArr, int nLeft, int nRight)
{
    if (nLeft < nRight)
    {
        //�ֽ�
        int nTmpPos = Patition3(pnArr, nLeft, nRight);

        //���/�ϲ�
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