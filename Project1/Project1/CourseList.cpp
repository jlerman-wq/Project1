/*
	Lerman, Josh (Team Leader)
	Craft, Mike // Member 2
	Nguyen, David // Member 3

	Fall 2026
	CS A250 - C++ 2

	Capstone Lab: Transcripts
*/
#include "CourseList.h"
#include <iostream>

void CourseList::addCourse(const Course& course)
{
	courses.insert(course);
}
void CourseList::printCourses() const
{
	for (const auto& course : courses)
	{
		std::cout << "Course: " << course.getCoursePrefix() << " " << course.getCourseNumber() << ", Units: " << course.getCourseUnits() << std::endl;
	}
	if (courses.empty())
	{
		std::cout << "Course List is Empty." << std::endl;
	}
}