#include<stdio.h>

void main()
{
	
	int n;
	printf("Nhap so luong phan tu: ");
	scanf("%d", &n);

	int *a = new int[n];

	for (int i = 0; i < n; i++)
	{
		printf("Nhap a[%d]: ", i);
		scanf("%d", &a[i]);
	}

	printf("a[0]=%d\n", a[0]);
	printf("*a=%d\n", *a);

	for (int i = 0; i < n; i++)
	{
		printf("a[%d]=%d\n", i, a[i]);
	}

	int s=0;
	for (int i = 0; i < n; i++)
		s += a[i];
	printf("Tong cac phan tu: %d\n", s);
	
	
	int m;
	printf("Nhap so dong: "); scanf("%d", &m);
	printf("Nhap so cot: "); scanf("%d", &n);
	int** b = new int* [m];
	for (int i = 0; i < m; i++)
		b[i] = new int[n];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("Nhap b[%d][%d]= ", i, j); scanf("%d", &b[i][j]);
		}
		printf("\n");
	}
	printf("Output mang 2 chieu: \n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < 10; i++)
	{
		delete[] b[i];
	}
	
}