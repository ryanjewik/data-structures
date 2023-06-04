#include <iostream>
using namespace std;

int main (int argc, char** argv){
    cout << "You have entered " << argc << "arguements" << endl;
    for (int i = 0; i < argc; ++i){
        cout << "arg " << i << ": " << argv[i] << endl;
    }

    return 0;
}