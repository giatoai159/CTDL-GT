#include"Matrix.h"
#include"FuncVecto.h"
#include"Graphic.h"
#include"Bool.h"

int main()
{
	int choice;
	do {
		system("CLS");
		title();
		menu1();
		cout << "Select: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			system("CLS");
			int a[MAX][MAX];
			int n;
			NhapDaThuc(a, n);
			XuatDaThuc(a, n);
			RutGon(a, n);
			XuatDaThuc(a, n);
			system("pause");
		}
		break;
		case 2:
		{
			do {
				system("CLS");
				title();
				menu2();
				cout << "Select: ";
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					system("CLS");
					float a[MAX], b[MAX];
					int n;
					cout << "Hai ma tran co cung so chieu moi co the cong voi nhau!" << endl;
					cout << "Nhap do dai hai ma tran: "; cin >> n;
					cout << "Nhap vecto thu nhat: " << endl;
					NhapVecto(a, n);
					cout << "Nhap vecto thu hai: " << endl;
					NhapVecto(b, n);
					TongVecto(a, b, n);
					cout << "Vecto tong la: " << endl;
					XuatVecto(a, n);
					cout << endl;
					system("pause");
				}
				break;
				case 2:
				{
					system("CLS");
					float Alphal, a[MAX];
					int n;
					cout << "Nhap so chieu: ";
					cin >> n;
					cout << "Nhap vector: " << endl;
					NhapVecto(a, n);
					cout << "Nhap so Alphal: ";
					cin >> Alphal;
					NhanAlphal(a, n, Alphal);
					cout << "Vecto nhan: " << endl;
					XuatVecto(a, n);
					cout << endl;
					system("pause");
				}
				break;
				default:
					break;
				}
			} while (choice != 3);
		}
		break;
		case 3:
		{
			do {
				system("CLS");
				title();
				menu3();
				cout << "Select: ";
				cin >> choice;

				switch (choice)
				{
				case 1:
				{
					system("CLS");
					int dim;
					cout << "Nhap kich thuoc ma tran: "; cin >> dim;
					float mat[MAX][MAX];
					nhapMaTranVuong(mat, dim);
					cout << "Ma tran vua nhap la: ";
					xuatMaTran(mat, dim, dim);
					cout << endl;
					cout << "Dinh thuc ma tran = " << findDet(mat, dim) << endl;
					system("pause");
					// some function
				}
				break;
				case 2:
				{
					system("CLS");
					int dim;
					cout << "Nhap kich thuoc ma tran: "; cin >> dim;
					float mat[MAX][2 * MAX];
					cout << "Nhap ma tran: " << endl;
					for (int i = 0; i < dim; i++)
						for (int j = 0; j < 2 * dim; j++)
							if (j == i + 3) mat[i][j] = 1.0;
							else mat[i][j] = 0;
							for (int i = 0; i < dim; i++)
							{
								for (int j = 0; j < dim; j++)
								{
									cout << "[" << i << "]" << "[" << j << "]" << "= "; cin >> mat[i][j];
								}
							}
							cout << "Ma tran vua nhap la: ";
							for (int i = 0; i < dim; i++)
							{
								cout << endl;
								for (int j = 0; j < dim; j++)
								{
									cout << mat[i][j] << "  ";
								}
							}
							for (int i = 0; i < dim; i++) NghichDao(mat, dim, i, i);
							for (int i = 0; i < dim; i++)
							{
								cout << endl;
								for (int j = 0; j < dim; j++)
								{
									cout << mat[i][j + dim] << "  ";
								}
							}
							system("pause");
				}
				break;
				case 3:
				{
					system("CLS");
					int row1, col1, row2, col2;
				Start:
					cout << "Nhap kich thuoc so hang so cot ma tran thu nhat: " << endl; cin >> row1 >> col1;
					cout << "Nhap kich thuoc so hang so cot ma tran thu hai: " << endl; cin >> row2 >> col2;
					if (col1 != row2)
					{
						cout << "Khong the nhan hai ma tran neu so cot ma tran 1 khac so dong ma tran 2! Xin nhap lai " << endl;
						goto Start;
					}
					else
					{
						float mata[MAX][MAX], matb[MAX][MAX], matc[MAX][MAX];
						nhapMaTran(mata, row1, col1);
						nhapMaTran(matb, row2, col2);
						cout << "Ket qua nhan hai ma tran: " << endl;
						Multiplication(mata, matb, matc, row1, col2);
						xuatMaTran(matc, row1, col2);
					}
					system("pause");
				}
				break;
				case 4:
				{
					system("CLS");
					float a[MAX][MAX];
					int row, col;
					cout << "Nhap vao so dong so cot cua ma tran: "; cin >> row >> col;
					nhapMaTran(a, row, col);
					cout << "Hang cua ma tran la: " << hangMaTran(a, row, col) << endl;
					system("pause");
				}
				break;
				case 5:
				{
					system("CLS");
					float a[MAX][MAX], b[MAX];
					int row, col;
					cout << "Nhap vao so dong so cot ma tran" << endl; cin >> row >> col;
					nhapMaTran(a, row, col);
					cout << "Nhap vao vecto B" << endl;
					for (int i = 0; i < row; i++) cin >> b[i];
					cout << "Phuong trinh co dang AX = B" << endl;
					HePTTT(a, b, row, col);
					system("pause");
				}
				default:
					break;
				}
			} while (choice != 6);
		}
		break;
		default:
			break;
		}
	} while (choice != 4);
	return 0;
}
