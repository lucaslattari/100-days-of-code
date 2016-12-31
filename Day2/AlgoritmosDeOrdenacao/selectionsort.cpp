#include "selectionsort.h"
#define UINT_MAX   4294967295U

void selectionSort(int* arrayOfData, int sizeOfArray, unsigned int& totalOfIterations, unsigned int& totalOfSwaps)
{
    totalOfIterations  = 0;
    totalOfSwaps       = 0;

    for(int i = 0 ; i < sizeOfArray ; i++)
    {
        int minimumElementIndex = i;
        for(int j = i + 1 ; j < sizeOfArray ; j++)
            if(arrayOfData[j] < arrayOfData[minimumElementIndex])
                minimumElementIndex = j;
        if(totalOfSwaps <= UINT_MAX)
            totalOfSwaps++;
        if(totalOfIterations <= UINT_MAX)
            totalOfIterations++;
        swapElementsInArray(arrayOfData, i, minimumElementIndex);
    }
}
