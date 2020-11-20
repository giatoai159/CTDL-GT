#include<stdio.h>

int Tong(int* a, int n)
{
	if (n == 0)
		return a[0];
	return(Tong(a,n-1)) + a[n];
}

int TichDaySo(int n)
{
	if (n == 1)
		return 1;
	return TichDaySo(n - 1)*n;
}

int TongSoLe(int* a, int n)
{
	if (n == 0)
	{
		if (a[0] % 2 != 0)
			return a[0];
		else return 0;
	}
	if (a[n] % 2 != 0)
		return TongSoLe(a, n - 1) + a[n];
	return TongSoLe(a, n - 1);
}
void main()
{
	int n;
	printf("Nhap n:"); scanf("%d", &n);
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		printf("Nhap a[%d]=", i);
		scanf("%d", &a[i]);
	}
	printf("%d\n", Tong(a, n-1));
	printf("%d\n", TichDaySo(n));
	printf("%d\n", TongSoLe(a, n-1));
}
