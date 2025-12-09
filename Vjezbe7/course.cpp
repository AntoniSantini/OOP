#include "course.h"
using namespace std;

Course::Course() : name(""), code(""), ects(5) {}
Course::Course(const string& n, const string& c, int e)
	: name(n), code(c), ects(e) {}

const string& Course::get_name() const { return name; }
const string& Course::get_code() const { return code; }
int Course::get_ects() const { return ects; }

ostream& operator<<(ostream& os, const Course& c) {
	os << "Kolegij: " << c.name << " (" << c.code << "), ECTS: " << c.ects;
	return os;
}

istream& operator>>(istream& is, Course& c) {
	cout << "Unesi ime kolegija: ";
	is >> c.name;
	cout << "Unesi sifru kolegija: ";
	is >> c.code;
	cout << "Unesi ECTS: ";
	is >> c.ects;
	return is;
}
