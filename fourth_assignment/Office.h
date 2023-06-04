/// @file Office.h
/// @brief Allows for the creation of a Office object. (header)
/// @author Ryan Jewik - jewik@chapman.edu

#ifndef OFFICE_H
#define OFFICE_H
#include <iostream>

#include "Window.h"
#include "DblList.h"
#include "ListQueue.h"
#include "ListNode.h"

class Office
{
  public:
    Office();
    virtual ~Office();
    Office(int w);

    int m_longestIdleTime;
    int m_windowsFive;
    double m_meanIdleTime;
    int m_meanWaitTime;

    DblList<int> m_idleTimes;
    DblList<bool> m_isOverFive;

    ListQueue<Customer>* m_officeLine;
    DblList<Window> m_windows;

    void windowCustomer(int secTime);
    bool windowsEmpty();
    bool totallyEmpty();

    double getMeanIdleTime();

    void addIdleTime(int index);
    void removeIdleTime(int index);

    void overFive(int index);
    int checkOverFive();

    int longestIdleTime();

  private:
    int m_nWindows;
};

#endif
