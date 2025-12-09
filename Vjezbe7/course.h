#pragma once
#include <string>
#include <iostream>

class Course {
	std::string name;
	std::string code;
	int ects;

public:
	Course();
	Course(const std::string& n, const std::string& c, int e);

	const std::string& get_name() const;
	const std::string& get_code() const;
	int get_ects() const;

	friend std::ostream& operator<<(std::ostream& os, const Course& c);
	friend std::istream& operator>>(std::istream& is, Course& c);
};
