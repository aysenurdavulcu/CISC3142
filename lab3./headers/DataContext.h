#ifndef __DATA_CONTEXT_H__
#define __DATA_CONTEXT_H__

#include <string>

struct DataContext {
  std::string studentId;
  std::string courseNumber;
  std::string instructorId;
  std::string sectionId;
  char grade;

  DataContext(std::string studentId, std::string courseNumber, std::string instructorId, std::string sectionId, char grade) {
    this->studentId = studentId;
    this->courseNumber = courseNumber;
    this->instructorId = instructorId;
    this->sectionId = sectionId;
    this->grade = grade;
  }
};



#endif
