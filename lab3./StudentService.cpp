#include "headers/Student.h"
#include <set>
#include <stdexcept> 

class StudentService {
private:
  static StudentService* studentService;
  std::set<Student*> studentsList;
  StudentService() {}
  

public:
  static StudentService* getInstance() {
    if(studentService == nullptr) {
      studentService = new StudentService;
    }
    return studentService;
  }

  void addStudent(Student* student) {
    studentsList.insert(student);
  }

  void updateGrade(Student* student, char grade) {
    if(studentsList.find(student) != studentsList.end()) {
      student->grade = grade;
    } else {
      throw std::runtime_error("Student does not exist");
    }
  }
  

};