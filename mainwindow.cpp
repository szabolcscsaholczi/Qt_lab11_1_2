#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
{
    //project 1
    setSurfaceType(QWindow::OpenGLSurface);

    //project 2
    QSurfaceFormat formate;
    formate.setProfile(QSurfaceFormat::CompatibilityProfile);
    //Beállítja a kívánt nagyobb és kisebb OpenGL verziókat.
    //Az alapértelmezett verzió 2.0.
    formate.setVersion(2,1);
    setFormat(formate);

    context = new QOpenGLContext;
    context->setFormat(formate);
    context->create();
    context->makeCurrent(this);

    openGLFunctions = context->functions();

    //project 2
    QTimer *timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(UpdateAnimation()));

    timer->start(100);

    rotation = 0;
}

MainWindow::~MainWindow()
{
}

void MainWindow::initializeGL()
{
    glEnable(GL_DEPTH_TEST);//Depth testing is disabled by default
    resizeGL(this->width(), this->height());
}

void MainWindow::resizeGL(int w, int h)
{
    //1 project
    //initialize projection matrix
//    glMatrixMode(GL_PROJECTION);//Applies subsequent matrix operations to the projection matrix stack.
//    glLoadIdentity();

//    //set viewport
//    glViewport(0,0,w, h);

//    qreal aspectratio = qreal (w)/ qreal(h);


//    glOrtho(-1 * aspectratio, 1 * aspectratio, -1,1,1,-1);

    //project 2
    //set viewport
    glViewport(0,0,w, h);

    qreal aspectRatio = qreal (w)/ qreal(h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //gluPerspective(75, aspectratio, 0.1, 400000000);
    glPerspectiveMY(75, aspectRatio, 0.1, 400000000);

    //initialize model view matrix
    glMatrixMode(GL_MODELVIEW);//Applies subsequent matrix operations to the modelview matrix stack.
    glLoadIdentity();

}

void MainWindow::paintGL()
{
    //project 1
    //glClearColor(1.0, 0.0f, 0.0f, 0.0f);
//    glClear(GL_COLOR_BUFFER_BIT);//Indicates the buffers currently enabled for color writing.

//    //delimit the vertices of a primitive or a group of like primitives
//    //A négy csúcs mindegyik csoportját független négyszögként kezeli.
//    glBegin(GL_QUADS);

//    //draw a rectangle
//    //glVertex commands are used within glBegin/glEnd pairs to specify point, line, and polygon vertices.
//    glVertex2f(-0.5f, -0.5f);
//    glVertex2f(0.5f, -0.5f);
//    glVertex2f(0.5f, 0.5f);
//    glVertex2f(-0.5f, 0.5f);

//    //added a color
//    glColor3f(1.0f, 0.0f, 0.0f);
//    glVertex2f(-0.5f, -0.5f);

//    glColor3f(0.0f, 1.0f, 0.0f);
//    glVertex2f(0.5f, -0.5f);

//    glColor3f(0.0f, 0.0f, 1.0f);
//    glVertex2f(0.5f, 0.5f);

//    glColor3f(0.5f, 0.5f, 0.5f);
//    glVertex2f(-0.5f, 0.5f);
//    glEnd();

//    glBegin(GL_TRIANGLES);
//    glVertex2f(-0.4f, -0.4f);
//    glColor3f(1.0f, 0.0f, 0.0f);

//    glVertex2f(0.8f, -0.1f);
//    glColor3f(0.0f, 1.0f, 0.0f);

//    glVertex2f(-0.1f, -0.8f);
//    glColor3f(0.0f, 0.0f, 1.0f);
//    glEnd();

//    glFlush();

    // project 2
    glClearColor(0.39, 0.58f, 0.93f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //reset model view matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // 3D transformation
    glTranslatef(0.0, 0.0, -3.0);
    glRotatef(rotation, 1.0, 1.0, 1.0);

    //front
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glEnd();

    //back
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glEnd();

    //right
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glEnd();

    //left
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f,-0.5f);
    glEnd();

    //top
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glEnd();

    //red side - botton
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glEnd();

    glFlush();

}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    resizeGL(this->width(), this->height());
    this->update();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    paintGL();
}

void MainWindow::UpdateAnimation()
{
    rotation += 10;
    this->update();
}

void MainWindow::glPerspectiveMY( GLdouble fov, GLdouble aspectRatio, GLdouble zNear, GLdouble zFar )
{
    // use glu library functions need to add headers glu.h
    //gluPerspective( fov, aspectRatio, zNear, zFar );
    // use OpenGL functions, but need to add math.h header file
    GLdouble rFov = fov * 3.14159265 / 180.0;
    glFrustum( -zNear * tan( rFov / 2.0 ) * aspectRatio,
               zNear * tan( rFov / 2.0 ) * aspectRatio,
               -zNear * tan( rFov / 2.0 ),
               zNear * tan( rFov / 2.0 ),
               zNear, zFar );
}
