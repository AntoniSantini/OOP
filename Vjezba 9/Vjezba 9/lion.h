#ifndef LION_H
#define LION_H

#include "mammal.h"
#include <string>

using namespace std;

class Lion : public Mammal {
public:
	Lion(const string& name, int age, double weight);
	virtual ~Lion() = default;

	string getSpecies() const override;
	double getDailyFood() const override;
};

#endif
