#include<stdio.h>

void XuatFile(char* tenFile, float* arr, int n)
{
	FILE* fo = fopen(tenFile, "wt");
	for (int i = 0; i < n; i++)
		fprintf(fo, "%0.1f", arr[i]);
	fclose(fo);
}

void XuatFileSoLe(char* tenFile, float* arr, int n)
{
	FILE* fo = fopen(tenFile, "wt");
	for (int i = 1; i < n; i+=2)
		fprintf(fo, "%0.1f\n", arr[i]);
	fclose(fo);
}

void XuatFileMSSV(char* tenFile, int* arr, int n)
{
	FILE* fo = fopen(tenFile, "wt");
	for (int i = 0; i < n; i++)
		fprintf(fo, "%d\n", arr[i]);
	fclose(fo);
}
void XuatFileSoLeMSSV(char* tenFile, int* arr, int n)
{
	FILE* fo = fopen(tenFile, "wt");
	for (int i = 1; i < n; i += 2)
		fprintf(fo, "%d\n", arr[i]);
	fclose(fo);
}

void tongPhanTu(char* tenFile, float* arr, int n)
{
	FILE* fo = fopen(tenFile, "wt");
	float s = 0;
	for (int i = 0; i < n; i++)
		s += arr[i];
	fprintf(fo, "Tong: %0.1f", s);
	fclose(fo);
}
void main()
{
	
	FILE* fi = fopen("input.txt", "rt");

	int n;
	fscanf(fi, "%d", &n);
	float *arr = new float[n];
	for (int i = 0; i < n; i++)
		fscanf(fi, "%f\n", &arr[i]);
	fclose(fi);
	
	for (int i = 0; i < n; i++)
		printf("%0.1f ", arr[i]);
	printf("\n");

	XuatFileSoLe("output.txt", arr, n);
	tongPhanTu("tong.txt", arr, n);
	
	FILE* fi_mssv = fopen("MSSV.txt", "rt");

	int n_mssv;
	fscanf(fi_mssv, "%d", &n_mssv);
	int *mssv = new int[n_mssv];
	for (int i = 0; i < n_mssv; i++)
		fscanf(fi_mssv, "%d", &mssv[i]);
	fclose(fi_mssv);

	for (int i = 0; i < n_mssv; i++)
		printf("%d ", mssv[i]);
	printf("\n");
	XuatFileSoLeMSSV("out_MSSV.txt",mssv,n_mssv);

}