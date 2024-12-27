#include "Texture.h"

// ���巿�䡢���ӡ��鱾������ĳߴ��λ�ò���
float roomSize = 15.0f;  // ����Ĵ�С
float tableWidth = 2.0f;   // ���Ӷ��������ĵ���Ե�Ŀ��
float tableLength = 4.0f;   // ���Ӷ��������ĵ���Ե�ĳ���
float tableHeight = 1.7f;   // ���Ӷ��������ĵ���Ե�ĸ߶�
float tableThickness = 0.3f;   // ���Ӷ����ĺ��
float legSize = 0.3f;   // �����ȵĳߴ�

float bookWidth = 2.0f / 3.0f;  // �鱾�����ĵ���Ե�Ŀ��
float bookLength = 4.0f / 3.0f;  // �鱾�����ĵ���Ե�ĳ���
float bookHeight = 2.0f;         // �鱾�����ĵ���Ե�ĸ߶�
float bookThickness = 0.025f;       // �鱾����ĺ��
float book12Thickness = 0.1f;        // �鱾1��2�ĺ��
float book3Thickness = 0.13f;      // �鱾3�ĺ��
float bookB = 0.03f;        // �鱾װ���ĺ��
float ang1 = 5.0f;       // �鱾1����ת�Ƕ�
float book2Height = bookThickness + book12Thickness;    // �鱾2�ĸ߶�
float book3Height = 2 * book2Height;     // �鱾3�ĸ߶�
float ang2 = 30.0f;      // �鱾2����ת�Ƕ�
float ang3 = 190.0f;     // �鱾3����ת�Ƕ�

float a = 0.0f;  // �������λ��
float b = 0.0f;
float c = 0.0f;
float d = 1.5f;  // ������Ĵ�С
float _min = 0.0f;  // �����������Сֵ
float _max = 1.0f;  // ������������ֵ
float wll = 0.01f;  // ǽ�ڵĺ��

void drawTableTop() {
    glPushMatrix(); // ���浱ǰ����״̬
    glTranslatef(0.0f, -2.0f, 0.0f); // �����Ӷ����ƶ����ذ���

    glBegin(GL_QUADS);  // ��ʼ�����ı���
    // �ײ������߳���
    glTexCoord2f(_min, _min);
    glVertex3f(-tableWidth, tableHeight, tableLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-tableWidth, tableHeight, -tableLength);
    glTexCoord2f(_max, _max);
    glVertex3f(tableWidth, tableHeight, -tableLength);
    glTexCoord2f(_min, _max);
    glVertex3f(tableWidth, tableHeight, tableLength);

    // ǰ�������߳���
    glTexCoord2f(_min, _min);
    glVertex3f(-tableWidth, tableHeight + tableThickness, tableLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-tableWidth, tableHeight, tableLength);
    glTexCoord2f(_max, _max);
    glVertex3f(tableWidth, tableHeight, tableLength);
    glTexCoord2f(_min, _max);
    glVertex3f(tableWidth, tableHeight + tableThickness, tableLength);

    // �󲿣����߳���
    glTexCoord2f(_min, _min);
    glVertex3f(tableWidth, tableHeight + tableThickness, -tableLength);
    glTexCoord2f(_max, _min);
    glVertex3f(tableWidth, tableHeight, -tableLength);
    glTexCoord2f(_max, _max);
    glVertex3f(-tableWidth, tableHeight, -tableLength);
    glTexCoord2f(_min, _max);
    glVertex3f(-tableWidth, tableHeight + tableThickness, -tableLength);

    // �Ҳ������߳���
    glTexCoord2f(_min, _min);
    glVertex3f(tableWidth, tableHeight + tableThickness, tableLength);
    glTexCoord2f(_max, _min);
    glVertex3f(tableWidth, tableHeight, tableLength);
    glTexCoord2f(_max, _max);
    glVertex3f(tableWidth, tableHeight, -tableLength);
    glTexCoord2f(_min, _max);
    glVertex3f(tableWidth, tableHeight + tableThickness, -tableLength);

    // �󲿣����߳���
    glTexCoord2f(_max, _max);
    glVertex3f(-tableWidth, tableHeight + tableThickness, tableLength);
    glTexCoord2f(_min, _max);
    glVertex3f(-tableWidth, tableHeight + tableThickness, -tableLength);
    glTexCoord2f(_min, _min);
    glVertex3f(-tableWidth, tableHeight, -tableLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-tableWidth, tableHeight, tableLength);

    // ���������߳���
    glTexCoord2f(_min, _min);
    glVertex3f(-tableWidth, tableHeight + tableThickness, tableLength);
    glTexCoord2f(_min, _max);
    glVertex3f(tableWidth, tableHeight + tableThickness, tableLength);
    glTexCoord2f(_max, _max);
    glVertex3f(tableWidth, tableHeight + tableThickness, -tableLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-tableWidth, tableHeight + tableThickness, -tableLength);
    glEnd();  // ��������
    glPopMatrix();  // �ָ�����״̬
}


// ���Ƶ�һ��������
void firstLeg() {
    glPushMatrix();  // ���浱ǰ����״̬
    glTranslatef(0.0f, -2.0f, 0.0f);  // ���������ƶ����ذ���

    glBegin(GL_QUADS);  // ��ʼ�����ı���
    // ǰ�������߳���
    glNormal3f(0, 0, 1);
    glTexCoord2f(_min, _min);
    glVertex3f(-tableWidth + legSize, tableHeight, tableLength - legSize);
    glTexCoord2f(_max, _min);
    glVertex3f(-tableWidth + legSize, 0.0f, tableLength - legSize);
    glTexCoord2f(_max, _max);
    glVertex3f(-tableWidth + legSize + legSize, 0.0f, tableLength - legSize);
    glTexCoord2f(_min, _max);
    glVertex3f(-tableWidth + legSize + legSize, tableHeight, tableLength - legSize);

    // �󲿣����߳���
    glNormal3f(0, 0, -1);
    glTexCoord2f(1, 1);
    glVertex3f(-tableWidth + legSize, tableHeight, tableLength - legSize - legSize);
    glTexCoord2f(0, 1);
    glVertex3f(-tableWidth + legSize + legSize, tableHeight, tableLength - legSize - legSize);
    glTexCoord2f(0, 0);
    glVertex3f(-tableWidth + legSize + legSize, 0.0f, tableLength - legSize - legSize);
    glTexCoord2f(1, 0);
    glVertex3f(-tableWidth + legSize, 0.0f, tableLength - legSize - legSize);

    // �Ҳ������߳���
    glNormal3f(1, 0, 0);
    glTexCoord2f(0, 1);
    glVertex3f(-tableWidth + legSize + legSize, tableHeight, tableLength - legSize);
    glTexCoord2f(0, 0);
    glVertex3f(-tableWidth + legSize + legSize, 0.0f, tableLength - legSize);
    glTexCoord2f(1, 0);
    glVertex3f(-tableWidth + legSize + legSize, 0.0f, tableLength - legSize - legSize);
    glTexCoord2f(1, 1);
    glVertex3f(-tableWidth + legSize + legSize, tableHeight, tableLength - legSize - legSize);

    // �󲿣����߳���
    glNormal3f(-1, 0, 0);
    glTexCoord2f(1, 1);
    glVertex3f(-tableWidth + legSize, tableHeight, tableLength - legSize);
    glTexCoord2f(0, 1);
    glVertex3f(-tableWidth + legSize, tableHeight, tableLength - legSize - legSize);
    glTexCoord2f(0, 0);
    glVertex3f(-tableWidth + legSize, 0.0f, tableLength - legSize - legSize);
    glTexCoord2f(1, 0);
    glVertex3f(-tableWidth + legSize, 0.0f, tableLength - legSize);
    glEnd();  // ��������
    glPopMatrix();  // �ָ�����״̬
}


// ���Ƶڶ���������
void secondLeg() {
    glPushMatrix();  // ���浱ǰ����״̬
    glTranslatef(0.0f, -2.0f, 0.0f);  // ���������ƶ����ذ���

    glBegin(GL_QUADS);  // ��ʼ�����ı���
    // ǰ�������߳���
    glNormal3f(0, 0, 1);
    glTexCoord2f(1, 1);
    glVertex3f(tableWidth - legSize, tableHeight, tableLength - legSize);
    glTexCoord2f(0, 1);
    glVertex3f(tableWidth - legSize - legSize, tableHeight, tableLength - legSize);
    glTexCoord2f(0, 0);
    glVertex3f(tableWidth - legSize - legSize, 0.0f, tableLength - legSize);
    glTexCoord2f(1, 0);
    glVertex3f(tableWidth - legSize, 0.0f, tableLength - legSize);

    // �󲿣����߳���
    glNormal3f(0, 0, -1);
    glTexCoord2f(0, 1);
    glVertex3f(tableWidth - legSize, tableHeight, tableLength - legSize - legSize);
    glTexCoord2f(0, 0);
    glVertex3f(tableWidth - legSize, 0.0f, tableLength - legSize - legSize);
    glTexCoord2f(1, 0);
    glVertex3f(tableWidth - legSize - legSize, 0.0f, tableLength - legSize - legSize);
    glTexCoord2f(1, 1);
    glVertex3f(tableWidth - legSize - legSize, tableHeight, tableLength - legSize - legSize);

    // �󲿣����߳���
    glNormal3f(-1, 0, 0);
    glTexCoord2f(1, 1);
    glVertex3f(tableWidth - legSize - legSize, tableHeight, tableLength - legSize);
    glTexCoord2f(0, 1);
    glVertex3f(tableWidth - legSize - legSize, tableHeight, tableLength - legSize - legSize);
    glTexCoord2f(0, 0);
    glVertex3f(tableWidth - legSize - legSize, 0.0f, tableLength - legSize - legSize);
    glTexCoord2f(1, 0);
    glVertex3f(tableWidth - legSize - legSize, 0.0f, tableLength - legSize);

    // �Ҳ������߳���
    glNormal3f(1, 0, 0);
    glTexCoord2f(0, 1);
    glVertex3f(tableWidth - legSize, tableHeight, tableLength - legSize);
    glTexCoord2f(0, 0);
    glVertex3f(tableWidth - legSize, 0.0f, tableLength - legSize);
    glTexCoord2f(1, 0);
    glVertex3f(tableWidth - legSize, 0.0f, tableLength - legSize - legSize);
    glTexCoord2f(1, 1);
    glVertex3f(tableWidth - legSize, tableHeight, tableLength - legSize - legSize);
    glEnd();  // ��������
    glPopMatrix();  // �ָ�����״̬
}

// ���Ƶ�����������
void thirdLeg() {
    glPushMatrix();  // ���浱ǰ����״̬
    glTranslatef(0.0f, -2.0f, 0.0f);  // ���������ƶ����ذ���

    glBegin(GL_QUADS);  // ��ʼ�����ı���
    // ǰ�������߳���
    glNormal3f(0, 0, 1);
    glTexCoord2f(_min, _min);
    glVertex3f(-tableWidth + legSize, tableHeight, -tableLength + legSize);
    glTexCoord2f(_max, _min);
    glVertex3f(-tableWidth + legSize, 0.0f, -tableLength + legSize);
    glTexCoord2f(_max, _max);
    glVertex3f(-tableWidth + legSize + legSize, 0.0f, -tableLength + legSize);
    glTexCoord2f(_min, _max);
    glVertex3f(-tableWidth + legSize + legSize, tableHeight, -tableLength + legSize);

    // �󲿣����߳���
    glNormal3f(0, 0, -1);
    glTexCoord2f(1, 1);
    glVertex3f(-tableWidth + legSize, tableHeight, -tableLength + legSize + legSize);
    glTexCoord2f(0, 1);
    glVertex3f(-tableWidth + legSize + legSize, tableHeight, -tableLength + legSize + legSize);
    glTexCoord2f(0, 0);
    glVertex3f(-tableWidth + legSize + legSize, 0.0f, -tableLength + legSize + legSize);
    glTexCoord2f(1, 0);
    glVertex3f(-tableWidth + legSize, 0.0f, -tableLength + legSize + legSize);

    // �Ҳ������߳���
    glNormal3f(1, 0, 0);
    glTexCoord2f(0, 1);
    glVertex3f(-tableWidth + legSize + legSize, tableHeight, -tableLength + legSize);
    glTexCoord2f(0, 0);
    glVertex3f(-tableWidth + legSize + legSize, 0.0f, -tableLength + legSize);
    glTexCoord2f(1, 0);
    glVertex3f(-tableWidth + legSize + legSize, 0.0f, -tableLength + legSize + legSize);
    glTexCoord2f(1, 1);
    glVertex3f(-tableWidth + legSize + legSize, tableHeight, -tableLength + legSize + legSize);

    // �󲿣����߳���
    glNormal3f(-1, 0, 0);
    glTexCoord2f(1, 1);
    glVertex3f(-tableWidth + legSize, tableHeight, -tableLength + legSize);
    glTexCoord2f(0, 1);
    glVertex3f(-tableWidth + legSize, tableHeight, -tableLength + legSize + legSize);
    glTexCoord2f(0, 0);
    glVertex3f(-tableWidth + legSize, 0.0f, -tableLength + legSize + legSize);
    glTexCoord2f(1, 0);
    glVertex3f(-tableWidth + legSize, 0.0f, -tableLength + legSize);
    glEnd();  // ��������
    glPopMatrix();  // �ָ�����״̬
}


// ���Ƶ�����������
void fourthLeg() {
    glPushMatrix();  // ���浱ǰ����״̬
    glTranslatef(0.0f, -2.0f, 0.0f);  // ���������ƶ����ذ���

    glBegin(GL_QUADS);  // ��ʼ�����ı���
    // ǰ�������߳���
    glNormal3f(0, 0, 1);
    glTexCoord2f(1, 1);
    glVertex3f(tableWidth - legSize, tableHeight, -tableLength + legSize);
    glTexCoord2f(0, 1);
    glVertex3f(tableWidth - legSize - legSize, tableHeight, -tableLength + legSize);
    glTexCoord2f(0, 0);
    glVertex3f(tableWidth - legSize - legSize, 0.0f, -tableLength + legSize);
    glTexCoord2f(1, 0);
    glVertex3f(tableWidth - legSize, 0.0f, -tableLength + legSize);

    // �󲿣����߳���
    glNormal3f(0, 0, -1);
    glTexCoord2f(0, 1);
    glVertex3f(tableWidth - legSize, tableHeight, -tableLength + legSize + legSize);
    glTexCoord2f(0, 0);
    glVertex3f(tableWidth - legSize, 0.0f, -tableLength + legSize + legSize);
    glTexCoord2f(1, 0);
    glVertex3f(tableWidth - legSize - legSize, 0.0f, -tableLength + legSize + legSize);
    glTexCoord2f(1, 1);
    glVertex3f(tableWidth - legSize - legSize, tableHeight, -tableLength + legSize + legSize);

    // �󲿣����߳���
    glNormal3f(-1, 0, 0);
    glTexCoord2f(1, 1);
    glVertex3f(tableWidth - legSize - legSize, tableHeight, -tableLength + legSize);
    glTexCoord2f(0, 1);
    glVertex3f(tableWidth - legSize - legSize, tableHeight, -tableLength + legSize + legSize);
    glTexCoord2f(0, 0);
    glVertex3f(tableWidth - legSize - legSize, 0.0f, -tableLength + legSize + legSize);
    glTexCoord2f(1, 0);
    glVertex3f(tableWidth - legSize - legSize, 0.0f, -tableLength + legSize);

    // �Ҳ������߳���
    glNormal3f(1, 0, 0);
    glTexCoord2f(0, 1);
    glVertex3f(tableWidth - legSize, tableHeight, -tableLength + legSize);
    glTexCoord2f(0, 0);
    glVertex3f(tableWidth - legSize, 0.0f, -tableLength + legSize);
    glTexCoord2f(1, 0);
    glVertex3f(tableWidth - legSize, 0.0f, -tableLength + legSize + legSize);
    glTexCoord2f(1, 1);
    glVertex3f(tableWidth - legSize, tableHeight, -tableLength + legSize + legSize);
    glEnd();  // ��������
    glPopMatrix();  // �ָ�����״̬
}

// ���Ʋ���������
void dGlassCube() {
    glPushMatrix();

    glTranslatef(0.3f, 0.0f, -2.3f);
    glBegin(GL_QUADS); 
    
    glTexCoord2f(0, 0);
    glVertex3f(a, b, c);
    glTexCoord2f(1, 0);
    glVertex3f(a + d, b, c);
    glTexCoord2f(1, 1);
    glVertex3f(a + d, b + d, c);
    glTexCoord2f(0, 1);
    glVertex3f(a, b + d, c);

   
    glTexCoord2f(_min, _min);
    glVertex3f(a + d, b, c);
    glTexCoord2f(_max, _min);
    glVertex3f(a + d, b, c - d);
    glTexCoord2f(_max, _max);
    glVertex3f(a + d, b + d, c - d);
    glTexCoord2f(_min, _max);
    glVertex3f(a + d, b + d, c);
  
    glTexCoord2f(_min, _min);
    glVertex3f(a + d, b, c - d);
    glTexCoord2f(_max, _min);
    glVertex3f(a, b, c - d);
    glTexCoord2f(_max, _max);
    glVertex3f(a, b + d, c - d);
    glTexCoord2f(_min, _max);
    glVertex3f(a + d, b + d, c - d);
  
    glTexCoord2f(_min, _min);
    glVertex3f(a, b, c - d);
    glTexCoord2f(_max, _min);
    glVertex3f(a, b, c);
    glTexCoord2f(_max, _max);
    glVertex3f(a, b + d, c);
    glTexCoord2f(_min, _max);
    glVertex3f(a, b + d, c - d);
 
    glTexCoord2f(_min, _min);
    glVertex3f(a, b + d, c);
    glTexCoord2f(_max, _min);
    glVertex3f(a + d, b + d, c);
    glTexCoord2f(_max, _max);
    glVertex3f(a + d, b + d, c - d);
    glTexCoord2f(_min, _max);
    glVertex3f(a, b + d, c - d);
   
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

void bk1() {
    glPushMatrix(); // 2
    glTranslatef(-1.0f, -2.0f, 2.0f); // move to lie on the left corner of the table
    glRotatef(ang1, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glNormal3f(0, 1, 0);
    /////////////bottom cover///
    // bottom
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth, bookHeight, bookLength);
    // top
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + bookThickness, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight + bookThickness, -bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth, bookHeight + bookThickness, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth, bookHeight + bookThickness, bookLength);
    // front
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + bookThickness, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth, bookHeight, bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth, bookHeight + bookThickness, bookLength);
    // back
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + bookThickness, -bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth, bookHeight + bookThickness, -bookLength);
    // right
    glTexCoord2f(_min, _min);
    glVertex3f(bookWidth, bookHeight + bookThickness, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth, bookHeight + bookThickness, -bookLength);
    // left
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + bookThickness, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(-bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(-bookWidth, bookHeight + bookThickness, -bookLength);

    glEnd();
    glPopMatrix(); // 2

    ///////////////top cover////////
    glPushMatrix(); // 3
    glTranslatef(-1.0f, -2.0f + book12Thickness, 2.0f); // move up to lie above bottom cover
    glRotatef(ang1, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    // bottom
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth, bookHeight, bookLength);
    // front
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + bookThickness, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth, bookHeight, bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth, bookHeight + bookThickness, bookLength);
    // back
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + bookThickness, -bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth, bookHeight + bookThickness, -bookLength);
    // right
    glTexCoord2f(_min, _min);
    glVertex3f(bookWidth, bookHeight + bookThickness, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth, bookHeight + bookThickness, -bookLength);
    // left
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + bookThickness, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(-bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(-bookWidth, bookHeight + bookThickness, -bookLength);

    glEnd();
    glPopMatrix(); // 3
    ////////////////////binding//////
    glPushMatrix(); // 5
    glTranslatef(-1.0f, -2.0f, 2.0f);
    glRotatef(ang1, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);

    // front
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth - bookB, bookHeight, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(-bookWidth, bookHeight + bookThickness + book12Thickness, bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(-bookWidth - bookB, bookHeight + bookThickness + book12Thickness, bookLength);
    // back
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth - bookB, bookHeight, -bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(-bookWidth, bookHeight + bookThickness + book12Thickness, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(-bookWidth - bookB, bookHeight + bookThickness + book12Thickness, -bookLength);
    // left
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth - bookB, bookHeight, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth - bookB, bookHeight, -bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(-bookWidth - bookB, bookHeight + bookThickness + book12Thickness, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(-bookWidth - bookB, bookHeight + bookThickness + book12Thickness, bookLength);
    // right
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(-bookWidth, bookHeight + bookThickness + book12Thickness, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(-bookWidth, bookHeight + bookThickness + book12Thickness, bookLength);
    // top
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth - bookB, bookHeight + bookThickness + book12Thickness, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight + bookThickness + book12Thickness, bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(-bookWidth, bookHeight + bookThickness + book12Thickness, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(-bookWidth - bookB, bookHeight + bookThickness + book12Thickness, -bookLength);
    glEnd();
    glPopMatrix();//5
}

void bk2() {
    glPushMatrix(); // 2
    glTranslatef(-1.0f, -2.0f + book2Height, 2.0f); // move to lie on the left corner of the table
    glRotatef(ang2, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glNormal3f(0, 1, 0);
    /////////////bottom cover///
    // bottom
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth, bookHeight, bookLength);
    // top
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + bookThickness, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight + bookThickness, -bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth, bookHeight + bookThickness, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth, bookHeight + bookThickness, bookLength);
    // front
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + bookThickness, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth, bookHeight, bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth, bookHeight + bookThickness, bookLength);
    // back
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + bookThickness, -bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth, bookHeight + bookThickness, -bookLength);
    // right
    glTexCoord2f(_min, _min);
    glVertex3f(bookWidth, bookHeight + bookThickness, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth, bookHeight + bookThickness, -bookLength);
    // left
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + bookThickness, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(-bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(-bookWidth, bookHeight + bookThickness, -bookLength);

    glEnd();
    glPopMatrix(); 

   //����
    glPushMatrix(); 
    glTranslatef(-1.0f, -2.0f + book2Height + book12Thickness, 2.0f);
    glRotatef(ang2, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth, bookHeight, bookLength);
    // ǰ
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + bookThickness, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth, bookHeight, bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth, bookHeight + bookThickness, bookLength);
    // ��
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + bookThickness, -bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth, bookHeight + bookThickness, -bookLength);
    // ��
    glTexCoord2f(_min, _min);
    glVertex3f(bookWidth, bookHeight + bookThickness, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth, bookHeight + bookThickness, -bookLength);
    // ��
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + bookThickness, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(-bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(-bookWidth, bookHeight + bookThickness, -bookLength);

    glEnd();
    glPopMatrix(); 
    
    // ��ҳ
    glPushMatrix(); 
    glTranslatef(-1.0f, -2.0f + book2Height, 2.0f);
    glRotatef(ang2, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);

    // ǰ
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth - bookB, bookHeight, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(-bookWidth, bookHeight + bookThickness + book12Thickness, bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(-bookWidth - bookB, bookHeight + bookThickness + book12Thickness, bookLength);
    // ��
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth - bookB, bookHeight, -bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(-bookWidth, bookHeight + bookThickness + book12Thickness, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(-bookWidth - bookB, bookHeight + bookThickness + book12Thickness, -bookLength);
    // ��
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth - bookB, bookHeight, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth - bookB, bookHeight, -bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(-bookWidth - bookB, bookHeight + bookThickness + book12Thickness, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(-bookWidth - bookB, bookHeight + bookThickness + book12Thickness, bookLength);
    // ��
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(-bookWidth, bookHeight + bookThickness + book12Thickness, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(-bookWidth, bookHeight + bookThickness + book12Thickness, bookLength);
    // ��
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth - bookB, bookHeight + bookThickness + book12Thickness, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight + bookThickness + book12Thickness, bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(-bookWidth, bookHeight + bookThickness + book12Thickness, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(-bookWidth - bookB, bookHeight + bookThickness + book12Thickness, -bookLength);
    glEnd();
    glPopMatrix();
}

void bk3() {
    glPushMatrix(); 
    glTranslatef(-1.0f, -2.0f + book3Height, 2.0f); 
    glRotatef(ang3, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glNormal3f(0, 1, 0);
   
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth, bookHeight, bookLength);
    
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + bookThickness, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight + bookThickness, -bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth, bookHeight + bookThickness, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth, bookHeight + bookThickness, bookLength);
    
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + bookThickness, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth, bookHeight, bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth, bookHeight + bookThickness, bookLength);
   
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + bookThickness, -bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth, bookHeight + bookThickness, -bookLength);
   
    glTexCoord2f(_min, _min);
    glVertex3f(bookWidth, bookHeight + bookThickness, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth, bookHeight + bookThickness, -bookLength);
   
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + bookThickness, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(-bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(-bookWidth, bookHeight + bookThickness, -bookLength);

    glEnd();
    glPopMatrix();

    glPushMatrix(); 
    glTranslatef(-1.0f, -2.0f + book3Height + book3Thickness, 2.0f);
    glRotatef(ang3, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);

    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth, bookHeight, bookLength);

    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + bookThickness, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth, bookHeight, bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth, bookHeight + bookThickness, bookLength);

    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + bookThickness, -bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth, bookHeight + bookThickness, -bookLength);

    glTexCoord2f(_min, _min);
    glVertex3f(bookWidth, bookHeight + bookThickness, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth, bookHeight + bookThickness, -bookLength);

    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + bookThickness, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(-bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(-bookWidth, bookHeight + bookThickness, -bookLength);

    glEnd();
    glPopMatrix();  
    
    glPushMatrix();
    glTranslatef(-1.0f, -2.0f + book3Height, 2.0f);
    glRotatef(ang3, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);

    
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth - bookB, bookHeight, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(-bookWidth, bookHeight + bookThickness + book3Thickness, bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(-bookWidth - bookB, bookHeight + bookThickness + book3Thickness, bookLength);
    
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth - bookB, bookHeight, -bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(-bookWidth, bookHeight + bookThickness + book3Thickness, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(-bookWidth - bookB, bookHeight + bookThickness + book3Thickness, -bookLength);
    
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth - bookB, bookHeight, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth - bookB, bookHeight, -bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(-bookWidth - bookB, bookHeight + bookThickness + book3Thickness, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(-bookWidth - bookB, bookHeight + bookThickness + book3Thickness, bookLength);
    
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(-bookWidth, bookHeight + bookThickness + book3Thickness, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(-bookWidth, bookHeight + bookThickness + book3Thickness, bookLength);
    
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth - bookB, bookHeight + bookThickness + book3Thickness, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight + bookThickness + book3Thickness, bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(-bookWidth, bookHeight + bookThickness + book3Thickness, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(-bookWidth - bookB, bookHeight + bookThickness + book3Thickness, -bookLength);
    glEnd();
    glPopMatrix();
}

//������Ĳ���
void pgs() {
    
    glPushMatrix(); 
    glTranslatef(-1.0f, -2.0f + bookThickness, 2.0f);
    glRotatef(ang1, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glNormal3f(0, 1, 0);

    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + book12Thickness, bookLength - 0.03f);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, bookLength - 0.03f);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth - 0.03f, bookHeight, bookLength - 0.03f);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth - 0.03f, bookHeight + book12Thickness, bookLength - 0.03f);

    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + book12Thickness, -bookLength + 0.03f);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, -bookLength + 0.03f);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth - 0.03f, bookHeight, -bookLength + 0.03f);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth - 0.03f, bookHeight + book12Thickness, -bookLength + 0.03f);

    glTexCoord2f(_min, _min);
    glVertex3f(bookWidth - 0.03f, bookHeight + book12Thickness, bookLength - 0.03f);
    glTexCoord2f(_max, _min);
    glVertex3f(bookWidth - 0.03f, bookHeight, bookLength - 0.03f);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth - 0.03f, bookHeight, -bookLength + 0.03f);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth - 0.03f, bookHeight + book12Thickness, -bookLength + 0.03f);

    glEnd();
    glPopMatrix(); 

   
    glPushMatrix(); 
    glTranslatef(-1.0f, -2.0f + book2Height + bookThickness, 2.0f);
    glRotatef(ang2, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);

    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + book12Thickness, bookLength - 0.03f);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, bookLength - 0.03f);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth - 0.03f, bookHeight, bookLength - 0.03f);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth - 0.03f, bookHeight + book12Thickness, bookLength - 0.03f);

    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + book12Thickness, -bookLength + 0.03f);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, -bookLength + 0.03f);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth - 0.03f, bookHeight, -bookLength + 0.03f);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth - 0.03f, bookHeight + book12Thickness, -bookLength + 0.03f);

    glTexCoord2f(_min, _min);
    glVertex3f(bookWidth - 0.03f, bookHeight + book12Thickness, bookLength - 0.03f);
    glTexCoord2f(_max, _min);
    glVertex3f(bookWidth - 0.03f, bookHeight, bookLength - 0.03f);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth - 0.03f, bookHeight, -bookLength + 0.03f);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth - 0.03f, bookHeight + book12Thickness, -bookLength + 0.03f);

    glEnd();
    glPopMatrix(); 

 
    glPushMatrix();
    glTranslatef(-1.0f, -2.0f + book3Height + bookThickness, 2.0f);
    glRotatef(ang3, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + book3Thickness, bookLength - 0.03f);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, bookLength - 0.03f);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth - 0.03f, bookHeight, bookLength - 0.03f);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth - 0.03f, bookHeight + book3Thickness, bookLength - 0.03f);
   
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + book3Thickness, -bookLength + 0.03f);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, -bookLength + 0.03f);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth - 0.03f, bookHeight, -bookLength + 0.03f);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth - 0.03f, bookHeight + book3Thickness, -bookLength + 0.03f);
   
    glTexCoord2f(_min, _min);
    glVertex3f(bookWidth - 0.03f, bookHeight + book3Thickness, bookLength - 0.03f);
    glTexCoord2f(_max, _min);
    glVertex3f(bookWidth - 0.03f, bookHeight, bookLength - 0.03f);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth - 0.03f, bookHeight, -bookLength + 0.03f);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth - 0.03f, bookHeight + book3Thickness, -bookLength + 0.03f);

    glEnd();
    glPopMatrix();  
}


// ���Ƶذ���Ӱ����
static void FloorShadowObj(void) {
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

static GLfloat floorVertices[4][3] = {
        { -roomSize, -2.0f, roomSize },
        { roomSize, -2.0f, roomSize },
        { roomSize, -2.0f, -roomSize },
        { -roomSize, -2.0f, -roomSize },
};


static void drawFloor(void) {
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


void drawSky() {
    glDisable(GL_FOG); // ������Ч
    // ����2D����ӳ��
    glEnable(GL_TEXTURE_2D);

    // ���������_textureId11 ����������ID��
    glBindTexture(GL_TEXTURE_2D, _textureId11);

    // ���������������С�ͷŴ�ʱʹ�����Թ���
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // ���û�ϣ�����ʵ��͸��Ч����
    glEnable(GL_BLEND);

    // ���û�Ϻ�����Դ��ɫ����ԴAlpha��Ŀ����ɫ���ԣ�1 - ԴAlpha��
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // ��ʼ�����������6����
    glBegin(GL_QUADS);

    float skySize = 100.0f;

    // ǰ��
    glNormal3f(0, -1, 0);
    glColor4f(1, 1, 1, 0.6f);
    glTexCoord2f(0, 0); glVertex3f(-skySize, -skySize, skySize);
    glTexCoord2f(1, 0); glVertex3f(skySize, -skySize, skySize);
    glTexCoord2f(1, 1); glVertex3f(skySize, skySize, skySize);
    glTexCoord2f(0, 1); glVertex3f(-skySize, skySize, skySize);

    // ����
    
    glTexCoord2f(0, 0); glVertex3f(-skySize, -skySize, -skySize);
    glTexCoord2f(1, 0); glVertex3f(skySize, -skySize, -skySize);
    glTexCoord2f(1, 1); glVertex3f(skySize, skySize, -skySize);
    glTexCoord2f(0, 1); glVertex3f(-skySize, skySize, -skySize);

    // ����
  
    glTexCoord2f(0, 0); glVertex3f(-skySize, -skySize, -skySize);
    glTexCoord2f(1, 0); glVertex3f(-skySize, -skySize, skySize);
    glTexCoord2f(1, 1); glVertex3f(-skySize, skySize, skySize);
    glTexCoord2f(0, 1); glVertex3f(-skySize, skySize, -skySize);

    // ����

    glTexCoord2f(0, 0); glVertex3f(skySize, -skySize, -skySize);
    glTexCoord2f(1, 0); glVertex3f(skySize, -skySize, skySize);
    glTexCoord2f(1, 1); glVertex3f(skySize, skySize, skySize);
    glTexCoord2f(0, 1); glVertex3f(skySize, skySize, -skySize);

    // ����
   
    glTexCoord2f(0, 0); glVertex3f(-skySize, skySize, -skySize);
    glTexCoord2f(1, 0); glVertex3f(skySize, skySize, -skySize);
    glTexCoord2f(1, 1); glVertex3f(skySize, skySize, skySize);
    glTexCoord2f(0, 1); glVertex3f(-skySize, skySize, skySize);

    // ����
   
    glTexCoord2f(0, 0); glVertex3f(-skySize, -skySize, -skySize);
    glTexCoord2f(1, 0); glVertex3f(skySize, -skySize, -skySize);
    glTexCoord2f(1, 1); glVertex3f(skySize, -skySize, skySize);
    glTexCoord2f(0, 1); glVertex3f(-skySize, -skySize, skySize);


    // ��������
    glEnd();

    // ��������ӳ��
    glDisable(GL_TEXTURE_2D);

    // ���û��
    glDisable(GL_BLEND);
    glEnable(GL_FOG); // ����������Ч
}

void drawWall() { // ���Ʒ����ǽ��
    drawSky(); // ������ձ���
    glEnable(GL_TEXTURE_2D); // ����2D����

    glBindTexture(GL_TEXTURE_2D, _textureId10); // ������IDΪ_textureId10������
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // ����������С������Ϊ���Թ���
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // ��������Ŵ������Ϊ���Թ���

    glBegin(GL_QUADS); // ��ʼ�����ı���
    glNormal3f(0, 1, 0); // ���÷�������Ϊ(0, 1, 0)�����ڹ��ռ���

    // ��ǽ
    glTexCoord2f(0, 0); // ���������������½�
    glVertex3f(-roomSize - wll, -2.0f, -roomSize); // ���ö�������
    glTexCoord2f(5, 0); // ���������������½�
    glVertex3f(-roomSize - wll, -2.0f, roomSize); // ���ö�������
    glTexCoord2f(5, 5); // ���������������Ͻ�
    glVertex3f(-roomSize - wll, 8.0f, roomSize); // ���ö�������
    glTexCoord2f(0, 5); // ���������������Ͻ�
    glVertex3f(-roomSize - wll, 8.0f, -roomSize); // ���ö�������

    // ��ǽ
    glTexCoord2f(0, 0); // ���������������½�
    glVertex3f(roomSize + wll, -2.0f, roomSize); // ���ö�������
    glTexCoord2f(5, 0); // ���������������½�
    glVertex3f(roomSize + wll, -2.0f, -roomSize); // ���ö�������
    glTexCoord2f(5, 5); // ���������������Ͻ�
    glVertex3f(roomSize + wll, 8.0f, -roomSize); // ���ö�������
    glTexCoord2f(0, 5); // ���������������Ͻ�
    glVertex3f(roomSize + wll, 8.0f, roomSize); // ���ö�������

    glEnd(); // ���������ı���
    glDisable(GL_TEXTURE_2D); // ����2D����
}

void drawWallM() { 
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, _textureId10);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBegin(GL_QUADS); 
    glNormal3f(0, 1, 0);
    
    glTexCoord2f(0, 0);
    glVertex3f(-roomSize - wll, -2.0f, -roomSize);
    glTexCoord2f(5, 0);
    glVertex3f(-roomSize - wll, -2.0f, roomSize);
    glTexCoord2f(5, 5);
    glVertex3f(-roomSize - wll, 8.0f, roomSize);
    glTexCoord2f(0, 5);
    glVertex3f(-roomSize - wll, 8.0f, -roomSize);
   
    glTexCoord2f(0, 0);
    glVertex3f(roomSize + wll, -2.0f, roomSize);
    glTexCoord2f(5, 0);
    glVertex3f(roomSize + wll, -2.0f, -roomSize);
    glTexCoord2f(5, 5);
    glVertex3f(roomSize + wll, 8.0f, -roomSize);
    glTexCoord2f(0, 5);
    glVertex3f(roomSize + wll, 8.0f, roomSize);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void glasscube() {
    glEnable(GL_TEXTURE_2D); // ����2D����

    glBindTexture(GL_TEXTURE_2D, _textureId1); // ������IDΪ_textureId1������
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // ����������С������Ϊ���Թ���
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // ��������Ŵ������Ϊ���Թ���

    glEnable(GL_BLEND); // ���û�ϣ�����͸��Ч����
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // ���û�Ϻ���

    glColor4f(1.0f, 1.0f, 1.0f, 0.5f); // ������ɫΪ��͸����ɫ
    dGlassCube(); // ���û��Ʋ���������ĺ���

    glDisable(GL_BLEND); // ���û��
    glDisable(GL_TEXTURE_2D); // ����2D����
}

void drawTable() {
    glEnable(GL_TEXTURE_2D); // ����2D����

    glBindTexture(GL_TEXTURE_2D, _textureId3); // ������IDΪ_textureId3������
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // ����������С������Ϊ���Թ���
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // ��������Ŵ������Ϊ���Թ���

    drawTableTop(); // ��������
    firstLeg(); // ���Ƶ�һ������
    secondLeg(); // ���Ƶڶ�������
    thirdLeg(); // ���Ƶ���������
    fourthLeg(); // ���Ƶ���������

    glDisable(GL_TEXTURE_2D); // ����2D����
}

void book1() {
    glEnable(GL_TEXTURE_2D); // ����2D����

    glBindTexture(GL_TEXTURE_2D, _textureId9); // ������IDΪ_textureId9������
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // ����������С������Ϊ���Թ���
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // ��������Ŵ������Ϊ���Թ���
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f); // ������ɫΪ��͸����ɫ

    bk1(); // ���û����鱾1�ĺ���

    glDisable(GL_TEXTURE_2D); // ����2D����
}

void book1top() {
    glEnable(GL_TEXTURE_2D); // ����2D����

    glBindTexture(GL_TEXTURE_2D, _textureId8); // ������IDΪ_textureId8������
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // ����������С������Ϊ���Թ���
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // ��������Ŵ������Ϊ���Թ���
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f); // ������ɫΪ��͸����ɫ

    glPushMatrix(); // ���浱ǰ����״̬
    glTranslatef(-1.0f, -2.0f + book12Thickness, 2.0f); // ƽ���鱾��ָ��λ��
    glRotatef(ang1, 0.0f, 1.0f, 0.0f); // ��Y����ת�鱾
    glBegin(GL_QUADS); // ��ʼ�����ı���

    // �鱾����
    glTexCoord2f(_min, _min); glVertex3f(-bookWidth, bookHeight + bookThickness, bookLength);
    glTexCoord2f(_min, _max); glVertex3f(-bookWidth, bookHeight + bookThickness, -bookLength);
    glTexCoord2f(_max, _max); glVertex3f(bookWidth, bookHeight + bookThickness, -bookLength);
    glTexCoord2f(_max, _min); glVertex3f(bookWidth, bookHeight + bookThickness, bookLength);

    glEnd(); // ���������ı���
    glDisable(GL_TEXTURE_2D); // ����2D����
    glPopMatrix(); // �ָ�����״̬
}

void book2() {
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, _textureId5);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    bk2();

    glDisable(GL_TEXTURE_2D);
}

void book2top() {
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, _textureId4);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    glPushMatrix();
    glTranslatef(-1.0f, -2.0f + book2Height + book12Thickness, 2.0f);
    glRotatef(ang2, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);

    
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + bookThickness, bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(-bookWidth, bookHeight + bookThickness, -bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth, bookHeight + bookThickness, -bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(bookWidth, bookHeight + bookThickness, bookLength);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void book3() {
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, _textureId7);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    bk3();

    glDisable(GL_TEXTURE_2D);
}

void book3top() {
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, _textureId6);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    glPushMatrix();
    glTranslatef(-1.0f, -2.0f + book3Height + book3Thickness, 2.0f);
    glRotatef(ang3, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);

    
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + bookThickness, bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(-bookWidth, bookHeight + bookThickness, -bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth, bookHeight + bookThickness, -bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(bookWidth, bookHeight + bookThickness, bookLength);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void pages() {
    glEnable(GL_TEXTURE_2D); // ����2D����

    glBindTexture(GL_TEXTURE_2D, _textureId2); // ������IDΪ_textureId2������
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // ����������С������Ϊ���Թ���
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // ��������Ŵ������Ϊ���Թ���
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f); // ������ɫΪ��͸����ɫ

    pgs(); // ���û����鱾ҳ��ĺ���

    glDisable(GL_TEXTURE_2D); // ����2D����
}