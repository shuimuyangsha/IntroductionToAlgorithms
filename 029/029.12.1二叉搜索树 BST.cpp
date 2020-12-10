#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct BSTree
{
    int nValue;
    struct BSTree *pLChild;
    struct BSTree *pRChild;
}BSTree, *PBSTree;

PBSTree InsertBSTree(PBSTree pRoot, int nValue)
{
    if (pRoot == NULL)
    {
        pRoot = (PBSTree)malloc(sizeof(BSTree));
        if (!pRoot)
        {
            printf("分配内存失败!\n");
            return NULL;
        }
        pRoot->nValue = nValue;
        pRoot->pLChild = NULL;
        pRoot->pRChild = NULL;
    }
    else
    {
        if (pRoot->nValue > nValue)
        {
            pRoot->pLChild = InsertBSTree(pRoot->pLChild, nValue);
        }
        else if (pRoot->nValue < nValue)
        {
            pRoot->pRChild = InsertBSTree(pRoot->pRChild, nValue);
        }
    }

    return pRoot;
}

PBSTree SearchBSTree(PBSTree pRoot, int nValue)
{
    if (pRoot == NULL)
    {
        return NULL;
    }
    if (pRoot->nValue == nValue)
    {
        return pRoot;
    }
    else if (pRoot->nValue > nValue)
    {
        return SearchBSTree(pRoot->pLChild, nValue);
    }
    else
    {
        return SearchBSTree(pRoot->pRChild, nValue);
    }
}

//删除BST中一个结点
void DeleteNode(PBSTree *pDel)
{
    PBSTree pTmp,pLChildMax;
    if ((*pDel)->pLChild && (*pDel)->pRChild)
    {//左右子树都不为空 则将左子树中最大值的右指针指向要删除结点的右子树
     //然后将要删除结点的左子树根结点放到要删除结点的位置
        pTmp = pLChildMax = (*pDel)->pLChild;
        while (pLChildMax->pRChild)
        {
            pLChildMax = pLChildMax->pRChild;
        }
        pLChildMax->pRChild = (*pDel)->pRChild;
        free((*pDel));
        (*pDel) = pTmp;
    }
    else if (!(*pDel)->pLChild)
    {//左子树为空
        pTmp = *pDel;
        (*pDel) = (*pDel)->pRChild;
        free(pTmp);
    }
    else if (!(*pDel)->pRChild)
    {//右子树为空
        pTmp = *pDel;
        (*pDel) = (*pDel)->pLChild;
        free(pTmp);
    }
    
}

//删除操作
//设p，p1，r是指针变量，p↑表示s要删除的结点，
//p1↑表示p↑的父母结点，则删除可以按如下规定进行：

//1 若结点p↑没有左子树，则用右子树的根代替被删除的结点p↑

//2 若结点p↑有左子树，则在左子树里找按中序周游的最后
//一个结点r↑，将r↑的右指针置成指向p↑的右子树的根，
//然后用结点p↑的左子树的根去代替被删除的结点p↑

void DeleteBSTree(PBSTree *pRoot, int nValue)
{
    if (!SearchBSTree((*pRoot), nValue))
    {
        printf("没有该元素，无法删除!\n");
        return;
    };
    if (nValue == (*pRoot)->nValue)
    {
        DeleteNode(pRoot);
    }
    else if ((*pRoot)->nValue > nValue)
    {
        DeleteBSTree(&(*pRoot)->pLChild, nValue);
    }
    else
    {
        DeleteBSTree(&(*pRoot)->pRChild, nValue);
    }
}

PBSTree DeleteBSTree1(PBSTree pRoot, int nValue)
{
    if (pRoot == NULL)
    {
        printf("树为空!\n");
        return NULL;
    }
    
    if (pRoot->nValue > nValue)
    {
        pRoot->pLChild = DeleteBSTree1(pRoot->pLChild, nValue);
    }
    else if (pRoot->nValue < nValue)
    {
        pRoot->pRChild = DeleteBSTree1(pRoot->pRChild, nValue);
    }
    else
    {//pRoot即为要删除的结点
        if(pRoot->pLChild && pRoot->pRChild)
        {//左右子树都不为空
         //将左子树的最大值赋值给要删除的结点，再删除左子树的最大值结点(叶子结点)    
            PBSTree pLChildMax = pRoot->pLChild;
            while (pLChildMax->pRChild)
            {
                pLChildMax = pLChildMax->pRChild;
            }
            pRoot->nValue = pLChildMax->nValue;
            
            pRoot->pLChild = DeleteBSTree1(pRoot->pLChild, pRoot->nValue);
        }
        else
        {
            PBSTree pTmp = pRoot;
            if (pRoot->pLChild == NULL)
            {//右子树为空
                pRoot = pRoot->pLChild;
            }
            else if (pRoot->pRChild == NULL)
            {//左子树为空
                pRoot = pRoot->pLChild;
            }

            delete pTmp;
        }   
    }
    return pRoot;
}

void InOrder(PBSTree pRoot)
{
    if (!pRoot)
    {
        return;
    }
    InOrder(pRoot->pLChild);
    printf("%d ", pRoot->nValue);
    InOrder(pRoot->pRChild);
}

PBSTree GetParent(PBSTree pRoot, int nValue)
{
    if (pRoot == NULL)
    {//BST树为空
        return NULL;
    }

    if (pRoot->pLChild && pRoot->pLChild->nValue == nValue)
    {
        return pRoot;
    }
    if (pRoot->pRChild && pRoot->pRChild->nValue == nValue)
    {
        return pRoot;
    }
    
    PBSTree ptemp = NULL;
    ptemp = GetParent(pRoot->pLChild, nValue);
    if(ptemp != NULL)
        return ptemp;

    ptemp = GetParent(pRoot->pRChild, nValue);
    if(ptemp != NULL)
    return ptemp;
}
int main()
{
    PBSTree pRoot = NULL;
    int data[] = {12,3,2,34,1,23,44,667,23,3};
    for (int i = 0; i < sizeof(data) / sizeof(int); i++)
    {
        pRoot = InsertBSTree(pRoot, data[i]);
    }
    
    InOrder(pRoot);
    PBSTree p = SearchBSTree(pRoot, 311);
    if (p)
    {
        printf("有该元素%d\n", p->nValue);
    }
    else
    {
        printf("没有该元素!\n");
    }
    
    //DeleteBSTree1(pRoot, 12);
    printf("\n");
    InOrder(pRoot);

    p = GetParent(pRoot, 23);
    if (p)
    {
        printf("父结点为%d\n", p->nValue);
    }
    else
    {
        printf("无父结点!\n");
    }

	system("pause");

    return 0;
}