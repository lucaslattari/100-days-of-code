#include <iostream>
#include <ctime>
#include <cstdlib>
#include "stdio.h"
#include "string.h"

#include "bubblesort.h"
#include "selectionsort.h"
#include "insertionsort.h"
#include "mergesort.h"
#include "quicksort.h"

using namespace std;

void fillArrayWithRandomNumbers(int* arrayOfData, int sizeOfArray, int maximumValueOfArray)
{
    srand((unsigned)time(nullptr));

    for(int i = 0 ; i < sizeOfArray ; i++)
    {
        int randomNumber = rand() % maximumValueOfArray;
        arrayOfData[i] = randomNumber;
    }
}

void printArray(int* arrayOfData, int sizeOfArray)
{
    cout << "Content: ";
    for(int i = 0 ; i < sizeOfArray ; i++)
        cout << arrayOfData[i] << " ";
    cout << endl;
}

void analysisOfBubbleSort(int* arrayOfData, int sizeOfArray, unsigned int& totalOfIterations, unsigned int& totalOfSwaps)
{
    const clock_t beginClockTime    = clock();                                 //contador de tempo inicial
    bubbleSort(arrayOfData, sizeOfArray, totalOfIterations, totalOfSwaps);     //executa algoritmo bubblesort
    const clock_t endClockTime      = clock();                                 //contador de tempo final

    float totalTimeInSeconds        = float( endClockTime - beginClockTime ) /  CLOCKS_PER_SEC;
    //printArray(arrayOfData, sizeOfArray);                                      //imprime vetor na tela

    cout << "Total of iterations in BubbleSort: " << totalOfIterations << endl;
    cout << "Total of swaps in BubbleSort: " << totalOfSwaps << endl;
    cout << "Total time in seconds: " << totalTimeInSeconds << endl;
}

void analysisOfSelectionSort(int* arrayOfData, int sizeOfArray, unsigned int& totalOfIterations, unsigned int& totalOfSwaps)
{
    const clock_t beginClockTime    = clock();                                 //contador de tempo inicial
    selectionSort(arrayOfData, sizeOfArray, totalOfIterations, totalOfSwaps);     //executa algoritmo selectionsort
    const clock_t endClockTime      = clock();                                 //contador de tempo final

    float totalTimeInSeconds        = float( endClockTime - beginClockTime ) /  CLOCKS_PER_SEC;
    //printArray(arrayOfData, sizeOfArray);                                      //imprime vetor na tela

    cout << "Total of iterations in SelectionSort: " << totalOfIterations << endl;
    cout << "Total of swaps in SelectionSort: " << totalOfSwaps << endl;
    cout << "Total time in seconds: " << totalTimeInSeconds << endl;
}

void analysisOfInsertionSort(int* arrayOfData, int sizeOfArray, unsigned int& totalOfIterations, unsigned int& totalOfSwaps)
{
    const clock_t beginClockTime    = clock();                                 //contador de tempo inicial
    insertionSort(arrayOfData, sizeOfArray, totalOfIterations, totalOfSwaps);     //executa algoritmo selectionsort
    const clock_t endClockTime      = clock();                                 //contador de tempo final

    float totalTimeInSeconds        = float( endClockTime - beginClockTime ) /  CLOCKS_PER_SEC;
    //printArray(arrayOfData, sizeOfArray);                                      //imprime vetor na tela

    cout << "Total of iterations in InsertionSort: " << totalOfIterations << endl;
    cout << "Total of swaps in InsertionSort: " << totalOfSwaps << endl;
    cout << "Total time in seconds: " << totalTimeInSeconds << endl;
}

void analysisOfMergeSort(int* arrayOfData, int sizeOfArray, unsigned int& totalOfMerges)
{
    unsigned int* temporaryArray = new unsigned int[sizeOfArray];

    const clock_t beginClockTime    = clock();                     //contador de tempo inicial
    mergeSort(arrayOfData, 0, sizeOfArray - 1, totalOfMerges, temporaryArray);     //executa algoritmo mergesort
    const clock_t endClockTime      = clock();                     //contador de tempo final

    float totalTimeInSeconds        = float( endClockTime - beginClockTime ) /  CLOCKS_PER_SEC;
    //printArray(arrayOfData, sizeOfArray);                                      //imprime vetor na tela

    cout << "Total of merges in MergeSort: " << totalOfMerges << endl;
    cout << "Total time in seconds: " << totalTimeInSeconds << endl;

    delete(temporaryArray);
}

void analysisOfQuickSort(int* arrayOfData, int sizeOfArray, unsigned int& totalOfPartitions, unsigned int& totalOfSwaps)
{
    const clock_t beginClockTime    = clock();                     //contador de tempo inicial
    quickSort(arrayOfData, 0, sizeOfArray - 1, totalOfPartitions, totalOfSwaps);     //executa algoritmo quicksort
    const clock_t endClockTime      = clock();                     //contador de tempo final

    float totalTimeInSeconds        = float( endClockTime - beginClockTime ) /  CLOCKS_PER_SEC;
    //printArray(arrayOfData, sizeOfArray);                                      //imprime vetor na tela

    cout << "Total of partitions in QuickSort: " << totalOfPartitions << endl;
    cout << "Total of swaps in QuickSort: " << totalOfSwaps << endl;
    cout << "Total time in seconds: " << totalTimeInSeconds << endl;
}

int main()
{
    int sizeOfArray                                 = 100000;
    int* arrayOfDataForBubbleSort                   = new int[sizeOfArray];
    int* arrayOfDataForSelectionSort                = new int[sizeOfArray];
    int* arrayOfDataForInsertionSort                = new int[sizeOfArray];
    int* arrayOfDataForMergeSort                    = new int[sizeOfArray];
    int* arrayOfDataForQuickSort                    = new int[sizeOfArray];

    unsigned int totalOfIterationsOfBubbleSort      = 0;
    unsigned int totalOfSwapsOfBubbleSort           = 0;
    unsigned int totalOfIterationsOfSelectionSort   = 0;
    unsigned int totalOfSwapsOfSelectionSort        = 0;
    unsigned int totalOfIterationsOfInsertionSort   = 0;
    unsigned int totalOfSwapsOfInsertionSort        = 0;
    unsigned int totalOfMergesOfMergeSort           = 0;
    unsigned int totalOfPartitionsOfQuickSort       = 0;
    unsigned int totalOfSwapsOfQuickSort            = 0;

    fillArrayWithRandomNumbers(arrayOfDataForBubbleSort, sizeOfArray, 1000000);             //preenche um vetor com números inteiros aleatórios
    memcpy(arrayOfDataForSelectionSort, arrayOfDataForBubbleSort, sizeof *arrayOfDataForBubbleSort * sizeOfArray); //copia dados do vetor bubble para o vetor selection
    memcpy(arrayOfDataForInsertionSort, arrayOfDataForBubbleSort, sizeof *arrayOfDataForBubbleSort * sizeOfArray); //copia dados do vetor bubble para o vetor insertion
    memcpy(arrayOfDataForMergeSort, arrayOfDataForBubbleSort, sizeof *arrayOfDataForBubbleSort * sizeOfArray); //copia dados do vetor bubble para o vetor mergesort
    memcpy(arrayOfDataForQuickSort, arrayOfDataForBubbleSort, sizeof *arrayOfDataForBubbleSort * sizeOfArray); //copia dados do vetor bubble para o vetor quicksort

    analysisOfBubbleSort(arrayOfDataForBubbleSort, sizeOfArray, totalOfIterationsOfBubbleSort, totalOfSwapsOfBubbleSort);
    cout << endl;
    analysisOfSelectionSort(arrayOfDataForSelectionSort, sizeOfArray, totalOfIterationsOfSelectionSort, totalOfSwapsOfSelectionSort);
    cout << endl;
    analysisOfInsertionSort(arrayOfDataForInsertionSort, sizeOfArray, totalOfIterationsOfInsertionSort, totalOfSwapsOfInsertionSort);
    cout << endl;
    analysisOfMergeSort(arrayOfDataForMergeSort, sizeOfArray, totalOfMergesOfMergeSort);
    cout << endl;
    analysisOfQuickSort(arrayOfDataForQuickSort, sizeOfArray, totalOfPartitionsOfQuickSort, totalOfSwapsOfQuickSort);

    return 0;
}
