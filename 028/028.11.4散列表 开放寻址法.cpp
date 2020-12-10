#include <iostream>
#include <time.h>
using namespace std;

template <class T>
class HashTable
{
private:
	T *pArr;
	int nSize;
	T EMPTY;	//Ϊ��
	T TOMB;		//Ĺ��
	int nCount;
	int hFun(T key)	//ɢ�к���
	{
		return key % nSize;
	}
	int hDoubleFun(T key)	//˫ɢ�к���
	{
		int h1 = key % nSize;
		int h2 = key % nSize + 1;
		return (h1 + h2) % nSize;
	}

	int p(T key, int i)    //̽�麯��
	{
		return i;
	}

public:
	HashTable(int count, T empty, T tomb);
	~HashTable(){ delete pArr; }
	bool HashInsert(T value);
	bool HashSearch(T value);
	T HashDelete(const T value);
	int Count(){  return nCount; }
};

template<class T>
HashTable<T>::HashTable(int size, T empty, T tomb)
{
	nSize = size;
	pArr = new T[nSize];
	nCount = 0;
	EMPTY = empty;
	TOMB = tomb;

	for (int i = 0; i < nSize; i++)
	{
		pArr[i] = EMPTY;  
	}
}

template<class T>
bool HashTable<T>::HashInsert(T value)
{
	int key = hFun(value);
	int nPos = key;
	int FirstTombPos;
	bool tombPos = false;
	int i = 0;

	while(pArr[nPos] != EMPTY)
	{
		if (pArr[nPos] == value)
		{
			return false;
		}
		if (pArr[nPos] == TOMB && tombPos == false)
		{
			FirstTombPos = nPos;
			tombPos = true;
		}
		i++;
		nPos = (key + p(key, i)) % nSize;
	}

	if (tombPos == false)
	{//����̽�����е�β���ղۣ� ���Բ�����Ԫ�� ��û������Ĺ����
		pArr[nPos] = value;
	}
	else
	{
		pArr[FirstTombPos] = value;
	}
	return true;
}

template<class T>
bool HashTable<T>::HashSearch(T value)
{
	int key = hFun(value);
	int nPos = key;
	int i = 0;
	while(pArr[nPos] != EMPTY)
	{
		if(pArr[nPos] == value)
		{
			return true;
		}
		i++;
		nPos = (key + p(value,i)) % nSize;
	}

	return false;
}

template<class T>
T HashTable<T>::HashDelete(T value)
{
	int key = hFun(value);
	int nPos = key;
	int i = 0;

	while(pArr[nPos] != EMPTY)
	{
		if (pArr[nPos] == value)
		{//�ҵ�Ҫɾ����Ԫ�� ����Ĺ��
			int nTmp = pArr[nPos];
			pArr[nPos] = TOMB;
			return nTmp;
		}
		i++;
		nPos = (key + p(value, i)) % nSize;
	}

	return EMPTY;
}
int main()
{
	HashTable<int> hashTable(11, -1, -2);
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int nTmp = rand()%100 + 1;
		cout<<nTmp<<" ";
		hashTable.HashInsert(nTmp);
	}
	
	int nSearch;
	cin>>nSearch;
	cout<<hashTable.HashSearch(nSearch)<<endl;
	int nDel;
	cin>>nDel;
	hashTable.HashDelete(nDel);
	cout<<hashTable.HashSearch(nDel)<<endl;

	system("pause");
	return 0;
}
                                           