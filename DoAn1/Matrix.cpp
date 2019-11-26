#include"Matrix.h"

void nhapMaTranVuong(float mat[MAX][MAX], int dim)
{
	cout << "Nhap ma tran: " << endl;
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			cout << "[" << i << "]" << "[" << j << "]" << "= "; cin >> mat[i][j];
		}
	}
}

void nhapMaTran(float mat[MAX][MAX], int row, int col)
{
	cout << "Nhap ma tran: " << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << "[" << i << "]" << "[" << j << "]" << "= "; cin >> mat[i][j];
		}
	}
}

float findDet(float mat[MAX][MAX], int dim) // Ham tinh dinh thuc ma tran, input mot ma tran vuong voi dim x dim chieu
{
	if (dim == 1)
		return mat[0][0]; // Neu ma tran co kich thuoc la 1x1 thi tra ve gia tri duy nhat trong ma tran;
	if (dim == 2)
		return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]; // Neu ma tran co kich thuoc la 2x2 thi tra ve gia tri det = a*d-b*c;
	// Neu ma tran co kich thuoc n>2 thi thuc hien cac phep toan sau
	float submat[MAX][MAX]; // Tao mot ma tran phu de chua ma tran con, duoc su dung de tinh dinh thuc con cua phan tu
	int kq = 0;
	int phepToan = 1; // Thay doi giua phep cong va phep tru
	for (int a = 0; a < dim; a++) // Lay tung phan tu dong dau tien cua ma tran va bat dau tim ma tran con cua no
	{
		int submat_row = 0; // Bat dau tu` dong` dau` tien cua ma tran con, con co tac dung reset lai vi tri dong` da~ xet cua ma tran con khi ta xet den phan` tu tiep theo cua ma tran
		for (int i = 1; i < dim; i++) // Lay cac phan tu tu` dong thu 2 cua ma tran de them vao ma tran con
		{
			int submat_col = 0; // Bat dau tu` cot dau` tien cua ma tran con, con co tac dung reset lai vi tri cot da~ xet cua ma tran con khi ta xet den phan` tu tiep theo cua ma tran
			for (int j = 0; j < dim; j++) // Bat dau lay tung` phan tu cua moi cot cua ma tran vao` ma tran con
			{
				if (j == a)
					continue; // Neu vi tri cot dang xet' trung` voi' vi tri' cot tren dong` dau` tien cua phan tu, bo qua cac buoc tiep theo va tiep tuc vong lap for
				submat[submat_row][submat_col] = mat[i][j]; // Gan phan tu cua ma tran vao ma tran con
				submat_col++; // Bat dau hoat dong va ghi len cot tiep theo cua ma tran con
			}
			submat_row++; // Bat dau hoat dong den dong tiep theo cua ma tran con
		}
		kq += phepToan*mat[0][a] * findDet(submat, dim - 1); // Phep tinh dinh thuc ma tran "phepToan" thay doi lan luot + - + - +,... neu ma tran lon hon, nhan voi cac phan tu dong` dau tien va dinh thuc cua ma tran con cua cac' phan` tu do' 
		phepToan = -1 * phepToan; // Luan phien phep toan
	}
	return kq; // Tra ve dinh thuc ma tran
}

void xuatMaTran(float mat[MAX][MAX], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		cout << endl;
		for (int j = 0; j < col; j++)
		{
			cout << mat[i][j] << "  ";
		}
	}
	cout << endl;
}
void NghichDao(float a[MAX][2 * MAX], int n, int row, int col) // n la size cua ma tran
{
	float x = a[row][row]; // Gan gia tri phan tu tren duong cheo cho x
	for (int i = 0; i < 2 * n; i++) a[row][i] /= x; // Chia tung phan tu cua hang hien tai cho gia tri x;
	for (int i = 0; i < n; i++) if (i != row) // Cho vong lap chay neu gia tri cua i bang n thi thuc hien
	{
		x = a[i][row]; // Lan luot gan cac gia tri tu tren xuong duoi trong cung cot row
		for (int j = 0; j < 2 * n; j++) 
			a[i][j] = a[i][j] - a[row][j] * x; // Tinh tung phan tu cua ma tran nghich dao
	}
}
void Multiplication(float a[MAX][MAX], float b[MAX][MAX], float c[MAX][MAX], int row, int col)
{
	for (int i = 0; i < row; i++) // Lap theo dong
	for (int j = 0; j < col; j++) // Lap theo cot
	{
		c[i][j] = 0; // Tao gia tri cho ma tran c
		for (int k = 0; k < col; k++) // Lap theo cot
			c[i][j] = c[i][j] + (a[i][k] * b[k][j]); // Tinh lai tung phan tu cua ma tra c theo cong thuc
	}
}

void swapRow(float mat[MAX][MAX], int row, int col, int n, int m)
{
	for (int i = 0; i<col; i++)
		swap(mat[n][i], mat[m][i]);
}
void swapCol(float mat[MAX][MAX], int row, int col, int n, int m)
{
	for (int i = 0; i<row; i++)
		swap(mat[i][n], mat[i][m]);
}

int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}

int hangMaTran(float mat[MAX][MAX], int row, int col)
{
	int hang = min(row, col); // So hang mac dinh lon nhat cua ma tran
							  // Quy trinh rut gon ma tran de tim hang
	for (int i = 0; i<hang; i++) // Xet tung cot cua ma tran de bien doi
	{
		if (mat[i][i] != 0) // Kiem tra xem phan tu cheo' cua ma tran co = 0 khong, neu co thi thuc hien swap dong va cot, neu ko thi thuc hien qua trinh rut gon
		{
			for (int j = i + 1; j<row; j++) // Xet phan tu tiep theo ben duoi' phan tu i dang xet...
			{
				if (mat[j][i] != 0) // ... de xem phan tu co = 0 hay ko, neu ko = 0 thi se tinh toan de bien phan tu do bang 0 va cac phan tu tren dong` cung~ bi anh huong
				{
					float temp1 = mat[i][i]; // Phep nhan hai phan tu de = 0
					float temp2 = mat[j][i]; // ^
					for (int k = i; k<col; k++) // Rut gon dong anh huong
						mat[j][k] = mat[j][k] * temp1 - mat[i][k] * temp2;
				}
			}
		}
		else
		{
			int flag = 1; // Sau khi rut gon xong ma tran, ta chuyen ma tran thanh dang bac thang de kiem tra hang ma tran
			for (int j = i + 1; j<row; j++)
			{
				if (mat[j][i])
				{
					flag = 0;
					swapRow(mat, row, col, i, j); // Thay doi vi tri dong thanh dang bac thang
					break;
				}
			}
			if (flag)
			{
				hang--; // Dem so dong 0 0 0 de tru hang dan` dan`
				swapCol(mat, row, col, i, col - 1); // Chuyen cac phan tu cua cot ra dang bac thang
				i--;
			}
		}
	}

	cout << "Ma tran da rut gon va chuyen hoa thanh dang bac thang: " << endl;
	for (int i = 0; i<row; i++) // Xuat ra ma tran da rut gon
	{
		for (int j = 0; j<col; j++)
		{
			cout << mat[i][j] << "  ";
		}
		cout << endl;
	}
	return hang;
}

void HePTTT(float a[MAX][MAX], float b[MAX], int row, int col)
{
	float x[MAX];
	int i = 0, j = 0, t;
	while (i < row && j < col) // Cho dong lap bat dau voi i khoi dau bang 0 theo dong va j khoi dau bang 0 theo cot
	{
		if (a[i][j] == 0) // Neu phan tu dau tien cua dong bang 0
		{
			for (t = i + 1; t < row; t++) // Cho dong lap chay tu dong duoi lien ke
			if (a[t][j] != 0) // Neu phan tu dau tien cua dong khac 0
			{
				for (int k = i; k < col; k++) // Cho dong lao tung phan tu theo cot cua dong hien tai
				{
					int temp1 = a[t][k]; // Gan gia tri dong duoi lien ke cho bien temp1 
					a[t][k] = a[i][k]; // Gan gia tri cua dong tren cho dong duoi
					a[i][k] = temp1; // Gan gia tri cua bien temp1 cho dong tren
					int temp2 = b[t]; // Gan gia tri dong duoi lien ke cho bien temp12
					b[t] = b[i]; // Gan gia tri cua dong tren cho dong duoi
					b[i] = temp2; // Gan gia tri cua bien temp2 cho dong tren
				}
				break; // Dung dong lap for
			}
			if (t == row) j++; // Neu bien t bang so dong thi tang bien j len 1
		}
		else // Neu khong thi bat dau rut gon phan tu thanh ma tran bac thang
		{
			for (t = i + 1; t < row; t++) // Cho dong lap chay tu dong duoi lien ke theo dong
			if (a[t][j] != 0) // Neu phan tu xet khac 0
			{
				float x = a[t][j]; // Gan gia tri hien tai cho x
				b[t] = b[t] - b[i] * x / a[i][j]; // Bien doi gia tri phan tu cung dong cua vecto b theo ti le dong cua ma tran a
				for (int k = j; k < col; k++) a[t][k] = a[t][k] - a[i][k] * x / a[i][j];// Tinh phan tu bang cach lay chinh no tru di gia tri cua dong tren nhan cho ti le phan tu theo thu tu cua hai dong
			}
			i++; j++; // tang gia tri i va j sau do tiep tuc vong lap moi neu i < row va j < col
		}
	}
	if (hangMaTran(a, row, col) != row) row--;
	if (a[row - 1][col - 1] == 0) // Xet gia tri cuoi cung cua hang va cot bang 0 hay khong
			if (b[row - 1] != 0) cout << "He pt vo nghiem" << endl; // Neu phan tu cuoi cung cua vecto b bang khong thi he phuong trinh vo nghiem
			else cout << "He pt co vo so nghiem" << endl; // Nguoc lai c vo so nghiem
		else // Neu phan tu cuoi cung khac 0
		{
			for (int i = row - 1; i >= 0; i--) // Dong lap chay tu dong cuoi len
			{
				if (a[i][i] != 0) // Neu pha tu khac 0
				{
					if (i == row - 1) // Neu dong hien tai beng dong cuoi
						x[i] = b[i] / a[i][i]; // Tinh gi tri x cuoi cung
					else // Nguoc lai
					{
						x[i] = b[i]; // Gan gia tri cua b cho x tren cung mot dong
						for (int j = i + 1; j < row; j++) // Cho dong lap de tinh tung phan tu cua x
							x[i] = x[i] - a[i][j] * x[j]; // Tinh gia tri cua x bang cach tru di tung phan tu cua ma tran a theo dong nhan voi x tuong ung
						x[i] = x[i] / a[i][i]; // chia cho he so cua dong
					}
				}
			}
			cout << "\nNghiem cua phuong trinh la: " << endl;
			for (int i = 0; i < row; i++)
				cout << x[i] << endl;
		}
}