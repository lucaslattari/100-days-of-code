#ifndef _BSPHEADER_H_
#define _BSPHEADER_H_

#include <string>
#include "lump.h"

using namespace std;

const int totalOfLumps = 17;

class BSPHeader
{
private:
    char        fileIdentifier[4];         //IBSP
    int         version;                //0x2e
    lump        lumps[totalOfLumps];

public:
    char* getFileIdentifier()
    {
        return fileIdentifier;
    }

    int  getVersion()
    {
        return version;
    }

    lump* getArrayOfLumps()
    {
        return &lumps[0];
    }
};

#endif // _BSPHEADER_H_
