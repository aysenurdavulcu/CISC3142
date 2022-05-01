#ifndef __COURSE_H__
#define __COURSE_H__

#include "Term.h"
#include <string>

struct Course {
  std::string id;
  std::string courseNumber;
  std::string sectionCode;
  Term term;

  Course(std::string id, std::string courseNumber, std::string sectionCode, Term term) {
    this->id = id;
    this->courseNumber = courseNumber;
    this->sectionCode = sectionCode;
    this->term = term;
  }
};

#endif