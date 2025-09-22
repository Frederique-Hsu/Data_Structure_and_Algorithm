/*!
 *  \file       employee.hpp
 *  \brief
 *
 */


#pragma once

#include <string>

class Employee
{
public:
    explicit Employee(const std::string& name, double salary = 0.0, int seniority = 1);
private:
    std::string name;
    double salary;
    int seniority;
public:
    const std::string getName() const;

    bool operator==(const Employee& rhs) const;
    bool operator!=(const Employee& rhs) const;

    // friend bool operator==(const Employee& lhs, const Employee& rhs);
    // friend bool operator!=(const Employee& lhs, const Employee& rhs);
};

// bool operator==(const Employee& lhs, const Employee& rhs);
// bool operator!=(const Employee& lhs, const Employee& rhs);
