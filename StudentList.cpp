/*
	Lerman, Josh (Team Leader)
	Craft, Mike // Member 2
	Nguyen, David // Member 3

	Fall 2026
	CS A250 - C++ 2

	Capstone Lab: Transcripts
*/

#include "StudentList.h"
#include <iostream>

using namespace std;

void StudentList::addStudent(const Student& student)
{
	Node* newNode = new Node(student, nullptr);

	if (first == nullptr)
		first = newNode;
	else
		last->setNext(newNode);

	last = newNode;
	++count;
}

int StudentList::getNoOfStudents() const
{
	return count;
}

void StudentList::printStudentByID(int id, double tuitionRate) const
{
	Node* current = first;

	while (current != nullptr && current->getStudent().getID() != id)
	{
		current = current->getNext();
	}

	if (current != nullptr)
		current->getStudent().printStudentInfo(tuitionRate);
	else
		cout << "Student ID " << id << " not found." << endl;
}

void StudentList::printStudentByName(const string& lastName) const
{
	Node* current = first;
	bool found = false;

	while (current != nullptr)
	{
		if (current->getStudent().getLastName() == lastName)
		{
			current->getStudent().printStudent();
			found = true;
		}
		current = current->getNext();
	}

	if (!found)
	{
		cout << "No students found with last name " << lastName << endl;
	}
}

void StudentList::printStudentsByCourse(const string& coursePrefix,
										int courseNumber) const
{
	Node* current = first;
	bool found = false;

	while (current != nullptr)
	{
		if (current->getStudent().isCourseCompleted(coursePrefix, courseNumber))
		{
			current->getStudent().printStudent();
			found = true;
		}
		current = current->getNext();
	}

	if (!found)
	{
		cout << "No students found for course " << coursePrefix << " "
			<< courseNumber << endl;
	}
}

void StudentList::printAllStudents(double tuitionRate) const
{
	Node* current = first;

	while (current != nullptr)
	{
		current->getStudent().printStudentInfo(tuitionRate);
		current = current->getNext();
	}
}

void StudentList::clearStudentList()
{
	while (first != nullptr)
	{
		Node* current = first;
		first = first->getNext();
		delete current;
	}

	last = nullptr;
	count = 0;
}

StudentList::~StudentList()
{
	if (first != nullptr)
		clearStudentList();
}