/*!
 * \file        employee.cpp
 * \brief
 *
 */


#include "employee.hpp"

Employee::Employee(const std::string& name, double salary, int seniority)
    : name(name), salary(salary), seniority(seniority)
{
}

const std::string Employee::getName() const
{
    return name;
}

bool Employee::operator==(const Employee& rhs) const
{
    return (getName() == rhs.getName());
}

bool Employee::operator!=(const Employee& rhs) const
{
    return (not (*this == rhs));
}
