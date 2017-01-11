#include "stdio.h"
#include "heapsort.h"

using namespace std;

//quando a prioridade de um nó é aumentada (ou um novo nó é adicionado no "fundo" do heap) deve-se navegar para "cima" para restaurar a ordem do heap
//quando a prioridade de um nó é diminuída (por exemplo, se substituirmos um nó da raiz com um novo nó com chave menor) deve-se navegar para baixo para se restaurar a ordem do heap

void heapify(int* arrayOfData, int positionOfNode, int sizeOfArray) //nó deve mover-se para um nivel abaixo para atender critério de heap
{
    while(2 * positionOfNode <= sizeOfArray)
    {
        int childrenNode = 2 * positionOfNode;
        if(childrenNode < sizeOfArray && arrayOfData[childrenNode] < arrayOfData[childrenNode + 1])
            childrenNode++;
        if(arrayOfData[positionOfNode] >= arrayOfData[childrenNode])
            break;
        swapElementsInArray(arrayOfData, positionOfNode, childrenNode);
        positionOfNode = childrenNode;
    }
}

void heapSort(int* arrayOfData, int sizeOfArray)
{
    for(int k = sizeOfArray / 2 ; k >= 1 ; k--)
        heapify(arrayOfData, k, sizeOfArray);

    int auxSize = sizeOfArray;
    while(auxSize >= 1)
    {
        swapElementsInArray(arrayOfData, 1, auxSize);
        auxSize--;
        heapify(arrayOfData, 1, auxSize);
    }
}
