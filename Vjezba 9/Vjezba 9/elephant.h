#ifndef ELEPHANT_H
#define ELEPHANT_H

#include "mammal.h"

using namespace std;

class Elephant : public Mammal {
public:
	Elephant(const string& name, int age, double weight);
	virtual ~Elephant() = default;

	string getSpecies() const override;
	double getDailyFood() const override;
};

#endif