/*
	Lerman, Josh (Team Leader)
	Craft, Mike // Member 2
	Nguyen, David // Member 3

	Fall 2026
	CS A250 - C++ 2

	Capstone Lab: Transcripts
*/

#ifndef STUDENT_H
#define STUDENT_H

#include <map>
#include <string>
#include "Course.h"


class Student
{
    public:

        Student(int id, std::string aFirstName, std::string aLastName, bool isTPaid, 
            std::multimap<Course, char> courses) : 

      studentID(id),
      firstName(aFirstName),
      lastName(aLastName),
      tuitionWasPaid(isTPaid),
      coursesCompleted(course),
      numberOfCourses(course.size())
{
}

            
            
        
        void setStudent(Student otherStudent);
        int getID() const;
        std::string getFirstName() const;
        std::string getLastName() const;
        void getName(std::string& first, std::string& last) const;
        int getNumberOfCourse() const;
        int getUnitCompleted() const;
        std::multimap<Course, char> getCoursesCompleted() const;
        bool isTuitionPaid() const;
        bool isCourseCompleted(std::string coursePrefix, int courseNumber) const;
        double calculateGPA() const;
        double billingAmount(double tuitionRate) const;
        void printStudent() const;
        void printStudentInfo(double tuitionRate) const;




    private:
    
        int studentID, numberOfCourses;
        std::string firstName, lastName;
        bool tuitionWasPaid;
        std::multimap<Course, char> coursesCompleted;
};

#endif 