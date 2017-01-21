#ifndef _BSPREADER_H_
#define _BSPREADER_H_

#include <stdio.h>
#include "bsp_header_file.h"
#include "bsp_data.h"
#include "lump_array.h"

class BSPLoader
{
private:
    FILE* pointerOfMapFile;

    void loadHeader(BSPHeader* header);
    void loadData(BSPHeader* header, BSPData* data);
    int  loadFile(string filename, BSPHeader* header, BSPData* data);

    void loadEntities(Lump l, BSPData* data);
    void loadTextures(Lump l, BSPData* data);
    void loadPlanes(Lump l, BSPData* data);
    void loadNodes(Lump l, BSPData* data);
    void loadLeaves(Lump l, BSPData* data);
    void loadLeafFaces(Lump l, BSPData* data);
    void loadLeafBrushes(Lump l, BSPData* data);
    void loadModels(Lump l, BSPData* data);
    void loadBrushes(Lump l, BSPData* data);
    void loadBrushSides(Lump l, BSPData* data);
    void loadFaceVertices(Lump l, BSPData* data);
    void loadTriangleMeshVertices(Lump l, BSPData* data);
    void loadEffects(Lump l, BSPData* data);
    void loadFaces(Lump l, BSPData* data);
    void loadLightmapVolumes(Lump l, BSPData* data);
    void loadLightmapColors(Lump l, BSPData* data);
    void loadVisData(Lump l, BSPData* data);

    void setPointerFileInPositionOfLump(Lump l);

public:
    BSPLoader(string filename, BSPHeader* header, BSPData* data);
    ~BSPLoader();
};

#endif // _BSPREADER_H_
