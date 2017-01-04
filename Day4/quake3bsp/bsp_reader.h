#ifndef _BSPREADER_H_
#define _BSPREADER_H_

#include <stdio.h>
#include "bsp_header_file.h"

class BSPLoader
{
private:
    FILE* pointerOfMapFile;
public:
    int readHeader(BSPHeader* bspHeader);
    int readFileMap(string filename);
    BSPLoader();
    ~BSPLoader();
};

#endif // _BSPREADER_H_
