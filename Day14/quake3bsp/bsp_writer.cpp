#include "bsp_writer.h"

BSPWriter::BSPWriter(string filenameOfLog)
{
    filePointerOfLog = fopen(filenameOfLog.c_str(), "a+");
}

BSPWriter::~BSPWriter()
{
    fclose(filePointerOfLog);
}

void BSPWriter::printBSPLoadedTimeInLog(int seconds, int milliseconds)
{
    fprintf(filePointerOfLog, "BSP loaded in %d seconds and %d milliseconds\n\n", seconds, milliseconds);
}

void BSPWriter::printHeaderInLog(BSPHeader* bspHeader)
{
    fprintf(filePointerOfLog, "********** HEADER ***********\n");
    fprintf(filePointerOfLog, "BSP Code: %s\n", bspHeader->getFileIdentifier());
    fprintf(filePointerOfLog, "Version: %d\n\n", bspHeader->getVersion());

    Lump* lumps = bspHeader->getArrayOfLumps();
    for(int i = 0 ; i < totalOfLumps ; i++)
    {
        fprintf(filePointerOfLog, "Lump %d:\n", i);
        fprintf(filePointerOfLog, "Offset: %d\n", lumps[i].getOffset());
        fprintf(filePointerOfLog, "Length: %d\n", lumps[i].getLength());
        fprintf(filePointerOfLog, "\n");
    }
}

void BSPWriter::printEntitiesInLog(Entity* e)
{
    fprintf(filePointerOfLog, "Entities: \n%s\n", e->getEntity().c_str());
}

void BSPWriter::printEachTextureDataInLog(Texture* textureObject)
{
    fprintf(filePointerOfLog, "Name: %s\n", textureObject->getName().c_str());
    fprintf(filePointerOfLog, "Flags: %d\n", textureObject->getFlags());
    fprintf(filePointerOfLog, "Content: %d\n", textureObject->getContents());
    fprintf(filePointerOfLog, "\n");
}

void BSPWriter::printEachPlaneDataInLog(Plane* planeObject)
{
    fprintf(filePointerOfLog, "Normal: %f %f %f\n", planeObject->getNormal()[0], planeObject->getNormal()[1], planeObject->getNormal()[2]);
    fprintf(filePointerOfLog, "Distance from origin to plane: %f\n\n", planeObject->getDistanceFromOriginToPlane());
    fprintf(filePointerOfLog, "\n");
}

void BSPWriter::printEachNodeDataInLog(Node* nodeObject)
{
    fprintf(filePointerOfLog, "Plane index: %d\n", nodeObject->getPlaneIndex());
    fprintf(filePointerOfLog, "Children indices: %d %d\n", nodeObject->getChildrenIndices()[0], nodeObject->getChildrenIndices()[1]);
    fprintf(filePointerOfLog, "Minimum coordinate bounding box: %d %d %d\n", nodeObject->getMinCoordBoundingBox()[0], nodeObject->getMinCoordBoundingBox()[1], nodeObject->getMinCoordBoundingBox()[2]);
    fprintf(filePointerOfLog, "Maximum coordinate bounding box: %d %d %d\n\n", nodeObject->getMaxCoordBoundingBox()[0], nodeObject->getMaxCoordBoundingBox()[1], nodeObject->getMaxCoordBoundingBox()[2]);
    fprintf(filePointerOfLog, "\n");
}

void BSPWriter::printEachLeafDataInLog(Leaf* leafObject)
{
    fprintf(filePointerOfLog, "Cluster index: %d\n", leafObject->getClusterIndex());
    fprintf(filePointerOfLog, "Minimum coordinate bounding box: %d %d %d\n", leafObject->getMinCoordBoundingBox()[0], leafObject->getMinCoordBoundingBox()[1], leafObject->getMinCoordBoundingBox()[2]);
    fprintf(filePointerOfLog, "Maximum coordinate bounding box: %d %d %d\n", leafObject->getMaxCoordBoundingBox()[0], leafObject->getMaxCoordBoundingBox()[1], leafObject->getMaxCoordBoundingBox()[2]);
    fprintf(filePointerOfLog, "Leaf face index: %d\n", leafObject->getLeafFaceIndex());
    fprintf(filePointerOfLog, "Number of leaf faces: %d\n", leafObject->getNumberOfLeafFaces());
    fprintf(filePointerOfLog, "Leaf brush index: %d\n", leafObject->getLeafBrushIndex());
    fprintf(filePointerOfLog, "Number of leaf brushes: %d\n", leafObject->getNumberOfLeafBrushes());
    fprintf(filePointerOfLog, "\n");
}

void BSPWriter::printEachLeafFaceDataInLog(LeafFace* leafFaceObject)
{
    fprintf(filePointerOfLog, "Face Index: %d\n", leafFaceObject->getFaceIndex());
}

void BSPWriter::printEachLeafBrushDataInLog(LeafBrush* leafBrushObject)
{
    fprintf(filePointerOfLog, "Brush Index: %d\n", leafBrushObject->getBrushIndex());
}

void BSPWriter::printEachModelDataInLog(Model* modelObject)
{
    fprintf(filePointerOfLog, "Minimum coordinate bounding box: %f %f %f\n", modelObject->getMinCoordBoundingBox()[0], modelObject->getMinCoordBoundingBox()[1], modelObject->getMinCoordBoundingBox()[2]);
    fprintf(filePointerOfLog, "Maximum coordinate bounding box: %f %f %f\n\n", modelObject->getMaxCoordBoundingBox()[0], modelObject->getMaxCoordBoundingBox()[1], modelObject->getMaxCoordBoundingBox()[2]);
    fprintf(filePointerOfLog, "First face index: %d\n", modelObject->getFirstFaceIndex());
    fprintf(filePointerOfLog, "Number of faces: %d\n", modelObject->getNumberOfFaces());
    fprintf(filePointerOfLog, "First brush index: %d\n", modelObject->getFirstBrushIndex());
    fprintf(filePointerOfLog, "Number of brushes: %d\n", modelObject->getNumberOfBrushes());
    fprintf(filePointerOfLog, "\n");
}

void BSPWriter::printEachBrushDataInLog(Brush* brushObject)
{
    fprintf(filePointerOfLog, "Brush side first index: %d\n", brushObject->getBrushSideFirstIndex());
    fprintf(filePointerOfLog, "Number of brush sides: %d\n", brushObject->getNumberOfBrushSides());
    fprintf(filePointerOfLog, "Texture index: %d\n", brushObject->getTextureIndex());
    fprintf(filePointerOfLog, "\n");
}

void BSPWriter::printEachBrushSideDataInLog(BrushSide* brushSideObject)
{
    fprintf(filePointerOfLog, "Texture index: %d\n", brushSideObject->getTextureIndex());
    fprintf(filePointerOfLog, "Plane index: %d\n", brushSideObject->getPlaneIndex());
    fprintf(filePointerOfLog, "\n");
}

void BSPWriter::printEachFaceVertexDataInLog(FaceVertex* faceVertexObject)
{
    fprintf(filePointerOfLog, "Position coordinates: %f %f %f\n", faceVertexObject->getPositionCoordinates()[0], faceVertexObject->getPositionCoordinates()[1], faceVertexObject->getPositionCoordinates()[2]);
    fprintf(filePointerOfLog, "Texture coordinates: %f %f\n", faceVertexObject->getTextureCoordinates()[0], faceVertexObject->getTextureCoordinates()[1]);
    fprintf(filePointerOfLog, "Lightmap coordinates: %f %f\n", faceVertexObject->getLightmapCoordinates()[0], faceVertexObject->getLightmapCoordinates()[1]);
    fprintf(filePointerOfLog, "Normal vector: %f %f %f\n", faceVertexObject->getNormalVector()[0], faceVertexObject->getNormalVector()[1], faceVertexObject->getNormalVector()[2]);
    fprintf(filePointerOfLog, "Color of vertex: %d %d %d %d\n", faceVertexObject->getColor()[0], faceVertexObject->getColor()[1], faceVertexObject->getColor()[2], faceVertexObject->getColor()[3]);
    fprintf(filePointerOfLog, "\n");
}

void BSPWriter::printEachTriangleMeshVertexDataInLog(TriangleMeshVertex* triangleMeshVertexObject)
{
    fprintf(filePointerOfLog, "Vertex index offset relative to first vertex of face: %d\n", triangleMeshVertexObject->getFirstVertexFaceOffset());
}

void BSPWriter::printEachEffectDataInLog(Effect* effectObject)
{
    fprintf(filePointerOfLog, "Name of shader: %s\n", effectObject->getNameOfShader().c_str());
    fprintf(filePointerOfLog, "Brush index that generated this effect: %d\n", effectObject->getBrushIndexThatGeneratedThisEffect());
    fprintf(filePointerOfLog, "\n");
}

void BSPWriter::printEachFaceDataInLog(Face* faceObject)
{
    fprintf(filePointerOfLog, "Texture index: %d\n", faceObject->getTextureIndex());
    fprintf(filePointerOfLog, "Effect index: %d\n", faceObject->getEffectIndex());
    switch(faceObject->getTypeOfFace())
    {
        case 1:
            fprintf(filePointerOfLog, "Type of face: polygon\n");
            break;

        case 2:
            fprintf(filePointerOfLog, "Type of face: patch\n");
            break;

        case 3:
            fprintf(filePointerOfLog, "Type of face: mesh\n");
            break;

        case 4:
            fprintf(filePointerOfLog, "Type of face: billboard\n");
            break;

        default:
            fprintf(filePointerOfLog, "Type of face: ERROR\n");
    }
    fprintf(filePointerOfLog, "Index of first vertex: %d\n", faceObject->getFirstVertexIndex());
    fprintf(filePointerOfLog, "Number of vertices: %d\n", faceObject->getNumberOfVertices());
    fprintf(filePointerOfLog, "Index of first mesh vertex: %d\n", faceObject->getFirstMeshVerticesIndex());
    fprintf(filePointerOfLog, "Number of mesh vertices: %d\n", faceObject->getNumberOfMeshVertices());
    fprintf(filePointerOfLog, "Lightmap index: %d\n", faceObject->getLightmapFaceObject()->getLightmapIndex());
    fprintf(filePointerOfLog, "Lightmap corner coordinates: %d %d\n", faceObject->getLightmapFaceObject()->getCornerCoordinates()[0], faceObject->getLightmapFaceObject()->getCornerCoordinates()[1]);
    fprintf(filePointerOfLog, "Lightmap image size: %d %d\n", faceObject->getLightmapFaceObject()->getSize()[0], faceObject->getLightmapFaceObject()->getSize()[1]);
    fprintf(filePointerOfLog, "Lightmap world space origin coordinates: %f %f %f\n", faceObject->getLightmapFaceObject()->getWorldCoordinatesOrigin()[0], faceObject->getLightmapFaceObject()->getWorldCoordinatesOrigin()[1], faceObject->getLightmapFaceObject()->getWorldCoordinatesOrigin()[2]);
    fprintf(filePointerOfLog, "Lightmap world space texture coordinates (x axis): %f %f\n", faceObject->getLightmapFaceObject()->getWorldCoordinatesBitsets(0)[0], faceObject->getLightmapFaceObject()->getWorldCoordinatesBitsets(0)[1]);
    fprintf(filePointerOfLog, "Lightmap world space texture coordinates (y axis): %f %f\n", faceObject->getLightmapFaceObject()->getWorldCoordinatesBitsets(1)[0], faceObject->getLightmapFaceObject()->getWorldCoordinatesBitsets(1)[1]);
    fprintf(filePointerOfLog, "Lightmap world space texture coordinates (z axis): %f %f\n", faceObject->getLightmapFaceObject()->getWorldCoordinatesBitsets(2)[0], faceObject->getLightmapFaceObject()->getWorldCoordinatesBitsets(2)[1]);
    fprintf(filePointerOfLog, "Normal vector: %f %f %f\n", faceObject->getNormalVector()[0], faceObject->getNormalVector()[1], faceObject->getNormalVector()[2]);
    fprintf(filePointerOfLog, "Patch dimensions: %d %d\n", faceObject->getBezierPatchDimensions()[0], faceObject->getBezierPatchDimensions()[1]);
    fprintf(filePointerOfLog, "\n");
}

void BSPWriter::printEachLightmapVolDataInLog(LightmapVolume* lightmapVolumeObject)
{
    fprintf(filePointerOfLog, "Ambient color component: %d %d %d\n", lightmapVolumeObject->getAmbientColorComponent(0), lightmapVolumeObject->getAmbientColorComponent(1), lightmapVolumeObject->getAmbientColorComponent(2));
    fprintf(filePointerOfLog, "Directional color component: %d %d %d\n", lightmapVolumeObject->getDirectionalColorComponent(0), lightmapVolumeObject->getDirectionalColorComponent(1), lightmapVolumeObject->getDirectionalColorComponent(2));
    fprintf(filePointerOfLog, "Direction to light: %d %d\n", lightmapVolumeObject->getLightDirection()[0], lightmapVolumeObject->getLightDirection()[1]);
    fprintf(filePointerOfLog, "\n");
}

void BSPWriter::printEachLightmapColorDataInLog(LightmapColor* lightmapColorObject)
{
    fprintf(filePointerOfLog, "Lightmap color data:\n");
    for(int x = 0 ; x < 128 ; x++)
    {
        for(int y = 0 ; y < 128 ; y++)
        {
            for(int c = 0 ; c < 3 ; c++)
            {
                fprintf(filePointerOfLog, "%d ", lightmapColorObject->getLightmapColorData(x, y, c));
            }
        }
        fprintf(filePointerOfLog, "\n");
    }
    fprintf(filePointerOfLog, "\n");
}

void BSPWriter::printEachVisDataDataInLog(VisibilityData* visDataObject)
{
    fprintf(filePointerOfLog, "Number of clusters: %d\n", visDataObject->getNumberOfClusters());
    fprintf(filePointerOfLog, "Bytes per clusters: %d\n", visDataObject->getSizeOfEachClusterInBytes());
    fprintf(filePointerOfLog, "Array of bytes holding the cluster visibility data: ");
    for(int i = 0 ; i < visDataObject->getNumberOfClusters() * visDataObject->getSizeOfEachClusterInBytes() ; i++)
        fprintf(filePointerOfLog, "%d ", visDataObject->getArrayOfBytesHoldingTheClusterVisibilitySets()[i]);
    fprintf(filePointerOfLog, "\n");
}

void BSPWriter::printDataInLog(BSPData* data)
{
    printEntitiesInLog(data->getEntityObject());

    fprintf(filePointerOfLog, "*************** TEXTURES ***************\nTotal: %d\n", data->getTextureObject()->getTotalOfElements());
    for(int textureIndex = 0 ; textureIndex < data->getTextureObject()->getTotalOfElements() ; textureIndex++)
    {
        fprintf(filePointerOfLog, "Texture element id: %d \n", textureIndex);
        printEachTextureDataInLog(data->getTextureObject()->getElementByIndex(textureIndex));
    }
    fprintf(filePointerOfLog, "\n");

    fprintf(filePointerOfLog, "*************** PLANES ***************\nTotal: %d\n", data->getPlaneObject()->getTotalOfElements());
    for(int planeIndex = 0 ; planeIndex < data->getPlaneObject()->getTotalOfElements() ; planeIndex++)
    {
        fprintf(filePointerOfLog, "Plane element id: %d \n", planeIndex);
        printEachPlaneDataInLog(data->getPlaneObject()->getElementByIndex(planeIndex));
    }
    fprintf(filePointerOfLog, "\n");

    fprintf(filePointerOfLog, "*************** NODES ***************\nTotal: %d\n", data->getNodeObject()->getTotalOfElements());
    for(int nodeIndex = 0 ; nodeIndex < data->getNodeObject()->getTotalOfElements() ; nodeIndex++)
    {
        fprintf(filePointerOfLog, "Node element id: %d \n", nodeIndex);
        printEachNodeDataInLog(data->getNodeObject()->getElementByIndex(nodeIndex));
    }
    fprintf(filePointerOfLog, "\n");

    fprintf(filePointerOfLog, "*************** LEAVES ***************\nTotal: %d\n", data->getLeafObject()->getTotalOfElements());
    for(int leafIndex = 0 ; leafIndex < data->getLeafObject()->getTotalOfElements() ; leafIndex++)
    {
        fprintf(filePointerOfLog, "Leaf element id: %d \n", leafIndex);
        printEachLeafDataInLog(data->getLeafObject()->getElementByIndex(leafIndex));
    }
    fprintf(filePointerOfLog, "\n");

    fprintf(filePointerOfLog, "*************** LEAF FACES ***************\nTotal: %d\n", data->getLeafFaceObject()->getTotalOfElements());
    for(int leafFaceIndex = 0 ; leafFaceIndex < data->getLeafFaceObject()->getTotalOfElements() ; leafFaceIndex++)
    {
        fprintf(filePointerOfLog, "Leaf Face element id: %d \n", leafFaceIndex);
        printEachLeafFaceDataInLog(data->getLeafFaceObject()->getElementByIndex(leafFaceIndex));
    }
    fprintf(filePointerOfLog, "\n");

    fprintf(filePointerOfLog, "*************** LEAF BRUSHES ***************\nTotal: %d\n", data->getLeafBrushObject()->getTotalOfElements());
    for(int leafBrushIndex = 0 ; leafBrushIndex < data->getLeafBrushObject()->getTotalOfElements() ; leafBrushIndex++)
    {
        fprintf(filePointerOfLog, "Leaf Brush element id: %d \n", leafBrushIndex);
        printEachLeafBrushDataInLog(data->getLeafBrushObject()->getElementByIndex(leafBrushIndex));
    }
    fprintf(filePointerOfLog, "\n");

    fprintf(filePointerOfLog, "*************** MODELS ***************\nTotal: %d\n", data->getModelObject()->getTotalOfElements());
    for(int modelIndex = 0 ; modelIndex < data->getModelObject()->getTotalOfElements() ; modelIndex++)
    {
        fprintf(filePointerOfLog, "Model element id: %d \n", modelIndex);
        printEachModelDataInLog(data->getModelObject()->getElementByIndex(modelIndex));
    }
    fprintf(filePointerOfLog, "\n");

    fprintf(filePointerOfLog, "*************** BRUSHES ***************\nTotal: %d\n", data->getBrushObject()->getTotalOfElements());
    for(int brushIndex = 0 ; brushIndex < data->getBrushObject()->getTotalOfElements() ; brushIndex++)
    {
        fprintf(filePointerOfLog, "Brush element id: %d \n", brushIndex);
        printEachBrushDataInLog(data->getBrushObject()->getElementByIndex(brushIndex));
    }
    fprintf(filePointerOfLog, "\n");

    fprintf(filePointerOfLog, "*************** BRUSH SIDES ***************\nTotal: %d\n", data->getBrushSideObject()->getTotalOfElements());
    for(int brushSideIndex = 0 ; brushSideIndex < data->getBrushSideObject()->getTotalOfElements() ; brushSideIndex++)
    {
        fprintf(filePointerOfLog, "Brush Side element id: %d \n", brushSideIndex);
        printEachBrushSideDataInLog(data->getBrushSideObject()->getElementByIndex(brushSideIndex));
    }
    fprintf(filePointerOfLog, "\n");

    fprintf(filePointerOfLog, "*************** FACE VERTICES ***************\nTotal: %d\n", data->getFaceVertexObject()->getTotalOfElements());
    for(int faceVertexIndex = 0 ; faceVertexIndex < data->getFaceVertexObject()->getTotalOfElements() ; faceVertexIndex++)
    {
        fprintf(filePointerOfLog, "Face Vertex element id: %d \n", faceVertexIndex);
        printEachFaceVertexDataInLog(data->getFaceVertexObject()->getElementByIndex(faceVertexIndex));
    }
    fprintf(filePointerOfLog, "\n");

    fprintf(filePointerOfLog, "*************** TRIANGLE MESH VERTICES ***************\nTotal: %d\n", data->getTriangleMeshVertexObject()->getTotalOfElements());
    for(int triangleMeshVertexIndex = 0 ; triangleMeshVertexIndex < data->getTriangleMeshVertexObject()->getTotalOfElements() ; triangleMeshVertexIndex++)
    {
        fprintf(filePointerOfLog, "Triangle Mesh Vertex element id: %d \n", triangleMeshVertexIndex);
        printEachTriangleMeshVertexDataInLog(data->getTriangleMeshVertexObject()->getElementByIndex(triangleMeshVertexIndex));
    }
    fprintf(filePointerOfLog, "\n");

    fprintf(filePointerOfLog, "*************** EFFECTS ***************\nTotal: %d\n", data->getEffectObject()->getTotalOfElements());
    for(int effectIndex = 0 ; effectIndex < data->getEffectObject()->getTotalOfElements() ; effectIndex++)
    {
        fprintf(filePointerOfLog, "Effect element id: %d \n", effectIndex);
        printEachEffectDataInLog(data->getEffectObject()->getElementByIndex(effectIndex));
    }
    fprintf(filePointerOfLog, "\n");

    fprintf(filePointerOfLog, "*************** FACES ***************\nTotal: %d\n", data->getFaceObject()->getTotalOfElements());
    for(int faceIndex = 0 ; faceIndex < data->getFaceObject()->getTotalOfElements() ; faceIndex++)
    {
        fprintf(filePointerOfLog, "Face element id: %d \n", faceIndex);
        printEachFaceDataInLog(data->getFaceObject()->getElementByIndex(faceIndex));
    }
    fprintf(filePointerOfLog, "\n");

    fprintf(filePointerOfLog, "*************** LIGHTMAP VOLUMES ***************\nTotal: %d\n", data->getLightmapVolumeObject()->getTotalOfElements());
    for(int lightmapVolumeIndex = 0 ; lightmapVolumeIndex < data->getLightmapVolumeObject()->getTotalOfElements() ; lightmapVolumeIndex++)
    {
        fprintf(filePointerOfLog, "Lightmap volume element id: %d \n", lightmapVolumeIndex);
        printEachLightmapVolDataInLog(data->getLightmapVolumeObject()->getElementByIndex(lightmapVolumeIndex));
    }
    fprintf(filePointerOfLog, "\n");

    fprintf(filePointerOfLog, "*************** LIGHTMAP COLORS ***************\nTotal: %d\n", data->getLightmapColorObject()->getTotalOfElements());
    for(int lightmapColorIndex = 0 ; lightmapColorIndex < data->getLightmapColorObject()->getTotalOfElements() ; lightmapColorIndex++)
    {
        fprintf(filePointerOfLog, "Lightmap color element id: %d \n", lightmapColorIndex);
        printEachLightmapColorDataInLog(data->getLightmapColorObject()->getElementByIndex(lightmapColorIndex));
    }
    fprintf(filePointerOfLog, "\n");

    fprintf(filePointerOfLog, "*************** POTENTIALLY VISIBLE SETS ***************\n");
    printEachVisDataDataInLog(data->getVisDataObject());
    fprintf(filePointerOfLog, "\n");
}
