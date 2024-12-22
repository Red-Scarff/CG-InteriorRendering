#include "myglwidget.h"
#include <QApplication>
#include <QSurfaceFormat>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
//#include "OpenGLWidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    // 设置OpenGL格式
    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setMajorVersion(4);
    format.setMinorVersion(5);
    QSurfaceFormat::setDefaultFormat(format);
    //创建OpenGL窗口
    QApplication a(argc, argv);
    MyGLWidget w;
	w.setWindowTitle("CG-InteriorRendering");
    w.show();

    return a.exec();
}
