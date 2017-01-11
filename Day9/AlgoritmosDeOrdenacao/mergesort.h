#ifndef _MERGESORT_H_
#define _MERGESORT_H_

void swapElementsInArray(int* arrayOfData, int indexOfFirstElement, int indexOfSecondElement);
void mergeTwoArrays(int* arrayOfData, int lowerIndex, int midPointArrayIndex, int higherIndex);
void mergeSort(int* arrayOfData, int lowerIndex, int higherIndex, unsigned int& totalOfMerges, unsigned int* temporaryArray);

#endif // _MERGESORT_H_
