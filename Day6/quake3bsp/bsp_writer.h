#ifndef _BSPWRITER_H_
#define _BSPWRITER_H_

#include <stdio.h>
#include "bsp_header_file.h"
#include "bsp_data.h"

class BSPWriter
{
private:
    FILE*   filePointerOfLog;
    void    printEntitiesInLog(Entity* e);
    void    printEachTextureDataInLog(Texture* t);
    void    printEachPlaneDataInLog(Plane* p);
    void    printEachNodeDataInLog(Node* p);
    void    printEachLeafDataInLog(Leaf* l);

public:
    BSPWriter(string filenameOfLog);
    ~BSPWriter();

    void    printHeaderInLog(BSPHeader* bspHeader);
    void    printDataInLog(BSPData* data);
};

#endif // _BSPWRITER_H_
