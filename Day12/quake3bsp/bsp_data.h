#ifndef _BSPDATA_H_
#define _BSPDATA_H_

#include <stdio.h>
#include <cstdlib>
#include <vector>
#include "lump_array.h"

using namespace std;

class Entity
{
private:
    //game-related map information, including information about the map name, weapons, health, armor, triggers, spawn points, lights, and .md3 models to be placed in the map
    string name;

public:
    void setEntity(char* name)
    {
        this->name = name;
    }

    string getEntity()
    {
        return this->name;
    }
};

class Texture
{
private:
    string  name;
    int     flags;
    int     contents;

public:
    string getName()
    {
        return name;
    }

    int getFlags()
    {
        return flags;
    }

    int getContents()
    {
        return contents;
    }

    void setName(string name)
    {
        this->name = name;
    }

    void setFlags(int flags)
    {
        this->flags = flags;
    }

    void setContents(int contents)
    {
        this->contents = contents;
    }
};

class Plane
{
private:
    float   normal[3];  //plane normal
    float   distanceFromOriginToPlane;       //Distance from origin to plane along normal.
public:
    float* getNormal()
    {
        return &normal[0];
    }

    float getDistanceFromOriginToPlane()
    {
        return distanceFromOriginToPlane;
    }

    void setNormal(int x, int y, int z)
    {
        normal[0] = x; normal[1] = y; normal[2] = z;
    }

    void setDistanceFromOriginToPlane(int distanceFromOriginToPlane)
    {
        this->distanceFromOriginToPlane = distanceFromOriginToPlane;
    }
};

class Node
{
private:
    int     planeIndex;          //index
    int     childrenIndices[2];    //Negative numbers are leaf indices: -(leaf+1)
    int     minCoordBoundingBox[3];        //Integer bounding box min coord.
    int     maxCoordBoundingBox[3];        //Integer bounding box max coord.

public:
    int getPlaneIndex()
    {
        return planeIndex;
    }

    void setPlaneIndex(int planeIndex)
    {
        this->planeIndex = planeIndex;
    }

    int* getChildrenIndices()
    {
        return &childrenIndices[0];
    }

    void setChildrenIndices(int leftChild, int rightChild)
    {
        this->childrenIndices[0] = leftChild;
        this->childrenIndices[1] = rightChild;
    }

    int* getMinCoordBoundingBox()
    {
        return &minCoordBoundingBox[0];
    }

    int* getMaxCoordBoundingBox()
    {
        return &maxCoordBoundingBox[0];
    }

    void setMinCoordBoundingBox(int x, int y, int z)
    {
        this->minCoordBoundingBox[0] = x; this->minCoordBoundingBox[1] = y; this->minCoordBoundingBox[2] = z;
    }

    void setMaxCoordBoundingBox(int x, int y, int z)
    {
        this->maxCoordBoundingBox[0] = x; this->maxCoordBoundingBox[1] = y; this->maxCoordBoundingBox[2] = z;
    }
};

class LeafFace
{
private:
    int     faceIndex;

public:
    void setFaceIndex(int faceIndex)
    {
        this->faceIndex = faceIndex;
    }

    int getFaceIndex()
    {
        return faceIndex;
    }
};

class LeafBrush
{
private:
    int     brushIndex;

public:
    void setBrushIndex(int brushIndex)
    {
        this->brushIndex = brushIndex;
    }

    int getBrushIndex()
    {
        return brushIndex;
    }
};

class Leaf : public Node
{
private:
    int     clusterIndex;            //pvs, if cluster is negative, the leaf is outside the map or otherwise invalid.
    int     area;
    int     leafFaceIndex;           //for rendering
    int     numberOfLeafFaces;
    int     leafBrushIndex;          //for collision detection
    int     numberOfLeafBrushes;
    int     minCoordBoundingBox[3];        //Integer bounding box min coord.
    int     maxCoordBoundingBox[3];        //Integer bounding box max coord.

public:
    void setClusterIndex(int clusterIndex)
    {
        this->clusterIndex = clusterIndex;
    }

    int getClusterIndex()
    {
        return clusterIndex;
    }

    int* getMinCoordBoundingBox()
    {
        return &minCoordBoundingBox[0];
    }

    int* getMaxCoordBoundingBox()
    {
        return &maxCoordBoundingBox[0];
    }

    void setMinCoordBoundingBox(int x, int y, int z)
    {
        this->minCoordBoundingBox[0] = x; this->minCoordBoundingBox[1] = y; this->minCoordBoundingBox[2] = z;
    }

    void setMaxCoordBoundingBox(int x, int y, int z)
    {
        this->maxCoordBoundingBox[0] = x; this->maxCoordBoundingBox[1] = y; this->maxCoordBoundingBox[2] = z;
    }

    void setArea(int area)
    {
        this->area = area;
    }

    int getArea()
    {
        return area;
    }

    void setLeafFaceIndex(int leafFaceIndex)
    {
        this->leafFaceIndex = leafFaceIndex;
    }

    int getLeafFaceIndex()
    {
        return leafFaceIndex;
    }

    void setNumberOfLeafFaces(int numberOfLeafFaces)
    {
        this->numberOfLeafFaces = numberOfLeafFaces;
    }

    int getNumberOfLeafFaces()
    {
        return numberOfLeafFaces;
    }

    void setLeafBrushIndex(int leafBrushIndex)
    {
        this->leafBrushIndex = leafBrushIndex;
    }

    int getLeafBrushIndex()
    {
        return leafBrushIndex;
    }

    void setNumberOfLeafBrushes(int numberOfLeafBrushes)
    {
        this->numberOfLeafBrushes = numberOfLeafBrushes;
    }

    int getNumberOfLeafBrushes()
    {
        return numberOfLeafBrushes;
    }
};

class Model
{
private:
    float   minCoordBoundingBox[3];
    float   maxCoordBoundingBox[3];
    int     firstFaceIndex;               //	First face for model
    int     numberOfFaces;
    int     firstBrushIndex;              // first brush for model.
    int     numberOfBrushes;

public:
    void setMinCoordBoundingBox(int x, int y, int z)
    {
        this->minCoordBoundingBox[0] = x; this->minCoordBoundingBox[1] = y; this->minCoordBoundingBox[2] = z;
    }

    float* getMinCoordBoundingBox()
    {
        return &minCoordBoundingBox[0];
    }

    void setMaxCoordBoundingBox(int x, int y, int z)
    {
        this->maxCoordBoundingBox[0] = x; this->maxCoordBoundingBox[1] = y; this->maxCoordBoundingBox[2] = z;
    }

    float* getMaxCoordBoundingBox()
    {
        return &maxCoordBoundingBox[0];
    }

    void setFirstFaceIndex(int firstFaceIndex)
    {
        this->firstFaceIndex = firstFaceIndex;
    }

    int getFirstFaceIndex()
    {
        return firstFaceIndex;
    }

    void setNumberOfFaces(int numberOfFaces)
    {
        this->numberOfFaces = numberOfFaces;
    }

    int getNumberOfFaces()
    {
        return numberOfFaces;
    }

    void setFirstBrushIndex(int firstBrushIndex)
    {
        this->firstBrushIndex = firstBrushIndex;
    }

    int getFirstBrushIndex()
    {
        return firstBrushIndex;
    }

    void setNumberOfBrushes(int numberOfBrushes)
    {
        this->numberOfBrushes = numberOfBrushes;
    }

    int getNumberOfBrushes()
    {
        return numberOfBrushes;
    }
};

class Brush
{
private:
    int     brushSideFirstIndex;
    int     numberOfBrushSides;
    int     textureIndex;

public:
    void setBrushSideFirstIndex(int brushSideFirstIndex)
    {
        this->brushSideFirstIndex = brushSideFirstIndex;
    }

    int getBrushSideFirstIndex()
    {
        return brushSideFirstIndex;
    }

    void setNumberOfBrushSides(int numberOfBrushSides)
    {
        this->numberOfBrushSides = numberOfBrushSides;
    }

    int getNumberOfBrushSides()
    {
        return numberOfBrushSides;
    }

    void setTextureIndex(int textureIndex)
    {
        this->textureIndex = textureIndex;
    }

    int getTextureIndex()
    {
        return textureIndex;
    }
};

class BrushSide
{
private:
    int     planeIndex;
    int     textureIndex;

public:

    void setPlaneIndex(int planeIndex)
    {
        this->planeIndex = planeIndex;
    }

    int getPlaneIndex()
    {
        return planeIndex;
    }

    void setTextureIndex(int textureIndex)
    {
        this->textureIndex = textureIndex;
    }

    int getTextureIndex()
    {
        return textureIndex;
    }
};

class FaceVertex
{
private:
    float           positionCoordinates[3];
    float           textureCoordinates[2];
    float           lightmapCoordinates[2];
    float           normal[3];
    unsigned char   color[4];

public:

    void setPositionCoordinates(float x, float y, float z)
    {
        this->positionCoordinates[0] = x;
        this->positionCoordinates[1] = y;
        this->positionCoordinates[2] = z;
    }

    float* getPositionCoordinates()
    {
        return &positionCoordinates[0];
    }

    void setTextureCoordinates(int u, int v)
    {
        this->textureCoordinates[0] = u;
        this->textureCoordinates[1] = v;
    }

    float* getTextureCoordinates()
    {
        return &textureCoordinates[0];
    }

    void setLightmapCoordinates(int u, int v)
    {
        this->lightmapCoordinates[0] = u;
        this->lightmapCoordinates[1] = v;
    }

    float* getLightmapCoordinates()
    {
        return &lightmapCoordinates[0];
    }

    void setNormalVector(float x, float y, float z)
    {
        this->normal[0] = x;
        this->normal[1] = y;
        this->normal[2] = z;
    }

    float* getNormalVector()
    {
        return &normal[0];
    }

    void setColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
    {
        this->color[0] = r;
        this->color[1] = g;
        this->color[2] = b;
        this->color[3] = a;
    }

    unsigned char* getColor()
    {
        return &color[0];
    }
};

class TriangleMeshVertex
{
private:
    int firstVertexFaceOffset;
public:

    void setFirstVertexFaceOffset(int firstVertexFaceOffset)
    {
        this->firstVertexFaceOffset = firstVertexFaceOffset;
    }

    int getFirstVertexFaceOffset()
    {
        return firstVertexFaceOffset;
    }
};

class Effect
{
private:
    string          nameOfShader;
    int             brushIndexThatGeneratedThisEffect;
    int             unknown;    //always 5

public:
    Effect()
    {
        unknown = 5;
    }

    ~Effect()
    {
    }

    void setNameOfShader(char* nameOfShader)
    {
        this->nameOfShader = nameOfShader;
    }

    string getNameOfShader()
    {
        return this->nameOfShader;
    }

    void setBrushIndexThatGeneratedThisEffect(int brushIndexThatGeneratedThisEffect)
    {
        this->brushIndexThatGeneratedThisEffect = brushIndexThatGeneratedThisEffect;
    }

    int getBrushIndexThatGeneratedThisEffect()
    {
        return brushIndexThatGeneratedThisEffect;
    }
};

class LightmapFace
{
private:
    int             lightmapIndex;
    int             cornerCoordinate[2];
    int             faceSize[2];
    float           worldCoordinatesOrigin[3];
    float           worldCoordinatesBitsets[2][3];

public:
    void setLightmapIndex(int lightmapIndex)
    {
        this->lightmapIndex = lightmapIndex;
    }

    int getLightmapIndex()
    {
        return lightmapIndex;
    }

    void setCornerCoordinates(int x, int y)
    {
        this->cornerCoordinate[0] = x;
        this->cornerCoordinate[1] = y;
    }

    int* getCornerCoordinates()
    {
        return cornerCoordinate;
    }

    void setSize(int x, int y)
    {
        this->faceSize[0] = x;
        this->faceSize[1] = y;
    }

    int* getSize()
    {
        return faceSize;
    }

    void setWorldCoordinatesOrigin(float x, float y, float z)
    {
        this->worldCoordinatesOrigin[0] = x;
        this->worldCoordinatesOrigin[1] = y;
        this->worldCoordinatesOrigin[2] = z;
    }

    float* getWorldCoordinatesOrigin()
    {
        return worldCoordinatesOrigin;
    }

    void setWorldCoordinatesBitsets(float sx, float tx, float sy, float ty, float sz, float tz)
    {
        this->worldCoordinatesBitsets[0][0] = sx;
        this->worldCoordinatesBitsets[1][0] = tx;
        this->worldCoordinatesBitsets[0][1] = sy;
        this->worldCoordinatesBitsets[1][1] = ty;
        this->worldCoordinatesBitsets[0][2] = sz;
        this->worldCoordinatesBitsets[1][2] = tz;
    }

    float* getWorldCoordinatesBitsets(int coordinate)
    {
        return worldCoordinatesBitsets[coordinate];
    }
};

class LightmapColor
{
private:
    unsigned char   data[128][128][3];

public:
    void setLightmapColorData(int x, int y, int channel, unsigned char value)
    {
        this->data[x][y][channel] = value;
    }

    unsigned char getLightmapColorData(int x, int y, int c)
    {
        return data[x][y][c];
    }
};

class LightmapVolume
{
private:
    unsigned char   ambientColorComponent[3];
    unsigned char   directionalColorComponent[3];
    unsigned char   lightDirection[2]; // 0=phi, 1=theta.

public:
    void setAmbientColorComponent(unsigned char r, unsigned char g, unsigned char b)
    {
        this->ambientColorComponent[0] = r;
        this->ambientColorComponent[1] = g;
        this->ambientColorComponent[2] = b;
    }

    unsigned char getAmbientColorComponent(int channel)
    {
        return ambientColorComponent[channel];
    }

    void setDirectionalColorComponent(unsigned char r, unsigned char g, unsigned char b)
    {
        this->directionalColorComponent[0] = r;
        this->directionalColorComponent[1] = g;
        this->directionalColorComponent[2] = b;
    }

    unsigned char getDirectionalColorComponent(int channel)
    {
        return directionalColorComponent[channel];
    }

    void setLightDirection(int index, unsigned char value)
    {
        if(index == 0 || index == 1)
            this->lightDirection[index] = value;
        else
            {
                printf("ERROR: INVALID INDEX OF LIGHTMAP VOLUME DIRECTION. Valid values: 0 (phi), 1 (theta)");
                exit(1);
            }
    }

    unsigned char* getLightDirection()
    {
        return &lightDirection[0];
    }
};

class Face
{
private:
    int             textureIndex;
    int             effectIndex;
    int             typeOfFace; //1=polygon, 2=patch, 3=mesh, 4=billboard
    int             firstVertexIndex;
    int             numberOfVertices;
    int             firstMeshVerticesIndex;
    int             numberOfMeshVertices;
    LightmapFace*   lightmapFace;
    float           normalVector[3];
    int             bezierPatchDimensions[2];

public:

    Face()
    {
        lightmapFace    = nullptr;
    }

    ~Face()
    {
        if(lightmapFace != nullptr)
            delete(lightmapFace);
    }

    void setTextureIndex(int textureIndex)
    {
        this->textureIndex = textureIndex;
    }

    int getTextureIndex()
    {
        return textureIndex;
    }

    void setEffectIndex(int effectIndex)
    {
        this->effectIndex = effectIndex;
    }

    int getEffectIndex()
    {
        return effectIndex;
    }

    void setTypeOfFace(int typeOfFace)
    {
        if(typeOfFace >= 1 && typeOfFace <= 4)
            this->typeOfFace = typeOfFace;
        else
            {
                printf("ERROR: INVALID TYPE OF POLYGON FACE.");
                exit(1);
            }
    }

    int getTypeOfFace()
    {
        return typeOfFace;
    }

    void setFirstVertexIndex(int firstVertexIndex)
    {
        this->firstVertexIndex = firstVertexIndex;
    }

    int getFirstVertexIndex()
    {
        return firstVertexIndex;
    }

    void setNumberOfVertices(int numberOfVertices)
    {
        this->numberOfVertices = numberOfVertices;
    }

    int getNumberOfVertices()
    {
        return numberOfVertices;
    }

    void setFirstMeshVerticesIndex(int firstMeshVerticesIndex)
    {
        this->firstMeshVerticesIndex = firstMeshVerticesIndex;
    }

    int getFirstMeshVerticesIndex()
    {
        return firstMeshVerticesIndex;
    }

    void setNumberOfMeshVertices(int numberOfMeshVertices)
    {
        this->numberOfMeshVertices = numberOfMeshVertices;
    }

    int getNumberOfMeshVertices()
    {
        return numberOfMeshVertices;
    }

    void setLightmapFaceObject(LightmapFace* lf)
    {
        this->lightmapFace = lf;
    }

    LightmapFace* getLightmapFaceObject()
    {
        return lightmapFace;
    }

    void setNormalVector(float x, float y, float z)
    {
        this->normalVector[0] = x;
        this->normalVector[1] = y;
        this->normalVector[2] = z;
    }

    float* getNormalVector()
    {
        return &normalVector[0];
    }

    void setBezierPatchDimensions(int x, int y)
    {
        this->bezierPatchDimensions[0] = x;
        this->bezierPatchDimensions[1] = y;
    }

    int* getBezierPatchDimensions()
    {
        return &bezierPatchDimensions[0];
    }
};

class VisibilityData
{
private:
    int             numberOfClusters;
    int             sizeOfEachClusterInBytes;
    unsigned char*  potentiallyVisibleSets;

public:

    VisibilityData()
    {
        potentiallyVisibleSets = nullptr;
    }

    ~VisibilityData()
    {
        if(potentiallyVisibleSets != nullptr)
            delete(potentiallyVisibleSets);
    }

    void setNumberOfClusters(int numberOfClusters)
    {
        this->numberOfClusters = numberOfClusters;
    }

    int getNumberOfClusters()
    {
        return numberOfClusters;
    }

    void setSizeOfEachClusterInBytes(int sizeInBytes)
    {
        this->sizeOfEachClusterInBytes = sizeInBytes;
    }

    int getSizeOfEachClusterInBytes()
    {
        return sizeOfEachClusterInBytes;
    }

    void setArrayOfBytesHoldingTheClusterVisibilitySets(unsigned char* data)
    {
        this->potentiallyVisibleSets = data;
    }

    unsigned char* getArrayOfBytesHoldingTheClusterVisibilitySets()
    {
        return potentiallyVisibleSets;
    }
};

class BSPData
{
private:
    Entity                          entity;
    LumpArray<Texture>              textures;
    LumpArray<Plane>                planes;
    LumpArray<Node>                 nodes;
    LumpArray<Leaf>                 leaves;
    LumpArray<LeafFace>             leafFaces;
    LumpArray<LeafBrush>            leafBrushes;
    LumpArray<Model>                models;
    LumpArray<Brush>                brushes;
    LumpArray<BrushSide>            brushSides;
    LumpArray<FaceVertex>           faceVertices;
    LumpArray<TriangleMeshVertex>   triangleMeshVertices;
    LumpArray<Effect>               effects;
    LumpArray<Face>                 faces;
    LumpArray<LightmapVolume>       lightmapVolumes;
    LumpArray<LightmapColor>        lightmapColors;
    VisibilityData                  potentiallyVisibleSets;

public:

    BSPData();
    ~BSPData();

    Entity*                         getEntityObject();
    LumpArray<Texture>*             getTextureObject();
    LumpArray<Plane>*               getPlaneObject();
    LumpArray<Node>*                getNodeObject();
    LumpArray<Leaf>*                getLeafObject();
    LumpArray<LeafFace>*            getLeafFaceObject();
    LumpArray<LeafBrush>*           getLeafBrushObject();
    LumpArray<Model>*               getModelObject();
    LumpArray<Brush>*               getBrushObject();
    LumpArray<BrushSide>*           getBrushSideObject();
    LumpArray<FaceVertex>*          getFaceVertexObject();
    LumpArray<TriangleMeshVertex>*  getTriangleMeshVertexObject();
    LumpArray<Effect>*              getEffectObject();
    LumpArray<Face>*                getFaceObject();
    LumpArray<LightmapVolume>*      getLightmapVolumeObject();
    LumpArray<LightmapColor>*       getLightmapColorObject();
    VisibilityData*                 getVisDataObject();
};

#endif // _BSPDATA_H_
