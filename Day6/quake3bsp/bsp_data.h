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
    int     n_faces;
    int     firstBrushIndex;              // first brush for model.
    int     n_brushes;
};

class Brush
{
    int     brushSideFirstIndex;
    int     numberOfBrushSides;
    int     textureIndex;
};

class BrushSide
{
    int     planeIndex;
    int     textureIndex;
};

class FaceVertex
{
    float           positionCoordinates[3];
    float           textureCoordinates[2][2];   //0=surface, 1=lightmap.
    float           normal[3];
    unsigned char   color[4];
};

class TriangleMeshVertex
{
    int             firstVertexFaceOffset;
};

class Effect
{
    string          nameOfShader;
    int             brushThatGeneratedThisEffectIndex;
    int             unknown;    //always 5
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
public:
    /*
    LumpArray<LeafFace*>            leafFaces;
    LumpArray<LeafBrush*>           leafBrushes;
    LumpArray<Model*>               models;
    LumpArray<Brush*>               brushes;
    LumpArray<BrushSide*>           brushSides;
    LumpArray<FaceVertex*>          faceVertices;
    LumpArray<TriangleMeshVertex*>  triangleMeshVertices;
    LumpArray<Effect*>              effects;
    LumpArray<Face*>                faces;
    LumpArray<VisibilityData*>      potentiallyVisibleSets;*/

    BSPData();
    ~BSPData();

    Entity*                 getEntityObject();
    LumpArray<Texture>*     getTextureObject();
    LumpArray<Plane>*       getPlaneObject();
    LumpArray<Node>*        getNodeObject();
    LumpArray<Leaf>*        getLeafObject();
};

#endif // _BSPDATA_H_
