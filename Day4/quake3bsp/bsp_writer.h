#ifndef _BSPWRITER_H_
#define _BSPWRITER_H_

#include <stdio.h>
#include "bsp_header_file.h"

class BSPWriter
{
    FILE* filePointerOfLog;
public:
    BSPWriter(string filenameOfLog);
    ~BSPWriter();

    void printHeaderInLog(BSPHeader* bspHeader);
};

#endif // _BSPWRITER_H_
