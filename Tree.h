#pragma once
#include "iterator.h"
using namespace std;
struct node {
	int value;
	node* left,
		* right;
	node(int symb, node* pointer, node* pointer2) : value(symb), left(pointer), right(pointer2) {}
};

struct Listic {
	node* inf;
	Listic* next;
	Listic(node* symb, Listic* pointer) : inf(symb), next(pointer) {}
};

class List
{
private:
	Listic* root,
		* last;
public:
	void push_front(node* current);
	void del_first();
	void del_last();
	void push_back(node* current);
	Listic* get_first();
	Listic* get_last();
};
class Tree
{

private:
	node* first;
public:
	Tree() {};
	bool contains(int x);
	void insert(int x);
	void remove(int x);
	void up();
	void right();
	Iterator* create_bft_iterator();
	Iterator* create_dft_iterator();
	class dft_Iterator : public Iterator {
		List stack;
		node* current;
	public:
		dft_Iterator(node* start) : current(start) {
			stack.push_front(start);
		}
		bool has_next();
		int next();
	};
	class bft_Iterator : public Iterator {
		List queue;
		node* current;
	public:
		bft_Iterator(node* start) : current(start) {
			queue.push_front(start);
		}
		bool has_next();
		int next();
	};


};

