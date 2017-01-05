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

        data->getTextureArray().insertElement(t);
        data->getTextureArray().elements.push_back(t);

        printf("%p\n", data->getTextureArray().elements[0]);
        getchar();
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

        data->getPlaneArray().insertElement(p);
    }
}

void BSPLoader::loadData(BSPHeader* header, BSPData* data)
{
    loadEntities(header->getLump(idEntityLump), data);
    loadTextures(header->getLump(idTextureLump), data);
    loadPlanes(header->getLump(idPlaneLump), data);
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
