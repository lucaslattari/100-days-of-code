#ifndef _BSPDATA_H_
#define _BSPDATA_H_

#include <vector>

using namespace std;

class Entity
{
private:
    //game-related map information, including information about the map name, weapons, health, armor, triggers, spawn points, lights, and .md3 models to be placed in the map
    string entityName;
};

class Texture
{
private:
    string  name;
    int     flags;
    int     contents;
};

class Plane
{
private:
    float   normal[3];  //plane normal
    float   dist;       //Distance from origin to plane along normal.
};

class Node
{
    int     planeIndex;          //index
protected:
    int     childrenIndices[2];    //Negative numbers are leaf indices: -(leaf+1)
    int     minCoordBoundingBox[3];        //Integer bounding box min coord.
    int     maxCoordBoundingBox[3];        //Integer bounding box max coord.
};

class LeafFace
{
private:
    int     faceIndex;
};

class LeafBrush
{
private:
    int     brushIndex;
};

class Leaf : public Node
{
private:
    int     cluster;            //pvs, if cluster is negative, the leaf is outside the map or otherwise invalid.
    int     area;
    int     leafFace;           //for rendering
    int     numberOfLeafFaces;
    int     leafBrush;          //for collision detection
    int     numberOfLeafBrushes;
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
    vector<Entity>              entities;
    vector<Texture>             textures;
    vector<Plane>               planes;
    vector<Node>                nodes;
    vector<Leaf>                leaves;
    vector<LeafFace>            leafFaces;
    vector<LeafBrush>           leafBrushes;
    vector<Model>               models;
    vector<Brush>               brushes;
    vector<BrushSide>           brushSides;
    vector<FaceVertex>          faceVertices;
    vector<TriangleMeshVertex>  triangleMeshVertices;
    vector<Effect>              effects;
    vector<Face>                faces;
    vector<VisibilityData>      potentiallyVisibleSets;

public:
    BSPData();
    ~BSPData();
};

#endif // _BSPDATA_H_
