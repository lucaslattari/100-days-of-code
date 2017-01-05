#include <stdio.h>
#include "bsp.h"

BSPData::BSPData()
{
}

BSPData::~BSPData()
{
    /*for (vector<Texture*>::iterator it = textures.begin() ; it != textures.end(); ++it)
    {
        Texture* t = textures.back();
        delete(t);
        textures.pop_back();
    }

    for (vector<Plane*>::iterator it = planes.begin() ; it != planes.end(); ++it)
    {
        Plane* p = planes.back();
        delete(p);
        planes.pop_back();
    }*/
}

Entity* BSPData::getEntityObject()
{
    return &entity;
}

LumpArray<Texture> BSPData::getTextureArray()
{
    return textures;
}

LumpArray<Plane> BSPData::getPlaneArray()
{
    return planes;
}
