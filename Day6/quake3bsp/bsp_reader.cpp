#include "bsp_reader.h"

BSPLoader::BSPLoader(string filename, BSPHeader* header, BSPData* data)
{
    pointerOfMapFile = nullptr;

    loadFile(filename, header, data);
}

BSPLoader::~BSPLoader()
{
    if(pointerOfMapFile)
        fclose(pointerOfMapFile);
}

void BSPLoader::loadHeader(BSPHeader* header)
{
    fread(header, 1, sizeof(BSPHeader), pointerOfMapFile);
}

void BSPLoader::loadEntities(Lump l, BSPData* data)
{
    fseek(pointerOfMapFile, l.getOffset(), SEEK_SET);

    int totalCharsOfEntity = l.getLength();
    char* tempArray = new char[totalCharsOfEntity];
    fread(tempArray, totalCharsOfEntity, sizeof(char), pointerOfMapFile);
    data->getEntityObject()->setEntity(tempArray);
    delete(tempArray);
}

void BSPLoader::loadTextures(Lump l, BSPData* data)
{
    fseek(pointerOfMapFile, l.getOffset(), SEEK_SET);

    int numberOfTextures = l.getLength() / sizeOfTextureInBytes;
    for(int textureIndex = 0 ; textureIndex < numberOfTextures ; ++textureIndex)
    {
        Texture* t = new Texture;

        char textureName[64];
        int flags, contents;
        fread(textureName, 1, 64, pointerOfMapFile);
        fread(&flags, 1, sizeof(int), pointerOfMapFile);
        fread(&contents, 1, sizeof(int), pointerOfMapFile);

        t->setName(textureName);
        t->setFlags(flags);
        t->setContents(contents);

        data->getTextureObject()->insertElement(t);
    }
}

void BSPLoader::loadPlanes(Lump l, BSPData* data)
{
    fseek(pointerOfMapFile, l.getOffset(), SEEK_SET);

    int numberOfPlanes = l.getLength() / (sizeOfPlaneInBytes);
    for(int planeIndex = 0 ; planeIndex < numberOfPlanes ; ++planeIndex)
    {
        Plane* p = new Plane;

        float normal[3], distanceFromOriginToPlane;
        fread(&normal[0], 1, sizeof(float) * 3, pointerOfMapFile);
        fread(&distanceFromOriginToPlane, 1, sizeof(float), pointerOfMapFile);

        p->setNormal(normal[0], normal[1], normal[2]);
        p->setDistanceFromOriginToPlane(distanceFromOriginToPlane);

        data->getPlaneObject()->insertElement(p);
    }
}

void BSPLoader::loadNodes(Lump l, BSPData* data)
{
    fseek(pointerOfMapFile, l.getOffset(), SEEK_SET);

    int numberOfNodes = l.getLength() / (sizeOfNodeInBytes);
    for(int nodeIndex = 0 ; nodeIndex < numberOfNodes ; ++nodeIndex)
    {
        Node* n = new Node;

        int planeIndex, childrenIndices[2], minCoordBoundingBox[3], maxCoordBoundingBox[3];

        fread(&planeIndex, 1, sizeof(int), pointerOfMapFile);
        fread(&childrenIndices[0], 2, sizeof(int), pointerOfMapFile);
        fread(&minCoordBoundingBox[0], 3, sizeof(int), pointerOfMapFile);
        fread(&maxCoordBoundingBox[0], 3, sizeof(int), pointerOfMapFile);

        n->setPlaneIndex(planeIndex);
        n->setChildrenIndices(childrenIndices[0], childrenIndices[1]);
        n->setMinCoordBoundingBox(minCoordBoundingBox[0], minCoordBoundingBox[1], minCoordBoundingBox[2]);
        n->setMaxCoordBoundingBox(maxCoordBoundingBox[0], maxCoordBoundingBox[1], maxCoordBoundingBox[2]);

        data->getNodeObject()->insertElement(n);
    }
}

void BSPLoader::loadLeaves(Lump l, BSPData* data)
{
    fseek(pointerOfMapFile, l.getOffset(), SEEK_SET);

    int numberOfLeaves = l.getLength() / (sizeOfLeafInBytes);
    for(int leafIndex = 0 ; leafIndex < numberOfLeaves ; ++leafIndex)
    {
        Leaf* l = new Leaf;

        int     clusterIndex, area, leafFaceIndex, numberOfLeafFaces, leafBrushIndex, numberOfLeafBrushes;
        int     minCoordBoundingBox[3], maxCoordBoundingBox[3];

        fread(&clusterIndex, 1, sizeof(int), pointerOfMapFile);
        fread(&area, 1, sizeof(int), pointerOfMapFile);
        fread(&minCoordBoundingBox[0], 3, sizeof(int), pointerOfMapFile);
        fread(&maxCoordBoundingBox[0], 3, sizeof(int), pointerOfMapFile);
        fread(&leafFaceIndex, 1, sizeof(int), pointerOfMapFile);
        fread(&numberOfLeafFaces, 1, sizeof(int), pointerOfMapFile);
        fread(&leafBrushIndex, 1, sizeof(int), pointerOfMapFile);
        fread(&numberOfLeafBrushes, 1, sizeof(int), pointerOfMapFile);

        l->setClusterIndex(clusterIndex);
        l->setArea(area);
        l->setMinCoordBoundingBox(minCoordBoundingBox[0], minCoordBoundingBox[1], minCoordBoundingBox[2]);
        l->setMaxCoordBoundingBox(maxCoordBoundingBox[0], maxCoordBoundingBox[1], maxCoordBoundingBox[2]);
        l->setLeafFaceIndex(leafFaceIndex);
        l->setNumberOfLeafFaces(numberOfLeafFaces);
        l->setLeafBrushIndex(leafBrushIndex);
        l->setNumberOfLeafBrushes(numberOfLeafBrushes);

        data->getLeafObject()->insertElement(l);
    }
}

void BSPLoader::loadData(BSPHeader* header, BSPData* data)
{
    loadEntities(header->getLump(idEntityLump), data);
    loadTextures(header->getLump(idTextureLump), data);
    loadPlanes(header->getLump(idPlaneLump), data);
    loadNodes(header->getLump(idNodeLump), data);
    loadLeaves(header->getLump(idLeafLump), data);
}

int BSPLoader::loadFile(string filename, BSPHeader* header, BSPData* data)
{
    pointerOfMapFile = fopen(filename.c_str(), "r+b");

    if(!pointerOfMapFile)
    {
        printf("ERROR: Invalid stream handler.");
        return 0;
    }

    loadHeader(header);
    loadData(header, data);

    return 1;
}
