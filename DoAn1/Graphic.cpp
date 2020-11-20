#include"Graphic.h"
void InChu(string word, bool invientren, bool invienduoi)
{
	if (invientren)
	{
		cout << "+------------------------------------------------+" << endl;
		cout << "|";
	}
	else
	{
		cout << "|";
	}
	bool khoangtrangtruoc = true;
	for (int i = word.length(); i < 48; i++)
	{
		if (khoangtrangtruoc)
			word = " " + word;
		else
			word = word + " ";
		khoangtrangtruoc = !khoangtrangtruoc;
	}
	cout << word.c_str();
	if (invienduoi)
	{
		cout << "|" << endl;
		cout << "+------------------------------------------------+" << endl;
	}
	else
		cout << "|" << endl;
}

void title()
{
	InChu("_______ _______ _______ _     _", true, false);
	InChu("|  |  | |_____|    |    |_____|", false, false);
	InChu("|  |  | |     |    |    |     |", false, false);
}

void menu1()
{
	InChu("1. Bool ", true, false);
	InChu("2. Vector", false, false);
	InChu("3. Matrix", false, false);
	InChu("4. Exit ", false, true);
}

void menu2()
{
	InChu("1. Tong hai vector          ", true, false);
	InChu("2. Nhan vector voi so Alphal", false, false);
	InChu("3. Quay lai                 ", false, true);
}

void menu3()
{
	InChu("1. Tim dinh thuc ma tran     ", true, false);
	InChu("2. Ma tran nghich dao        ", false, false);
	InChu("3. Tich hai ma tran          ", false, false);
	InChu("4. Hang cua ma tran          ", false, false);
	InChu("5. He phuong trinh tuyen tinh", false, false);
	InChu("6. Quay lai                  ", false, true);
}
