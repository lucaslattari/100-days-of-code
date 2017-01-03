#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_

void    swapElementsInArray(int* arrayOfData, int indexOfFirstElement, int indexOfSecondElement);
int     partitionArray(int* arrayOfData, int lowerIndex, int higherIndex, int& totalOfSwaps);
void    quickSort(int* arrayOfData, int lowerIndex, int higherIndex, unsigned int& totalOfPartitions, unsigned int& totalOfSwaps);

#endif // _QUICKSORT_H_
