#include "camcal.h"

CamCal::CamCal()
{

}

CamCal::CamCal(QString modelfile)
{
    qDebug()<<"model file"<<modelfile<<endl;

    ExternalImporter *exImporter = new ExternalImporter<MyMesh>();

    if(!exImporter->read_mesh(mesh,modelfile.toStdString().c_str()))
    {
        std::cerr << "error: Cannot read mesh from "<<std::endl;
        return;
    }

    // if the file did not provide vertex normals, then calculate them
    if(!mesh.has_vertex_normals())
    {
        std::cout << "we need calculate vertex normal first"<<std::endl;
        // allocate memory for normals storage
        // we need face normals to update the vertex normals
        mesh.request_face_normals();
        mesh.request_vertex_normals();

        // let the mesh update  the normals
        mesh.update_face_normals();
        // dispose the face normals, as we don't need them any more
        mesh.release_face_normals();
    }



}

