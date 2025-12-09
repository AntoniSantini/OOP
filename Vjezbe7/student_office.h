#pragma once
#include "student.h"
using namespace std;

class StudentOffice {
public:
	void moveStudent(Student& s, string new_program);
	void enroll_student(Student& s, const Course& c);
	void process_exam_results(Student& s, const Course& c);
	void update_student_years(Student* arr, size_t count);
};
