#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>  
#include "model.h"
#include "Camera.h"
#include "Shadow.h"
#include "Light.h"
#include "Mirror.h"
    
using namespace std;

enum {
    M_NONE,                 // �޲���
    M_MOTION,               // ���ƶ���
    M_LIGHT,                // ���ƹ�Դ����
    M_SHADOWS,              // ������Ӱ��Ⱦ
    M_REFLECTION,           // ���Ʒ���
    M_FloorShadowObj,       // ���Ƶذ���Ӱ����
    M_STENCIL_REFLECTION,   // ����ģ�巴��
    M_STENCIL_SHADOW,       // ����ģ����Ӱ
    M_OFFSET_SHADOW,        // ������Ӱƫ��
    M_POSITIONAL,           // ���Ƶ��Դ
    M_DIRECTIONAL,          // ����ƽ�й�
    M_PERFORMANCE           // ����������ʾ
};

// ���ڴ�С�ı�ʱ�Ļص�����
void handleResize(int w, int h) {
    glViewport(0, 0, w, h);  // �����ӿڴ�С
    glMatrixMode(GL_PROJECTION);  // �л���ͶӰ����
    glLoadIdentity();  // ����ͶӰ����
    gluPerspective(
        45.0,  // ����ӽ�
        (double)w / (double)h,  // ��߱�
        1.0,  // ���ü���
        200.0  // Զ�ü���
    );
}

void drawItems() {
    drawTable();  // ��������
    book1();      // �����鱾1
    book1top();   // �����鱾1�Ķ���
    book2();      // �����鱾2
    book2top();   // �����鱾2�Ķ���
    book3();      // �����鱾3
    book3top();   // �����鱾3�Ķ���
    pages();      // ������ҳ
    glasscube();  // ���Ʋ���������
    drawWallM();  // ����ǽ��
}

void drawSun() {
    // ����ǽ�ڵı߽�
    const float x_wall_min = -15.01f, x_wall_max = 15.01f; // ��ǽ�ڵ�ʵ��λ��һ��
    const float y_wall_min = -2.0f, y_wall_max = 8.0f;
    const float z_wall_min = -15.0f, z_wall_max = 15.0f;

    // ���̫���Ƿ���ǽ�ڷ�Χ��
    if (lightPosition[0] >= x_wall_min && lightPosition[0] <= x_wall_max &&
        lightPosition[1] >= y_wall_min && lightPosition[1] <= y_wall_max &&
        lightPosition[2] >= z_wall_min && lightPosition[2] <= z_wall_max) {
        // �����ǽ�ڷ�Χ�ڣ��򲻻���̫��
        return;
    }

    static float pulse = 0.0f;
    static float pulseSpeed = 0.01f;

    // ��������Ч��
    pulse += pulseSpeed;
    if (pulse > 1.0f || pulse < 0.0f) {
        pulseSpeed = -pulseSpeed;
    }

    glDisable(GL_LIGHTING);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // ���ƹ���
    for (int i = 1; i <= 3; ++i) {
        glColor4f(1.0, 0.8, 0.0, 0.2 / i); // ��͸����ɫ
        glutSolidSphere(1.5 + i * 0.5, 75, 75); // ��һ����С���ΰ뾶
    }

    // ���ƹ�Դ
    glPushMatrix(); // ���浱ǰ����״̬
    glTranslatef(lightPosition[0], lightPosition[1], lightPosition[2]); // ƽ�Ƶ���Դλ��

    float scale = 1.0f + 0.1f * sin(pulse);
    glScalef(scale, scale, scale);
    glColor3f(1.0, 0.5 + 0.5 * sin(pulse), 0.0); // ��ɫ��̬�仯
    //glutSolidSphere(3.0, 75, 75);

    glPopMatrix(); // �ָ�����״̬

    glDisable(GL_BLEND);
    glEnable(GL_LIGHTING);
}
// ������������
void drawScene() {
    // �����һ�λ��Ƶ���Ϣ
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);  // �л���ģ����ͼ����
    glLoadIdentity();  // ����ģ����ͼ����

    // ��������ӽ�
    gluLookAt(cx, cy, z, cx + lx, 1.0f, z + lz, 0.0f, 1.0f, 0.0f);
    // ������Ч
    enableFog();
    drawMirrors();  // ���ƾ���
    glDisable(GL_BLEND);
    drawWall();
    glEnable(GL_BLEND);

    glEnable(GL_CULL_FACE);  // �������޳�
    glCullFace(GL_FRONT);    // �޳�����

    drawItems();  // ��������

    glCullFace(GL_BACK);  // �޳�����

    drawItems();  // �ٴλ�������

    glDisable(GL_CULL_FACE);  // �������޳�
    // ��������
    updateParticles();

    // ��Ⱦ����
    drawParticles();


    glFlush();  // ǿ��ˢ��OpenGL����

    int start, end;

    if (reportSpeed) {
        start = glutGet(GLUT_ELAPSED_TIME);  // ��ȡ��ǰʱ��
    }

    // ���¶�λ��Դλ��
    lightPosition[0] = 20 * cos(lightAngle);
    lightPosition[1] = 20 * sin(lightAngle);
    lightPosition[2] = lightHeight;
    lightPosition[3] = 1.0;

    shadowMatrix(floorShadow, floorPlane, lightPosition);  // ������Ӱ����

    glPushMatrix();
    // �����û����������г�����ת
    glRotatef(angle2, 1.0, 0.0, 0.0);
    glRotatef(ang, 0.0, 1.0, 0.0);

    glDisable(GL_LIGHTING); // ���ù���
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition); // ���ù�Դλ��
    glEnable(GL_LIGHTING); // �������ù���

    if (renderShadow) {
        if (stencilShadow) {
            // ʹ��ģ��ֵ3���Ƶذ壬ȷ����Ӱֻ�ڵذ������ϻ���һ��
            glEnable(GL_STENCIL_TEST);
            glStencilFunc(GL_ALWAYS, 3, 0xffffffff);
            glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
        }
    }

    // ���Ƶذ�ġ���������ʹ�û������Ϸ���
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.7f, 0.0f, 0.0f, 0.3f);

    drawFloor();  // ���Ƶذ�
    glDisable(GL_BLEND);

    if (FloorShadow) {
        FloorShadowObj();  // ���Ƶذ���Ӱ����
    }

    if (FloorShadow) {
        // ��ȾͶӰ��Ӱ
        if (stencilShadow) {
            // ֻ��ģ��ֵ����2�ĵط���Ⱦ��Ӱ��������ģ��ֵ
            glStencilFunc(GL_LESS, 2, 0xffffffff);
            glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);
        }

        // ʹ�ö����ƫ��������Ȼ���αӰ
        if (offsetShadow) {
            switch (polygonOffsetVersion) {
            case EXTENSION:
#ifdef GL_EXT_polygon_offset
                glEnable(GL_POLYGON_OFFSET_EXT);
                break;
#endif
#ifdef GL_VERSION_1_1
            case ONE_DOT_ONE:
                glEnable(GL_POLYGON_OFFSET_FILL);
                break;
#endif
            case MISSING:
                break;
            }
        }

        // �ڵذ�����Ⱦ50%��ɫ��Ӱ
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glDisable(GL_LIGHTING);  // ǿ��ʹ��50%��ɫ
        glColor4f(0.0, 0.0, 0.0, 0.5);

        glPushMatrix();
        // ͶӰ��Ӱ
        glMultMatrixf((GLfloat*)floorShadow);
        FloorShadowObj();
        glPopMatrix();

        glDisable(GL_BLEND);
        glEnable(GL_LIGHTING);

        if (offsetShadow) {
            switch (polygonOffsetVersion) {
#ifdef GL_EXT_polygon_offset
            case EXTENSION:
                glDisable(GL_POLYGON_OFFSET_EXT);
                break;
#endif
#ifdef GL_VERSION_1_1
            case ONE_DOT_ONE:
                glDisable(GL_POLYGON_OFFSET_FILL);
                break;
#endif
            case MISSING:
                break;
            }
        }
        if (stencilShadow) {
            glDisable(GL_STENCIL_TEST);
        }
    }

    glTranslatef(lightPosition[0], lightPosition[1], lightPosition[2]);
    drawSun(); // ����������Ĺ�Դ

    glPopMatrix();

    if (reportSpeed) {
        glFinish();
        end = glutGet(GLUT_ELAPSED_TIME);
        printf("֡���� %.3g FPS (%d ms)\n", 100.0 / (end - start), end - start);
    }

    glutSwapBuffers();  // ��3D�������͵���Ļ
}

// ���ƹ�Դ�Ĳ˵��ص�����
static void controlLights(int value) {
    switch (value) {
    case M_NONE:
        return;
    case M_MOTION:
        animation = 1 - animation;
        if (animation) {
            glutIdleFunc(idle);
        }
        else {
            glutIdleFunc(NULL);
        }
        break;
    case M_LIGHT:
        lightSwitch = !lightSwitch;
        if (lightSwitch) {
            glEnable(GL_LIGHT0);
        }
        else {
            glDisable(GL_LIGHT0);
        }
        break;

    case M_SHADOWS:
        renderShadow = 1 - renderShadow;
        break;

    case M_FloorShadowObj:
        FloorShadow = 1 - FloorShadow;
        break;

    case M_STENCIL_SHADOW:
        stencilShadow = 1 - stencilShadow;
        break;
    case M_OFFSET_SHADOW:
        offsetShadow = 1 - offsetShadow;
        break;
    case M_POSITIONAL:
        directionalLight = 0;
        break;
    case M_DIRECTIONAL:
        directionalLight = 1;
        break;
    }
    glutPostRedisplay();
}

// ���ڿɼ��Ըı�ʱ�Ļص�����
static void visible(int vis) {
    if (vis == GLUT_VISIBLE) {
        if (animation)
            glutIdleFunc(idle);
    }
    else {
        if (!animation)
            glutIdleFunc(NULL);
    }
}

// �����������Ļص�����
void handleKeypress(unsigned char key, int x, int y) {
    float fraction = 0.1f;  // �ƶ�����
    switch (key)
    {
    case 27:  // ESC��
        exit(0);  // �˳�����
    case 'q':
        cx = -15.0f;
        cy = 8.0f;
        z = 15.0f;
        lx = +15.0f;
        lz = -15.0f;
        drawScene();
        break;
    case 'w':
        cx = 15.0f;
        cy = 0.0f;
        z = 15.0f;
        lx = -15.0f;
        lz = -15.0f;
        drawScene();
        break;
    case 'e':
        cx = 15.0f;
        cy = 8.0f;
        z = -15.0f;
        lx = -15.0f;
        lz = 15.0f;
        drawScene();
        break;
    case 'r':
        cx = -1.0f;
        cy = 1.0f;
        z = 13.0f;
        lx = 0.0f;
        lz = -1.0f;
        drawScene();
        break;
    default:
        cx = -1.0f;
        cy = 1.0f;
        z = 13.0f;
        lx = 0.0f;
        lz = -1.0f;
        drawScene();
        break;
    }
}

// ������
int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_STENCIL | GLUT_MULTISAMPLE);  // ������ʾģʽ
    glutInitWindowSize(600, 600);  // ���ô��ڴ�С
    glutCreateWindow("HomeWork_Room");  // ��������
    initRender();  // ��ʼ����Ⱦ

    glutDisplayFunc(drawScene);  // ���û��ƻص�����
    glutVisibilityFunc(visible);  // ���ÿɼ��Իص�����
    glutKeyboardFunc(handleKeypress);  // ���ü��̻ص�����

    // �����˵�
    glutCreateMenu(controlLights);
    glutAddMenuEntry("Light_Motion", M_MOTION);
    glutAddMenuEntry("Light", M_LIGHT);
    glutAddMenuEntry("Shadows", M_SHADOWS);
    glutAddMenuEntry("Objects", M_FloorShadowObj);
    glutAddMenuEntry("shadow stenciling", M_STENCIL_SHADOW);
    glutAddMenuEntry("shadow offset", M_OFFSET_SHADOW);

    glutAttachMenu(GLUT_RIGHT_BUTTON);  // ���˵��󶨵��Ҽ�

    glEnable(GL_CULL_FACE);  // �������޳�
    glEnable(GL_DEPTH_TEST);  // ������Ȳ���

    glLineWidth(3.0);  // �����߿�

    glMatrixMode(GL_PROJECTION);
    gluPerspective(
        40.0f,  // �ӽ�
        1.0f,   // ��߱�
        20.0f,  // ���ü���
        100.0f  // Զ�ü���
    );
    glMatrixMode(GL_MODELVIEW);
    GLfloat globalAmbient[] = { 0.5f, 0.5f, 0.5f, 1.0f }; // ȫ�ֻ�����
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbient);

    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);  // ���þֲ��۲���ģʽ
    glDisable(GL_LIGHTING); // ���ù���
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition); // ���ù�Դλ��
    glEnable(GL_LIGHTING); // �������ù���
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.1f);  // ���ù�Դ˥��
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.05f);
    glEnable(GL_LIGHT0);  // ���ù�Դ
    glEnable(GL_LIGHTING);  // ���ù���



    findPlane(floorPlane, floorVertices[1], floorVertices[2], floorVertices[3]);  // ����ذ�ƽ��

    glutSpecialFunc(handleSpecialKeypress);  // ����������ص����������������ת��
    glutReshapeFunc(handleResize);  // ���ô��ڴ�С�ı�ص�����
    glutTimerFunc(25, update, 0);  // ���ö�ʱ���ص�����
    // ��ʼ������ϵͳ
    initParticles();

    glutMainLoop();
    // �����ʾ��Ϣ
    cout << "�� Q��W��E ���л���̬/���������λ�� " << endl;

    cout << "�� R ������Ĭ�϶�̬���" << endl;

    cout << "ʹ�÷�����ƶ�Ĭ�϶�̬���" << endl;

    cout << "�Ҽ�����򿪲˵� " << endl;
    return 0;
}