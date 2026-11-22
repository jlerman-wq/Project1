/*
	Lerman, Josh (Team Leader)
	Craft, Mike // Member 2
	Nguyen, David // Member 3

	Fall 2026
	CS A250 - C++ 2

	Capstone Lab: Transcripts
*/

#include "Course.h"
#include "CourseList.h"
#include "Student.h"
#include "StudentList.h"
#include <iostream>

using namespace std;

int main()
{
	/*******************************************************
	*             DO NOT REMOVE THE COMMENTS               *
	********************************************************/

	// ===== COURSE =====

	cout << "===== COURSE =====\n";

   // Create at least three Course objects.
   // Use the same prefix with different numbers for two courses,
   // and a different prefix for the third course.
   // Call setCourseInfo() to initialize each object.
	Course course1, course2, course3, course4;
	course1.setCourseInfo("CS", 100, 3);
	course2.setCourseInfo("MATH", 101, 3);
	course3.setCourseInfo("CS", 101, 4);
	course4.setCourseInfo("CS", 150, 2);


	// Test getCoursePrefix(), getCourseNumber(), and getCourseUnits().
	// Display the expected and actual values.
	cout << "Expected Prefix: CS, Actual: " << course1.getCoursePrefix() << endl;
	cout << "Expected Number: 100, Actual: " << course1.getCourseNumber() << endl;
	cout << "Expected Units: 3, Actual: " << course1.getCourseUnits() << endl;


	// Test setCourseInfo() again by changing an existing course.
	// Verify that all three member variables were updated.
	course1.setCourseInfo("CS", 102, 4);
	cout << "After update - Prefix: " << course1.getCoursePrefix() << ", Number: " << course1.getCourseNumber() << ", Units: " << course1.getCourseUnits() << std::endl;


	// Test operator<() with different course prefixes.
	course1.setCourseInfo("BIO", 100, 3);
	course2.setCourseInfo("CS", 100, 3);

	cout << "Is BIO 100 < CS 100? Expected: 1, Actual: " << (course1 < course2) << endl;

	cout << "Is CS 100 < BIO 100? Expected: 0, Actual: " << (course2 < course1) << endl;


	// Test operator<() with matching prefixes and different numbers.

	course1.setCourseInfo("CS", 100, 3);
	course2.setCourseInfo("CS", 101, 3);

	cout << "Is CS 100 < CS 101? Expected: 1, Actual: " << (course1 < course2) << endl;

	cout << "Is CS 101 < CS 100? Expected: 0, Actual: " << (course2 < course1) << endl;


	// Test operator<() with matching prefixes and numbers.
	// Verify that neither course is less than the other,
	// even when their units differ.
	course1.setCourseInfo("CS", 100, 3);
	course2.setCourseInfo("CS", 100, 4);
	course3.setCourseInfo("CS", 100, 2);

	cout << "Is CS 100 (3 units) < CS 100 (4 units)? Expected: 0, Actual: " << (course1 < course2) << endl;

	cout << "Is CS 100 (4 units) < CS 100 (3 units)? Expected: 0, Actual: " << (course2 < course1) << endl;

	cout << "Is CS 100 (3 units) < CS 100 (2 units)? Expected: 0, Actual: " << (course1 < course3) << endl;

	cout << "Is CS 100 (2 units) < CS 100 (3 units)? Expected: 0, Actual: " << (course3 < course1) << endl;

	// ===== COURSELIST =====

	cout << "\n===== COURSELIST =====\n";

	// Create an empty CourseList object and test printCourses().
	course1.setCourseInfo("CS", 100, 3);
	course2.setCourseInfo("MATH", 101, 3);
	course3.setCourseInfo("CS", 101, 4);
	cout << endl;
	cout << "Testing printCourses() on an empty CourseList:" << endl;
	CourseList courseList;
	courseList.printCourses();



	// Test addCourse() by adding courses in an unsorted order.
	courseList.addCourse(course2);
	courseList.addCourse(course1);
	courseList.addCourse(course3);
	cout << "Courses added to CourseList." << endl;

	// Add a duplicate course with the same prefix and number.
	courseList.addCourse(course2);
	courseList.addCourse(course2);
	cout << "Duplicate courses added to CourseList." << endl;


	// Test printCourses() again.
	// Verify that courses appear in sorted order without duplicates.
	cout << "Testing printCourses() after adding courses:" << endl;
	courseList.printCourses();


	// ===== STUDENT =====

	cout << "\n===== STUDENT =====\n";

	  // Create a multimap containing several courses and grades
    course1.setCourseInfo("CS", 101, 3);
    course2.setCourseInfo("MATH", 200, 4);
    course3.setCourseInfo("ENG", 101, 3);
    course4.setCourseInfo("CS", 150, 2);

    multimap<Course, char> courses;

    courses.insert({course1, 'A'});
    courses.insert({course2, 'B'});
    courses.insert({course3, 'F'});
    courses.insert({course4, 'C'});

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

	
	// ===== NODE =====
		cout << "\n===== NODE =====\n";

	// Create two dynamic Node objects using existing Student objects.
	// Use nullptr as the next pointer when appropriate.
		Node* node1 = new Node(student1, nullptr);
		cout << "Node 1 created with Student ID: " << node1->getStudent().getID() << endl;
		Node* node2 = new Node(student2, nullptr);
		cout << "Node 2 created with Student ID: " << node2->getStudent().getID() << endl;

	// Test getStudent() by displaying the stored student's information.
		node1->getStudent().printStudent();
		cout << "Node 1 Student ID: " << node1->getStudent().getID() << endl;

	// Test setStudent() and verify that the stored student changed.
		node1->setStudent(student2);
		cout << "After setStudent(), Node 1 Student ID: " << node1->getStudent().getID() << endl;
		node1->getStudent().printStudent();
		cout << "Node 1 Student ID: " << node1->getStudent().getID() << endl;


	// Test setNext() by linking the first node to the second node.
		node1->setNext(node2);
		cout << "Node 1 next pointer set to Node 2." << endl;

	// Test getNext() and verify that it returns the expected pointer.
		node1->getNext()->getStudent().printStudent();
		cout << "Node 1 next pointer Student ID: " << node1->getNext()->getStudent().getID() << endl;

	// Set the first node's next pointer to nullptr and verify it.
		node1->setNext(nullptr);
		cout << "Node 1 next pointer set to nullptr." << endl;

	delete node1;
	delete node2;
	node1 = nullptr;
	node2 = nullptr;

	// ===== STUDENTLIST =====

		cout << "\n===== STUDENTLIST =====\n";

	// Create an empty StudentList object.
		StudentList studentList;

	// Test getNoOfStudents(). The expected result is 0.
		studentList.getNoOfStudents();
		cout << "Expected number of students: 0, Actual: " << studentList.getNoOfStudents() << endl;

	// Test all four printing functions on the empty list:
	// printStudentByID(), printStudentByName(),
	// printStudentsByCourse(), and printAllStudents().
		studentList.printStudentByID(1001, tuitionRate);
		studentList.printStudentByName("Smith");
		studentList.printStudentsByCourse("CS", 101);
		studentList.printAllStudents(tuitionRate);
		cout << "All printing functions tested on empty StudentList." << endl;


	// Test clearStudentList() on the empty list.
		studentList.clearStudentList();
		cout << "clearStudentList() called on empty StudentList." << endl;

	// Test addStudent() by adding the first student.
	// Verify that getNoOfStudents() returns 1.
		studentList.addStudent(student1);
		cout << "Student 1 added to StudentList." << endl;
		studentList.getNoOfStudents();
		cout << "Expected number of students: 1, Actual: " << studentList.getNoOfStudents() << endl;


	// Add more students, including paid and unpaid students.
	// Include two students with the same last name and
	// two students who share a course.
		studentList.addStudent(student2);
		studentList.addStudent(student3);
		cout << "Student 2 and Student 3 added to StudentList." << endl;

	// Test getNoOfStudents() again.
	// Verify that it matches the number of students added.
		studentList.getNoOfStudents();
		cout << "Expected number of students: 3, Actual: " << studentList.getNoOfStudents() << endl;

	// Test printStudentByID() for students at the beginning,
	// middle, and end of the list.
		studentList.printStudentByID(1001, tuitionRate);
		studentList.printStudentByID(1002, tuitionRate);
		studentList.printStudentByID(1003, tuitionRate);
		cout << "printStudentByID() tested for students at beginning, middle, and end of list." << endl;

	// Test printStudentByID() with an ID that is not in the list.
		studentList.printStudentByID(1004, tuitionRate);
		cout << "printStudentByID() tested with an ID not in the list." << endl;

	// Test printStudentByName() with a shared last name.
	// Verify that every matching student is displayed.
		studentList.printStudentByName("Smith");
		cout << "printStudentByName() tested with a shared last name." << endl;

	// Test printStudentByName() with a last name not in the list.
		studentList.printStudentByName("Johnson");
		cout << "printStudentByName() tested with a last name not in the list." << endl;

	// Test printStudentsByCourse() with a shared course.
	// Verify that every matching student is displayed.
		studentList.printStudentsByCourse("CS", 101);
		cout << "printStudentsByCourse() tested with a shared course." << endl;

	// Test printStudentsByCourse() with a course that no
	// student has completed.
		studentList.printStudentsByCourse("MATH", 101);
		cout << "printStudentsByCourse() tested with a course that no student has completed." << endl;

	// Test printAllStudents().
	// Verify that every student's information is displayed.
		studentList.printAllStudents(tuitionRate);
		cout << "printAllStudents() tested, all students displayed." << endl;

	// Test clearStudentList() on the populated list.
	// Verify that getNoOfStudents() returns 0.
		studentList.clearStudentList();
		cout << "clearStudentList() called on populated StudentList." << endl;
		cout << "Expected number of students: 0, Actual: " << studentList.getNoOfStudents() << endl;

	// Add a student after clearing the list.
	// Verify that insertion and printing still work correctly.
		studentList.addStudent(student1);
		cout << "Student 1 added to StudentList after clearing." << endl;

	// Clear the list again, then clear the already empty list.
		studentList.clearStudentList();
		studentList.clearStudentList();
		cout << "clearStudentList() called on already cleared StudentList." << endl;

	// Test the StudentList destructor by creating a local
	// StudentList inside a separate block, adding students,
	// and allowing the object to go out of scope without
	// explicitly calling clearStudentList().
		StudentList destructorTestList;
		destructorTestList.addStudent(student1);
		destructorTestList.addStudent(student2);

		cout << "Students before destructor test: "
			<< destructorTestList.getNoOfStudents() << endl;

	cout << endl;
	system("Pause");
	return 0;
}

