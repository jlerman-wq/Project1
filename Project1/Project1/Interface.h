/*
	Lerman, Josh (Team Leader)
	Craft, Mike // Member 2
	Nguyen, David // Member 3

	Fall 2026
	CS A250 - C++ 2

	Capstone Lab: Transcripts
*/

#ifndef INTERFACE_H
#define INTERFACE_H

#include "CourseList.h"
#include "StudentList.h"

void runInterface(const CourseList& courseList,
	const StudentList& studentList, double tuitionRate);

void displayMenu();

void processChoice(const CourseList& courseList,
	const StudentList& studentList, double tuitionRate);

#endif
