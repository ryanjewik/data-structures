/// @file Window.h
/// @brief Allows for the creation of a Window object. (header)
/// @author Ryan Jewik - jewik@chapman.edu

#ifndef WINDOW_H
#define WINDOW_H
#include <iostream>

#include "DblList.h"
#include "Customer.h"
#include "ListQueue.h"
#include "ListNode.h"

class Window
{
  public:

    Window();
    virtual ~Window();
    bool windowOpen();
    void addIdleTime();
    int getIdleTime();


    int print();

    //Customer* m_customer;
    void addCustomer(Customer c);
    //Customer m_customer [1];
    Customer getCustomer();
    ListQueue<Customer>* m_customer;

    void isOverFive();
    bool getOverFive();

  private:
    int m_idleTime;
    int m_longestIdleTime;

    bool m_isOpen;
    bool m_overFive;
};

#endif
