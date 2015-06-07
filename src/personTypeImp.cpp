#include <iostream>
#include <string>
#include "personType.h"

using namespace std;

personType::personType(string first, string last)
{
    setName(first, last);
}

void personType::print() const
{
    cout << "First Name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;
}

void personType::setName(string first, string last)
{
    setLastName(last);
    setFirstName(first);
}

string personType::getFirstName() const
{
    return firstName;
}

string personType::getLastName() const
{
    return lastName;
}

personType& personType::setLastName(string last)
{
    lastName = last;

    return *this;
}

personType& personType::setFirstName(string first)
{
    firstName = first;

    return *this;
}
