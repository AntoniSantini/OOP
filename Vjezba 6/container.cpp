#include "container.h"
#include <iostream>

container::container(size_t initial_capacity)
	: data(nullptr), count(0), cap(initial_capacity) {
	if (cap > 0) data = new int[cap];
	std::cout << "Container kreiran, kapacitet=" << cap << "\n";
}

container::container(const container& other)
	: data(nullptr), count(other.count), cap(other.cap) {
	if (cap > 0) data = new int[cap];
	for (size_t i = 0; i < count; i++) data[i] = other.data[i];
	std::cout << "Container kopiran, broj elemenata=" << count << "\n";
}

container::container(container&& other) noexcept
	: data(other.data), count(other.count), cap(other.cap) {
	other.data = nullptr;
	other.count = 0;
	other.cap = 0;
	std::cout << "Container premjesten, broj elemenata=" << count << "\n";
}

container::~container() {
	delete[] data;
	std::cout << "Container unisten\n";
}

void container::push_back(int x) {
	if (count >= cap) {
		size_t newcap = (cap == 0 ? 1 : cap * 2);
		int* novo = new int[newcap];
		for (size_t i = 0; i < count; i++) novo[i] = data[i];
		delete[] data;
		data = novo;
		cap = newcap;
		std::cout << "Realokacija, novi kapacitet=" << cap << "\n";
	}
	data[count++] = x;
}

size_t container::size() const { return count; }
size_t container::capacity() const { return cap; }
int& container::at(size_t index) { return data[index]; }
const int& container::at(size_t index) const { return data[index]; }
void container::clear() { count = 0; }
