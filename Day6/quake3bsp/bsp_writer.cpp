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

void BSPWriter::printEachPlaneDataInLog(Plane* planeObject)
{
    fprintf(filePointerOfLog, "Normal: %f %f %f\n", planeObject->getNormal()[0], planeObject->getNormal()[1], planeObject->getNormal()[2]);
    fprintf(filePointerOfLog, "Distance from origin to plane: %f\n\n", planeObject->getDistanceFromOriginToPlane());
}

void BSPWriter::printEachNodeDataInLog(Node* nodeObject)
{
    fprintf(filePointerOfLog, "Plane index: %d\n", nodeObject->getPlaneIndex());
    fprintf(filePointerOfLog, "Children indices: %d %d\n", nodeObject->getChildrenIndices()[0], nodeObject->getChildrenIndices()[1]);
    fprintf(filePointerOfLog, "Minimum coordinate bounding box: %d %d %d\n", nodeObject->getMinCoordBoundingBox()[0], nodeObject->getMinCoordBoundingBox()[1], nodeObject->getMinCoordBoundingBox()[2]);
    fprintf(filePointerOfLog, "Maximum coordinate bounding box: %d %d %d\n\n", nodeObject->getMaxCoordBoundingBox()[0], nodeObject->getMaxCoordBoundingBox()[1], nodeObject->getMaxCoordBoundingBox()[2]);
}

void BSPWriter::printEachLeafDataInLog(Leaf* leafObject)
{
    fprintf(filePointerOfLog, "Cluster index: %d\n", leafObject->getClusterIndex());
    fprintf(filePointerOfLog, "Minimum coordinate bounding box: %d %d %d\n", leafObject->getMinCoordBoundingBox()[0], leafObject->getMinCoordBoundingBox()[1], leafObject->getMinCoordBoundingBox()[2]);
    fprintf(filePointerOfLog, "Maximum coordinate bounding box: %d %d %d\n", leafObject->getMaxCoordBoundingBox()[0], leafObject->getMaxCoordBoundingBox()[1], leafObject->getMaxCoordBoundingBox()[2]);
    fprintf(filePointerOfLog, "Leaf face index: %d\n", leafObject->getLeafFaceIndex());
    fprintf(filePointerOfLog, "Number of leaf faces: %d\n", leafObject->getNumberOfLeafFaces());
    fprintf(filePointerOfLog, "Leaf brush index: %d\n", leafObject->getLeafBrushIndex());
    fprintf(filePointerOfLog, "Number of leaf brushes: %d\n", leafObject->getNumberOfLeafBrushes());
}

void BSPWriter::printDataInLog(BSPData* data)
{
    printEntitiesInLog(data->getEntityObject());

    fprintf(filePointerOfLog, "*************** TEXTURES ***************\nTotal: %d\n", data->getTextureObject()->getTotalOfElements());
    for(int textureIndex = 0 ; textureIndex < data->getTextureObject()->getTotalOfElements() ; textureIndex++)
    {
        fprintf(filePointerOfLog, "Texture id: %d: \n", textureIndex);
        printEachTextureDataInLog(data->getTextureObject()->getElementByIndex(textureIndex));
    }
    fprintf(filePointerOfLog, "\n");

    fprintf(filePointerOfLog, "*************** PLANES ***************\nTotal: %d\n", data->getPlaneObject()->getTotalOfElements());
    for(int planeIndex = 0 ; planeIndex < data->getPlaneObject()->getTotalOfElements() ; planeIndex++)
    {
        fprintf(filePointerOfLog, "Plane id: %d: \n", planeIndex);
        printEachPlaneDataInLog(data->getPlaneObject()->getElementByIndex(planeIndex));
    }

    fprintf(filePointerOfLog, "*************** NODES ***************\nTotal: %d\n", data->getNodeObject()->getTotalOfElements());
    for(int nodeIndex = 0 ; nodeIndex < data->getNodeObject()->getTotalOfElements() ; nodeIndex++)
    {
        fprintf(filePointerOfLog, "Node id: %d: \n", nodeIndex);
        printEachNodeDataInLog(data->getNodeObject()->getElementByIndex(nodeIndex));
    }

    fprintf(filePointerOfLog, "*************** LEAVES ***************\nTotal: %d\n", data->getNodeObject()->getTotalOfElements());
    for(int leafIndex = 0 ; leafIndex < data->getLeafObject()->getTotalOfElements() ; leafIndex++)
    {
        fprintf(filePointerOfLog, "Leaf id: %d: \n", leafIndex);
        printEachLeafDataInLog(data->getLeafObject()->getElementByIndex(leafIndex));
    }
}
