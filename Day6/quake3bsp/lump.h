#ifndef _LUMP_H_
#define _LUMP_H_

/**
 * Constant for the ID Software Magic number.
 */
const std::string			idMagicNumber	= "IBSP";

/**
 * Constant for the Q3 Map version.
 */
const int					idVersion		= 0x2E;

/**
 * Constant identifier for all the lumps.
 */
const int					idEntityLump	= 0x00; // Entities : Game-related object descriptions.
const int					idTextureLump	= 0x01; // Textures : Surface descriptions.
const int					idPlaneLump		= 0x02; // Planes : Planes used by map geometry.
const int					idNodeLump		= 0x03; // Nodes : BSP tree nodes.
const int					idLeafLump		= 0x04; // Leafs : BSP tree leaves.
const int					idLeafFaceLump	= 0x05; // LeafFaces : Lists of face indices, one list per leaf.
const int					idLeafBrushLump	= 0x06; // LeafBrushes  Lists of brush indices, one list per leaf.
const int					idModelLump		= 0x07; // Models  Descriptions of rigid world geometry in map.
const int					idBrushLump		= 0x08; // Brushes  Convex polyhedra used to describe solid space.
const int					idBrushSideLump	= 0x09; // Brushsides  Brush surfaces.
const int					idVertexLump		= 0x0A; // Vertexes  Vertices used to describe faces.
const int					idMeshVertLump	= 0x0B; // MeshVerts  Lists of offsets, one list per mesh.
const int					idEffectLump		= 0x0C; // Effects  List of special map effects.
const int					idFaceLump		= 0x0D; // Faces  Surface geometry.
const int					idLightMapLump	= 0x0E; // LightMaps  Packed lightmap data.
const int					idLightVolLump	= 0x0F; // LightVols  Local illumination data.
const int					idVisDataLump	= 0x10; // Visdata  Cluster-cluster visibility data.

const int                   sizeOfTextureInBytes    = 64 + 4 + 4;
const int                   sizeOfPlaneInBytes      = 4 * 4;
const int                   sizeOfNodeInBytes       = 9 * 4;
const int                   sizeOfLeafInBytes       = 12 * 4;

class Lump
{
private:
    int offset; //offset to start of a lump
    int length; //always a multiple of 4
public:
    int getOffset()
    {
        return offset;
    }

    int getLength()
    {
        return length;
    }
};

#endif // _LUMP_H_
