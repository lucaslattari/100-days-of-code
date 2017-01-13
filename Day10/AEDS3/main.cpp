#include <iostream>
#include <ctime>
#include <cstdlib>
#include "stdio.h"
#include "string.h"
#include <algorithm>

#include "bubblesort.h"
#include "selectionsort.h"
#include "insertionsort.h"
#include "mergesort.h"
#include "quicksort.h"
#include "heapsort.h"

#include "binarysearchtree.h"
#include "redblacktree.h"

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

void readArrayDataFromDisk(char* pathOfFile, int* arrayOfData, int& sizeOfArray)
{
    FILE* f = fopen(pathOfFile, "a+");
    int scanfData;
    int numberOfScanfs = 0;

    while(fscanf(f, "%d", &scanfData) != EOF)
    {
        if(numberOfScanfs == sizeOfArray)
        {
            printf("ERRO: Numero de elementos passados via .txt supera o tamanho do array.");
            exit(1);
        }

        arrayOfData[numberOfScanfs] = scanfData;
        numberOfScanfs++;
    }

    sizeOfArray = numberOfScanfs;

    fclose(f);
}

void printArray(int* arrayOfData, int sizeOfArray)
{
    cout << "Content: ";
    for(int i = 0 ; i < sizeOfArray ; i++)
        cout << arrayOfData[i] << " ";
    cout << endl;
}

void printArrayForHeapsort(int* arrayOfData, int sizeOfArray)
{
    cout << "Content: ";
    for(int i = 1 ; i <= sizeOfArray ; i++)
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

void analysisOfHeapSort(int* arrayOfData, int sizeOfArray)
{
    const clock_t beginClockTime    = clock();  //contador de tempo inicial
    heapSort(arrayOfData, sizeOfArray);         //executa algoritmo heapsort
    const clock_t endClockTime      = clock();  //contador de tempo final

    float totalTimeInSeconds        = float( endClockTime - beginClockTime ) /  CLOCKS_PER_SEC;
    //printArray(arrayOfData, sizeOfArray);                                      //imprime vetor na tela

    cout << "Total time of HeapSort in seconds: " << totalTimeInSeconds << endl;
}

void testingAllSortingAlgorithms()
{
    int sizeOfArray                                 = 200000;
    int* arrayOfDataForBubbleSort                   = new int[sizeOfArray];
    int* arrayOfDataForSelectionSort                = new int[sizeOfArray];
    int* arrayOfDataForInsertionSort                = new int[sizeOfArray];
    int* arrayOfDataForMergeSort                    = new int[sizeOfArray];
    int* arrayOfDataForQuickSort                    = new int[sizeOfArray];
    int* arrayOfDataForHeapSort                     = new int[sizeOfArray + 1];

    unsigned int totalOfIterationsOfBubbleSort      = 0;
    unsigned int totalOfSwapsOfBubbleSort           = 0;
    unsigned int totalOfIterationsOfSelectionSort   = 0;
    unsigned int totalOfSwapsOfSelectionSort        = 0;
    unsigned int totalOfIterationsOfInsertionSort   = 0;
    unsigned int totalOfSwapsOfInsertionSort        = 0;
    unsigned int totalOfMergesOfMergeSort           = 0;
    unsigned int totalOfPartitionsOfQuickSort       = 0;
    unsigned int totalOfSwapsOfQuickSort            = 0;

    fillArrayWithRandomNumbers(arrayOfDataForBubbleSort, sizeOfArray, 100000);             //preenche um vetor com números inteiros aleatórios
    //readArrayDataFromDisk("input.txt", arrayOfDataForBubbleSort, sizeOfArray);

    memcpy(arrayOfDataForSelectionSort, arrayOfDataForBubbleSort, sizeof *arrayOfDataForBubbleSort * sizeOfArray); //copia dados do vetor bubble para o vetor selection
    memcpy(arrayOfDataForInsertionSort, arrayOfDataForBubbleSort, sizeof *arrayOfDataForBubbleSort * sizeOfArray); //copia dados do vetor bubble para o vetor insertion
    memcpy(arrayOfDataForMergeSort, arrayOfDataForBubbleSort, sizeof *arrayOfDataForBubbleSort * sizeOfArray); //copia dados do vetor bubble para o vetor mergesort
    memcpy(arrayOfDataForQuickSort, arrayOfDataForBubbleSort, sizeof *arrayOfDataForBubbleSort * sizeOfArray); //copia dados do vetor bubble para o vetor quicksort
    memcpy(&arrayOfDataForHeapSort[1], arrayOfDataForBubbleSort, sizeof *arrayOfDataForBubbleSort * sizeOfArray); //copia dados do vetor bubble para o vetor heapsort

    analysisOfBubbleSort(arrayOfDataForBubbleSort, sizeOfArray, totalOfIterationsOfBubbleSort, totalOfSwapsOfBubbleSort);
    delete(arrayOfDataForBubbleSort);

    cout << endl;
    analysisOfSelectionSort(arrayOfDataForSelectionSort, sizeOfArray, totalOfIterationsOfSelectionSort, totalOfSwapsOfSelectionSort);
    delete(arrayOfDataForSelectionSort);

    cout << endl;
    analysisOfInsertionSort(arrayOfDataForInsertionSort, sizeOfArray, totalOfIterationsOfInsertionSort, totalOfSwapsOfInsertionSort);
    delete(arrayOfDataForInsertionSort);

    cout << endl;
    analysisOfMergeSort(arrayOfDataForMergeSort, sizeOfArray, totalOfMergesOfMergeSort);
    delete(arrayOfDataForMergeSort);

    cout << endl;
    analysisOfQuickSort(arrayOfDataForQuickSort, sizeOfArray, totalOfPartitionsOfQuickSort, totalOfSwapsOfQuickSort);
    delete(arrayOfDataForQuickSort);

    cout << endl;
    analysisOfHeapSort(arrayOfDataForHeapSort, sizeOfArray);
    delete(arrayOfDataForHeapSort);
}

void experimentsWithBinarySearchTree()
{
    BinarySearchTree bst;

    bst.putValueInBST("s", 19);
    bst.putValueInBST("e", 5);
    bst.putValueInBST("a", 1);
    bst.putValueInBST("c", 3);
    bst.putValueInBST("x", 24);
    bst.putValueInBST("r", 18);
    bst.putValueInBST("h", 8);
    bst.putValueInBST("m", 13);

    printf("Value of s = %d\n", bst.getValue("s"));
    printf("Value of e = %d\n", bst.getValue("e"));
    printf("Value of a = %d\n", bst.getValue("a"));
    printf("Value of c = %d\n", bst.getValue("c"));
    printf("Value of x = %d\n", bst.getValue("x"));
    printf("Value of r = %d\n", bst.getValue("r"));
    printf("Value of h = %d\n", bst.getValue("h"));
    printf("Value of m = %d\n", bst.getValue("m"));

    printf("Size = %d\n", bst.getSize());
    printf("Value of minimum key: %d\n", bst.getValueOfMinimumKey());
    printf("Value of maximum key: %d\n", bst.getValueOfMaximumKey());
    printf("Floor of e: %c\n", *(bst.getKeyOfFloorNode("e")));
    printf("Ceiling of e: %c\n", *(bst.getKeyOfCeilingNode("e")));
    printf("Key of rank 3: %c\n", *(bst.getKeyByRank(3)));
    printf("Rank of key s: %d\n", bst.getRankByKey("s"));

    bst.deleteNode("e");
    bst.printTree();
}

void experimentsWithRedBlackTree()
{
    RedBlackTree rbt;
    int counterOfValue = 0;

    rbt.putValueInRBT("a", ++counterOfValue);
    rbt.putValueInRBT("b", ++counterOfValue);
    rbt.putValueInRBT("c", ++counterOfValue);
    rbt.putValueInRBT("d", ++counterOfValue);
    rbt.putValueInRBT("e", ++counterOfValue);
    rbt.putValueInRBT("f", ++counterOfValue);
    rbt.putValueInRBT("g", ++counterOfValue);
    rbt.putValueInRBT("h", ++counterOfValue);
    rbt.putValueInRBT("i", ++counterOfValue);
    rbt.putValueInRBT("j", ++counterOfValue);
    rbt.putValueInRBT("k", ++counterOfValue);
    rbt.putValueInRBT("l", ++counterOfValue);
    rbt.putValueInRBT("m", ++counterOfValue);
    rbt.putValueInRBT("n", ++counterOfValue);
    rbt.putValueInRBT("o", ++counterOfValue);
    rbt.putValueInRBT("p", ++counterOfValue);
    rbt.putValueInRBT("q", ++counterOfValue);
    rbt.putValueInRBT("r", ++counterOfValue);
    rbt.putValueInRBT("s", ++counterOfValue);
    rbt.putValueInRBT("t", ++counterOfValue);
    rbt.putValueInRBT("u", ++counterOfValue);
    rbt.putValueInRBT("v", ++counterOfValue);
    rbt.putValueInRBT("w", ++counterOfValue);
    rbt.putValueInRBT("x", ++counterOfValue);
    rbt.putValueInRBT("y", ++counterOfValue);
    rbt.putValueInRBT("z", ++counterOfValue);
    rbt.printTree();
}

int main()
{
    //testingAllSortingAlgorithms();
    //experimentsWithBinarySearchTree();
    experimentsWithRedBlackTree();

    return 0;
}
