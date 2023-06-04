#ifndef SORT_H
#define SORT_H

int partition(int* arr, int lo, int hi){
    //select pivot - naive
    int pivot = arr[hi];
    int smallValueIdx = lo-1; //prime for beginning of array
    for (int j =lo; j <= hi-1; ++j){
        ++smallValueIdx;
        int temp = arr[j];
        arr[j] = arr[smallValueIdx];
        arr[smallValueIdx] = temp;
    }

    //place the pivot
    int pivotSpotValue = arr[smallValueIdx+1];
    arr[smallValueIdx+1] = pivot;
    arr[hi] = pivotSpotValue;
    return (smallValueIdx+1);
}

void quickSort (int* arr, int lo, int hi){
    if(lo < hi){
        int partitionIdx = partition(arr, lo, hi); //put pivot in position
        quickSort(arr, lo, partitionIdx-1);
        quickSort(arr, partitionIdx+1, hi);
    }
}

#endif