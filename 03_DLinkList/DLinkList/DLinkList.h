#ifndef _DLINKLIST_H_

#define _DLINKLIST_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElemType;		//元素类型

//带头节点双向链表结构
typedef struct _LinkList
{
	ElemType data;				//数据
	struct LinkList* previous;	//前驱节点
	struct LinkList* next;		//后继节点
	
}LinkList, *PLinkList;


/*=======================================================
*	@函数功能：创建头节点
*	@函数参数：无
*	@函数返回：成功返回PLinkList头节点，失败返回NULL
*=======================================================*/
PLinkList InitHeadNode();



/*=======================================================
*	@函数功能：链表尾插入节点
*	@函数参数：LinkList* , data
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int InsertNode(LinkList* pHead,ElemType data);



/*=======================================================
*	@函数功能：链表头插入节点
*	@函数参数：LinkList* , data
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int InsertNodeToHead(LinkList* pHead, ElemType data);



/*=======================================================
*	@函数功能：链表指定位置插入节点
*	@函数参数：LinkList* , pos , data
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int InsertNodeToPos(LinkList* pHead,int pos, ElemType data);



/*=======================================================
*	@函数功能：链表尾删除节点
*	@函数参数：LinkList*
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int DeleteNode(LinkList* pHead);



/*=======================================================
*	@函数功能：链表头删除节点
*	@函数参数：LinkList*
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int DeleteNodeToHead(LinkList* pHead);



/*=======================================================
*	@函数功能：链表指定位置删除节点
*	@函数参数：LinkList* , pos
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int DeleteNodeToPos(LinkList* pHead,int pos);



/*=======================================================
*	@函数功能：获取链表节点长度
*	@函数参数：LinkList* 
*	@函数返回：成功返回链表节点个数，失败返回-1
*=======================================================*/
int GetLinkListLen(LinkList* pHead);



/*=======================================================
*	@函数功能：清空链表
*	@函数参数：LinkList*
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int ClearLinkList(LinkList* pHead);



/*=======================================================
*	@函数功能：销毁链表
*	@函数参数：LinkList**
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int RemoveLinkList(LinkList** pHead);



/*=======================================================
*	@函数功能：遍历节点
*	@函数参数：LinkList*
*	@函数返回：成功返回0，失败返回-1
*=======================================================*/
int PrintLinkList(LinkList* pHead);



#endif
