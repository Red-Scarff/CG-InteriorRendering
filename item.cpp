#include "items.h"

// 构造函数
Scene::Scene() {
    Rs = 15.0f; // 房间的大小
    Tw = 2.0f;  // 桌子顶部的宽度（从中心开始）
    Tl = 4.0f;  // 桌子顶部的长度（从中心开始）
    Th = 1.7f;  // 桌子顶部的高度（从中心开始）
    Tt = 0.3f;  // 桌子顶部的厚度
    Ls = 0.3f;  // 桌子腿的大小

    Bw = 2.0f / 3.0f; // 书本的宽度（从中心开始）
    Bl = 4.0f / 3.0f; // 书本的长度（从中心开始）
    Bh = 2.0f;        // 书本的高度（从中心开始）
    Bt = 0.025f;      // 书本封面的厚度
    Btt = 0.1f;       // 书本1和2的厚度
    Btt3 = 0.13f;     // 书本3的厚度
    Bb = 0.03f;       // 书本装订的厚度
    ang1 = 5.0f;      // 书本1的旋转角度
    B2h = Bt + Btt;   // 书本2的高度
    B3h = 2 * B2h;    // 书本3的高度
    ang2 = 30.0f;     // 书本2的旋转角度
    ang3 = 190.0f;    // 书本3的旋转角度

    a = 0.0f;         // 立方体的位置
    b = 0.0f;
    c = 0.0f;
    d = 1.5f;         // 立方体的大小
    _min = 0.0f;
    _max = 1.0f;
    wll = 0.01f;
}

// 析构函数
Scene::~Scene() {}

// 绘制桌子顶部
void Scene::drawTableTop() {
    glPushMatrix();
    glTranslatef(0.0f, -2.0f, 0.0f);

    glBegin(GL_QUADS);
    // 底部
    glTexCoord2f(_min, _min);
    glVertex3f(-Tw, Th, Tl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Tw, Th, -Tl);
    glTexCoord2f(_max, _max);
    glVertex3f(Tw, Th, -Tl);
    glTexCoord2f(_min, _max);
    glVertex3f(Tw, Th, Tl);
    // 顶部
    glTexCoord2f(_min, _min);
    glVertex3f(-Tw, Th + Tt, Tl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Tw, Th, Tl);
    glTexCoord2f(_max, _max);
    glVertex3f(Tw, Th, Tl);
    glTexCoord2f(_min, _max);
    glVertex3f(Tw, Th + Tt, Tl);
    // 背面
    glTexCoord2f(_min, _min);
    glVertex3f(Tw, Th + Tt, -Tl);
    glTexCoord2f(_max, _min);
    glVertex3f(Tw, Th, -Tl);
    glTexCoord2f(_max, _max);
    glVertex3f(-Tw, Th, -Tl);
    glTexCoord2f(_min, _max);
    glVertex3f(-Tw, Th + Tt, -Tl);
    // 右侧
    glTexCoord2f(_min, _min);
    glVertex3f(Tw, Th + Tt, Tl);
    glTexCoord2f(_max, _min);
    glVertex3f(Tw, Th, Tl);
    glTexCoord2f(_max, _max);
    glVertex3f(Tw, Th, -Tl);
    glTexCoord2f(_min, _max);
    glVertex3f(Tw, Th + Tt, -Tl);
    // 左侧
    glTexCoord2f(_max, _max);
    glVertex3f(-Tw, Th + Tt, Tl);
    glTexCoord2f(_min, _max);
    glVertex3f(-Tw, Th + Tt, -Tl);
    glTexCoord2f(_min, _min);
    glVertex3f(-Tw, Th, -Tl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Tw, Th, Tl);
    // 顶部
    glTexCoord2f(_min, _min);
    glVertex3f(-Tw, Th + Tt, Tl);
    glTexCoord2f(_min, _max);
    glVertex3f(Tw, Th + Tt, Tl);
    glTexCoord2f(_max, _max);
    glVertex3f(Tw, Th + Tt, -Tl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Tw, Th + Tt, -Tl);
    glEnd();
    glPopMatrix();
}

// 绘制第一条桌腿
void Scene::firstLeg() {
    glPushMatrix();
    glTranslatef(0.0f, -2.0f, 0.0f);

    glBegin(GL_QUADS);
    // 前面
    glNormal3f(0, 0, 1);
    glTexCoord2f(_min, _min);
    glVertex3f(-Tw + Ls, Th, Tl - Ls);
    glTexCoord2f(_max, _min);
    glVertex3f(-Tw + Ls, 0.0f, Tl - Ls);
    glTexCoord2f(_max, _max);
    glVertex3f(-Tw + Ls + Ls, 0.0f, Tl - Ls);
    glTexCoord2f(_min, _max);
    glVertex3f(-Tw + Ls + Ls, Th, Tl - Ls);
    // 背面
    glNormal3f(0, 0, -1);
    glTexCoord2f(1, 1);
    glVertex3f(-Tw + Ls, Th, Tl - Ls - Ls);
    glTexCoord2f(0, 1);
    glVertex3f(-Tw + Ls + Ls, Th, Tl - Ls - Ls);
    glTexCoord2f(0, 0);
    glVertex3f(-Tw + Ls + Ls, 0.0f, Tl - Ls - Ls);
    glTexCoord2f(1, 0);
    glVertex3f(-Tw + Ls, 0.0f, Tl - Ls - Ls);
    // 右侧
    glNormal3f(1, 0, 0);
    glTexCoord2f(0, 1);
    glVertex3f(-Tw + Ls + Ls, Th, Tl - Ls);
    glTexCoord2f(0, 0);
    glVertex3f(-Tw + Ls + Ls, 0.0f, Tl - Ls);
    glTexCoord2f(1, 0);
    glVertex3f(-Tw + Ls + Ls, 0.0f, Tl - Ls - Ls);
    glTexCoord2f(1, 1);
    glVertex3f(-Tw + Ls + Ls, Th, Tl - Ls - Ls);
    // 左侧
    glNormal3f(-1, 0, 0);
    glTexCoord2f(1, 1);
    glVertex3f(-Tw + Ls, Th, Tl - Ls);
    glTexCoord2f(0, 1);
    glVertex3f(-Tw + Ls, Th, Tl - Ls - Ls);
    glTexCoord2f(0, 0);
    glVertex3f(-Tw + Ls, 0.0f, Tl - Ls - Ls);
    glTexCoord2f(1, 0);
    glVertex3f(-Tw + Ls, 0.0f, Tl - Ls);
    glEnd();
    glPopMatrix();
}

// 绘制第二条桌腿
void Scene::secondLeg() {
    glPushMatrix();
    glTranslatef(0.0f, -2.0f, 0.0f);

    glBegin(GL_QUADS);
    // 前面
    glNormal3f(0, 0, 1);
    glTexCoord2f(1, 1);
    glVertex3f(Tw - Ls, Th, Tl - Ls);
    glTexCoord2f(0, 1);
    glVertex3f(Tw - Ls - Ls, Th, Tl - Ls);
    glTexCoord2f(0, 0);
    glVertex3f(Tw - Ls - Ls, 0.0f, Tl - Ls);
    glTexCoord2f(1, 0);
    glVertex3f(Tw - Ls, 0.0f, Tl - Ls);
    // 背面
    glNormal3f(0, 0, -1);
    glTexCoord2f(0, 1);
    glVertex3f(Tw - Ls, Th, Tl - Ls - Ls);
    glTexCoord2f(0, 0);
    glVertex3f(Tw - Ls, 0.0f, Tl - Ls - Ls);
    glTexCoord2f(1, 0);
    glVertex3f(Tw - Ls - Ls, 0.0f, Tl - Ls - Ls);
    glTexCoord2f(1, 1);
    glVertex3f(Tw - Ls - Ls, Th, Tl - Ls - Ls);
    // 左侧
    glNormal3f(-1, 0, 0);
    glTexCoord2f(1, 1);
    glVertex3f(Tw - Ls - Ls, Th, Tl - Ls);
    glTexCoord2f(0, 1);
    glVertex3f(Tw - Ls - Ls, Th, Tl - Ls - Ls);
    glTexCoord2f(0, 0);
    glVertex3f(Tw - Ls - Ls, 0.0f, Tl - Ls - Ls);
    glTexCoord2f(1, 0);
    glVertex3f(Tw - Ls - Ls, 0.0f, Tl - Ls);
    // 右侧
    glNormal3f(1, 0, 0);
    glTexCoord2f(0, 1);
    glVertex3f(Tw - Ls, Th, Tl - Ls);
    glTexCoord2f(0, 0);
    glVertex3f(Tw - Ls, 0.0f, Tl - Ls);
    glTexCoord2f(1, 0);
    glVertex3f(Tw - Ls, 0.0f, Tl - Ls - Ls);
    glTexCoord2f(1, 1);
    glVertex3f(Tw - Ls, Th, Tl - Ls - Ls);
    glEnd();
    glPopMatrix();
}

// 绘制第三条桌腿
void Scene::thirdLeg() {
    glPushMatrix(); 
    glTranslatef(0.0f, -2.0f, 0.0f);

    glBegin(GL_QUADS);
    
    glNormal3f(0, 0, 1);
    glTexCoord2f(_min, _min);
    glVertex3f(-Tw + Ls, Th, -Tl + Ls);
    glTexCoord2f(_max, _min);
    glVertex3f(-Tw + Ls, 0.0f, -Tl + Ls);
    glTexCoord2f(_max, _max);
    glVertex3f(-Tw + Ls + Ls, 0.0f, -Tl + Ls);
    glTexCoord2f(_min, _max);
    glVertex3f(-Tw + Ls + Ls, Th, -Tl + Ls);
   
    glNormal3f(0, 0, -1);
    glTexCoord2f(1, 1);
    glVertex3f(-Tw + Ls, Th, -Tl + Ls + Ls);
    glTexCoord2f(0, 1);
    glVertex3f(-Tw + Ls + Ls, Th, -Tl + Ls + Ls);
    glTexCoord2f(0, 0);
    glVertex3f(-Tw + Ls + Ls, 0.0f, -Tl + Ls + Ls);
    glTexCoord2f(1, 0);
    glVertex3f(-Tw + Ls, 0.0f, -Tl + Ls + Ls);
   
    glNormal3f(1, 0, 0);
    glTexCoord2f(0, 1);
    glVertex3f(-Tw + Ls + Ls, Th, -Tl + Ls);
    glTexCoord2f(0, 0);
    glVertex3f(-Tw + Ls + Ls, 0.0f, -Tl + Ls);
    glTexCoord2f(1, 0);
    glVertex3f(-Tw + Ls + Ls, 0.0f, -Tl + Ls + Ls);
    glTexCoord2f(1, 1);
    glVertex3f(-Tw + Ls + Ls, Th, -Tl + Ls + Ls);
  
    glNormal3f(-1, 0, 0);
    glTexCoord2f(1, 1);
    glVertex3f(-Tw + Ls, Th, -Tl + Ls);
    glTexCoord2f(0, 1);
    glVertex3f(-Tw + Ls, Th, -Tl + Ls + Ls);
    glTexCoord2f(0, 0);
    glVertex3f(-Tw + Ls, 0.0f, -Tl + Ls + Ls);
    glTexCoord2f(1, 0);
    glVertex3f(-Tw + Ls, 0.0f, -Tl + Ls);
    glEnd();
    glPopMatrix();
}

// 绘制第四条桌腿
void Scene::fourthLeg() {
    glPushMatrix();
    glTranslatef(0.0f, -2.0f, 0.0f);

    glBegin(GL_QUADS);
    // 前面
    glNormal3f(0, 0, 1);
    glTexCoord2f(1, 1);
    glVertex3f(Tw - Ls, Th, -Tl + Ls);
    glTexCoord2f(0, 1);
    glVertex3f(Tw - Ls - Ls, Th, -Tl + Ls);
    glTexCoord2f(0, 0);
    glVertex3f(Tw - Ls - Ls, 0.0f, -Tl + Ls);
    glTexCoord2f(1, 0);
    glVertex3f(Tw - Ls, 0.0f, -Tl + Ls);
    // 背面
    glNormal3f(0, 0, -1);
    glTexCoord2f(0, 1);
    glVertex3f(Tw - Ls, Th, -Tl + Ls + Ls);
    glTexCoord2f(0, 0);
    glVertex3f(Tw - Ls, 0.0f, -Tl + Ls + Ls);
    glTexCoord2f(1, 0);
    glVertex3f(Tw - Ls - Ls, 0.0f, -Tl + Ls + Ls);
    glTexCoord2f(1, 1);
    glVertex3f(Tw - Ls - Ls, Th, -Tl + Ls + Ls);
    // 左侧
    glNormal3f(-1, 0, 0);
    glTexCoord2f(1, 1);
    glVertex3f(Tw - Ls - Ls, Th, -Tl + Ls);
    glTexCoord2f(0, 1);
    glVertex3f(Tw - Ls - Ls, Th, -Tl + Ls + Ls);
    glTexCoord2f(0, 0);
    glVertex3f(Tw - Ls - Ls, 0.0f, -Tl + Ls + Ls);
    glTexCoord2f(1, 0);
    glVertex3f(Tw - Ls - Ls, 0.0f, -Tl + Ls);
    // 右侧
    glNormal3f(1, 0, 0);
    glTexCoord2f(0, 1);
    glVertex3f(Tw - Ls, Th, -Tl + Ls);
    glTexCoord2f(0, 0);
    glVertex3f(Tw - Ls, 0.0f, -Tl + Ls);
    glTexCoord2f(1, 0);
    glVertex3f(Tw - Ls, 0.0f, -Tl + Ls + Ls);
    glTexCoord2f(1, 1);
    glVertex3f(Tw - Ls, Th, -Tl + Ls + Ls);
    glEnd();
    glPopMatrix();
}

// 绘制玻璃立方体
void Scene::dGlassCube() {
    glPushMatrix();
    glTranslatef(0.3f, 0.0f, -2.3f);

    glBegin(GL_QUADS);
    // 前面
    glTexCoord2f(0, 0);
    glVertex3f(a, b, c);
    glTexCoord2f(1, 0);
    glVertex3f(a + d, b, c);
    glTexCoord2f(1, 1);
    glVertex3f(a + d, b + d, c);
    glTexCoord2f(0, 1);
    glVertex3f(a, b + d, c);
    // 右侧
    glTexCoord2f(_min, _min);
    glVertex3f(a + d, b, c);
    glTexCoord2f(_max, _min);
    glVertex3f(a + d, b, c - d);
    glTexCoord2f(_max, _max);
    glVertex3f(a + d, b + d, c - d);
    glTexCoord2f(_min, _max);
    glVertex3f(a + d, b + d, c);
    // 背面
    glTexCoord2f(_min, _min);
    glVertex3f(a + d, b, c - d);
    glTexCoord2f(_max, _min);
    glVertex3f(a, b, c - d);
    glTexCoord2f(_max, _max);
    glVertex3f(a, b + d, c - d);
    glTexCoord2f(_min, _max);
    glVertex3f(a + d, b + d, c - d);
    // 左侧
    glTexCoord2f(_min, _min);
    glVertex3f(a, b, c - d);
    glTexCoord2f(_max, _min);
    glVertex3f(a, b, c);
    glTexCoord2f(_max, _max);
    glVertex3f(a, b + d, c);
    glTexCoord2f(_min, _max);
    glVertex3f(a, b + d, c - d);
    // 顶部
    glTexCoord2f(_min, _min);
    glVertex3f(a, b + d, c);
    glTexCoord2f(_max, _min);
    glVertex3f(a + d, b + d, c);
    glTexCoord2f(_max, _max);
    glVertex3f(a + d, b + d, c - d);
    glTexCoord2f(_min, _max);
    glVertex3f(a, b + d, c - d);
    // 底部
    glTexCoord2f(_min, _min);
    glVertex3f(a, b, c);
    glTexCoord2f(_min, _max);
    glVertex3f(a, b, c - d);
    glTexCoord2f(_max, _max);
    glVertex3f(a + d, b, c - d);
    glTexCoord2f(_max, _min);
    glVertex3f(a + d, b, c);
    glEnd();
    glPopMatrix();
}

// 绘制书本1
void Scene::bk1() {
    glPushMatrix();
    glTranslatef(-1.0f, -2.0f, 2.0f);
    glRotatef(ang1, 0.0f, 1.0f, 0.0f);

    glBegin(GL_QUADS);
    glNormal3f(0, 1, 0);
    // 底部封面
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, -Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw, Bh, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(Bw, Bh, Bl);
    // 顶部封面
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh + Bt, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh + Bt, -Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw, Bh + Bt, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(Bw, Bh + Bt, Bl);
    // 前面
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh + Bt, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw, Bh, Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(Bw, Bh + Bt, Bl);
    // 背面
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh + Bt, -Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, -Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw, Bh, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(Bw, Bh + Bt, -Bl);
    // 右侧
    glTexCoord2f(_min, _min);
    glVertex3f(Bw, Bh + Bt, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(Bw, Bh, Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw, Bh, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(Bw, Bh + Bt, -Bl);
    // 左侧
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh + Bt, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(-Bw, Bh, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(-Bw, Bh + Bt, -Bl);
    glEnd();
    glPopMatrix();

    // 顶部封面
    glPushMatrix();
    glTranslatef(-1.0f, -2.0f + Btt, 2.0f);
    glRotatef(ang1, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    // 顶部
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh + Bt, Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(-Bw, Bh + Bt, -Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw, Bh + Bt, -Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(Bw, Bh + Bt, Bl);
    glEnd();
    glPopMatrix();

    // 装订
    glPushMatrix();
    glTranslatef(-1.0f, -2.0f, 2.0f);
    glRotatef(ang1, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    // 前面
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw - Bb, Bh, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(-Bw, Bh + Bt + Btt, Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(-Bw - Bb, Bh + Bt + Btt, Bl);
    // 背面
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw - Bb, Bh, -Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, -Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(-Bw, Bh + Bt + Btt, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(-Bw - Bb, Bh + Bt + Btt, -Bl);
    // 左侧
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw - Bb, Bh, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw - Bb, Bh, -Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(-Bw - Bb, Bh + Bt + Btt, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(-Bw - Bb, Bh + Bt + Btt, Bl);
    // 右侧
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, -Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(-Bw, Bh + Bt + Btt, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(-Bw, Bh + Bt + Btt, Bl);
    // 顶部
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw - Bb, Bh + Bt + Btt, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh + Bt + Btt, Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(-Bw, Bh + Bt + Btt, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(-Bw - Bb, Bh + Bt + Btt, -Bl);
    glEnd();
    glPopMatrix();
}

void Scene::bk2() {
    glPushMatrix(); // 2
    glTranslatef(-1.0f, -2.0f + B2h, 2.0f); // move to lie on the left corner of the table
    glRotatef(ang2, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glNormal3f(0, 1, 0);
    /////////////bottom cover///
    // bottom
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, -Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw, Bh, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(Bw, Bh, Bl);
    // top
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh + Bt, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh + Bt, -Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw, Bh + Bt, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(Bw, Bh + Bt, Bl);
    // front
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh + Bt, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw, Bh, Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(Bw, Bh + Bt, Bl);
    // back
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh + Bt, -Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, -Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw, Bh, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(Bw, Bh + Bt, -Bl);
    // right
    glTexCoord2f(_min, _min);
    glVertex3f(Bw, Bh + Bt, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(Bw, Bh, Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw, Bh, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(Bw, Bh + Bt, -Bl);
    // left
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh + Bt, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(-Bw, Bh, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(-Bw, Bh + Bt, -Bl);

    glEnd();
    glPopMatrix(); // 2

    ///////////////top cover////////
    glPushMatrix(); // 3
    glTranslatef(-1.0f, -2.0f + B2h + Btt, 2.0f); // move up to lie above bottom cover
    glRotatef(ang2, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    // bottom
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, -Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw, Bh, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(Bw, Bh, Bl);
    // front
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh + Bt, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw, Bh, Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(Bw, Bh + Bt, Bl);
    // back
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh + Bt, -Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, -Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw, Bh, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(Bw, Bh + Bt, -Bl);
    // right
    glTexCoord2f(_min, _min);
    glVertex3f(Bw, Bh + Bt, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(Bw, Bh, Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw, Bh, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(Bw, Bh + Bt, -Bl);
    // left
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh + Bt, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(-Bw, Bh, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(-Bw, Bh + Bt, -Bl);

    glEnd();
    glPopMatrix(); // 3
    ////////////////////binding//////
    glPushMatrix(); // 5
    glTranslatef(-1.0f, -2.0f + B2h, 2.0f);
    glRotatef(ang2, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);

    // front
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw - Bb, Bh, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(-Bw, Bh + Bt + Btt, Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(-Bw - Bb, Bh + Bt + Btt, Bl);
    // back
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw - Bb, Bh, -Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, -Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(-Bw, Bh + Bt + Btt, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(-Bw - Bb, Bh + Bt + Btt, -Bl);
    // left
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw - Bb, Bh, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw - Bb, Bh, -Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(-Bw - Bb, Bh + Bt + Btt, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(-Bw - Bb, Bh + Bt + Btt, Bl);
    // right
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, -Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(-Bw, Bh + Bt + Btt, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(-Bw, Bh + Bt + Btt, Bl);
    // top
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw - Bb, Bh + Bt + Btt, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh + Bt + Btt, Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(-Bw, Bh + Bt + Btt, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(-Bw - Bb, Bh + Bt + Btt, -Bl);
    glEnd();
    glPopMatrix(); // 5
}

void Scene::bk3() {
    glPushMatrix(); // 2
    glTranslatef(-1.0f, -2.0f + B3h, 2.0f); // move to lie on the left corner of the table
    glRotatef(ang3, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glNormal3f(0, 1, 0);
    /////////////bottom cover///
    // bottom
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, -Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw, Bh, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(Bw, Bh, Bl);
    // top
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh + Bt, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh + Bt, -Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw, Bh + Bt, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(Bw, Bh + Bt, Bl);
    // front
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh + Bt, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw, Bh, Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(Bw, Bh + Bt, Bl);
    //back
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh + Bt, -Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, -Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw, Bh, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(Bw, Bh + Bt, -Bl);
    //right
    glTexCoord2f(_min, _min);
    glVertex3f(Bw, Bh + Bt, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(Bw, Bh, Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw, Bh, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(Bw, Bh + Bt, -Bl);
    //left
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh + Bt, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(-Bw, Bh, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(-Bw, Bh + Bt, -Bl);

    glEnd();
    glPopMatrix();//2

    ///////////////top cover////////
    glPushMatrix(); //3
    glTranslatef(-1.0f, -2.0f + B3h + Btt3, 2.0f);// move up to lie above bottom cover
    glRotatef(ang3, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    // bottom
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, -Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw, Bh, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(Bw, Bh, Bl);
    //front
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh + Bt, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw, Bh, Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(Bw, Bh + Bt, Bl);
    //back
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh + Bt, -Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, -Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw, Bh, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(Bw, Bh + Bt, -Bl);
    //right
    glTexCoord2f(_min, _min);
    glVertex3f(Bw, Bh + Bt, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(Bw, Bh, Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw, Bh, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(Bw, Bh + Bt, -Bl);
    //left
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh + Bt, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(-Bw, Bh, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(-Bw, Bh + Bt, -Bl);

    glEnd();
    glPopMatrix();  //3
    ////////////////////binding//////
    glPushMatrix();//5
    glTranslatef(-1.0f, -2.0f + B3h, 2.0f);
    glRotatef(ang3, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);

    //front
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw - Bb, Bh, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(-Bw, Bh + Bt + Btt3, Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(-Bw - Bb, Bh + Bt + Btt3, Bl);
    //back
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw - Bb, Bh, -Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, -Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(-Bw, Bh + Bt + Btt3, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(-Bw - Bb, Bh + Bt + Btt3, -Bl);
    //left
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw - Bb, Bh, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw - Bb, Bh, -Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(-Bw - Bb, Bh + Bt + Btt3, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(-Bw - Bb, Bh + Bt + Btt3, Bl);
    //right
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, -Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(-Bw, Bh + Bt + Btt3, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(-Bw, Bh + Bt + Btt3, Bl);
    //top
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw - Bb, Bh + Bt + Btt3, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh + Bt + Btt3, Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(-Bw, Bh + Bt + Btt3, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(-Bw - Bb, Bh + Bt + Btt3, -Bl);
    glEnd();
    glPopMatrix();//5
}

void Scene::pgs() {
    /////////pages of book 1
    glPushMatrix(); //4
    glTranslatef(-1.0f, -2.0f + Bt, 2.0f);// move to lie between covers
    glRotatef(ang1, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glNormal3f(0, 1, 0);
    //front
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh + Btt, Bl - 0.03f);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, Bl - 0.03f);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw - 0.03f, Bh, Bl - 0.03f);
    glTexCoord2f(_min, _max);
    glVertex3f(Bw - 0.03f, Bh + Btt, Bl - 0.03f);
    //back
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh + Btt, -Bl + 0.03f);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, -Bl + 0.03f);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw - 0.03f, Bh, -Bl + 0.03f);
    glTexCoord2f(_min, _max);
    glVertex3f(Bw - 0.03f, Bh + Btt, -Bl + 0.03f);
    //right
    glTexCoord2f(_min, _min);
    glVertex3f(Bw - 0.03f, Bh + Btt, Bl - 0.03f);
    glTexCoord2f(_max, _min);
    glVertex3f(Bw - 0.03f, Bh, Bl - 0.03f);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw - 0.03f, Bh, -Bl + 0.03f);
    glTexCoord2f(_min, _max);
    glVertex3f(Bw - 0.03f, Bh + Btt, -Bl + 0.03f);

    glEnd();
    glPopMatrix();  //4

    //////////////////pages of book 2///////////////
    glPushMatrix(); //8
    glTranslatef(-1.0f, -2.0f + B2h + Bt, 2.0f);// move to lie between covers
    glRotatef(ang2, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    //front
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh + Btt, Bl - 0.03f);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, Bl - 0.03f);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw - 0.03f, Bh, Bl - 0.03f);
    glTexCoord2f(_min, _max);
    glVertex3f(Bw - 0.03f, Bh + Btt, Bl - 0.03f);
    //back
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh + Btt, -Bl + 0.03f);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, -Bl + 0.03f);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw - 0.03f, Bh, -Bl + 0.03f);
    glTexCoord2f(_min, _max);
    glVertex3f(Bw - 0.03f, Bh + Btt, -Bl + 0.03f);
    //right
    glTexCoord2f(_min, _min);
    glVertex3f(Bw - 0.03f, Bh + Btt, Bl - 0.03f);
    glTexCoord2f(_max, _min);
    glVertex3f(Bw - 0.03f, Bh, Bl - 0.03f);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw - 0.03f, Bh, -Bl + 0.03f);
    glTexCoord2f(_min, _max);
    glVertex3f(Bw - 0.03f, Bh + Btt, -Bl + 0.03f);

    glEnd();
    glPopMatrix();  //8

    ///////////////////////////////
    ///////////pages of book 3
    glPushMatrix(); //12
    glTranslatef(-1.0f, -2.0f + B3h + Bt, 2.0f);// move to lie between covers
    glRotatef(ang3, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    //front
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh + Btt3, Bl - 0.03f);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, Bl - 0.03f);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw - 0.03f, Bh, Bl - 0.03f);
    glTexCoord2f(_min, _max);
    glVertex3f(Bw - 0.03f, Bh + Btt3, Bl - 0.03f);
    //back
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh + Btt3, -Bl + 0.03f);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, -Bl + 0.03f);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw - 0.03f, Bh, -Bl + 0.03f);
    glTexCoord2f(_min, _max);
    glVertex3f(Bw - 0.03f, Bh + Btt3, -Bl + 0.03f);
    //right
    glTexCoord2f(_min, _min);
    glVertex3f(Bw - 0.03f, Bh + Btt3, Bl - 0.03f);
    glTexCoord2f(_max, _min);
    glVertex3f(Bw - 0.03f, Bh, Bl - 0.03f);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw - 0.03f, Bh, -Bl + 0.03f);
    glTexCoord2f(_min, _max);
    glVertex3f(Bw - 0.03f, Bh + Btt3, -Bl + 0.03f);

    glEnd();
    glPopMatrix();  //12
}

static void Scene::FloorShadowObj(void) {
    drawTableTop();
    firstLeg();
    secondLeg();
    thirdLeg();
    fourthLeg();
    dGlassCube();
    bk1();
    bk2();
    bk3();
    pgs();
}

static GLfloat Scene::floorVertices[4][3] = {
        { -Rs, -2.0f, Rs },
        { Rs, -2.0f, Rs },
        { Rs, -2.0f, -Rs },
        { -Rs, -2.0f, -Rs },
};


static void Scene::drawFloor(void) {
    glBegin(GL_QUADS);
    glNormal3f(0, 1, 0);
    glColor3f(0.90f, 0.90f, 0.90f);
    glVertex3fv(floorVertices[0]);
    glVertex3fv(floorVertices[1]);
    glVertex3fv(floorVertices[2]);
    glVertex3fv(floorVertices[3]);
    glEnd();
}

static GLfloat floorPlane[4];
static GLfloat floorShadow[4][4];

void Scene::drawSky() {
    glEnable(GL_TEXTURE_2D);//enabling texture

    glBindTexture(GL_TEXTURE_2D, _textureId11);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glEnable(GL_BLEND);//turns on alpha blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    glBegin(GL_QUADS);//normals pointing inwards
    glNormal3f(0, 1, 0);
    glColor4f(1, 1, 1, 0.6f);
    glTexCoord2f(0, 0);
    glVertex3f(-Rs, 8.0f, -Rs);
    glTexCoord2f(1, 0);
    glVertex3f(Rs, 8.0f, -Rs);
    glTexCoord2f(1, 1);
    glVertex3f(Rs, 8.0f, Rs);
    glTexCoord2f(0, 1);
    glVertex3f(-Rs, 8.0f, Rs);


    glEnd();
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_BLEND);

}

void Scene::drawWall() { //enclosing the walls of the room{
    drawSky();
    glEnable(GL_TEXTURE_2D);//enabling texture

    glBindTexture(GL_TEXTURE_2D, _textureId10);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBegin(GL_QUADS);//normals pointing outwards
    glNormal3f(0, 1, 0);


    ////left
    glTexCoord2f(0, 0);
    glVertex3f(-Rs - wll, -2.0f, -Rs);
    glTexCoord2f(5, 0);
    glVertex3f(-Rs - wll, -2.0f, Rs);
    glTexCoord2f(5, 5);
    glVertex3f(-Rs - wll, 8.0f, Rs);
    glTexCoord2f(0, 5);
    glVertex3f(-Rs - wll, 8.0f, -Rs);
    ////right
    glTexCoord2f(0, 0);
    glVertex3f(Rs + wll, -2.0f, Rs);
    glTexCoord2f(5, 0);
    glVertex3f(Rs + wll, -2.0f, -Rs);
    glTexCoord2f(5, 5);
    glVertex3f(Rs + wll, 8.0f, -Rs);
    glTexCoord2f(0, 5);
    glVertex3f(Rs + wll, 8.0f, Rs);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void Scene::drawWallM() { // enclosing the walls of the room
    glEnable(GL_TEXTURE_2D);//enabling texture

    glBindTexture(GL_TEXTURE_2D, _textureId10);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBegin(GL_QUADS); // normals pointing outwards
    glNormal3f(0, 1, 0);
    ////left
    glTexCoord2f(0, 0);
    glVertex3f(-Rs - wll, -2.0f, -Rs);
    glTexCoord2f(5, 0);
    glVertex3f(-Rs - wll, -2.0f, Rs);
    glTexCoord2f(5, 5);
    glVertex3f(-Rs - wll, 8.0f, Rs);
    glTexCoord2f(0, 5);
    glVertex3f(-Rs - wll, 8.0f, -Rs);
    ////right
    glTexCoord2f(0, 0);
    glVertex3f(Rs + wll, -2.0f, Rs);
    glTexCoord2f(5, 0);
    glVertex3f(Rs + wll, -2.0f, -Rs);
    glTexCoord2f(5, 5);
    glVertex3f(Rs + wll, 8.0f, -Rs);
    glTexCoord2f(0, 5);
    glVertex3f(Rs + wll, 8.0f, Rs);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void Scene::glasscube() {
    glEnable(GL_TEXTURE_2D);//enabling texture

    glBindTexture(GL_TEXTURE_2D, _textureId1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glEnable(GL_BLEND);//turns on alpha blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glColor4f(1.0f, 1.0f, 1.0f, 0.5f);
    dGlassCube();
    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);

}

void Scene::drawTable() {
    glEnable(GL_TEXTURE_2D);//enabling texture

    glBindTexture(GL_TEXTURE_2D, _textureId3);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    drawTableTop();
    firstLeg();
    secondLeg();
    thirdLeg();
    fourthLeg();

    glDisable(GL_TEXTURE_2D);
}

void book1() {
    glEnable(GL_TEXTURE_2D);//enabling texture

    glBindTexture(GL_TEXTURE_2D, _textureId9);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    bk1();

    glDisable(GL_TEXTURE_2D);
}
void book1top()
{
    glEnable(GL_TEXTURE_2D);//enabling texture

    glBindTexture(GL_TEXTURE_2D, _textureId8);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);


    glPushMatrix(); //3
    glTranslatef(-1.0f, -2.0f + Btt, 2.0f);// move up to lie above bottom cover
    glRotatef(ang1, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);

    //Top
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh + Bt, Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(-Bw, Bh + Bt, -Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw, Bh + Bt, -Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(Bw, Bh + Bt, Bl);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void book2() {
    glEnable(GL_TEXTURE_2D);//enabling texture

    glBindTexture(GL_TEXTURE_2D, _textureId5);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    bk2();

    glDisable(GL_TEXTURE_2D);
}

void book2top() {
    glEnable(GL_TEXTURE_2D);//enabling texture

    glBindTexture(GL_TEXTURE_2D, _textureId4);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    glPushMatrix(); //3
    glTranslatef(-1.0f, -2.0f + B2h + Btt, 2.0f);// move up to lie above bottom cover
    glRotatef(ang2, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);

    //Top
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh + Bt, Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(-Bw, Bh + Bt, -Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw, Bh + Bt, -Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(Bw, Bh + Bt, Bl);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void book3() {
    glEnable(GL_TEXTURE_2D);//enabling texture

    glBindTexture(GL_TEXTURE_2D, _textureId7);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    bk3();

    glDisable(GL_TEXTURE_2D);
}

void book3top() {
    glEnable(GL_TEXTURE_2D);//enabling texture

    glBindTexture(GL_TEXTURE_2D, _textureId6);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    glPushMatrix(); //3
    glTranslatef(-1.0f, -2.0f + B3h + Btt3, 2.0f);// move up to lie above bottom cover
    glRotatef(ang3, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);

    //Top
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh + Bt, Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(-Bw, Bh + Bt, -Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw, Bh + Bt, -Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(Bw, Bh + Bt, Bl);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void pages() { //textures must be added
    glEnable(GL_TEXTURE_2D); //enabling texture

    glBindTexture(GL_TEXTURE_2D, _textureId2);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    pgs();
    glDisable(GL_TEXTURE_2D);
}
