#include "SqList.h"

/*=======================================================
*	@函数功能：创建线性表
*	@函数参数：无
*	@函数返回：成功返回SqList*，失败返回NULL
*=======================================================*/
SqList* InitSqList()
{
	//创建线性表结构
	SqList* pSqList = (SqList*)malloc(sizeof(SqList));
	if (!pSqList)
	{
		return NULL;
	}
	//创建线性表
	pSqList->elem = (ElemType*)malloc(sizeof(ElemType) * INIT_SIZE);
	if (!pSqList->elem)
	{
		return NULL;
	}
	//初始化线性表
	pSqList->len = 0;
	pSqList->capacity = INIT_SIZE;

	return pSqList;
}



/*=======================================================
*	@函数功能：线性表尾插入元素
*	@函数参数：SqList* , data
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int InsertSqList(SqList* pList, ElemType data)
{
	//判断线性表是否存在
	if (!pList || !pList->elem)
	{
		return -1;
	}
	//判断线性表是否已满
	if (pList->len == pList->capacity)
	{
		//创建比原线性表空间更大的线性表
		ElemType* pNewSqList = (ElemType*)malloc(sizeof(ElemType) * (pList->capacity + INIT_INCREASE));
		if (!pNewSqList)
		{
			return -1;
		}
		//原线性表内容拷贝到新线性表
		memcpy(pNewSqList, pList->elem, sizeof(ElemType) * pList->capacity);
		//释放原线性表空间
		free(pList->elem);
		//指向新的线性表
		pList->elem = pNewSqList;
		//更新容量
		pList->capacity += INIT_INCREASE;
	}
	//末尾插入数据
	pList->elem[pList->len] = data;
	//线性表长度++
	pList->len++;

	return 0;
}



/*=======================================================
*	@函数功能：线性表头插入元素
*	@函数参数：SqList* , data
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int HeadInsertToSqList(SqList* pList, ElemType data)
{
	//判断线性表是否存在
	if (!pList || !pList->elem)
	{
		return -1;
	}
	//判断线性表是否已满
	if (pList->len == pList->capacity)
	{
		//创建比原线性表空间更大的线性表
		ElemType* pNewSqList = (ElemType*)malloc(sizeof(ElemType) * (pList->capacity + INIT_INCREASE));
		if (!pNewSqList)
		{
			return -1;
		}
		//原线性表内容拷贝到新线性表
		memcpy(pNewSqList, pList->elem, sizeof(ElemType) * pList->capacity);
		//释放原线性表空间
		free(pList->elem);
		//指向新的线性表
		pList->elem = pNewSqList;
		//更新容量
		pList->capacity += INIT_INCREASE;
	}
	//元素后移
	for (int i = pList->len - 1; i >= 0; i--)
	{
		pList->elem[i+1] = pList->elem[i];
	}
	//头部插入数据
	pList->elem[0] = data;
	//线性表长度++
	pList->len++;
}



/*=======================================================
*	@函数功能：指定位置插入线性表
*	@函数参数：SqList* , pos , data
*	@函数返回：成功返回0，位置不合法返回-2，失败返回-1
*=======================================================*/
int PosInsertToSqList(SqList* pList, int pos, ElemType data)
{
	//判断线性表是否存在
	if (!pList || !pList->elem)
	{
		return -1;
	}
	//判断插入位置是否合法
	if (pos < 1 || pos > pList->len + 1)	//从1开始插入，大于pList->len + 1尾插
	{
		return -2;
	}
	//判断线性表是否已满
	if (pList->len == pList->capacity)
	{
		//创建比原线性表空间更大的线性表
		ElemType* pNewSqList = (ElemType*)malloc(sizeof(ElemType) * (pList->capacity + INIT_INCREASE));
		if (!pNewSqList)
		{
			return -1;
		}
		//原线性表内容拷贝到新线性表
		memcpy(pNewSqList, pList->elem, sizeof(ElemType) * pList->capacity);
		//释放原线性表空间
		free(pList->elem);
		//指向新的线性表
		pList->elem = pNewSqList;
		//更新容量
		pList->capacity += INIT_INCREASE;
	}
	//元素后移
	for (int i = pList->len - 1; i >= pos - 1; i--)
	{
		pList->elem[i+1] = pList->elem[i];
	}
	//位置插入数据，-1换算位置与下标关系
	pList->elem[pos-1] = data;
	//线性表长度++
	pList->len++;

	return 0;
}



/*=======================================================
*	@函数功能：线性表尾删除元素
*	@函数参数：SqList*
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int DeleteSqList(SqList* pList)
{
	//判断线性表是否存在
	if (!pList || !pList->elem)
	{
		return -1;
	}
	//判断线性表是否存在元素
	if (pList->len == 0)
	{
		return 0;
	}
	//线性表长度--
	pList->len--;
	
	return 0;
}



/*=======================================================
*	@函数功能：线性表头删除元素
*	@函数参数：SqList*
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int HeadDeleteToSqList(SqList* pList)
{
	//判断线性表是否存在
	if (!pList || !pList->elem)
	{
		return -1;
	}
	//判断线性表是否存在元素
	if (pList->len == 0)
	{
		return 0;
	}
	//移动元素
	for (int i = 1; i <= pList->len - 1; i++)
	{
		pList->elem[i-1] = pList->elem[i];
	}
	//线性表长度--
	pList->len--;

	return 0;
}



/*=======================================================
*	@函数功能：指定位置删除线性表
*	@函数参数：SqList* , pos
*	@函数返回：成功返回0，位置不合法返回-2，失败返回-1
* ======================================================*/
int PosDeleteToSqList(SqList* pList, int pos)
{
	//判断线性表是否存在
	if (!pList || !pList->elem)
	{
		return -1;
	}
	//判断线性表是否存在元素
	if (pList->len == 0)
	{
		return 0;
	}
	//判断删除位置是否合法
	if (pos < 1 || pos > pList->len)	
	{
		return -2;
	}
	//判断删除的是否是尾部
	if (pList->len == pos)
	{
		DeleteSqList(pList);
		return 0;
	}
	//判断删除的是否是头部
	if (pos == 1)
	{
		HeadDeleteToSqList(pList);
		return 0;
	}
	//移动元素
	for (int i = pos - 1; i <= pList->len - 1; i++)
	{
		pList->elem[i] = pList->elem[i + 1];
	}
	//线性表长度--
	pList->len--;

	return 0;
}



/*=======================================================
*	@函数功能：获取线性表指定位置值
*	@函数参数：@函数参数：SqList* , pos
*	@函数返回：成功返回该值，位置不合法返回-2，失败返回-1
*=======================================================*/
int GetPosValueSqList(SqList* pList,int pos)
{
	//判断线性表是否存在
	if (!pList || !pList->elem)
	{
		return -1;
	}
	//判断线性表是否存在元素
	if (pList->len == 0)
	{
		return -1;
	}
	//判断位置是否合法
	if (pos < 1 || pos > pList->len)
	{
		return -2;
	}

	return pList->elem[pos - 1];
}



/*=======================================================
*	@函数功能：获取线性表长度
*	@函数参数：SqList*
*	@函数返回：成功返回线性表长度，失败返回-1
*=======================================================*/
int GetSqListLen(SqList* pList)
{
	//判断线性表是否存在
	if (!pList || !pList->elem)
	{
		return -1;
	}
	return pList->len;
}


/*=======================================================
*	@函数功能：清空线性表
*	@函数参数：SqList*
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int ClearSqList(SqList* pList)
{
	//判断线性表是否存在
	if (!pList || !pList->elem)
	{
		return -1;
	}
	//判断线性表是否存在元素
	if (pList->len == 0)
	{
		return 0;
	}
	pList->len = 0;

	return 0;
}



/*=======================================================
*	@函数功能：遍历线性表
*	@函数参数：SqList*
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int PrintSqList(SqList* pList)
{
	//判断线性表是否存在
	if (!pList || !pList->elem)
	{
		return -1;
	}
	for (int i = 0; i < pList->len; i++)
	{
		printf("List[%-2d]: %c addr: %p\n",i,pList->elem[i],&pList->elem[i]);
	}
	return 0;
}



/*=======================================================
*	@函数功能：释放线性表空间
*	@函数参数：SqList**
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int FreeSqList(SqList** pList)
{
	//判断线性表是否存在
	if (!*pList || !(*pList)->elem)
	{
		return -1;
	}
	free((*pList)->elem);
	(*pList)->elem = NULL;

	free(*pList);
	*pList = NULL;
}