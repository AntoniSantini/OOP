#include "container.h"
using namespace std;

void print(container c) {
	cout << "Ispis: " << endl;
	for (size_t i = 0; i < c.size(); i++)
		cout << "c[" << i << "] = " << c.at(i) << endl;
}

container returnContainer(){
	container temp;
	temp.push_back(100);
	temp.push_back(200);
	return temp;
}

int main() {
	container a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);

	container b = a;

	container c = move(a);
	
	print(b);

	container d = returnContainer();
	for (int i = 0; i < 10; i++)
		d.push_back(i);

	cout << "Ispis containera: " << endl;
	for (size_t i = 0; i < d.size(); i++)
		cout << "d[" << i << "] = " << d.at(i) << endl;

	return 0;
}