/*******************************************************************************
 * File name    : Person.h
 * Description  : Define a class Person.
 * Creator      : Frederick Hsu
 * Creation date: Tue.  22 March, 2016
 * Copyright(C) 2016    All rights reserved.
 * 
 *******************************************************************************/


#ifndef PERSON_H
#define PERSON_H

    class Person
    {
    private:
        char *name;
        int age;
        friend bool lesserAge(const Person&, const Person&);
    public:
        Person(char *n = "", int a = 0);
        ~Person(void);
        bool operator==(const Person& p) const;
        bool operator<(const Person& p) const;
        bool operator>(const Person& p) const;
    protected:
    };
    
    bool lesserAge(const Person& p1, const Person& p2);

#endif  /* PERSON_H */