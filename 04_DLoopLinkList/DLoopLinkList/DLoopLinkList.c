#include "DLoopLinkList.h"



/*=======================================================
*	@函数功能：创建头节点
*	@函数参数：无
*	@函数返回：成功返回PDLoopLinkList头节点，失败返回NULL
*=======================================================*/
PDLoopLinkList InitHeadNode()
{
	//创建头节点
	DLoopLinkList* pHead = (DLoopLinkList*)malloc(sizeof(DLoopLinkList));
	if (!pHead)
	{
		return NULL;
	}
	//初始化头节点
	pHead->data = 0;	//头节点数据用来记录节点个数
	//循环链表，初始头尾相连
	pHead->previous = pHead;
	pHead->next = pHead;

	return pHead;
}



/*=======================================================
*	@函数功能：链表尾插入节点
*	@函数参数：DLoopLinkList*
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int InsertNode(DLoopLinkList* pHead, ElemType data)
{
	//判断头节点是否存在
	if (!pHead)
	{
		return -1;
	}
	//创建新节点
	DLoopLinkList* pNewNode = (DLoopLinkList*)malloc(sizeof(DLoopLinkList));
	if (!pNewNode)
	{
		return -1;
	}
	//初始化新节点
	pNewNode->data = data;
	pNewNode->previous = NULL;
	pNewNode->next = NULL;
	//头尾相连
	DLoopLinkList* pTail = pHead->previous;	//头节点的前驱就是尾节点
	pTail->next = pNewNode;
	pNewNode->previous = pTail;
	pNewNode->next = pHead;
	pHead->previous = pNewNode;
	//节点数量++
	pHead->data++;

	return 0;
}



/*=======================================================
*	@函数功能：链表头插入节点
*	@函数参数：DLoopLinkList* , data
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int InsertNodeToHead(DLoopLinkList* pHead, ElemType data)
{
	//判断头节点是否存在
	if (!pHead)
	{
		return -1;
	}
	//创建新节点
	DLoopLinkList* pNewNode = (DLoopLinkList*)malloc(sizeof(DLoopLinkList));
	if (!pNewNode)
	{
		return -1;
	}
	//初始化新节点
	pNewNode->data = data;
	pNewNode->previous = NULL;
	pNewNode->next = NULL;
	//建立链接
	DLoopLinkList* pFirst = pHead->next;
	pHead->next = pNewNode;
	pNewNode->previous = pHead;
	pNewNode->next = pFirst;
	pFirst->previous = pNewNode;
	//节点数量++
	pHead->data++;

	return 0;
}



/*=======================================================
*	@函数功能：链表指定位置插入节点
*	@函数参数：DLoopLinkList* , pos , data
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int InsertNodeToPos(DLoopLinkList* pHead, int pos, ElemType data)
{
	//判断头节点是否存在
	if (!pHead)
	{
		return -1;
	}
	//判断位置是否合法
	if (pos < 1 || pos > pHead->data)
	{
		return -1;
	}
	//判断插入位置是否等于头
	if (pos == 1)
	{
		InsertNodeToHead(pHead,data);
		return 0;
	}
	//判断插入位置是否等于尾
	if (pos == 1)
	{
		InsertNode(pHead,data);
		return 0;
	}
	//创建新节点
	DLoopLinkList* pNewNode = (DLoopLinkList*)malloc(sizeof(DLoopLinkList));
	if (!pNewNode)
	{
		return -1;
	}
	//初始化新节点
	pNewNode->data = data;
	pNewNode->previous = NULL;
	pNewNode->next = NULL;
	//循环移动后继到pos
	DLoopLinkList* pCurrent = pHead->next;
	for (int i = 1; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	//建立关系
	DLoopLinkList* pCurPrevious = pCurrent->previous;
	pNewNode->next = pCurrent;
	pNewNode->previous = pCurrent->previous;
	pCurrent->previous = pNewNode;
	pCurPrevious->next = pNewNode;
	//节点数量++
	pHead->data++;

	return 0;
}



/*=======================================================
*	@函数功能：链表尾删除节点
*	@函数参数：DLoopLinkList*
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int DeleteNode(DLoopLinkList* pHead)
{
	//判断头节点是否存在
	if (!pHead)
	{
		return -1;
	}
	//判断是否是头节点
	DLoopLinkList* pCurrent = pHead->previous;
	if (pCurrent != pHead)
	{
		//保存尾节点的前驱节点
		DLoopLinkList* pLast = pCurrent->previous;
		//头尾相连
		pLast->next = pHead;
		pHead->previous = pLast;
		//释放尾节点
		free(pCurrent);
		//节点数量--
		pHead->data--;

		return 0;
	}
	

	return -1;
}



/*=======================================================
*	@函数功能：链表头删除节点
*	@函数参数：DLoopLinkList*
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int DeleteNodeToHead(DLoopLinkList* pHead)
{
	//判断头节点是否存在
	if (!pHead)
	{
		return -1;
	}
	//判断是否是头节点
	DLoopLinkList* pCurrent = pHead->next;
	if (pCurrent != pHead)
	{
		//保存第一个节点的后继节点
		DLoopLinkList* pFirst = pCurrent->next;
		//建立链接
		pHead->next =  pFirst;
		pFirst->previous = pHead;
		//释放尾节点
		free(pCurrent);
		//节点数量--
		pHead->data--;

		return 0;
	}
}



/*=======================================================
*	@函数功能：链表指定位置删除节点
*	@函数参数：DLoopLinkList* , pos
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int DeleteNodeToPos(DLoopLinkList* pHead, int pos)
{
	//判断头节点是否存在
	if (!pHead)
	{
		return -1;
	}
	//判断位置是否等于头
	if (pos == 1)
	{
		DeleteNodeToHead(pHead);
		return 0;
	}
	//判断位置是否等于尾
	if (pos == pHead->data)
	{
		DeleteNode(pHead);
		return 0;
	}
	//移动节点
	DLoopLinkList* pCurrent = pHead->next;
	for (int i = 1; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	//建立链接
	DLoopLinkList* pCurPrevious = pCurrent->previous;
	DLoopLinkList* pCurNext = pCurrent->next;
	pCurPrevious->next = pCurrent->next;
	pCurNext->previous = pCurPrevious;
	//释放节点
	free(pCurrent);
	//节点数量--
	pHead->data--;

	return 0;
}


/*=======================================================
*	@函数功能：获取链表节点长度
*	@函数参数：DLoopLinkList*
*	@函数返回：成功返回链表节点个数，失败返回-1
*=======================================================*/
int GetDLoopLinkListLen(DLoopLinkList* pHead)
{
	//判断头节点是否存在
	if (!pHead)
	{
		return -1;
	}

	return pHead->data;
}



/*=======================================================
*	@函数功能：清空链表
*	@函数参数：DLoopLinkList*
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int ClearDLoopLinkList(DLoopLinkList* pHead)
{
	//判断头节点是否存在
	if (!pHead)
	{
		return -1;
	}
	//判断链表是否为空
	while (pHead == pHead->next)
	{
		return 0;
	}
	//除头节点，循环释放所有节点
	DLoopLinkList* pCurrent = pHead->next;
	DLoopLinkList* pCurPrevious = pHead;
	while (pCurrent != pHead)
	{
		pCurPrevious = pCurrent->next;
		free(pCurrent);
		pHead->data--;
		pCurrent = pCurPrevious;
	}
	//头节点指向前驱后继都指向自己
	pHead->previous = pHead;
	pHead->next = pHead;

	return 0;
}



/*=======================================================
*	@函数功能：销毁链表
*	@函数参数：DLoopLinkList**
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int RemoveDLoopLinkList(DLoopLinkList** pHead)
{
	//判断头节点是否存在
	if ((*pHead)->previous == *pHead  && (*pHead)->next == *pHead)
	{
		free(*pHead);
		*pHead = NULL;
		return 0;
	}
	return -1;
}



/*=======================================================
*	@函数功能：遍历节点
*	@函数参数：DLoopLinkList*
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int PrintDLoopLinkList(DLoopLinkList* pHead)
{
	//判断头节点是否存在
	if (!pHead)
	{
		return -1;
	}
	//循环打印节点
	DLoopLinkList* pCurrent = pHead->next;  //不打印头节点
	while (pCurrent != pHead)
	{
		printf("CurNode->data: %-4d  CurNode->addr: %#8X  CurNode->next: %#9X  CurNode->prev: %#8X\n", pCurrent->data,
			pCurrent, pCurrent->next, pCurrent->previous);
		pCurrent = pCurrent->next;
	}

	return 0;
}