#include"Bool.h"
void NhapDaThuc(int a[][MAX], int &n)
{
	cout << "Nhap vao so luong bien: ";
	cin >> n;
	cout << "Nhap gia tri tung bien trong da thuc: " << endl; //Chi nhan hai gia tri 0 va 1
	for (int i = 0; i < pow(2, n); i++)
	for (int j = 0; j < n; j++)
		cin >> a[i][j];
}
void XuatDaThuc(int a[][MAX], int n)
{
	cout << "Da thuc la: ";
	for (int i = 0; i < pow(2, n); i++)
	{
		cout << endl;
		for (int j = 0; j < n; j++)
		if (a[i][j] == 2) cout << " ";
		else cout << a[i][j] << " ";
	}
	cout << endl;
}
void RutGon(int a[][MAX], int n)
{
	for (int i = 0; i < pow(2, n) - 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] != a[i + 1][j])
			{
				a[i][j] = 2;
				a[i + 1][j] = 2;
				for (int k = i + 1; k < pow(2, n) - 1; k++)
				for (int h = 0; h < n; h++)
					a[k][j] = a[k + 1][j];
				n--;
				i = 0;
			}
		}
	}
}