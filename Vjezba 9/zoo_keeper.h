#ifndef ZOO_KEEPER_H
#define ZOO_KEEPER_H

#include "animal.h"
#include <iostream>

using namespace std;

class ZooKeeper {
private:
	static int totalAnimalsServed;

public:
	void processAnimal(Animal* animal);
	static int getTotalAnimalsServed();
};

#endif