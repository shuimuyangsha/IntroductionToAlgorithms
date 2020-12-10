#include <iostream>
using namespace std;

struct LinkNode
{
public:
    LinkNode(int value = 0): nValue(value){ pNext = NULL; }
    ~LinkNode() { pNext = NULL; }
private:
    friend class LinkList;
    int nValue;
    LinkNode *pNext;
};

class LinkList
{
public:
    LinkList();
    ~LinkList();
    void Insert(int nData);
    void Delete(int nData);
    void Sort();
    bool IsEmpty();
    void Reverse();
    void Destroy();
    int Length();
    LinkNode* Find(int nData);
    bool IsLoop();
    void Print();
private:
    LinkNode *pHead;
};

LinkList::LinkList()
{
    pHead = new LinkNode();
}
LinkList::~LinkList()
{
    Destroy();
}
//从大到小插入
void LinkList::Insert(int nData)
{
    if (pHead == NULL)
    {
        cout<<"链表未创建!"<<endl;
        return;
    }
    LinkNode *pCur = pHead;
    while (pCur->pNext != NULL)
    {
        if (pCur->pNext->nValue < nData)
        {
            break;
        }
        pCur = pCur->pNext;
    }
    LinkNode *pTmp = new LinkNode(nData);
    pTmp->pNext = pCur->pNext;
    pCur->pNext = pTmp;
}

void LinkList::Delete(int nData)
{
    if (pHead == NULL)
    {
        cout<<"链表未创建!"<<endl;
        return;
    }
    if (pHead->pNext == NULL)
    {
        cout<<"链表为空!"<<endl;
        return;
    }

    LinkNode *pCur = pHead;
    while (pCur->pNext)
    {
        if (pCur->pNext->nValue == nData)
        {
            LinkNode *pDel = pCur->pNext;
            pCur->pNext = pCur->pNext->pNext;
            
            pDel->pNext = NULL;
            delete (pDel);
        }
        else
        {
            pCur = pCur->pNext;
        }
    }
}

void LinkList::Sort()
{
    if (pHead == NULL)
    {
        cout<<"链表未创建!"<<endl;
        return;
    }
    if (pHead->pNext == NULL)
    {
        cout<<"链表为空!"<<endl;
    }
    
    LinkNode *pCur = pHead->pNext;
    LinkNode *pPre = pHead;

    LinkNode *pNewHead = new LinkNode();
    while (pCur)
    {
        LinkNode *pTmp = pCur;
        pCur = pCur->pNext;
        
        //将pTmp结点插入到pNewHead指向的新链表中
        LinkNode *p = pNewHead;  
        while (p->pNext)
        {
            if (p->pNext->nValue > pTmp->nValue)
            {
                break;
            }
            p = p->pNext;
        }
        pTmp->pNext = p->pNext;
        p->pNext = pTmp;       
    }
    delete pHead;
    pHead = pNewHead;
}
bool LinkList::IsEmpty()
{
    if (pHead == NULL)
    {
        cout<<"链表未创建!"<<endl;
        return false;
    }

    return pHead->pNext == NULL;
}

int LinkList::Length()
{
    if (pHead == NULL)
    {
        cout<<"链表未创建!"<<endl;
        return 0;
    }
    int nLength = 0;
    LinkNode *pCur = pHead->pNext;
    while (pCur)
    {
        nLength++;
        pCur = pCur->pNext;
    }

    return nLength;
}
void LinkList::Reverse()
{
    if (pHead == NULL)
    {
        cout<<"链表未创建!"<<endl;
    }
    if (pHead->pNext == NULL)
    {
        cout<<"链表为空!"<<endl;
    }
    else
    {
        LinkNode *pCur = pHead->pNext->pNext;
        LinkNode *pPre = pHead->pNext;
        LinkNode *pnext = NULL;

        while (pCur)
        {
            pnext = pCur->pNext;
            pCur->pNext = pPre;

            pPre = pCur;
            pCur = pnext;       
        }

        pHead->pNext->pNext = NULL;
        pHead->pNext = pPre;
    }
}
void LinkList::Destroy()
{
    if (pHead == NULL)
    {
        cout<<"链表未创建!"<<endl;
        return;
    }
    
    while (pHead->pNext)
    {
        LinkNode *pDel = pHead->pNext;
        pHead->pNext = pDel->pNext;
        delete pDel;
    }
    delete pHead;
    pHead = NULL;
}
LinkNode* LinkList::Find(int nData)
{
    if (pHead == NULL)
    {
        cout<<"链表未创建!"<<endl;
        return NULL;
    }
    if (pHead->pNext == NULL)
    {
        cout<<"链表为空!"<<endl;
        return NULL;
    }

    LinkNode *pCur = pHead->pNext;
    while (pCur != NULL)
    {
        if (pCur->nValue == nData)
        {
            return pCur;
        }
    }
    
    return NULL;
}
void LinkList::Print()
{
    if (pHead == NULL)
    {
        cout<<"链表未创建!"<<endl;
        return;
    }
    if (pHead->pNext == NULL)
    {
        cout<<"链表为空!"<<endl;
        return;
    }
    else
    {
        LinkNode *pCur = pHead->pNext;
        while (pCur)
        {
            cout<<pCur->nValue<<" ";
            pCur = pCur->pNext;
        }
        cout<<endl;
    }
}
bool LinkList::IsLoop()
{
    if (pHead == NULL)
    {
        cout<<"链表未创建!"<<endl;
        return false;
    }
    if (pHead->pNext == NULL)
    {
        cout<<"链表为空!"<<endl;
        return false;
    }

    LinkNode *pFast = pHead->pNext;
    LinkNode *pLow = pHead->pNext;

    while (pFast != NULL && pLow != NULL  && pFast->pNext != NULL)
    {
        pFast = pFast->pNext->pNext;
        pLow = pLow->pNext;
        if (pFast == pLow)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    LinkList list;
    list.Insert(12);
    list.Insert(14);
    list.Insert(2);
    list.Insert(4);
    list.Insert(5);
    list.Insert(4);
    list.Insert(7);
    list.Print();
    list.Delete(5);
    list.Print();

    list.Sort();
    list.Destroy();
    list.Print();
    
	system("pause");
    return 0;
}