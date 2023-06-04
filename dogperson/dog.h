#ifndef DOG_H
#define DOG_H

#include "person.h"
#include <iostream>
using namespace std;

class Dog{
    public:
        Dog();
        Dog(string name, int age, string ownerName);
        virtual ~Dog();
        void speak();
        string getName();
        int getAge();

        void setName(string name);
        void setAge(int age);

    private:
        string m_name;
        int m_age;
        Person* m_owner; //declares a pointer variable to a person
};

#endif