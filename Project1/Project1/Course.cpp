/*
	Lerman, Josh (Team Leader)
	Craft, Mike // Member 2
	Nguyen, David // Member 3

	Fall 2026
	CS A250 - C++ 2

	Capstone Lab: Transcripts
*/
#include "Course.h"
#include <string>

Course::Course() : coursePrefix(""), courseNumber(0), courseUnits(0) {}
void Course::setCourseInfo(std::string coursePrefix, int courseNumber, int courseUnits)
{
	this->coursePrefix = coursePrefix;
	this->courseNumber = courseNumber;
	this->courseUnits = courseUnits;
}
std::string Course::getCoursePrefix() const
{
	return coursePrefix;
}	
int Course::getCourseNumber() const
{
	return courseNumber;
}
int Course::getCourseUnits() const
{
	return courseUnits;
}
bool Course::operator<(const Course& otherCourse) const
{
	if (coursePrefix < otherCourse.coursePrefix)
	{
		return true;
	}
	else if (coursePrefix == otherCourse.coursePrefix)
	{
		if (courseNumber < otherCourse.courseNumber)
		{
			return true;
		}
	}
	return false;
}