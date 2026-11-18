/*
	Lerman, Josh (Team Leader)
	Craft, Mike // Member 2
	Nguyen, David // Member 3

	Fall 2026
	CS A250 - C++ 2

	Capstone Lab: Transcripts
*/

#include "StudentList.h"

using namespace std;
void StudentList::addStudent(Student student)
{
	Node* newNode = new Node(student, nullptr);
	if (first == nullptr)
	{
		first = newNode;
		last = newNode;
		
	}
	else
	{
		last->setNext(newNode);
		last = newNode;
	}
	++count;
}
int StudentList::getNoOfStudents()
{
	return count;
}
void StudentList::printStudentsByID(int id, double tuitionRate)
{
	Node* current = first;

	while (current != nullptr)
	{
		if (current->getStudent().getID() == id)
		{

		}
	}
}
void StudentList::printStudentByName(string lastName)
{

}
void StudentList::printStudentsByCourse(string coursePrefix, int courseNumber)
{

}
void StudentList::printAllStudents(double tuitionRate)
{

}
void StudentList::clearStudentList()
{

}
StudentList::~StudentList()
{
	if (first != nullptr)
		clearStudentList();
}