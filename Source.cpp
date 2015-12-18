#include <iostream>
#include <stack>
#include <set>
#include "Array.h"

using namespace std;

const unsigned int SIZE_OF_STACK = 10;
const unsigned int MIN_SIZE_OF_ARRAY = 0;
const unsigned int MAX_SIZE_OF_ARRAY = 5;

int irandom_range(int a, int b) {
	if (a > b) {
		int swap = a;
		a = b;
		b = swap;
	}
	return (rand() % (b - a + 1) + a);
}

template <class T>
void sortStack(stack <T> & st) {
	multiset <T> G;
	while (!st.empty()) {
		G.emplace(st.top());
		st.pop();
	}
	for (multiset <T> ::iterator i = G.begin(); i != G.end(); ++i) {
		st.push(*i);
	}
}

template <class T>
stack <T> operator + (stack <T> st, set <T> G) {
	for (set <T> ::iterator i = G.begin(); i != G.end(); ++i) {
		st.push(*i);
	}
	return st;
}

template <class T>
void sortSet(set <T> & st) {
	multiset <T> G;
	set <T> empty;
	for (set <T> ::iterator i = st.begin(); i != st.end(); ++i) {
		G.emplace(*i);
	}
	st = empty;
	for (multiset <T> ::iterator i = G.begin(); i != G.end(); ++i) {
		st.emplace(*i);
	}
}

template <class T>
void reverseStack(stack <T> & st) {
	stack <T> temp;
	while (!st.empty()) {
		temp.push(st.top());
		st.pop();
	}
	st = temp;
}

template <class T>
void printStack(stack <T> st) {
	stack <T> temp = st;
	while (!temp.empty()) {
		cout << temp.top();
		temp.pop();
	}
	cout << endl;
}

template <class T>
void printSet(set <T> G) {
	for (set <T> ::iterator i = G.begin(); i != G.end(); ++i) {
		cout << *i;
	}
	cout << endl;
}

void main() {
	cout << "\nCREATE STACK OF ARRAYS\n";
	stack <Array<int>> st;
	for (int i = 0; i < SIZE_OF_STACK; i++) {
		Array <int> temp(irandom_range(MIN_SIZE_OF_ARRAY, MAX_SIZE_OF_ARRAY));
		st.emplace(temp);
	}
	printStack(st);

	cout << "\nANTISORT STACK\n";
	sortStack(st);
	printStack(st);

	cout << "\nCOUNT OF ARRAYS WITH (SIZE == 3) = ";
	set <Array<int>> G;
	{
		int counter = 0;
		stack <Array<int>> temp = st;
		while (!temp.empty()) {
			if (temp.top().GetSize() == 3) {
				counter++;
				G.emplace(temp.top());
			}
			temp.pop();
		}
		cout << counter << endl;
	}
	printSet(G);

	cout << "\nSORT SET\n";
	sortSet(G);
	printSet(G);

	cout << "\nTHIRD STACK\n";
	stack <Array<int>> st3 = st;
	st3 = st3 + G;
	printStack(st3);

	cout << "\nCOUNT OF ARRAYS WITH (SIZE == 3) = ";
	{
		stack <Array<int>> G;
		int counter = 0;
		stack <Array<int>> temp = st3;
		while (!temp.empty()) {
			if (temp.top().GetSize() == 3) {
				counter++;
				G.push(temp.top());
			}
			temp.pop();
		}
		cout << counter << endl;
		printStack(G);
	}
	cout << endl;
}