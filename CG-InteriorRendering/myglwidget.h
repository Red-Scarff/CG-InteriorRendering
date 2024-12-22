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
#include <QOpenGLShaderProgram> // ������ɫ�����
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

    //������Ⱦ
    void scene_0();
    void scene_1();
    void scene_2();
    //������
    float axisX = 0.0f;
    float axisY = 0.0f;
    float axisZ = 0.0f;
    //��Ⱦ��ظ�������
    void setupShaders();
    void loadModel(const QString& path);  // ����ģ�ͺ���
    void drawModel();  // ���Ƽ��ص�ģ��

    QOpenGLShaderProgram* shaderProgram;
    const aiScene* scene;  // Assimp�ĳ�������
    std::vector<float> vertexBuffer;  // ���ڴ洢��������
    std::vector<unsigned int> indexBuffer;  // ���ڴ洢��������
};
#endif // MYGLWIDGET_H
