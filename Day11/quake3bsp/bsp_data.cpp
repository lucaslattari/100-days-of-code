#include <stdio.h>
#include "bsp.h"

BSPData::BSPData()
{
}

BSPData::~BSPData()
{
}

Entity* BSPData::getEntityObject()
{
    return &entity;
}

LumpArray<Texture>* BSPData::getTextureObject()
{
    return &textures;
}

LumpArray<Plane>* BSPData::getPlaneObject()
{
    return &planes;
}

LumpArray<Node>* BSPData::getNodeObject()
{
    return &nodes;
}

LumpArray<Leaf>* BSPData::getLeafObject()
{
    return &leaves;
}

LumpArray<LeafFace>* BSPData::getLeafFaceObject()
{
    return &leafFaces;
}

LumpArray<LeafBrush>* BSPData::getLeafBrushObject()
{
    return &leafBrushes;
}

LumpArray<Model>* BSPData::getModelObject()
{
    return &models;
}

LumpArray<Brush>* BSPData::getBrushObject()
{
    return &brushes;
}

LumpArray<BrushSide>* BSPData::getBrushSideObject()
{
    return &brushSides;
}

LumpArray<FaceVertex>* BSPData::getFaceVertexObject()
{
    return &faceVertices;
}

LumpArray<TriangleMeshVertex>* BSPData::getTriangleMeshVertexObject()
{
    return &triangleMeshVertices;
}

LumpArray<Effect>* BSPData::getEffectObject()
{
    return &effects;
}
