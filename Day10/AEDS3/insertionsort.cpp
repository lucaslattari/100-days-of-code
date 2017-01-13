#include "insertionsort.h"
#define UINT_MAX   4294967295U

void insertionSort(int* arrayOfData, int sizeOfArray, unsigned int& totalOfIterations, unsigned int& totalOfSwaps)
{
    totalOfIterations  = 0;
    totalOfSwaps       = 0;

    for(int i = 0 ; i < sizeOfArray ; i++)
    {
        for(int j = i ; j > 0 ; j--)
        {
            if(totalOfIterations <= UINT_MAX)
                totalOfIterations++;
            if(arrayOfData[j] > arrayOfData[j - 1])
                break;
            swapElementsInArray(arrayOfData, j, j - 1);
            if(totalOfSwaps <= UINT_MAX)
                totalOfSwaps++;
        }
    }
}
