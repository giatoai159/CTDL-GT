#include "BST.h"

void Init(NODE *& TREE)
{
	TREE = NULL;
}

void Insert(NODE *& pRoot, int x)
{
	if(pRoot==NULL)
	{
		NODE *q;
		q = new NODE;
		q->data = x;
		q->pLeft = q->pRight = NULL;
		pRoot = q;
	}
	else
	{
		if (pRoot->data < x)
			Insert(pRoot->pRight, x);
		else if(pRoot->data > x)
			Insert(pRoot->pLeft, x);
	}
}

void createTree(NODE *& pRoot)
{
	int Data; 
	do 
	{ 
		cout << "Nhap vao du lieu, -1 de ket thuc: "; 
		cin >> Data;
		if (Data == -1)
			break; 
		Insert(pRoot, Data);
	} while (1);
}

void NLR(NODE * pRoot)
{
	if (pRoot != NULL)
	{
		cout << pRoot->data << " ";
		NLR(pRoot->pLeft);
		NLR(pRoot->pRight);
	}
}

NODE * Search(NODE * pRoot, int x)
{
	if (pRoot == NULL)
		return NULL;
	if(pRoot->data>x)
		Search(pRoot->pLeft, x);
	else
	{
		if (pRoot->data < x)
			Search(pRoot->pRight, x);
		else return pRoot;
	}
}

int Height(NODE*pRoot)
{
	if (pRoot == NULL)
		return 0;
	int HL, HR;
	HL = Height(pRoot->pLeft);
	HR = Height(pRoot->pRight);
	if (HL > HR)
		return (1 + HL);
	else return (1 + HR);
}

void SearchStandFor(NODE *& TREE, NODE *& q)
{
	if (TREE->pRight)
		SearchStandFor(TREE->pRight, q);
	else
	{
		q->data = TREE->data;
		q = TREE;
		TREE = TREE->pLeft;
	}
}

void removeNode(NODE *& TREE, int x)
{
	NODE*p;
	if (TREE = NULL)
		cout << x << " khong co trong cay.";
	else
	{
		if (TREE->data > x)
			removeNode(TREE->pLeft, x);
		else
		{
			if (TREE->data < x)
				removeNode(TREE->pRight, x);
			else
			{
				p = TREE;
				if (p->pRight == NULL)
					TREE = p->pLeft;
				else
				{
					if (p->pLeft == NULL)
						TREE = p->pRight;
					else SearchStandFor(TREE->pLeft, p);
				}
				delete p;
			}
		}
	}
}

int sumTree(NODE *pRoot)
{
	if (pRoot == NULL)
		return 0;
	return (pRoot->data + sumTree(pRoot->pLeft) + sumTree(pRoot->pRight));
}

int largestNode(NODE *pRoot)
{
	if (pRoot->pRight == NULL)
		return pRoot->data;
	return largestNode(pRoot->pRight);
}

int smallestNode(NODE *pRoot)
{
	if (pRoot->pLeft == NULL)
		return pRoot->data;
	return smallestNode(pRoot->pLeft);
}

int countNode(NODE *pRoot)
{
	if (pRoot == NULL)
		return 0;
	return(1 + countNode(pRoot->pLeft) + countNode(pRoot->pRight));
}