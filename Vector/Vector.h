#pragma once
#include <iostream>
using namespace std;

class Vector {
private:
	int cur_size;
	int buf_size;
	int *els;
public:
	//default constructor
	Vector() {
		cur_size = 0;
		buf_size = 0;
		els = nullptr;
	}
	//size constructor
	Vector(int size) {
		this->cur_size = size;
		this->buf_size = size;
		this->els = new int[buf_size];
		for (int i = 0; i < buf_size; i++) {
			this->els[i] = 0;
		}
	}
	//copy constructor
	Vector(const Vector&src) {
		this->cur_size = src.cur_size;
		this->buf_size = src.cur_size;
		this->els = new int[cur_size];

		for (int i = 0; i < cur_size; i++) {
			this->els[i] = src.els[i];
		}
	}

	void buf() {
		if (cur_size >= buf_size) {
			int *temp;
			buf_size *= 2;
			temp = new int[buf_size];
			for (int i = 0; i < cur_size; i++) {
				temp[i] = els[i];
			}
			delete[] els;
			els = temp;
		}
	}

	void push_back(const int &e) {
		buf();
		els[cur_size++] = e;

	}

	void push_this(const int &pos, const int &e) {
		buf();

		els[cur_size + 1] = e;
		cur_size++;

		for (int i = cur_size; i > pos-1; i--) {
			swap(els[i], els[i - 1]);
		}
	}

	void delete_this(const int &pos) {
		for (int i = pos-1; i < cur_size; i++) {
			swap(els[i], els[i + 1]);
		}
		cur_size--;
	}

	int &at(int pos) {
		return els[pos - 1];
	}

	void print() {
		for (int i = 0; i < cur_size; i++) {
			cout << els[i] << " ";
		}
	}

	//destructor
	~Vector() {
		delete[] els;
		els = nullptr;
	}
};
