/*
	Lerman, Josh (Team Leader)
	Craft, Mike // Member 2
	Nguyen, David // Member 3

	Fall 2026
	CS A250 - C++ 2

	Capstone Lab: Transcripts
*/

#include "Interface.h"
#include "OutputHandler.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

void runInterface(const CourseList& courseList,
	const StudentList& studentList, double tuitionRate)
{
	displayMenu();
	processChoice(courseList, studentList, tuitionRate);
}

void displayMenu()
{
	cout << "**************************************\n"
		 << "            MAIN MENU\n"
		 << "**************************************\n"
		 << " => Select one of the following:\n\n"
		 << "    1: Print all students\n"
		 << "    2: Print student information\n"
		 << "    3: Search student by last name\n"
		 << "    4: Print students by course\n"
		 << "    5: Print students on hold\n"
		 << "    6: Print students to file\n"
		 << "    7: To exit\n";
}

void processChoice(const CourseList& courseList,
	const StudentList& studentList, double tuitionRate)
{
	int choice = 0;
	
	cout << fixed << showpoint << setprecision(2);

	do
	{
		cout << "\n => Enter your choice: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:
			studentList.printAllStudents(tuitionRate);
			break;

		case 2:
		{
			int studentID = 0;
			cout << " => Please enter student's ID: ";
			cin >> studentID;
			cout << endl;

			studentList.printStudentByID(studentID, tuitionRate);
			break;
		}

		case 3:
		{
			string lastName;
			cout << " => Please enter the student's last name: ";
			cin >> lastName;
			cout << endl;

			studentList.printStudentByName(lastName);
			break;
		}

		case 4:
		{
			courseList.printCourses();

			string coursePrefix;
			cout << "\n => Please enter the course prefix: ";
			cin >> coursePrefix;

			int courseNumber = 0;
			cout << " => Please enter the course number: ";
			cin >> courseNumber;
			cout << endl;

			studentList.printStudentsByCourse(coursePrefix, courseNumber);
			break;
		}

		case 5:
			studentList.printStudentsOnHold(tuitionRate);
			break;

		case 6:
			printAllStudentsToFile(studentList, tuitionRate);
			break;

		case 7:
			cout << " => Thank you for using the OCC Gradebook."
				<< "  => Good-bye!" << endl;
			break;

		default:
			cout << " => Sorry. That is not a selection." << endl;
			break;
		}

		if (choice != 7)
		{
			cout << "\n => ";
			system("Pause");
			cout << endl;
			displayMenu();
		}
	} while (choice != 7);
}