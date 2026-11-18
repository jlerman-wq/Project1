#include "Student.h"

using namespace std;
        
void setStudent(Student otherStudent)
{
    studentID = otherStudent.studentID;
    firstName = otherStudent.firstName;
    lastName = otherStudent.lastName;
    tuitionWasPaid = otherStudent.tuitionWasPaid;
    coursesCompleted = otherStudent.coursesCompleted;
    numberOfCourses = otherStudent.numberOfCourses;
}

int getID() const
{
    return studentID;
}

std::string getFirstName() const
{
    return firstName;
}

std::string getLastName() const
{
    return lastName;
}

void getName(std::string& first, std::string& last) const
{
    firstName = first;
    lastName = last;
}

int getNumberOfCourse() const
{
    return numberOfCourses;
}

int getUnitCompleted() const
{
    int totalUnits = 0;
    for (auto iter = courseCompleted.begin(); iter != courseCompleted.end(); ++iter)
    {
        totalUnit += iter->first.getCourseUnits();
    }
    return totalUnits;
}

std::multimap<Course, char> getCoursesCompleted() const
{
    return coursesCompleted;
}

bool isTuitionPaid() const
{
    return tuitionWasPaid;
}

bool isCourseCompleted(std::string coursePrefix, int courseNumber) const
{
    bool isMatching = false;

    if (numberOfCourses != 0)
    {

        for (auto iter = coursesCompleted.begin(); iter != coursesCompleted.end(); ++iter)
        {
            if (iter->first.getCoursePrefix() == coursePrefix && 
                iter->first.getCourseNumber() == courseNumber)
                {
                    isMatching = true;
                }
        }

        
    }
    return isMatching;
}

double calculateGPA() const
{
    double totalGpa = 0.0;
    for (auto iter = courseCompleted.begin(); iter != courseCompleted.end(); ++iter)
    {
        int units = iter->first.getCourseUnits();
        char grade = iter->second;

        if (grade == 'A') totalGpa += units * 4.0;
        if (grade == 'B') totalGpa += units * 3.0;
        if (grade == 'C') totalGpa += units * 2.0;
        if (grade == 'D') totalGpa += units * 1.0;
        if (grade == 'F') totalGpa += units * 0.0;
        
    }

    double totalUnits = getUnitCompleted();
    if (totalUnits = 0.0) {return 0.0;}
    else
    {
        return totalGpa / totalUnit;
    }

}
double billingAmount(double tuitionRate) const
{
    return numberOfCourses * tuitionRate;
}
void printStudent() const
{
    
}
void printStudentInfo(double tuitionRate) const;
