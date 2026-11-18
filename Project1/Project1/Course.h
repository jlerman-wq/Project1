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

//hgf