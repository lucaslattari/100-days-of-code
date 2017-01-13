#include "stdio.h"
#include "string.h"
#include "mergesort.h"
#define UINT_MAX   4294967295U

void mergeTwoArrays(int* arrayOfData, int lowerIndex, int midPointArrayIndex, int higherIndex, unsigned int* temporaryArray)
{
    //merge array[lowerIndex ... midpointArray] with array[midpointArrayIndex + 1 ... higherIndex]
    int indexForFirstPartOfArray    = lowerIndex;
    int indexForSecondPartOfArray   = midPointArrayIndex + 1;

    memset(temporaryArray, 0, sizeof(int) * (higherIndex - lowerIndex));
    for(int k = lowerIndex ; k <= higherIndex ; k++)
        temporaryArray[k - lowerIndex] = arrayOfData[k];

    for(int k = lowerIndex ; k <= higherIndex ; k++)
    {
        if(indexForFirstPartOfArray > midPointArrayIndex)
        {
            arrayOfData[k] = temporaryArray[indexForSecondPartOfArray - lowerIndex];
            indexForSecondPartOfArray++;
        }else if(indexForSecondPartOfArray > higherIndex)
        {
            arrayOfData[k] = temporaryArray[indexForFirstPartOfArray - lowerIndex];
            indexForFirstPartOfArray++;
        }else if(temporaryArray[indexForFirstPartOfArray - lowerIndex] < temporaryArray[indexForSecondPartOfArray - lowerIndex])
        {
            arrayOfData[k] = temporaryArray[indexForFirstPartOfArray - lowerIndex];
            indexForFirstPartOfArray++;
        }else
        {
            arrayOfData[k] = temporaryArray[indexForSecondPartOfArray - lowerIndex];
            indexForSecondPartOfArray++;
        }
    }
}

void mergeSort(int* arrayOfData, int lowerIndex, int higherIndex, unsigned int& totalOfMerges, unsigned int* temporaryArray)
{
    if(higherIndex <= lowerIndex)
        return;
    int midPointIndex = lowerIndex + (higherIndex - lowerIndex) / 2;
    mergeSort(arrayOfData, lowerIndex, midPointIndex, totalOfMerges, temporaryArray);
    if(totalOfMerges <= UINT_MAX)
        totalOfMerges++;

    mergeSort(arrayOfData, midPointIndex + 1, higherIndex, totalOfMerges, temporaryArray);
    if(totalOfMerges <= UINT_MAX)
        totalOfMerges++;

    mergeTwoArrays(arrayOfData, lowerIndex, midPointIndex, higherIndex, temporaryArray);
}
