/*
	Lerman, Josh (Team Leader)
	Craft, Mike // Member 2
	Nguyen, David // Member 3

	Fall 2026
	CS A250 - C++ 2

	Capstone Lab: Transcripts
*/

#include "Student.h"
#include <iostream>

using namespace std;

void Student::setStudent(Student otherStudent)
{
    studentID = otherStudent.studentID;
    firstName = otherStudent.firstName;
    lastName = otherStudent.lastName;
    tuitionWasPaid = otherStudent.tuitionWasPaid;
    coursesCompleted = otherStudent.coursesCompleted;
    numberOfCourses = otherStudent.numberOfCourses;
}

int Student::getID() const
{
    return studentID;
}

string Student::getFirstName() const
{
    return firstName;
}

string Student::getLastName() const
{
    return lastName;
}

void Student::getName(string& first, string& last) const
{
    first = firstName;
    last = lastName;
}

int Student::getNumberOfCourse() const
{
    return numberOfCourses;
}

int Student::getUnitCompleted() const
{
    int totalUnits = 0;

    for (auto iter = coursesCompleted.begin();
         iter != coursesCompleted.end(); ++iter)
    {
        totalUnits += iter->first.getCourseUnits();
    }

    return totalUnits;
}

multimap<Course, char> Student::getCoursesCompleted() const
{
    return coursesCompleted;
}

bool Student::isTuitionPaid() const
{
    return tuitionWasPaid;
}

bool Student::isCourseCompleted(string coursePrefix, int courseNumber) const
{
    bool isMatching = false;

    for (auto iter = coursesCompleted.begin();
         iter != coursesCompleted.end(); ++iter)
    {
        if (iter->first.getCoursePrefix() == coursePrefix &&
            iter->first.getCourseNumber() == courseNumber)
        {
            isMatching = true;
        }
    }

    return isMatching;
}

double Student::calculateGPA() const
{
    double totalGpa = 0.0;

    for (auto iter = coursesCompleted.begin();
         iter != coursesCompleted.end(); ++iter)
    {
        int units = iter->first.getCourseUnits();
        char grade = iter->second;

        if (grade == 'A') totalGpa += units * 4.0;
        else if (grade == 'B') totalGpa += units * 3.0;
        else if (grade == 'C') totalGpa += units * 2.0;
        else if (grade == 'D') totalGpa += units * 1.0;
        else if (grade == 'F') totalGpa += units * 0.0;
    }

    double totalUnits = getUnitCompleted();

    if (totalUnits == 0.0)
    {
        return 0.0;
    }

    return totalGpa / totalUnits;
}

double Student::billingAmount(double tuitionRate) const
{
    return numberOfCourses * tuitionRate;
}

void Student::printStudent() const
{
    cout << "Student ID: " << getID() << endl;
    cout << "Last Name: " << getLastName() << endl;
    cout << "First Name: " << getFirstName() << endl;
}

void Student::printStudentInfo(double tuitionRate) const
{
    cout << "Student Name: " << getLastName() << ", "
         << getFirstName() << endl;

    cout << "Student ID: " << getID() << endl;
    cout << "Number of Courses: " << coursesCompleted.size() << endl;

    for (auto iter = coursesCompleted.begin();
         iter != coursesCompleted.end(); ++iter)
    {
        cout << iter->first.getCoursePrefix() << " "
             << iter->first.getCourseNumber() << " "
             << iter->first.getCourseUnits() << " units ";

        if (tuitionWasPaid)
            cout << "Grade: " << iter->second << endl;
        else
            cout << "Grade: ***" << endl;
    }

    cout << "Total Course Units: " << getUnitCompleted() << endl;

    if (tuitionWasPaid)
    {
        cout << "GPA: " << calculateGPA() << endl;
    }
    else
    {
        cout << "Grades are being held because tuition was not paid."
             << endl;

        cout << "Amount Due: $" << billingAmount(tuitionRate) << endl;
    }
}
