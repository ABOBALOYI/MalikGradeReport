#include <iostream>
#include <fstream>
#include <string>
#include "src/studentType.h"

using namespace std;

const int MAX_NO_OF_STUDENTS = 10;

void getStudentData(ifstream& infile, studentType studentList[], int numberOfStudents)
{

    string fName;
    string lName;
    int ID;
    int nOfCourses;
    char isPaid;
    bool isTuitionPaid;

    string cName;
    string cNo;
    int credits;

    int count;
    int i;

    courseType courses[6];

    char cGrades[6];

    for(count = 0; count < numberOfStudents; count++)
    {

        infile >> fName >> lName >> ID >> isPaid;

        if(isPaid == 'Y')
        {
            isTuitionPaid = true;
        }
        else
        {
            isTuitionPaid = false;
        }

        infile >> nOfCourses;

        for(i = 0; i < nOfCourses; i++)
        {
            infile >> cName >> cNo >> credits >> cGrades[i];

            courses[i].setCourseInfo(cName, cNo, credits);
        }

        studentList[count].setInfo(fName, lName, ID, nOfCourses, isTuitionPaid, courses, cGrades);
    }
}


void printGradeReports(ofstream& outfile,
                       studentType studentList[],
                       int numberOfStudents,
                       double tuitionRate) {
    int count;

    for(count = 0; count < numberOfStudents; count++)
    {
        studentList[count].print(outfile, tuitionRate);
    }
}

int main()
{
    studentType studentList[MAX_NO_OF_STUDENTS];

    int noOfStudents;
    double tuitionRate;
    ifstream infile;
    ofstream outfile;

    infile.open("stData.txt");

    if(!infile)
    {
        cout << "The input file does not exist. "
             << "Program terminates." << endl;

        return 1;
    }

    outfile.open("sDataOut.txt");

    infile >> noOfStudents;
    infile >> tuitionRate;

    getStudentData(infile, studentList, noOfStudents);
    printGradeReports(outfile, studentList, noOfStudents, tuitionRate);

    return 0;
}
