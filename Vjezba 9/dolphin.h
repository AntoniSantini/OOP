#ifndef DOLPHIN_H
#define DOLPHIN_H

#include "mammal.h"
#include "aquatic.h"

using namespace std;

class Dolphin : public Mammal, public Aquatic {
public:
	Dolphin(const string& name, int age, double weight);
	virtual ~Dolphin() = default;

	string getSpecies() const override;
	double getDailyFood() const override;
};

#endif