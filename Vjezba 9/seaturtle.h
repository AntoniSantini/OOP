#ifndef SEATURTLE_H
#define SEATURTLE_H

#include "aquatic.h"

using namespace std;

class SeaTurtle : public Aquatic {
public:
	SeaTurtle(const string& name, int age, double weight);
	virtual ~SeaTurtle() = default;

	string getSpecies() const override;
	double getDailyFood() const override;
};

#endif