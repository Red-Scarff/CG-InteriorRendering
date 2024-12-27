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
    M_NONE,                 // 无操作
    M_MOTION,               // 控制动画
    M_LIGHT,                // 控制光源开关
    M_SHADOWS,              // 控制阴影渲染
    M_REFLECTION,           // 控制反射
    M_FloorShadowObj,       // 控制地板阴影物体
    M_STENCIL_REFLECTION,   // 控制模板反射
    M_STENCIL_SHADOW,       // 控制模板阴影
    M_OFFSET_SHADOW,        // 控制阴影偏移
    M_POSITIONAL,           // 控制点光源
    M_DIRECTIONAL,          // 控制平行光
    M_PERFORMANCE           // 控制性能显示
};

// 窗口大小改变时的回调函数
void handleResize(int w, int h) {
    glViewport(0, 0, w, h);  // 设置视口大小
    glMatrixMode(GL_PROJECTION);  // 切换到投影矩阵
    glLoadIdentity();  // 重置投影矩阵
    gluPerspective(
        45.0,  // 相机视角
        (double)w / (double)h,  // 宽高比
        1.0,  // 近裁剪面
        200.0  // 远裁剪面
    );
}

void drawItems() {
    drawTable();  // 绘制桌子
    book1();      // 绘制书本1
    book1top();   // 绘制书本1的顶部
    book2();      // 绘制书本2
    book2top();   // 绘制书本2的顶部
    book3();      // 绘制书本3
    book3top();   // 绘制书本3的顶部
    pages();      // 绘制书页
    glasscube();  // 绘制玻璃立方体
    drawWallM();  // 绘制墙壁
}

void drawSun() {
    // 定义墙壁的边界
    const float x_wall_min = -15.01f, x_wall_max = 15.01f; // 与墙壁的实际位置一致
    const float y_wall_min = -2.0f, y_wall_max = 8.0f;
    const float z_wall_min = -15.0f, z_wall_max = 15.0f;

    // 检查太阳是否在墙壁范围内
    if (lightPosition[0] >= x_wall_min && lightPosition[0] <= x_wall_max &&
        lightPosition[1] >= y_wall_min && lightPosition[1] <= y_wall_max &&
        lightPosition[2] >= z_wall_min && lightPosition[2] <= z_wall_max) {
        // 如果在墙壁范围内，则不绘制太阳
        return;
    }

    static float pulse = 0.0f;
    static float pulseSpeed = 0.01f;

    // 更新脉动效果
    pulse += pulseSpeed;
    if (pulse > 1.0f || pulse < 0.0f) {
        pulseSpeed = -pulseSpeed;
    }

    glDisable(GL_LIGHTING);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // 绘制光晕
    for (int i = 1; i <= 3; ++i) {
        glColor4f(1.0, 0.8, 0.0, 0.2 / i); // 半透明橙色
        glutSolidSphere(1.5 + i * 0.5, 75, 75); // 进一步缩小光晕半径
    }

    // 绘制光源
    glPushMatrix(); // 保存当前矩阵状态
    glTranslatef(lightPosition[0], lightPosition[1], lightPosition[2]); // 平移到光源位置

    float scale = 1.0f + 0.1f * sin(pulse);
    glScalef(scale, scale, scale);
    glColor3f(1.0, 0.5 + 0.5 * sin(pulse), 0.0); // 颜色动态变化
    //glutSolidSphere(3.0, 75, 75);

    glPopMatrix(); // 恢复矩阵状态

    glDisable(GL_BLEND);
    glEnable(GL_LIGHTING);
}
// 绘制整个场景
void drawScene() {
    // 清除上一次绘制的信息
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);  // 切换到模型视图矩阵
    glLoadIdentity();  // 重置模型视图矩阵

    // 设置相机视角
    gluLookAt(cx, cy, z, cx + lx, 1.0f, z + lz, 0.0f, 1.0f, 0.0f);
    // 启用雾效
    enableFog();
    drawMirrors();  // 绘制镜子
    glDisable(GL_BLEND);
    drawWall();
    glEnable(GL_BLEND);

    glEnable(GL_CULL_FACE);  // 启用面剔除
    glCullFace(GL_FRONT);    // 剔除正面

    drawItems();  // 绘制物体

    glCullFace(GL_BACK);  // 剔除背面

    drawItems();  // 再次绘制物体

    glDisable(GL_CULL_FACE);  // 禁用面剔除
    // 更新粒子
    updateParticles();

    // 渲染粒子
    drawParticles();


    glFlush();  // 强制刷新OpenGL命令

    int start, end;

    if (reportSpeed) {
        start = glutGet(GLUT_ELAPSED_TIME);  // 获取当前时间
    }

    // 重新定位光源位置
    lightPosition[0] = 20 * cos(lightAngle);
    lightPosition[1] = 20 * sin(lightAngle);
    lightPosition[2] = lightHeight;
    lightPosition[3] = 1.0;

    shadowMatrix(floorShadow, floorPlane, lightPosition);  // 计算阴影矩阵

    glPushMatrix();
    // 根据用户鼠标输入进行场景旋转
    glRotatef(angle2, 1.0, 0.0, 0.0);
    glRotatef(ang, 0.0, 1.0, 0.0);

    glDisable(GL_LIGHTING); // 禁用光照
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition); // 设置光源位置
    glEnable(GL_LIGHTING); // 重新启用光照

    if (renderShadow) {
        if (stencilShadow) {
            // 使用模板值3绘制地板，确保阴影只在地板像素上绘制一次
            glEnable(GL_STENCIL_TEST);
            glStencilFunc(GL_ALWAYS, 3, 0xffffffff);
            glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
        }
    }

    // 绘制地板的“顶部”，使用混合来混合反射
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.7f, 0.0f, 0.0f, 0.3f);

    drawFloor();  // 绘制地板
    glDisable(GL_BLEND);

    if (FloorShadow) {
        FloorShadowObj();  // 绘制地板阴影物体
    }

    if (FloorShadow) {
        // 渲染投影阴影
        if (stencilShadow) {
            // 只在模板值大于2的地方渲染阴影，并更新模板值
            glStencilFunc(GL_LESS, 2, 0xffffffff);
            glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);
        }

        // 使用多边形偏移消除深度缓冲伪影
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

        // 在地板上渲染50%黑色阴影
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glDisable(GL_LIGHTING);  // 强制使用50%黑色
        glColor4f(0.0, 0.0, 0.0, 0.5);

        glPushMatrix();
        // 投影阴影
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
    drawSun(); // 绘制美化后的光源

    glPopMatrix();

    if (reportSpeed) {
        glFinish();
        end = glutGet(GLUT_ELAPSED_TIME);
        printf("帧速率 %.3g FPS (%d ms)\n", 100.0 / (end - start), end - start);
    }

    glutSwapBuffers();  // 将3D场景发送到屏幕
}

// 控制光源的菜单回调函数
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

// 窗口可见性改变时的回调函数
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

// 处理键盘输入的回调函数
void handleKeypress(unsigned char key, int x, int y) {
    float fraction = 0.1f;  // 移动步长
    switch (key)
    {
    case 27:  // ESC键
        exit(0);  // 退出程序
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

// 主函数
int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_STENCIL | GLUT_MULTISAMPLE);  // 设置显示模式
    glutInitWindowSize(600, 600);  // 设置窗口大小
    glutCreateWindow("HomeWork_Room");  // 创建窗口
    initRender();  // 初始化渲染

    glutDisplayFunc(drawScene);  // 设置绘制回调函数
    glutVisibilityFunc(visible);  // 设置可见性回调函数
    glutKeyboardFunc(handleKeypress);  // 设置键盘回调函数

    // 创建菜单
    glutCreateMenu(controlLights);
    glutAddMenuEntry("Light_Motion", M_MOTION);
    glutAddMenuEntry("Light", M_LIGHT);
    glutAddMenuEntry("Shadows", M_SHADOWS);
    glutAddMenuEntry("Objects", M_FloorShadowObj);
    glutAddMenuEntry("shadow stenciling", M_STENCIL_SHADOW);
    glutAddMenuEntry("shadow offset", M_OFFSET_SHADOW);

    glutAttachMenu(GLUT_RIGHT_BUTTON);  // 将菜单绑定到右键

    glEnable(GL_CULL_FACE);  // 启用面剔除
    glEnable(GL_DEPTH_TEST);  // 启用深度测试

    glLineWidth(3.0);  // 设置线宽

    glMatrixMode(GL_PROJECTION);
    gluPerspective(
        40.0f,  // 视角
        1.0f,   // 宽高比
        20.0f,  // 近裁剪面
        100.0f  // 远裁剪面
    );
    glMatrixMode(GL_MODELVIEW);
    GLfloat globalAmbient[] = { 0.5f, 0.5f, 0.5f, 1.0f }; // 全局环境光
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbient);

    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);  // 启用局部观察者模式
    glDisable(GL_LIGHTING); // 禁用光照
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition); // 设置光源位置
    glEnable(GL_LIGHTING); // 重新启用光照
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.1f);  // 设置光源衰减
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.05f);
    glEnable(GL_LIGHT0);  // 启用光源
    glEnable(GL_LIGHTING);  // 启用光照



    findPlane(floorPlane, floorVertices[1], floorVertices[2], floorVertices[3]);  // 计算地板平面

    glutSpecialFunc(handleSpecialKeypress);  // 设置特殊键回调函数（用于相机旋转）
    glutReshapeFunc(handleResize);  // 设置窗口大小改变回调函数
    glutTimerFunc(25, update, 0);  // 设置定时器回调函数
    // 初始化粒子系统
    initParticles();

    glutMainLoop();
    // 输出提示信息
    cout << "按 Q、W、E 键切换静态/定向相机的位置 " << endl;

    cout << "按 R 键返回默认动态相机" << endl;

    cout << "使用方向键移动默认动态相机" << endl;

    cout << "右键点击打开菜单 " << endl;
    return 0;
}