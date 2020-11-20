#pragma once
#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

const int MAX_NODE = 256 * 9;

struct NODE
{
	unsigned char c;
	int freq;
	bool used; 
	int nLeft;
	int nRight;
};

void Init();
void countFreqOfLetters(char* FileName);
void FreqTable();
bool FindTwoLettersWithLowestFreq(int &a, int &b, int nNode);
int createHuffTree();