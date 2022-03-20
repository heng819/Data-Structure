#include "DLoopLinkList.h"

int main()
{
	printf("======================创建测试======================\n");
	DLoopLinkList* pHead = InitHeadNode();
	printf("pHead->data: %-4d  pHead->addr: %#8X  pHead->next: %#9X  pHead->prev: %#8X\n", pHead->data,
		pHead, pHead->next, pHead->previous);
	

	printf("======================尾插测试======================\n");
	for (int i = 0; i < 10; i++)
	{
		InsertNode(pHead, i);
	}
	PrintDLoopLinkList(pHead);
	/*printf("pHead->data: %-4d  pHead->addr: %#8X  pHead->next: %#9X  pHead->prev: %#8X\n", pHead->data,
		pHead, pHead->next, pHead->previous);*/

	printf("======================头插测试======================\n");
	InsertNodeToHead(pHead, 3333);
	PrintDLoopLinkList(pHead);
	/*printf("pHead->data: %-4d  pHead->addr: %#8X  pHead->next: %#9X  pHead->prev: %#8X\n", pHead->data,
		pHead, pHead->next, pHead->previous);*/

	printf("======================位插测试======================\n");
	InsertNodeToPos(pHead, 1, 6666);
	InsertNodeToPos(pHead, pHead->data, 9999);
	PrintDLoopLinkList(pHead);
	/*printf("pHead->data: %-4d  pHead->addr: %#8X  pHead->next: %#9X  pHead->prev: %#8X\n", pHead->data,
		pHead, pHead->next, pHead->previous);*/

	printf("======================尾删测试======================\n");
	DeleteNode(pHead);
	DeleteNode(pHead);
	PrintDLoopLinkList(pHead);
	/*printf("pHead->data: %-4d  pHead->addr: %#8X  pHead->next: %#9X  pHead->prev: %#8X\n", pHead->data,
		pHead, pHead->next, pHead->previous);*/

	printf("======================头删测试======================\n");
	DeleteNodeToHead(pHead);
	PrintDLoopLinkList(pHead);
	/*printf("pHead->data: %-4d  pHead->addr: %#8X  pHead->next: %#9X  pHead->prev: %#8X\n", pHead->data,
		pHead, pHead->next, pHead->previous);*/
	
	printf("======================位删测试======================\n");
	DeleteNodeToPos(pHead, 1);
	DeleteNodeToPos(pHead, pHead->data);
	PrintDLoopLinkList(pHead);
	/*printf("pHead->data: %-4d  pHead->addr: %#8X  pHead->next: %#9X  pHead->prev: %#8X\n", pHead->data,
		pHead, pHead->next, pHead->previous);*/
	
	printf("======================长度测试======================\n");
	printf("Node len is: %d\n", GetDLoopLinkListLen(pHead));
	

	printf("======================清空测试======================\n");
	printf("Node len is: %d\n", ClearDLoopLinkList(pHead));
	/*printf("pHead->data: %-4d  pHead->addr: %#8X  pHead->next: %#9X  pHead->prev: %#8X\n", pHead->data,
		pHead, pHead->next, pHead->previous);*/

	printf("======================销毁测试======================\n");
	printf("pHead: %#X\n", RemoveDLoopLinkList(&pHead));


	return 0;
}