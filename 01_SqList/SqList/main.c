#include "SqList.h"


int main()
{
	printf("======================¥¥Ω®≤‚ ‘======================\n");
	SqList* pList = InitSqList();
	printf("pList: %#X\n", pList);

	printf("======================Œ≤≤Â≤‚ ‘======================\n");
	for (int i = 65; i < 91; i++)
	{
		InsertSqList(pList,i);
	}
	PrintSqList(pList);

	printf("======================Õ∑≤Â≤‚ ‘======================\n");
	HeadInsertToSqList(pList, '@');
	PrintSqList(pList);
	
	printf("======================Œª≤Â≤‚ ‘======================\n");
	PosInsertToSqList(pList, 1, '^');
	PosInsertToSqList(pList, 2, '^');
	PosInsertToSqList(pList, 4, '^');
	PosInsertToSqList(pList, pList->len+1, '^');
	PrintSqList(pList);

	printf("======================Œ≤…æ≤‚ ‘======================\n");
	DeleteSqList(pList);
	PrintSqList(pList);

	printf("======================Õ∑…æ≤‚ ‘======================\n");
	HeadDeleteToSqList(pList);
	HeadDeleteToSqList(pList);
	HeadDeleteToSqList(pList);
	HeadDeleteToSqList(pList);
	PrintSqList(pList);

	printf("======================Œª…æ≤‚ ‘======================\n");
	PosDeleteToSqList(pList, 4);
	PrintSqList(pList);

	printf("======================»°÷µ≤‚ ‘======================\n");
	printf("pos value is: %c\n", GetPosValueSqList(pList, 1));
	printf("pos value is: %c\n", GetPosValueSqList(pList, pList->len));

	printf("======================≥§∂»≤‚ ‘======================\n");
	printf("len is: %d\n", GetSqListLen(pList));

	printf("======================«Âø’≤‚ ‘======================\n");
	printf("len is: %d\n", ClearSqList(pList));

	printf("======================œ˙ªŸ≤‚ ‘======================\n");
	FreeSqList(&pList);
	printf("pList: %#X\n", pList);


	return 0;
}

