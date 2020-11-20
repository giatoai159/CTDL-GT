#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cctype>
#include<cstring>

#define HELP_ERROR 99
#define width_unit 5

using namespace std;

// Huffman Tree
class Tree
{
private:
	class Node
	{
	public:
		unsigned int freq;
		unsigned char ch;
		Node *left, *right;
		//constructor
		Node(void)
			:freq(0), ch('\0'), left(NULL), right(NULL) {}
	};

	Node *root;

	//copy cons. and assign. op. overload prototypes are private to
	//prevent them to be used
	Tree(const Tree &); //copy constructor
	const Tree & operator=(const Tree &); //assignment oper. overload
	void chop(Node * N); //destroys the tree
	void print(ostream &, Node *, int) const; //prints the tree
	void print(Node *, int) const; //prints the tree

public:
	Tree(void); //constructor
	~Tree(void); //destructor
	friend ostream & operator<<(ostream &, const Tree &);
	//utility functions to get or set class members
	unsigned int get_freq(void) const;
	unsigned char get_char(void) const;
	void set_freq(unsigned int);
	void set_char(unsigned char);
	Node* get_left(void) const;
	Node* get_right(void) const;
	void set_left(Node *);
	void set_right(Node *);
	Node* get_root(void) const;
	//comparison operator overloads to compare
	//2 objects of the class
	bool operator==(const Tree &) const;
	bool operator!=(const Tree &) const;
	bool operator<(const Tree &) const;
	bool operator>(const Tree &) const;
	bool operator<=(const Tree &) const;
	bool operator>=(const Tree &) const;

	//to get H. string of a given char
	void huf(Node *, unsigned char, string, string &) const;
	//outputs the H. char-string pairs list
	void huf_list(Node *, string) const;
	//to get char equivalent of a H. string (if exists)
	bool get_huf_char(string, unsigned char &) const;
	string print_char(Node *) const; //prints chars 
};