#include <iostream>
using namespace std;


//int array[] -> passing a pointer, the compiler treats it as int*
void printArray(int array[], int len){
    for (int i = 0; i < len; ++i){
        cout << array[i] << endl;
    }
}

int main(){

    /*
    int arr1[3];
    arr1[0] = 10;
    arr1[1] = 20;
    arr1[2] = 30;
    for (int i = 0; i < 3; i++){
        cout << arr1[i] << endl;
    }

    int arr2[5] = {5, 10, 15, 20, 25};
    for (int i = 0; i < 5; ++i){
        cout << arr2[i] << endl;
    }
    cout << endl;
    int arr3[10];
    printArray(arr3, 10);

    cout << endl;
    //dynamic arrays
    int* arr4 = new int[5]; //dynamically allocated array

    for (int i = 0; i < 5; ++i){
        arr4[i] = i * 2;
    }
    printArray(arr4, 5);
    delete[] arr4;

    cout << endl;

    int* arr5 = new int[3];
    arr5[0] = 1;
    arr5[1] = 2;
    arr5[2] = 3;
    printArray(arr5, 3);
    delete[] arr5;

    int* arr4 = new int[10];
*/


//2D array
//allocating array
int** arr2D = new int*[3];
for (int i = 0; i < 3; ++i){
    arr2D[i] = new int[4];
}

//print
for (int i = 0; i < 3; ++i){
    for (int j = 0; j < 4; ++j){
        arr2D[i][j] = i * j;
    }
}

//initialize
for (int i = 0; i < 3; ++i){
    for (int j = 0; j < 4; ++j){
        cout << arr2D[i][j] << endl;
    }
}
//delete
for (int i =0; i < 3; ++i){
    delete[] arr2D[i];
}
}


