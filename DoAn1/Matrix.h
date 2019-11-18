#pragma once
#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100

using namespace std;

void nhapMaTranVuong(float mat[MAX][MAX], int dim);
void nhapMaTran(float mat[MAX][MAX], int row, int col);
void xuatMaTran(float mat[MAX][MAX], int row, int col);
float findDet(float mat[MAX][MAX], int dim);
void NghichDao(float a[MAX][2 * MAX], int n, int row, int col);
void Multiplication(float a[MAX][MAX], float b[MAX][MAX], float c[MAX][MAX], int row, int col);
void swapRow(float mat[MAX][MAX], int row, int col, int n, int m);
void swapCol(float mat[MAX][MAX], int row, int col, int n, int m);
int min(int a, int b);
int hangMaTran(float mat[MAX][MAX], int row, int col);
void HePTTT(float a[MAX][MAX], float b[MAX], int row, int col);