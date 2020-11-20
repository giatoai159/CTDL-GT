#include"BST.h"

void main()
{
	NODE *pTree;
	Init(pTree);
	createTree(pTree);
	NLR(pTree);
	cout << endl;
	cout << "Tong la: " << sumTree(pTree) << endl;
	cout << "So lon nhat trong cay la: " << largestNode(pTree) << endl;
	cout << "So nho nhat trong cay la: " << smallestNode(pTree) << endl;
	cout << "Tong so node cua cay la: " << countNode(pTree) << endl;
}