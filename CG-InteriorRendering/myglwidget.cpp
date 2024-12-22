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
	//glDisable(GL_DEPTH_TEST);//Ӧ����Ҫ����Ȳ��Ե�

	initializeOpenGLFunctions();
	glEnable(GL_DEPTH_TEST);  // ������Ȳ���

	setupShaders();  // ������ɫ������
	loadModel("path/to/your/model.obj");  // ����ģ���ļ����滻·����
}

void MyGLWidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // �����ɫ����Ȼ���
	if (scene_id == 0) {
		scene_0();
	}
	else if (scene_id == 1) {
		scene_1();
	}
	else if (scene_id == 2) {
		scene_2();
	}
	// ����ģ��
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
	else if (e->key() == Qt::Key_W) { // �Ϸ��������X����������ת
		axisX += 5.0f;
		update();
	}
	else if (e->key() == Qt::Key_S) { // �·��������X�Ḻ������ת
		axisX -= 5.0f;
		update();
	}
	else if (e->key() == Qt::Key_A) { // ���������Y����������ת
		axisY += 5.0f;
		update();
	}
	else if (e->key() == Qt::Key_D) { // �ҷ��������Y�Ḻ������ת
		axisY -= 5.0f;
		update();
	}
	else if (e->key() == Qt::Key_Q) { // Q������Z����������ת
		axisZ += 5.0f;
		update();
	}
	else if (e->key() == Qt::Key_E) { // E������Z�Ḻ������ת
		axisZ -= 5.0f;
		update();
	}
}

void MyGLWidget::setupShaders() {
	shaderProgram = new QOpenGLShaderProgram();

	// ��Ӳ����붥���Ƭ����ɫ��
	shaderProgram->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/vertex_shader.glsl");
	shaderProgram->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/fragment_shader.glsl");
	shaderProgram->link();
	shaderProgram->bind();
}

//�������������ݻ�û�����һЩǰ�ã������Լ���һ�£���Ȼ�ò�����������������ֱ��ɾ��
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
	glRotatef(axisX, 1.0f, 0.0f, 0.0f); // ��X����ת
	glRotatef(axisY, 0.0f, 1.0f, 0.0f); // ��Y����ת
	glRotatef(axisZ, 0.0f, 0.0f, 1.0f); // ��Z����ת

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
	// ��Ӳ����붥���Ƭ����ɫ��
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

	// ����ģ�Ͳ���ȡ�������ݺ���������
	// ע�⣺����Ը����Լ�������������ͬ���͵�ģ�ͺ�����
	aiMesh* mesh = scene->mMeshes[0];
	for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
		aiVector3D vertex = mesh->mVertices[i];
		vertexBuffer.push_back(vertex.x);
		vertexBuffer.push_back(vertex.y);
		vertexBuffer.push_back(vertex.z);
	}

	// ������������
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

	// ����ģ��
	glDrawElements(GL_TRIANGLES, indexBuffer.size(), GL_UNSIGNED_INT, indexBuffer.data());

	glDisableClientState(GL_VERTEX_ARRAY);
}