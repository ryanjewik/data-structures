#include "ACStack.h"
#include "ATStack.h"
#include <iostream>
using namespace std;

int main(){

    //ACStack myStack(10);
    ATStack<int> myStack(10);
    myStack.push(1);
    myStack.push(2);
    myStack.push(4);
    myStack.push(6);
    myStack.push(8);
    cout << myStack.peek() << endl;

    //myStack.pop();

    cout << myStack.peek() << endl;

    while (!myStack.isEmpty()){
        cout << myStack.pop() << endl;
    }



    return 0;
}