#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <GL/glew.h>
#include "meshglhelper.hh"

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <glm/glm.hpp>
#include "common.hh"

QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram)

class PointsMatchRelation;
class QString;

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    GLWidget(MyMesh &in_mesh,QWidget *parent = 0);

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

    ~GLWidget();

public slots:
    virtual void cleanup();

signals:

protected:
    void initializeGL() Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
    void resizeGL(int width,int height) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;

protected:
    glm::mat4 getModelViewMatrix();
    glm::mat4 m_proj;
    glm::mat4 m_camera;
    glm::mat4 m_baseRotate;
    glm::mat4 m_rotateN;
    float m_angle;
    GLfloat m_scale;
    GLuint m_programID;
    MeshGLHelper<MyMesh> m_helper;
    MyMesh m_mesh;
    glm::mat4 v_modelViewMatrix;

private:
    GLint viewpoint[4];
    int flag_vertices;
    QPoint m_lastPos;
    bool m_transparent;
};

#endif // GLWIDGET_H
