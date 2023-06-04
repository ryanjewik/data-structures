#include "AQueue.h"
#include <iostream>
using namespace std;

int main(){
    AQueue<char>* theQ = new AQueue<char>(10);

    theQ->add('P');
    theQ->add('E');
    theQ->add('T');
    theQ->add('E');
    theQ->add('P');
    theQ->add('A');
    theQ->add('N');
    theQ->add('T');
    theQ->add('H');
    theQ->add('E');
    theQ->add('R');

    //cout << theQ->peak()<<endl;
    //cout << theQ->size() << endl;

    cout << theQ->size() <<endl;
    while(!theQ->isEmpty()){
        cout << theQ->remove() << endl;
    }
    cout << theQ->size() <<endl;
    delete theQ;



    return 0;
}