#ifndef CAMCAL_H
#define CAMCAL_H

#include "externalimporter.hh"
#include <QString>

class CamCal
{
public:
    CamCal();
    CamCal(QString modelfile);

private:
    MyMesh mesh;


};

#endif // CAMCAL_H
