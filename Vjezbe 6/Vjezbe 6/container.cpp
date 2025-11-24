#include "container.h"
#include <stdexcept>

container::container(size_t kap)
	:data(nullptr), velicina(0), kapacitet(kap)
{
	if (kapacitet > 0)
		data = new int[kapacitet];
}

container::container(const container& other)
	:data(nullptr), velicina(other.velicina), kapacitet(other.kapacitet)
{
	if (kapacitet > 0)
		data = new int[kapacitet];

	for (size_t i = 0; i < velicina; i++) {
		data[i] = other.data[i];
	}
}

size_t container::size() const {
	return velicina;
}

void container::clear() {
	velicina = 0;
}