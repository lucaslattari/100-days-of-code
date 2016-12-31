#include "bubblesort.h"
#define UINT_MAX   4294967295U

void swapElementsInArray(int* arrayOfData, int indexOfFirstElement, int indexOfSecondElement)
{
    int temporary                       = arrayOfData[indexOfFirstElement];
    arrayOfData[indexOfFirstElement]    = arrayOfData[indexOfSecondElement];
    arrayOfData[indexOfSecondElement]   = temporary;
}

void bubbleSort(int* arrayOfData, int sizeOfArray, unsigned int& totalOfIterations, unsigned int& totalOfSwaps)
{
    totalOfIterations  = 0;
    totalOfSwaps       = 0;

    bool swappedInLastIteration;
    do
    {
        swappedInLastIteration = false;
        for (int i = 1 ; i < sizeOfArray ; i++)
            if(arrayOfData[i - 1] > arrayOfData[i])
            {
                swapElementsInArray(arrayOfData, i - 1, i);
                swappedInLastIteration = true;

                if(totalOfSwaps <= UINT_MAX)
                    totalOfSwaps++;
            }
        if(totalOfIterations <= UINT_MAX)
            totalOfIterations++;
    }while(swappedInLastIteration);
}
