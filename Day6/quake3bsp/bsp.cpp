#include "bsp.h"

BSP::BSP(string filename)
{
    loader = new BSPLoader(filename, &header, &data);

    BSPWriter writer("log.txt");
    writer.printHeaderInLog(&header);
    writer.printDataInLog(&data);
}

BSP::~BSP()
{
    delete(loader);
}
