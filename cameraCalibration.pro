#-------------------------------------------------
#
# Project created by QtCreator 2016-02-29T19:25:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cameraCalibration
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    camcal.cpp \
    glwidget.cc \
    shader.cc \
    trackball.cc

OTHER_FILES += shader/*.vert shader/*.frag

HEADERS  += \
    camcal.h \
    externalimporter.hh \
    common.hh \
    glwidget.hh \
    mainwindow.h \
    meshglhelper.hh \
    shader.hh \
    trackball.hh

FORMS    += mainwindow.ui

DEFINES += _USE_MATH_DEFINES GLM_FORCE_RADIANS

# OpenMesh
INCLUDEPATH += /usr/local/include
LIBS += -lOpenMeshCore

# assimp
INCLUDEPATH += /usr/include/assimp
LIBS += -lassimp

# glew
# INCLUDEPATH +=
LIBS += -lGLEW -lGLU -lGL

# glm
INCLUDEPATH += usr/include/glm

#opencv
INCLUDEPATH += /usr/local/include \
                /usr/local/include/opencv \
                /usr/local/include/opencv2 \

LIBS += /usr/local/lib/libopencv_aruco.so.3.1 \
        /usr/local/lib/libopencv_bgsegm.so.3.1 \
        /usr/local/lib/libopencv_bioinspired.so.3.1 \
        /usr/local/lib/libopencv_calib3d.so.3.1 \
        /usr/local/lib/libopencv_ccalib.so.3.1 \
        /usr/local/lib/libopencv_core.so.3.1 \
        /usr/local/lib/libopencv_datasets.so.3.1 \
        /usr/local/lib/libopencv_dnn.so.3.1 \
        /usr/local/lib/libopencv_dpm.so.3.1 \
        /usr/local/lib/libopencv_face.so.3.1 \
        /usr/local/lib/libopencv_features2d.so.3.1 \
        /usr/local/lib/libopencv_flann.so.3.1 \
        /usr/local/lib/libopencv_fuzzy.so.3.1 \
        /usr/local/lib/libopencv_hdf.so.3.1 \
        /usr/local/lib/libopencv_highgui.so.3.1 \
        /usr/local/lib/libopencv_imgcodecs.so.3.1 \
        /usr/local/lib/libopencv_imgproc.so.3.1 \
        /usr/local/lib/libopencv_line_descriptor.so.3.1 \
        /usr/local/lib/libopencv_ml.so.3.1 \
        /usr/local/lib/libopencv_objdetect.so.3.1 \
        /usr/local/lib/libopencv_optflow.so.3.1 \
        /usr/local/lib/libopencv_photo.so.3.1 \
        /usr/local/lib/libopencv_plot.so.3.1 \
        /usr/local/lib/libopencv_reg.so.3.1 \
        /usr/local/lib/libopencv_rgbd.so.3.1 \
        /usr/local/lib/libopencv_saliency.so.3.1 \
        /usr/local/lib/libopencv_sfm.so.3.1 \
        /usr/local/lib/libopencv_shape.so.3.1 \
        /usr/local/lib/libopencv_stereo.so.3.1 \
        /usr/local/lib/libopencv_stitching.so.3.1 \
        /usr/local/lib/libopencv_structured_light.so.3.1 \
        /usr/local/lib/libopencv_superres.so.3.1 \
        /usr/local/lib/libopencv_surface_matching.so.3.1 \
        /usr/local/lib/libopencv_text.so.3.1 \
        /usr/local/lib/libopencv_tracking.so.3.1 \
        /usr/local/lib/libopencv_videoio.so.3.1 \
        /usr/local/lib/libopencv_video.so.3.1 \
        /usr/local/lib/libopencv_videostab.so.3.1 \
        /usr/local/lib/libopencv_viz.so.3.1 \
        /usr/local/lib/libopencv_xfeatures2d.so.3.1 \
        /usr/local/lib/libopencv_ximgproc.so.3.1 \
        /usr/local/lib/libopencv_xobjdetect.so.3.1 \
        /usr/local/lib/libopencv_xphoto.so.3.1
