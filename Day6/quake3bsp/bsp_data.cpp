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
