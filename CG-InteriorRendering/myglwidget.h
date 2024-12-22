#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#ifdef MAC_OS
#include <QtOpenGL/QtOpenGL>
#else
#include <GL/glew.h>
#endif
#include <QtGui>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QTimer>
#include <QOpenGLShaderProgram> // 用于着色器编程
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <vector>
#include <assimp/mesh.h>


    
class MyGLWidget : public QOpenGLWidget, protected QOpenGLFunctions {
    Q_OBJECT

public:
    MyGLWidget(QWidget *parent = nullptr);
    ~MyGLWidget();

protected:
    void initializeGL()override;
    void paintGL()override;
    void resizeGL(int width, int height)override;
	void keyPressEvent(QKeyEvent *e)override;

private:
    int scene_id;

    //场景渲染
    void scene_0();
    void scene_1();
    void scene_2();
    //坐标轴
    float axisX = 0.0f;
    float axisY = 0.0f;
    float axisZ = 0.0f;
    //渲染相关辅助函数
    void setupShaders();
    void loadModel(const QString& path);  // 加载模型函数
    void drawModel();  // 绘制加载的模型

    QOpenGLShaderProgram* shaderProgram;
    const aiScene* scene;  // Assimp的场景对象
    std::vector<float> vertexBuffer;  // 用于存储顶点数据
    std::vector<unsigned int> indexBuffer;  // 用于存储索引数据
};
#endif // MYGLWIDGET_H
