#ifndef AQUATIC_H
#define AQUATIC_H

#include "animal.h"

using namespace std;

class Aquatic : public virtual Animal {
protected:
	double maxDiveDepth;

public:
	Aquatic(const string& name, int age, double weight, double maxDiveDepth);
	virtual ~Aquatic() = default;

	double getMaxDiveDepth() const;
};

#endif