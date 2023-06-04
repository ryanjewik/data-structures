/// @file Window.cpp
/// @brief Allows for the creation of a Window object.
/// @author Ryan Jewik - jewik@chapman.edu

using namespace std;
#include "Window.h"

Window::Window() //constructor
{
  cout << "window created" << endl;
  m_idleTime = 0;
  m_longestIdleTime = 0;

  m_isOpen = true;
  m_overFive = false;
  m_customer = new ListQueue<Customer>;
}

Window::~Window(){ //destructor
}

//Adds a customer to a given window gven the customer object.
//@input Customer c - customer to add to the window
//returns @output N/A
void Window::addCustomer(Customer c)
{
  c.setOfficesVisited();
  m_customer->add(c);
}

//Checks if the window is empty or not
//@input N/A
//returns @output bool - true if the window is empty / open
bool Window::windowOpen(){
  if (m_customer->isEmpty()){
    m_isOpen = true;
    return true;
  }
  else{
    m_isOpen = false;
    return false;
  }
}

//DGets the customer at the front of the line.
//@input N/A
//returns @output Customer - customer at front of line
Customer Window::getCustomer(){
  return m_customer->peek();
}

//Returns the idle time of the window.
//@input N/A
//returns @output int - idle time
int Window::getIdleTime(){
  return m_idleTime;
}

//Adds to the idle time of a window.
//@input N/A
//returns @output N/A
void Window::addIdleTime(){
  ++m_idleTime;
}

//Sets the m_overFive to true;
//@input N/A
//returns N/A
void Window::isOverFive()
{
  m_overFive = true;
}

//Returns if the window has been idle for over five minutes.
//@input N/A
//returns @output bool - true if window idle time > 5
bool Window::getOverFive()
{
  return m_overFive;
}
