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

    Lump* lumps = bspHeader->getArrayOfLumps();
    for(int i = 0 ; i < totalOfLumps ; i++)
    {
        fprintf(filePointerOfLog, "Lump %d:\n", i);
        fprintf(filePointerOfLog, "Offset: %d\n", lumps[i].getOffset());
        fprintf(filePointerOfLog, "Length: %d\n", lumps[i].getLength());
        fprintf(filePointerOfLog, "\n");
    }
}

void BSPWriter::printEntitiesInLog(Entity* e)
{
    fprintf(filePointerOfLog, "Entities: \n%s\n", e->getEntity().c_str());
}

void BSPWriter::printEachTextureDataInLog(Texture* textureObject)
{
    fprintf(filePointerOfLog, "Name: %s\n", textureObject->getName().c_str());
    fprintf(filePointerOfLog, "Flags: %d\n", textureObject->getFlags());
    fprintf(filePointerOfLog, "Content: %d\n", textureObject->getContents());
}

void BSPWriter::printDataInLog(BSPData* data)
{
    printEntitiesInLog(data->getEntityObject());

    fprintf(filePointerOfLog, "Textures: %d\n", data->getTextureArray().getTotalOfElements());
    for(int textureIndex = 0 ; textureIndex < data->getTextureArray().getTotalOfElements() ; textureIndex++)
    {
        fprintf(filePointerOfLog, "%d: \n", textureIndex);
        printEachTextureDataInLog(data->getTextureArray().getElementByIndex(textureIndex));
    }
}
