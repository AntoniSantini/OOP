#include <iostream>
#include <vector>
#include "student.h"
#include "student_office.h"
#include "university_constants.h"
#include "course.h"
using namespace std;

int main() {
	Course oop("Objektno Programiranje", "OOP101", 5);
	Course alg("Algoritmi", "ALG201", 5);

	Student s1(1, "Ante", "Racunarsvo", 1);
	Student s2(2, "Marko", "Informatika", 1);

	vector<Student> studenti = { s1, s2 };

	StudentOffice office;

	office.enroll_student(studenti[0], oop);
	office.enroll_student(studenti[0], alg);
	office.enroll_student(studenti[1], oop);

	office.process_exam_results(studenti[0], oop);
	office.process_exam_results(studenti[0], alg);
	office.process_exam_results(studenti[1], oop);

	office.update_student_years(studenti.data(), studenti.size());

	for (auto& s : studenti) cout << s;

	cout << "Ukupno studenata: " << Student::get_total_students() << "\n";
	UniversityConstants::print_university_rules();

	return 0;
}
