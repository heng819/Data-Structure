#include "LinkList.h"
#include <stdio.h>

int main()
{
	printf("======================创建测试======================\n");
	LinkNode* pHead = InitHeadNode();
	printf("pList: %#X\n", pHead);

	printf("======================尾插测试======================\n");
	for (int i = 0; i < 25; i++)
	{
		InsertLinkNode(pHead, i);
	}
	PrintLinkList(pHead);

	printf("======================头插测试======================\n");
	InsertNodeToHead(pHead, 3333);
	PrintLinkList(pHead);
	
	printf("======================位插测试======================\n");
	PosInsertToNode(pHead, 5, 9999);
	PrintLinkList(pHead);

	printf("======================尾删测试======================\n");
	DeleteNode(pHead);
	PrintLinkList(pHead);
	
	printf("======================头删测试======================\n");
	HeadDeleteToNode(pHead);
	HeadDeleteToNode(pHead);
	PrintLinkList(pHead);
	
	printf("======================位删测试======================\n");
	PosDeleteToNode(pHead, 3);
	PrintLinkList(pHead);

	printf("======================取值测试======================\n");
	printf("pos value is: %d\n", GetNodePosValue(pHead, 1));
	printf("pos value is: %d\n", GetNodePosValue(pHead, pHead->data));
	
	printf("======================长度测试======================\n");
	printf("len is: %d\n", GetLinkListLen(pHead));
	
	printf("======================清空测试======================\n");
	ClearLinkList(pHead);
	printf("len is: %d\n",pHead->data);
	
	printf("======================销毁测试======================\n");
	FreeHeadNode(&pHead);
	printf("pHead: %#X\n", pHead);


    return 0;
}

