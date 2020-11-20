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

template<class T>
class Queue
{
public:

	Queue(int d = 2); //constructor 
	~Queue(void); // destructor
	void enq(T*); //enqueue (to push)
	T* deq(void); //dequeue (to pop)
	T* front(void); //the front element
	bool empty(void) const; //is empty?
	bool full(void) const; //is full?

private:

	int back; //the last element in the queue
	T* *arr; //dynamic array
	int size; //current size of the queue array
	static const int SIZE = 10; //size increment step size  
	int D; //max number of children for a parent>=2 
		   //copy constructor and assignment are hidden to protect 
	Queue(const Queue &);
	const Queue & operator=(const Queue &);

	//utility functions to fix the heap
	//when an element added or removed 
	void reheapup(int, int); //fix heap upward
	void reheapdown(int, int); //fix heap downward
	void swap(T* &, T* &); //swap f. needed by reheapup/down functions

}; //end class
