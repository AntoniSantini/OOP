#include "student.h"
using namespace std;

int Student::total_students = 0;

Student::Student(int id, const string& n, const string& sp, int y)
	: id(id), name(n), study_program(sp), year(y),
	enrolled_courses(nullptr), enrolled_count(0),
	completed_courses(nullptr), completed_count(0)
{
	total_students++;
}

Student::Student(const Student& o)
	: id(o.id), name(o.name), study_program(o.study_program), year(o.year),
	enrolled_count(o.enrolled_count), completed_count(o.completed_count)
{
	enrolled_courses = new Course[enrolled_count];
	completed_courses = new Course[completed_count];

	for (size_t i = 0; i < enrolled_count; i++) enrolled_courses[i] = o.enrolled_courses[i];
	for (size_t i = 0; i < completed_count; i++) completed_courses[i] = o.completed_courses[i];

	total_students++;
}

Student::Student(Student&& o) noexcept
	: id(o.id), name(move(o.name)), study_program(move(o.study_program)),
	year(o.year), enrolled_courses(o.enrolled_courses),
	enrolled_count(o.enrolled_count), completed_courses(o.completed_courses),
	completed_count(o.completed_count)
{
	o.enrolled_courses = nullptr;
	o.completed_courses = nullptr;
	o.enrolled_count = 0;
	o.completed_count = 0;

	total_students++;
}

Student& Student::operator=(const Student& o) {
	if (this == &o) return *this;

	delete[] enrolled_courses;
	delete[] completed_courses;

	id = o.id;
	name = o.name;
	study_program = o.study_program;
	year = o.year;

	enrolled_count = o.enrolled_count;
	completed_count = o.completed_count;

	enrolled_courses = new Course[enrolled_count];
	completed_courses = new Course[completed_count];

	for (size_t i = 0; i < enrolled_count; i++) enrolled_courses[i] = o.enrolled_courses[i];
	for (size_t i = 0; i < completed_count; i++) completed_courses[i] = o.completed_courses[i];

	return *this;
}

Student& Student::operator=(Student&& o) noexcept {
	if (this == &o) return *this;

	delete[] enrolled_courses;
	delete[] completed_courses;

	id = o.id;
	name = move(o.name);
	study_program = move(o.study_program);
	year = o.year;

	enrolled_courses = o.enrolled_courses;
	enrolled_count = o.enrolled_count;
	completed_courses = o.completed_courses;
	completed_count = o.completed_count;

	o.enrolled_courses = nullptr;
	o.completed_courses = nullptr;
	o.enrolled_count = 0;
	o.completed_count = 0;

	return *this;
}

Student::~Student() {
	delete[] enrolled_courses;
	delete[] completed_courses;
	total_students--;
}

ostream& operator<<(ostream& os, const Student& s) {
	os << "Student: " << s.name << " (" << s.id << ") "
		<< "Smjer: " << s.study_program
		<< " Godina: " << s.year
		<< " Upisani ECTS: " << s.get_total_enrolled_ects()
		<< " Polozeni ECTS: " << s.get_total_completed_ects() << "\n";
	return os;
}

istream& operator>>(istream& is, Student& s) {
	cout << "Unesi ID: "; is >> s.id;
	cout << "Unesi ime: "; is >> s.name;
	cout << "Unesi smjer: "; is >> s.study_program;
	cout << "Unesi godinu: "; is >> s.year;
	return is;
}

Student& Student::operator+=(const Course& c) {
	Course* tmp = new Course[enrolled_count + 1];
	for (size_t i = 0; i < enrolled_count; i++) tmp[i] = enrolled_courses[i];
	tmp[enrolled_count] = c;
	delete[] enrolled_courses;
	enrolled_courses = tmp;
	enrolled_count++;
	return *this;
}

Student& Student::operator++() {
	if (get_total_completed_ects() >= UniversityConstants::REQUIRED_ECTS_PER_YEAR)
		year++;
	return *this;
}

Student Student::operator++(int) {
	Student temp = *this;
	++(*this);
	return temp;
}

int Student::get_total_enrolled_ects() const {
	int sum = 0;
	for (size_t i = 0; i < enrolled_count; i++) sum += enrolled_courses[i].get_ects();
	return sum;
}

int Student::get_total_completed_ects() const {
	int sum = 0;
	for (size_t i = 0; i < completed_count; i++) sum += completed_courses[i].get_ects();
	return sum;
}

int Student::get_total_students() { return total_students; }
