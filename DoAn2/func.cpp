#include"func.h"

void Compress(const char *in, const char *out)
{
	fstream input, output;
	char c, next_c;
	int filesize = 0;
	int count = 1;       // unique byte values
	int pos = 0;

	input.open(in, ios::in | ios::ate | ios::binary); // Mo file = binary, dat vi tri con tro o cuoi file
	output.open(out, ios::out | ios::trunc | ios::binary); // Mo file = binary, xoa tat ca noi dung cu~ cua file bang ios::trunc
	filesize = input.tellg(); // tellg() tra ve vi tri cuoi cung tai vi tri con tro hien tai

	for (int i = 0; i < filesize; i++)
	{
		input.seekg(i, ios::beg);      // Dat vi tri doc tai i
		input.read((char*)&c, sizeof(char)); // lay ki tu hien tai, tai vi tri con tro
		next_c = input.peek(); // Nhin vao ki tu ke tiep
		if (next_c != c)
		{
			output.seekp(pos, ios::beg);
			output.write((char*)&count, sizeof(char)); // 
			output.seekp(pos + 1, ios::beg);
			output.write((char*)&c, sizeof(char));
			pos += 2;
			count = 0;
		}
		count++;
	}
	input.close();
	output.close();
}
void Decompress(const char *in, const char *out)
{
	fstream input;
	fstream output;
	char c;
	int count = 0;
	int filesize = 0;
	int pos = 0;

	input.open(in, ios::ate | ios::in | ios::binary);
	output.open(out, ios::trunc | ios::out | ios::binary);
	filesize = input.tellg();

	for (int i = 0; i < filesize; i += 2)
	{
		input.seekg(i, ios::beg);
		input.read((char*)&count, sizeof(char));
		input.seekg(i + 1, ios::beg);
		input.read((char*)&c, sizeof(char));
		for (int j = 0; j < count; j++)
		{
			output.seekp(pos, ios::beg);
			output.write((char*)&c, sizeof(char));
			pos++;
		}
	}
	input.close();
	output.close();
}