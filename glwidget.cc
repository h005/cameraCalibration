#include "glwidget.hh"
#include <iostream>
#include <QMouseEvent>
#include <QOpenGLShaderProgram>
#include <QCoreApplication>
#include <math.h>
#include <glm/gtc/matrix_inverse.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include "shader.hh"
#include "trackball.hh"
#include <QDebug>
#include <stdio.h>


GLWidget::GLWidget(MyMesh &in_mesh,
                   QWidget *parent)
    : QOpenGLWidget(parent),
      m_mesh(in_mesh),
      m_angle(0),
      m_scale(1),
      m_rotateN(1.f),
      m_baseRotate(1.f),
      m_programID(0),
      m_helper(in_mesh),
      v_modelViewMatrix(0)
{
    m_transparent = QCoreApplication::arguments().contains(QStringLiteral("--transparent"));
    if (m_transparent)
        setAttribute(Qt::WA_TranslucentBackground);
}

GLWidget::~GLWidget()
{
    cleanup();
}

QSize GLWidget::minimumSizeHint() const
{
    return QSize(50,50);
}

QSize GLWidget::sizeHint() const
{
    return QSize(800,800);
}

static void qNormalizeAngle(int &angle)
{
    while(angle < 0)
        angle += 360 * 16;
    while(angle > 360 * 16)
        angle -= 360 * 16;
}

void GLWidget::cleanup()
{
    makeCurrent();
    if(m_programID)
    {
        glDeleteProgram(m_programID);
    }
    m_helper.cleanup();
    doneCurrent();
}

void GLWidget::resizeGL(int w,int h)
{
    m_proj = glm::perspective(glm::pi<float>() / 3, GLfloat(w) / h, 1.0f, 10.0f);
}

glm::mat4 GLWidget::getModelViewMatrix()
{
    return (m_camera
            * glm::scale(glm::mat4(1.f), glm::vec3(m_scale, m_scale, m_scale))
            * glm::rotate(glm::mat4(1.f), m_angle, m_rotateN)
            * m_baseRotate);
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    m_lastPos = event->pos();
}

void GLWidget::mouseReleaseEvent(QMouseEvent *event)
{
    glm::mat4 leftRotationMatrix = glm::rotate(glm::mat4(1.f),m_angle,m_rotateN);
    m_baseRotate = leftRotationMatrix * m_baseRotate;

    m_angle = 0.f;
    m_rotateN = glm::vec3(1.f);
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    float width = this->width();
    float height = this->height();

    glm::vec2 a,b;
    a.x = (m_lastPos.x() - width / 2.f) / (width / 2.f);
    a.y = (height / 2.f - m_lastPos.y()) / (height / 2.f);
    b.x = (event->pos().x() - width / 2.f) / (width / 2.f);
    b.y = (height / 2.f - event->pos().y()) / (height / 2.f);

    computeRotation(a,b,m_rotateN,m_angle);
    update();
}

void GLWidget::wheelEvent(QWheelEvent *event)
{
    m_scale += event->delta() / (120.f * 50);
    if (m_scale < 1)
        m_scale = 1;
    if (m_scale > 10)
        m_scale = 10;
    update();
}
