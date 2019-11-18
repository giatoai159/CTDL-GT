#include"FuncVecto.h"
void NhapVecto(float a[MAX], int n)
{
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
void XuatVecto(float a[MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i == 0) cout << "a(" << a[i];
		else if (i == n - 1) cout << a[i] << ")";
		else cout << a[i] << ",";
	}
}
void TongVecto(float a[], float b[], int n)
{
	for (int i = 0; i < n; i++)
		a[i] += b[i];
}
void NhanAlphal(float a[], int n, float Alphal)
{
	for (int i = 0; i < n; i++)
		a[i] *= Alphal;
}