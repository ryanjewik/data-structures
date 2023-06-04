
#include "Sort.h"
using namespace std;

int main(){
    int* myArray = new int[5];
    myArray[0] = 10;
    myArray[1] = 4;
    myArray[2] = 15;
    myArray[3] = 12;
    myArray[4] = 7;
    myArray[5] = 1;





    quickSort(myArray, 0, 4);

    for (int i = 0; i < 5; ++i){
        std::cout << myArray[i] << std::endl;
    }
    return 0;
}