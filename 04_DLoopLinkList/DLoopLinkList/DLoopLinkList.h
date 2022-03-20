#ifndef _DLoopLinkList_H_

#define _DLoopLinkList_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElemType;		//元素类型

//带头节点双向循环链表结构
typedef struct _DLoopLinkList
{
	ElemType data;				//数据
	struct DLoopLinkList* previous;	//前驱节点
	struct DLoopLinkList* next;		//后继节点

}DLoopLinkList, * PDLoopLinkList;


/*=======================================================
*	@函数功能：创建头节点
*	@函数参数：无
*	@函数返回：成功返回PDLoopLinkList头节点，失败返回NULL
*=======================================================*/
PDLoopLinkList InitHeadNode();



/*=======================================================
*	@函数功能：链表尾插入节点
*	@函数参数：DLoopLinkList* , data
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int InsertNode(DLoopLinkList* pHead, ElemType data);



/*=======================================================
*	@函数功能：链表头插入节点
*	@函数参数：DLoopLinkList* , data
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int InsertNodeToHead(DLoopLinkList* pHead, ElemType data);



/*=======================================================
*	@函数功能：链表指定位置插入节点
*	@函数参数：DLoopLinkList* , pos , data
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int InsertNodeToPos(DLoopLinkList* pHead, int pos, ElemType data);



/*=======================================================
*	@函数功能：链表尾删除节点
*	@函数参数：DLoopLinkList*
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int DeleteNode(DLoopLinkList* pHead);



/*=======================================================
*	@函数功能：链表头删除节点
*	@函数参数：DLoopLinkList*
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int DeleteNodeToHead(DLoopLinkList* pHead);



/*=======================================================
*	@函数功能：链表指定位置删除节点
*	@函数参数：DLoopLinkList* , pos
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int DeleteNodeToPos(DLoopLinkList* pHead, int pos);



/*=======================================================
*	@函数功能：获取链表节点长度
*	@函数参数：DLoopLinkList*
*	@函数返回：成功返回链表节点个数，失败返回-1
*=======================================================*/
int GetDLoopLinkListLen(DLoopLinkList* pHead);



/*=======================================================
*	@函数功能：清空链表
*	@函数参数：DLoopLinkList*
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int ClearDLoopLinkList(DLoopLinkList* pHead);



/*=======================================================
*	@函数功能：销毁链表
*	@函数参数：DLoopLinkList**
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int RemoveDLoopLinkList(DLoopLinkList** pHead);



/*=======================================================
*	@函数功能：遍历节点
*	@函数参数：DLoopLinkList*
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int PrintDLoopLinkList(DLoopLinkList* pHead);



#endif
