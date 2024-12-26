#include "Texture.h"

// 定义房间、桌子、书本等物体的尺寸和位置参数
float roomSize = 15.0f;  // 房间的大小
float tableWidth = 2.0f;   // 桌子顶部从中心到边缘的宽度
float tableLength = 4.0f;   // 桌子顶部从中心到边缘的长度
float tableHeight = 1.7f;   // 桌子顶部从中心到边缘的高度
float tableThickness = 0.3f;   // 桌子顶部的厚度
float legSize = 0.3f;   // 桌子腿的尺寸

float bookWidth = 2.0f / 3.0f;  // 书本从中心到边缘的宽度
float bookLength = 4.0f / 3.0f;  // 书本从中心到边缘的长度
float bookHeight = 2.0f;         // 书本从中心到边缘的高度
float bookThickness = 0.025f;       // 书本封面的厚度
float book12Thickness = 0.1f;        // 书本1和2的厚度
float book3Thickness = 0.13f;      // 书本3的厚度
float bookB = 0.03f;        // 书本装订的厚度
float ang1 = 5.0f;       // 书本1的旋转角度
float book2Height = bookThickness + book12Thickness;    // 书本2的高度
float book3Height = 2 * book2Height;     // 书本3的高度
float ang2 = 30.0f;      // 书本2的旋转角度
float ang3 = 190.0f;     // 书本3的旋转角度

float a = 0.0f;  // 立方体的位置
float b = 0.0f;
float c = 0.0f;
float d = 1.5f;  // 立方体的大小
float _min = 0.0f;  // 纹理坐标的最小值
float _max = 1.0f;  // 纹理坐标的最大值
float wll = 0.01f;  // 墙壁的厚度

void drawTableTop() {
    glPushMatrix(); // 保存当前矩阵状态
    glTranslatef(0.0f, -2.0f, 0.0f); // 将桌子顶部移动到地板上

    glBegin(GL_QUADS);  // 开始绘制四边形
    // 底部：法线朝外
    glTexCoord2f(_min, _min);
    glVertex3f(-tableWidth, tableHeight, tableLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-tableWidth, tableHeight, -tableLength);
    glTexCoord2f(_max, _max);
    glVertex3f(tableWidth, tableHeight, -tableLength);
    glTexCoord2f(_min, _max);
    glVertex3f(tableWidth, tableHeight, tableLength);

    // 前部：法线朝外
    glTexCoord2f(_min, _min);
    glVertex3f(-tableWidth, tableHeight + tableThickness, tableLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-tableWidth, tableHeight, tableLength);
    glTexCoord2f(_max, _max);
    glVertex3f(tableWidth, tableHeight, tableLength);
    glTexCoord2f(_min, _max);
    glVertex3f(tableWidth, tableHeight + tableThickness, tableLength);

    // 后部：法线朝外
    glTexCoord2f(_min, _min);
    glVertex3f(tableWidth, tableHeight + tableThickness, -tableLength);
    glTexCoord2f(_max, _min);
    glVertex3f(tableWidth, tableHeight, -tableLength);
    glTexCoord2f(_max, _max);
    glVertex3f(-tableWidth, tableHeight, -tableLength);
    glTexCoord2f(_min, _max);
    glVertex3f(-tableWidth, tableHeight + tableThickness, -tableLength);

    // 右部：法线朝外
    glTexCoord2f(_min, _min);
    glVertex3f(tableWidth, tableHeight + tableThickness, tableLength);
    glTexCoord2f(_max, _min);
    glVertex3f(tableWidth, tableHeight, tableLength);
    glTexCoord2f(_max, _max);
    glVertex3f(tableWidth, tableHeight, -tableLength);
    glTexCoord2f(_min, _max);
    glVertex3f(tableWidth, tableHeight + tableThickness, -tableLength);

    // 左部：法线朝外
    glTexCoord2f(_max, _max);
    glVertex3f(-tableWidth, tableHeight + tableThickness, tableLength);
    glTexCoord2f(_min, _max);
    glVertex3f(-tableWidth, tableHeight + tableThickness, -tableLength);
    glTexCoord2f(_min, _min);
    glVertex3f(-tableWidth, tableHeight, -tableLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-tableWidth, tableHeight, tableLength);

    // 顶部：法线朝外
    glTexCoord2f(_min, _min);
    glVertex3f(-tableWidth, tableHeight + tableThickness, tableLength);
    glTexCoord2f(_min, _max);
    glVertex3f(tableWidth, tableHeight + tableThickness, tableLength);
    glTexCoord2f(_max, _max);
    glVertex3f(tableWidth, tableHeight + tableThickness, -tableLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-tableWidth, tableHeight + tableThickness, -tableLength);
    glEnd();  // 结束绘制
    glPopMatrix();  // 恢复矩阵状态
}


// 绘制第一条桌子腿
void firstLeg() {
    glPushMatrix();  // 保存当前矩阵状态
    glTranslatef(0.0f, -2.0f, 0.0f);  // 将桌子腿移动到地板上

    glBegin(GL_QUADS);  // 开始绘制四边形
    // 前部：法线朝外
    glNormal3f(0, 0, 1);
    glTexCoord2f(_min, _min);
    glVertex3f(-tableWidth + legSize, tableHeight, tableLength - legSize);
    glTexCoord2f(_max, _min);
    glVertex3f(-tableWidth + legSize, 0.0f, tableLength - legSize);
    glTexCoord2f(_max, _max);
    glVertex3f(-tableWidth + legSize + legSize, 0.0f, tableLength - legSize);
    glTexCoord2f(_min, _max);
    glVertex3f(-tableWidth + legSize + legSize, tableHeight, tableLength - legSize);

    // 后部：法线朝外
    glNormal3f(0, 0, -1);
    glTexCoord2f(1, 1);
    glVertex3f(-tableWidth + legSize, tableHeight, tableLength - legSize - legSize);
    glTexCoord2f(0, 1);
    glVertex3f(-tableWidth + legSize + legSize, tableHeight, tableLength - legSize - legSize);
    glTexCoord2f(0, 0);
    glVertex3f(-tableWidth + legSize + legSize, 0.0f, tableLength - legSize - legSize);
    glTexCoord2f(1, 0);
    glVertex3f(-tableWidth + legSize, 0.0f, tableLength - legSize - legSize);

    // 右部：法线朝外
    glNormal3f(1, 0, 0);
    glTexCoord2f(0, 1);
    glVertex3f(-tableWidth + legSize + legSize, tableHeight, tableLength - legSize);
    glTexCoord2f(0, 0);
    glVertex3f(-tableWidth + legSize + legSize, 0.0f, tableLength - legSize);
    glTexCoord2f(1, 0);
    glVertex3f(-tableWidth + legSize + legSize, 0.0f, tableLength - legSize - legSize);
    glTexCoord2f(1, 1);
    glVertex3f(-tableWidth + legSize + legSize, tableHeight, tableLength - legSize - legSize);

    // 左部：法线朝外
    glNormal3f(-1, 0, 0);
    glTexCoord2f(1, 1);
    glVertex3f(-tableWidth + legSize, tableHeight, tableLength - legSize);
    glTexCoord2f(0, 1);
    glVertex3f(-tableWidth + legSize, tableHeight, tableLength - legSize - legSize);
    glTexCoord2f(0, 0);
    glVertex3f(-tableWidth + legSize, 0.0f, tableLength - legSize - legSize);
    glTexCoord2f(1, 0);
    glVertex3f(-tableWidth + legSize, 0.0f, tableLength - legSize);
    glEnd();  // 结束绘制
    glPopMatrix();  // 恢复矩阵状态
}


// 绘制第二条桌子腿
void secondLeg() {
    glPushMatrix();  // 保存当前矩阵状态
    glTranslatef(0.0f, -2.0f, 0.0f);  // 将桌子腿移动到地板上

    glBegin(GL_QUADS);  // 开始绘制四边形
    // 前部：法线朝外
    glNormal3f(0, 0, 1);
    glTexCoord2f(1, 1);
    glVertex3f(tableWidth - legSize, tableHeight, tableLength - legSize);
    glTexCoord2f(0, 1);
    glVertex3f(tableWidth - legSize - legSize, tableHeight, tableLength - legSize);
    glTexCoord2f(0, 0);
    glVertex3f(tableWidth - legSize - legSize, 0.0f, tableLength - legSize);
    glTexCoord2f(1, 0);
    glVertex3f(tableWidth - legSize, 0.0f, tableLength - legSize);

    // 后部：法线朝外
    glNormal3f(0, 0, -1);
    glTexCoord2f(0, 1);
    glVertex3f(tableWidth - legSize, tableHeight, tableLength - legSize - legSize);
    glTexCoord2f(0, 0);
    glVertex3f(tableWidth - legSize, 0.0f, tableLength - legSize - legSize);
    glTexCoord2f(1, 0);
    glVertex3f(tableWidth - legSize - legSize, 0.0f, tableLength - legSize - legSize);
    glTexCoord2f(1, 1);
    glVertex3f(tableWidth - legSize - legSize, tableHeight, tableLength - legSize - legSize);

    // 左部：法线朝外
    glNormal3f(-1, 0, 0);
    glTexCoord2f(1, 1);
    glVertex3f(tableWidth - legSize - legSize, tableHeight, tableLength - legSize);
    glTexCoord2f(0, 1);
    glVertex3f(tableWidth - legSize - legSize, tableHeight, tableLength - legSize - legSize);
    glTexCoord2f(0, 0);
    glVertex3f(tableWidth - legSize - legSize, 0.0f, tableLength - legSize - legSize);
    glTexCoord2f(1, 0);
    glVertex3f(tableWidth - legSize - legSize, 0.0f, tableLength - legSize);

    // 右部：法线朝外
    glNormal3f(1, 0, 0);
    glTexCoord2f(0, 1);
    glVertex3f(tableWidth - legSize, tableHeight, tableLength - legSize);
    glTexCoord2f(0, 0);
    glVertex3f(tableWidth - legSize, 0.0f, tableLength - legSize);
    glTexCoord2f(1, 0);
    glVertex3f(tableWidth - legSize, 0.0f, tableLength - legSize - legSize);
    glTexCoord2f(1, 1);
    glVertex3f(tableWidth - legSize, tableHeight, tableLength - legSize - legSize);
    glEnd();  // 结束绘制
    glPopMatrix();  // 恢复矩阵状态
}

// 绘制第三条桌子腿
void thirdLeg() {
    glPushMatrix();  // 保存当前矩阵状态
    glTranslatef(0.0f, -2.0f, 0.0f);  // 将桌子腿移动到地板上

    glBegin(GL_QUADS);  // 开始绘制四边形
    // 前部：法线朝外
    glNormal3f(0, 0, 1);
    glTexCoord2f(_min, _min);
    glVertex3f(-tableWidth + legSize, tableHeight, -tableLength + legSize);
    glTexCoord2f(_max, _min);
    glVertex3f(-tableWidth + legSize, 0.0f, -tableLength + legSize);
    glTexCoord2f(_max, _max);
    glVertex3f(-tableWidth + legSize + legSize, 0.0f, -tableLength + legSize);
    glTexCoord2f(_min, _max);
    glVertex3f(-tableWidth + legSize + legSize, tableHeight, -tableLength + legSize);

    // 后部：法线朝外
    glNormal3f(0, 0, -1);
    glTexCoord2f(1, 1);
    glVertex3f(-tableWidth + legSize, tableHeight, -tableLength + legSize + legSize);
    glTexCoord2f(0, 1);
    glVertex3f(-tableWidth + legSize + legSize, tableHeight, -tableLength + legSize + legSize);
    glTexCoord2f(0, 0);
    glVertex3f(-tableWidth + legSize + legSize, 0.0f, -tableLength + legSize + legSize);
    glTexCoord2f(1, 0);
    glVertex3f(-tableWidth + legSize, 0.0f, -tableLength + legSize + legSize);

    // 右部：法线朝外
    glNormal3f(1, 0, 0);
    glTexCoord2f(0, 1);
    glVertex3f(-tableWidth + legSize + legSize, tableHeight, -tableLength + legSize);
    glTexCoord2f(0, 0);
    glVertex3f(-tableWidth + legSize + legSize, 0.0f, -tableLength + legSize);
    glTexCoord2f(1, 0);
    glVertex3f(-tableWidth + legSize + legSize, 0.0f, -tableLength + legSize + legSize);
    glTexCoord2f(1, 1);
    glVertex3f(-tableWidth + legSize + legSize, tableHeight, -tableLength + legSize + legSize);

    // 左部：法线朝外
    glNormal3f(-1, 0, 0);
    glTexCoord2f(1, 1);
    glVertex3f(-tableWidth + legSize, tableHeight, -tableLength + legSize);
    glTexCoord2f(0, 1);
    glVertex3f(-tableWidth + legSize, tableHeight, -tableLength + legSize + legSize);
    glTexCoord2f(0, 0);
    glVertex3f(-tableWidth + legSize, 0.0f, -tableLength + legSize + legSize);
    glTexCoord2f(1, 0);
    glVertex3f(-tableWidth + legSize, 0.0f, -tableLength + legSize);
    glEnd();  // 结束绘制
    glPopMatrix();  // 恢复矩阵状态
}


// 绘制第四条桌子腿
void fourthLeg() {
    glPushMatrix();  // 保存当前矩阵状态
    glTranslatef(0.0f, -2.0f, 0.0f);  // 将桌子腿移动到地板上

    glBegin(GL_QUADS);  // 开始绘制四边形
    // 前部：法线朝外
    glNormal3f(0, 0, 1);
    glTexCoord2f(1, 1);
    glVertex3f(tableWidth - legSize, tableHeight, -tableLength + legSize);
    glTexCoord2f(0, 1);
    glVertex3f(tableWidth - legSize - legSize, tableHeight, -tableLength + legSize);
    glTexCoord2f(0, 0);
    glVertex3f(tableWidth - legSize - legSize, 0.0f, -tableLength + legSize);
    glTexCoord2f(1, 0);
    glVertex3f(tableWidth - legSize, 0.0f, -tableLength + legSize);

    // 后部：法线朝外
    glNormal3f(0, 0, -1);
    glTexCoord2f(0, 1);
    glVertex3f(tableWidth - legSize, tableHeight, -tableLength + legSize + legSize);
    glTexCoord2f(0, 0);
    glVertex3f(tableWidth - legSize, 0.0f, -tableLength + legSize + legSize);
    glTexCoord2f(1, 0);
    glVertex3f(tableWidth - legSize - legSize, 0.0f, -tableLength + legSize + legSize);
    glTexCoord2f(1, 1);
    glVertex3f(tableWidth - legSize - legSize, tableHeight, -tableLength + legSize + legSize);

    // 左部：法线朝外
    glNormal3f(-1, 0, 0);
    glTexCoord2f(1, 1);
    glVertex3f(tableWidth - legSize - legSize, tableHeight, -tableLength + legSize);
    glTexCoord2f(0, 1);
    glVertex3f(tableWidth - legSize - legSize, tableHeight, -tableLength + legSize + legSize);
    glTexCoord2f(0, 0);
    glVertex3f(tableWidth - legSize - legSize, 0.0f, -tableLength + legSize + legSize);
    glTexCoord2f(1, 0);
    glVertex3f(tableWidth - legSize - legSize, 0.0f, -tableLength + legSize);

    // 右部：法线朝外
    glNormal3f(1, 0, 0);
    glTexCoord2f(0, 1);
    glVertex3f(tableWidth - legSize, tableHeight, -tableLength + legSize);
    glTexCoord2f(0, 0);
    glVertex3f(tableWidth - legSize, 0.0f, -tableLength + legSize);
    glTexCoord2f(1, 0);
    glVertex3f(tableWidth - legSize, 0.0f, -tableLength + legSize + legSize);
    glTexCoord2f(1, 1);
    glVertex3f(tableWidth - legSize, tableHeight, -tableLength + legSize + legSize);
    glEnd();  // 结束绘制
    glPopMatrix();  // 恢复矩阵状态
}

// 绘制玻璃立方体
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
    glPopMatrix(); // 2

    ///////////////top cover////////
    glPushMatrix(); // 3
    glTranslatef(-1.0f, -2.0f + book2Height + book12Thickness, 2.0f); // move up to lie above bottom cover
    glRotatef(ang2, 0.0f, 1.0f, 0.0f);
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
    glTranslatef(-1.0f, -2.0f + book2Height, 2.0f);
    glRotatef(ang2, 0.0f, 1.0f, 0.0f);
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
    glPopMatrix(); // 5
}

void bk3() {
    glPushMatrix(); // 2
    glTranslatef(-1.0f, -2.0f + book3Height, 2.0f); // move to lie on the left corner of the table
    glRotatef(ang3, 0.0f, 1.0f, 0.0f);
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
    //back
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + bookThickness, -bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth, bookHeight + bookThickness, -bookLength);
    //right
    glTexCoord2f(_min, _min);
    glVertex3f(bookWidth, bookHeight + bookThickness, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth, bookHeight + bookThickness, -bookLength);
    //left
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + bookThickness, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(-bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(-bookWidth, bookHeight + bookThickness, -bookLength);

    glEnd();
    glPopMatrix();//2

    ///////////////top cover////////
    glPushMatrix(); //3
    glTranslatef(-1.0f, -2.0f + book3Height + book3Thickness, 2.0f);// move up to lie above bottom cover
    glRotatef(ang3, 0.0f, 1.0f, 0.0f);
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
    //front
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + bookThickness, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth, bookHeight, bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth, bookHeight + bookThickness, bookLength);
    //back
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + bookThickness, -bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth, bookHeight + bookThickness, -bookLength);
    //right
    glTexCoord2f(_min, _min);
    glVertex3f(bookWidth, bookHeight + bookThickness, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth, bookHeight + bookThickness, -bookLength);
    //left
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + bookThickness, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(-bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(-bookWidth, bookHeight + bookThickness, -bookLength);

    glEnd();
    glPopMatrix();  //3
    ////////////////////binding//////
    glPushMatrix();//5
    glTranslatef(-1.0f, -2.0f + book3Height, 2.0f);
    glRotatef(ang3, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);

    //front
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth - bookB, bookHeight, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(-bookWidth, bookHeight + bookThickness + book3Thickness, bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(-bookWidth - bookB, bookHeight + bookThickness + book3Thickness, bookLength);
    //back
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth - bookB, bookHeight, -bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(-bookWidth, bookHeight + bookThickness + book3Thickness, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(-bookWidth - bookB, bookHeight + bookThickness + book3Thickness, -bookLength);
    //left
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth - bookB, bookHeight, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth - bookB, bookHeight, -bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(-bookWidth - bookB, bookHeight + bookThickness + book3Thickness, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(-bookWidth - bookB, bookHeight + bookThickness + book3Thickness, bookLength);
    //right
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(-bookWidth, bookHeight + bookThickness + book3Thickness, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(-bookWidth, bookHeight + bookThickness + book3Thickness, bookLength);
    //top
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth - bookB, bookHeight + bookThickness + book3Thickness, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight + bookThickness + book3Thickness, bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(-bookWidth, bookHeight + bookThickness + book3Thickness, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(-bookWidth - bookB, bookHeight + bookThickness + book3Thickness, -bookLength);
    glEnd();
    glPopMatrix();//5
}

void pgs() {
    /////////pages of book 1
    glPushMatrix(); //4
    glTranslatef(-1.0f, -2.0f + bookThickness, 2.0f);// move to lie between covers
    glRotatef(ang1, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glNormal3f(0, 1, 0);
    //front
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + book12Thickness, bookLength - 0.03f);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, bookLength - 0.03f);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth - 0.03f, bookHeight, bookLength - 0.03f);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth - 0.03f, bookHeight + book12Thickness, bookLength - 0.03f);
    //back
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + book12Thickness, -bookLength + 0.03f);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, -bookLength + 0.03f);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth - 0.03f, bookHeight, -bookLength + 0.03f);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth - 0.03f, bookHeight + book12Thickness, -bookLength + 0.03f);
    //right
    glTexCoord2f(_min, _min);
    glVertex3f(bookWidth - 0.03f, bookHeight + book12Thickness, bookLength - 0.03f);
    glTexCoord2f(_max, _min);
    glVertex3f(bookWidth - 0.03f, bookHeight, bookLength - 0.03f);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth - 0.03f, bookHeight, -bookLength + 0.03f);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth - 0.03f, bookHeight + book12Thickness, -bookLength + 0.03f);

    glEnd();
    glPopMatrix();  //4

    //////////////////pages of book 2///////////////
    glPushMatrix(); //8
    glTranslatef(-1.0f, -2.0f + book2Height + bookThickness, 2.0f);// move to lie between covers
    glRotatef(ang2, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    //front
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + book12Thickness, bookLength - 0.03f);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, bookLength - 0.03f);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth - 0.03f, bookHeight, bookLength - 0.03f);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth - 0.03f, bookHeight + book12Thickness, bookLength - 0.03f);
    //back
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + book12Thickness, -bookLength + 0.03f);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, -bookLength + 0.03f);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth - 0.03f, bookHeight, -bookLength + 0.03f);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth - 0.03f, bookHeight + book12Thickness, -bookLength + 0.03f);
    //right
    glTexCoord2f(_min, _min);
    glVertex3f(bookWidth - 0.03f, bookHeight + book12Thickness, bookLength - 0.03f);
    glTexCoord2f(_max, _min);
    glVertex3f(bookWidth - 0.03f, bookHeight, bookLength - 0.03f);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth - 0.03f, bookHeight, -bookLength + 0.03f);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth - 0.03f, bookHeight + book12Thickness, -bookLength + 0.03f);

    glEnd();
    glPopMatrix();  //8

    ///////////////////////////////
    ///////////pages of book 3
    glPushMatrix(); //12
    glTranslatef(-1.0f, -2.0f + book3Height + bookThickness, 2.0f);// move to lie between covers
    glRotatef(ang3, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    //front
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + book3Thickness, bookLength - 0.03f);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, bookLength - 0.03f);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth - 0.03f, bookHeight, bookLength - 0.03f);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth - 0.03f, bookHeight + book3Thickness, bookLength - 0.03f);
    //back
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + book3Thickness, -bookLength + 0.03f);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, -bookLength + 0.03f);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth - 0.03f, bookHeight, -bookLength + 0.03f);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth - 0.03f, bookHeight + book3Thickness, -bookLength + 0.03f);
    //right
    glTexCoord2f(_min, _min);
    glVertex3f(bookWidth - 0.03f, bookHeight + book3Thickness, bookLength - 0.03f);
    glTexCoord2f(_max, _min);
    glVertex3f(bookWidth - 0.03f, bookHeight, bookLength - 0.03f);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth - 0.03f, bookHeight, -bookLength + 0.03f);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth - 0.03f, bookHeight + book3Thickness, -bookLength + 0.03f);

    glEnd();
    glPopMatrix();  //12
}

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

//////////////////////////

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
    glVertex3f(-roomSize, 8.0f, -roomSize);
    glTexCoord2f(1, 0);
    glVertex3f(roomSize, 8.0f, -roomSize);
    glTexCoord2f(1, 1);
    glVertex3f(roomSize, 8.0f, roomSize);
    glTexCoord2f(0, 1);
    glVertex3f(-roomSize, 8.0f, roomSize);


    glEnd();
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_BLEND);

}

void drawWall() { //enclosing the walls of the room{
    drawSky();
    glEnable(GL_TEXTURE_2D);//enabling texture

    glBindTexture(GL_TEXTURE_2D, _textureId10);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBegin(GL_QUADS);//normals pointing outwards
    glNormal3f(0, 1, 0);


    ////left
    glTexCoord2f(0, 0);
    glVertex3f(-roomSize - wll, -2.0f, -roomSize);
    glTexCoord2f(5, 0);
    glVertex3f(-roomSize - wll, -2.0f, roomSize);
    glTexCoord2f(5, 5);
    glVertex3f(-roomSize - wll, 8.0f, roomSize);
    glTexCoord2f(0, 5);
    glVertex3f(-roomSize - wll, 8.0f, -roomSize);
    ////right
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

void drawWallM() { // enclosing the walls of the room
    glEnable(GL_TEXTURE_2D);//enabling texture

    glBindTexture(GL_TEXTURE_2D, _textureId10);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBegin(GL_QUADS); // normals pointing outwards
    glNormal3f(0, 1, 0);
    ////left
    glTexCoord2f(0, 0);
    glVertex3f(-roomSize - wll, -2.0f, -roomSize);
    glTexCoord2f(5, 0);
    glVertex3f(-roomSize - wll, -2.0f, roomSize);
    glTexCoord2f(5, 5);
    glVertex3f(-roomSize - wll, 8.0f, roomSize);
    glTexCoord2f(0, 5);
    glVertex3f(-roomSize - wll, 8.0f, -roomSize);
    ////right
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

void drawTable() {
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
    glTranslatef(-1.0f, -2.0f + book12Thickness, 2.0f);// move up to lie above bottom cover
    glRotatef(ang1, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);

    //Top
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
    glTranslatef(-1.0f, -2.0f + book2Height + book12Thickness, 2.0f);// move up to lie above bottom cover
    glRotatef(ang2, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);

    //Top
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
    glTranslatef(-1.0f, -2.0f + book3Height + book3Thickness, 2.0f);// move up to lie above bottom cover
    glRotatef(ang3, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);

    //Top
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
    glEnable(GL_TEXTURE_2D); 

    glBindTexture(GL_TEXTURE_2D, _textureId2);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    pgs();
    glDisable(GL_TEXTURE_2D);
}
