#include "bsp_writer.h"

BSPWriter::BSPWriter(string filenameOfLog)
{
    filePointerOfLog = fopen(filenameOfLog.c_str(), "a+");
}

BSPWriter::~BSPWriter()
{
    fclose(filePointerOfLog);
}

void BSPWriter::printHeaderInLog(BSPHeader* bspHeader)
{
    fprintf(filePointerOfLog, "********** HEADER ***********\n");
    fprintf(filePointerOfLog, "BSP Code: %s\n", bspHeader->getFileIdentifier());
    fprintf(filePointerOfLog, "Version: %d\n\n", bspHeader->getVersion());

    lump* lumps = bspHeader->getArrayOfLumps();
    for(int i = 0 ; i < totalOfLumps ; i++)
    {
        fprintf(filePointerOfLog, "Lump %d:\n", i);
        fprintf(filePointerOfLog, "Offset: %d\n", lumps[i].getOffset());
        fprintf(filePointerOfLog, "Length: %d\n", lumps[i].getLength());
        fprintf(filePointerOfLog, "\n");
    }
}
