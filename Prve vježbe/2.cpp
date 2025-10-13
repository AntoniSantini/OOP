#include <iostream>

int ogranici(int broj, int low = 10, int high = 100) {
	if (broj < low)
		return low;
	if (broj > high)
		return high;
	return broj;
}

double ogranici(double broj, double low = 10.5, double high = 100.5) {
	if (broj < low)
		return low;
	if (broj > high)
		return high;
	return broj;
}

int main() {
	int a = -5, c = 50;
	double b = 100.9, d= 70;
	
	std::cout << "Int vrijednost:\n";
	std::cout << "Broj -5 -> " << ogranici(a) << std::endl;
	std::cout << "Broj 50 -> " << ogranici(c) << std::endl;

	std::cout << "Double vrijednost:\n";
	std::cout << "Broj 100.9 -> " << ogranici(b) << std::endl;
	std::cout << "Broj 70 -> " << ogranici(d) << std::endl;
	
	return 0;
}