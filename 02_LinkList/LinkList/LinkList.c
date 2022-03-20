#include "LinkList.h"



/*=======================================================
*	@函数功能：创建头节点
*	@函数参数：无
*	@函数返回：成功返回PLinkList头节点，失败返回NULL
*=======================================================*/
PLinkNode InitHeadNode()
{
	//创建头节点
	LinkNode* pHead = (LinkNode*)malloc(sizeof(LinkNode));
	if (!pHead)
	{
		return NULL;
	}
	//初始化头节点
	pHead->data = 0;		//头节点数据用来记录节点个数,不记录头节点
	pHead->next = NULL;

	return pHead;
}



/*=======================================================
*	@函数功能：链表尾插入节点
*	@函数参数：LinkNode* , data
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int InsertLinkNode(LinkNode* pHead, ElemType data)
{
	//判断头节点是否存在
	if (!pHead)
	{
		return -1;
	}
	//创建新节点
	LinkNode* pNewNode = (LinkNode*)malloc(sizeof(LinkNode));
	if (!pNewNode)
	{
		return -1;
	}
	//初始化新节点
	pNewNode->data = data;
	pNewNode->next = NULL;
	//移动节点后继到尾部
	LinkNode* pCurrent = pHead;
	while (pCurrent->next != NULL)
	{
		pCurrent = pCurrent->next;
	}
	//建立链接
	pCurrent->next = pNewNode;
	//节点数量++
	pHead->data++;

	return 0;
}



/*=======================================================
*	@函数功能：链表头插入节点
*	@函数参数：LinkNode* , data
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int InsertNodeToHead(LinkNode* pHead, ElemType data)
{
	//判断头节点是否存在
	if (!pHead)
	{
		return -1;
	}
	//创建新节点
	LinkNode* pNewNode = (LinkNode*)malloc(sizeof(LinkNode));
	if (!pNewNode)
	{
		return -1;
	}
	//初始化新节点
	pNewNode->data = data;
	pNewNode->next = NULL;

	//建立链接
	LinkNode* pCurrent = pHead;
	//1、新节点后继指向头节点后继
	pNewNode->next = pCurrent->next;
	//2、头节点后继指向新节点
	pHead->next = pNewNode;

	//节点数量++
	pHead->data++;

	return 0;
}



/*=======================================================
*	@函数功能：链表指定位置插入节点
*	@函数参数：LinkNode* , pos , data
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int PosInsertToNode(LinkNode* pHead, int pos, ElemType data)
{
	//判断头节点是否存在
	if (!pHead)
	{
		return -1;
	}
	//判断插入位置
	if (pos < 1 || pos > pHead->data)
	{
		return -1;
	}
	//创建新节点
	LinkNode* pNewNode = (LinkNode*)malloc(sizeof(LinkNode));
	if (!pNewNode)
	{
		return -1;
	}
	//初始化新节点
	pNewNode->data = data;
	pNewNode->next = NULL;

	//移动节点后继到pos
	LinkNode* pCurrent = pHead->next;	//当前节点
	LinkNode* pPrevious = pHead;		//当前节点前驱
	for (int i = 1; i < pos; i++)
	{
		pPrevious = pCurrent;
		pCurrent = pCurrent->next;
	}
	pNewNode->next = pCurrent;
	pPrevious->next = pNewNode;

	//节点数量++
	pHead->data++;
}



/*=======================================================
*	@函数功能：链表尾删除节点
*	@函数参数：LinkNode*
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int DeleteNode(LinkNode* pHead)
{
	//判断头节点是否存在
	if (!pHead || !pHead->next)
	{
		return -1;
	}
	//移动节点后继到尾部
	LinkNode* pCurrent = pHead->next;
	LinkNode* pPrevious = pHead;		//当前节点前驱
	while (pCurrent->next != NULL)
	{
		pPrevious = pCurrent;
		pCurrent = pCurrent->next;
	}
	//释放节点
	free(pCurrent);
	//尾节点后继指向NULL
	pPrevious->next = NULL;
	//节点数量--
	pHead->data--;

	return 0;
}



/*=======================================================
*	@函数功能：线性表头删除元素
*	@函数参数：LinkNode*
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int HeadDeleteToNode(LinkNode* pHead)
{
	//判断头节点是否存在
	if (!pHead || !pHead->next)
	{
		return -1;
	}
	//当前节点
	LinkNode* pCurrent = pHead->next;
	//建立链接
	pHead->next = pCurrent->next;
	//释放节点
	free(pCurrent);

	//节点数量--
	pHead->data--;
}


/*=======================================================
*	@函数功能：删除指定位置节点
*	@函数参数：LinkNode* , pos
*	@函数返回：成功返回0 ,失败返回-1
*=======================================================*/
int PosDeleteToNode(LinkNode* pHead, int pos)
{
	//判断头节点是否存在
	if (!pHead)
	{
		return -1;
	}
	//判断插入位置
	if (pos < 1 || pos > pHead->data)
	{
		return -1;
	}
	//移动节点后继到pos
	LinkNode* pCurrent = pHead->next;	//当前节点
	LinkNode* pPrevious = pHead;		//当前节点前驱
	for (int i = 1; i < pos; i++)
	{
		pPrevious = pCurrent;
		pCurrent = pCurrent->next;
	}
	//建立链接
	pPrevious->next = pCurrent->next;
	//释放节点
	free(pCurrent);
	//节点数量--
	pHead->data--;
}


/*=======================================================
*	@函数功能：获取指定位置节点值
*	@函数参数：LinkNode* , pos
*	@函数返回：成功返回该值，失败返回-1
*=======================================================*/
int GetNodePosValue(LinkNode* pHead, int pos)
{
	//判断头节点是否存在
	if (!pHead || !pHead->next)
	{
		return -1;
	}
	//判断是否合法
	if (pos < 1 || pos > pHead->data)
	{
		return -1;
	}
	//移动节点后继
	LinkNode* pCurrent = pHead->next;
	for (int i = 1; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	return pCurrent->data;
}


/*=======================================================
*	@函数功能：获取链表长度
*	@函数参数：SqList*
*	@函数返回：成功返回线性表长度，失败返回-1
*=======================================================*/
int GetLinkListLen(LinkNode* pHead)
{
	//判断头节点是否存在
	if (!pHead)
	{
		return -1;
	}

	return pHead->data;
}



/*=======================================================
*	@函数功能：遍历链表
*	@函数参数：LinkNode*
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int PrintLinkList(LinkNode* pHead)
{
	//判断头节点是否存在
	if (!pHead || !pHead->next)
	{
		return -1;
	}
	LinkNode* pCurrent = pHead->next;	//不打印头节点
	for (int i = 0; i < pHead->data; i++)
	{
		printf("data: %-4d addr: %#X\n", pCurrent->data, pCurrent->next);
		pCurrent = pCurrent->next;
	}

	return 0;
}


/*=======================================================
*	@函数功能：清空链表
*	@函数参数：LinkNode*
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int ClearLinkList(LinkNode* pHead)
{
	//判断头节点是否存在
	if (!pHead || !pHead->next)
	{
		return -1;
	}
	//循环释放节点
	LinkNode* pCurrent = pHead->next;
	LinkNode* pPrevios = pHead;

	while (pCurrent->next != NULL)
	{
		pPrevios = pCurrent->next;
		free(pCurrent);
		//节点数量--
		pHead->data--;
		pCurrent = pPrevios;
	}
	//释放第一个或最后一个节点
	free(pCurrent);
	//节点数量--
	pHead->data--;

	//头节点指向NULL
	pHead->next = NULL;

	return 0;
}



/*=======================================================
*	@函数功能：释放链表空间
*	@函数参数：LinkNode**
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int FreeHeadNode(LinkNode** pHead)
{
	if (*pHead != NULL && (*pHead)->next == NULL)
	{
		free(*pHead);
		*pHead = NULL;

		return 0;
	}
	return -1;
}