#include "bsp.h"

BSP::BSP(string filename)
{
    loader.readFileMap(filename);
    loader.readHeader(&header);

    BSPWriter writer("log.txt");
    writer.printHeaderInLog(&header);
}

BSP::~BSP()
{

}
