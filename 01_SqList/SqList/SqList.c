#include "SqList.h"

/*=======================================================
*	@�������ܣ��������Ա�
*	@������������
*	@�������أ��ɹ�����SqList*��ʧ�ܷ���NULL
*=======================================================*/
SqList* InitSqList()
{
	//�������Ա�ṹ
	SqList* pSqList = (SqList*)malloc(sizeof(SqList));
	if (!pSqList)
	{
		return NULL;
	}
	//�������Ա�
	pSqList->elem = (ElemType*)malloc(sizeof(ElemType) * INIT_SIZE);
	if (!pSqList->elem)
	{
		return NULL;
	}
	//��ʼ�����Ա�
	pSqList->len = 0;
	pSqList->capacity = INIT_SIZE;

	return pSqList;
}



/*=======================================================
*	@�������ܣ����Ա�β����Ԫ��
*	@����������SqList* , data
*	@�������أ��ɹ�����0��ʧ�ܷ���-1
*=======================================================*/
int InsertSqList(SqList* pList, ElemType data)
{
	//�ж����Ա��Ƿ����
	if (!pList || !pList->elem)
	{
		return -1;
	}
	//�ж����Ա��Ƿ�����
	if (pList->len == pList->capacity)
	{
		//������ԭ���Ա�ռ��������Ա�
		ElemType* pNewSqList = (ElemType*)malloc(sizeof(ElemType) * (pList->capacity + INIT_INCREASE));
		if (!pNewSqList)
		{
			return -1;
		}
		//ԭ���Ա����ݿ����������Ա�
		memcpy(pNewSqList, pList->elem, sizeof(ElemType) * pList->capacity);
		//�ͷ�ԭ���Ա�ռ�
		free(pList->elem);
		//ָ���µ����Ա�
		pList->elem = pNewSqList;
		//��������
		pList->capacity += INIT_INCREASE;
	}
	//ĩβ��������
	pList->elem[pList->len] = data;
	//���Ա���++
	pList->len++;

	return 0;
}



/*=======================================================
*	@�������ܣ����Ա�ͷ����Ԫ��
*	@����������SqList* , data
*	@�������أ��ɹ�����0��ʧ�ܷ���-1
*=======================================================*/
int HeadInsertToSqList(SqList* pList, ElemType data)
{
	//�ж����Ա��Ƿ����
	if (!pList || !pList->elem)
	{
		return -1;
	}
	//�ж����Ա��Ƿ�����
	if (pList->len == pList->capacity)
	{
		//������ԭ���Ա�ռ��������Ա�
		ElemType* pNewSqList = (ElemType*)malloc(sizeof(ElemType) * (pList->capacity + INIT_INCREASE));
		if (!pNewSqList)
		{
			return -1;
		}
		//ԭ���Ա����ݿ����������Ա�
		memcpy(pNewSqList, pList->elem, sizeof(ElemType) * pList->capacity);
		//�ͷ�ԭ���Ա�ռ�
		free(pList->elem);
		//ָ���µ����Ա�
		pList->elem = pNewSqList;
		//��������
		pList->capacity += INIT_INCREASE;
	}
	//Ԫ�غ���
	for (int i = pList->len - 1; i >= 0; i--)
	{
		pList->elem[i+1] = pList->elem[i];
	}
	//ͷ����������
	pList->elem[0] = data;
	//���Ա���++
	pList->len++;
}



/*=======================================================
*	@�������ܣ�ָ��λ�ò������Ա�
*	@����������SqList* , pos , data
*	@�������أ��ɹ�����0��λ�ò��Ϸ�����-2��ʧ�ܷ���-1
*=======================================================*/
int PosInsertToSqList(SqList* pList, int pos, ElemType data)
{
	//�ж����Ա��Ƿ����
	if (!pList || !pList->elem)
	{
		return -1;
	}
	//�жϲ���λ���Ƿ�Ϸ�
	if (pos < 1 || pos > pList->len + 1)	//��1��ʼ���룬����pList->len + 1β��
	{
		return -2;
	}
	//�ж����Ա��Ƿ�����
	if (pList->len == pList->capacity)
	{
		//������ԭ���Ա�ռ��������Ա�
		ElemType* pNewSqList = (ElemType*)malloc(sizeof(ElemType) * (pList->capacity + INIT_INCREASE));
		if (!pNewSqList)
		{
			return -1;
		}
		//ԭ���Ա����ݿ����������Ա�
		memcpy(pNewSqList, pList->elem, sizeof(ElemType) * pList->capacity);
		//�ͷ�ԭ���Ա�ռ�
		free(pList->elem);
		//ָ���µ����Ա�
		pList->elem = pNewSqList;
		//��������
		pList->capacity += INIT_INCREASE;
	}
	//Ԫ�غ���
	for (int i = pList->len - 1; i >= pos - 1; i--)
	{
		pList->elem[i+1] = pList->elem[i];
	}
	//λ�ò������ݣ�-1����λ�����±��ϵ
	pList->elem[pos-1] = data;
	//���Ա���++
	pList->len++;

	return 0;
}



/*=======================================================
*	@�������ܣ����Ա�βɾ��Ԫ��
*	@����������SqList*
*	@�������أ��ɹ�����0��ʧ�ܷ���-1
*=======================================================*/
int DeleteSqList(SqList* pList)
{
	//�ж����Ա��Ƿ����
	if (!pList || !pList->elem)
	{
		return -1;
	}
	//�ж����Ա��Ƿ����Ԫ��
	if (pList->len == 0)
	{
		return 0;
	}
	//���Ա���--
	pList->len--;
	
	return 0;
}



/*=======================================================
*	@�������ܣ����Ա�ͷɾ��Ԫ��
*	@����������SqList*
*	@�������أ��ɹ�����0��ʧ�ܷ���-1
*=======================================================*/
int HeadDeleteToSqList(SqList* pList)
{
	//�ж����Ա��Ƿ����
	if (!pList || !pList->elem)
	{
		return -1;
	}
	//�ж����Ա��Ƿ����Ԫ��
	if (pList->len == 0)
	{
		return 0;
	}
	//�ƶ�Ԫ��
	for (int i = 1; i <= pList->len - 1; i++)
	{
		pList->elem[i-1] = pList->elem[i];
	}
	//���Ա���--
	pList->len--;

	return 0;
}



/*=======================================================
*	@�������ܣ�ָ��λ��ɾ�����Ա�
*	@����������SqList* , pos
*	@�������أ��ɹ�����0��λ�ò��Ϸ�����-2��ʧ�ܷ���-1
* ======================================================*/
int PosDeleteToSqList(SqList* pList, int pos)
{
	//�ж����Ա��Ƿ����
	if (!pList || !pList->elem)
	{
		return -1;
	}
	//�ж����Ա��Ƿ����Ԫ��
	if (pList->len == 0)
	{
		return 0;
	}
	//�ж�ɾ��λ���Ƿ�Ϸ�
	if (pos < 1 || pos > pList->len)	
	{
		return -2;
	}
	//�ж�ɾ�����Ƿ���β��
	if (pList->len == pos)
	{
		DeleteSqList(pList);
		return 0;
	}
	//�ж�ɾ�����Ƿ���ͷ��
	if (pos == 1)
	{
		HeadDeleteToSqList(pList);
		return 0;
	}
	//�ƶ�Ԫ��
	for (int i = pos - 1; i <= pList->len - 1; i++)
	{
		pList->elem[i] = pList->elem[i + 1];
	}
	//���Ա���--
	pList->len--;

	return 0;
}



/*=======================================================
*	@�������ܣ���ȡ���Ա�ָ��λ��ֵ
*	@����������@����������SqList* , pos
*	@�������أ��ɹ����ظ�ֵ��λ�ò��Ϸ�����-2��ʧ�ܷ���-1
*=======================================================*/
int GetPosValueSqList(SqList* pList,int pos)
{
	//�ж����Ա��Ƿ����
	if (!pList || !pList->elem)
	{
		return -1;
	}
	//�ж����Ա��Ƿ����Ԫ��
	if (pList->len == 0)
	{
		return -1;
	}
	//�ж�λ���Ƿ�Ϸ�
	if (pos < 1 || pos > pList->len)
	{
		return -2;
	}

	return pList->elem[pos - 1];
}



/*=======================================================
*	@�������ܣ���ȡ���Ա���
*	@����������SqList*
*	@�������أ��ɹ��������Ա��ȣ�ʧ�ܷ���-1
*=======================================================*/
int GetSqListLen(SqList* pList)
{
	//�ж����Ա��Ƿ����
	if (!pList || !pList->elem)
	{
		return -1;
	}
	return pList->len;
}


/*=======================================================
*	@�������ܣ�������Ա�
*	@����������SqList*
*	@�������أ��ɹ�����0��ʧ�ܷ���-1
*=======================================================*/
int ClearSqList(SqList* pList)
{
	//�ж����Ա��Ƿ����
	if (!pList || !pList->elem)
	{
		return -1;
	}
	//�ж����Ա��Ƿ����Ԫ��
	if (pList->len == 0)
	{
		return 0;
	}
	pList->len = 0;

	return 0;
}



/*=======================================================
*	@�������ܣ��������Ա�
*	@����������SqList*
*	@�������أ��ɹ�����0��ʧ�ܷ���-1
*=======================================================*/
int PrintSqList(SqList* pList)
{
	//�ж����Ա��Ƿ����
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
*	@�������ܣ��ͷ����Ա�ռ�
*	@����������SqList**
*	@�������أ��ɹ�����0��ʧ�ܷ���-1
*=======================================================*/
int FreeSqList(SqList** pList)
{
	//�ж����Ա��Ƿ����
	if (!*pList || !(*pList)->elem)
	{
		return -1;
	}
	free((*pList)->elem);
	(*pList)->elem = NULL;

	free(*pList);
	*pList = NULL;
}