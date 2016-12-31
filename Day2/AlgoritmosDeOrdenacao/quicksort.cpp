#include <iostream>
#include "stdio.h"
#include "quicksort.h"
#define UINT_MAX   4294967295U

using namespace std;

int partitionArray(int* arrayOfData, int lowerIndex, int higherIndex, unsigned int& totalOfSwaps)
{
    int indexOfFirstHalf    = lowerIndex;
    int indexOfSecondHalf   = higherIndex + 1;

    int pivot               = arrayOfData[lowerIndex];

    int sizeOfArray = higherIndex - lowerIndex;
    while(1)
    {
        while(arrayOfData[++indexOfFirstHalf] < pivot)
            if(indexOfFirstHalf == higherIndex)
                break;
        while(arrayOfData[--indexOfSecondHalf] > pivot)
            if(indexOfSecondHalf == lowerIndex)
                break;
        if(indexOfFirstHalf >= indexOfSecondHalf)
            break;
        if(totalOfSwaps <= UINT_MAX)
            totalOfSwaps++;
        swapElementsInArray(arrayOfData, indexOfFirstHalf, indexOfSecondHalf);
    }
    if(totalOfSwaps <= UINT_MAX)
        totalOfSwaps++;
    swapElementsInArray(arrayOfData, indexOfSecondHalf, lowerIndex);

    return indexOfSecondHalf;
}

void quickSort(int* arrayOfData, int lowerIndex, int higherIndex, unsigned int& totalOfPartitions, unsigned int& totalOfSwaps)
{
    if(higherIndex <= lowerIndex)
        return;
    int partitionIndex = partitionArray(arrayOfData, lowerIndex, higherIndex, totalOfSwaps);
    if(totalOfPartitions <= UINT_MAX)
        totalOfPartitions++;
    quickSort(arrayOfData, lowerIndex, partitionIndex - 1, totalOfPartitions, totalOfSwaps);
    quickSort(arrayOfData, partitionIndex + 1, higherIndex, totalOfPartitions, totalOfSwaps);
}
