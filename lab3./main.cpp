#include <iostream>
#include "DataUtility.cpp"
using namespace std;

#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream


int main() {
  
    DataUtility* data = new DataUtility();
    DataUtility::static_init();
    printf("PassRate for Instructor I12: %f \n", data->getPassRateForInstructor("I12"));
    printf("WRate for Instructor I12: %f \n", data->getWRateForInstructor("I12"));
    printf("SpringVsFall for course 1115: %f", data->getSpringVsFallPassRate("1115"));

    
    return 0;
}