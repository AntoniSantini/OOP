#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>

class container {
	int* data;
	size_t velicina;
	size_t kapacitet;

public:
	container(size_t kap = 0);
	container(const container& other);
	container(const container&& other)noexcept;

	~container();

	void push_back(int value);
	size_t size() const;
	size_t capacity() const;
	int& at(size_t indeks);
	const int& at(size_t indeks) const;
	void clear();
};

#endif

