#include<stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct BiTNode
{
    int nValue;
    struct BiTNode *pLChild;
    struct BiTNode *pRChild;
}BiTNode, *PBiTree;

//输入为0表示结点为空
PBiTree Create()
{
    int nValue;
    PBiTree pRoot;
    scanf("%d", &nValue);
    if (nValue == 0)
    {
        pRoot = NULL;
    }
    else
    {
        pRoot = (PBiTree)malloc(sizeof(BiTNode));
        if (NULL == pRoot)
        {
            printf("分配内存失败!\n");
        }
        else
        {
            pRoot->nValue = nValue;
            printf("请输入%d结点的左子结点:", pRoot->nValue);
            pRoot->pLChild = Create();

            printf("请输入%d结点的右子结点:", pRoot->nValue);
            pRoot->pRChild = Create();
        }
    }
    return pRoot;
}

PBiTree Init()
{
    int nValue;
    PBiTree pRoot;
    scanf("%d", &nValue);
    //输入0表示空结点
    if (nValue == 0)
    {
        pRoot = NULL;
        return pRoot;
    }
    else
    {
        pRoot = (PBiTree)malloc(sizeof(BiTNode));
        printf("请输入%d结点的左孩子:");
        pRoot->pLChild = Init();

        printf("请输入%d结点的右孩子:");
        pRoot->pRChild = Init();
        
        return pRoot;
    }
}
void Visit(PBiTree p)
{
    printf("%d ", p->nValue);
}

void PreOrder(PBiTree pRoot)
{
    if (NULL == pRoot)
    {
        return;
    }
    Visit(pRoot);
    PreOrder(pRoot->pLChild);
    PreOrder(pRoot->pRChild);
}

void PreOrder1(PBiTree pRoot)
{
    PBiTree pStack[100];
    int nTop = 0;
    PBiTree pCur = pRoot;

    while (nTop > 0 || pCur != NULL)
    {
        while (pCur != NULL)
        {//访问结点pCur所有的左孩子 
            Visit(pCur);
            pStack[nTop++] = pCur;
            pCur = pCur->pLChild;
        }

        if (nTop > 0)
        {//出栈 访问右孩子
            nTop--;
            pCur = pStack[nTop];
            pCur = pCur->pRChild;
        }
    }
}

void InOrder(PBiTree pRoot)
{
    if (NULL == pRoot)
    {
        return;
    }
    InOrder(pRoot->pLChild);
    Visit(pRoot);
    InOrder(pRoot->pRChild);
}

void InOrder1(PBiTree pRoot)
{
    PBiTree pStack[100];
    int nTop = 0;
    PBiTree pCur = pRoot;

    while (nTop > 0 || pCur != NULL)
    {
        while (pCur != NULL)
        {
            pStack[nTop++] = pCur;
            pCur = pCur->pLChild;
        }

        if (nTop > 0)
        {
            nTop--;
            pCur = pStack[nTop];
            Visit(pCur);
            pCur = pCur->pRChild;
        }
    }
}

void PostOrder(PBiTree pRoot)
{
    if (NULL == pRoot)
    {
        return;
    }
    PostOrder(pRoot->pLChild);
    PostOrder(pRoot->pRChild);
    Visit(pRoot);
}

void PostOrder1(PBiTree pRoot)
{
    PBiTree pStack[100];
    int nTop = 0;
    PBiTree pCur = pRoot;
    PBiTree IsVisited = NULL;
    while (nTop > 0 || pCur != NULL)
    {
        while (pCur != NULL)
        {
            pStack[nTop++] = pCur;
            pCur = pCur->pLChild;
        }
        pCur = pStack[nTop - 1];
        if (pCur->pRChild == NULL && IsVisited == pCur->pRChild)
        {
            Visit(pCur);
            nTop--;
            IsVisited = pCur;
            pCur = NULL;
        }
        else
        {
            pCur = pCur->pRChild;
        }
        
    }
}

//逐层遍历二叉树
void LevelOrder(PBiTree pRoot)
{
    if (NULL == pRoot)
    {
        return;
    }
    PBiTree Queue[100];
    int nHead = 0;
    int nTail = 0;
    PBiTree pCur;
    
    Queue[nTail++] = pRoot;
    while (nHead != nTail)
    {
        pCur = Queue[nHead++];
        Visit(pCur);
        if (pCur->pLChild)
        {
            Queue[nTail++] = pCur->pLChild;
        }
        if (pCur->pRChild)
        {
            Queue[nTail++] = pCur->pRChild;
        }
    }
}

//只有根结点时 高度为1 深度为0
int TreeHight(PBiTree pRoot)
{
    int nCount;
    int nLChild, nRChild;
    if (NULL == pRoot)
    {
        return 0;
    }
    nLChild = TreeHight(pRoot->pLChild);
    nRChild = TreeHight(pRoot->pRChild);
    nCount = nLChild > nRChild ? nLChild : nRChild;

    return nCount + 1;
}

//叶子结点个数
int TreeLeaf(PBiTree pRoot)
{
    int nLChild, nRChild;
    if (pRoot == NULL)
    {
        return 0;
    }
    if (pRoot->pLChild == NULL && pRoot->pRChild == NULL)
    {
        return 1;
    }
    nLChild = TreeLeaf(pRoot->pLChild);
    nRChild = TreeLeaf(pRoot->pRChild);
    return nLChild + nRChild; 
}

int FindParent(PBiTree pRoot, int nValue)
{
    if (pRoot == NULL)
    {
        return 0;
    }
    if (pRoot->pLChild && pRoot->pLChild->nValue == nValue)
    {
        return pRoot->nValue;
    }
    if (pRoot->pRChild && pRoot->pRChild->nValue == nValue)
    {
        return pRoot->nValue;
    }
    FindParent(pRoot->pLChild, nValue);
    FindParent(pRoot->pRChild, nValue);
}

int LeftSibling(PBiTree pRoot, int nValue)
{
    if (pRoot == NULL)
    {
        return 0;
    }

    if (pRoot->pRChild && pRoot->pRChild->nValue == nValue)
    {
        if (pRoot->pLChild)
        {
            return pRoot->pLChild->nValue;
        }
    }
    FindParent(pRoot->pLChild, nValue);
    FindParent(pRoot->pRChild, nValue);
}

int RightSibling(PBiTree pRoot, int nValue)
{
    if (pRoot == NULL)
    {
        return 0;
    }

    if (pRoot->pLChild && pRoot->pLChild->nValue == nValue)
    {
        if (pRoot->pRChild)
        {
            return pRoot->pRChild->nValue;
        }
    }
    FindParent(pRoot->pLChild, nValue);
    FindParent(pRoot->pRChild, nValue);
}

int main()
{
    printf("请输入根结点的值:");
    PBiTree pRoot = Create();

    printf("前序遍历:");
    PreOrder1(pRoot);
    
    printf("中序遍历:");
    InOrder1(pRoot);

    printf("后序遍历:");
    PostOrder(pRoot);
    
    printf("逐层遍历:");
    LevelOrder(pRoot);

    printf("二叉树的高度为:%d\n", TreeHight(pRoot));
    printf("二叉树的叶子个数为:%d\n", TreeLeaf(pRoot));
    
    int rv = FindParent(pRoot, 4);
    if (rv != 0)
    {
        printf("父结点的值为:%d\n", rv);
    }
    else
    {
        printf("该结点无父结点!\n", rv);
    }

    rv = LeftSibling(pRoot, 4);
    if (rv != 0)
    {
        printf("左兄弟结点的值为:%d\n", rv);
    }
    else
    {
        printf("该结点无左兄弟结点!\n", rv);
    }

	system("pause");
    return 0;
}