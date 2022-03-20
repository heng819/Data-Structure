#include "DLinkList.h"



/*=======================================================
*	@函数功能：创建头节点
*	@函数参数：无
*	@函数返回：成功返回PLinkList头节点，失败返回NULL
*=======================================================*/
PLinkList InitHeadNode()
{
	//创建头节点
	LinkList* pHead = (LinkList*)malloc(sizeof(LinkList));
	if (!pHead)
	{
		return NULL;
	}
	//初始化头节点
	pHead->data = 0;	//头节点数据用来记录节点个数
	pHead->previous = NULL;
	pHead->next = NULL;

	return pHead;
}



/*=======================================================
*	@函数功能：链表尾插入节点
*	@函数参数：LinkList*
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int InsertNode(LinkList* pHead,ElemType data)
{
	//判断头节点是否存在
	if (!pHead)
	{
		return -1;
	}
	//创建新节点
	LinkList* pNewNode = (LinkList*)malloc(sizeof(LinkList));
	if (!pNewNode)
	{
		return -1;
	}
	//初始化新节点
	pNewNode->data = data;
	pNewNode->previous = NULL;
	pNewNode->next = NULL;
	//建立链接
	LinkList* pCurrent = pHead;
	while (pCurrent->next != NULL)
	{
		pCurrent = pCurrent->next;
	}
	pCurrent->next = pNewNode;
	pNewNode->previous = pCurrent;
	pNewNode->next = NULL;
	//节点数量++
	pHead->data++;

	return 0;
}



/*=======================================================
*	@函数功能：链表头插入节点
*	@函数参数：LinkList* , data
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int InsertNodeToHead(LinkList* pHead, ElemType data)
{
	//判断头节点是否存在
	if (!pHead)
	{
		return -1;
	}
	//创建新节点
	LinkList* pNewNode = (LinkList*)malloc(sizeof(LinkList));
	if (!pNewNode)
	{
		return -1;
	}
	//初始化新节点
	pNewNode->data = data;
	pNewNode->previous = NULL;
	pNewNode->next = NULL;
	//建立链接
	LinkList* pCurrent = pHead;
	pNewNode->next = pCurrent->next;
	pNewNode->previous = pCurrent;
	pCurrent->next = pNewNode;
	//节点数量++
	pHead->data++;

	return 0;
}



/*=======================================================
*	@函数功能：链表指定位置插入节点
*	@函数参数：LinkList* , pos , data
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int InsertNodeToPos(LinkList* pHead, int pos, ElemType data)
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
	//创建新节点
	LinkList* pNewNode = (LinkList*)malloc(sizeof(LinkList));
	if (!pNewNode)
	{
		return -1;
	}
	//初始化新节点
	pNewNode->data = data;
	pNewNode->previous = NULL;
	pNewNode->next = NULL;
	//循环移动后继到pos
	LinkList* pCurrent = pHead->next;
	for (int i = 1; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	//建立关系
	LinkList* pCurPrevious = pCurrent->previous;
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
*	@函数参数：LinkList*
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int DeleteNode(LinkList* pHead)
{
	//判断头节点是否存在
	if (!pHead || !pHead->next)
	{
		return -1;
	}
	//移动到链表尾
	LinkList* pCurrent = pHead->next;
	while (pCurrent->next != NULL)
	{
		pCurrent = pCurrent->next;
	}
	//将尾节点的前驱的后继置为NULL
	LinkList* pPreCurrent = pCurrent->previous;
	pPreCurrent->next = NULL;
	//释放尾节点
	free(pCurrent);
	//节点数量--
	pHead->data--;

	return 0;
}



/*=======================================================
*	@函数功能：链表头删除节点
*	@函数参数：LinkList*
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int DeleteNodeToHead(LinkList* pHead)
{
	//判断头节点是否存在
	if (!pHead || !pHead->next)
	{
		return -1;
	}
	//建立链接
	LinkList* pCurrent = pHead->next;
	LinkList* pCurrentNext = pCurrent->next;
	pHead->next = pCurrent->next;
	pCurrentNext->previous = pHead;
	//释放节点
	free(pCurrent);
	//节点数量--
	pHead->data--;

	return 0;
}



/*=======================================================
*	@函数功能：链表指定位置删除节点
*	@函数参数：LinkList* , pos
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int DeleteNodeToPos(LinkList* pHead, int pos)
{
	//判断头节点是否存在
	if (!pHead || !pHead->next)
	{
		return -1;
	}
	//判断位置是否合法
	if (pos < 1 || pos > pHead->data)
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
	LinkList* pCurrent = pHead->next;
	for (int i = 1; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	//建立链接
	LinkList* pCurPrevious = pCurrent->previous;
	LinkList* pCurNext = pCurrent->next;
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
*	@函数参数：LinkList*
*	@函数返回：成功返回链表节点个数，失败返回-1
*=======================================================*/
int GetLinkListLen(LinkList* pHead)
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
*	@函数参数：LinkList*
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int ClearLinkList(LinkList* pHead)
{
	//判断头节点是否存在
	if (!pHead)
	{
		return -1;
	}
	//判断链表是否为空
	if (pHead->data == 0)
	{
		return 0;
	}
	//循环释放节点
	LinkList* pCurrent = pHead->next;
	LinkList* pCurPrevious = pHead;
	while (pCurrent != NULL)
	{
		pCurPrevious = pCurrent->next;
		free(pCurrent);
		pHead->data--;
		pCurrent = pCurPrevious;
	}
	//头节点指向NULL
	pHead->next = NULL;

	return 0;
}



/*=======================================================
*	@函数功能：销毁链表
*	@函数参数：LinkList**
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int RemoveLinkList(LinkList** pHead)
{
	//判断头节点是否存在
	if (*pHead != NULL && (*pHead)->next == NULL)
	{
		free(*pHead);
		*pHead = NULL;
		return 0;
	}
	return -1;
}



/*=======================================================
*	@函数功能：遍历节点
*	@函数参数：LinkList*
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int PrintLinkList(LinkList* pHead)
{
	//判断头节点是否存在
	if (!pHead)
	{
		return -1;
	}
	//循环打印节点
	LinkList* pCurrent = pHead->next;  //不打印头节点
	for (int i = 0; i < pHead->data; i++)
	{
		printf("CurNode->data: %-4d  CurNode->addr: %#8X  CurNode->next: %#9X  CurNode->prev: %#8X\n",pCurrent->data,
		pCurrent,pCurrent->next,pCurrent->previous);
		pCurrent = pCurrent->next;
	}

	return 0;
}