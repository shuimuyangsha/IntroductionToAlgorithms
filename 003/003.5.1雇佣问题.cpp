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


void HireAssistant(int *pnArr, int nLen)
{
    int nMax = pnArr[0];
    printf("%d ", pnArr[0]);
    for (int i = 1; i < nLen; i++)
    {
        if (nMax < pnArr[i])
        {
            printf("%d ", pnArr[i]);
            nMax = pnArr[i];
        }
    }
    printf("\n");
}

int main()
{
    int nArr[10];
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        nArr[i] = rand()%100;
    }
    PrintArr(nArr, 10);
    HireAssistant(nArr, 10);

	system("pause");
    return 0;
}