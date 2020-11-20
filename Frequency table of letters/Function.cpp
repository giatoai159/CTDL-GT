#include"Function.h"
NODE huffTree[MAX_NODE];
void Init() {
	for (int i = 0; i < MAX_NODE; i++) {
		huffTree[i].c = i;
		huffTree[i].freq = 0;
		huffTree[i].used = false;
		huffTree[i].nLeft = -1;
		huffTree[i].nRight = -1;
	}
}

void countFreqOfLetters(char* FileName)
{
	unsigned char c;
	ifstream fi(FileName);
	if (fi.is_open())
		while (!fi.eof())
		{
			fi >> c;
			huffTree[c].freq++;
		}
	fi.close();
}

void FreqTable()
{
	cout << "Frequency Table of Letters: " << endl;
	for (int i = 0; i < 256; i++)
		if (huffTree[i].freq > 0)
			cout << unsigned char(i) << ": " << huffTree[i].freq << endl;
}

bool FindTwoLettersWithLowestFreq(int &a, int &b, int nNode)
{
	a = -1; // Phan tu co freq nho nhat
	b = -1; // Phan tu co freq nho thu 2
	for (int i = 0; i < nNode; i++)
	{
		if (huffTree[i].used == false && huffTree[i].freq > 0) // Chi xet cac phan tu co ton tai trong file txt
		{
			if (a == -1)
				a = i;
			else if (b == -1)
				b = i;
			else
				if (huffTree[a].freq > huffTree[b].freq)
				{
					if (huffTree[i].freq < huffTree[a].freq)
						a = i;
				}
				else
				{
					if (huffTree[i].freq < huffTree[b].freq)
						b = i;
				}
		}
	}
	if (a != -1 && b != -1)
	{
		if ((huffTree[a].freq > huffTree[b].freq) || ((huffTree[a].freq > huffTree[b].freq) && (huffTree[a].c > huffTree[b].c)))
		{
			int temp = a;
			a = b;
			b = temp;
		}
		return true;
	}
	else return false;
}

int createHuffTree()
{
	int nNode = 256;
	int a, b;
	bool found;
	while (true)
	{
		found = FindTwoLettersWithLowestFreq(a, b, nNode);
		if (!found)
			break;
		if (huffTree[a].c < huffTree[b].c)
			huffTree[nNode].c = huffTree[a].c;
		else
			huffTree[nNode].c = huffTree[b].c;
		huffTree[nNode].freq = huffTree[a].freq + huffTree[b].freq;
		huffTree[nNode].nLeft = a;
		huffTree[nNode].nRight = b;
		huffTree[a].used = true;
		huffTree[b].used = true;
		huffTree[nNode].used = false;
		nNode++;
	}
	return nNode - 1;
}
