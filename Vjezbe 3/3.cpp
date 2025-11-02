//#include <iostream>
//using namespace std;
//
//int main() {
//	int rezultat[] = { 1,2,3,4,5,6 };
//	int n = sizeof(rezultat) / sizeof(rezultat[0]);
//
//	auto jeParan = [](int x) { return x % 2 == 0; };
//	auto jeNeparan = [](int x) { return x % 2 != 0; };
//	auto udvostruci = [](int x) { return x * 2; };
//	auto prepolovi = [](int x) { return x / 2; };
//
//	int suma = 0;
//	auto dodajUSumu = [&suma](int x) { suma += x; };
//
//	int produkt = 1;
//	auto dodajUProdukt = [&produkt](int x) { produkt *= x; };
//
//	int prag = 4;
//	int sumaPrag = 0;
//	auto dodajAkoVeci = [prag, &sumaPrag](int x) { if (x > prag) sumaPrag += x; };
//
//	for (int i = 0; i < n; i++) {
//		if (jeParan(rezultat[i])) rezultat[i] = prepolovi(rezultat[i]);
//		else rezultat[i] = udvostruci(rezultat[i]);
//	}
//
//	suma = 0;
//	produkt = 1;
//	for (int i = 0; i < n; i++) {
//		dodajUSumu(rezultat[i]);
//		dodajUProdukt(rezultat[i]);
//	}
//
//	sumaPrag = 0;
//	for (int i = 0; i < n; i++) {
//		dodajAkoVeci(rezultat[i]);
//	}
//
//	cout << "Rezultat niza: ";
//	for (int i = 0; i < n; i++) cout << rezultat[i] << " ";
//	cout << "\nSuma: " << suma;
//	cout << "\nProdukt: " << produkt;
//	cout << "\nSuma vecih od " << prag << ": " << sumaPrag << endl;
//
//	return 0;
//}
