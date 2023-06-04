/// @file ServiceCenter.h
/// @brief Allows for the creation of a Service Center object. (header)
/// @author Ryan Jewik - jewik@chapman.edu

#ifndef SERVICECENTER_H
#define SERVICECENTER_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "DblList.h"
#include "Customer.h"
#include "Office.h"

class ServiceCenter
{
  public:
    ServiceCenter();
    virtual ~ServiceCenter();
    ServiceCenter(std::string file);
    int m_secTime;
    void newWave();
    //void sendToOffice(Customer c);
    DblList<Customer> satisfiedCustomers;

  private:
    int m_rWindow;
    int m_cWindow;
    int m_fWindow;
    int m_time;
    int m_nCustomers;
    std::string m_file;

    int m_windowsFive;

    int* m_officeTimes;
    char* m_officeTypes;
    char* m_officeOrder;

    int m_cWaitLong;
    int m_fWaitLong;
    int m_rWaitLong;
    float m_cWaitMean;
    float m_fWaitMean;
    float m_rWaitMean;

    //Office* m_offices;
};

#endif
