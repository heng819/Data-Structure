#include "LinkList.h"



/*=======================================================
*	@�������ܣ�����ͷ�ڵ�
*	@������������
*	@�������أ��ɹ�����PLinkListͷ�ڵ㣬ʧ�ܷ���NULL
*=======================================================*/
PLinkNode InitHeadNode()
{
	//����ͷ�ڵ�
	LinkNode* pHead = (LinkNode*)malloc(sizeof(LinkNode));
	if (!pHead)
	{
		return NULL;
	}
	//��ʼ��ͷ�ڵ�
	pHead->data = 0;		//ͷ�ڵ�����������¼�ڵ����,����¼ͷ�ڵ�
	pHead->next = NULL;

	return pHead;
}



/*=======================================================
*	@�������ܣ�����β����ڵ�
*	@����������LinkNode* , data
*	@�������أ��ɹ�����0��ʧ�ܷ���-1
*=======================================================*/
int InsertLinkNode(LinkNode* pHead, ElemType data)
{
	//�ж�ͷ�ڵ��Ƿ����
	if (!pHead)
	{
		return -1;
	}
	//�����½ڵ�
	LinkNode* pNewNode = (LinkNode*)malloc(sizeof(LinkNode));
	if (!pNewNode)
	{
		return -1;
	}
	//��ʼ���½ڵ�
	pNewNode->data = data;
	pNewNode->next = NULL;
	//�ƶ��ڵ��̵�β��
	LinkNode* pCurrent = pHead;
	while (pCurrent->next != NULL)
	{
		pCurrent = pCurrent->next;
	}
	//��������
	pCurrent->next = pNewNode;
	//�ڵ�����++
	pHead->data++;

	return 0;
}



/*=======================================================
*	@�������ܣ�����ͷ����ڵ�
*	@����������LinkNode* , data
*	@�������أ��ɹ�����0��ʧ�ܷ���-1
*=======================================================*/
int InsertNodeToHead(LinkNode* pHead, ElemType data)
{
	//�ж�ͷ�ڵ��Ƿ����
	if (!pHead)
	{
		return -1;
	}
	//�����½ڵ�
	LinkNode* pNewNode = (LinkNode*)malloc(sizeof(LinkNode));
	if (!pNewNode)
	{
		return -1;
	}
	//��ʼ���½ڵ�
	pNewNode->data = data;
	pNewNode->next = NULL;

	//��������
	LinkNode* pCurrent = pHead;
	//1���½ڵ���ָ��ͷ�ڵ���
	pNewNode->next = pCurrent->next;
	//2��ͷ�ڵ���ָ���½ڵ�
	pHead->next = pNewNode;

	//�ڵ�����++
	pHead->data++;

	return 0;
}



/*=======================================================
*	@�������ܣ�����ָ��λ�ò���ڵ�
*	@����������LinkNode* , pos , data
*	@�������أ��ɹ�����0��ʧ�ܷ���-1
*=======================================================*/
int PosInsertToNode(LinkNode* pHead, int pos, ElemType data)
{
	//�ж�ͷ�ڵ��Ƿ����
	if (!pHead)
	{
		return -1;
	}
	//�жϲ���λ��
	if (pos < 1 || pos > pHead->data)
	{
		return -1;
	}
	//�����½ڵ�
	LinkNode* pNewNode = (LinkNode*)malloc(sizeof(LinkNode));
	if (!pNewNode)
	{
		return -1;
	}
	//��ʼ���½ڵ�
	pNewNode->data = data;
	pNewNode->next = NULL;

	//�ƶ��ڵ��̵�pos
	LinkNode* pCurrent = pHead->next;	//��ǰ�ڵ�
	LinkNode* pPrevious = pHead;		//��ǰ�ڵ�ǰ��
	for (int i = 1; i < pos; i++)
	{
		pPrevious = pCurrent;
		pCurrent = pCurrent->next;
	}
	pNewNode->next = pCurrent;
	pPrevious->next = pNewNode;

	//�ڵ�����++
	pHead->data++;
}



/*=======================================================
*	@�������ܣ�����βɾ���ڵ�
*	@����������LinkNode*
*	@�������أ��ɹ�����0��ʧ�ܷ���-1
*=======================================================*/
int DeleteNode(LinkNode* pHead)
{
	//�ж�ͷ�ڵ��Ƿ����
	if (!pHead || !pHead->next)
	{
		return -1;
	}
	//�ƶ��ڵ��̵�β��
	LinkNode* pCurrent = pHead->next;
	LinkNode* pPrevious = pHead;		//��ǰ�ڵ�ǰ��
	while (pCurrent->next != NULL)
	{
		pPrevious = pCurrent;
		pCurrent = pCurrent->next;
	}
	//�ͷŽڵ�
	free(pCurrent);
	//β�ڵ���ָ��NULL
	pPrevious->next = NULL;
	//�ڵ�����--
	pHead->data--;

	return 0;
}



/*=======================================================
*	@�������ܣ����Ա�ͷɾ��Ԫ��
*	@����������LinkNode*
*	@�������أ��ɹ�����0��ʧ�ܷ���-1
*=======================================================*/
int HeadDeleteToNode(LinkNode* pHead)
{
	//�ж�ͷ�ڵ��Ƿ����
	if (!pHead || !pHead->next)
	{
		return -1;
	}
	//��ǰ�ڵ�
	LinkNode* pCurrent = pHead->next;
	//��������
	pHead->next = pCurrent->next;
	//�ͷŽڵ�
	free(pCurrent);

	//�ڵ�����--
	pHead->data--;
}


/*=======================================================
*	@�������ܣ�ɾ��ָ��λ�ýڵ�
*	@����������LinkNode* , pos
*	@�������أ��ɹ�����0 ,ʧ�ܷ���-1
*=======================================================*/
int PosDeleteToNode(LinkNode* pHead, int pos)
{
	//�ж�ͷ�ڵ��Ƿ����
	if (!pHead)
	{
		return -1;
	}
	//�жϲ���λ��
	if (pos < 1 || pos > pHead->data)
	{
		return -1;
	}
	//�ƶ��ڵ��̵�pos
	LinkNode* pCurrent = pHead->next;	//��ǰ�ڵ�
	LinkNode* pPrevious = pHead;		//��ǰ�ڵ�ǰ��
	for (int i = 1; i < pos; i++)
	{
		pPrevious = pCurrent;
		pCurrent = pCurrent->next;
	}
	//��������
	pPrevious->next = pCurrent->next;
	//�ͷŽڵ�
	free(pCurrent);
	//�ڵ�����--
	pHead->data--;
}


/*=======================================================
*	@�������ܣ���ȡָ��λ�ýڵ�ֵ
*	@����������LinkNode* , pos
*	@�������أ��ɹ����ظ�ֵ��ʧ�ܷ���-1
*=======================================================*/
int GetNodePosValue(LinkNode* pHead, int pos)
{
	//�ж�ͷ�ڵ��Ƿ����
	if (!pHead || !pHead->next)
	{
		return -1;
	}
	//�ж��Ƿ�Ϸ�
	if (pos < 1 || pos > pHead->data)
	{
		return -1;
	}
	//�ƶ��ڵ���
	LinkNode* pCurrent = pHead->next;
	for (int i = 1; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	return pCurrent->data;
}


/*=======================================================
*	@�������ܣ���ȡ������
*	@����������SqList*
*	@�������أ��ɹ��������Ա��ȣ�ʧ�ܷ���-1
*=======================================================*/
int GetLinkListLen(LinkNode* pHead)
{
	//�ж�ͷ�ڵ��Ƿ����
	if (!pHead)
	{
		return -1;
	}

	return pHead->data;
}



/*=======================================================
*	@�������ܣ���������
*	@����������LinkNode*
*	@�������أ��ɹ�����0��ʧ�ܷ���-1
*=======================================================*/
int PrintLinkList(LinkNode* pHead)
{
	//�ж�ͷ�ڵ��Ƿ����
	if (!pHead || !pHead->next)
	{
		return -1;
	}
	LinkNode* pCurrent = pHead->next;	//����ӡͷ�ڵ�
	for (int i = 0; i < pHead->data; i++)
	{
		printf("data: %-4d addr: %#X\n", pCurrent->data, pCurrent->next);
		pCurrent = pCurrent->next;
	}

	return 0;
}


/*=======================================================
*	@�������ܣ��������
*	@����������LinkNode*
*	@�������أ��ɹ�����0��ʧ�ܷ���-1
*=======================================================*/
int ClearLinkList(LinkNode* pHead)
{
	//�ж�ͷ�ڵ��Ƿ����
	if (!pHead || !pHead->next)
	{
		return -1;
	}
	//ѭ���ͷŽڵ�
	LinkNode* pCurrent = pHead->next;
	LinkNode* pPrevios = pHead;

	while (pCurrent->next != NULL)
	{
		pPrevios = pCurrent->next;
		free(pCurrent);
		//�ڵ�����--
		pHead->data--;
		pCurrent = pPrevios;
	}
	//�ͷŵ�һ�������һ���ڵ�
	free(pCurrent);
	//�ڵ�����--
	pHead->data--;

	//ͷ�ڵ�ָ��NULL
	pHead->next = NULL;

	return 0;
}



/*=======================================================
*	@�������ܣ��ͷ�����ռ�
*	@����������LinkNode**
*	@�������أ��ɹ�����0��ʧ�ܷ���-1
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