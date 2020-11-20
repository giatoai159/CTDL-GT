#include<stdio.h>

struct DIEM
{
	int x, y;
};

void TruyenThamTri(int a)
{
	a = a * 10;
}

void TruyenThamBien(int &a)
{
	a = a * 10;
}

void ThamTriConTro(DIEM *d)
{
	d->x = d->x * 10;
	d->y = d->y * 10;
}

void ThamBienConTro(DIEM* &d, DIEM *p)
{
	d->x = d->x * 10;
	d->y = d->y * 10;
	d = p;
}

void main()
{
	int a = 1;
	printf("a=%d\n", a);
	TruyenThamTri(a);
	printf("a sau ham TruyenThamTri = %d\n", a);
	TruyenThamBien(a);
	printf("a sau ham TruyenThamBien = %d\n", a);

	DIEM *d2 = new DIEM;
	d2->x = 5; d2->y = 5;
	printf("Diem d2(%d,%d)\n", d2->x, d2->y);
	ThamTriConTro(d2);
	printf("d2 sau khi goi ham ThamTriConTro: (%d,%d)\n", d2->x, d2->y);
	printf("\n");

	DIEM* d1 = new DIEM;
	d1->x = 5; d1->y = 5;
	d2->x = 5; d2->y = 5;
	printf("Diem d2(%d,%d)\n", d2->x, d2->y);
	ThamBienConTro(d2, d1);
	printf("d2 sau khi goi ham ThamBienConTro: (%d,%d)\n", d2->x, d2->y);
}