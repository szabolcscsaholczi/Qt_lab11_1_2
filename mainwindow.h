#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QOpenGLWindow>

#include <QSurfaceFormat>
#include <QOpenGLFunctions>
#include <QtOpenGL>
#include <GL/glu.h>

class MainWindow : public QOpenGLWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    virtual void initializeGL();
    virtual void resizeGL(int width, int height);
    virtual void paintGL();
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);

//project 2
public slots:
    void UpdateAnimation();

private:
    QOpenGLContext *context;
    QOpenGLFunctions  *openGLFunctions;
    void glPerspectiveMY( GLdouble fov, GLdouble aspectRatio, GLdouble zNear, GLdouble zFar );

    float rotation;
};
#endif // MAINWINDOW_H
