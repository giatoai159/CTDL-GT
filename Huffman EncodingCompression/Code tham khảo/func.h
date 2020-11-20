#pragma once
#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cctype>
#include<cstring>
#include"Queue.h"
#include"Tree.h"

#define HELP_ERROR 99
#define width_unit 5

using namespace std;

void huf_write(unsigned char i, ofstream & outfile);
unsigned char huf_read(ifstream & infile);
void encoder(string ifile, string ofile, bool verbose);
void decoder(string ifile, string ofile, bool verbose);
void usage_msg(const string & pname);