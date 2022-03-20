#include "DLinkList.h"

int main()
{
	printf("======================��������======================\n");
	LinkList* pHead = InitHeadNode();
	printf("pHead: %#X\n", pHead);

	printf("======================β�����======================\n");
	for (int i = 0; i < 25; i++)
	{
		InsertNode(pHead, i);
	}
	PrintLinkList(pHead);

	printf("======================ͷ�����======================\n");
	InsertNodeToHead(pHead, 3333);
	PrintLinkList(pHead);

	printf("======================λ�����======================\n");
	InsertNodeToPos(pHead, 1, 6666);
	InsertNodeToPos(pHead, pHead->data, 9999);
	PrintLinkList(pHead);

	printf("======================βɾ����======================\n");
	DeleteNode(pHead);
	DeleteNode(pHead);
	PrintLinkList(pHead);

	printf("======================ͷɾ����======================\n");
	DeleteNodeToHead(pHead);
	DeleteNodeToHead(pHead);
	PrintLinkList(pHead);

	printf("======================λɾ����======================\n");
	DeleteNodeToPos(pHead,1);
	DeleteNodeToPos(pHead, pHead->data);
	DeleteNodeToPos(pHead, 10);
	PrintLinkList(pHead);

	printf("======================���Ȳ���======================\n");
	printf("Node len is: %d\n", GetLinkListLen(pHead));
	
	printf("======================��ղ���======================\n");
	printf("Node len is: %d\n", ClearLinkList(pHead));

	printf("======================���ٲ���======================\n");
	printf("pHead: %#X\n", RemoveLinkList(&pHead));

	return 0;
}