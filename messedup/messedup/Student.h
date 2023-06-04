/// @file Student.h
/// @brief Allows for creation of Student objects implementing the person class.
/// @author Ryan Jewik - jewik@chapman.edu

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
using namespace std;

#include "Person.h"
#include "DblList.h"

class Student : public Person
{
  private:
    string m_major;
    double m_gpa;
    int m_advisorId;

  public:
  Student(){}
    Student(int studentId, string studentName, string studentLevel, string studentMajor, double studentGpa)
    { //constructor
      this->m_id = studentId;
      this->m_name = studentName;
      this->m_level = studentLevel;

      m_major = studentMajor;
      m_gpa = studentGpa;
      m_advisorId = -1;
    }

    void printInfo() //prints the student's info
    {
      string nameIdLevel = this->getNameIdAndLevel();
      cout << nameIdLevel << endl;

      cout << "Major: " << this->m_major << endl;
      cout << "GPA: " << this->m_gpa << endl;

      if(this->m_advisorId == -1)
      {
        cout << "NO ADVISOR YET" << endl;
      }
      else
      {
        cout << "Advisor ID: " << this->m_advisorId << endl;
      }
    }

    int getAdvisor() {return this->m_advisorId;}

    void swapAdvisor(int newId) {
      cout << "newId: " << newId << endl;
      m_advisorId = newId;
      }
    /*
    friend bool operator==( Student& lhs,  Student& rhs);
    friend bool operator!=( Student& lhs,  Student& rhs);
    friend bool operator<( Student& lhs,  Student& rhs);
    friend bool operator>( Student& lhs,  Student& rhs);
    */
    bool operator ==(Student& rhs) //overloads the == opterator
    {
      if (m_id == rhs.getId()){
        return true;
      }else{return false;}
    }
      //return(m_id == rhs.getId());}

    bool operator !=(Student& rhs) //overloads the != opterator
    {return(m_id != rhs.getId());}

    bool operator <(Student& rhs) //overloads the < opterator
    {return(m_id < rhs.getId());}

    bool operator >(Student& rhs) //overloads the > opterator
    {return(m_id > rhs.getId());}

};
/*
bool operator==( Student& lhs,  Student& rhs) //overloads the == opterator
{
  cout <<"oioi" << endl;
  return(lhs.getId() == rhs.getId());}

bool operator!=( Student& lhs,  Student& rhs) //overloads the != opterator
{return(lhs.getId() != rhs.getId());}

bool operator<( Student& lhs,  Student& rhs) //overloads the < opterator
{return(lhs.getId() < rhs.getId());}

bool operator>( Student& lhs,  Student& rhs) //overloads the > opterator
{return(lhs.getId() > rhs.getId());}
*/

#endif
