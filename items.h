#ifndef ITEMS_H
#define ITEMS_H

#include "Texture.h"


class Scene {
public:

    Scene();
    ~Scene();

    // 绘制场景中的对象
    void drawTableTop();
    void firstLeg();
    void secondLeg();
    void thirdLeg();
    void fourthLeg();
    void dGlassCube();
    void bk1();
    void bk2();
    void bk3();
    void pgs();
    void FloorShadowObj();
    void drawFloor();
    void drawSky();
    void drawWall();
    void drawWallM();
    void glasscube();
    void drawTable();
    void book1();
    void book1top();
    void book2();
    void book2top();
    void book3();
    void book3top();
    void pages();

private:
    // 常量定义
    float Rs; // 房间的大小
    float Tw; // 桌子顶部的宽度（从中心开始）
    float Tl; // 桌子顶部的长度（从中心开始）
    float Th; // 桌子顶部的高度（从中心开始）
    float Tt; // 桌子顶部的厚度
    float Ls; // 桌子腿的大小

    float Bw; // 书本的宽度（从中心开始）
    float Bl; // 书本的长度（从中心开始）
    float Bh; // 书本的高度（从中心开始）
    float Bt; // 书本封面的厚度
    float Btt; // 书本1和2的厚度
    float Btt3; // 书本3的厚度
    float Bb; // 书本装订的厚度
    float ang1; // 书本1的旋转角度
    float B2h; // 书本2的高度
    float B3h; // 书本3的高度
    float ang2; // 书本2的旋转角度
    float ang3; // 书本3的旋转角度

    float a; // 立方体的位置
    float b;
    float c;
    float d; // 立方体的大小
    float _min;
    float _max;
    float wll;
};

#endif ITEMS_H