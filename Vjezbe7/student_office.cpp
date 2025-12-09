#include "student_office.h"
using namespace std;

void StudentOffice::moveStudent(Student& s, string new_program) {
	s.study_program = move(new_program);
}

void StudentOffice::enroll_student(Student& s, const Course& c) {
	if (s.get_total_enrolled_ects() + c.get_ects() <= UniversityConstants::MAX_ECTS_PER_YEAR)
		s += c;
}

void StudentOffice::process_exam_results(Student& s, const Course& c) {
	Course* tmp = new Course[s.completed_count + 1];
	for (size_t i = 0; i < s.completed_count; i++) tmp[i] = s.completed_courses[i];
	tmp[s.completed_count] = c;
	delete[] s.completed_courses;
	s.completed_courses = tmp;
	s.completed_count++;
}

void StudentOffice::update_student_years(Student* arr, size_t count) {
	for (size_t i = 0; i < count; i++) arr[i]++;
}
