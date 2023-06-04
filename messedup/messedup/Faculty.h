/// @file Faculty.h
/// @brief Allows for creation of Faculty objects implementing the person class.
/// @author Ryan Jewik - jewik@chapman.edu

#ifndef FACULTY_H
#define FACULTY_H

#include <string>
#include <iostream>
using namespace std;

#include "Person.h"
#include "DblList.h"

class Faculty : public Person
{
  private:
    string m_department;
  public:
    DblList<int> m_adviseesIds;
    Faculty(){}
    Faculty(int facultyId, string facultyName, string facultyLevel, string facultyDepartment) //constructor
    {
     
      this->m_id = facultyId;
      this->m_name = facultyName;
      this->m_level = facultyLevel;

      m_department = facultyDepartment;
      //m_adviseesIds.addBack(1);
    }

    void printInfo() //prints the faculty member's info
    {
      string nameIdLevel = this->getNameIdAndLevel();
      cout << nameIdLevel << endl;

      cout << "Department: " << this->m_department << endl;
      cout << "Advisee IDs" << endl;

      if(m_adviseesIds.isEmpty())
      {
        cout << "No advisees yet." << endl;
      }

      else
      {
        for(int i = 0; i < this->m_adviseesIds.size(); ++i)
        {
          //cout << this->m_adviseesIds.size() << endl;
          cout << "Student " << i + 1 << ": " << this->m_adviseesIds.get(i) << endl;
        }
      }
    }

    void removeAdvisee(int id)
    {
      int pos = m_adviseesIds.search(id);
      cout << pos << endl;
      this->m_adviseesIds.remove(pos);
    }

    void addAdvisee(int id) {
      cout << "Id: " << id << endl;
      m_adviseesIds.addBack(id);
      //cout << m_adviseesIds.get(0);}
    }
      bool operator ==(Faculty& rhs) //overloads the == opterator
      {return(m_id == rhs.getId());}

      bool operator !=( Faculty& rhs) //overloads the != opterator
      {return(m_id != rhs.getId());}

      bool operator <(Faculty& rhs) //overloads the < opterator
      {return(m_id < rhs.getId());}

      bool operator >(Faculty& rhs) //overloads the > opterator
      {return(m_id > rhs.getId());}

      };



#endif
