/*
	Lerman, Joshua

	Fall 2026
	CS A250 - C++ 2

	Capstone Lab: Transcripts
*/

#include "CourseList.h"
#include "StudentList.h"

// Added for test cases
#include <iostream>

using namespace std;

int main()
{
	/*******************************************************
	*             DO NOT REMOVE THE COMMENTS               *
	********************************************************/

    // ===== COURSE =====

	// Create at least three Course objects.
	// Use the same prefix with different numbers for two courses,
	// and a different prefix for the third course.
	// Call setCourseInfo() to initialize each object.
	 

	// Test getCoursePrefix(), getCourseNumber(), and getCourseUnits().
	// Display the expected and actual values.


	// Test setCourseInfo() again by changing an existing course.
	// Verify that all three member variables were updated.


	// Test operator<() with different course prefixes.


	// Test operator<() with matching prefixes and different numbers.


	// Test operator<() with matching prefixes and numbers.
	// Verify that neither course is less than the other,
	// even when their units differ.


	// ===== COURSELIST =====

	// Create an empty CourseList object and test printCourses().


	// Test addCourse() by adding courses in an unsorted order.


	// Add a duplicate course with the same prefix and number.


	// Test printCourses() again.
	// Verify that courses appear in sorted order without duplicates.


	// ===== STUDENT =====

	  // Create a multimap containing several courses and grades
    Course c1("CS", 101, 3);
    Course c2("MATH", 200, 4);
    Course c3("ENG", 101, 3);
    Course c4("CS", 150, 2);

    multimap<Course, char> courses;

    courses.insert({c1, 'A'});
    courses.insert({c2, 'B'});
    courses.insert({c3, 'F'});
    courses.insert({c4, 'C'});

    // Create Student with paid tuition
    Student student1(1001, "David", "Smith", true, courses);

    // Create Student with unpaid tuition
    Student student2(1002, "John", "Doe", false, courses);

    // Create Student with empty courses
    multimap<Course, char> emptyCourses;
    Student student3(1003, "Alex", "Brown", true, emptyCourses);

    // Test getID(), getFirstName(), getLastName()
    cout << "\n===== GETTERS =====\n";

    cout << "Expected ID: 1001\n";
    cout << "Actual ID: " << student1.getID() << endl;

    cout << "Expected First Name: David\n";
    cout << "Actual First Name: " << student1.getFirstName() << endl;

    cout << "Expected Last Name: Smith\n";
    cout << "Actual Last Name: " << student1.getLastName() << endl;

    // Test getName()
    cout << "\n===== GET NAME =====\n";

    string first, last;
    student1.getName(first, last);

    cout << "First Name: " << first << endl;
    cout << "Last Name: " << last << endl;

    // Test getNumberOfCourse()
    cout << "\n===== NUMBER OF COURSES =====\n";

    cout << "Student 1 Expected: 4\n";
    cout << "Student 1 Actual: " << student1.getNumberOfCourse() << endl;

    cout << "Student 3 Expected: 0\n";
    cout << "Student 3 Actual: " << student3.getNumberOfCourse() << endl;

    // Test getCoursesCompleted()
    cout << "\n===== GET COURSES COMPLETED =====\n";

    multimap<Course, char> returnedCourses =
        student1.getCoursesCompleted();

    for (auto iter = returnedCourses.begin();
         iter != returnedCourses.end(); ++iter)
    {
        cout << iter->first.getCoursePrefix() << " "
             << iter->first.getCourseNumber() << " Grade: "
             << iter->second << endl;
    }

    // Modify returned multimap
    returnedCourses.clear();

    cout << "Returned multimap size: "
         << returnedCourses.size() << endl;

    cout << "Original Student course count: "
         << student1.getCoursesCompleted().size() << endl;

    // Test isTuitionPaid()
    cout << "\n===== TUITION STATUS =====\n";

    cout << "Student 1 Expected: 1\n";
    cout << "Student 1 Actual: " << student1.isTuitionPaid() << endl;

    cout << "Student 2 Expected: 0\n";
    cout << "Student 2 Actual: " << student2.isTuitionPaid() << endl;

    // Test getUnitCompleted()
    cout << "\n===== TOTAL UNITS =====\n";

    cout << "Student 1 Expected: 12\n";
    cout << "Student 1 Actual: " << student1.getUnitCompleted() << endl;

    cout << "Student 3 Expected: 0\n";
    cout << "Student 3 Actual: " << student3.getUnitCompleted() << endl;

    // Test isCourseCompleted()
    cout << "\n===== COURSE COMPLETED =====\n";

    cout << "CS 101 Expected: 1\n";
    cout << "Actual: " << student1.isCourseCompleted("CS", 101) << endl;

    cout << "CS 200 Expected: 0\n";
    cout << "Actual: " << student1.isCourseCompleted("CS", 200) << endl;

    cout << "MATH 101 Expected: 0\n";
    cout << "Actual: " << student1.isCourseCompleted("MATH", 101) << endl;


    // Test calculateGPA()
    cout << "\n===== GPA =====\n";

    cout << "Expected GPA: 2.5\n";
    cout << "Actual GPA: " << student1.calculateGPA() << endl;

    cout << "Empty Student Expected GPA: 0.0\n";
    cout << "Actual GPA: " << student3.calculateGPA() << endl;

    // Test billingAmount()
    cout << "\n===== BILLING AMOUNT =====\n";

    double tuitionRate = 150.0;

    // 4 courses * $150 = $600
    cout << "Expected: $600\n";
    cout << "Actual: $" << student2.billingAmount(tuitionRate) << endl;

    // Test setStudent()
    cout << "\n===== SET STUDENT =====\n";

    student3.setStudent(student1);

    cout << "Expected ID: 1001\n";
    cout << "Actual ID: " << student3.getID() << endl;

    cout << "Expected First Name: David\n";
    cout << "Actual First Name: " << student3.getFirstName() << endl;

    cout << "Expected Last Name: Smith\n";
    cout << "Actual Last Name: " << student3.getLastName() << endl;

    cout << "Expected Courses: 4\n";
    cout << "Actual Courses: "
         << student3.getCoursesCompleted().size() << endl;

    cout << "Expected Tuition Paid: 1\n";
    cout << "Actual Tuition Paid: " << student3.isTuitionPaid() << endl;

    // Test printStudent()
    cout << "\n===== PRINT STUDENT =====\n";

    student1.printStudent();

    // Test printStudentInfo() with paid tuition
    cout << "\n===== PAID TUITION INFO =====\n";

    student1.printStudentInfo(tuitionRate);

    // Test printStudentInfo() with unpaid tuition
    cout << "\n===== UNPAID TUITION INFO =====\n";

    student2.printStudentInfo(tuitionRate);

    // Test printStudentInfo() with no courses
    cout << "\n===== EMPTY STUDENT INFO =====\n";

    Student emptyStudent(1004, "Jane", "White", false, emptyCourses);

    emptyStudent.printStudentInfo(tuitionRate);

    return 0;
}

	// ===== NODE =====

	// Create two dynamic Node objects using existing Student objects.
	// Use nullptr as the next pointer when appropriate.


	// Test getStudent() by displaying the stored student's information.


	// Test setStudent() and verify that the stored student changed.


	// Test setNext() by linking the first node to the second node.


	// Test getNext() and verify that it returns the expected pointer.


	// Set the first node's next pointer to nullptr and verify it.


	// ===== STUDENTLIST =====

	// Create an empty StudentList object.


	// Test getNoOfStudents(). The expected result is 0.


	// Test all four printing functions on the empty list:
	// printStudentByID(), printStudentByName(),
	// printStudentsByCourse(), and printAllStudents().


	// Test clearStudentList() on the empty list.


	// Test addStudent() by adding the first student.
	// Verify that getNoOfStudents() returns 1.


	// Add more students, including paid and unpaid students.
	// Include two students with the same last name and
	// two students who share a course.


	// Test getNoOfStudents() again.
	// Verify that it matches the number of students added.


	// Test printStudentByID() for students at the beginning,
	// middle, and end of the list.


	// Test printStudentByID() with an ID that is not in the list.


	// Test printStudentByName() with a shared last name.
	// Verify that every matching student is displayed.


	// Test printStudentByName() with a last name not in the list.


	// Test printStudentsByCourse() with a shared course.
	// Verify that every matching student is displayed.


	// Test printStudentsByCourse() with a course that no
	// student has completed.


	// Test printAllStudents().
	// Verify that every student's information is displayed.


	// Test clearStudentList() on the populated list.
	// Verify that getNoOfStudents() returns 0.


	// Add a student after clearing the list.
	// Verify that insertion and printing still work correctly.


	// Clear the list again, then clear the already empty list.


	// Test the StudentList destructor by creating a local
	// StudentList inside a separate block, adding students,
	// and allowing the object to go out of scope without
	// explicitly calling clearStudentList().



	cout << endl;
	system("Pause");
	return 0;
}

