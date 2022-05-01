#include "headers/DataContext.h"
#include "FileReader.cpp"
#include <unordered_map>
#include <unordered_set>

static std::string insIdCol = "instructorid";
static std::string gradeCol = "grade";
static std::string termCol = "termid";
static std::unordered_set<std::string> passGrades;
static std::unordered_set<std::string> fallTerm;
static std::unordered_set<std::string> springTerm;

class DataUtility {


public:

  static void static_init() {
    passGrades.insert("A+"); passGrades.insert("A");
    passGrades.insert("B+"); passGrades.insert("B");
    passGrades.insert("C+"); passGrades.insert("C");
    passGrades.insert("D+"); passGrades.insert("D");
    fallTerm.insert("T04"); fallTerm.insert("T08");
    fallTerm.insert("T12"); fallTerm.insert("T16");
    fallTerm.insert("T20"); fallTerm.insert("T23");
    springTerm.insert("T02"); springTerm.insert("T06");
    springTerm.insert("T10"); springTerm.insert("T14");
    springTerm.insert("T18"); springTerm.insert("T21");
    
    
  }

  double getPassRateForInstructor(std::string instructorId) {
    
    instructorToGradeCountMap.clear();
    update("data/1115.csv");
    double passCount = 0;
    double failCount = 0;
    std::unordered_map<std::string, int> gradeCount = instructorToGradeCountMap[instructorId];
    for(auto it : gradeCount) {
        
        string grade = it.first;
        if(passGrades.find(grade) == passGrades.end()) {
          failCount = failCount + it.second;
        } else {
          passCount = passCount + it.second;
        }
    }
    double res = passCount/(passCount + failCount);
    return res;
  }  

  double getWRateForInstructor(std::string instructorId) {
    instructorToGradeCountMap.clear();
    update("data/1115.csv");
    double wCount = 0;
    double otherCount = 0;
    std::unordered_map<std::string, int> gradeCount = instructorToGradeCountMap[instructorId];
    for(auto it : gradeCount) {
        string grade = it.first;
        if(grade == "W") {
         
          wCount = wCount + it.second;
        } else {
          otherCount = otherCount + it.second;
        }
    }
    double res = wCount/(wCount + otherCount);
    return res;
  }  

double getSpringVsFallPassRate(string courseName) {
  termToGradeCountMap.clear();
  update("data/" + courseName + ".csv");
  double fallPassRate, springPassRate;
  double fallPassCount = 0, springPassCount = 0;
  double fallFailCount = 0, springFailCount = 0; 
  for(auto itr : termToGradeCountMap) {
    if(springTerm.find(itr.first) != springTerm.end()) {
      std::unordered_map<std::string, int> gradeCount = termToGradeCountMap[itr.first];
      for(auto it : gradeCount) {
        string grade = it.first;
        if(passGrades.find(grade) == passGrades.end()) {
          springFailCount = springFailCount + it.second;
        } else {
          springPassCount = springPassCount + it.second;
        }
      }
    } else if(fallTerm.find(itr.first) != fallTerm.end()) {
      
      std::unordered_map<std::string, int> gradeCount = termToGradeCountMap[itr.first];
      for(auto it : gradeCount) {
        string grade = it.first;
        if(passGrades.find(grade) == passGrades.end()) {
          fallFailCount = fallFailCount + it.second;
        } else {
          fallPassCount = fallPassCount + it.second;
        }
      }
    } else {
      //ignore for now.
    }
  }
  fallPassRate = fallPassCount/ (fallPassCount + fallFailCount);
  springPassRate = springPassCount / (springPassCount + springFailCount);
  return (fallPassRate/springPassRate);
}

private:
  std::unordered_map<std::string , std::unordered_map<std::string, int>> instructorToGradeCountMap;
  std::unordered_map<std::string , std::unordered_map<std::string, int>> termToGradeCountMap;

  
  void update(string fileName) {
    vector<std::string> instructorIds;
    vector<std::string> grades;
    vector<std::string> termIds;
    FileReader* fileReader = FileReader::getInstance();
    vector<std::pair<std::string, std::vector<string>>> allValues = fileReader->read_csv(fileName);
    for(std::pair<std::string, std::vector<string>> colToValues : allValues) {
      std::string colName = colToValues.first;
      if(colName.compare(insIdCol) == 0) {
        instructorIds = colToValues.second;
      } else if(colName.compare(gradeCol) == 0) {
        grades = colToValues.second;
      } else if(colName.compare(termCol) == 0) {
        termIds = colToValues.second;
      }
    } 
    for(int index = 0; index < instructorIds.size(); index++) {
      std::string instructorId = instructorIds.at(index);
      std::string grade = grades.at(index);
      if(instructorToGradeCountMap.find(instructorId) != instructorToGradeCountMap.end()) {
        std::unordered_map<std::string, int>& gradeCountMap = instructorToGradeCountMap[instructorId];
        if(gradeCountMap.find(grade) != gradeCountMap.end()) {
          gradeCountMap[grade]++;
        } else {
          gradeCountMap.insert({grade,1});
        }
      } else {
        std::unordered_map<std::string, int> gradeCountMap;
        gradeCountMap.insert({grade,1});
        instructorToGradeCountMap.insert({instructorId, gradeCountMap});
      }
    } 

     for(int index = 0; index < termIds.size(); index++) {
      std::string termId = termIds.at(index);
      std::string grade = grades.at(index);
      if(termToGradeCountMap.find(termId) != termToGradeCountMap.end()) {
        std::unordered_map<std::string, int>& gradeCountMap = termToGradeCountMap[termId];
        if(gradeCountMap.find(grade) != gradeCountMap.end()) {
          gradeCountMap[grade]++;
        } else {
          gradeCountMap.insert({grade,1});
        }
      } else {
        std::unordered_map<std::string, int> gradeCountMap;
        gradeCountMap.insert({grade, 1});
        termToGradeCountMap.insert({termId, gradeCountMap});
      }
    }
  }
};