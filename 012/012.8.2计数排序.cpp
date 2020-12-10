#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#define N 5
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

int Digit(int nNum, int w)
{
    int nTmp = 1;
    for (int i = 0; i < w - 1; i++)
    {
        nTmp *= 10;
    }
    
    return (nNum / nTmp) % 10;
}

void RadixSort(int* pDataArray, int iDataNum, int w)  
{  
	int i;
	int *radixArrays[10];    //�ֱ�Ϊ0~9�����пռ�  
	for (i = 0; i < 10; i++)  
	{  
	    radixArrays[i] = (int *)malloc(sizeof(int) * (iDataNum + 1));          
        radixArrays[i][0] = 0;    //indexΪ0����¼�������ݵĸ���  
	}  

	for (int pos = 1; pos <= w; pos++)    //�Ӹ�λ��ʼ����λ  
	{  
	    for (int i = 0; i < iDataNum; i++)    //�������  
	    {  
	        int num = Digit(pDataArray[i], pos);  
	        int index = ++(radixArrays[num][0]);  
	        radixArrays[num][index] = pDataArray[i];  
	    }  
  
        int j;
	    for (i = 0,j =0; i < 10; i++)    //�ռ�  
	    {  
	        for (int k = 1; k <= radixArrays[i][0]; k++) 
            {
   	            pDataArray[j++] = radixArrays[i][k];  
            }
            radixArrays[i][0] = 0;    //��λ  
	    }  

        PrintArr(pDataArray, iDataNum);
	}  
}  


void RandomedArr(int *pnArr, int nLen)
{
    srand(time(NULL));
    for (int i = 0; i < nLen; i++)
    {
        int nIndex = rand()%(nLen -i + 1) +i;
        Swap(&pnArr[i], &pnArr[nIndex]);
    }
}

int main()
{

    int nArr[N] = {0}; 
    srand(time(NULL));
    for(int i = 0; i < N; i++)
    {
        nArr[i] = rand()%1000;
    }
    
    RadixSort(nArr, N, 5);
    PrintArr(nArr, N);

	system("pause");
    return 0;
}