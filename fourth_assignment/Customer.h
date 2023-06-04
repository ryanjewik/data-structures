/// @file Customer.h
/// @brief Allows for the creation of a Customer object. (header)
/// @author Ryan Jewik - jewik@chapman.edu

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>

class Customer
{
  public:
    Customer();
    virtual ~Customer();
    Customer(int t1, int t2, int t3, char o1, char o2, char o3);

    int getTimeOne();
    int getTimeTwo();
    int getTimeThree();

    char getOfficeOne();
    char getOfficeTwo();
    char getOfficeThree();

    int getWaitC();
    int getWaitF();
    int getWaitR();

    void setWaitC(int t);
    void setWaitF(int t);
    void setWaitR(int t);

    void setDepartureTime(int currentTime);
    int getDepartureTime();
    int getOfficesVisited();
    void setOfficesVisited();

    void setArrivalTime(int k);
    void setLeaveTime(int k);
    int getArrivalTime();
    int getLeaveTime();
  

  private:
    int m_timeOne;
    int m_timeTwo;
    int m_timeThree;

    char m_officeOne;
    char m_officeTwo;
    char m_officeThree;

    int m_cWait;
    int m_fWait;
    int m_rWait;

    int m_officesVisited;
    int m_arrivalTime;
    int m_departureTime;

    int lineArrival;
    int lineLeave;
};

#endif
