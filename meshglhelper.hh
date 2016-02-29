#ifndef MESHGLHELPER
#define MESHGLHELPER

#include <assert.h>
#include <map>
#include <GL/glew.h>
#include <iostream>
#include <vector>
#include <QDebug>

template <typename MeshT>
class MeshGLHelper{
public:
    MeshGLHelper(MeshT &in_mesh)
        :m_mesh(in_mesh)
    {
    }

    MeshGLHelper(std::vector<GLfloat> &vertices,
                 std::vector<GLuint> &faceIndices)
    {

    }

private:
    MeshT m_mesh;

    std::vector<GLfloat> m_vertices;
    std::vector<GLuint> m_faceIndices;
    bool m_isInited;
    GLuint m_vao,m_vboVetex,m_vboIndex;
    int numsToDraw;

};

#endif // MESHGLHELPER

