#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

using namespace std;

class Animal {
protected:
	string name;
	int age;
	double weight;

	Animal(const string& name, int age, double weight);

public:
	virtual ~Animal() = default;

	virtual string getSpecies() const = 0;
	virtual double getDailyFood() const = 0;
	virtual string getName() const;

	int getAge() const;
	double getWeight() const;
};

#endif