#include <iostream> 
using namespace std;

//return the index of the array that contains the value of the key
int simpleSearch(int* arr, int length, int key){
    int idx = -1;
    for (int i = 0; i < length; ++i){
        if (arr[i] == key){
            idx = i;
            break;
        }
    }
    return idx;
}


//return the index of the array that contains the value of the key
//the array is ordered least to greatest
int binarySearch(int* arr, int len, int key){
    int idx = -1;
    int right = len;
    int left = 0;

    while (right >= left){
        int middle = (right+left) /2;
        if (arr[middle] == key){
            idx = middle;
            break;
        }
        if(key < arr[middle]){
            right == middle -1;
        }
        else{
            left = middle + 1;
        }
    }
    return idx;
}

int main(){
    int* myArr = new int[10];
    for (int i = 0; i < 20; ++i){
        myArr[i] = i * 2;
        
    }
    cout << "starting simple search test" << endl;
    cout << simpleSearch (myArr, 1000, 859) << endl;
    cout << "ending simple search test" << endl;

    cout << "starting binary search test" << endl;
    cout << binarySearch (myArr, 1000, 859) << endl;
    cout << "ending binary search test" << endl;

    delete[] myArr;
    return 0;
}