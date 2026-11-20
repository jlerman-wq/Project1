/*
	Lerman, Josh (Team Leader)
	Craft, Mike // Member 2
	Nguyen, David // Member 3

	Fall 2026
	CS A250 - C++ 2

	Capstone Lab: Transcripts
*/
#ifndef COURSELIST_H
#define COURSELIST_H

#include <set>
#include "Course.h"

class CourseList
{
private:
	std::set<Course> courses;
public:
	void addCourse(const Course& course);
	void printCourses() const;
};

#endif