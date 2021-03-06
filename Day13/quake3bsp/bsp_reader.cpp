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

void BSPLoader::setPointerFileInPositionOfLump(Lump l)
{
    fseek(pointerOfMapFile, l.getOffset(), SEEK_SET);
}


void BSPLoader::loadHeader(BSPHeader* header)
{
    fread(header, 1, sizeof(BSPHeader), pointerOfMapFile);
}

void BSPLoader::loadEntities(Lump l, BSPData* data)
{
    setPointerFileInPositionOfLump(l);

    int totalCharsOfEntity = l.getLength();
    char* tempArray = new char[totalCharsOfEntity];
    fread(tempArray, totalCharsOfEntity, sizeof(char), pointerOfMapFile);
    data->getEntityObject()->setEntity(tempArray);
    delete(tempArray);
}

void BSPLoader::loadTextures(Lump l, BSPData* data)
{
    setPointerFileInPositionOfLump(l);

    int numberOfTextures = l.getLength() / sizeOfTextureInBytes;
    for(int textureIndex = 0 ; textureIndex < numberOfTextures ; textureIndex++)
    {
        Texture* t = new Texture;

        char textureName[64];
        int flags, contents;
        fread(textureName, 64, sizeof(char), pointerOfMapFile);
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
    setPointerFileInPositionOfLump(l);

    int numberOfPlanes = l.getLength() / (sizeOfPlaneInBytes);
    for(int planeIndex = 0 ; planeIndex < numberOfPlanes ; planeIndex++)
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
    setPointerFileInPositionOfLump(l);

    int numberOfNodes = l.getLength() / (sizeOfNodeInBytes);
    for(int nodeIndex = 0 ; nodeIndex < numberOfNodes ; nodeIndex++)
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
    setPointerFileInPositionOfLump(l);

    int numberOfLeaves = l.getLength() / (sizeOfLeafInBytes);
    for(int leafIndex = 0 ; leafIndex < numberOfLeaves ; leafIndex++)
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

void BSPLoader::loadLeafFaces(Lump l, BSPData* data)
{
    setPointerFileInPositionOfLump(l);

    int numberOfLeafFaces = l.getLength() / (sizeOfLeafFaceInBytes);
    for(int leafFaceIndex = 0 ; leafFaceIndex < numberOfLeafFaces ; leafFaceIndex++)
    {
        LeafFace* lf = new LeafFace;

        int faceIndex;
        fread(&faceIndex, 1, sizeof(int), pointerOfMapFile);

        lf->setFaceIndex(faceIndex);

        data->getLeafFaceObject()->insertElement(lf);
    }
}

void BSPLoader::loadLeafBrushes(Lump l, BSPData* data)
{
    setPointerFileInPositionOfLump(l);

    int numberOfLeafBrushes = l.getLength() / (sizeOfLeafBrushInBytes);
    for(int leafBrushIndex = 0 ; leafBrushIndex < numberOfLeafBrushes ; leafBrushIndex++)
    {
        LeafBrush* lb = new LeafBrush;

        int brushIndex;
        fread(&brushIndex, 1, sizeof(int), pointerOfMapFile);

        lb->setBrushIndex(brushIndex);

        data->getLeafBrushObject()->insertElement(lb);
    }
}

void BSPLoader::loadModels(Lump l, BSPData* data)
{
    setPointerFileInPositionOfLump(l);

    int numberOfModels = l.getLength() / (sizeOfModelInBytes);
    for(int modelIndex = 0 ; modelIndex < numberOfModels ; modelIndex++)
    {
        Model* m = new Model;

        int     firstFaceIndex, firstBrushIndex, numberOfFaces, numberOfBrushes;
        float   minCoordBoundingBox[3], maxCoordBoundingBox[3];

        fread(&minCoordBoundingBox[0], 3, sizeof(float), pointerOfMapFile);
        fread(&maxCoordBoundingBox[0], 3, sizeof(float), pointerOfMapFile);
        fread(&firstFaceIndex, 1, sizeof(int), pointerOfMapFile);
        fread(&numberOfFaces, 1, sizeof(int), pointerOfMapFile);
        fread(&firstBrushIndex, 1, sizeof(int), pointerOfMapFile);
        fread(&numberOfBrushes, 1, sizeof(int), pointerOfMapFile);

        m->setMinCoordBoundingBox(minCoordBoundingBox[0], minCoordBoundingBox[1], minCoordBoundingBox[2]);
        m->setMaxCoordBoundingBox(maxCoordBoundingBox[0], maxCoordBoundingBox[1], maxCoordBoundingBox[2]);
        m->setFirstFaceIndex(firstFaceIndex);
        m->setNumberOfFaces(numberOfFaces);
        m->setFirstBrushIndex(firstBrushIndex);
        m->setNumberOfBrushes(numberOfBrushes);

        data->getModelObject()->insertElement(m);
    }
}

void BSPLoader::loadBrushes(Lump l, BSPData* data)
{
    setPointerFileInPositionOfLump(l);

    int numberOfBrushes = l.getLength() / (sizeOfBrushInBytes);
    for(int brushIndex = 0 ; brushIndex < numberOfBrushes ; brushIndex++)
    {
        Brush* b = new Brush;

        int     brushSideFirstIndex, numberOfBrushSides, textureIndex;

        fread(&brushSideFirstIndex, 1, sizeof(int), pointerOfMapFile);
        fread(&numberOfBrushSides, 1, sizeof(int), pointerOfMapFile);
        fread(&textureIndex, 1, sizeof(int), pointerOfMapFile);

        b->setBrushSideFirstIndex(brushSideFirstIndex);
        b->setNumberOfBrushSides(numberOfBrushSides);
        b->setTextureIndex(textureIndex);

        data->getBrushObject()->insertElement(b);
    }
}

void BSPLoader::loadBrushSides(Lump l, BSPData* data)
{
    setPointerFileInPositionOfLump(l);

    int numberOfBrushSides = l.getLength() / (sizeOfBrushSideInBytes);
    for(int brushSideIndex = 0 ; brushSideIndex < numberOfBrushSides ; brushSideIndex++)
    {
        BrushSide* bs = new BrushSide;

        int planeIndex, textureIndex;
        fread(&planeIndex, 1, sizeof(int), pointerOfMapFile);
        fread(&textureIndex, 1, sizeof(int), pointerOfMapFile);

        bs->setPlaneIndex(planeIndex);
        bs->setTextureIndex(textureIndex);

        data->getBrushSideObject()->insertElement(bs);
    }
}

void BSPLoader::loadFaceVertices(Lump l, BSPData* data)
{
    setPointerFileInPositionOfLump(l);

    int numberOfFaceVertices = l.getLength() / (sizeOfFaceVertexInBytes);
    for(int faceVerticeIndex = 0 ; faceVerticeIndex < numberOfFaceVertices ; faceVerticeIndex++)
    {
        FaceVertex* fv = new FaceVertex;

        float           positionCoordinates[3];
        float           textureCoordinates[2];
        float           lightmapCoordinates[2];
        float           normal[3];
        unsigned char   color[4];

        fread(&positionCoordinates[0], 3, sizeof(float), pointerOfMapFile);
        fread(&textureCoordinates[0], 2, sizeof(float), pointerOfMapFile);
        fread(&lightmapCoordinates[0], 2, sizeof(float), pointerOfMapFile);
        fread(&normal[0], 3, sizeof(float), pointerOfMapFile);
        fread(&color[0], 4, sizeof(unsigned char), pointerOfMapFile);

        fv->setPositionCoordinates(positionCoordinates[0], positionCoordinates[1], positionCoordinates[2]);
        fv->setTextureCoordinates(textureCoordinates[0], textureCoordinates[1]);
        fv->setLightmapCoordinates(lightmapCoordinates[0], lightmapCoordinates[1]);
        fv->setNormalVector(normal[0], normal[1], normal[2]);
        fv->setColor(color[0], color[1], color[2], color[3]);

        data->getFaceVertexObject()->insertElement(fv);
    }
}

void BSPLoader::loadTriangleMeshVertices(Lump l, BSPData* data)
{
    setPointerFileInPositionOfLump(l);

    int numberOfTriangleMeshVertices = l.getLength() / (sizeOfTriangleMeshVertexInBytes);
    for(int triangleMeshVertexIndex = 0 ; triangleMeshVertexIndex < numberOfTriangleMeshVertices ; triangleMeshVertexIndex++)
    {
        TriangleMeshVertex* tmv = new TriangleMeshVertex;

        int triangleMeshVertexIndexOffset;
        fread(&triangleMeshVertexIndexOffset, 1, sizeof(int), pointerOfMapFile);

        tmv->setFirstVertexFaceOffset(triangleMeshVertexIndexOffset);

        data->getTriangleMeshVertexObject()->insertElement(tmv);
    }
}

void BSPLoader::loadEffects(Lump l, BSPData* data)
{
    setPointerFileInPositionOfLump(l);

    int numberOfEffects = l.getLength() / (sizeOfEffectInBytes);
    for(int effectIndex = 0 ; effectIndex < numberOfEffects ; effectIndex++)
    {
        Effect* e = new Effect;

        char shaderName[64];
        int brushIndex, unknown;
        fread(shaderName, 64, sizeof(char), pointerOfMapFile);
        fread(&brushIndex, 1, sizeof(int), pointerOfMapFile);
        fread(&unknown, 1, sizeof(int), pointerOfMapFile);

        e->setNameOfShader(shaderName);
        e->setBrushIndexThatGeneratedThisEffect(brushIndex);

        data->getEffectObject()->insertElement(e);
    }
}

void BSPLoader::loadFaces(Lump l, BSPData* data)
{
    setPointerFileInPositionOfLump(l);

    int numberOfFaces = l.getLength() / (sizeOfFaceInBytes);
    for(int faceIndex = 0 ; faceIndex < numberOfFaces ; faceIndex++)
    {
        Face* f = new Face;

        //face data
        int             textureIndex, effectIndex, typeOfFace, firstVertexIndex, numberOfVertices, firstMeshVerticesIndex, numberOfMeshVertices;
        float           normalVector[3] = {0};
        int             bezierPatchDimensions[2] = {0};

        //lightmap face data
        int             lightmapIndex;
        int             cornerCoordinate[2] = {0};
        int             faceSize[2] = {0};
        float           worldCoordinatesOrigin[3] = {0};
        float           worldCoordinatesBitsets[2][3] = {0};

        fread(&textureIndex, 1, sizeof(int), pointerOfMapFile);
        fread(&effectIndex, 1, sizeof(int), pointerOfMapFile);
        fread(&typeOfFace, 1, sizeof(int), pointerOfMapFile);
        fread(&firstVertexIndex, 1, sizeof(int), pointerOfMapFile);
        fread(&numberOfVertices, 1, sizeof(int), pointerOfMapFile);
        fread(&firstMeshVerticesIndex, 1, sizeof(int), pointerOfMapFile);
        fread(&numberOfMeshVertices, 1, sizeof(int), pointerOfMapFile);

        f->setTextureIndex(textureIndex);
        f->setEffectIndex(effectIndex);
        f->setTypeOfFace(typeOfFace);
        f->setFirstVertexIndex(firstVertexIndex);
        f->setNumberOfVertices(numberOfVertices);
        f->setFirstMeshVerticesIndex(firstMeshVerticesIndex);
        f->setNumberOfMeshVertices(numberOfMeshVertices);

        fread(&lightmapIndex, 1, sizeof(int), pointerOfMapFile);
        fread(&cornerCoordinate[0], 2, sizeof(int), pointerOfMapFile);
        fread(&faceSize[0], 2, sizeof(int), pointerOfMapFile);
        fread(&worldCoordinatesOrigin[0], 3, sizeof(float), pointerOfMapFile);
        fread(&worldCoordinatesBitsets[0], 6, sizeof(float), pointerOfMapFile);

        LightmapFace* lf = new LightmapFace;
        lf->setLightmapIndex(lightmapIndex);
        lf->setCornerCoordinates(cornerCoordinate[0], cornerCoordinate[1]);
        lf->setSize(faceSize[0], faceSize[1]);
        lf->setWorldCoordinatesOrigin(worldCoordinatesOrigin[0],worldCoordinatesOrigin[1], worldCoordinatesOrigin[2]);
        lf->setWorldCoordinatesBitsets(worldCoordinatesBitsets[0][0], worldCoordinatesBitsets[1][0], worldCoordinatesBitsets[0][1], worldCoordinatesBitsets[1][1], worldCoordinatesBitsets[0][2], worldCoordinatesBitsets[1][2]);
        f->setLightmapFaceObject(lf);

        fread(&normalVector[0], 3, sizeof(float), pointerOfMapFile);
        fread(&bezierPatchDimensions[0], 2, sizeof(int), pointerOfMapFile);
        f->setNormalVector(normalVector[0], normalVector[1], normalVector[2]);
        f->setBezierPatchDimensions(bezierPatchDimensions[0], bezierPatchDimensions[1]);

        data->getFaceObject()->insertElement(f);
    }
}

void BSPLoader::loadLightmapVolumes(Lump l, BSPData* data)
{
    setPointerFileInPositionOfLump(l);

    int numberOfLightmapVols = l.getLength() / (sizeOfLightmapVolsInBytes);
    for(int lightmapVolIndex = 0 ; lightmapVolIndex < numberOfLightmapVols ; lightmapVolIndex++)
    {
        float ambientColorComponent[3], directionalColorComponent[3], lightDirection[2];

        fread(&ambientColorComponent[0], 3, sizeof(unsigned char), pointerOfMapFile);
        fread(&directionalColorComponent[0], 3, sizeof(unsigned char), pointerOfMapFile);
        fread(&lightDirection[0], 2, sizeof(unsigned char), pointerOfMapFile);

        LightmapVolume* lv  = new LightmapVolume;
        lv->setAmbientColorComponent(ambientColorComponent[0], ambientColorComponent[1], ambientColorComponent[2]);
        lv->setDirectionalColorComponent(directionalColorComponent[0], directionalColorComponent[1], directionalColorComponent[2]);
        lv->setLightDirection(lightDirection[0], lightDirection[1]);

        data->getLightmapVolumeObject()->insertElement(lv);
    }
}

void BSPLoader::loadLightmapColors(Lump l, BSPData* data)
{
    setPointerFileInPositionOfLump(l);

    int numberOfLightmapColorElements = l.getLength() / (sizeOfLightmapColorsInBytes);
    for(int lightmapColorIndex = 0 ; lightmapColorIndex < numberOfLightmapColorElements ; lightmapColorIndex++)
    {
        //lightmap color data
        unsigned char   colorData[128][128][3];
        fread(&colorData[0], 128 * 128 * 3, sizeof(unsigned char), pointerOfMapFile);

        LightmapColor* lc   = new LightmapColor;
        for(int x = 0 ; x < 128 ; x++)
            for(int y = 0 ; y < 128 ; y++)
                for(int c = 0 ; c < 3 ; c++)
                    lc->setLightmapColorData(x, y, c, colorData[x][y][c]);

        data->getLightmapColorObject()->insertElement(lc);
    }
}

void BSPLoader::loadVisData(Lump l, BSPData* data)
{
    setPointerFileInPositionOfLump(l);

    int             numberOfClusters;
    int             sizeOfEachClusterInBytes;

    fread(&numberOfClusters, 1, sizeof(int), pointerOfMapFile);
    data->getVisDataObject()->setNumberOfClusters(numberOfClusters);

    fread(&sizeOfEachClusterInBytes, 1, sizeof(int), pointerOfMapFile);
    data->getVisDataObject()->setSizeOfEachClusterInBytes(sizeOfEachClusterInBytes);

    int bufferSize = numberOfClusters * sizeOfEachClusterInBytes;
    unsigned char* potentiallyVisibleSets = new unsigned char[bufferSize];
    fread(potentiallyVisibleSets, bufferSize, sizeof(unsigned char), pointerOfMapFile);
    data->getVisDataObject()->setArrayOfBytesHoldingTheClusterVisibilitySets(potentiallyVisibleSets);
}

void BSPLoader::loadData(BSPHeader* header, BSPData* data)
{
    loadEntities(header->getLump(idEntityLump), data);
    loadTextures(header->getLump(idTextureLump), data);
    loadPlanes(header->getLump(idPlaneLump), data);
    loadNodes(header->getLump(idNodeLump), data);
    loadLeaves(header->getLump(idLeafLump), data);
    loadLeafFaces(header->getLump(idLeafFaceLump), data);
    loadLeafBrushes(header->getLump(idLeafBrushLump), data);
    loadModels(header->getLump(idModelLump), data);
    loadBrushes(header->getLump(idBrushLump), data);
    loadBrushSides(header->getLump(idBrushSideLump), data);
    loadFaceVertices(header->getLump(idVertexLump), data);
    loadTriangleMeshVertices(header->getLump(idMeshVertLump), data);
    loadEffects(header->getLump(idEffectLump), data);
    loadFaces(header->getLump(idFaceLump), data);
    loadLightmapVolumes(header->getLump(idLightVolLump), data);
    loadLightmapColors(header->getLump(idLightMapLump), data);
    loadVisData(header->getLump(idVisDataLump), data);
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
