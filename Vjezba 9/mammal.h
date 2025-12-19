#ifndef MAMMAL_H
#define MAMMAL_H

#include "animal.h"

using namespace std;

class Mammal : public virtual Animal {
protected:
	bool hasFur;

public:
	Mammal(const string& name, int age, double weight, bool hasFur);
	virtual ~Mammal() = default;

	bool getHasFur() const;
};

#endif