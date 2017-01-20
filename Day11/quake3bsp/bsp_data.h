#ifndef _BSPDATA_H_
#define _BSPDATA_H_

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
    int             lightmapIndex;
    int             lightmapCoordinateOrigin[2];
    int             lightmapSize[2];
    float           worldCoordinateOrigin[3];
    float           worldCoordinateUnitVectors[2][3];
};

class LightmapColor
{
    unsigned char   data[128][128][3];
};

class LightmapVolume
{
    unsigned char   ambientColorComponent[3];
    unsigned char   directionalColorComponent[3];
    unsigned char   lightDirection[2]; // 0=phi, 1=theta.
};

class Face
{
    int             textureIndex;
    int             effectIndex;
    int             typeOfFace; //1=polygon, 2=patch, 3=mesh, 4=billboard
    int             firstVertexIndex;
    int             numberOfVertices;
    int             firstMeshVerticesIndex;
    int             totalOfMeshVertices;
    LightmapFace    lightmapFace;
    LightmapColor   lightmapColor;
    float           normalCoordinates[3];
    int             sizePatchDimensions[2];
};

class VisibilityData
{
    int             numberOfVectors;
    int             sizeOfEachVectorInBytes;
    unsigned char*  potentiallyVisibleSets;
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

public:
    /*
    LumpArray<Face*>                faces;
    LumpArray<VisibilityData*>      potentiallyVisibleSets;*/

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
};

#endif // _BSPDATA_H_
