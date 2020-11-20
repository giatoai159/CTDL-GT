#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<iostream>

using namespace std;

struct NODE
{
	int data;
	NODE *pLeft;
	NODE *pRight;
};

void Init(NODE *& TREE);
void Insert(NODE *& pRoot, int x);
void createTree(NODE *&pRoot);
void NLR(NODE *pRoot);
NODE* Search(NODE* pRoot, int x);
int Height(NODE*pRoot);
void SearchStandFor(NODE*&TREE, NODE* &q);
void removeNode(NODE *& pRoot, int x);
int sumTree(NODE *pRoot);
int largestNode(NODE *pRoot);
int smallestNode(NODE *pRoot);
int countNode(NODE *pRoot);
