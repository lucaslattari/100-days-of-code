#ifndef _HEAPSORT_H_
#define _HEAPSORT_H_

void printArrayForHeapsort(int* arrayOfData, int sizeOfArray);
void swapElementsInArray(int* arrayOfData, int indexOfFirstElement, int indexOfSecondElement);
void heapify(int* arrayOfData, int positionOfNode, int sizeOfArray);
void heapSort(int* arrayOfData, int sizeOfArray);

#endif // _HEAPSORT_H_
