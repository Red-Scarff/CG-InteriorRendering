#include "myglwidget.h"
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <iostream>
#include <QFileInfo>

MyGLWidget::MyGLWidget(QWidget *parent)
	:QOpenGLWidget(parent),scene_id(0), axisX(0.0f), axisY(0.0f), axisZ(0.0f)
{
	shaderProgram = nullptr;
}

MyGLWidget::~MyGLWidget()
{
	if (shaderProgram)
	{
		delete shaderProgram;
	}
}

void MyGLWidget::initializeGL()
{
	glViewport(0, 0, width(), height());
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	//glDisable(GL_DEPTH_TEST);//应该是要用深度测试的

	initializeOpenGLFunctions();
	glEnable(GL_DEPTH_TEST);  // 开启深度测试

	setupShaders();  // 设置着色器程序
	loadModel("path/to/your/model.obj");  // 加载模型文件（替换路径）
}

void MyGLWidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // 清除颜色与深度缓冲
	if (scene_id == 0) {
		scene_0();
	}
	else if (scene_id == 1) {
		scene_1();
	}
	else if (scene_id == 2) {
		scene_2();
	}
	// 绘制模型
	if (scene_id) {
		MyGLWidget::drawModel();
	}
}

void MyGLWidget::resizeGL(int width, int height)
{
	glViewport(0, 0, width, height);
	update();
}

void MyGLWidget::keyPressEvent(QKeyEvent *e) {
	//Press 0 or 1 to switch the scene
	if (e->key() == Qt::Key_0) {
		scene_id = 0;
		update();
	}
	else if (e->key() == Qt::Key_1) {
		scene_id = 1;
		update();
	}
	else if (e->key() == Qt::Key_2) {
		scene_id = 2;
		update();
	}
	else if (e->key() == Qt::Key_W) { // 上方向键，绕X轴正方向旋转
		axisX += 5.0f;
		update();
	}
	else if (e->key() == Qt::Key_S) { // 下方向键，绕X轴负方向旋转
		axisX -= 5.0f;
		update();
	}
	else if (e->key() == Qt::Key_A) { // 左方向键，绕Y轴正方向旋转
		axisY += 5.0f;
		update();
	}
	else if (e->key() == Qt::Key_D) { // 右方向键，绕Y轴负方向旋转
		axisY -= 5.0f;
		update();
	}
	else if (e->key() == Qt::Key_Q) { // Q键，绕Z轴正方向旋转
		axisZ += 5.0f;
		update();
	}
	else if (e->key() == Qt::Key_E) { // E键，绕Z轴负方向旋转
		axisZ -= 5.0f;
		update();
	}
}

void MyGLWidget::setupShaders() {
	shaderProgram = new QOpenGLShaderProgram();

	// 添加并编译顶点和片段着色器
	shaderProgram->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/vertex_shader.glsl");
	shaderProgram->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/fragment_shader.glsl");
	shaderProgram->link();
	shaderProgram->bind();
}

//三个场景的内容还没填，放了一些前置，可以自己改一下，当然用不上三个场景，可以直接删掉
void MyGLWidget::scene_0()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, 100.0f, 0.0f, 100.0f, -1000.0f, 1000.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(50.0f, 50.0f, 0.0f);
	
	glPushMatrix();

	glPopMatrix();	
}

void MyGLWidget::scene_1()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, width(), 0.0f, height(), -1000.0f, 1000.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.5 * width(), 0.5 * height(), 0.0f);

    //your implementation here, maybe you should write several glBegin
	glPushMatrix();
	//your implementation
	
	glPopMatrix();
}

void MyGLWidget::scene_2()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);

	// set perspective
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (GLfloat)width() / (GLfloat)height(), 1.0f, 2000.0f);

	// set model matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0f, 0.0f, 500.0f, // look at
		0.0f, 0.0f, 0.0f,  // look for
		0.0f, 1.0f, 0.0f); // up

	// applicate rotate
	glRotatef(axisX, 1.0f, 0.0f, 0.0f); // 绕X轴旋转
	glRotatef(axisY, 0.0f, 1.0f, 0.0f); // 绕Y轴旋转
	glRotatef(axisZ, 0.0f, 0.0f, 1.0f); // 绕Z轴旋转

	static bool seeded = false;
	if (!seeded) {
		srand(static_cast<unsigned>(time(nullptr)));
		seeded = true;
	}

	
	glBegin(GL_QUADS);
	
	glPopMatrix();

	glDisable(GL_DEPTH_TEST);
}

void MyGLWidget::setupShaders() {
	shaderProgram = new QOpenGLShaderProgram();
	// 添加并编译顶点和片段着色器
	shaderProgram->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/vertex_shader.glsl");
	shaderProgram->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/fragment_shader.glsl");
	shaderProgram->link();
	shaderProgram->bind();
}

void MyGLWidget::loadModel(const QString& path) {
	Assimp::Importer importer;
	scene = importer.ReadFile(path.toStdString(), aiProcess_Triangulate | aiProcess_FlipUVs);

	if (!scene || !scene->mRootNode) {
		std::cerr << "Assimp model loading failed: " << importer.GetErrorString() << std::endl;
		return;
	}

	// 遍历模型并获取顶点数据和索引数据
	// 注意：你可以根据自己的需求来处理不同类型的模型和网格
	aiMesh* mesh = scene->mMeshes[0];
	for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
		aiVector3D vertex = mesh->mVertices[i];
		vertexBuffer.push_back(vertex.x);
		vertexBuffer.push_back(vertex.y);
		vertexBuffer.push_back(vertex.z);
	}

	// 处理索引数据
	for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
		aiFace face = mesh->mFaces[i];
		for (unsigned int j = 0; j < face.mNumIndices; j++) {
			indexBuffer.push_back(face.mIndices[j]);
		}
	}
}

void MyGLWidget::drawModel() {
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertexBuffer.data());

	// 绘制模型
	glDrawElements(GL_TRIANGLES, indexBuffer.size(), GL_UNSIGNED_INT, indexBuffer.data());

	glDisableClientState(GL_VERTEX_ARRAY);
}