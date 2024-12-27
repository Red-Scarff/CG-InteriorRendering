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
    glPopMatrix(); 

   //封面
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
    // 前
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + bookThickness, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth, bookHeight, bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth, bookHeight + bookThickness, bookLength);
    // 后
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight + bookThickness, -bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth, bookHeight + bookThickness, -bookLength);
    // 右
    glTexCoord2f(_min, _min);
    glVertex3f(bookWidth, bookHeight + bookThickness, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(bookWidth, bookHeight + bookThickness, -bookLength);
    // 左
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
    
    // 书页
    glPushMatrix(); 
    glTranslatef(-1.0f, -2.0f + book2Height, 2.0f);
    glRotatef(ang2, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);

    // 前
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth - bookB, bookHeight, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(-bookWidth, bookHeight + bookThickness + book12Thickness, bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(-bookWidth - bookB, bookHeight + bookThickness + book12Thickness, bookLength);
    // 后
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth - bookB, bookHeight, -bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(-bookWidth, bookHeight + bookThickness + book12Thickness, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(-bookWidth - bookB, bookHeight + bookThickness + book12Thickness, -bookLength);
    // 左
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth - bookB, bookHeight, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth - bookB, bookHeight, -bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(-bookWidth - bookB, bookHeight + bookThickness + book12Thickness, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(-bookWidth - bookB, bookHeight + bookThickness + book12Thickness, bookLength);
    // 右
    glTexCoord2f(_min, _min);
    glVertex3f(-bookWidth, bookHeight, bookLength);
    glTexCoord2f(_max, _min);
    glVertex3f(-bookWidth, bookHeight, -bookLength);
    glTexCoord2f(_max, _max);
    glVertex3f(-bookWidth, bookHeight + bookThickness + book12Thickness, -bookLength);
    glTexCoord2f(_min, _max);
    glVertex3f(-bookWidth, bookHeight + bookThickness + book12Thickness, bookLength);
    // 顶
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

//绘制书的侧面
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


// 绘制地板阴影对象
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
    glDisable(GL_FOG); // 禁用雾效
    // 启用2D纹理映射
    glEnable(GL_TEXTURE_2D);

    // 绑定天空纹理（_textureId11 是天空纹理的ID）
    glBindTexture(GL_TEXTURE_2D, _textureId11);

    // 设置纹理参数：缩小和放大时使用线性过滤
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // 启用混合（用于实现透明效果）
    glEnable(GL_BLEND);

    // 设置混合函数：源颜色乘以源Alpha，目标颜色乘以（1 - 源Alpha）
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // 开始绘制立方体的6个面
    glBegin(GL_QUADS);

    float skySize = 100.0f;

    // 前面
    glNormal3f(0, -1, 0);
    glColor4f(1, 1, 1, 0.6f);
    glTexCoord2f(0, 0); glVertex3f(-skySize, -skySize, skySize);
    glTexCoord2f(1, 0); glVertex3f(skySize, -skySize, skySize);
    glTexCoord2f(1, 1); glVertex3f(skySize, skySize, skySize);
    glTexCoord2f(0, 1); glVertex3f(-skySize, skySize, skySize);

    // 后面
    
    glTexCoord2f(0, 0); glVertex3f(-skySize, -skySize, -skySize);
    glTexCoord2f(1, 0); glVertex3f(skySize, -skySize, -skySize);
    glTexCoord2f(1, 1); glVertex3f(skySize, skySize, -skySize);
    glTexCoord2f(0, 1); glVertex3f(-skySize, skySize, -skySize);

    // 左面
  
    glTexCoord2f(0, 0); glVertex3f(-skySize, -skySize, -skySize);
    glTexCoord2f(1, 0); glVertex3f(-skySize, -skySize, skySize);
    glTexCoord2f(1, 1); glVertex3f(-skySize, skySize, skySize);
    glTexCoord2f(0, 1); glVertex3f(-skySize, skySize, -skySize);

    // 右面

    glTexCoord2f(0, 0); glVertex3f(skySize, -skySize, -skySize);
    glTexCoord2f(1, 0); glVertex3f(skySize, -skySize, skySize);
    glTexCoord2f(1, 1); glVertex3f(skySize, skySize, skySize);
    glTexCoord2f(0, 1); glVertex3f(skySize, skySize, -skySize);

    // 上面
   
    glTexCoord2f(0, 0); glVertex3f(-skySize, skySize, -skySize);
    glTexCoord2f(1, 0); glVertex3f(skySize, skySize, -skySize);
    glTexCoord2f(1, 1); glVertex3f(skySize, skySize, skySize);
    glTexCoord2f(0, 1); glVertex3f(-skySize, skySize, skySize);

    // 下面
   
    glTexCoord2f(0, 0); glVertex3f(-skySize, -skySize, -skySize);
    glTexCoord2f(1, 0); glVertex3f(skySize, -skySize, -skySize);
    glTexCoord2f(1, 1); glVertex3f(skySize, -skySize, skySize);
    glTexCoord2f(0, 1); glVertex3f(-skySize, -skySize, skySize);


    // 结束绘制
    glEnd();

    // 禁用纹理映射
    glDisable(GL_TEXTURE_2D);

    // 禁用混合
    glDisable(GL_BLEND);
    glEnable(GL_FOG); // 重新启用雾效
}

void drawWall() { // 绘制房间的墙壁
    drawSky(); // 绘制天空背景
    glEnable(GL_TEXTURE_2D); // 启用2D纹理

    glBindTexture(GL_TEXTURE_2D, _textureId10); // 绑定纹理ID为_textureId10的纹理
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // 设置纹理缩小过滤器为线性过滤
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // 设置纹理放大过滤器为线性过滤

    glBegin(GL_QUADS); // 开始绘制四边形
    glNormal3f(0, 1, 0); // 设置法线向量为(0, 1, 0)，用于光照计算

    // 左墙
    glTexCoord2f(0, 0); // 设置纹理坐标左下角
    glVertex3f(-roomSize - wll, -2.0f, -roomSize); // 设置顶点坐标
    glTexCoord2f(5, 0); // 设置纹理坐标右下角
    glVertex3f(-roomSize - wll, -2.0f, roomSize); // 设置顶点坐标
    glTexCoord2f(5, 5); // 设置纹理坐标右上角
    glVertex3f(-roomSize - wll, 8.0f, roomSize); // 设置顶点坐标
    glTexCoord2f(0, 5); // 设置纹理坐标左上角
    glVertex3f(-roomSize - wll, 8.0f, -roomSize); // 设置顶点坐标

    // 右墙
    glTexCoord2f(0, 0); // 设置纹理坐标左下角
    glVertex3f(roomSize + wll, -2.0f, roomSize); // 设置顶点坐标
    glTexCoord2f(5, 0); // 设置纹理坐标右下角
    glVertex3f(roomSize + wll, -2.0f, -roomSize); // 设置顶点坐标
    glTexCoord2f(5, 5); // 设置纹理坐标右上角
    glVertex3f(roomSize + wll, 8.0f, -roomSize); // 设置顶点坐标
    glTexCoord2f(0, 5); // 设置纹理坐标左上角
    glVertex3f(roomSize + wll, 8.0f, roomSize); // 设置顶点坐标

    glEnd(); // 结束绘制四边形
    glDisable(GL_TEXTURE_2D); // 禁用2D纹理
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
    glEnable(GL_TEXTURE_2D); // 启用2D纹理

    glBindTexture(GL_TEXTURE_2D, _textureId1); // 绑定纹理ID为_textureId1的纹理
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // 设置纹理缩小过滤器为线性过滤
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // 设置纹理放大过滤器为线性过滤

    glEnable(GL_BLEND); // 启用混合（用于透明效果）
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // 设置混合函数

    glColor4f(1.0f, 1.0f, 1.0f, 0.5f); // 设置颜色为半透明白色
    dGlassCube(); // 调用绘制玻璃立方体的函数

    glDisable(GL_BLEND); // 禁用混合
    glDisable(GL_TEXTURE_2D); // 禁用2D纹理
}

void drawTable() {
    glEnable(GL_TEXTURE_2D); // 启用2D纹理

    glBindTexture(GL_TEXTURE_2D, _textureId3); // 绑定纹理ID为_textureId3的纹理
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // 设置纹理缩小过滤器为线性过滤
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // 设置纹理放大过滤器为线性过滤

    drawTableTop(); // 绘制桌面
    firstLeg(); // 绘制第一条桌腿
    secondLeg(); // 绘制第二条桌腿
    thirdLeg(); // 绘制第三条桌腿
    fourthLeg(); // 绘制第四条桌腿

    glDisable(GL_TEXTURE_2D); // 禁用2D纹理
}

void book1() {
    glEnable(GL_TEXTURE_2D); // 启用2D纹理

    glBindTexture(GL_TEXTURE_2D, _textureId9); // 绑定纹理ID为_textureId9的纹理
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // 设置纹理缩小过滤器为线性过滤
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // 设置纹理放大过滤器为线性过滤
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f); // 设置颜色为不透明白色

    bk1(); // 调用绘制书本1的函数

    glDisable(GL_TEXTURE_2D); // 禁用2D纹理
}

void book1top() {
    glEnable(GL_TEXTURE_2D); // 启用2D纹理

    glBindTexture(GL_TEXTURE_2D, _textureId8); // 绑定纹理ID为_textureId8的纹理
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // 设置纹理缩小过滤器为线性过滤
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // 设置纹理放大过滤器为线性过滤
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f); // 设置颜色为不透明白色

    glPushMatrix(); // 保存当前矩阵状态
    glTranslatef(-1.0f, -2.0f + book12Thickness, 2.0f); // 平移书本到指定位置
    glRotatef(ang1, 0.0f, 1.0f, 0.0f); // 绕Y轴旋转书本
    glBegin(GL_QUADS); // 开始绘制四边形

    // 书本顶部
    glTexCoord2f(_min, _min); glVertex3f(-bookWidth, bookHeight + bookThickness, bookLength);
    glTexCoord2f(_min, _max); glVertex3f(-bookWidth, bookHeight + bookThickness, -bookLength);
    glTexCoord2f(_max, _max); glVertex3f(bookWidth, bookHeight + bookThickness, -bookLength);
    glTexCoord2f(_max, _min); glVertex3f(bookWidth, bookHeight + bookThickness, bookLength);

    glEnd(); // 结束绘制四边形
    glDisable(GL_TEXTURE_2D); // 禁用2D纹理
    glPopMatrix(); // 恢复矩阵状态
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
    glEnable(GL_TEXTURE_2D); // 启用2D纹理

    glBindTexture(GL_TEXTURE_2D, _textureId2); // 绑定纹理ID为_textureId2的纹理
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // 设置纹理缩小过滤器为线性过滤
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // 设置纹理放大过滤器为线性过滤
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f); // 设置颜色为不透明白色

    pgs(); // 调用绘制书本页面的函数

    glDisable(GL_TEXTURE_2D); // 禁用2D纹理
}