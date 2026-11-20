/*
	Lerman, Josh (Team Leader)
	Craft, Mike // Member 2
	Nguyen, David // Member 3

	Fall 2026
	CS A250 - C++ 2

	Capstone Lab: Transcripts
*/
#ifndef COURSE_H
#define COURSE_H

#include <string>

class Course
{
private:
	std::string coursePrefix;
	int courseNumber;
	int courseUnits;

public:
	Course();
	void setCourseInfo(std::string coursePrefix, int courseNumber, int courseUnits);
	std::string getCoursePrefix() const;
	int getCourseNumber() const;
	int getCourseUnits() const;
	bool operator<(const Course& otherCourse) const;

};

#endif
