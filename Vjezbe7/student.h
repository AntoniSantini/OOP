#pragma once
#include <string>
#include <iostream>
#include "course.h"
#include "university_constants.h"
using namespace std;

class StudentOffice;

class Student {
	int id;
	string name;
	string study_program;
	int year;

	Course* enrolled_courses;
	size_t enrolled_count;

	Course* completed_courses;
	size_t completed_count;

	static int total_students;

public:
	Student(int id, const string& n, const string& sp, int y);
	Student(const Student& o);
	Student(Student&& o) noexcept;
	Student& operator=(const Student& o);
	Student& operator=(Student&& o) noexcept;
	~Student();

	friend ostream& operator<<(ostream&, const Student&);
	friend istream& operator>>(istream&, Student&);

	Student& operator+=(const Course& c);
	Student& operator++();
	Student operator++(int);

	int get_total_enrolled_ects() const;
	int get_total_completed_ects() const;

	static int get_total_students();

	friend class StudentOffice;
};
