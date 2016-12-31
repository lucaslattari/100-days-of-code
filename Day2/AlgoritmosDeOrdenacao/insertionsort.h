#ifndef _INSERTIONSORT_H_
#define _INSERTIONSORT_H_

void swapElementsInArray(int* arrayOfData, int indexOfFirstElement, int indexOfSecondElement);
void insertionSort(int* arrayOfData, int sizeOfArray, unsigned int& totalOfIterations, unsigned int& totalOfSwaps);

#endif // _INSERTIONSORT_H_
