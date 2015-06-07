#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "courseType.h"

using namespace std;

courseType::courseType(string cName, string cNo, int credits)
{
    setCourseInfo(cName, cNo, credits);
}

string courseType::getCourseName()
{
    return courseName;
}

string courseType::getCourseNumber()
{
    return courseNo;
}

int courseType::getCredits()
{
    return courseCredits;
}

void courseType::setCourseInfo(string cName, string cNo, int credits)
{
    courseName = cName;
    courseNo = cNo;
    courseCredits = credits;
}

void courseType::print(ostream& outF)
{
    outF << left;
    outF << setw(8) << courseNo << "    ";
    outF << setw(15) << courseName;
    outF << right;
    outF << setw(3) << courseCredits << "   ";
}

