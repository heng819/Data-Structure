#include "DLoopLinkList.h"



/*=======================================================
*	@�������ܣ�����ͷ�ڵ�
*	@������������
*	@�������أ��ɹ�����PDLoopLinkListͷ�ڵ㣬ʧ�ܷ���NULL
*=======================================================*/
PDLoopLinkList InitHeadNode()
{
	//����ͷ�ڵ�
	DLoopLinkList* pHead = (DLoopLinkList*)malloc(sizeof(DLoopLinkList));
	if (!pHead)
	{
		return NULL;
	}
	//��ʼ��ͷ�ڵ�
	pHead->data = 0;	//ͷ�ڵ�����������¼�ڵ����
	//ѭ��������ʼͷβ����
	pHead->previous = pHead;
	pHead->next = pHead;

	return pHead;
}



/*=======================================================
*	@�������ܣ�����β����ڵ�
*	@����������DLoopLinkList*
*	@�������أ��ɹ�����0��ʧ�ܷ���-1
*=======================================================*/
int InsertNode(DLoopLinkList* pHead, ElemType data)
{
	//�ж�ͷ�ڵ��Ƿ����
	if (!pHead)
	{
		return -1;
	}
	//�����½ڵ�
	DLoopLinkList* pNewNode = (DLoopLinkList*)malloc(sizeof(DLoopLinkList));
	if (!pNewNode)
	{
		return -1;
	}
	//��ʼ���½ڵ�
	pNewNode->data = data;
	pNewNode->previous = NULL;
	pNewNode->next = NULL;
	//ͷβ����
	DLoopLinkList* pTail = pHead->previous;	//ͷ�ڵ��ǰ������β�ڵ�
	pTail->next = pNewNode;
	pNewNode->previous = pTail;
	pNewNode->next = pHead;
	pHead->previous = pNewNode;
	//�ڵ�����++
	pHead->data++;

	return 0;
}



/*=======================================================
*	@�������ܣ�����ͷ����ڵ�
*	@����������DLoopLinkList* , data
*	@�������أ��ɹ�����0��ʧ�ܷ���-1
*=======================================================*/
int InsertNodeToHead(DLoopLinkList* pHead, ElemType data)
{
	//�ж�ͷ�ڵ��Ƿ����
	if (!pHead)
	{
		return -1;
	}
	//�����½ڵ�
	DLoopLinkList* pNewNode = (DLoopLinkList*)malloc(sizeof(DLoopLinkList));
	if (!pNewNode)
	{
		return -1;
	}
	//��ʼ���½ڵ�
	pNewNode->data = data;
	pNewNode->previous = NULL;
	pNewNode->next = NULL;
	//��������
	DLoopLinkList* pFirst = pHead->next;
	pHead->next = pNewNode;
	pNewNode->previous = pHead;
	pNewNode->next = pFirst;
	pFirst->previous = pNewNode;
	//�ڵ�����++
	pHead->data++;

	return 0;
}



/*=======================================================
*	@�������ܣ�����ָ��λ�ò���ڵ�
*	@����������DLoopLinkList* , pos , data
*	@�������أ��ɹ�����0��ʧ�ܷ���-1
*=======================================================*/
int InsertNodeToPos(DLoopLinkList* pHead, int pos, ElemType data)
{
	//�ж�ͷ�ڵ��Ƿ����
	if (!pHead)
	{
		return -1;
	}
	//�ж�λ���Ƿ�Ϸ�
	if (pos < 1 || pos > pHead->data)
	{
		return -1;
	}
	//�жϲ���λ���Ƿ����ͷ
	if (pos == 1)
	{
		InsertNodeToHead(pHead,data);
		return 0;
	}
	//�жϲ���λ���Ƿ����β
	if (pos == 1)
	{
		InsertNode(pHead,data);
		return 0;
	}
	//�����½ڵ�
	DLoopLinkList* pNewNode = (DLoopLinkList*)malloc(sizeof(DLoopLinkList));
	if (!pNewNode)
	{
		return -1;
	}
	//��ʼ���½ڵ�
	pNewNode->data = data;
	pNewNode->previous = NULL;
	pNewNode->next = NULL;
	//ѭ���ƶ���̵�pos
	DLoopLinkList* pCurrent = pHead->next;
	for (int i = 1; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	//������ϵ
	DLoopLinkList* pCurPrevious = pCurrent->previous;
	pNewNode->next = pCurrent;
	pNewNode->previous = pCurrent->previous;
	pCurrent->previous = pNewNode;
	pCurPrevious->next = pNewNode;
	//�ڵ�����++
	pHead->data++;

	return 0;
}



/*=======================================================
*	@�������ܣ�����βɾ���ڵ�
*	@����������DLoopLinkList*
*	@�������أ��ɹ�����0��ʧ�ܷ���-1
*=======================================================*/
int DeleteNode(DLoopLinkList* pHead)
{
	//�ж�ͷ�ڵ��Ƿ����
	if (!pHead)
	{
		return -1;
	}
	//�ж��Ƿ���ͷ�ڵ�
	DLoopLinkList* pCurrent = pHead->previous;
	if (pCurrent != pHead)
	{
		//����β�ڵ��ǰ���ڵ�
		DLoopLinkList* pLast = pCurrent->previous;
		//ͷβ����
		pLast->next = pHead;
		pHead->previous = pLast;
		//�ͷ�β�ڵ�
		free(pCurrent);
		//�ڵ�����--
		pHead->data--;

		return 0;
	}
	

	return -1;
}



/*=======================================================
*	@�������ܣ�����ͷɾ���ڵ�
*	@����������DLoopLinkList*
*	@�������أ��ɹ�����0��ʧ�ܷ���-1
*=======================================================*/
int DeleteNodeToHead(DLoopLinkList* pHead)
{
	//�ж�ͷ�ڵ��Ƿ����
	if (!pHead)
	{
		return -1;
	}
	//�ж��Ƿ���ͷ�ڵ�
	DLoopLinkList* pCurrent = pHead->next;
	if (pCurrent != pHead)
	{
		//�����һ���ڵ�ĺ�̽ڵ�
		DLoopLinkList* pFirst = pCurrent->next;
		//��������
		pHead->next =  pFirst;
		pFirst->previous = pHead;
		//�ͷ�β�ڵ�
		free(pCurrent);
		//�ڵ�����--
		pHead->data--;

		return 0;
	}
}



/*=======================================================
*	@�������ܣ�����ָ��λ��ɾ���ڵ�
*	@����������DLoopLinkList* , pos
*	@�������أ��ɹ�����0��ʧ�ܷ���-1
*=======================================================*/
int DeleteNodeToPos(DLoopLinkList* pHead, int pos)
{
	//�ж�ͷ�ڵ��Ƿ����
	if (!pHead)
	{
		return -1;
	}
	//�ж�λ���Ƿ����ͷ
	if (pos == 1)
	{
		DeleteNodeToHead(pHead);
		return 0;
	}
	//�ж�λ���Ƿ����β
	if (pos == pHead->data)
	{
		DeleteNode(pHead);
		return 0;
	}
	//�ƶ��ڵ�
	DLoopLinkList* pCurrent = pHead->next;
	for (int i = 1; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	//��������
	DLoopLinkList* pCurPrevious = pCurrent->previous;
	DLoopLinkList* pCurNext = pCurrent->next;
	pCurPrevious->next = pCurrent->next;
	pCurNext->previous = pCurPrevious;
	//�ͷŽڵ�
	free(pCurrent);
	//�ڵ�����--
	pHead->data--;

	return 0;
}


/*=======================================================
*	@�������ܣ���ȡ����ڵ㳤��
*	@����������DLoopLinkList*
*	@�������أ��ɹ���������ڵ������ʧ�ܷ���-1
*=======================================================*/
int GetDLoopLinkListLen(DLoopLinkList* pHead)
{
	//�ж�ͷ�ڵ��Ƿ����
	if (!pHead)
	{
		return -1;
	}

	return pHead->data;
}



/*=======================================================
*	@�������ܣ��������
*	@����������DLoopLinkList*
*	@�������أ��ɹ�����0��ʧ�ܷ���-1
*=======================================================*/
int ClearDLoopLinkList(DLoopLinkList* pHead)
{
	//�ж�ͷ�ڵ��Ƿ����
	if (!pHead)
	{
		return -1;
	}
	//�ж������Ƿ�Ϊ��
	while (pHead == pHead->next)
	{
		return 0;
	}
	//��ͷ�ڵ㣬ѭ���ͷ����нڵ�
	DLoopLinkList* pCurrent = pHead->next;
	DLoopLinkList* pCurPrevious = pHead;
	while (pCurrent != pHead)
	{
		pCurPrevious = pCurrent->next;
		free(pCurrent);
		pHead->data--;
		pCurrent = pCurPrevious;
	}
	//ͷ�ڵ�ָ��ǰ����̶�ָ���Լ�
	pHead->previous = pHead;
	pHead->next = pHead;

	return 0;
}



/*=======================================================
*	@�������ܣ���������
*	@����������DLoopLinkList**
*	@�������أ��ɹ�����0��ʧ�ܷ���-1
*=======================================================*/
int RemoveDLoopLinkList(DLoopLinkList** pHead)
{
	//�ж�ͷ�ڵ��Ƿ����
	if ((*pHead)->previous == *pHead  && (*pHead)->next == *pHead)
	{
		free(*pHead);
		*pHead = NULL;
		return 0;
	}
	return -1;
}



/*=======================================================
*	@�������ܣ������ڵ�
*	@����������DLoopLinkList*
*	@�������أ��ɹ�����0��ʧ�ܷ���-1
*=======================================================*/
int PrintDLoopLinkList(DLoopLinkList* pHead)
{
	//�ж�ͷ�ڵ��Ƿ����
	if (!pHead)
	{
		return -1;
	}
	//ѭ����ӡ�ڵ�
	DLoopLinkList* pCurrent = pHead->next;  //����ӡͷ�ڵ�
	while (pCurrent != pHead)
	{
		printf("CurNode->data: %-4d  CurNode->addr: %#8X  CurNode->next: %#9X  CurNode->prev: %#8X\n", pCurrent->data,
			pCurrent, pCurrent->next, pCurrent->previous);
		pCurrent = pCurrent->next;
	}

	return 0;
}