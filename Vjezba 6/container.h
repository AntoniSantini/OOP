#ifndef CONTAINER_H
#define CONTAINER_H

#include <cstddef>

class container {
public:
	container(size_t initial_capacity = 0);
	container(const container& other);
	container(container&& other) noexcept;
	~container();

	void push_back(int x);
	size_t size() const;
	size_t capacity() const;
	int& at(size_t index);
	const int& at(size_t index) const;
	void clear();

private:
	int* data;
	size_t count;
	size_t cap;
};

#endif
