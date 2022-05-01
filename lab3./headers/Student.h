#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "Term.h"
#include "Course.h"
#include <string>

struct Student {
  std::string id;
  Course* course;
  char grade;

  Student(std::string id, Course* course, char grade) {    
    this->id = id;
    this->course = course;
    this->grade = grade;
  }
};

#endif