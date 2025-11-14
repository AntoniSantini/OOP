#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

class Karta {
public:
	int broj;
	string zog;

	Karta(int b, string z) : broj(b), zog(z) {}
};

class Mac {
private:
	vector<Karta> karte;

public:
	Mac() {
		string zogovi[4] = { "Bastoni", "Kupe", "Spade", "Dinari" };
		for (string zog : zogovi) {

			for (int broj = 1; broj <= 7; broj++) {
				karte.push_back(Karta(broj, zog));
			}

			for (int broj = 11; broj <= 13; broj++) {
				karte.push_back(Karta(broj, zog));
			}
		}
	}

	void promijesaj() {
		srand(time(0));
		for (int i = 0; i < karte.size(); i++) {
			int rIndex = rand() % karte.size();
			swap(karte[i], karte[rIndex]);
		}
	}

	vector<Karta> podijeli(int brojKarata) {
		vector<Karta> ruka;
		for (int i = 0; i < brojKarata; i++) {
			ruka.push_back(karte.back());
			karte.pop_back();
		}
		return ruka;
	}
};

class Igrac {
private:
	string ime;
	vector<Karta> karte;
	int bodovi;

	bool imaNapolitanu() {
		for (string zog : {"Bastoni", "Kupe", "Spade", "Dinari"}) {
			bool imaAs = false, imaDuja = false, imaTrica = false;

			for (Karta karta : karte) {
				if (karta.zog == zog) {
					if (karta.broj == 1) imaAs = true;
					if (karta.broj == 2) imaDuja = true;
					if (karta.broj == 3) imaTrica = true;
				}
			}

			if (imaAs && imaDuja && imaTrica) return true;
		}
		return false;
	}

	int brojIstihKarata() {
		int maxIste = 0;

		for (int broj = 1; broj <= 3; broj++) {
			int brojac = 0;
			for (Karta karta : karte) {
				if (karta.broj == broj) brojac++;
			}
			if (brojac > maxIste) maxIste = brojac;
		}

		if (maxIste >= 3) return maxIste;
		return 0;
	}

public:
	Igrac(string i) : ime(i), bodovi(0) {}

	void primiKarte(vector<Karta> noveKarte) {
		karte = noveKarte;
	}

	void ispisiKarte() {
		cout << ime << " karte: ";
		for (Karta karta : karte) {
			cout << karta.broj << karta.zog[0] << " ";
		}
		cout << endl;
	}

	void akuza() {
		bodovi = 0;

		if (imaNapolitanu()) {
			bodovi += 3;
		}

		int iste = brojIstihKarata();
		if (iste >= 3) {
			bodovi += iste;
		}
	}

	int getBodovi() { return bodovi; }
	string getIme() { return ime; }
};

int main() {
	int brojIgraca;
	cout << "Broj igraca (2 ili 4): ";
	cin >> brojIgraca;

	if (brojIgraca != 2 && brojIgraca != 4) {
		cout << "Greska!" << endl;
		return 1;
	}

	vector<Igrac> igraci;

	for (int i = 0; i < brojIgraca; i++) {
		string ime;
		cout << "Ime igraca " << i + 1 << ": ";
		cin >> ime;
		igraci.push_back(Igrac(ime));
	}

	Mac mac;
	mac.promijesaj();

	for (int i = 0; i < brojIgraca; i++) {
		vector<Karta> ruka = mac.podijeli(10);
		igraci[i].primiKarte(ruka);
	}

	cout << endl;
	for (Igrac& igrac : igraci) {
		igrac.ispisiKarte();
		igrac.akuza();
		cout << igrac.getIme() << " bodovi: " << igrac.getBodovi() << endl;
		cout << endl;
	}

	return 0;
}