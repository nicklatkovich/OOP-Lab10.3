#pragma once
#include <iostream>

using namespace std;

const int MIN_NUMBER = 0;
const int MAX_NUMBER = 9;

template <class T>
class Array {
	T * data = new T[0];
	int size = 0;
public:
	Array(int size) {
		delete[] data;
		this->size = size;
		data = new T[size];
		SetRand(MIN_NUMBER, MAX_NUMBER);
	}
	Array(const Array & Copy) {
		delete[] data;
		size = Copy.size;
		data = new T[size];
		for (int i = 0; i < size; i++) {
			data[i] = Copy.data[i];
		}
	}
	~Array() {
		delete[] data;
	}
	void Set(T dat, int index) {
		if (index > -1) if (index < size) {
			data[index] = dat;
		}
	}
	template <typename T = int>
	void SetRand(int min, int max) {
		int r = abs(max - min) + 1;
		for (int i = 0; i < size; i++) {
			data[i] = rand() % r + min;
		}
	}
	template <typename T = double>
	void SetRandDouble(int min, int max) {
		min *= 100;
		max *= 100;
		int r = abs(max - min) + 1;
		for (int i = 0; i < size; i++) {
			data[i] = (double)(rand() % r + min) / 100;
		}
	}
	T Get(int index) {
		if (index > -1) if (index < size) {
			return data[index];
		}
		return 0;
	}
	int GetSize() {
		return size;
	}
	void Resize(int size) {
		Array temp = *this;
		delete[] data;
		data = new T[size];
		for (int i = 0; i < size; i++) {
			data[i] = temp.Get(i);
		}
	}
	friend Array operator * (Array & left, Array & right) {
		int min;
		if (left.size < right.size) {
			min = left.size;
		}
		else {
			min = right.size;
		}
		Array temp(min);
		for (int i = 0; i < min; i++) {
			temp.data[i] = left[i] * right[i];
		}
		return temp;
	}
	Array & operator = (const Array & right) {
		delete[] data;
		size = right.size;
		data = new T[size];
		for (int i = 0; i < size; i++) {
			data[i] = right.data[i];
		}
		return *this;
	}
	T operator [] (int index) {
		return Get(index);
	}
	operator int() {
		return size;
	}
	friend bool operator == (Array & left, Array & right) {
		if (left.size != right.size) {
			return false;
		}
		else {
			for (int i = 0; i < left.size; i++) {
				if (left[i] != right[i]) {
					return false;
				}
			}
			return true;
		}
	}
	friend bool operator <= (Array & left, Array & right) {
		if (left.size < right.size) {
			return true;
		}
		else if (left.size > right.size) {
			return false;
		}
		else {
			for (int i = 0; i < left.size; i++) {
				if (left[i] < right[i]) {
					return true;
				}
				else if (left[i] > right[i]) {
					return false;
				}
			}
			return true;
		}
	}
	friend bool operator < (Array <T> left, Array <T> right) {
		if (left.size < right.size) {
			return true;
		}
		else if (left.size > right.size) {
			return false;
		}
		else {
			for (int i = 0; i < left.size; i++) {
				if (left.data[i] < right[i]) {
					return true;
				}
				else if (left.data[i] > right[i]) {
					return false;
				}
			}
			return false;
		}
	}
	void print() {
		cout << *this;
	}
	friend ostream & operator << (ostream & output, const Array arr) {
		output << "(";
		for (int i = 0; i < arr.size; i++) {
			if (i > 0) {
				output << ",";
			}
			output << " " << arr.data[i];
		}
		output << " )";
		return output;
	}
};