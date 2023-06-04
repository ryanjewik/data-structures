/// @file Office.cpp
/// @brief Allows for the creation of a Office object.
/// @author Ryan Jewik - jewik@chapman.edu

using namespace std;

#include "Office.h"

Office::Office(){} //constructor

Office::~Office(){} //destructor

Office::Office(int n) //overloaded constructor
{
  m_nWindows = n;
  m_longestIdleTime = 0;
  m_windowsFive = 0;
  m_meanIdleTime = 0;

  m_officeLine = new ListQueue<Customer>;

  for(int i = 0; i < m_nWindows; ++i)
  {
    Window w;
    m_windows.addBack(w);
    m_idleTimes.addBack(-1);
    m_isOverFive.addBack(false);
  }

  for(int i = 0; i < m_nWindows; ++i)
  {
    Window test = m_windows.get(i);
  }
}

//Checks all windows and finds an open one, removes the first from the queue then passes into window
//@input int secTime - the current time
//returns @output N/A
void Office::windowCustomer(int secTime)
{
  for (int i = 0; i < m_nWindows; ++i){
    if (m_windows.get(i).windowOpen() == true){
        cout << "window: " << i << " is empty so we will add here." << endl;
        if (!m_officeLine->isEmpty()){ //makes sure line isn't empty
        Customer tempC = m_officeLine->remove(); //removes customer from the queue
        tempC.setDepartureTime(secTime); //sets the time they will leave
        m_windows.get(i).addCustomer(tempC); //adds customer to the window
        }
        break;
    }
  }
}

//Checks both the windows and the queue to see if they are completely emtpy.
//@input N/A
//returns @output bool - true if both the queue and windows are empty.
bool Office::totallyEmpty(){
  bool windowsEmptyVar = true;
  for(int i = 0; i < m_nWindows; ++i)
  {
    if (m_windows.get(i).windowOpen() == false){
      windowsEmptyVar = false;
      break;
    }else{
    }
  }
  if (m_officeLine->isEmpty() == true && windowsEmptyVar == true){
    return true;
  }
  else{
    return false;
  }
}

//Loops and checks if all of the windows are empty.
//@input N/A
//returns @output bool - true if all the windows are empty.
bool Office::windowsEmpty(){
  for(int i = 0; i < m_nWindows; ++i)
  {
    if (m_windows.get(i).windowOpen() == false){
      return false;
      exit;
    }
  }
  return true;
}

//Computes and returns the mean idle time.
//@input N/A
//returns @output double - average idle time
double Office::getMeanIdleTime()
{
  for(int i = 0; i < m_nWindows; ++i)
  {
    cout << m_idleTimes.get(i) << endl;
    m_meanIdleTime += (double) m_idleTimes.get(i);
  }

  cout << m_meanIdleTime << endl;
  return (m_meanIdleTime / (double) m_nWindows);
}

//Increases the idle time given the index of the window to change.
//@input int i - index of window
//returns @output N/A
void Office::addIdleTime(int i)
{
  int temp = m_idleTimes.remove(i);
  temp++;
  m_idleTimes.add(i, temp);
}

//Decreases the idle time given the index of the window to change.
//@input int i - index of window
//returns @output N/A
void Office::removeIdleTime(int i)
{
  int temp = m_idleTimes.remove(i);
  temp--;
  m_idleTimes.add(i, temp);
}

//Changes a specific window's isOverFive variable given the index of the window.
//@input int i - index of window
//returns @output N/A
void Office::overFive(int i)
{
  m_isOverFive.remove(i);
  m_isOverFive.add(i, true);
}

//Counts and returns the number of windows with an idle time over five.
//@input N/A
//returns @output int - number of windows that have an idle time of over five minutes.
int Office::checkOverFive()
{
  int count = 0;
  for(int i = 0; i < m_nWindows; ++i)
  {
    if(m_isOverFive.get(i))
    {
      count++;
    }
  }

  return count;
}

//Finds and returns the longest idle time among all the windows.
//@input N/A
//returns @output int - longest idle time
int Office::longestIdleTime()
{
  int max = m_idleTimes.get(0);
  for(int i = 0; i < m_nWindows; ++i)
  {
    int check = m_idleTimes.get(i);
    if(check > max)
    {
      max = check;
    }
  }

  return max;
}
