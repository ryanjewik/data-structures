/// @file ServiceCenter.h
/// @brief Allows for the creation of a Service Center object.
/// @author Ryan Jewik - jewik@chapman.edu

#include "ServiceCenter.h"

using namespace std;

ServiceCenter::ServiceCenter(){}

ServiceCenter::~ServiceCenter(){}

ServiceCenter::ServiceCenter(std::string file)
{
  m_file = file;
  ifstream inFile;
  inFile.open(m_file, ios::in);
  int stopTime;
  m_secTime = 0;
  inFile >> m_rWindow; // 2
  inFile >> m_cWindow; // 3
  inFile >> m_fWindow; // 1

  Office Registrar(m_rWindow);
  Office Cashier(m_cWindow);
  Office financialAid(m_fWindow);
  DblList<Office> Offices;
  Offices.addBack(Registrar);
  Offices.addBack(Cashier);
  Offices.addBack(financialAid);


    if (inFile.is_open()){
      inFile >> m_time;
      inFile >> m_nCustomers;
      //stopTime = m_time * 60;
        for(int i = 0; i < m_nCustomers; ++i) // populates the queues and reads the first hour
        {
          m_officeTimes = new int[3];
          m_officeTypes = new char[3];
          m_officeOrder = new char[3];

          for(int k = 0; k < 6; ++k) //populates arrays that will be used to create customer objects
          {
            if(k <= 2)
            {
              inFile >> m_officeTimes[k];
            }

            else
            {
              inFile >> m_officeTypes[k - 3];
              m_officeOrder[k - 3] = m_officeTypes[k - 3] ;
            }
          }


          Customer c(m_officeTimes[0], m_officeTimes[1], m_officeTimes[2], m_officeOrder[0], m_officeOrder[1], m_officeOrder[2]);

          switch(c.getOfficeOne()) // finds which office to send customer to
          {
              case 'C':
                cout << "It's a C" << endl;
                c.setArrivalTime(m_secTime);
                Cashier.m_officeLine->add(c);
                Cashier.windowCustomer(0);
                break;

              case 'F':
                cout << "It's a F" << endl;
                c.setArrivalTime(m_secTime);
                financialAid.m_officeLine->add(c);
                financialAid.windowCustomer(0);
                break;

              case 'R':
                cout << "It's a R" << endl;
                c.setArrivalTime(m_secTime);
                Registrar.m_officeLine->add(c);
                Registrar.windowCustomer(0);
                break;

              default:
                cout << "invalid char" << endl;
                break;
          }
          }//initial set of students at opening
              cout << Cashier.totallyEmpty() << endl;
              cout << financialAid.totallyEmpty() << endl;
              cout << Registrar.totallyEmpty() << endl;
          cout << "--------------------------------- initial set of customers added" << endl;
          cout << endl;
          cout << endl;
          inFile >> m_time; // reads time again to know when the next wave of customers will arrive
          inFile >> m_nCustomers;
          stopTime = m_time * 60; // the time when it should check for the next wave of customers
          while((financialAid.totallyEmpty() != 1 || inFile.eof() != 1) || (Registrar.totallyEmpty() != 1 || Cashier.totallyEmpty() != 1)){//time only stops when it's the end of the file and the queues are empty
            m_secTime +=1; //time has started
            cout << "time: " << m_secTime << endl;
              for (int c = 0; c < Cashier.m_windows.size(); ++c){//Cashier check windows and see who is done
                if (Cashier.m_windows.get(c).windowOpen() != 1){//check if window open
                if (Cashier.m_windows.get(c).getCustomer().getDepartureTime() == m_secTime){//check if its time for customer to leave
                  Customer c1;
                  switch(Cashier.m_windows.get(c).getCustomer().getOfficesVisited()){//if it's their last office send them to satisfied customers dbllist
                    case 3:
                    //send to first office
                    satisfiedCustomers.addBack(Cashier.m_windows.get(c).m_customer->remove());
                    cout << "current time: " << m_secTime << " happy customer" << endl;
                    break;
                    case 1:
                    switch(Cashier.m_windows.get(c).getCustomer().getOfficeTwo())//send them to second office accordingly
                    {
                        case 'C': // currently at Cashier
                          cout << "error, shouldn't be C" << endl;
                          break;

                        case 'F': //send to financial aid
                          cout << "It's a F" << endl;
                          c1 = Cashier.m_windows.get(c).m_customer->remove();
                          c1.setArrivalTime(m_secTime);
                          financialAid.m_officeLine->add(c1); // removes from window then adds to next queue
                          financialAid.windowCustomer(m_secTime); // moves the queue along

                          //financialAid.windowCustomer(m_secTime); // checks if that customer needs to be pushed into window
                          break;

                        case 'R': //send to registrar
                          cout << "It's a R" << endl;
                          c1 = Cashier.m_windows.get(c).m_customer->remove();
                          c1.setArrivalTime(m_secTime);
                          Registrar.m_officeLine->add(c1); // removes from window then adds to next queue
                          Registrar.windowCustomer(m_secTime); // moves the queue along
                          //Registrar.windowCustomer(m_secTime); // checks if that customer needs to be pushed into window
                          break;

                        default:
                          cout << "invalid char" << endl;
                          break;
                    }
                    //send to second office
                    break;
                    case 2:
                    switch(Cashier.m_windows.get(c).getCustomer().getOfficeThree())//send to last office accordingly
                    {
                        case 'C': //they are at cashier so it shouldn't be there
                          cout << "error, shouldn't be C" << endl;
                          break;

                        case 'F': // to financial aid
                          cout << "It's a F" << endl;
                          c1 = Cashier.m_windows.get(c).m_customer->remove();
                          c1.setArrivalTime(m_secTime);
                          financialAid.m_officeLine->add(c1); // removes from window then adds to next queue
                          financialAid.windowCustomer(m_secTime); // moves the queue along
                          //financialAid.windowCustomer(m_secTime); // checks if that customer needs to be pushed into window
                          break;

                        case 'R': // to registrar
                          cout << "It's a R" << endl;
                          c1 = Cashier.m_windows.get(c).m_customer->remove();
                          c1.setArrivalTime(m_secTime);
                          Registrar.m_officeLine->add(c1); // removes from window then adds to next queue
                          Registrar.windowCustomer(m_secTime); // moves the queue along
                          //Registrar.windowCustomer(m_secTime); // checks if that customer needs to be pushed into window
                          break;

                        default:
                          cout << "invalid char" << endl;
                          break;
                    }
                    //send to third office
                    break;
                  }//switch statement to send to which office
                  }//if statement if the departure time has been met
                }//if the window is occupied

                if (Cashier.m_windows.get(c).windowOpen() && !Cashier.m_officeLine->isEmpty()){//if there is an empty window and there are people in the line add them to a window
                  Cashier.windowCustomer(m_secTime);
                }
                else if(Cashier.m_windows.get(c).windowOpen() && Cashier.m_officeLine->isEmpty())//if line and window empty add to idle time
                {
                    Cashier.addIdleTime(c);
                    //cout << Cashier.m_idleTimes.get(c) << endl;
                    if(Cashier.m_idleTimes.get(c) > 5)
                    {
                      Cashier.overFive(c);
                    }
                }
              }//loops for each window to check
              for (int c = 0; c < financialAid.m_windows.size(); ++c){//financial aid check windows and see who is done
                if (financialAid.m_windows.get(c).windowOpen() != 1){//send to first office according to character

                if (financialAid.m_windows.get(c).getCustomer().getDepartureTime() == m_secTime){
                  Customer c1;
                  switch(financialAid.m_windows.get(c).getCustomer().getOfficesVisited()){
                    case 3:
                    //send to first office
                    satisfiedCustomers.addBack(financialAid.m_windows.get(c).m_customer->remove());
                    cout << "current time: " << m_secTime << " happy customer" << endl;
                    break;
                    case 1:
                    switch(financialAid.m_windows.get(c).getCustomer().getOfficeTwo())//second office send them according to character
                    {
                        case 'C':
                          cout << "It's a C" << endl;
                          c1 = financialAid.m_windows.get(c).m_customer->remove();
                          c1.setArrivalTime(m_secTime);
                          Cashier.m_officeLine->add(c1); // removes from window then adds to next queue
                          Cashier.windowCustomer(m_secTime); // moves the queue along
                          //Cashier.windowCustomer(m_secTime); // checks if that customer needs to be pushed into window
                          break;

                        case 'F':
                          cout << "error, shouldn't be F" << endl;
                          break;

                        case 'R':
                          cout << "It's a R" << endl;
                          c1 = financialAid.m_windows.get(c).m_customer->remove();
                          c1.setArrivalTime(m_secTime);
                          Registrar.m_officeLine->add(c1); // removes from window then adds to next queue
                          Registrar.windowCustomer(m_secTime); // moves the queue along
                          //Registrar.windowCustomer(m_secTime); // checks if that customer needs to be pushed into window
                          break;

                        default:
                          cout << "invalid char" << endl;
                          break;
                    }
                    //send to second office
                    break;
                    case 2:
                    switch(financialAid.m_windows.get(c).getCustomer().getOfficeThree())//last office send them according to character
                    {
                        case 'C':
                          cout << "its a C" << endl;
                          c1 = financialAid.m_windows.get(c).m_customer->remove();
                          c1.setArrivalTime(m_secTime);
                          Cashier.m_officeLine->add(c1); // removes from window then adds to next queue
                          Cashier.windowCustomer(m_secTime); // moves the queue along
                          //Cashier.windowCustomer(m_secTime); // checks if that customer needs to be pushed into window
                          break;

                        case 'F':
                          cout << "error, shouldn't be F" << endl;
                          break;

                        case 'R':
                          cout << "It's a R" << endl;
                          c1 = financialAid.m_windows.get(c).m_customer->remove();
                          c1.setArrivalTime(m_secTime);
                          Registrar.m_officeLine->add(c1); // removes from window then adds to next queue
                          Registrar.windowCustomer(m_secTime); // moves the queue along
                         //Registrar.windowCustomer(m_secTime); // checks if that customer needs to be pushed into window
                          break;

                        default:
                          cout << "invalid char" << endl;
                          break;
                    }
                    //send to third office
                    break;
                  }//switch statement to send to which office
                }//if statement if the departure time has been met
                }//is window occupied

                if (financialAid.m_windows.get(c).windowOpen() && !financialAid.m_officeLine->isEmpty()){//if there is an empty window and there are people in the line add them to a window
                  financialAid.windowCustomer(m_secTime);
                }
                else if(financialAid.m_windows.get(c).windowOpen() && financialAid.m_officeLine->isEmpty())//if window and line empty add to idle time
                {
                    financialAid.addIdleTime(c);
                    //cout << financialAid.m_idleTimes.get(c) << endl;
                    if(financialAid.m_idleTimes.get(c) > 5)
                    {
                        financialAid.overFive(c);
                    }
                }

              }//loops for each window to check

              for (int c = 0; c < Registrar.m_windows.size(); ++c){//registrar check windows and see who is done
                if (Registrar.m_windows.get(c).windowOpen() != 1){//if a window is occupied we then check if it's time for the customer to leave
                  if (Registrar.m_windows.get(c).getCustomer().getDepartureTime() == m_secTime){ //if has reached the time at which they are supposed to leave then move them
                  Customer c1;
                  switch(Registrar.m_windows.get(c).getCustomer().getOfficesVisited()){//if it's their first office send them accordingly
                    case 3:
                    //send to first office
                    satisfiedCustomers.addBack(Registrar.m_windows.get(c).m_customer->remove());
                    cout << "current time: " << m_secTime << " happy customer" << endl;
                    break;
                    case 1:

                    switch(Registrar.m_windows.get(c).getCustomer().getOfficeTwo())//checks where to go for the third office
                    {
                        case 'C':
                          cout << "It's a C" << endl;
                          c1 = Registrar.m_windows.get(c).m_customer->remove();
                          c1.setArrivalTime(m_secTime);
                          Cashier.m_officeLine->add(c1); // removes from window then adds to next queue

                          Cashier.windowCustomer(m_secTime); // moves the queue along
                          //Cashier.windowCustomer(m_secTime); // checks if that customer needs to be pushed into window
                          break;

                        case 'F':
                          cout << "It's a F" << endl;
                          c1 = Registrar.m_windows.get(c).m_customer->remove();
                          c1.setArrivalTime(m_secTime);
                          financialAid.m_officeLine->add(c1);
                          financialAid.windowCustomer(m_secTime); // moves the queue along
                          //financialAid.windowCustomer(m_secTime); // checks if that customer needs to be pushed into window
                          break;

                        case 'R':
                          cout << "error, shouldn't be R" << endl;
                          break;

                        default:
                          cout << "invalid char" << endl;
                          break;
                    }
                    //send to second office
                    break;
                    case 2:
                    switch(Registrar.m_windows.get(c).getCustomer().getOfficeThree())//for their last office, checks the character and performs the action
                    {
                        case 'C':
                          cout << "It's a C" << endl;
                          c1 = Registrar.m_windows.get(c).m_customer->remove();
                          c1.setArrivalTime(m_secTime);
                          Cashier.m_officeLine->add(c1); // removes from window then adds to next queue
                          Cashier.windowCustomer(m_secTime); // moves the queue along
                          break;

                        case 'F':
                          cout << "It's a F" << endl;
                          c1 = Registrar.m_windows.get(c).m_customer->remove();
                          c1.setArrivalTime(m_secTime);
                          financialAid.m_officeLine->add(c1); // removes from window then adds to next queue
                          financialAid.windowCustomer(m_secTime); // moves the queue along
                          //financialAid.windowCustomer(m_secTime); // checks if that customer needs to be pushed into window
                          break;

                        case 'R':
                          cout << "Error, shouldn't be R" << endl;

                          //Registrar.windowCustomer(m_secTime); // checks if that customer needs to be pushed into window
                          break;

                        default:
                          cout << "invalid char" << endl;
                          break;
                    }
                    //send to third office
                    break;
                  }//switch statement to send to which office
                }//if statement if the departure time has been met
                }//checks if window is open

                if (Registrar.m_windows.get(c).windowOpen() && !Registrar.m_officeLine->isEmpty()){//if there is an empty window and there are people in the line add them to a window
                  Registrar.windowCustomer(m_secTime);
                }
                else if(Registrar.m_windows.get(c).windowOpen() && Registrar.m_officeLine->isEmpty())//if the line is empty and nobody at the window, add to the idletime
                {
                    Registrar.addIdleTime(c);
                    //cout << Registrar.m_idleTimes.get(c) << endl;
                    if(Registrar.m_idleTimes.get(c) > 5) // if the idleTime is over 5 then it changes the boolean
                    {
                      Registrar.overFive(c);
                    }
                }



              }//loops for each window to check


            if (m_secTime == stopTime){ // the next hour that customers arrive, adds all of them to the queues
              cout << "reached the next wave: " << stopTime << endl;
              for(int i = 0; i < m_nCustomers; ++i)
              { // creates each customer and adds them to their queue
                m_officeTimes = new int[3];
                m_officeTypes = new char[3];
                m_officeOrder = new char[3];

                for(int k = 0; k < 6; ++k) //reads each attribute and adds them to an array
                {
                  if(k <= 2)
                  {
                    inFile >> m_officeTimes[k];
                  }

                  else
                  {
                    inFile >> m_officeTypes[k - 3];
                    m_officeOrder[k - 3] = m_officeTypes[k - 3] ;
                  }
                }

                Customer c(m_officeTimes[0], m_officeTimes[1], m_officeTimes[2], m_officeOrder[0], m_officeOrder[1], m_officeOrder[2]); // creates customer object

                switch(c.getOfficeOne())//reads each character and finds which office to put them in first
                {
                    case 'C':
                      cout << "It's a C" << endl;
                      c.setArrivalTime(m_secTime);
                      cout << c.getOfficesVisited() << endl;
                      Cashier.m_officeLine->add(c);
                      Cashier.windowCustomer(m_secTime);
                      break;

                    case 'F':
                      cout << "It's a F" << endl;
                      c.setArrivalTime(m_secTime);
                      cout << c.getOfficesVisited() << endl;
                      financialAid.m_officeLine->add(c);
                      financialAid.windowCustomer(m_secTime);
                      break;

                    case 'R':
                      cout << "It's a R" << endl;
                      c.setArrivalTime(m_secTime);
                      cout << c.getOfficesVisited() << endl;
                      Registrar.m_officeLine->add(c);
                      Registrar.windowCustomer(m_secTime);
                      break;

                    default:
                      cout << "invalid char" << endl;
                      break;
                } // first office bracket
                }//creates each customer object
              inFile >> m_time;
              inFile >> m_nCustomers;
              stopTime = m_time * 60;
              }//adds new set of customers bracket


            }//time bracket

            cout << "Cashier window: ";
            cout <<Cashier.m_windows.get(0).windowOpen() << endl;
            cout << "financial aid window: ";
            cout <<financialAid.m_windows.get(0).windowOpen() << endl;
            cout << "registrar window: ";
            cout <<Registrar.m_windows.get(0).windowOpen() << endl;
            cout << "Cashier line: ";
            cout << Cashier.m_officeLine->size() << endl;
            cout << "finnancial aid line: ";
            cout << financialAid.m_officeLine->size() << endl;
            cout << "registrar line: ";
            cout << Registrar.m_officeLine->size() << endl;


            //confirms status of each of the windows
            cout << Cashier.totallyEmpty() << endl;
            cout << financialAid.totallyEmpty() << endl;
            cout << Registrar.totallyEmpty() << endl;
            cout << "satisfied customers: " << satisfiedCustomers.size() << endl;//a dbllist that consists of all of the customers that finished

            cout << m_time << endl;
            cout << m_nCustomers << endl;

            float cSum = 0;
            float fSum = 0;
            float rSum = 0;
            int overFive =0;

            //adds first customer's numbers
            m_cWaitLong = satisfiedCustomers.get(0).getWaitC();
            cSum += satisfiedCustomers.get(0).getWaitC();
            m_fWaitLong = satisfiedCustomers.get(0).getWaitF();
            fSum += satisfiedCustomers.get(0).getWaitF();
            m_rWaitLong = satisfiedCustomers.get(0).getWaitR();
            rSum += satisfiedCustomers.get(0).getWaitR();


            //adds all of the other customer's numbers and does comparisons
            for (int i = 1; i < satisfiedCustomers.size(); ++i){//loops through every customer
              bool s_OverFive = false;
              cSum += satisfiedCustomers.get(i).getWaitC(); //adds to sum

              if (satisfiedCustomers.get(i).getWaitC()>m_cWaitLong){//if the value is larger then override
                m_cWaitLong = satisfiedCustomers.get(i).getWaitC();
              }

              if (satisfiedCustomers.get(i).getWaitC() > 10){//if they waited over 10 minutes
                s_OverFive = true;
              }
              cout << satisfiedCustomers.get(i).getWaitC() << endl;

              fSum += satisfiedCustomers.get(i).getWaitF();//adds to sum

              if (satisfiedCustomers.get(i).getWaitF()>m_fWaitLong){//overrides if larger
                m_fWaitLong = satisfiedCustomers.get(i).getWaitF();
              }

              if (satisfiedCustomers.get(i).getWaitF() > 10){//if they waited over 10 minutes
                s_OverFive = true;
              }
              cout << satisfiedCustomers.get(i).getWaitF() << endl;

              rSum += satisfiedCustomers.get(i).getWaitR();//adds to sum
              if (satisfiedCustomers.get(i).getWaitR()>m_rWaitLong){//overrides if larger
                m_rWaitLong = satisfiedCustomers.get(i).getWaitR();
              }
              if (satisfiedCustomers.get(i).getWaitR() > 10){//if they waited over 10 minutes
                s_OverFive = true;
              }

              if (s_OverFive){
                overFive +=1;
              }

              cout << satisfiedCustomers.get(i).getWaitR() << endl;
              cout << "---------------" << endl;
            }
            m_cWaitMean = cSum / satisfiedCustomers.size();
            m_fWaitMean = fSum / satisfiedCustomers.size();
            m_rWaitMean = rSum / satisfiedCustomers.size();

            cout << "Cashier mean student wait time: " << m_cWaitMean << endl;
            cout << "Financial Aid mean student wait time: " << m_fWaitMean << endl;
            cout << "Registrar mean student wait time: " << m_rWaitMean << endl;

            cout <<"Cashier longest student wait time: " << m_cWaitLong << endl;
            cout <<"Financial Aid longest student wait time: " << m_fWaitLong << endl;
            cout <<"Registrar longest student wait time: " << m_rWaitLong << endl;

            cout <<"Number of students that waited over 10 minutes: " << overFive << endl;

            cout << "Cashier windows mean idle time: " << Cashier.getMeanIdleTime() << endl << endl;
            cout << "Financial Aid windows mean idle time: " << financialAid.getMeanIdleTime() << endl << endl;
            cout << "Registrar windows mean idle time: " << Registrar.getMeanIdleTime() << endl << endl;

            cout << "Cashier longest Idle Time: " << Cashier.longestIdleTime() << endl;
            cout << "Financial Aid longest Idle Time: " << financialAid.longestIdleTime() << endl;
            cout << "Registrar longest Idle Time: " << Registrar.longestIdleTime() << endl;

            int allOverFive = Cashier.checkOverFive() + financialAid.checkOverFive() + Registrar.checkOverFive();
            cout << "Windows with over five minutes of idle time: " << allOverFive << endl;
          }//initial assignment of m_time and m_nCustomers bracket

      inFile.close();


    }//constructor bracket
