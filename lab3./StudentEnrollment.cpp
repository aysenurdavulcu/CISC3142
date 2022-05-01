#include "headers/Student.h"
#include "headers/Term.h"
#include "headers/Course.h"
#include "StudentService.cpp"
#include <unordered_set>

class StudentEnrollment {
private:
  Student* student;
public:
  StudentEnrollment(std::string id, std::string courseId, char grade, std::string courseNumber, std::string sectionCode, Term term) {
    //create new course
    Course* course = new Course(courseId, courseNumber, sectionCode, term);
    //create new Student object
    student = new Student(id, course, grade);
    StudentService::getInstance()->addStudent(student);
  }
};