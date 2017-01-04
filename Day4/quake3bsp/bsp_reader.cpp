#include "bsp_reader.h"

BSPLoader::BSPLoader()
{
    pointerOfMapFile = nullptr;
}

BSPLoader::~BSPLoader()
{
    if(pointerOfMapFile)
        fclose(pointerOfMapFile);
}

int BSPLoader::readHeader(BSPHeader* bspHeader)
{
    fread(bspHeader, 1, sizeof(BSPHeader), pointerOfMapFile);
}

int BSPLoader::readFileMap(string filename)
{
    pointerOfMapFile = fopen(filename.c_str(), "r+b");

    if(!pointerOfMapFile)
    {
        printf("ERROR: Invalid stream handler.");
        return 0;
    }

    return 1;
}

