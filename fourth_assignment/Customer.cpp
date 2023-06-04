/// @file Customer.cpp
/// @brief Allows for the creation of a Customer object.
/// @author Ryan Jewik - jewik@chapman.edu

using namespace std;

#include "Customer.h"

Customer::Customer(){ //constructor
  m_timeOne = -1;
  m_timeTwo = -1;
  m_timeThree = -1;
}

Customer::~Customer(){} //destructor

Customer::Customer(int t1, int t2, int t3, char o1, char o2, char o3) //overloaded constructor
{
  m_timeOne = t1;
  m_timeTwo = t2;
  m_timeThree = t3;

  m_officeOne = o1;
  m_officeTwo = o2;
  m_officeThree = o3;

  int m_cWait = 0;
  int m_fWait = 0;
  int m_rWait = 0;

  int lineArrival;
  this->m_officesVisited = 0;

  cout << m_timeOne << endl;
  cout << m_timeTwo << endl;
  cout << m_timeThree << endl;

  cout << m_officeOne << endl;
  cout << m_officeTwo << endl;
  cout << m_officeThree << endl;
}

//Returns the amount of time the customer spends at the (first/second/third) office.
//@input N/A
//returns @output int - time spent at office
int Customer::getTimeOne(){return m_timeOne;}
int Customer::getTimeTwo(){return m_timeTwo;}
int Customer::getTimeThree(){return m_timeThree;}

//Returns the order that the customer visits the offices.
//@input N/A
//returns @output char - char representative of (first/second/third) office
char Customer::getOfficeOne(){return m_officeOne;}
char Customer::getOfficeTwo(){return m_officeTwo;}
char Customer::getOfficeThree(){return m_officeThree;}

//Returns the amount of time the customer waits at the (first/second/third) office.
//@input N/A
//returns @output int - wait time at the given office
int Customer::getWaitC(){return m_cWait;}
int Customer::getWaitF(){return m_fWait;}
int Customer::getWaitR(){return m_rWait;}

//Sets the amount of time waited at a given office.
//@input int t - time waited at office
//returns @output N/A
void Customer::setWaitC(int t){m_cWait = t;}
void Customer::setWaitF(int t){m_fWait = t;}
void Customer::setWaitR(int t){m_rWait = t;}

//Sets the time that the Customer leaves the office.
//@input currentTime - the current time
//returns @output N/A
void Customer::setDepartureTime(int currentTime){
  switch(m_officesVisited){
    case 0:
    m_departureTime =currentTime + m_timeOne;
    switch(m_officeOne){
      case 'C':
      m_cWait = currentTime - lineArrival;
      cout << "line wait time: " << m_cWait << endl;
      break;
      case 'F':
      m_fWait = currentTime - lineArrival;
      cout << "line wait time: " << m_fWait << endl;
      break;
      case 'R':
      m_rWait = currentTime - lineArrival;
      cout << "line wait time: " << m_rWait << endl;
      break;
    }
    break;
    case 1:
    m_departureTime =currentTime + m_timeTwo;
    switch(m_officeTwo){
      case 'C':
      m_cWait = currentTime - lineArrival;
      cout << "line wait time: " << m_cWait << endl;

      break;
      case 'F':
      m_fWait = currentTime - lineArrival;
      cout << "line wait time: " << m_fWait << endl;
      break;
      case 'R':
      m_rWait = currentTime - lineArrival;
      cout << "line wait time: " << m_rWait << endl;
      break;
    }
    break;
    case 2:
    m_departureTime =currentTime + m_timeThree;
    switch(m_officeThree){
      case 'C':
      m_cWait = currentTime - lineArrival;
      cout << "line wait time: " << m_cWait << endl;
      break;
      case 'F':
      m_fWait = currentTime - lineArrival;
      cout << "line wait time: " << m_fWait << endl;
      break;
      case 'R':
      m_rWait = currentTime - lineArrival;
      cout << "line wait time: " << m_rWait << endl;
      break;
    }
    break;
    default:
    m_departureTime = -1;
    break;
  }

  cout << "setting departure time... current time: " << currentTime << " therefore departure time: " << m_departureTime << endl;
}

//Returns the time the customer is meant to leave the office.
//@input N/A
//returns @output int - departure time from office
int Customer::getDepartureTime(){
  return m_departureTime;
}

//Returns the offices visited by teh customer.
//@input N/A
//returns @output int - number of offices visited
int Customer::getOfficesVisited(){
  return m_officesVisited;
}

//Increments the number of offices visited by 1
//@input N/A
//returns @output N/A
void Customer::setOfficesVisited(){
  m_officesVisited +=1;
}

//Sets a new arrival time for the customer at the next office.
//@input int k - arrival time
//returns @output N/A
void Customer::setArrivalTime(int k){
  lineArrival = k;
  cout << "new arrival time: " << lineArrival << endl;
}

//Sets a new leave time for the customer at the next office.
//@input int k - time they leave the office
//returns @output N/A
void Customer::setLeaveTime(int k){
  lineLeave = k;
}

//Returns the time the customer arrived at the office.
//@input N/A
//returns @output int - arrival time at the office
int Customer::getArrivalTime(){
  return lineArrival;
}

//Returns the time the customer is meant to leave the next office.
//@input N/A
//returns @output int - departure time from next office
int Customer::getLeaveTime(){
  return lineLeave;
}
