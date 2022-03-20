#include "DLinkList.h"

int main()
{
	printf("======================¥¥Ω®≤‚ ‘======================\n");
	LinkList* pHead = InitHeadNode();
	printf("pHead: %#X\n", pHead);

	printf("======================Œ≤≤Â≤‚ ‘======================\n");
	for (int i = 0; i < 25; i++)
	{
		InsertNode(pHead, i);
	}
	PrintLinkList(pHead);

	printf("======================Õ∑≤Â≤‚ ‘======================\n");
	InsertNodeToHead(pHead, 3333);
	PrintLinkList(pHead);

	printf("======================Œª≤Â≤‚ ‘======================\n");
	InsertNodeToPos(pHead, 1, 6666);
	InsertNodeToPos(pHead, pHead->data, 9999);
	PrintLinkList(pHead);

	printf("======================Œ≤…æ≤‚ ‘======================\n");
	DeleteNode(pHead);
	DeleteNode(pHead);
	PrintLinkList(pHead);

	printf("======================Õ∑…æ≤‚ ‘======================\n");
	DeleteNodeToHead(pHead);
	DeleteNodeToHead(pHead);
	PrintLinkList(pHead);

	printf("======================Œª…æ≤‚ ‘======================\n");
	DeleteNodeToPos(pHead,1);
	DeleteNodeToPos(pHead, pHead->data);
	DeleteNodeToPos(pHead, 10);
	PrintLinkList(pHead);

	printf("======================≥§∂»≤‚ ‘======================\n");
	printf("Node len is: %d\n", GetLinkListLen(pHead));
	
	printf("======================«Âø’≤‚ ‘======================\n");
	printf("Node len is: %d\n", ClearLinkList(pHead));

	printf("======================œ˙ªŸ≤‚ ‘======================\n");
	printf("pHead: %#X\n", RemoveLinkList(&pHead));

	return 0;
}