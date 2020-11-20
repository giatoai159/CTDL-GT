#include<vector>
#include<iostream>

using namespace std;

class FileSystemInfo
{
public:
	virtual int GetSize()
	{
		return 0;
	}
};

class File: public FileSystemInfo
{
private:
	int size;
public:
	File(int size)
	{
		this->size = size;
	}
	int GetSize()
	{
		return size;
	}
};

class Folder: public FileSystemInfo
{
private:
	vector<FileSystemInfo*>_arr;
public:
	void AddChild(FileSystemInfo* ele)
	{
		_arr.push_back(ele);
	}
	int GetSize()
	{
		int S = 0;
		for (unsigned int i = 0; i < _arr.size(); i++)
			S += _arr[i]->GetSize();
		return S;
	}
};

void main()
{
	Folder root;
	Folder a;
	Folder b;
	File myFile1(10);
	File myFile2(20);
	root.AddChild(&a);
	root.AddChild(&b);
	a.AddChild(&myFile1);
	b.AddChild(&myFile2);
	cout << root.GetSize();
	cout << endl;
}