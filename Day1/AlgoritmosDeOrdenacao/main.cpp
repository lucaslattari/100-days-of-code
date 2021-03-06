#include <iostream>
#include <ctime>
#include <cstdlib>
#include "stdio.h"
#include "string.h"

#include "bubblesort.h"
#include "selectionsort.h"
#include "insertionsort.h"

using namespace std;

void fillArrayWithRandomNumbers(int* arrayOfData, int sizeOfArray, int maximumValueOfArray)
{
    srand((unsigned)time(nullptr));

    for(int i = 0 ; i < sizeOfArray ; i++)
    {
        int randomNumber = 1 + rand() % maximumValueOfArray;
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

    cout << "Total of iterations of BubbleSort: " << totalOfIterations << endl;
    cout << "Total of swaps: " << totalOfSwaps << endl;
    cout << "Total time in seconds: " << totalTimeInSeconds << endl;
}

void analysisOfSelectionSort(int* arrayOfData, int sizeOfArray, unsigned int& totalOfIterations, unsigned int& totalOfSwaps)
{
    const clock_t beginClockTime    = clock();                                 //contador de tempo inicial
    selectionSort(arrayOfData, sizeOfArray, totalOfIterations, totalOfSwaps);     //executa algoritmo selectionsort
    const clock_t endClockTime      = clock();                                 //contador de tempo final

    float totalTimeInSeconds        = float( endClockTime - beginClockTime ) /  CLOCKS_PER_SEC;
    //printArray(arrayOfData, sizeOfArray);                                      //imprime vetor na tela

    cout << "Total of iterations of SelectionSort: " << totalOfIterations << endl;
    cout << "Total of swaps of SelectionSort: " << totalOfSwaps << endl;
    cout << "Total time in seconds: " << totalTimeInSeconds << endl;
}

void analysisOfInsertionSort(int* arrayOfData, int sizeOfArray, unsigned int& totalOfIterations, unsigned int& totalOfSwaps)
{
    const clock_t beginClockTime    = clock();                                 //contador de tempo inicial
    insertionSort(arrayOfData, sizeOfArray, totalOfIterations, totalOfSwaps);     //executa algoritmo selectionsort
    const clock_t endClockTime      = clock();                                 //contador de tempo final

    float totalTimeInSeconds        = float( endClockTime - beginClockTime ) /  CLOCKS_PER_SEC;
    //printArray(arrayOfData, sizeOfArray);                                      //imprime vetor na tela

    cout << "Total of iterations of InsertionSort: " << totalOfIterations << endl;
    cout << "Total of swaps of InsertionSort: " << totalOfSwaps << endl;
    cout << "Total time in seconds: " << totalTimeInSeconds << endl;
}

int main()
{
    int sizeOfArray                                 = 10000;
    int* arrayOfDataForBubbleSort                   = new int[sizeOfArray];
    int* arrayOfDataForSelectionSort                = new int[sizeOfArray];
    int* arrayOfDataForInsertionSort                = new int[sizeOfArray];

    unsigned int totalOfIterationsOfBubbleSort      = 0;
    unsigned int totalOfSwapOfBubbleSort            = 0;
    unsigned int totalOfIterationsOfSelectionSort   = 0;
    unsigned int totalOfSwapsOfSelectionSort        = 0;
    unsigned int totalOfIterationsOfInsertionSort   = 0;
    unsigned int totalOfSwapsOfInsertionSort        = 0;

    fillArrayWithRandomNumbers(arrayOfDataForBubbleSort, sizeOfArray, 1000000);             //preenche um vetor com n�meros inteiros aleat�rios
    memcpy(arrayOfDataForSelectionSort, arrayOfDataForBubbleSort, sizeof *arrayOfDataForBubbleSort * sizeOfArray); //copia dados do vetor bubble para o vetor selection
    memcpy(arrayOfDataForInsertionSort, arrayOfDataForBubbleSort, sizeof *arrayOfDataForBubbleSort * sizeOfArray); //copia dados do vetor bubble para o vetor insertion

    analysisOfBubbleSort(arrayOfDataForBubbleSort, sizeOfArray, totalOfIterationsOfBubbleSort, totalOfSwapOfBubbleSort);
    cout << endl;
    analysisOfSelectionSort(arrayOfDataForSelectionSort, sizeOfArray, totalOfIterationsOfSelectionSort, totalOfSwapsOfSelectionSort);
    cout << endl;
    analysisOfInsertionSort(arrayOfDataForInsertionSort, sizeOfArray, totalOfIterationsOfInsertionSort, totalOfSwapsOfInsertionSort);

    return 0;
}
