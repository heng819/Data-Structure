#include "SqList.h"


int main()
{
	printf("======================��������======================\n");
	SqList* pList = InitSqList();
	printf("pList: %#X\n", pList);

	printf("======================β�����======================\n");
	for (int i = 65; i < 91; i++)
	{
		InsertSqList(pList,i);
	}
	PrintSqList(pList);

	printf("======================ͷ�����======================\n");
	HeadInsertToSqList(pList, '@');
	PrintSqList(pList);
	
	printf("======================λ�����======================\n");
	PosInsertToSqList(pList, 1, '^');
	PosInsertToSqList(pList, 2, '^');
	PosInsertToSqList(pList, 4, '^');
	PosInsertToSqList(pList, pList->len+1, '^');
	PrintSqList(pList);

	printf("======================βɾ����======================\n");
	DeleteSqList(pList);
	PrintSqList(pList);

	printf("======================ͷɾ����======================\n");
	HeadDeleteToSqList(pList);
	HeadDeleteToSqList(pList);
	HeadDeleteToSqList(pList);
	HeadDeleteToSqList(pList);
	PrintSqList(pList);

	printf("======================λɾ����======================\n");
	PosDeleteToSqList(pList, 4);
	PrintSqList(pList);

	printf("======================ȡֵ����======================\n");
	printf("pos value is: %c\n", GetPosValueSqList(pList, 1));
	printf("pos value is: %c\n", GetPosValueSqList(pList, pList->len));

	printf("======================���Ȳ���======================\n");
	printf("len is: %d\n", GetSqListLen(pList));

	printf("======================��ղ���======================\n");
	printf("len is: %d\n", ClearSqList(pList));

	printf("======================���ٲ���======================\n");
	FreeSqList(&pList);
	printf("pList: %#X\n", pList);


	return 0;
}

