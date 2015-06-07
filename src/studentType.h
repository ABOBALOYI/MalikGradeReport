#ifndef H_studentType
#define H_studentType

#include <fstream>
#include <string>
#include "personType.h"
#include "courseType.h"

using namespace std;

class studentType: public personType
{
    public:
        void setInfo(
                     string fname, 
                     string lName, 
                     int ID, 
                     int nOfCourses, 
                     bool isTPaid, 
                     courseType courses[], 
                     char courseGrades[]
                    );

        void print(ostream& outF, double tuitionRate);

        studentType();

        int getHoursEnrolled();

        double getGpa();

        double billingAmount(double tuitionRate);

    private:
        void sortCourses();
        int sId;
        int numberOfCourses;
        bool isTuitionPaid;
        courseType coursesEnrolled[6];
        char coursesGrade[6];
};

#endif
