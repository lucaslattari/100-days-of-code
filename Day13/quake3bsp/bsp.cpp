#include <time.h>
#include "bsp.h"

BSP::BSP(string filename)
{
    clock_t startCounter = clock();
    loader = new BSPLoader(filename, &header, &data);
    clock_t endCounter = clock();

    int time = (endCounter - startCounter) * 1000 / CLOCKS_PER_SEC;

    BSPWriter writer("log.txt");
    writer.printBSPLoadedTimeInLog(time/1000, time%1000);
    writer.printHeaderInLog(&header);
    writer.printDataInLog(&data);
}

BSP::~BSP()
{
    delete(loader);
}
