#include "items.h"

// ���캯��
Scene::Scene() {
    Rs = 15.0f; // ����Ĵ�С
    Tw = 2.0f;  // ���Ӷ����Ŀ�ȣ������Ŀ�ʼ��
    Tl = 4.0f;  // ���Ӷ����ĳ��ȣ������Ŀ�ʼ��
    Th = 1.7f;  // ���Ӷ����ĸ߶ȣ������Ŀ�ʼ��
    Tt = 0.3f;  // ���Ӷ����ĺ��
    Ls = 0.3f;  // �����ȵĴ�С

    Bw = 2.0f / 3.0f; // �鱾�Ŀ�ȣ������Ŀ�ʼ��
    Bl = 4.0f / 3.0f; // �鱾�ĳ��ȣ������Ŀ�ʼ��
    Bh = 2.0f;        // �鱾�ĸ߶ȣ������Ŀ�ʼ��
    Bt = 0.025f;      // �鱾����ĺ��
    Btt = 0.1f;       // �鱾1��2�ĺ��
    Btt3 = 0.13f;     // �鱾3�ĺ��
    Bb = 0.03f;       // �鱾װ���ĺ��
    ang1 = 5.0f;      // �鱾1����ת�Ƕ�
    B2h = Bt + Btt;   // �鱾2�ĸ߶�
    B3h = 2 * B2h;    // �鱾3�ĸ߶�
    ang2 = 30.0f;     // �鱾2����ת�Ƕ�
    ang3 = 190.0f;    // �鱾3����ת�Ƕ�

    a = 0.0f;         // �������λ��
    b = 0.0f;
    c = 0.0f;
    d = 1.5f;         // ������Ĵ�С
    _min = 0.0f;
    _max = 1.0f;
    wll = 0.01f;
}

// ��������
Scene::~Scene() {}

// �������Ӷ���
void Scene::drawTableTop() {
    glPushMatrix();
    glTranslatef(0.0f, -2.0f, 0.0f);

    glBegin(GL_QUADS);
    // �ײ�
    glTexCoord2f(_min, _min);
    glVertex3f(-Tw, Th, Tl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Tw, Th, -Tl);
    glTexCoord2f(_max, _max);
    glVertex3f(Tw, Th, -Tl);
    glTexCoord2f(_min, _max);
    glVertex3f(Tw, Th, Tl);
    // ����
    glTexCoord2f(_min, _min);
    glVertex3f(-Tw, Th + Tt, Tl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Tw, Th, Tl);
    glTexCoord2f(_max, _max);
    glVertex3f(Tw, Th, Tl);
    glTexCoord2f(_min, _max);
    glVertex3f(Tw, Th + Tt, Tl);
    // ����
    glTexCoord2f(_min, _min);
    glVertex3f(Tw, Th + Tt, -Tl);
    glTexCoord2f(_max, _min);
    glVertex3f(Tw, Th, -Tl);
    glTexCoord2f(_max, _max);
    glVertex3f(-Tw, Th, -Tl);
    glTexCoord2f(_min, _max);
    glVertex3f(-Tw, Th + Tt, -Tl);
    // �Ҳ�
    glTexCoord2f(_min, _min);
    glVertex3f(Tw, Th + Tt, Tl);
    glTexCoord2f(_max, _min);
    glVertex3f(Tw, Th, Tl);
    glTexCoord2f(_max, _max);
    glVertex3f(Tw, Th, -Tl);
    glTexCoord2f(_min, _max);
    glVertex3f(Tw, Th + Tt, -Tl);
    // ���
    glTexCoord2f(_max, _max);
    glVertex3f(-Tw, Th + Tt, Tl);
    glTexCoord2f(_min, _max);
    glVertex3f(-Tw, Th + Tt, -Tl);
    glTexCoord2f(_min, _min);
    glVertex3f(-Tw, Th, -Tl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Tw, Th, Tl);
    // ����
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

// ���Ƶ�һ������
void Scene::firstLeg() {
    glPushMatrix();
    glTranslatef(0.0f, -2.0f, 0.0f);

    glBegin(GL_QUADS);
    // ǰ��
    glNormal3f(0, 0, 1);
    glTexCoord2f(_min, _min);
    glVertex3f(-Tw + Ls, Th, Tl - Ls);
    glTexCoord2f(_max, _min);
    glVertex3f(-Tw + Ls, 0.0f, Tl - Ls);
    glTexCoord2f(_max, _max);
    glVertex3f(-Tw + Ls + Ls, 0.0f, Tl - Ls);
    glTexCoord2f(_min, _max);
    glVertex3f(-Tw + Ls + Ls, Th, Tl - Ls);
    // ����
    glNormal3f(0, 0, -1);
    glTexCoord2f(1, 1);
    glVertex3f(-Tw + Ls, Th, Tl - Ls - Ls);
    glTexCoord2f(0, 1);
    glVertex3f(-Tw + Ls + Ls, Th, Tl - Ls - Ls);
    glTexCoord2f(0, 0);
    glVertex3f(-Tw + Ls + Ls, 0.0f, Tl - Ls - Ls);
    glTexCoord2f(1, 0);
    glVertex3f(-Tw + Ls, 0.0f, Tl - Ls - Ls);
    // �Ҳ�
    glNormal3f(1, 0, 0);
    glTexCoord2f(0, 1);
    glVertex3f(-Tw + Ls + Ls, Th, Tl - Ls);
    glTexCoord2f(0, 0);
    glVertex3f(-Tw + Ls + Ls, 0.0f, Tl - Ls);
    glTexCoord2f(1, 0);
    glVertex3f(-Tw + Ls + Ls, 0.0f, Tl - Ls - Ls);
    glTexCoord2f(1, 1);
    glVertex3f(-Tw + Ls + Ls, Th, Tl - Ls - Ls);
    // ���
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

// ���Ƶڶ�������
void Scene::secondLeg() {
    glPushMatrix();
    glTranslatef(0.0f, -2.0f, 0.0f);

    glBegin(GL_QUADS);
    // ǰ��
    glNormal3f(0, 0, 1);
    glTexCoord2f(1, 1);
    glVertex3f(Tw - Ls, Th, Tl - Ls);
    glTexCoord2f(0, 1);
    glVertex3f(Tw - Ls - Ls, Th, Tl - Ls);
    glTexCoord2f(0, 0);
    glVertex3f(Tw - Ls - Ls, 0.0f, Tl - Ls);
    glTexCoord2f(1, 0);
    glVertex3f(Tw - Ls, 0.0f, Tl - Ls);
    // ����
    glNormal3f(0, 0, -1);
    glTexCoord2f(0, 1);
    glVertex3f(Tw - Ls, Th, Tl - Ls - Ls);
    glTexCoord2f(0, 0);
    glVertex3f(Tw - Ls, 0.0f, Tl - Ls - Ls);
    glTexCoord2f(1, 0);
    glVertex3f(Tw - Ls - Ls, 0.0f, Tl - Ls - Ls);
    glTexCoord2f(1, 1);
    glVertex3f(Tw - Ls - Ls, Th, Tl - Ls - Ls);
    // ���
    glNormal3f(-1, 0, 0);
    glTexCoord2f(1, 1);
    glVertex3f(Tw - Ls - Ls, Th, Tl - Ls);
    glTexCoord2f(0, 1);
    glVertex3f(Tw - Ls - Ls, Th, Tl - Ls - Ls);
    glTexCoord2f(0, 0);
    glVertex3f(Tw - Ls - Ls, 0.0f, Tl - Ls - Ls);
    glTexCoord2f(1, 0);
    glVertex3f(Tw - Ls - Ls, 0.0f, Tl - Ls);
    // �Ҳ�
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

// ���Ƶ���������
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

// ���Ƶ���������
void Scene::fourthLeg() {
    glPushMatrix();
    glTranslatef(0.0f, -2.0f, 0.0f);

    glBegin(GL_QUADS);
    // ǰ��
    glNormal3f(0, 0, 1);
    glTexCoord2f(1, 1);
    glVertex3f(Tw - Ls, Th, -Tl + Ls);
    glTexCoord2f(0, 1);
    glVertex3f(Tw - Ls - Ls, Th, -Tl + Ls);
    glTexCoord2f(0, 0);
    glVertex3f(Tw - Ls - Ls, 0.0f, -Tl + Ls);
    glTexCoord2f(1, 0);
    glVertex3f(Tw - Ls, 0.0f, -Tl + Ls);
    // ����
    glNormal3f(0, 0, -1);
    glTexCoord2f(0, 1);
    glVertex3f(Tw - Ls, Th, -Tl + Ls + Ls);
    glTexCoord2f(0, 0);
    glVertex3f(Tw - Ls, 0.0f, -Tl + Ls + Ls);
    glTexCoord2f(1, 0);
    glVertex3f(Tw - Ls - Ls, 0.0f, -Tl + Ls + Ls);
    glTexCoord2f(1, 1);
    glVertex3f(Tw - Ls - Ls, Th, -Tl + Ls + Ls);
    // ���
    glNormal3f(-1, 0, 0);
    glTexCoord2f(1, 1);
    glVertex3f(Tw - Ls - Ls, Th, -Tl + Ls);
    glTexCoord2f(0, 1);
    glVertex3f(Tw - Ls - Ls, Th, -Tl + Ls + Ls);
    glTexCoord2f(0, 0);
    glVertex3f(Tw - Ls - Ls, 0.0f, -Tl + Ls + Ls);
    glTexCoord2f(1, 0);
    glVertex3f(Tw - Ls - Ls, 0.0f, -Tl + Ls);
    // �Ҳ�
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

// ���Ʋ���������
void Scene::dGlassCube() {
    glPushMatrix();
    glTranslatef(0.3f, 0.0f, -2.3f);

    glBegin(GL_QUADS);
    // ǰ��
    glTexCoord2f(0, 0);
    glVertex3f(a, b, c);
    glTexCoord2f(1, 0);
    glVertex3f(a + d, b, c);
    glTexCoord2f(1, 1);
    glVertex3f(a + d, b + d, c);
    glTexCoord2f(0, 1);
    glVertex3f(a, b + d, c);
    // �Ҳ�
    glTexCoord2f(_min, _min);
    glVertex3f(a + d, b, c);
    glTexCoord2f(_max, _min);
    glVertex3f(a + d, b, c - d);
    glTexCoord2f(_max, _max);
    glVertex3f(a + d, b + d, c - d);
    glTexCoord2f(_min, _max);
    glVertex3f(a + d, b + d, c);
    // ����
    glTexCoord2f(_min, _min);
    glVertex3f(a + d, b, c - d);
    glTexCoord2f(_max, _min);
    glVertex3f(a, b, c - d);
    glTexCoord2f(_max, _max);
    glVertex3f(a, b + d, c - d);
    glTexCoord2f(_min, _max);
    glVertex3f(a + d, b + d, c - d);
    // ���
    glTexCoord2f(_min, _min);
    glVertex3f(a, b, c - d);
    glTexCoord2f(_max, _min);
    glVertex3f(a, b, c);
    glTexCoord2f(_max, _max);
    glVertex3f(a, b + d, c);
    glTexCoord2f(_min, _max);
    glVertex3f(a, b + d, c - d);
    // ����
    glTexCoord2f(_min, _min);
    glVertex3f(a, b + d, c);
    glTexCoord2f(_max, _min);
    glVertex3f(a + d, b + d, c);
    glTexCoord2f(_max, _max);
    glVertex3f(a + d, b + d, c - d);
    glTexCoord2f(_min, _max);
    glVertex3f(a, b + d, c - d);
    // �ײ�
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

// �����鱾1
void Scene::bk1() {
    glPushMatrix();
    glTranslatef(-1.0f, -2.0f, 2.0f);
    glRotatef(ang1, 0.0f, 1.0f, 0.0f);

    glBegin(GL_QUADS);
    glNormal3f(0, 1, 0);
    // �ײ�����
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, -Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw, Bh, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(Bw, Bh, Bl);
    // ��������
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh + Bt, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh + Bt, -Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw, Bh + Bt, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(Bw, Bh + Bt, Bl);
    // ǰ��
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh + Bt, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw, Bh, Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(Bw, Bh + Bt, Bl);
    // ����
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh + Bt, -Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, -Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw, Bh, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(Bw, Bh + Bt, -Bl);
    // �Ҳ�
    glTexCoord2f(_min, _min);
    glVertex3f(Bw, Bh + Bt, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(Bw, Bh, Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(Bw, Bh, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(Bw, Bh + Bt, -Bl);
    // ���
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

    // ��������
    glPushMatrix();
    glTranslatef(-1.0f, -2.0f + Btt, 2.0f);
    glRotatef(ang1, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    // ����
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

    // װ��
    glPushMatrix();
    glTranslatef(-1.0f, -2.0f, 2.0f);
    glRotatef(ang1, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    // ǰ��
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw - Bb, Bh, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(-Bw, Bh + Bt + Btt, Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(-Bw - Bb, Bh + Bt + Btt, Bl);
    // ����
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw - Bb, Bh, -Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, -Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(-Bw, Bh + Bt + Btt, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(-Bw - Bb, Bh + Bt + Btt, -Bl);
    // ���
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw - Bb, Bh, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw - Bb, Bh, -Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(-Bw - Bb, Bh + Bt + Btt, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(-Bw - Bb, Bh + Bt + Btt, Bl);
    // �Ҳ�
    glTexCoord2f(_min, _min);
    glVertex3f(-Bw, Bh, Bl);
    glTexCoord2f(_max, _min);
    glVertex3f(-Bw, Bh, -Bl);
    glTexCoord2f(_max, _max);
    glVertex3f(-Bw, Bh + Bt + Btt, -Bl);
    glTexCoord2f(_min, _max);
    glVertex3f(-Bw, Bh + Bt + Btt, Bl);
    // ����
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
